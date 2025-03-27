/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_BootHandler_hpp)
#define Asc_BootHandler_hpp

#include <Apc/SignalTypes.hpp>

#include <Asc/BaseHandler.hpp>

#include <Asc/BootDispatcher.hpp>

/*  ========================================================================
    BootHandler
    ======================================================================== */
class BootHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = BootHandlerId };        

        BootHandler();
        virtual ~BootHandler();

        virtual HandlerId GetHandlerId() const;

        static void RequestOnStartup(INT providerid, BootNotification notification);

    private:
        BootDispatcher m_boot_dispatcher;       // dispatcher for retrieving asynchronous messages

};

#endif // Asc_BootHandler_hpp


