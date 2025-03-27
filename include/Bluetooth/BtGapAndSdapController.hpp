/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtGapAndSdapController_hpp)
#define BtGapAndSdapController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <stack/extensions.h>
#include <Kernel/Os/Mutex.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtDeviceAndServiceClass.hpp>
#include <Bluetooth/BtLocalSettings.hpp>
#include <Bluetooth/BtDeviceList.hpp>
#include <Bluetooth/BtController.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtLocalSettings;
class BtDevice;
class BtDeviceList;

class BtTransport;

class BtSetRemoteDeviceNameRequest;
class BtDevicePairRequest;
class BtDeviceUnpairRequest;
class BtDeviceTrustRequest;
class BtDeviceUntrustRequest;
class BtQuerySupportedProfilesRequest;
class BtSendPasskeyRequest;
class BtRespondAuthorizationRequest;
class BtDeviceSearchRequest;
class BtServiceVerifyRequest;

class BtSddbRegisterServiceRecordRequest;
class BtSddbUnregisterServiceRecordRequest;

class BtConnectionlessController;
class BtConnectionBasedController;

class BtGapAndSdapController: public BtController
{
    private:
        typedef BtController Base;

    public:

        static BtGapAndSdapController& GetInstance();

    public:
        virtual ~BtGapAndSdapController();


        virtual const WCHAR* GetName() const;


        virtual UINT8 GetPriority() const;

    protected:

        virtual void Init();


        virtual void Register();


        virtual void Unregister();


        virtual btapi_userid_t GetUserId() const;


        void SetUserId(btapi_userid_t user_id);


        virtual btapi_cb_funp_t* GetCallbackFunctionPointers() const;


        void SetCallbackFunctionPointers(btapi_cb_funp_t* callback_functions);

    private:
        /*---------------------------------------------------------------------*/
        /* The following functions are used for the device list management     */
        /*---------------------------------------------------------------------*/


        BOOLEAN GetFilteredDeviceList(BtDeviceList& device_list, const BtDeviceFilter& device_filter);


        BOOLEAN GetKnownDeviceList(BtDeviceList& device_list);


        BOOLEAN GetPairedDeviceList(BtDeviceList& device_list);

        /*---------------------------------------------------------------------*/
        /* The following functions are used for the local Bluetooth Device     */
        /*---------------------------------------------------------------------*/


        BtStackState GetLocalState() const;


        BtResultCode TurnOnRequest(BtLocalSettings* local_settings = 0);


        BtResultCode TurnOffRequest(BtLocalSettings* local_settings = 0);


        BOOLEAN GetChipVersion(BtChipVersion& chip_version) const;


        BOOLEAN GetLocalAddress(BtDeviceAddress& device_address) const;


        BOOLEAN GetLocalName(WString& local_name) const;


        BtResultCode SetLocalNameRequest(const WString& local_name, BtLocalSettings* local_settings = 0);


        BOOLEAN GetDiscoverableMode(BtDiscoverableMode& discoverable_mode) const;


        BtResultCode SetDiscoverableModeRequest(BtDiscoverableMode discoverable_mode = BtDmGeneralDiscoverable, BtLocalSettings* local_settings = 0);


        BOOLEAN GetPairableMode(BtPairableMode& pairable_mode) const;


        BtResultCode SetPairableModeRequest(BtPairableMode pairable_mode = BtPmPairable, BtLocalSettings* local_settings = 0);


        BOOLEAN GetConnectableMode(BtConnectableMode& connectable_mode) const;


        BtResultCode SetConnectableModeRequest(BtConnectableMode connectable_mode = BtCmConnectable, BtLocalSettings* local_settings = 0);


        BOOLEAN GetIsProfileActive(BtProfile profile, BOOLEAN& active);


        BtResultCode SetIsProfileActiveRequest(BtProfile profile, BOOLEAN active, BtLocalSettings* local_settings = 0);

        /*---------------------------------------------------------------------*/
        /* The following functions are for remote Bluetooth devices            */
        /*---------------------------------------------------------------------*/


        BOOLEAN GetRemoteDeviceInformation(btapi_bdaddr_t& device_address, btapi_known_device_t& device_information) const;


        BOOLEAN SetRemoteDeviceNameRequest(BtSetRemoteDeviceNameRequest* set_remote_device_name_request);


        BOOLEAN DevicePairRequest(BtDevicePairRequest* device_pair_request);


        BOOLEAN DeviceUnpairRequest(BtDeviceUnpairRequest* device_unpair_request);


        BOOLEAN DeviceTrustRequest(BtDeviceTrustRequest* device_trust_request);


        BOOLEAN DeviceUntrustRequest(BtDeviceUntrustRequest* device_untrust_request);


        BOOLEAN QuerySupportedProfilesRequest(BtQuerySupportedProfilesRequest* query_supported_profiles_request);


        BOOLEAN SendPasskeyRequest(const btapi_passkey_rsp_t& passkey_response);


        BOOLEAN RespondAuthorizationRequest(const btapi_authorisation_rsp_t& authorization_response);


        BOOLEAN DeviceSearchRequest(BtDeviceSearchRequest* device_search_request);


        BOOLEAN CancelDeviceSearchRequest();


        BOOLEAN ServiceVerfiyRequest(BtServiceVerifyRequest* service_verify_request);

        BOOLEAN CancelServiceVerifyRequest();

        /*---------------------------------------------------------------------*/
        /* The following functions are for the SDDB                            */
        /*---------------------------------------------------------------------*/


        BOOLEAN SddbRegisterServiceRecordRequest(BtSddbRegisterServiceRecordRequest* register_service_record_request);


        BOOLEAN SddbUnregisterServiceRecordRequest(BtSddbUnregisterServiceRecordRequest* unregister_service_record_request);

    private:
        /*---------------------------------------------------------------------*/
        /* The following functions must not be called by an application.       */
        /* They are the entry point from the stack callback functions into our */
        /* object orientated framework (APOXI).                                */
        /* They are implemented as static because they have to be passed as    */
        /* normal C function pointers. The reason for this is the BT-API Stack */
        /* interface that demands C function pointers for callback the         */
        /* callback functions it calls to state the progress of ongoing        */
        /* operations                                                          */
        /*---------------------------------------------------------------------*/


        static void OnStateChangedCallback(btapi_result_t result, btapi_stack_state_t state);


        void OnStateChanged(BtResultCode result, BtStackState state);


        static void OnGapCommonCallback(btapi_result_t result, btapi_common_gapcb_t type);


        void OnSetLocalName(BtResultCode result);


        void OnSetDiscoverable(BtResultCode result);


        void OnSetPairable(BtResultCode result);


        void OnSetConnectable(BtResultCode result);


        void OnPairedDeviceNameChange(BtResultCode result);


        void OnCreateBond(BtResultCode result);


        void OnPairedDeviceDelete(BtResultCode result);


        void OnPairedDeviceTrustChange(BtResultCode result);


        static void OnGapAuthorizationRequestCallback(btapi_result_t result, const btapi_authorisation_req_t *authorization_request);


        void OnAuthorization(BtResultCode result, const btapi_authorisation_req_t *authorization_request);


        static void OnGapPasskeyRequestCallback(btapi_result_t result, const btapi_passkey_req_t *passeky_request);


        void OnPasskey(BtResultCode result, const btapi_passkey_req_t *passeky_request);


        static void OnSdapCommonCallback(btapi_result_t result, btapi_common_sdapcb_t type);


        void OnAccessoryReq(BtResultCode result);


        void OnInquiry(BtResultCode result);


        void OnServiceSearch(BtResultCode result);


        void OnCancel(BtResultCode result);


        static void OnSdapRemoteDeviceCallback(btapi_result_t result, const btapi_remote_device_t *remote_device);


        void OnSdapRemoteDevice(const btapi_remote_device_t *remote_device);


        static void OnSdapRemoteDeviceNameCallback(btapi_result_t result, const btapi_remote_name_t *remote_name);


        void OnSdapRemoteDeviceName(const btapi_remote_name_t *remote_name);


        static void OnSdapServiceSearchCallback(btapi_result_t result, const btapi_service_search_rsp_t *service_search_response);


        void OnSdapServiceSearchResult(BtResultCode result, const btapi_service_search_rsp_t *service_search_response);


        static void OnSdapHsServiceCallback(btapi_result_t result, const btapi_hs_service_t *hs_service);


        void OnSdapHsService(BtResultCode result, const btapi_hs_service_t *hs_service);


        static void OnSdapHfServiceCallback(btapi_result_t result, const btapi_hf_service_t *hf_service);


        void OnSdapHfService(BtResultCode result, const btapi_hf_service_t *hf_service);


        static void OnSdapPaServiceCallback(btapi_result_t result, const btapi_pa_service_t *pa_service);


        void OnSdapPaService(BtResultCode result, const btapi_pa_service_t *pa_service);


        static void OnSddbServiceRegisterCallback(btapi_result_t result, const btapi_service_register_t* service_register);


        void OnSddbServiceRegister(BtResultCode result, const btapi_service_register_t* service_register);


        static void OnProfileActiveCallback(btapi_result_t result, const btapi_profile_active_t *response);


        void OnProfileActive(BtResultCode result, const btapi_profile_active_t *response);

    private:
        BtGapAndSdapController();


        BtRequest* GetExecutingRequest() const;


        BOOLEAN PrepareRequestExecution(BtRequest* request);


        BtRequest* CleanUpRequestExecution(BtResultCode result, BtRequestType request_type);


        BtResultCode PerpareLocalRequestExecution(BtResultCode* result, BtLocalSettings* local_settings);


        void CleanUpLocalRequestExecution(BtResultCode result, BtLocalSettings* local_settings);


        UINT32 CallLocalRequestCallback(BtResultCode result, INT message_id);


        BOOLEAN AddControllerForRegistration(BtController* controller);

    private:

        class BtControllerListElement
        {
            public:
                BtControllerListElement();

                virtual ~BtControllerListElement();

            public:

                BtController* GetController() const;


                void SetController(BtController* controller);


                BtControllerListElement* GetNext() const;


                void SetNext(BtControllerListElement* next);

            private:
                BtController* m_controller;

                BtControllerListElement* m_next;
        };


        static void BtStartupTimerFunction(void* timer_function_data);

    private:
        btapi_userid_t m_user_id;

        btapi_cb_funp_t* m_callback_functions;

        btapi_gapcb_funp_t* m_gap_callback_functions;

        btapi_sdapcb_funp_t* m_sdap_callback_functions;

        Mutex m_executing_request_mutex;

        BtRequest* m_executing_request;

        Mutex m_executing_local_request_mutex;

        BtLocalSettings* m_executing_local_request;

        BtResultCode* m_executing_local_request_result;

        BtControllerListElement* m_controller_list_anchor;

    private:
        static BtGapAndSdapController m_controller;

        static SystemTimer m_startup_timer;

    private:
        friend class BtLocalSettings;
        friend class BtDevice;
        friend class BtDeviceList;

        friend class BtTransport;

        friend class BtSetRemoteDeviceNameRequest;
        friend class BtDevicePairRequest;
        friend class BtDeviceUnpairRequest;
        friend class BtDeviceTrustRequest;
        friend class BtDeviceUntrustRequest;
        friend class BtQuerySupportedProfilesRequest;
        friend class BtSendPasskeyRequest;
        friend class BtRespondAuthorizationRequest;
        friend class BtDeviceSearchRequest;
        friend class BtServiceVerifyRequest;

        friend class BtSddbRegisterServiceRecordRequest;
        friend class BtSddbUnregisterServiceRecordRequest;

        friend class BtConnectionlessController;
        friend class BtConnectionBasedController;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtGapAndSdapController_hpp


