/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_CallDeflectionHandler_hpp)
#define Asc_CallDeflectionHandler_hpp


#include <Asc/BaseHandler.hpp>
#include <Asc/CallDeflectionDispatcher.hpp>

class CallDeflectionHandler : public BaseHandler {
    typedef BaseHandler Base;
    
    public:
        enum { ID = CallDeflectionHandlerId };
        
        CallDeflectionHandler();
        virtual ~CallDeflectionHandler();
        virtual HandlerId GetHandlerId() const;
        CallApiRc ProcessCallDeflectRequest(PhoneNumber deflect_number);

    private:
        CallDeflectionDispatcher m_cd_disp;
};

#endif // Asc_CallDeflectionHandler_hpp


