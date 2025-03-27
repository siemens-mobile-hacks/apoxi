/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsConnectionSettingWin_hpp)
#define BtHsConnectionSettingWin_hpp

#include <Gui/ItemMenu.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <GuiExtensions/MmiWindow.hpp>

#include "BtHsProfileService.hpp"

/*  ------------------------------------------------------------------------
    BtHsConnectionSettingWin
    ------------------------------------------------------------------------ */

class BtHsConnectionSettingWin : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtHsConnectionSettingWin(BtHsProfileService& service);

        virtual ~BtHsConnectionSettingWin();


        void Init();

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();


    private:
        BtHsProfileService &m_hs_profile_service;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_on_action;
        RadioButtonAction m_off_action;

};

#endif // BtHsConnectionSettingWin_hpp
