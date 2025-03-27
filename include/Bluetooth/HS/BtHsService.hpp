/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHsService_hpp)
#define BtHsService_hpp

#include <Kernel/Application.hpp>
#include <Bluetooth/BtAudioAccessoryService.hpp>
#include <Bluetooth/HS/BtTypes.hpp>
#include <Bluetooth/HS/BtHsControllerMessage.hpp>
#include <Bluetooth/HS/BtHsConnectRequest.hpp>
#include <Bluetooth/HS/BtHsDisconnectRequest.hpp>
#include <Bluetooth/HS/BtHsRingRequest.hpp>
#include <Bluetooth/HS/BtHsStopRingRequest.hpp>
#include <Bluetooth/HS/BtHsTransferAudioToPhoneRequest.hpp>
#include <Bluetooth/HS/BtHsTransferAudioToAccessoryRequest.hpp>
#include <Bluetooth/HS/BtHsSetMicrophoneGainRequest.hpp>
#include <Bluetooth/HS/BtHsSetSpeakerGainRequest.hpp>

class BtHsService: public BtAudioAccessoryService
{
    private:
        typedef BtAudioAccessoryService Base;

    public:
        BtHsService();

        virtual ~BtHsService();


        virtual void Init();


        virtual BtProfile GetProfile() const;


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual void SetTargetDevice(const BtDevice& target_device);


        virtual BOOLEAN IsConnected() const;


        virtual BOOLEAN IsRinging() const;


        virtual BOOLEAN IsInCall() const;


        virtual BtRequestState ConnectRequest();


        virtual BtRequestState DisconnectRequest();


        virtual BtRequestState TransferAudioToPhoneRequest();


        virtual BtRequestState TransferAudioToAccessoryRequest();


        virtual UINT8 GetMicrophoneGain() const;


        virtual BtRequestState SetMicrophoneGainRequest(INT8 gain_offset);


        virtual UINT8 GetSpeakerGain() const;


        virtual BtRequestState SetSpeakerGainRequest(INT8 gain_offset);


        BOOLEAN GetConnectionOnlyDuringCall() const;


        void SetConnectionOnlyDuringCall(BOOLEAN connection_only_during_call);


        UINT16 GetRingInterval() const;


        void SetRingInterval(UINT16 ring_interval);


        UINT8 GetNumberOfRingSignals() const;


        void SetNumberOfRingSignals(UINT8 number_of_ring_signals);


        BtHsState GetState() const;

    public:

        static const BtDevice& GetLastConnectedDevice();


        static void SetLastConnectedDevice(const BtDevice& last_connected_device);

    protected:

        BtRequestState RingRequest();


        BtRequestState StopRingRequest(BOOLEAN keep_audio = FALSE);


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);


        virtual BOOLEAN OnCallEventMessage(const CallEventMsg& call_event_message);


        virtual BOOLEAN OnControllerMessage(const BtHsControllerMessage& controller_message);


        void AcceptCall();


        void ReleaseCall();

    private:

        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


        void TryAudioRequest(BtRequest* audio_request);


        void CheckPendingAudioRequest();

#ifdef _DEBUG
    private:

        const char* BtHsRequestAsString(BtRequest* request);


        void DebugState();
#endif /* _DEBUG */

    private:
        Application* m_owner;

        Semaphore m_audio_request_pending_semaphore;

        BtRequest* m_pending_audio_request;

        BOOLEAN m_connection_only_during_call;

        BtHsConnectRequest m_connect_request;

        BtHsConnectRequest m_connect_request_intern;

        BtHsDisconnectRequest m_disconnect_request;

        BtHsDisconnectRequest m_disconnect_request_intern;

        BtHsRingRequest m_ring_request_intern;

        BtHsStopRingRequest m_stop_ring_request_intern;

        BtHsTransferAudioToPhoneRequest m_transfer_audio_to_phone_request;

        BtHsTransferAudioToPhoneRequest m_transfer_audio_to_phone_request_intern;

        BtHsTransferAudioToAccessoryRequest m_transfer_audio_to_accessory_request;

        BtHsTransferAudioToAccessoryRequest m_transfer_audio_to_accessory_request_intern;

        BtHsSetMicrophoneGainRequest m_set_microphone_gain_request;

        BtHsSetSpeakerGainRequest m_set_speaker_gain_request;

    private:
        friend class BtHsRequest;
        friend class BtHsRingRequest;
};

#endif  // BtHsService_hpp

