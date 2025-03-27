/* ------------------------------------------------------------------------
   Copyright (C) COMNEON Software GmbH & Co. OHG. 
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Asc_MobileOriginatedUssdHandler_hpp)
#define Asc_MobileOriginatedUssdHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/UssdHandler.hpp>

class MobileOriginatedUssdHandler : public UssdHandler {
    typedef UssdHandler Base;

#ifdef TEST_SUPPLEMENTARY_SERVICES

    friend class MobileOriginatedUSSDHandlerTest;
#endif  

public:
    enum { ID = MoUssdHandlerId };  
        
    MobileOriginatedUssdHandler();
    virtual ~MobileOriginatedUssdHandler();

    virtual HandlerId GetHandlerId() const;
        
    virtual SsBaseHandler::ReturnCode ProcessStackMsgArgument(const SsStackMsgArgument& arg);

    SsApiRc SendUssdRequest(const WString& ss_ctrl_sequence, const DataCodingScheme& dcs, BOOLEAN register_only = FALSE);

    SsApiRc TerminateUssdTransaction(Tipd tipd);

    virtual void RegisterTransaction(Tipd tipd);

private:
    SsBaseHandler::ReturnCode CreateUssdAnswerMsg(const SsUnstructIndArg& arg, SsMessage*& msg);
        
    SsBaseHandler::ReturnCode CreateResentMsg(const SsUssdResentIndArg& arg, SsMessage*& msg);
    
    WString m_param_ctrl_sequence;

    Tipd m_old_tipd;

    BOOLEAN m_resent_pending;
};

#endif // Asc_MobileOriginatedUssdHandler_hpp


