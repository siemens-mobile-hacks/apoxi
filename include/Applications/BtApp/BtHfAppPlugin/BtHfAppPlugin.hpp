 /* ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
 

#if ! defined(BtHfAppPlugin_hpp)
#define BtHfAppPlugin_hpp

#include <Atl/Properties/Property.hpp>
#include <Common/MmiProgressBox.hpp>
#include <Common/MmiApplicationPlugin.hpp>

#include <Bluetooth/HF/BtHfNotificationMessage.hpp>
#include <BtApp/BtApplication.hpp>
#include "BtHfVolumeSettingsWin.hpp"
#include "BtHfProfileService.hpp"
#include "BtHfProfileWindows.hpp"
#include "BtHfAudioPathWindow.hpp"
#include "BtHfInbandSettingWin.hpp"

#define DISCONNECT_DEVICE "BtHfDisconnect"
#define CONNECT_DEVICE "BtHfConnect"
#define DEFAULT_AUDIO_PATH "BtHfDefaultAudioPath"
#define CHANGE_CURRENT_AUDIO_PATH "BtHfCurrentAudioPath"
#define REMOTE_VOLUME_SETTING "BtHfRemoteVolumeSetting"
#define HF_DEVICE_FEATURES "BtHfDeviceFeatures"
#define HF_INBAND_SETTING "BtHfInbandSetting"
#define BTHF_AUDIO_2_PHONE "BtHfAudioTransferToPhone"
#define BTHF_AUDIO_2_HF "BtHfAudioTransferToHandsfree"


class BtHfAppPlugin : public MmiApplicationPlugin {
    typedef MmiApplicationPlugin Base;

    public:
        virtual ~BtHfAppPlugin();

        static BtHfAppPlugin* GetInstance();
        
        virtual void Init(Application* bt_app);

        void AddMenuFeature(FeatureID feature, BOOLEAN success);

        void RemoveMenuFeature(FeatureID feature, BOOLEAN success);

    protected:
        virtual void OnAppOpen();

        virtual void OnAppClose();

        virtual BOOLEAN OnMessage(const Message &msg);

        BOOLEAN OnHfNotification(const BtHfNotificationMessage& hf_notification_message);

        void OnConnectNotification(BtResultCode result, const BtDevice& device);

        void OnDisconnectNotification(BtResultCode result);

        void OnTransferAudioToAccessoryNotification(BtResultCode result);

        void OnTransferAudioToPhoneNotification();

        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);

        virtual BOOLEAN OnContextFeatureTriggered(const FeatureID& feature_id, const DataItem& context_item);


        virtual void RegisterHfMessages() const;
        
        virtual void UnregisterHfMessages() const;

        virtual BOOLEAN BtHfInsertPhoneNr();

    private:
        BtHfAppPlugin();

        static BtHfAppPlugin    m_bthf_plugin;

        BtHfVolumeSettingsWin   m_bthf_vol_setting_win;

        BtHfProfileWindow       m_bt_hf_service_win;
        BtHfProfileService      m_bt_hf_service;

        BtHfAudioPathWindow     m_audio_path_win;
        BtHfFeatureListWin      m_hf_device_feature_win;
        BtHfInbandSettingWin    m_hf_inband_setting_win;

        Feature         m_hf_default_path_feature;
        Feature         m_change_current_path_feature;
        Feature         m_remote_volume_feature;
        Feature         m_disconnect_feature;   
        Feature         m_hf_device_list_feature;
        Feature         m_hf_inband_setting_feature;
        Feature         m_audio_2_phone_feature;
        Feature         m_audio_2_hf_feature;
        ContextFeature  m_connect_feature;

        Property        m_hf_prop;

        BtApplication*  m_app;

        BtAlertMessageWindow        m_alert_message_window;
        BtRequestRunningWindow  m_request_running_window;

};

#endif //#define BtHfAppPlugin_hpp

