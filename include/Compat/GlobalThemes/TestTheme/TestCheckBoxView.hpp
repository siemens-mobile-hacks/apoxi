/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TestCheckBoxView_hpp)
#define Apoxi_TestCheckBoxView_hpp

#include <Gui/CheckBox.hpp>

/*  ------------------------------------------------------------------------
    TestCheckBoxView
    ------------------------------------------------------------------------ */
class TestCheckBoxView : public CheckBoxView{
    public:
        typedef CheckBoxView Base;

        TestCheckBoxView(XYDIM item_height, XYDIM left_gap, XYDIM middle_gap);
        virtual ~TestCheckBoxView() {}

    protected:
        virtual void DrawCheckBox(const CheckBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
        virtual void DrawShiftedCheckBox(const Rect &shift_rect, const CheckBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_TestCheckBoxView_hpp


