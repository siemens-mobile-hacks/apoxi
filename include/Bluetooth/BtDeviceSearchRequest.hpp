/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceSearchRequest_hpp)
#define BtDeviceSearchRequest_hpp

#include <Bluetooth/BtDeviceList.hpp>
#include <Bluetooth/BtCancelableBroadcastRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtDeviceSearchRequest: public BtCancelableBroadcastRequest
{
    private:
        typedef BtCancelableBroadcastRequest Base;

    public:
        BtDeviceSearchRequest();

        virtual ~BtDeviceSearchRequest();


        virtual BtRequestType GetRequestType() const;


        BtDeviceAndServiceClass GetDeviceAndServiceClass() const;


        void SetDeviceAndServiceClass(BtDeviceAndServiceClass device_and_service_class);


        UINT8 GetMaximalFoundDevices() const;


        void SetMaximalFoundDevice(UINT8 maximal_found_devices = 0);


        UINT8 GetInquiryTimeOut() const;


        void SetInquiryTimeOut(UINT8 inquiry_time_out = 0);


        BtInquiryAccessCode GetInquiryAccessCode() const;


        void SetInquiryAccessCode(BtInquiryAccessCode inquiry_access_code);


        BOOLEAN GetQueryRemoteDeviceName() const;


        void SetQueryRemoteDeviceName(BOOLEAN query_remote_device_name);


        BOOLEAN GetImmediatlyRetrieveRemoteDeviceNames() const;


        void SetImmediatlyRerieveRemoteDeviceNames(BOOLEAN immediatly_rerieve_names);


        const BtDeviceList& GetDeviceList() const;

    protected:

        virtual BOOLEAN Execute();


        virtual BOOLEAN Cancel();


        virtual void RegisterMessages(void) const;


        virtual void UnregisterMessages(void) const;


        virtual BOOLEAN OnMessage(const Message& message);

        /* #################################################################
            ATTENTION: Obsolete, only for backward compatiblities - Start
           ############################################################## */


        virtual void OnRemoteDeviceFound(const BtDevice& remote_device, const BtDeviceAndServiceClass& remote_device_and_service_class);

        /* #################################################################
            ATTENTION: Obsolete, only for backward compatiblities - End
           ############################################################## */


        virtual void OnRemoteDeviceFound(const BtDevice& remote_device, const BtDeviceAndServiceClass& remote_device_and_service_class, UINT8 signal_strength);


        virtual void OnRemoteDeviceName(const BtDevice& remote_device, const WString& remote_device_name);

    private:

        const btapi_device_search_req_t* GetApiSettings() const;

    private:
        btapi_device_search_req_t m_api_device_search_request;

        BtDeviceList m_device_list;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtDeviceSearchRequest_hpp


