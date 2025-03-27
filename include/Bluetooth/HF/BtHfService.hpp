/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfService_hpp)
#define BtHfService_hpp

#include <Kernel/Application.hpp>
#include <Bluetooth/BtAudioAccessoryService.hpp>
#include <Bluetooth/HF/BtTypes.hpp>
#include <Bluetooth/HF/BtHfControllerMessage.hpp>
#include <Bluetooth/HF/BtHfConnectRequest.hpp>
#include <Bluetooth/HF/BtHfDisconnectRequest.hpp>
#include <Bluetooth/HF/BtHfTransferAudioToPhoneRequest.hpp>
#include <Bluetooth/HF/BtHfTransferAudioToAccessoryRequest.hpp>
#include <Bluetooth/HF/BtHfSetMicrophoneGainRequest.hpp>
#include <Bluetooth/HF/BtHfSetSpeakerGainRequest.hpp>

class BtHfService: public BtAudioAccessoryService
{
    private:
        typedef BtAudioAccessoryService Base;

    public:
        BtHfService();

        virtual ~BtHfService();


        virtual void Init();


        virtual BtProfile GetProfile() const;


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual void SetTargetDevice(const BtDevice& target_device);


        virtual BOOLEAN IsConnected() const;


        virtual void SetUseInbandRinging(BOOLEAN use_inband_ringing);


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


        UINT16 GetSupportedFeatures() const;


        BtHfState GetState() const;

    protected:

        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);


        virtual BOOLEAN OnCallEventMessage(const CallEventMsg& call_event_message);


        BOOLEAN OnControllerMessage(const BtHfControllerMessage& controller_message);

    private:

        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


        virtual void OnPhoneNumberRequired(BtResultCode result) = 0;


        void TryAudioRequest(BtRequest* audio_request);


        void CheckPendingAudioRequest();

    private:

        class BtHfAtChldOneCommand
        {
            public:
                typedef enum {
                    BtHfAcocStopped,
                    BtHfAcocWaitingForRelease,
                    BtHfAcocWaitingForEstablishment
                } BtHfAtChldOneCommandState;

            public:
                BtHfAtChldOneCommand();

                virtual ~BtHfAtChldOneCommand();

            public:

                void Start();


                void Stop();


                void Step();


                BOOLEAN IsRunning() const;


                BOOLEAN IsRightCallEvent(StackMsgArgId id) const;


                BtHfCallLocation GetCallLocation() const;


                void SetCallLocation(BtHfCallLocation call_location);


                BtHfAtChldOneCommandState GetState() const;

            private:
                BtHfAtChldOneCommandState m_state;

                BtHfCallLocation m_call_location;
        };

#ifdef _DEBUG
    private:

        const char* BtHfRequestAsString(BtRequest* request);


        void DebugState();
#endif /* _DEBUG */

    private:
        Application* m_owner;

        Semaphore m_audio_request_pending_semaphore;

        BtRequest* m_pending_audio_request;

        BtHfAtChldOneCommand m_at_chld_one_command;

        BtHfConnectRequest m_connect_request;

        BtHfDisconnectRequest m_disconnect_request;

        BtHfTransferAudioToPhoneRequest m_transfer_audio_to_phone_request;

        BtHfTransferAudioToPhoneRequest m_transfer_audio_to_phone_request_intern;

        BtHfTransferAudioToAccessoryRequest m_transfer_audio_to_accessory_request;

        BtHfTransferAudioToAccessoryRequest m_transfer_audio_to_accessory_request_intern;

        BtHfSetMicrophoneGainRequest m_set_microphone_gain_request;

        BtHfSetSpeakerGainRequest m_set_speaker_gain_request;
};

#endif  // BtHfService_hpp

