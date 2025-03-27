/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfProfileWindows_hpp)
#define BtHfProfileWindows_hpp

#include <Gui/Action.hpp>
#include <Gui/TextLine.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include <Atl/Features/FeatureItem.hpp>

#include "BtHfProfileService.hpp"

#include <BtApp/BtDeviceListsWindows.hpp>

class BtHfFeatureListWin: public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtHfFeatureListWin(BtHfProfileService& service);

        virtual ~BtHfFeatureListWin();


        void Init();

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnConfirm();

        virtual BOOLEAN OnCancel();

    private:
        BtHfProfileService& m_service;

        MultiLineEditor m_feature_display;

};

class BtHfProfileWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:

        BtHfProfileWindow(BtHfProfileService& service);

        virtual ~BtHfProfileWindow();


        void Init();


        const BtDevice& GetTargetDevice() const;


        void SetTargetDevice(const BtDevice& target_device);


        //void OnConnect(const BtDevice& target_device);


        //void OnDisconnect();

        void OnUserConnect();

        void OnUserDisconnect();

        void OnTransferCallToHandsfree();

        void OnTransferCallToPhone();

        void OnRemoteConnect(BOOLEAN result);

        void OnRemoteDisconnect(BOOLEAN result);


    protected:

        void OnDeviceListWindowClose(void);

        void OnHfSettingsWindowClosed(void);

        void OnTransferCallToPhoneFinished(BOOLEAN success);

        void OnTransferCallToHandsfreeFinished(BOOLEAN success);

        void OnUserConnectFinished(BOOLEAN success);

        void OnUserDisconnectFinished(BOOLEAN success);

        void OnPhoneNumberRequired(BtResultCode result);

    private:
        TextLine m_target_device_name_header;
        TextLine m_target_device_name_display;
        TextLine m_target_device_address_header;
        TextLine m_target_device_address_display;
        TextLine m_connected_header;
        TextLine m_connected_display;

        Action m_disconnect_action;

        BtAlertMessageWindow m_alert_message_window;
        BtRequestRunningWindow m_request_running_window;

        CloseWindowAction m_close_window_action;

        BtHfProfileService  &m_hf_profile_service;

        BtDeviceListWindow m_device_list_window;

        BOOLEAN     m_current_audio_request;    //TRUE audio 2 phone - FALSE audio 2 HF
        FeatureItem m_hf_feature_to_handsfree;
        FeatureItem m_hf_feature_to_phone;

    private:
        friend class BtHfProfileService;
};

#endif // BtHfProfileWindows_hpp

