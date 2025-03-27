/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceDetailWindow_hpp)
#define BtDeviceDetailWindow_hpp

#include <Common/MmiWindow.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <BtApp/BtApplicationWindows.hpp>
#include <BtApp/BtApplicationRequests.hpp>


class BtDeviceDetailWindow : public MmiWindow 
{
    private:
        typedef MmiWindow Base;

    public:
        BtDeviceDetailWindow();

        virtual ~BtDeviceDetailWindow();


        void Init();


        const BtDevice& GetDevice();


        void SetDevice(const BtDevice& device);

        void OnSupportedProfileSearch();


    
    protected:

        virtual void OnOpen();

        void OnRequestFinished(BOOLEAN success);


    private:


        void GetDeviceAndServiceClassString();


    private:

        BtDevice m_device;

        enum CaptionList
        {
            MaCaptionDeviceName,
            MaCaptionDeviceAddress,
            MaCaptionDeviceStatus,
            MaCaptionConnected,
            MaCaptionMajorDeviceClass,
            MaCaptionServiceClass,
            MaCaptionLast
        };

        WString     m_caption_list[MaCaptionLast];

        enum ValueList
        {
            MaValueDeviceName,
            MaValueDeviceAddress,
            MaValueDeviceStatus,
            MaValueConnected,
            MaValueMajorDeviceClass,
            MaValueServiceClass,
            MaValueLast
        };

        WString     m_value_list[MaValueLast];


        WString     m_device_name;
        WString     m_device_address;


        MultiLineEditor     m_multiline_editor;

        WString     m_editor_string;
    
        BtAlertMessageWindow m_alert_message_window;
        BtRequestRunningWindow m_request_running_window;

        BtApplicationQuerySupportedProfilesRequest m_query_supported_profiles_request;

    private:
        friend class BtApplicationQuerySupportedProfilesRequest;
};



#endif /* BtDeviceListsWindows_hpp */
