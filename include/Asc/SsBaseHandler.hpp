/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_SsBaseHandler_hpp)
#define Asc_SsBaseHandler_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Kernel/Types.hpp>

#include <Apc/SignalTypes.hpp>
#include <Apc/SsErrorCode.hpp>
#include <Apc/TaggedProblemCode.hpp>
#include <Apc/SsStackMsgArgument.hpp>

#include <Asc/BaseHandler.hpp>
#include <Asc/InputParser.hpp>
#include <Asc/SsMessage.hpp>

class SsBaseHandler : public BaseHandler {
    typedef BaseHandler Base;

    friend class SupplementaryServiceDispatcher;
    friend class SsMainHandler;

#ifdef TEST_SUPPLEMENTARY_SERVICES
    friend class CallWaitingHandlerTest;
#endif  

 public:
    enum ReturnCode {
        OkNoMessage,
        OkMessageReady,
        OutOfMemory,
        TipdMismatch,
        OperationCodeMismatch,
        UnexpectedArgument,
        UnexpectedSelector,
        UnexpectedStatus,
        UnexpectedSsCode,
        UnexpectedOperationCode,
    IllegalUsedFlag,
        IllegalListSize,
        IllegalNotificationFlags,
        IllegalCallHoldIndicator,
        IllegalRdnSelector,
        IllegalEctCallstate,
        IllegalNotificationData,
        IllegalMptyIndicator,
        IllegalCallWaitIndicator,
        IllegalCugIndex,
        IllegalClirSuprRejectIndicator,
        AmbiguousData,
        PasswordMismatch,
        UssdResentFailed
    };

    SsBaseHandler();
    
    virtual ~SsBaseHandler();

    virtual void RegisterTransaction(Tipd tipd);

 protected:

    Tipd m_tipd;

    BOOLEAN m_message_ready;

    SsMessage* m_current_message;

    SsOperationCode m_op_code;

    SsCode  m_ss_code;
    
    ServiceGroup m_basic_service;

    LineSelector m_line;

    virtual ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &argument) = 0;

    SsMessage* GetMessage();

    virtual ReturnCode EndTransaction(const Tipd tipd);

    void Error(const Tipd tipd, const SsErrorCode &error_code);

    void Error(const Tipd tipd, const MnCause &error_cause);

    void Reject(const Tipd tipd, const TaggedProblemCode &tagged_problem_code);

    void Reset();

    void SetTipd(const Tipd tipd);

    Tipd GetTipd() const;

    BOOLEAN CheckTipd(const Tipd tipd) const;

    BOOLEAN CheckOperationCode(const SsOperationCode ss_op_code, const Tipd tipd) const;

    SsOperationCode GetOperationCode(const Tipd tipd) const;

    void SetOperationCode(const SsOperationCode ss_op_code);

    SsCode GetSsCode(const Tipd tipd) const;
    void SetSsCode(const SsCode ss_code);

    ServiceGroup GetBasicService(const Tipd tipd) const;
    void SetBasicService(const ServiceGroup basic_service);

    LineSelector GetSelectedLine(const Tipd tipd) const;
    void SetSelectedLine(const LineSelector line);

    void SetMessage(SsMessage *msg);

    void SetMessageReady();

    SsApiRc SendRejectMsg(SsApiRc result, SsCode ss_code, ServiceGroup basic_service, 
                  SsOperationCode ss_opcode, const WString& param1, const WString& param2, const WString& param3,
              CallErrorCause cause) const;
    
    SsApiRc SendRequest(const WString& ss_ctrl_seq, BOOLEAN register_only, SsCode ss_code, 
                                   SsOperationCode op_code, ServiceGroup basic_service, const WString& p1 = L"", 
                                   const WString& p2 = L"", const WString& p3 = L"");

    SsOperationCode ParseOpCode(const WString& ss_ctrl_seq);


};
#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // Asc_SsBaseHandler_hpp

