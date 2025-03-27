/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtApplicationWindows_hpp)
#define BtApplicationWindows_hpp

#include <Common/MmiAlert.hpp>
#include <Common/MmiWaitingBox.hpp>
#include <BtApp/BtApplicationRequests.hpp>

class BtAlertMessageWindow : public MmiAlert
{
    private:
        typedef MmiAlert Base;

    public:
        // Enumeration for text display in allert box
        typedef enum
        {
            // Pairing
            BtAmwPair,
            // Unpairing
            BtAmwUnpair,
            // Trusing
            BtAmwTrust,
            // Untrusting
            BtAmwUntrust,
            // Setting remote device name
            BtAmwSetName,
            // Querying the supported accessory profiles
            BtAmwQuerySupportedProfiles,
            // DUN connection established notification
            BtAmwDunConnect,
            // DUN connection released notification
            BtAmwDunDisconnect,
            //HS connection established notification
            BtAmwHsConnect,
            //HS connection released notification
            BtAmwHsDisconnect,
            //HS call transfer to phone notification
            BtAmwHsCallTransferToPhone,
            //HS call transfer to headset notification
            BtAmwHsCallTransferToHeadset,
            //
            BtAmwHfConnect,
            //
            BtAmwHfDisconnect,
            //
            BtAmwHfAudio2Phone,
            //
            BtAmwHfAudio2Hf,
            //FAX connection established notification
            BtAmwFaxConnect,
            //FAX connection released notification
            BtAmwFaxDisconnect,
            // to inform use supported profile
            BtAmwSupportedProfile,
            // Service Verify
            BtAmwServiceVerify

        } BtAmwType;

        BtAlertMessageWindow();

        virtual ~BtAlertMessageWindow();


        void Init();


        void Display(BtAmwType amw_type, BOOLEAN success);
};

class BtRequestRunningWindow : public MmiWaitingBox
{
    private:
        typedef MmiWaitingBox Base;

    public:
        // Enumeration for text display in allert box
        typedef enum
        {
            // Unknwon Request running
            BtRrwUnknown = -1,
            // Pairing
            BtRrwPair,
            // Unpairing
            BtRrwUnpair,
            // Trusing
            BtRrwTrust,
            // Untrusting
            BtRrwUntrust,
            // Setting remote device name
            BtRrwSetName,
            // Querying the supported accessory profiles
            BtRrwQuerySupportedProfiles,
            // Searching devices
            BtRrwDeviceSearch,
            // Dun disconnect
            BtRrwDunDisconnect,
            //HS connect 
            BtRrwHsConnect,
            //HS disconnect
            BtRrwHsDisconnect,
            //HS call transfer to phone
            BtRrwHsCallTransferToPhone,
            //HS call transfer to headset
            BtRrwHsCallTransferToHeadset,
            //
            BtRrwHfConnect,
            //
            BtRrwHfDisconnect,      
            //
            BtRrwHfAudio2Hf,
            //
            BtRrwHfAudio2Phone,
            //FAX disconnect
            BtRrwFaxDisconnect,
            // Service Verify
            BtRrwServiceVerify
        } BtRrwType;

    public:
        BtRequestRunningWindow();

        virtual ~BtRequestRunningWindow();


        void Init();


        void SetType(BtRrwType type);


        void SetCancelableRequest(BtCancelableRequest* cancelable_request);


        BtCancelableRequest* GetCancelableRequest();


        const BtCancelableRequest* GetCancelableRequest() const;

    protected:

        virtual void OnOpen();


        virtual BOOLEAN OnCancel();


    //  virtual BOOLEAN OnMessage(const Message& message);
        void OnRequestCancel();   


    private:
        BtRrwType m_type;

        BtCancelableRequest* m_cancelable_request;
};

class BtPasskeyRequiredWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:
        BtPasskeyRequiredWindow();

        virtual ~BtPasskeyRequiredWindow();


        void Init();


        void SetRemoteDeviceAddress(const BtDeviceAddress& remote_device_address);


        void SetRemoteDeviceName(const WString& remote_device_name);

    protected:

        virtual BOOLEAN OnTimeout(const Timer &timer);
        

        virtual BOOLEAN OnMessage(const Message& message);


        virtual void OnOpen();


        virtual void OnLayoutClient();


        virtual BOOLEAN OnConfirm();


        virtual BOOLEAN OnKeyDown(KeyCode code);

        virtual BOOLEAN OnCancel();

    private:
        void Cleanup();
        BtDeviceAddress m_remote_device_address;
        WString         m_remote_device_name;

        TextBox        m_passkey_caption;
        PasswordEditor m_passkey_edit;

        Timer           m_timer;
        BtApplicationSendPasskeyRequest m_send_passkey_request;
};

class BtAuthorizationRequiredWindow : public MmiWindow
{
    private:
        typedef MmiWindow Base;

    public:
        BtAuthorizationRequiredWindow();

        virtual ~BtAuthorizationRequiredWindow();


        void Init();


        void SetRemoteDeviceAddress(const BtDeviceAddress& remote_device_address);


        void SetRemoteDeviceName(const WString& remote_device_name);


        void SetProfile(BtProfile profile);

    protected:

        virtual void OnOpen();


        virtual void OnLayoutClient();


        virtual BOOLEAN OnConfirm();


        virtual BOOLEAN OnKeyDown(KeyCode code);

        virtual BOOLEAN OnCancel();

        

    private:
        
        void Cleanup();
        
        BtDeviceAddress m_remote_device_address;
        WString         m_remote_device_name;
        BtProfile       m_profile;

        TextBox m_authorization_caption;

        ItemMenu m_item_menu;

        RadioButtonGroup  m_radio_button_group;
        RadioButtonAction m_trust_action;
        RadioButtonAction m_untrust_action;

        BtApplicationRespondAuthorizationRequest m_respond_authorization_request;
};



#endif /* BtApplicationWindows_hpp*/
