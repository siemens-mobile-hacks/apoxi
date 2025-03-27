/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkyRadioButtonListView_hpp)
#define Apoxi_BlueSkyRadioButtonListView_hpp

#include <Gui/RadioButtonList.hpp>

/*  ------------------------------------------------------------------------
    BlueSkyRadioButtonListView
    ------------------------------------------------------------------------ */
class BlueSkyRadioButtonListView : public RadioButtonListView {
    typedef RadioButtonListView Base;

    public:
        BlueSkyRadioButtonListView(RadioButtonView *rb_view, XYDIM item_height);
        virtual ~BlueSkyRadioButtonListView() {}

    protected:
        virtual void DrawRadioButtonItem(const RadioButtonItem &item, DeviceContext *dc, const Rect &item_rect, BOOLEAN highlighted) const;
};

#endif  // Apoxi_BlueSkyRadioButtonListView_hpp


