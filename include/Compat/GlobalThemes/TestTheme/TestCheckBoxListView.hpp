/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestCheckBoxListView_hpp)
#define Apoxi_TestCheckBoxListView_hpp

#include <Gui/CheckBoxList.hpp>

/*  ------------------------------------------------------------------------
    TestCheckBoxView
    ------------------------------------------------------------------------ */
class TestCheckBoxListView : public CheckBoxListView {
    typedef CheckBoxListView Base;

    public:
        TestCheckBoxListView(CheckBoxView *cb_view, XYDIM item_height);
        virtual ~TestCheckBoxListView() {}

    protected:
        virtual void DrawCheckBoxItem(const CheckBoxItem &item, DeviceContext *dc, const Rect &item_rect, BOOLEAN highlighted) const;
};

#endif  // Apoxi_TestCheckBoxListView_hpp


