/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SubMenuAction_hpp)
#define Apoxi_SubMenuAction_hpp

#include <Gui/Action.hpp>
#include <AddOns/GuiMenuAccessors/AccessorActionExtension.hpp>
#include <AddOns/GuiMenuAccessors/ActionMenuAccessor.hpp>

class AbstractMenuAccessor;

class SubMenuAction : public Action {
    typedef Action Base;

    public:
        SubMenuAction();

        SubMenuAction(Dispatcher* dispatcher,
                       const WCHAR* text,
                       const BitmapRes* bitmap = 0,
                       BOOLEAN enabled = TRUE);

        virtual ~SubMenuAction();

        void Init(Dispatcher* dispatcher,
                  const WCHAR* text,
                  const BitmapRes* bitmap = 0,
                  BOOLEAN enabled = TRUE);

        void AddAction(Action* action);

        AbstractMenuAccessor* GetMenuAccessor() { return m_ext.GetMenuAccessor(); }

        virtual const ActionExtension* GetExtension() const; 

    private:
        AccessorActionExtension m_ext;
        ActionMenuAccessor      m_action_menu_accessor;
};

#endif // Apoxi_SubMenuAction_hpp

