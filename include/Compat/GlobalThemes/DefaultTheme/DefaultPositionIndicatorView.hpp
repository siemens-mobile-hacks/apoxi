/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultPositionIndicatorView_hpp)
#define Apoxi_DefaultPositionIndicatorView_hpp

#include <Gui/PositionIndicator.hpp>

/*  ------------------------------------------------------------------------
    DefaultPositionIndicatorView
    ------------------------------------------------------------------------ */
class DefaultPositionIndicatorView : public PositionIndicatorView {
    typedef PositionIndicatorView Base;

    public:
        DefaultPositionIndicatorView();
        explicit DefaultPositionIndicatorView(XYDIM size);
        virtual ~DefaultPositionIndicatorView() {}

    protected:
        virtual void DrawPositionIndicator(const PositionIndicator &pos_ind, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_DefaultPositionIndicatorView_hpp


