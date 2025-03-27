/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestPositionIndicatorView_hpp)
#define Apoxi_TestPositionIndicatorView_hpp

#include <Gui/PositionIndicator.hpp>

/*  ------------------------------------------------------------------------
    TestPositionIndicatorView
    ------------------------------------------------------------------------ */
class TestPositionIndicatorView : public PositionIndicatorView {
    typedef PositionIndicatorView Base;

    public:
        TestPositionIndicatorView(XYDIM size);

        virtual ~TestPositionIndicatorView() {}

    protected:
        virtual void DrawPositionIndicator(const PositionIndicator &pos_ind, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_TestPositionIndicatorView_hpp


