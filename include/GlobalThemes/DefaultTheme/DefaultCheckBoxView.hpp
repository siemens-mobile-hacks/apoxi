/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultCheckBoxView_hpp)
#define Apoxi_DefaultCheckBoxView_hpp

#include <Gui/CheckBox.hpp>

class DefaultCheckBoxView : public CheckBoxView {
    typedef CheckBoxView Base;

    public:
        DefaultCheckBoxView();
        DefaultCheckBoxView(XYDIM default_height, XYDIM left_gap, XYDIM middle_gap);
        virtual void Update(const Theme& theme);
        virtual ~DefaultCheckBoxView() {}

    protected:
        virtual void DrawCheckBox(const CheckBoxModel& model, DeviceContext* dc, const Rect& repaint_rect) const;
        virtual void DrawShiftedCheckBox(const Rect& shift_rect, const CheckBoxModel& model, DeviceContext* dc, const Rect& repaint_rect) const;
};

#endif  // Apoxi_DefaultCheckBoxView_hpp


