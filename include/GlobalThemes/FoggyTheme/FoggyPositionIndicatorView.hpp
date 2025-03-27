/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_FoggyPositionIndicatorView_hpp)
#define Apoxi_FoggyPositionIndicatorView_hpp

#include <Gui/PositionIndicator.hpp>

/*  ------------------------------------------------------------------------
    DefaultPositionIndicatorView
    ------------------------------------------------------------------------*/
class FoggyPositionIndicatorView : public PositionIndicatorView {
    typedef PositionIndicatorView Base;

    public:
        FoggyPositionIndicatorView();
        explicit FoggyPositionIndicatorView(XYDIM size);
        virtual ~FoggyPositionIndicatorView() {}

    protected:
        virtual void DrawPositionIndicator(const PositionIndicator& pos_ind, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_FoggyPositionIndicatorView_hpp


