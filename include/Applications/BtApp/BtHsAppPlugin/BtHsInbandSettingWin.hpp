/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsInbandSettingWin_hpp)
#define BtHsInbandSettingWin_hpp

#include <Gui/ItemMenu.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <GuiExtensions/MmiWindow.hpp>

#include "BtHsProfileService.hpp"

static const CHAR* c_bthsplugin_uri = "./BtHsAppPlugin";
static const CHAR* c_bthsplugin_path = "./BtHsAppPlugin/HsInbandSetting";

/*  ------------------------------------------------------------------------
    BtHsInbandSettingWin
    ------------------------------------------------------------------------ */

class BtHsInbandSettingWin : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtHsInbandSettingWin(BtHsProfileService& service);

        virtual ~BtHsInbandSettingWin();


        void Init();

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();


    private:
        BtHsProfileService      &m_bt_hs_service;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_on_action;
        RadioButtonAction m_off_action;

};

#endif // BtHsInbandSettingWin_hpp
