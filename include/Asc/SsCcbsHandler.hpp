/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SsCcbsHandler_hpp)
#define Asc_SsCcbsHandler_hpp

#include <Kernel/Types.hpp>

#include <Asc/InputParser.hpp>
#include <Asc/SsCcbsDispatcher.hpp>

/*  ========================================================================
    SsCcbsHandler 
    ======================================================================== */
class SsCcbsHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = SsCcbsHandlerId };  
        
        SsCcbsHandler();
        virtual ~SsCcbsHandler();

        virtual HandlerId GetHandlerId() const;

        SsApiRc SendCcbsInvoke() const;

        SsApiRc SendCcbsReject() const;

        SsApiRc SendCcbsReCallRequest() const;


    private:
        SsCcbsDispatcher m_ss_dispatcher; // main dispatcher for retrieving asynchronous messages
        BOOLEAN m_rejected;
};

#endif // Asc_SsCcbsHandler_hpp


