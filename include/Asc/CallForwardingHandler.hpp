/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_CallForwardingHandler_hpp)
#define Asc_CallForwardingHandler_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/PhoneNumber.hpp>

#include <Asc/SsBaseHandler.hpp>
#include <Asc/InputParser.hpp>

class CallForwardingHandler : public SsBaseHandler {
    typedef SsBaseHandler Base;

 public:
    enum { ID = CallForwardingHandlerId };  
         
    CallForwardingHandler();

    virtual HandlerId GetHandlerId() const;
        
    SsApiRc Deactivate(SsCode ss_code, ServiceGroup basic_service = AllServices, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc Register(SsCode ss_code, const PhoneNumber &number, UINT time_out = 0, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);        

    SsApiRc Register(SsCode ss_code, ServiceGroup basic_service, const PhoneNumber &number, UINT time_out = 0, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);
        
    SsApiRc Activate(SsCode ss_code, ServiceGroup basic_service, const PhoneNumber &number, UINT time_out = 0, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc Activate(SsCode ss_code, const PhoneNumber &number, UINT time_out = 0, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);

    SsApiRc Activate(SsCode ss_code, ServiceGroup basic_service = AllServices, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);
                
    SsApiRc Erase(SsCode ss_code, ServiceGroup basic_service = AllServices, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);
        
    SsApiRc RequestStatus(SsCode ss_code, ServiceGroup basic_service = AllServices, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);


 protected:
    virtual ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &arg);


 private:

    SsApiRc CheckParameterCodes(InputParser::SsCode ss_code, InputParser::BasicServiceMmiCode mmi_code) const;

    SsApiRc ExecuteRequest(SsOperationCode op_code, SsCode ss_code,
                           ServiceGroup basic_service, const PhoneNumber *number=0, UINT time_out=0, const WString override_ss_seq = L"", BOOLEAN register_only = FALSE, LineSelector line = InvalidLine);
    
    SsBaseHandler::ReturnCode CreateRegisteredMsg(const SsForwardingIndArg &arg, SsMessage*& msg) const;

    SsBaseHandler::ReturnCode CreateRegisteredMsg(const SsDataIndArg &arg, SsMessage*& msg) const; 

    SsBaseHandler::ReturnCode CreateErasedMsg(const SsForwardingIndArg &arg, SsMessage*& msg) const;

    SsBaseHandler::ReturnCode CreateErasedMsg(const SsDataIndArg &arg, SsMessage*& msg) const; 

    SsBaseHandler::ReturnCode CreateActivatedMsg(const SsForwardingIndArg &arg, SsMessage*& msg) const;

    SsBaseHandler::ReturnCode CreateActivatedMsg(const SsDataIndArg &arg, SsMessage*& msg) const; 
        
    SsBaseHandler::ReturnCode CreateDeactivatedMsg(const SsForwardingIndArg &arg, SsMessage*& msg) const;

    SsBaseHandler::ReturnCode CreateDeactivatedMsg(const SsDataIndArg &arg, SsMessage*& msg) const; 
    
    SsBaseHandler::ReturnCode CreateInterrogateResultMsg(const SsInterrogateIndArg &arg, SsMessage*& msg) const;

    SsBaseHandler::ReturnCode CreateSuccessResultMsg(const SsRetResIndArg &arg, SsMessage*& msg);

//    SsCode GetSsCode(Tipd tipd) const { return m_param_ss_code; }
        
//    ServiceGroup GetBasicServiceCode(Tipd tipd) const { return m_param_basic_service_code; }

    const PhoneNumber& GetPhoneNumber(Tipd tipd) const;

    UINT GetTimeOut(Tipd tipd) const;

    BOOLEAN CheckStatus(const SsInterrogateIndArg &arg) const;

    BOOLEAN CheckSsCode(const ForwardingInfo &info) const;

    void FillList(const ForwardingInfo &info, Vector<ForwardingFeature> &tha_list, const UINT8 count) const;

    INT CountList(const InterrogateSsResult &result, UINT8 status1, UINT8 status2) const;

    INT CountList(const ForwardingInfo &info, UINT8 status) const;

//    SsCode m_param_ss_code;
        
//    ServiceGroup m_param_basic_service_code;

    PhoneNumber m_phone_number;

    UINT m_time_out;
};

#endif // Asc_CallForwardingHandler_hpp


