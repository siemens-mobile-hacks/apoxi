/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SyncPaintDc_hpp)
#define Apoxi_SyncPaintDc_hpp

#include <Gui/DeviceContext.hpp>

class SyncPaintDc : public DeviceContext {
    typedef DeviceContext Base;

    public:
        SyncPaintDc(Control* control); 

        virtual ~SyncPaintDc();
};

#endif  // Apoxi_SyncPaintDc_hpp


