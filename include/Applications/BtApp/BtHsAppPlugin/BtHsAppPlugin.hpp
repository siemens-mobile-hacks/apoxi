/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_BtHsAppPlugin_hpp)
#define Mmi_BtHsAppPlugin_hpp

#include <Common/MmiApplicationPlugin.hpp>
#include <Bluetooth/HS/BtHsNotificationMessage.hpp>
#include <Bluetooth/HS/BtHsNotificationMessageArgument.hpp>
#include <BtApp/BtApplication.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include "BtHsProfileService.hpp"
#include "BtHsVolumeSettingsWin.hpp"
#include "BtHsConnectionSettingWin.hpp"
#include "BtHsInbandSettingWin.hpp"
class BtHsAppPlugin : public MmiApplicationPlugin
{
    typedef MmiApplicationPlugin Base;

    public:

        virtual ~BtHsAppPlugin();

        void Init(Application* app);

        static BtHsAppPlugin* GetInstance();

        virtual BOOLEAN OnMessage(const Message &msg);

        void OnHsDisconnectRequestFinished(BOOLEAN success);

        void OnHsConnectRequestFinished(BOOLEAN success);

        void OnHsCallTransferToPhoneRequestFinished(BOOLEAN success);

        void OnHsCallTransferToHeadsetRequestFinished(BOOLEAN success);


    protected:
        virtual void OnAppOpen();
        virtual void OnAppClose();

        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);
        virtual BOOLEAN OnContextFeatureTriggered (const FeatureID& feature_id, const DataItem& context_item);



    private:

        BtHsAppPlugin();

        void OnHsNotification(const BtHsNotificationMessage& notification_message);


        BOOLEAN OnHsConnectNotification(BtResultCode result, const BtDevice& target_device);
        /*Remote device and local device both can initiate Hs disconnect. In this function
        the added menu and indicator should be remove.
        */
        BOOLEAN OnHsDisconnectNotification(BtResultCode result);


        BOOLEAN OnHsCallTransferToHeadsetNotification(BtResultCode result);

        BOOLEAN OnHsCallEventNotification(BtHsCallEvent call_event);


        void OnConnectActionExecuted(const BtDevice& device);

        void OnDisconnectActionExecuted();

        void OnCallTransferToPhoneFeature();

        void OnCallTransferToHeadsetFeature();

    private:

        Feature m_hs_disconnect_feature;
        Feature m_call_transfer_to_phone_feature;
        Feature m_call_transfer_to_hs_feature;
        Feature m_vol_setting_hs_feature;
        Feature m_connection_on_call_hs_feature;        
        Feature m_inband_setting_hs_feature;        
        ContextFeature m_hs_connect_context_feature;
        Property m_hs_prop;

        static BtHsAppPlugin m_plugin;

        BtDevice m_target_device;

        BtApplication* m_host_app;
        BtHsProfileService m_hs_profile_service;
        BtAlertMessageWindow m_alert_message_window;
        BtRequestRunningWindow m_request_running_window;
        BtHsVolumeSettingsWin m_bths_vol_setting_win;
        BtHsConnectionSettingWin m_hs_connection_on_call_window;    
        BtHsInbandSettingWin m_hs_inband_setting_win;
};
#endif  // Mmi_AppPlugin_hpp

