/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_FoggyPanelView_hpp)
#define Apoxi_FoggyPanelView_hpp

#include <Gui/Panel.hpp>

/*  ------------------------------------------------------------------------
    FoggyPanelView
    ------------------------------------------------------------------------*/
class FoggyPanelView : public PanelView {
    typedef PanelView Base;

    public:
        virtual ~FoggyPanelView();
    
        virtual void Update(const Theme& theme);

    protected:
        virtual void DrawPanel(const Panel& panel, DeviceContext* dc, const Rect& repaint_rect) const;

    private:
        void DrawShadedRect(DeviceContext* dc, XYDIM left, XYDIM top, XYDIM right, XYDIM bottom, UINT8 red, UINT8 green, UINT8 blue) const;

};

#endif  // Apoxi_FoggyPanelView_hpp


