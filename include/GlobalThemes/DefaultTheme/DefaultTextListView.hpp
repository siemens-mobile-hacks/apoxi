/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_DefaultTextListView_hpp)
#define Apoxi_DefaultTextListView_hpp

#include <Gui/TextList.hpp>

/*  ------------------------------------------------------------------------
    DefaultTextListView
    ------------------------------------------------------------------------*/
class DefaultTextListView : public TextListView {
    typedef TextListView Base;

    public:
        DefaultTextListView();
        explicit DefaultTextListView(XYDIM item_height);
        virtual void Update(const Theme& theme);
        virtual ~DefaultTextListView() {}

    protected:
        virtual void DrawTextListItem(const TextList& text_list, DeviceContext* dc, INT index, const Rect& item_rect) const;
};

#endif  // Apoxi_DefaultTextListView_hpp


