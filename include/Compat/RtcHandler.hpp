/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_RtcHandler_hpp)
#define Asc_RtcHandler_hpp

#include <Asc/BaseHandler.hpp>

/*  ========================================================================
    RtcHandler
    ======================================================================== */
#ifdef APOXI_COMPAT_2_0_0

class RtcHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = RtcHandlerId };

        RtcHandler();
        virtual ~RtcHandler();

        virtual HandlerId GetHandlerId() const;
};

#endif  // APOXI_COMPAT_2_0_0

#endif // Asc_RtcHandler_hpp


