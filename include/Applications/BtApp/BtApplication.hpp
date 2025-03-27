/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Bt_Application_hpp)
#define Bt_Application_hpp

#include <Common/MmiApplication.hpp>

#include <Bluetooth/BtLocalSettings.hpp>
#include <BtApp/BtLocalSettingsWindows.hpp>
#include <BtApp/BtDeviceListsWindows.hpp>
#include <BtApp/BtApplicationRequests.hpp>
#include <Bluetooth/BtGapAndSdapApplicationMessage.hpp>
#include <BtApp/BtActiveDeviceWindow.hpp>
#include <Atl/Features/Feature.hpp>
#include <Atl/Features/FeatureBroker.hpp>
#include <Bluetooth/BtTypes.hpp>



class BtApplication : public MmiApplication
{
    private:
        typedef MmiApplication Base;

    public:

        static BtApplication* GetInstance();

        virtual ~BtApplication();
        

        BtActiveDeviceWindow* GetActiveDeviceWindow(){return &m_active_device_window;}

        BtDeviceListWindow* GetDeviceListWindow(){return &m_device_list_window;}
        BtLocalSettings* GetLocalSettings() {return &m_local_settings;}
        virtual void OnStartup();
        void BtFeatureSetAvailable(const FeatureID &feature_id, BOOLEAN available);
        void BtRemoteDeviceListOptions();
        void SetIndicatorVisible(const String& str, BOOLEAN visible);

    
    private:

        BtApplication();

    protected:

        virtual void OnOpen();


        virtual void OnClose();


        virtual BOOLEAN OnMessage(const Message &message);
        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification, const Property* property, const DataItem &value);
        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);   

        BOOLEAN OnPasskeyRequired(const BtPasskeyRequiredMessage& message);

    
        BOOLEAN OnAuthorizationRequired(const BtAuthorizationRequiredMessage& message);

        // Is called, when a bt service has been actived(such as DUN,FAX...)
        virtual void OnBtActivated(BtProfile profile, BOOLEAN connected);



    private:

        void CreateFeatureItems(void);

        BOOLEAN OnRequestOperation(BtOperationPtr operation);
    private:
        // enum type for FeatureItems
        enum BtItemIds
        {
            BtDeviceListFeature, 
            BtActiveDeviceFeature, 
            BtOnOffFeature, 
            BtSearchDeviceFeature, 
            BtSearchProfileFeature, 
            BtPairFeature, 
            BtUnpairFeature, 
            BtTrustFeature, 
            BtUntrustFeature, 
            BtShowDetailsFeature, 
            BtObexSelectFeature, 
            BtDeviceSearchMode,
            BtLastFeature
        };

        //enum for properties
        enum BtProperty {
            BtLocalName,
            BtDiscoverable,
            BtPairable,
            BtConnectable,
            BtSetRemoteName,
            BtPropertyCnt   
        };


        INT GetPropertyID(FeatureID id) const;

        //Feature Items
        Feature     m_feature[BtLastFeature];

        //Property Items
        Property            m_property[BtPropertyCnt];

        BtPasskeyRequiredWindow         m_passkey_required_window;

        BtAuthorizationRequiredWindow   m_authorization_required_window;

        BtDeviceListWindow              m_device_list_window;

        BtActiveDeviceWindow            m_active_device_window;
        
        BtDeviceList                    m_device_list;

        BtLocalSettings                 m_local_settings;
        BtTurnOnOffWindow        m_turn_on_off_window;
        BtDevice                  m_device;
        BtDeviceSearchModeWindow  m_device_search_mode_window;
        static BtApplication m_application;

};

#endif  // BtApp_hpp


