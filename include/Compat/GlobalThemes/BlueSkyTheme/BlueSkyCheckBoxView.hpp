/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkyCheckBoxView_hpp)
#define Apoxi_BlueSkyCheckBoxView_hpp

#include <Gui/CheckBox.hpp>

/*  ------------------------------------------------------------------------
    BlueSkyCheckBoxView
    ------------------------------------------------------------------------ */
class BlueSkyCheckBoxView : public CheckBoxView {
    public:
        typedef CheckBoxView Base;

        BlueSkyCheckBoxView(XYDIM default_height, XYDIM left_gap, XYDIM middle_gap);
        virtual ~BlueSkyCheckBoxView() {}

    protected:
        virtual void DrawCheckBox(const CheckBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
        virtual void DrawShiftedCheckBox(const Rect &shift_rect, const CheckBoxModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_BlueSkyCheckBoxView_hpp


