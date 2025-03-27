/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsController_hpp)
#define BtHsController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <stack/extensions.h>
#include <Devices/AudioAccessoryDetails.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtSingleConnectionController.hpp>
#include <Bluetooth/HS/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtHsService;
class BtHsConnectRequest;
class BtHsDisconnectRequest;
class BtHsRingRequest;
class BtHsStopRingRequest;
class BtHsTransferAudioToPhoneRequest;
class BtHsTransferAudioToAccessoryRequest;
class BtHsSetMicrophoneGainRequest;
class BtHsSetSpeakerGainRequest;

class BtHsController : public BtSingleConnectionController
{
    private:
        typedef BtSingleConnectionController Base;

    public:

        static BtHsController& GetInstance();

    public:
        virtual ~BtHsController();


        virtual const WCHAR* GetName() const;

    protected:

        BOOLEAN HsRingRequest(BtHsRingRequest* ring_request);


        BOOLEAN HsStopRingRequest(BtHsStopRingRequest* stop_ring_request);


        BOOLEAN HsTransferAudioToPhoneRequest(BtHsTransferAudioToPhoneRequest* transfer_audio_to_phone_request);


        BOOLEAN HsTransferAudioToAccessoryRequest(BtHsTransferAudioToAccessoryRequest* transfer_audio_to_accessory_request);


        BOOLEAN HsSetMicrophoneGainRequest(BtHsSetMicrophoneGainRequest* set_microphone_gain_request);


        BOOLEAN HsSetSpeakerGainRequest(BtHsSetSpeakerGainRequest* set_speaker_gain_request);


        BtHsState GetState(const BtDevice& device) const;


        BOOLEAN GetIsRinging(const BtDevice& device) const;


        void SetIsRinging(const BtDevice& device, BOOLEAN is_ringing);


        BtHsCallLocation GetCallLocation(const BtDevice& device) const;


        void SetCallLocation(const BtDevice& device, BtHsCallLocation call_location);


        UINT8 GetMicrophoneGain(const BtDevice& device) const;


        UINT8 GetSpeakerGain(const BtDevice& device) const;


        BOOLEAN GetLowPowerModePossible() const;


        const BtDevice& GetLastConnectedDevice() const;


        void SetLastConnectedDevice(const BtDevice& last_connected_device);

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
        

        static void OnHsCommonCallback(btapi_result_t result,btapi_common_hscb_t type);


        void OnHsRing(BtResultCode result);


        void OnHsStopRing(BtResultCode result);


        void OnHsAudioConnectionLost(BtResultCode result);


        void OnHsLowPowerModeNotPosssible(BtResultCode result);


        static void OnHsConnectCallback(btapi_result_t result, btapi_bdaddr_t api_device_address);


        void OnHsConnect(BtResultCode result, BtDeviceAddress& device_address);


        static void OnHsDisconnectCallback(btapi_result_t result, btapi_bdaddr_t api_device_address);


        void OnHsDisconnect(BtResultCode result);


        static void OnHsAudioCallback(btapi_result_t result, btapi_bool_t is_audio_at_phone);


        void OnHsAudio(BtResultCode result, BOOLEAN is_audio_at_phone);


        void OnHsTransferAudioToPhoneRequest(BtHsTransferAudioToPhoneRequest* request, BtResultCode result, BOOLEAN is_audio_at_phone);


        void OnHsTransferAudioToAccessoryRequest(BtHsTransferAudioToAccessoryRequest* request, BtResultCode result, BOOLEAN is_audio_at_phone);


        void OnHsTransferAudio(BtResultCode result, BOOLEAN is_audio_at_phone);


        static void OnHsMicrophoneGainCallback(btapi_result_t result, btapi_u8_t gain);


        void OnHsMicrophoneGain(BtResultCode result, UINT8 microphone_gain);


        static void OnHsSpeakerGainCallback(btapi_result_t result, btapi_u8_t gain);


        void OnHsSpeakerGain(BtResultCode result, UINT8 speaker_gain);


        void OnAudioPathConnected(BOOLEAN connected, BOOLEAN update_path);

    private:
        BtHsController();


        virtual void Register();


        virtual void Unregister();


        void SetState(BtHsState state);


        void SetMicrophoneGain(UINT8 microphone_gain);


        void SetSpeakerGain(UINT8 speaker_gain);


        void SetLowPowerModePossible(BOOLEAN low_power_mode_possible);


        BOOLEAN SwitchAudio(BOOLEAN connected, BOOLEAN switch_path);


        void SetRunningAudioSetConnected(BOOLEAN running, BOOLEAN connected, BOOLEAN switch_path);


        void SetPendingAudioCallback(BOOLEAN pending, BOOLEAN connected, BOOLEAN switch_path);


        void CheckPendingAudioCallback();

    private:
        class BtHsAudioAccessoryDetails: public AudioAccessoryDetails
        {
            private:
                typedef AudioAccessoryDetails Base;

            public:
                BtHsAudioAccessoryDetails();


                virtual void OnAudioPathConnected(BOOLEAN connected, BOOLEAN update_path);
        };  // BtHsAudioAccessoryDetails

#ifdef _DEBUG
    private:

        void DebugState();
#endif /* _DEBUG */

    private:
        btapi_hscb_funp_t* m_hs_callback_functions;

        BtHsState m_hs_state;

        BOOLEAN m_is_ringing;

        BtHsCallLocation m_call_location;

        BOOLEAN m_low_power_mode_possible;

        BtDevice m_last_connected_device;

        UINT8 m_microphone_gain;

        UINT8 m_speaker_gain;

        BOOLEAN m_in_audio_switch;

        BtHsAudioAccessoryDetails m_audio_accessory_details;

        Semaphore m_audio_callback_pending_semaphore;

        BOOLEAN m_audio_set_connected_running;

        BOOLEAN m_audio_set_connected_connected;

        BOOLEAN m_audio_set_connected_switch_path;

        BOOLEAN m_audio_callback_pending;

        BOOLEAN m_audio_callback_connected;

        BOOLEAN m_audio_callback_switch_path;

    private:
        static BtHsController m_controller;

    private:
        friend class BtHsController::BtHsAudioAccessoryDetails;

    private:
        friend class BtHsService;
        friend class BtHsConnectRequest;
        friend class BtHsDisconnectRequest;
        friend class BtHsRingRequest;
        friend class BtHsStopRingRequest;
        friend class BtHsTransferAudioToPhoneRequest;
        friend class BtHsTransferAudioToAccessoryRequest;
        friend class BtHsSetMicrophoneGainRequest;
        friend class BtHsSetSpeakerGainRequest;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHsController_hpp

