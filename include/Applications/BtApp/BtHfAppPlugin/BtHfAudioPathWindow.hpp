/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_BtHfAudioPathWin_hpp)
#define Mmi_BtHfAudioPathWin_hpp

#include <Gui/Item.hpp>
#include <Gui/Action.hpp>
#include <Gui/ItemMenu.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <Gui/TextLine.hpp>
#include <Gui/LineEditor.hpp>
#include <GuiExtensions/MmiWindow.hpp>
#include "BtHfProfileService.hpp"
#include "BtHfProvider.hpp"


/*  ------------------------------------------------------------------------
    BtHfAudioPathWindow
    ------------------------------------------------------------------------ */
class BtHfAudioPathWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:
        enum BtHfPath
        {
            CurrentAudioPath,
            DefaultAudioPath
        };


        BtHfAudioPathWindow(BtHfProfileService& service);

        virtual ~BtHfAudioPathWindow();


        void Init();

        void OpenCurrentPathWindow(void);

        void OpenDefaultPathWindow(void);

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();


        virtual BOOLEAN OnCancel();

    private:
        BtHfProfileService &bt_hf_service;

        BtHfPath m_current_path;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_phone_action;
        RadioButtonAction m_bthf_action;

        BtHfProvider m_provider;
};

#endif  //Mmi_BtHfAudioPathWin_hpp
