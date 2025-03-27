/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultSoftkeyBarView_hpp)
#define Apoxi_DefaultSoftkeyBarView_hpp

#include <Gui/SoftkeyBar.hpp>

/*  ------------------------------------------------------------------------
    DefaultSoftkeyBarView
    ------------------------------------------------------------------------ */
class DefaultSoftkeyBarView : public SoftkeyBarView {
    //typedef SoftkeyBarView Base;

    public:
        virtual ~DefaultSoftkeyBarView() {}

    protected:
        virtual void DrawSoftkeyBar(const SoftkeyBar &softkey_bar, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_DefaultSoftkeyBarView_hpp


