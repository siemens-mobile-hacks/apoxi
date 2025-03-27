/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfInbandSettingWin_hpp)
#define BtHfInbandSettingWin_hpp

#include <Gui/ItemMenu.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <GuiExtensions/MmiWindow.hpp>

#include "BtHfProfileService.hpp"

static const CHAR* c_bthfplugin_uri = "./BtHfAppPlugin";
static const CHAR* c_bthfplugin_path = "./BtHfAppPlugin/HfInbandSetting";

/*  ------------------------------------------------------------------------
    BtHfInbandSettingWin
    ------------------------------------------------------------------------ */

class BtHfInbandSettingWin : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtHfInbandSettingWin(BtHfProfileService& service);

        virtual ~BtHfInbandSettingWin();


        void Init();

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();


    private:
        BtHfProfileService      &m_bt_hf_service;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_on_action;
        RadioButtonAction m_off_action;

};

#endif // BtHfInbandSettingWin_hpp
