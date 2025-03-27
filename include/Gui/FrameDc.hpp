/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FrameDc_hpp)
#define Apoxi_FrameDc_hpp

#include <Gui/ControlDc.hpp>

class Control;

class FrameDc : public ControlDc {
    typedef ControlDc Base;

    public:
        FrameDc();
        FrameDc(Control* control);
        virtual void AdjustBoundingRect();

    protected:
        void Update(const Rect& abs_rect);
};  // FrameDc

#endif  // Apoxi_FrameDc_hpp


