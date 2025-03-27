/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ToggleActionGroup_hpp)
#define Apoxi_ToggleActionGroup_hpp

#include <Gui/AbstractToggleAction.hpp>

class ToggleActionGroup {
    public:
        ToggleActionGroup();

        virtual ~ToggleActionGroup();

        void Init();
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        void SetSelectedToggleAction(AbstractToggleAction* rb);

        AbstractToggleAction* GetSelectedToggleAction() { return m_selected_action; }

    private:
        AbstractToggleAction* m_selected_action;
};

#endif // Apoxi_ToggleActionGroup_hpp

