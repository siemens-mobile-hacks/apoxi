/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_CallBarringHandler_hpp)
#define Asc_CallBarringHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/InputParser.hpp>
#include <Asc/SsBaseHandler.hpp>


class CallBarringHandler : public SsBaseHandler {
    typedef SsBaseHandler Base;
    
public:
    enum { ID = CallBarringHandlerId }; 
        
        CallBarringHandler();
        virtual ~CallBarringHandler();

    virtual HandlerId GetHandlerId() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    virtual ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &arg);
#endif // DOXYGEN_SHOULD_SKIP_THIS

    SsApiRc Activate(SsCode ss_code, const WString& pw, ServiceGroup basic_service = AllServices, const WString& override_ss_sequence = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc Deactivate(SsCode ss_code, const WString& pw, ServiceGroup basic_service = AllServices, const WString& override_ss_sequence = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc RequestStatus(SsCode ss_code, ServiceGroup basic_service = AllServices, const WString& override_ss_sequence = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc ChangePassword(const WString& old_pw, const WString& new_pw, const WString& conf_pw, const WString& override_ss_sequence = L"", BOOLEAN register_only = FALSE, BOOLEAN provide_ss_code = TRUE);

    SsApiRc SendPassword(Tipd tipd, const WString& password);

    SsApiRc AbortPasswordRequest(Tipd tipd);

    private:

    SsBaseHandler::ReturnCode CreateActivatedMsg(const StackMsgArgument &arg, SsMessage*& msg);
        
    SsBaseHandler::ReturnCode CreateDeactivatedMsg(const StackMsgArgument &arg, SsMessage*& msg);
    
    SsBaseHandler::ReturnCode CreateInterrogateResultMsg(const StackMsgArgument &arg, SsMessage*& msg);

    SsBaseHandler::ReturnCode CreatePasswordRegisterMsg(const StackMsgArgument &arg, SsMessage*& msg);

        
    SsBaseHandler::ReturnCode CreateSuccessResultMsg(const SsRetResIndArg &arg, SsMessage*& msg);
    
    SsBaseHandler::ReturnCode CreateGetPasswordMsg(const SsGetPasswordIndArg &arg, SsMessage*& msg);

    SsApiRc CheckParameterCodes(InputParser::SsCode ss_code, InputParser::BasicServiceMmiCode mmi_code) const;


    SsApiRc ExecuteRequest(SsCode ss_code, SsOperationCode op_code, const WString& pw, ServiceGroup basic_service, const WString& override_ss_sequence, BOOLEAN register_only, LineSelector line = InvalidLine);

    SsMessage* m_curr_msg;

//  SsCode m_param_ss_code;

//  ServiceGroup m_param_bs_code;
    
    WString m_param_pw;

    WString m_param_new_pw;

    WString m_param_conf_pw;
};

#endif // Asc_CallBarringHandler_hpp


