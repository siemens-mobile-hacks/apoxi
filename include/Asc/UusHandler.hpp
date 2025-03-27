/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_UusHandler_hpp)
#define Asc_UusHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/SsBaseHandler.hpp>
#include <Asc/InputParser.hpp>

class UusHandler : public SsBaseHandler {
    typedef SsBaseHandler Base;

 public:
    enum { ID = UusHandlerId }; 
        
    UusHandler();
    virtual ~UusHandler();

    virtual HandlerId GetHandlerId() const;

    SsApiRc Register(SsCode ss_code, const WString& uus_text, UusOutTextType type);
    
    SsApiRc Erase(SsCode ss_code, UusOutTextType type);
    
    SsApiRc RequestStatus(SsCode ss_code);
 
 protected:
    // not needed in this handler (at least for now)
    virtual ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument &argument) { return OkNoMessage; }

 private:

    SsApiRc SendUusRequest(SsCode ss_code, SsOperationCode op_code, StackMsgArgument* arg) ;

    LineSelector m_line;

//    ServiceGroup m_param_bs_code;
};

#endif // Asc_UusHandler_hpp

