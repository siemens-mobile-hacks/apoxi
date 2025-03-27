/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkyRadioButtonView_hpp)
#define Apoxi_BlueSkyRadioButtonView_hpp

#include <Gui/RadioButton.hpp>

/*  ------------------------------------------------------------------------
    BlueSkyRadioButtonView
    ------------------------------------------------------------------------ */
class BlueSkyRadioButtonView : public RadioButtonView{
    public:
        typedef RadioButtonView Base;

        BlueSkyRadioButtonView(XYDIM item_height, XYDIM left_gap, XYDIM middle_gap);
        virtual ~BlueSkyRadioButtonView() {}

    protected:
        virtual void DrawRadioButton(const RadioButtonModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
        virtual void DrawShiftedRadioButton(const Rect &shift_rect, const RadioButtonModel &model, DeviceContext *dc, const Rect &repaint_rect) const;
};

#endif  // Apoxi_BlueSkyRadioButtonView_hpp


