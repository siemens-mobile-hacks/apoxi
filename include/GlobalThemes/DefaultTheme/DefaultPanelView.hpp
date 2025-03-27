/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultPanelView_hpp)
#define Apoxi_DefaultPanelView_hpp

#include <Gui/Panel.hpp>

class DefaultPanelView : public PanelView {
    typedef PanelView Base;

    public:
        virtual ~DefaultPanelView();
        virtual void Update(const Theme& theme);

    protected:
        virtual void DrawPanel(const Panel& panel, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_DefaultPanelView_hpp


