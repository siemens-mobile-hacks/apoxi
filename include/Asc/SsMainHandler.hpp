/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_SsMainHandler_hpp)
#define Asc_SsMainHandler_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include <Kernel/Types.hpp>

#include <Apc/TaggedProblemCode.hpp>

#include <Asc/BaseHandler.hpp>
#include <Asc/InputParser.hpp>

#include <Asc/SupplementaryServiceAction.hpp>
#include <Asc/SupplementaryServiceDispatcher.hpp>
#include <Asc/SupplementaryServiceWaitDispatcher.hpp>
#include <Asc/SsBaseHandler.hpp>

class SsMainHandler : public BaseHandler {
    typedef BaseHandler Base;
 public:
    enum { ID = SsMainHandlerId };  
        
    SsMainHandler();
    virtual ~SsMainHandler();
    virtual HandlerId GetHandlerId() const;
        
    SsBaseHandler* GetHandlerByTiPd(Tipd tipd) const;

    SsApiRc BeginTransaction(const WString &ss_ctrl_sequence, SsBaseHandler *ss_handler, BOOLEAN register_only,
                             SsCode ss_code, SsOperationCode op_code, ServiceGroup basic_service,
                             const WString &p1 = L"", const WString &p2 = L"", const WString &p3 = L"");
    
    SsApiRc ReSetupTransaction(Tipd tipd, SsBaseHandler* ss_handler, SsCode ss_code, SsOperationCode op_code, 
                               ServiceGroup basic_service, const WString &p1 = L"", const WString &p2 = L"", 
                               const WString &p3 = L"");

    void CompleteTransactionSetup(const SsBeginAccArg& arg);

    void AbortTransactionSetup(const SsFacilityRejArg& arg);

    void CallControlTransactionSetup(const StackMsgArgument& arg);

    SsApiRc EndTransaction(Tipd tipd);

    SsApiRc RegisterTransaction(SsBaseHandler *ss_handler, Tipd tipd);

    SsApiRc PostArgument(StackMsgArgument *arg, SsBaseHandler *ss_handler) const;

    void ReleaseTransaction(Tipd tipd);

    static BOOLEAN IsSsPending() { return m_ss_transaction_pending; }

    static BOOLEAN Startup();

    static Mutex* GetSsTransactionStateMutex() { return &m_ss_state_mutex; }

    static BOOLEAN ObtainSsPending();

    static void ClearSsPending();

 private:    

    void StoreTipdHandler(Tipd tipd, SsBaseHandler* ss_handler);
    
    void SetupCallControlTransaction(const WString& user_input);
    
    void ResetData();

    static void ResetStaticData();

    Tipd m_tipd;

    SsBaseHandler *m_ss_handler;

    MnCause m_reject_cause;

    static Mutex m_ss_state_mutex;
    
    static BOOLEAN m_ss_transaction_pending;

    SsBaseHandler *m_current_pending_handler;
    
    SsCode m_pending_ss_code;

    SsOperationCode m_pending_op_code;
    
    ServiceGroup m_pending_basic_service;

    WString m_pending_p1;

    WString m_pending_p2;

    WString m_pending_p3;

    WString m_ss_control_sequence;

    SupplementaryServiceDispatcher m_ss_dispatcher;

    InputActionList m_action_list;

    SsCallBarringActionImpl m_barring_action;

    SsCallForwardingActionImpl m_forwarding_action;

    SsCallWaitingActionImpl m_wait_action;

    SsClipActionImpl m_clip_action;

    SsClirActionImpl m_clir_action;

    SsColpActionImpl m_colp_action;

    SsColrActionImpl m_colr_action;

    SsCnapActionImpl m_cnap_action;

    SsEmlppActionImpl m_emlpp_action;

    SsPasswordChangeActionImpl m_password_action;

    SsUssdActionImpl m_ussd_action;


    friend SupplementaryServiceDispatcher;


};

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // Asc_SsMainHandler_hpp

