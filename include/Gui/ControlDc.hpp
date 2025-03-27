/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ControlDc_hpp)
#define Apoxi_ControlDc_hpp

#include <Gui/DeviceContext.hpp>

class Control;

class ControlDc : public DeviceContext {
    typedef DeviceContext Base;

    public:
        ControlDc();
        ControlDc(Control* control);
        ControlDc(VirtualDisplay* display);
        void Init(Control* control);
        void Init(VirtualDisplay* display);

    protected:
        void Update(const Rect& abs_rect);
};  // ControlDc

#endif  // Apoxi_ControlDc_hpp

