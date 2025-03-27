/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtApplicationRequests_hpp)
#define BtApplicationRequests_hpp

#include <Bluetooth/BtSendPasskeyRequest.hpp>
#include <Bluetooth/BtRespondAuthorizationRequest.hpp>
#include <Bluetooth/BtDevicePairRequest.hpp>
#include <Bluetooth/BtDeviceUnpairRequest.hpp>
#include <Bluetooth/BtDeviceTrustRequest.hpp>
#include <Bluetooth/BtDeviceUntrustRequest.hpp>
#include <Bluetooth/BtSetRemoteDeviceNameRequest.hpp>
#include <Bluetooth/BtQuerySupportedProfilesRequest.hpp>
#include <Bluetooth/BtDeviceSearchRequest.hpp>
#include <Bluetooth/BtServiceVerifyRequest.hpp>

class BtDeviceListWindow;
class BtDeviceDetailWindow;
class BtServiceSupportedWindow;

/*  ------------------------------------------------------------------------
    BtApplicationSendPasskeyRequest
    ------------------------------------------------------------------------ */

class BtApplicationSendPasskeyRequest : public BtSendPasskeyRequest
{
    private:
        typedef BtSendPasskeyRequest Base;

    public:
        BtApplicationSendPasskeyRequest();

        virtual ~BtApplicationSendPasskeyRequest();


    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

};

/*  ------------------------------------------------------------------------
    BtApplicationRespondAuthorizationRequest
    ------------------------------------------------------------------------ */

class BtApplicationRespondAuthorizationRequest : public BtRespondAuthorizationRequest
{
    private:
        typedef BtRespondAuthorizationRequest Base;

    public:
        BtApplicationRespondAuthorizationRequest();

        virtual ~BtApplicationRespondAuthorizationRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);
};

/*  ------------------------------------------------------------------------
    BtApplicationDevicePairRequest
    ------------------------------------------------------------------------ */

class BtApplicationDevicePairRequest : public BtDevicePairRequest
{
    private:
        typedef BtDevicePairRequest Base;

    public:
        BtApplicationDevicePairRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationDevicePairRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtDeviceListWindow* m_device_list_window;
};

/*  ------------------------------------------------------------------------
    BtApplicationDevicePairRequest
    ------------------------------------------------------------------------ */

class BtApplicationDeviceUnpairRequest : public BtDeviceUnpairRequest
{
    private:
        typedef BtDeviceUnpairRequest Base;

    public:
        BtApplicationDeviceUnpairRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationDeviceUnpairRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtDeviceListWindow* m_device_list_window;
};

/*  ------------------------------------------------------------------------
    BtApplicationDeviceTrustRequest
    ------------------------------------------------------------------------ */

class BtApplicationDeviceTrustRequest : public BtDeviceTrustRequest
{
    private:
        typedef BtDeviceTrustRequest Base;

    public:
        BtApplicationDeviceTrustRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationDeviceTrustRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtDeviceListWindow* m_device_list_window;
};

/*  ------------------------------------------------------------------------
    BtApplicationDeviceUntrustRequest
    ------------------------------------------------------------------------ */

class BtApplicationDeviceUntrustRequest : public BtDeviceUntrustRequest
{
    private:
        typedef BtDeviceUntrustRequest Base;

    public:
        BtApplicationDeviceUntrustRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationDeviceUntrustRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtDeviceListWindow* m_device_list_window;
};

/*  ------------------------------------------------------------------------
    BtApplicationQuerySupportedProfilesRequest
    ------------------------------------------------------------------------ */

class BtApplicationQuerySupportedProfilesRequest : public BtQuerySupportedProfilesRequest
{
    private:
        typedef BtQuerySupportedProfilesRequest Base;

    public:
        BtApplicationQuerySupportedProfilesRequest(BtDeviceDetailWindow* device_detail_window);
        BtApplicationQuerySupportedProfilesRequest(BtDeviceListWindow* device_list_window);

        enum BtQueryRequestSupportWinType
        {
            TDeviceDetail,
            TDeviceList
        };
        virtual ~BtApplicationQuerySupportedProfilesRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtQueryRequestSupportWinType m_type;
        BtDeviceDetailWindow* m_device_detail_window;
        BtDeviceListWindow* m_device_list_window;
};

/*  ------------------------------------------------------------------------
    BtApplicationSetRemoteDeviceNameRequest
    ------------------------------------------------------------------------ */

class BtApplicationSetRemoteDeviceNameRequest : public BtSetRemoteDeviceNameRequest
{
    private:
        typedef BtSetRemoteDeviceNameRequest Base;

    public:
        BtApplicationSetRemoteDeviceNameRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationSetRemoteDeviceNameRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtDeviceListWindow* m_device_list_window;

};

/*  ------------------------------------------------------------------------
    BtApplicationDeviceSearchRequest
    ------------------------------------------------------------------------ */

class BtApplicationDeviceSearchRequest : public BtDeviceSearchRequest
{
    private:
        typedef BtDeviceSearchRequest Base;

    public:
        BtApplicationDeviceSearchRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationDeviceSearchRequest();

        void CancelSearchRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

        virtual void OnRemoteDeviceName(const BtDevice& remote_device, const WString& remote_device_name);

    private:
        BtDeviceListWindow* m_device_list_window;
};

/*  ------------------------------------------------------------------------
    BtApplicationServiceVerifyRequest
    ------------------------------------------------------------------------ */

class BtApplicationServiceVerifyRequest: public BtServiceVerifyRequest
{
    private:
        typedef BtServiceVerifyRequest Base;

    public:
        BtApplicationServiceVerifyRequest(BtDeviceListWindow* device_list_window);

        virtual ~BtApplicationServiceVerifyRequest();

    protected:

        virtual void OnRequestStateChange(BtRequestState old_request_state, BtRequestState new_request_state);

    private:
        BtDeviceListWindow* m_device_list_window;
};

#endif /* BtApplicationRequests_hpp */

