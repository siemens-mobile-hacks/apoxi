/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SigHandler_hpp)
#define Asc_SigHandler_hpp

#include <Asc/BaseHandler.hpp>

#include <Asc/SigDispatcher.hpp>

/*  ========================================================================
    SigHandler
    ======================================================================== */
class SigHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = SigHandlerId };

        SigHandler();
        virtual ~SigHandler();

        virtual HandlerId GetHandlerId() const;

        /* Start receiving radio signal strength indication.
        @param treshold_db: Only if the new value received from network is more different 
        as this dB-value, it is forwarded to mmi(reduces power-consumtion if percentage value is high).*/
        void Start(UINT threshold_db = 0) const;

        void Stop() const;

    private:
        SigDispatcher m_sig_dispatcher; // main dispatcher for retrieving asynchronous messages
};

#endif // Asc_SigHandler_hpp

