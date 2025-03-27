/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_AtlItemMenu_hpp)
#define Atl_AtlItemMenu_hpp

#include <Gui/ItemMenu.hpp>

class AtlItemMenu : public ItemMenu {
    typedef ItemMenu Base;

    public:
        //
        AtlItemMenu();

        AtlItemMenu(Control* parent,
                 AbstractItemContainer* item_cont = 0,
                 BOOLEAN adjust_win_title = FALSE);

        virtual ~AtlItemMenu();


    protected:
        virtual BOOLEAN OnMessage(const Message& msg);
};

#endif  // Atl_AtlItemMenu_hpp


