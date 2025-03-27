/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_LcsSettingsApp_hpp)
#define Mmi_LcsSettingsApp_hpp

#include <Common/MmiApplication.hpp>
#include <Atl/Properties/Property.hpp>
#include <Common/Properties/Descriptors/SetPropertyDescriptor.hpp>
#include <Atl/Gui/AtlItemMenuWindow.hpp>

#include "AidingDataWin.hpp"
#include "ServerAddressWin.hpp"
#include "SelfLocationDialogWin.hpp"

class LcsSettingsApp : public MmiApplication
{
    typedef MmiApplication Base;
    
    public:

        virtual ~LcsSettingsApp();

        static LcsSettingsApp* GetInstance();

    protected:

        virtual void OnStartup();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnOpen();

        virtual void OnClose();

        virtual BOOLEAN OnFeatureTriggered(const FeatureID& feature_id);

        virtual BOOLEAN OnPropertyNotification(const Property::Notification notification,
                                                const Property* property,
                                                const DataItem& value);


    private:

        LcsSettingsApp();

        void RegisterProperties();


    private:

        static LcsSettingsApp m_lcs_settings_app;

        enum LcsSettingsFeatureId {
            GltpServers,
            GltpPosnFixCfg,
            LcsVersionInfo,
            LcsSettingsFeatureCnt
        };

        Feature m_features[LcsSettingsFeatureCnt];

        GltpAidingDataWin m_pos_fix_data_win;

        ServerAddressWin m_server_address_win;

        SelfLocationDialog m_self_loc_dlg;

        WString m_version_info;

        Property m_prop_protocols;
        SetPropertyDescriptor m_prop_desc_protocols;

        AtlItemMenuWindow m_gtlp_menu_win;

        enum UartSettingsPropertyId {
            NmeaBaudRate,
            NmeaDataBits,
            NmeaParity,
            NmeaStopBits,
            NmeaFlowControl,
            UartSettingsPropertyCnt
        };

        Property m_prop_uart_settings[UartSettingsPropertyCnt];
        SetPropertyDescriptor m_prop_desc_uart[UartSettingsPropertyCnt];

        Property m_prop_nmea_switch;

}; // LcsSettingsApp

#endif // Mmi_LcsSettingsApp_hpp
