/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultTabControlView_hpp)
#define Apoxi_DefaultTabControlView_hpp

#if !defined(APOXI_DISABLE_TAB_CONTROL)

#include <Gui/TabControl.hpp>

class DefaultTabControlView : public TabControlView {
    typedef TabControlView Base;

    public:
        DefaultTabControlView(XYDIM border_size,
                              XYDIM header_height = -1);
        
        virtual ~DefaultTabControlView();

    protected:
        virtual void DrawTabControl(const TabControl& tab_control,
                                    DeviceContext* dc,
                                    const Rect& repaint_rect) const;
};

#endif // APOXI_DISABLE_TAB_CONTROL
#endif  // Apoxi_DefaultTabControlView_hpp


