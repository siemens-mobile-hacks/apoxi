/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_CallWaitingHandler_hpp)
#define Asc_CallWaitingHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/SsBaseHandler.hpp>
#include <Asc/InputParser.hpp>

class CallWaitingHandler : public SsBaseHandler {
    typedef SsBaseHandler Base;

#ifdef TEST_SUPPLEMENTARY_SERVICES

    friend class CallWaitingHandlerTest;
#endif  

 public:
    enum { ID = CallWaitingHandlerId }; 
        
    CallWaitingHandler();
    virtual ~CallWaitingHandler();

    virtual HandlerId GetHandlerId() const;

    
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    virtual SsBaseHandler::ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &arg);
#endif // DOXYGEN_SHOULD_SKIP_THIS
    
    SsApiRc Activate(ServiceGroup basic_service = AllServices, const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);
    
    SsApiRc Deactivate(ServiceGroup basic_service = AllServices, const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);
    
    SsApiRc RequestStatus(const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc RequestStatus(ServiceGroup basic_service, const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc RequestStatus(ServiceGroup basic_service, const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE);


 private:

    SsApiRc ExecuteRequest(SsOperationCode op_code, ServiceGroup basic_service, const WString& override_ss_seq, BOOLEAN register_only, LineSelector line = InvalidLine);

    SsBaseHandler::ReturnCode CreateActivatedMsg(const SsForwardingIndArg &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreateActivatedMsg(const SsDataIndArg &arg, SsMessage*& msg);
        
    SsBaseHandler::ReturnCode CreateDeactivatedMsg(const SsForwardingIndArg &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreateDeactivatedMsg(const SsDataIndArg &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreateInterrogateResultMsg(const SsInterrogateIndArg &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreateSuccessResultMsg(const SsRetResIndArg &arg, SsMessage*& msg);

    LineSelector m_line;

//    ServiceGroup m_param_bs_code;
};

#endif // Asc_CallWaitingHandler_hpp


