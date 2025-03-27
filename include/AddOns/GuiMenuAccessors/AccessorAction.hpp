/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AccessorAction_hpp)
#define Apoxi_AccessorAction_hpp

#include <Gui/Action.hpp>
#include <AddOns/GuiMenuAccessors/AccessorActionExtension.hpp>

class AbstractMenuAccessor;

class AccessorAction : public Action {
    typedef Action Base;

    public:
        AccessorAction();

        AccessorAction(Dispatcher* dispatcher,
                       AbstractMenuAccessor* accessor,
                       const WCHAR* text,
                       const BitmapRes* bitmap = 0,
                       BOOLEAN enabled = TRUE);

        virtual ~AccessorAction();

        void Init(Dispatcher* dispatcher,
                  AbstractMenuAccessor* accessor,
                  const WCHAR* text,
                  const BitmapRes* bitmap = 0,
                  BOOLEAN enabled = TRUE);

        AbstractMenuAccessor* GetMenuAccessor() { return m_ext.GetMenuAccessor(); }

        virtual const ActionExtension* GetExtension() const; 

    private:
        AccessorActionExtension m_ext;
};

#endif // Apoxi_AccessorAction_hpp

