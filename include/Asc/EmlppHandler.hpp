/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_EmlppHandler_hpp)
#define Asc_EmlppHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/SsBaseHandler.hpp>
#include <Asc/InputParser.hpp>

class EmlppHandler : public SsBaseHandler {
    typedef SsBaseHandler Base;

#ifdef TEST_SUPPLEMENTARY_SERVICES

    friend class EmlppHandlerTest;
#endif  

 public:
    enum { ID = EmlppHandlerId };   

    EmlppHandler();
    virtual ~EmlppHandler();

    virtual HandlerId GetHandlerId() const;

    
#ifndef DOXYGEN_SHOULD_SKIP_THIS

    virtual SsBaseHandler::ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &arg);
#endif // DOXYGEN_SHOULD_SKIP_THIS
    
    SsApiRc Register(EmlppPriorityLevel priority, const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE);
    
    SsApiRc RequestStatus(const WString& override_ss_seq = L"", BOOLEAN register_only = FALSE);


 private:

    SsApiRc ExecuteRequest(const SsOperationCode op_code, EmlppPriorityLevel priority, const WString& override_ss_seq, BOOLEAN register_only);

    SsBaseHandler::ReturnCode CreateRegisteredMsg(const SsDataIndArg &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreateInterrogateResultMsg(const SsInterrogateIndArg &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreateSuccessResultMsg(const SsRetResIndArg &arg, SsMessage*& msg);

    EmlppPriorityLevel m_param_priority;
};

#endif // Asc_EmlppHandler_hpp


