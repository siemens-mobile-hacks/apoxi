 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if ! defined(BtAvrcpPanelApplication_hpp)
#define BtAvrcpPanelApplication_hpp

#include <Common/MmiApplication.hpp>
#include <Common/MmiWaitingBox.hpp>

#include <AddOns/Services/Service.hpp>
#include <AddOns/Services/ServiceBroker.hpp>

#include <Bluetooth/AVRCP/BtAvrcpNotificationMessage.hpp>
#include <Bluetooth/AVRCP/BtTypes.hpp>
#include <Bluetooth/AVRCP/BtAvrcpNotificationMessageArgument.hpp>

#include <Atl/Features/Feature.hpp>
#include <Atl/Features/FeatureID.hpp>

#include "BtAvrcpPanelServiceImpl.hpp"
#include "BtAvrcpCommandInterface.hpp"
#include "BtAvrcpPanelApplicationWindows.hpp"
#include "BtAvrcpProfileService.hpp"
#include "BtAvrcpControllerApplicationWindows.hpp"
#include "BtAvrcpAlertMessageWindow.hpp"


class SubUnitReference : public Item
{
    public:
        SubUnitReference(BtAvrcpCommandInterface* app_ref, WString app_name) : Item(NULL, app_name)
        {
            m_avrcp_app_ref=app_ref;
            m_avrcp_operation_service=NULL;
        }

        ~SubUnitReference()
        {
            delete m_avrcp_operation_service;
        }

        BtAvrcpCommandInterface* GetAvrcpAppReference() const
        {
            return m_avrcp_app_ref;
        }

        BtAvrcpProfileOperationService* GetAvrcpOperationService() const
        {
            return m_avrcp_operation_service;
        }

        void SetAvrcpOperationService(BtAvrcpProfileOperationService* avrcp_operation_service)
        {
            m_avrcp_operation_service=avrcp_operation_service;
        }

        void InitAvrcpOperationService()
        {
            if(m_avrcp_operation_service)
                    m_avrcp_operation_service->Init();
        }

        void ConnectResponse(btapi_avrcp_handle_t avrcp_handle)
        {
            if(m_avrcp_operation_service)
                m_avrcp_operation_service->ConnectResponse(avrcp_handle);
        }

    private:
        BtAvrcpCommandInterface* m_avrcp_app_ref;//Doesnot own, its only reference
        BtAvrcpProfileOperationService* m_avrcp_operation_service;// owns the object pointed to.
};

class BtAvrcpPanelApplication : public MmiApplication
{
    typedef MmiApplication Base;

    public:
        enum BtAvrcpPanelAppFeatures
        {
            // must start with 0 and must be continously
            BtAvrcpPanelSetActiveSubUnit = 0,
            BtAvrcpOpenControllerWindow,
            BtAvrcpControllerSelectDeviceRequest, //Used in Controller window to open device list
            BtAvrcpControllerConnectRequest, //Used in Controller device list window
            BtAvrcpControllerDisconnectRequest, //Used in Controller device list window
            BtAvrcpControllerSubUnitInfoRequest, //Used in Controller device list window
            BtAvrcpControllerSetActiveDeviceRequest, //Used in Controller device list window
            BtAvrcpControllerSetInactiveDeviceRequest, //Used in Controller device list window
            BtAvrcpPanelFeatureCount    // mandatory last entry
        };

        virtual ~BtAvrcpPanelApplication();

        static BtAvrcpPanelApplication* GetInstance();

        virtual void OnStartup();

        BOOLEAN RegisterAvrcpApp (WString& app_name, BtAvrcpCommandInterface& cmd_handle, MmiSubUnitType sub_unit_info);

        BOOLEAN DeregisterAvrcpApp (WString & app_name);

        BtAvrcpResponseType OnPanelPassThrough(BtAvrcpPanelPassThroughParams ppt_params);

        void UpdateContext();

        BOOLEAN ChangeActiveDevice(INT idx);

        void UpdateControllerFeaturesAvailable();

        void UpdateControllerDeviceListFeaturesAvailable();

    protected:
        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnMessage(const Message &message);

        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);

        BOOLEAN OnAvrcpNotification(const BtAvrcpNotificationMessage& avrcp_notification_message);

        //virtual void RegisterAvrcpMessages() const;

        //virtual void UnregisterAvrcpMessages() const;

        void RegisterPanelToApoxiAvrcp();

        virtual void UnregisterPanelToApoxiAvrcp();

        BtAvrcpSubunitType GetBtApoxiAvrcpSubunitInfo(MmiSubUnitType sub_unit_info);

        AvrcpCommand ConvertBtApoxiOperationToMmiCommand(BtAvrcpOperation bt_apoxi_operation);

        BtAvrcpResponseType ConvertMmiResponseToApoxiResponse(AvrcpResponse mmi_response);

    private:
        BtAvrcpPanelApplication();

        void OnConnectNotification(btapi_avrcp_connect_handle_t hdl);

        void OnDisconnectNotification(void* app_hdl);

        void RegisterFeatures(const CHAR* feat_ids[], INT feat_count, Feature feat_items[]);

        Feature m_features[BtAvrcpPanelFeatureCount];

        static const CHAR* m_feature_ids[BtAvrcpPanelFeatureCount];

        static BtAvrcpPanelApplication  m_bt_avrcp_panel_app;

        BtAvrcpPanelServiceImpl     m_service;

        ItemContainer   m_subunits_container;

        BtAvrcpDeviceListWin m_subunits_list_win;

        SubUnitReference*   m_active_subunit;// only reference

        BtAvrcpSubunitInfoEntry*    m_subunitinfo_entry; // owns objects

        BtAvrcpProfileRegistrationService   m_avrcp_registration_service;

        BtAvrcpAlertMessageWindow   m_alert_message_window;

        MmiWaitingBox   m_waiting_box;

        BtAvrcpControllerApplicationWindow m_controller_window;
};
#endif //#define BtAvrcpPanelApplication_hpp

