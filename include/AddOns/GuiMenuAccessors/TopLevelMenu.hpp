/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TopLevelMenu_hpp)
#define Apoxi_TopLevelMenu_hpp

#include <Gui/Menu.hpp>
#include <AddOns/GuiMenuAccessors/ActionMenuAccessor.hpp>

class TopLevelMenu : public Menu {
    typedef Menu Base;

    public:
        TopLevelMenu();

        void Init(Control* parent, const WCHAR* text);
        
        void AddAction(Action* action);

    private:
        ActionMenuAccessor  m_action_menu_accessor;
};

#endif // Apoxi_TopLevelMenu_hpp


