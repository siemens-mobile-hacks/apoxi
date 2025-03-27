/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkyProgressBarView_hpp)
#define Apoxi_BlueSkyProgressBarView_hpp

#include <Gui/ProgressBar.hpp>

/*  ------------------------------------------------------------------------
    BlueSkyProgressBarView
    ------------------------------------------------------------------------ */
class BlueSkyProgressBarView : public ProgressBarView {
    typedef ProgressBarView Base;

    public:
        BlueSkyProgressBarView(XYDIM default_height);
        virtual ~BlueSkyProgressBarView() {}

    protected:
        virtual void DrawProgressBar(const ProgressBar &progress_bar, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_BlueSkyProgressBarView_hpp


