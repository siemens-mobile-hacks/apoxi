/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtHfController_hpp)
#define BtHfController_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <stack/extensions.h>
#include <Apc/SignalHandler/SignalMapTableNode.hpp>
#include <Apc/SignalHandler/SignalMapTableEntry.hpp>
#include <Apc/SignalHandler/StackMsgProcessor.hpp>
#include <Devices/AudioAccessoryDetails.hpp>
#include <Bluetooth/BtServiceRequest.hpp>
#include <Bluetooth/BtSingleConnectionController.hpp>
#include <Bluetooth/HF/BtTypes.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtHfService;
class BtHfConnectRequest;
class BtHfDisconnectRequest;
class BtHfTransferAudioToPhoneRequest;
class BtHfTransferAudioToAccessoryRequest;
class BtHfSetMicrophoneGainRequest;
class BtHfSetSpeakerGainRequest;
class BtHfPmiMsgManager;
class BtHfAudioTransferRequest;

class BtHfController : public BtSingleConnectionController
{
    private:
        typedef BtSingleConnectionController Base;
    
    public:

        static BtHfController& GetInstance();

    public:
        virtual ~BtHfController();


        virtual const WCHAR* GetName() const;

    protected:

        void HfSetInbandRinging(BOOLEAN enable);


        BOOLEAN HfTransferAudioToPhoneRequest(BtHfTransferAudioToPhoneRequest* transfer_audio_to_phone_request);


        BOOLEAN HfTransferAudioToAccessoryRequest(BtHfTransferAudioToAccessoryRequest* transfer_audio_to_accessory_request);


        BOOLEAN HfSetMicrophoneGainRequest(BtHfSetMicrophoneGainRequest* set_microphone_gain_request);


        BOOLEAN HfSetSpeakerGainRequest(BtHfSetSpeakerGainRequest* set_speaker_gain_request);


        BtHfState GetState(const BtDevice& device) const;


        BOOLEAN GetIsRinging(const BtDevice& device) const;


        void SetIsRinging(const BtDevice& device, BOOLEAN is_ringing);


        BtHfCallLocation GetCallLocation(const BtDevice& device) const;


        void SetCallLocation(const BtDevice& device, BtHfCallLocation call_location);


        UINT8 GetMicrophoneGain(const BtDevice& device) const;


        UINT8 GetSpeakerGain(const BtDevice& device) const;


        UINT16 GetSupportedFeatures(const BtDevice& device) const;

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


        static void OnHfCommonCallback(btapi_result_t result, btapi_common_hfcb_t type);


        void OnHfAudioConnectionLost(BtResultCode result);


        void OnHfLowPowerModeNotPosssible(BtResultCode result);


        static void OnHfConnectCallback(btapi_result_t result, btapi_bdaddr_t api_device_address);


        void OnHfConnect(BtResultCode result, BtDeviceAddress device_address);


        static void OnHfDisconnectCallback(btapi_result_t result, btapi_bdaddr_t api_device_address);


        void OnHfDisconnect(BtResultCode result /*, btapi_bdaddr_t bdaddr*/);


        static void OnHfAudioCallback(btapi_result_t result, btapi_bool_t is_audio_at_phone);


        void OnHfAudio(BtResultCode result, BOOLEAN is_audio_at_phone);


        void OnHfTransferAudioToPhoneRequest(BtHfTransferAudioToPhoneRequest* request, BtResultCode result, BOOLEAN is_audio_at_phone);


        void OnHfTransferAudioToAccessoryRequest(BtHfTransferAudioToAccessoryRequest* request, BtResultCode result, BOOLEAN is_audio_at_phone);


        void OnHfTransferAudio(BtResultCode result, BOOLEAN is_audio_at_phone);


        static void OnHfPmiCallback(const ProcessPtr& process_pointer);


        void OnHfPmi(UINT16 pmi_function, UINT16 pmi_accessory, UINT16 pmi_tid, UINT16 pmi_report);


        void OnHfPmiMtcOnHf(void);


        void OnHfPmiMocOnHf(void);


        void OnHfPmiNameRecognized(void);


        void OnHfPmiVoiceRecognition(BOOLEAN pmi_accessory);


        void OnHfPmiNoiseReductionEchoCancelationRequest(UINT16 status);


        void OnHfPmiMicrophoneGain(UINT8 microphone_gain);


        void OnHfPmiSpeakerGain(UINT8 speaker_gain);


        void OnHfPmiReleaseWaitingAndAcceptWaitingOnHf();


        void OnAudioPathConnected(BOOLEAN connected, BOOLEAN update_path);

    private:
        BtHfController();


        virtual void Register();


        virtual void Unregister();


        void SetState(BtHfState state);


        void SetMicrophoneGain(UINT8 microphone_gain);


        void SetSpeakerGain(UINT8 speaker_gain);


        BOOLEAN SwitchAudio(BOOLEAN conneded, BOOLEAN switch_path);


        void SetRunningAudioSetConnected(BOOLEAN running, BOOLEAN connected, BOOLEAN switch_path);


        void SetPendingAudioCallback(BOOLEAN pending, BOOLEAN connected, BOOLEAN switch_path);


        void CheckPendingAudioCallback();

    private:
        class BtHfSignalMapTableNode: public SignalMapTableNode
        {
            private:
                typedef SignalMapTableNode Base;

            public:
                BtHfSignalMapTableNode();

                virtual ~BtHfSignalMapTableNode();
    
            private:
                static const SignalMapTableEntry m_signal_map_table_entry[];
        };  // BtHfSignalMapTableNode

        class BtHfStackMessageProcessor: public StackMsgProcessor
        {
            private:
                typedef StackMsgProcessor Base;

            public:
                BtHfStackMessageProcessor();

                virtual ~BtHfStackMessageProcessor();

            public:

                UINT16 GetPmiTid() const;


                void SetPmiTid(UINT16 pmi_tid);


                void SendHsInformIndication(UINT16 pmi_function, UINT16 pmi_report, UINT32* pmi_data);


                void SetHfDataInput(UINT8* number);


                void SetHfVoiceRecognitionReq(BOOLEAN enable);


                void SetHfVoiceRecognitionInd(T_PMI_REPORT report);


                void SetHfInbandRingingIndication(BOOLEAN enable);


                void SendNoiceReductionEchoCancelationIndication(BOOLEAN result);

            protected:

                void SendSignal(UINT16 pmi_function, UINT16 pmi_accessory, UINT16 pmi_report, UINT32* pmi_data);

            private:
                UINT16 m_pmi_tid;
        };  // BtStackMessageProcessor

        class BtHfAudioAccessoryDetails: public AudioAccessoryDetails
        {
            private:
                typedef AudioAccessoryDetails Base;

            public:
                BtHfAudioAccessoryDetails();


                virtual void OnAudioPathConnected(BOOLEAN connected, BOOLEAN update_path);
        };  // BtHfAudioAccessoryDetails

#ifdef _DEBUG
    private:

        void DebugState();
#endif /* _DEBUG */

    private:
        btapi_hfcb_funp_t* m_hf_callback_functions;

        BtHfState m_hf_state;

        BOOLEAN m_is_ringing;

        BtHfCallLocation m_call_location;

        BOOLEAN m_noice_reduction_echo_cancelation;

        UINT8 m_microphone_gain;

        UINT8 m_speaker_gain;

        BtHfSignalMapTableNode m_signal_map_table_node;

        BtHfStackMessageProcessor m_stack_message_processor;

        BtHfAudioAccessoryDetails m_audio_accessory_details;

        Semaphore m_audio_callback_pending_semaphore;

        BOOLEAN m_audio_set_connected_running;

        BOOLEAN m_audio_set_connected_connected;

        BOOLEAN m_audio_set_connected_switch_path;

        BOOLEAN m_audio_callback_pending;

        BOOLEAN m_audio_callback_connected;

        BOOLEAN m_audio_callback_switch_path;

    private:
        static BtHfController m_controller;

    private:
        friend class BtHfController::BtHfAudioAccessoryDetails;

    private:
        friend class BtHfService;
        friend class BtHfConnectRequest;
        friend class BtHfDisconnectRequest;
        friend class BtHfTransferAudioToPhoneRequest;
        friend class BtHfTransferAudioToAccessoryRequest;
        friend class BtHfSetMicrophoneGainRequest;
        friend class BtHfSetSpeakerGainRequest;
        friend class BtHfPmiMsgManager;
        friend class BtHfAudioTransferRequest;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtHfController_hpp

