/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultPushButtonView_hpp)
#define Apoxi_DefaultPushButtonView_hpp

#include <Gui/PushButton.hpp>

/*  ------------------------------------------------------------------------
    DefaultPushButtonView
    ------------------------------------------------------------------------ */
class DefaultPushButtonView : public PushButtonView {
    typedef PushButtonView Base;

    public:
        DefaultPushButtonView();
        explicit DefaultPushButtonView(XYDIM default_height);
        virtual ~DefaultPushButtonView() {}
        virtual void Update(const Theme &theme);

    protected:
        virtual void DrawPushButton(const PushButton &push_button, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_DefaultPushButtonView_hpp


