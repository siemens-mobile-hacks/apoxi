/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestSoftkeyBarView_hpp)
#define Apoxi_TestSoftkeyBarView_hpp

#include <Gui/SoftkeyBar.hpp>

class DeviceContext;

/*  ------------------------------------------------------------------------
    TestSoftkeyBarView
    ------------------------------------------------------------------------ */
class TestSoftkeyBarView : public SoftkeyBarView {
    public:
        typedef SoftkeyBarView Base;

        virtual ~TestSoftkeyBarView() {}

    protected:
        virtual void DrawSoftkeyBar(const SoftkeyBar &softkey_bar, DeviceContext *dc, const Rect &repaint_rect) const;

    private:
        void DrawShadedRect(DeviceContext *dc, XYDIM left, XYDIM top, XYDIM right, XYDIM bottom, UINT8 red, UINT8 green, UINT8 blue) const;

};

#endif  // Apoxi_TestSoftkeyBarView_hpp


