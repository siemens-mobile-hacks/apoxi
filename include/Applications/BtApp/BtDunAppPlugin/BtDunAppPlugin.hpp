/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_BtDunAppPlugin_hpp)
#define Mmi_BtDunAppPlugin_hpp
#include <Common/MmiApplicationPlugin.hpp>
#include <BtApp/BtApplication.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include <Bluetooth/DUN/BtDunApplicationMessage.hpp>
#include "BtDunProfileService.hpp"

class BtDunAppPlugin : public MmiApplicationPlugin
{
    typedef MmiApplicationPlugin Base;

    public:

        virtual ~BtDunAppPlugin();

        void Init(Application* app);

        static BtDunAppPlugin* GetInstance();
        
        virtual BOOLEAN OnMessage(const Message &msg);

        /*Remote device and local device both can initiate dun disconnect. In this function
        the added menu and indicator should be remove.
        */
        void OnDunDisconnectRequestFinished(BOOLEAN success);
    
    protected:
        virtual void OnAppOpen();
        virtual void OnAppClose();
        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);
    
    private:

        BtDunAppPlugin();


        BOOLEAN OnDunConnect(BtResultCode result, const BtDevice& device);
        BOOLEAN OnDunDisconnect(BtResultCode result);
        void DoDunDisconnect();


    private:
        
        //Action m_dun_disconnect_action;
        Feature m_dun_disconnect_feature;
        Property m_dun_prop;
        static BtDunAppPlugin m_plugin;

        BtApplication* m_host_app;

        BtDunProfileService m_dun_profile_service;
        BtAlertMessageWindow m_alert_message_window;
        
        BtRequestRunningWindow m_request_running_window;


};
#endif  // Mmi_AppPlugin_hpp

