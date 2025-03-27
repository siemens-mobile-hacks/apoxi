/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_ChrHandler_hpp)
#define Asc_ChrHandler_hpp

#ifdef APOXI_COMPAT_2_2_0

#include <Asc/BaseHandler.hpp>

/*  ========================================================================
    ChrHandler
    ======================================================================== */
class ChrHandler : public BaseHandler {
    typedef BaseHandler Base;
    public:
        enum { ID = ChrHandlerId };

        ChrHandler();
        virtual ~ChrHandler();

        virtual HandlerId GetHandlerId() const;

};
#endif // APOXI_COMPAT_2_2_0

#endif // Asc_ChrHandler_hpp


