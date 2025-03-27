/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_DataConnOptionWin_hpp)
#define Apoxi_DataConnOptionWin_hpp

#include <GuiExtensions/MmiDialog.hpp>
#include <GuiExtensions/RadioButtonListBoxModel.hpp>
#include <GuiExtensions/DrawableObjectListBox.hpp>

class DataConnOptionWin : public MmiDialog {
    public:
        typedef MmiDialog Base;

        DataConnOptionWin();
        virtual ~DataConnOptionWin();

        void Init();

        void AddAction(RadioButtonAction *action) { m_lb_model.Add(action); }

        void SetSelectedRadioButton(INT value);
            
        INT GetSelectedValue();

    protected:
        virtual BOOLEAN OnConfirm();

    private:
        RadioButtonListBoxModel m_lb_model;
        DrawableObjectListBox   m_lb;
};

#endif  // Apoxi_DataConnWin_hpp
