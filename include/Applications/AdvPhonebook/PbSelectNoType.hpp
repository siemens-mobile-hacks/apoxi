/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Test_PbSelectNoType_hpp)
#define Test_PbSelectNoType_hpp

#include <AdvPhonebook/PbTypes.hpp>
#include <GuiExtensions/MmiWindow.hpp>
#include <GuiExtensions/RadioButtonListBoxModel.hpp>
#include <GuiExtensions/DrawableObjectListBox.hpp>
#include <Gui/RadioButtonAction.hpp>

class PbSelectNoType : public MmiWindow {
    typedef MmiWindow Base;

    public:
        PbSelectNoType();

        virtual ~PbSelectNoType();

        void Init();

        void SetSelectedNumberTypeIndex(INT index);

        INT GetSelectedNumberTypeIndex() const;

    protected:
        virtual void OnActionExecuted(Action *action);
    
    private:
        enum NumberTypeId {
            NoTypeId = 0,
            MobileId,
            HomeId,
            OfficeId,
            FaxId,
            LastId  // mandatory last entry
        };

        DrawableObjectListBox m_listbox;
        RadioButtonListBoxModel m_model;
        RadioButtonAction m_rb_action[LastId];
        Action m_close_win_action;
};

#endif  // Test_PbAddEditEntry_hpp
