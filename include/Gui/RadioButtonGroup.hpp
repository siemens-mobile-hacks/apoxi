/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RadioButtonGroup_hpp)
#define Apoxi_RadioButtonGroup_hpp

#include <Gui/ToggleActionGroup.hpp>
#include <Gui/RadioButtonAction.hpp>

class RadioButtonGroup : public ToggleActionGroup {
    typedef ToggleActionGroup Base;

    public:
        RadioButtonGroup();

        virtual ~RadioButtonGroup();

        void Init();
        
        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        void SetSelectedRadioButtonAction(RadioButtonAction* rb) { SetSelectedToggleAction(rb); }

        RadioButtonAction* GetSelectedRadioButtonAction() { return (RadioButtonAction*)GetSelectedToggleAction(); }
};

#endif // Apoxi_RadioButtonGroup_hpp

