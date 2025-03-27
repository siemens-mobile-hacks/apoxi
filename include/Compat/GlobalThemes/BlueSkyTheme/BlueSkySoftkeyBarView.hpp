/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkySoftkeyBarView_hpp)
#define Apoxi_BlueSkySoftkeyBarView_hpp

#include <Gui/SoftkeyBar.hpp>

class DeviceContext;

/*  ------------------------------------------------------------------------
    BlueSkySoftkeyBarView
    ------------------------------------------------------------------------ */
class BlueSkySoftkeyBarView : public SoftkeyBarView {
    public:
        typedef SoftkeyBarView Base;

        virtual ~BlueSkySoftkeyBarView() {}

    protected:
        virtual void DrawSoftkeyBar(const SoftkeyBar &softkey_bar, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_BlueSkySoftkeyBarView_hpp


