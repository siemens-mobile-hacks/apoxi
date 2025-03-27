/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Test_PbSelectGroup_hpp)
#define Test_PbSelectGroup_hpp

#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/RadioButtonListBoxModel.hpp>
#include <GuiExtensions/DrawableObjectListBox.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <AdvPhonebook/GroupProvider.hpp>

#define MAX_GROUP_COUNT 10

class PbSelectGroup : public MmiWindow {
    typedef MmiWindow Base;

    public:
        //
        PbSelectGroup();

        //
        virtual ~PbSelectGroup();

        //
        void Init();

        void SetSelectedGroupIndex(INT index);

        INT GetSelectedGroupIndex() const;


    protected:
        virtual void OnActionExecuted(Action *action);
        
    private:
        DrawableObjectListBox m_listbox;
        RadioButtonListBoxModel m_model;
        RadioButtonAction m_rb_action[MAX_GROUP_COUNT];
        WString m_grp_str[MAX_GROUP_COUNT];
        Action m_close_win_action;
        GroupProvider       m_group_prov;
};

#endif  // Test_PbAddEditEntry_hpp
