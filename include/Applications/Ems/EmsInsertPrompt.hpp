/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Ems_EmsInsertPrompt_hpp)
#define Ems_EmsInsertPrompt_hpp

#include <Gui/Action.hpp>
#include <Gui/Font.hpp>
#include <Gui/Color.hpp>
#include <Gui/AbstractToggleAction.hpp>
#include <Auxiliary/WString.hpp>

#include <GuiExtensions/ActionListBoxModel.hpp>
#include <GuiExtensions/Label.hpp>
#include <GuiExtensions/MmiDialog.hpp>

class EmsInsertPrompt;

class EmsInsertPromptListBoxModel : public LabelListBoxModel {
    typedef LabelListBoxModel Base;

    public:
        EmsInsertPromptListBoxModel();
        virtual ~EmsInsertPromptListBoxModel();

        void Init(DrawableObjectListBox *parent);

        virtual const WCHAR* GetCellText(INT index, BOOLEAN highlighted);
};

class EmsInsertPrompt : public MmiDialog {
    typedef MmiDialog Base;

    public:
        enum EmsInsertType {
            InsertImageType = 0,
            InsertSoundType = 1
        };

        EmsInsertPrompt();
        virtual ~EmsInsertPrompt();

        void Init();
        EmsInsertPrompt::EmsInsertType GetSelectedType() const;

    private:
        DrawableObjectListBox       m_listbox;
        EmsInsertPromptListBoxModel m_listbox_model;
};

#endif // Ems_EmsInsertPrompt_hpp
