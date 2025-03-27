/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSetRemoteDeviceNameRequest_hpp)
#define BtSetRemoteDeviceNameRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtSetRemoteDeviceNameRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtSetRemoteDeviceNameRequest(const BtDevice& device);

        virtual ~BtSetRemoteDeviceNameRequest();


        virtual BtRequestType GetRequestType() const;


        const WString& GetRemoteDeviceName() const;


        void SetRemoteDeviceName(const WString& remoted_device_name);

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);

    private:

        const btapi_utf8_t* GetApiSettings() const;

    private:
        WString m_remote_device_name;

        btapi_utf8_t* m_utf8_remote_device_name;

    private:
        friend class BtGapAndSdapController;
};

#endif  // BtSetRemoteDeviceNameRequest_hpp


