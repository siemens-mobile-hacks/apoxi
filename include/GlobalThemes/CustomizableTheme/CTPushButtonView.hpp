/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_CTPushButtonView_hpp)
#define Apoxi_CTPushButtonView_hpp

#include <Gui/PushButton.hpp>

/*  ------------------------------------------------------------------------
    CTPushButtonView
    ------------------------------------------------------------------------*/
class CTPushButtonView : public PushButtonView {
    typedef PushButtonView Base;

    public:
        CTPushButtonView();

        explicit CTPushButtonView(XYDIM default_height);

        virtual ~CTPushButtonView() {}

        virtual void Update(const Theme& theme);
        
        void SetDefaultPushButtonHeight(XYDIM height);

    protected:
        virtual void DrawPushButton(const PushButton& push_button, DeviceContext* dc, const Rect& repaint_rect) const;

};

#endif  // Apoxi_CTPushButtonView_hpp


