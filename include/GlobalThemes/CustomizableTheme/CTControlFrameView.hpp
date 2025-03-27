/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_CTControlFrameView_hpp)
#define Apoxi_CTControlFrameView_hpp

#include <Gui/ControlFrameView.hpp>

/*  ------------------------------------------------------------------------
    CTControlFrameView
    ------------------------------------------------------------------------*/
class CTControlFrameView : public ControlFrameView {
    typedef ControlFrameView Base;

    public:
        CTControlFrameView();

        CTControlFrameView(XYDIM left_size, XYDIM top_size, XYDIM right_size, XYDIM bottom_size);

        virtual ~CTControlFrameView();
        
        void SetDimensions(XYDIM left_size, XYDIM top_size, XYDIM right_size, XYDIM bottom_size);

    protected:
        virtual void DrawControlFrame(const Control& control, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_CTControlFrameView_hpp


