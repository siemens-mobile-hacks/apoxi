/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_BtFaxAppPlugin_hpp)
#define Mmi_BtFaxAppPlugin_hpp

#include <Common/MmiApplicationPlugin.hpp>
#include <Bluetooth/FAX/BtFaxApplicationMessage.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include <BtApp/BtApplication.hpp>
#include "BtFaxProfileService.hpp"

class BtFaxAppPlugin : public MmiApplicationPlugin
{
    typedef MmiApplicationPlugin Base;

    public:

        virtual ~BtFaxAppPlugin();

        void Init(Application* app);

        static BtFaxAppPlugin* GetInstance();
        
        virtual BOOLEAN OnMessage(const Message &msg);

        void OnFaxDisconnectRequestFinished(BOOLEAN success);
        
    
    protected:
        virtual void OnAppOpen();
        virtual void OnAppClose();
        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);

    private:

        BtFaxAppPlugin();


        BOOLEAN OnFaxConnect(BtResultCode result, const BtDevice& device);
        
        /*In this function the added menu and indicator should be remove.
        */
        BOOLEAN OnFaxDisconnect(BtResultCode result);
        void DoFaxDisconnect();

    private:
        
       // Action m_fax_disconnect_action;
        Feature m_fax_disconnect_feature;
        Property m_fax_prop;

        static BtFaxAppPlugin m_plugin;

        BtApplication* m_host_app;

        BtFaxProfileService m_fax_profile_service;
        
        BtAlertMessageWindow m_alert_message_window;
        
        BtRequestRunningWindow m_request_running_window;

};
#endif  // Mmi_AppPlugin_hpp

