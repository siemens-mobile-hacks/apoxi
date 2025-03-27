/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkyPushButtonView_hpp)
#define Apoxi_BlueSkyPushButtonView_hpp

#include <Gui/PushButton.hpp>

/*  ------------------------------------------------------------------------
    BlueSkyPushButtonView
    ------------------------------------------------------------------------ */
class BlueSkyPushButtonView : public PushButtonView {
    public:
        typedef PushButtonView Base;

        BlueSkyPushButtonView(XYDIM default_height);
        virtual ~BlueSkyPushButtonView() {}

    protected:
        virtual void DrawPushButton(const PushButton &push_button, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_BlueSkyPushButtonView_hpp


