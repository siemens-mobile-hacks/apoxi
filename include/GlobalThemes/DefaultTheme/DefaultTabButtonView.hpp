/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultTabButtonView_hpp)
#define Apoxi_DefaultTabButtonView_hpp

#if !defined(APOXI_DISABLE_TAB_CONTROL)

#include <Gui/TabButton.hpp>

class DefaultTabButtonView : public TabButtonView {
    typedef TabButtonView Base;

    public:
        DefaultTabButtonView(XYDIM default_height,
                             XYDIM default_width = -1,
                             XYDIM min_width = -1,
                             XYDIM max_width = -1,
                             XYDIM clipped_width = 20);

        virtual ~DefaultTabButtonView();

    protected:
        virtual void DrawTabButton(const TabButton& tab_button, DeviceContext* dc, const Rect& repaint_rect) const;

    private:
        void DimmColor(Color& color) const;
        void DrawClippedArea(const TabButton& tab_button, DeviceContext* dc, BOOLEAN  left) const;
};

#endif // APOXI_DISABLE_TAB_CONTROL
#endif  // Apoxi_DefaultTabButtonView_hpp


