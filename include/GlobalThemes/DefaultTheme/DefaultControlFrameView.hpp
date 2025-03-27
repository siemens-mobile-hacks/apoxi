/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultControlFrameView_hpp)
#define Apoxi_DefaultControlFrameView_hpp

#include <Gui/ControlFrameView.hpp>

class DefaultControlFrameView : public ControlFrameView {
    typedef ControlFrameView Base;

    public:
        DefaultControlFrameView();
        DefaultControlFrameView(XYDIM left_size, XYDIM top_size, XYDIM right_size, XYDIM bottom_size);
        virtual void Update(const Theme& theme);
        virtual ~DefaultControlFrameView();

    protected:
        virtual void DrawControlFrame(const Control& control, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_DefaultControlFrameView_hpp


