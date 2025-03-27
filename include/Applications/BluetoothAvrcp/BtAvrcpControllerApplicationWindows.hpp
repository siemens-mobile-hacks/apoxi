/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(BtAvrcpControllerApplicationWindow_hpp)
#define BtAvrcpControllerApplicationWindow_hpp

#include <Common/MmiWindow.hpp>
#include <Common/MmiWaitingBox.hpp>
#include <Gui/MultiLineEditor.hpp>

#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtDeviceList.hpp>
#include <Bluetooth/BtDeviceListIterator.hpp>

#include "BtAvrcpAlertMessageWindow.hpp"
#include "BtAvrcpControllerDeviceListWindow.hpp"

/*  ************************************************************************
    <em>BtAvrcpControllerDeviceListItem<em> is to show the BT device name in AtlItemListWindow
    ************************************************************************ */
class BtAvrcpControllerDeviceListItem: public Item
{
    private:
        typedef Item Base;

    public:
        BtAvrcpControllerDeviceListItem(Dispatcher* dispatcher, const WString& device_name, const BtDeviceAddress& device_address);

        virtual ~BtAvrcpControllerDeviceListItem();

        const BtDeviceAddress& GetDeviceAddress() const;

        BOOLEAN IsControllerConnected();

        const BtDevice& GetTargetDevice() const;

        void SetTargetDevice(const BtDevice& target_device);

        BtAvrcpProfileOperationService* GetOperationService();

        void SetOperationService(BtAvrcpProfileOperationService* avrcp_operation_service);

        void SetPlayActive(BOOLEAN active_flag);

        BOOLEAN GetPlayActive();

        void SetLastPanelPassThroughRequest(UINT last_panel_passthrough_request);

        UINT GetLastPanelPassThroughRequest();

    private:
        BtDeviceAddress m_device_address;

        BtAvrcpProfileOperationService* m_avrcp_operation_service; // owns an instance

        BOOLEAN m_play_active;

        UINT m_last_panel_passthrough_request;

};

/*  ************************************************************************
    <em>BtAvrcpControllerApplicationWindow<em> MmiWindow window used to display the Controller information.
    ************************************************************************ */
//Forward declaration
class BtAvrcpPanelApplication;
class BtAvrcpAlertMessageWindow;
class BtAvrcpProfileOperationService;

class BtAvrcpControllerApplicationWindow : public MmiWindow
{
    typedef MmiWindow Base;

    public:

        enum 
        {
            AvrcpNotSelected = 0,
            AvrcpNotConnected,
            AvrcpConnected,
            AvrcpConnectedAndActive
        };
    
        BtAvrcpControllerApplicationWindow();

        virtual ~BtAvrcpControllerApplicationWindow();

        void DeleteAllDeviceListItems();
        
        void Init(BtAvrcpPanelApplication* avrcp_panel_app);

        void ControllerConnectRequest();

        void OnConnectRequestFinished(BOOLEAN success);

        void ControllerDisconnectRequest();

        void OnDisconnectRequestFinished(BOOLEAN success);

        void OnPanelPassthroughRequestFinished(BOOLEAN success);

        void ControllerSetActiveDeviceRequest();

        void ControllerSetInactiveDeviceRequest();

        void ControllerSubUnitInfoRequest();

        void OnSubUnitInfoRequestFinished(BOOLEAN success);

        void ControllerSelectDeviceRequest();

        INT GetDeviceCount();

        INT GetPairedDeviceCount();

        INT GetSelectedDeviceState();

    protected:
        virtual void OnOpen();

        virtual void OnGetFocus();

        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnKeyDown(KeyCode key_code);

    private:
        void PrepareDeviceListContainer();

        void OnSelectKeyDown();

        void OnCancelKeyDown();

        void DisplayControllerInfo(BOOLEAN display_subunitinfo=FALSE);

        BtAvrcpPanelApplication* m_avrcp_panel_app;//does not own

        BtAvrcpAlertMessageWindow   m_alert_message_window;

        MultiLineEditor m_display;

        MmiWaitingBox   m_waiting_box;

        BtAvrcpControllerDeviceListWindow m_controller_device_list_window;

        ItemContainer m_devicelist_container;

        BtDeviceList m_device_list;

        BtDeviceAndServiceClass m_device_and_service_class;

        BtDevice m_selected_device;

        BtAvrcpControllerDeviceListItem* m_active_device;// only reference

};

#endif /* BtAvrcpControllerApplicationWindow_hpp */

