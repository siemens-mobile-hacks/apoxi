/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestPushButtonView_hpp)
#define Apoxi_TestPushButtonView_hpp

#include <Gui/PushButton.hpp>

/*  ------------------------------------------------------------------------
    TestPushButtonView
    ------------------------------------------------------------------------ */
class TestPushButtonView : public PushButtonView {
    typedef PushButtonView Base;

    public:
        TestPushButtonView(XYDIM default_height);
        virtual ~TestPushButtonView() {}

    protected:
        virtual void DrawPushButton(const PushButton &push_button, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_TestPushButtonView_hpp


