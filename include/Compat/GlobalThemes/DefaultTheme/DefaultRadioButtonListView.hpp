/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DefaultRadioButtonListView_hpp)
#define Apoxi_DefaultRadioButtonListView_hpp

#include <Gui/RadioButtonList.hpp>

/*  ------------------------------------------------------------------------
    DefaultRadioButtonListView
    ------------------------------------------------------------------------ */
class DefaultRadioButtonListView : public RadioButtonListView {
    typedef RadioButtonListView Base;

    public:
        DefaultRadioButtonListView();
        DefaultRadioButtonListView(const RadioButtonView *rb_view, XYDIM item_height);
        
        virtual void Update(const Theme &theme);

        virtual ~DefaultRadioButtonListView() {}

    protected:
        virtual void DrawRadioButtonItem(const RadioButtonItem &item, DeviceContext *dc, const Rect &item_rect, BOOLEAN highlighted) const;
};

#endif  // Apoxi_DefaultRadioButtonListView_hpp


