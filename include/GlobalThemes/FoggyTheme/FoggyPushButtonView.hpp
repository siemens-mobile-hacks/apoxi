/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_FoggyPushButtonView_hpp)
#define Apoxi_FoggyPushButtonView_hpp

#include <Gui/PushButton.hpp>

/*  ------------------------------------------------------------------------
    FoggyPushButtonView
    ------------------------------------------------------------------------*/
class FoggyPushButtonView : public PushButtonView {
    typedef PushButtonView Base;

    public:
        FoggyPushButtonView();
        explicit FoggyPushButtonView(XYDIM Foggy_height);
        virtual ~FoggyPushButtonView() {}
        virtual void Update(const Theme& theme);

    protected:
        virtual void DrawPushButton(const PushButton& push_button, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_FoggyPushButtonView_hpp


