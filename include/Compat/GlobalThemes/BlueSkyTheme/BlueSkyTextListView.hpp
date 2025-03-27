/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BlueSkyTextListView_hpp)
#define Apoxi_BlueSkyTextListView_hpp

#include <Gui/TextList.hpp>

/*  ------------------------------------------------------------------------
    BlueSkyTextListView
    ------------------------------------------------------------------------ */
class BlueSkyTextListView : public TextListView {
    typedef TextListView Base;

    public:
        BlueSkyTextListView(XYDIM item_height);
        virtual ~BlueSkyTextListView() {}

    protected:
        virtual void DrawTextListItem(const TextList &text_list, DeviceContext *dc, INT index, const Rect &item_rect) const;
};

#endif  // Apoxi_BlueSkyTextListView_hpp


