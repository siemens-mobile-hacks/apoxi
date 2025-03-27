/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSettingsDisplayInfoWindow_hpp)
#define BtSettingsDisplayInfoWindow_hpp

#include <Gui/Item.hpp>
#include <Gui/Action.hpp>
#include <Gui/ItemMenu.hpp>
#include <Gui/RadioButtonGroup.hpp>
#include <Gui/RadioButtonAction.hpp>
#include <Gui/TextLine.hpp>
#include <Gui/LineEditor.hpp>
#include <Common/MmiWindow.hpp>
#include <Bluetooth/BtLocalSettings.hpp>
#include <BtApp/BtDeviceListsWindows.hpp>

/*  ------------------------------------------------------------------------
    BtTurnOnOffWindow 
    ------------------------------------------------------------------------ */

class BtTurnOnOffWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtTurnOnOffWindow();

        virtual ~BtTurnOnOffWindow();


        void Init(BtLocalSettings* local_settings);

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();

    
    private:
        BtLocalSettings* m_local_settings;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_on_action;
        RadioButtonAction m_off_action;

};


/*  ------------------------------------------------------------------------
    BtDeviceSearchModeWindow
    ------------------------------------------------------------------------ */
static const CHAR* c_bt_device_searchmode_uri = "./BtApp";
static const CHAR* c_bt_device_searchmode_path = "./BtApp/BtAppDeviceListSearchMode";

class BtDeviceSearchModeWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtDeviceSearchModeWindow();

        virtual ~BtDeviceSearchModeWindow();


        void Init(BtDeviceListWindow* device_list_window);

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();

    private:
        BtDeviceListWindow* m_device_list_window;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_immediate_action;
        RadioButtonAction m_delayed_action;
};


#endif // BtSettingsDisplayInfoWindow_hpp

