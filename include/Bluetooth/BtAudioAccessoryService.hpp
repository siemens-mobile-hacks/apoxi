/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtAudioAccessoryService_hpp)
#define BtAudioAccessoryService_hpp

#include <Bluetooth/BtService.hpp>

/*  ------------------------------------------------------------------------
    macro definitions
    ------------------------------------------------------------------------ */

#define BT_AA_INVALID_VOLUME_LEVEL 0xFF

class BtAudioAccessoryService: public BtService
{
    private:
        typedef BtService Base;

    public:
        BtAudioAccessoryService();

        BtAudioAccessoryService(const BtDevice& target_device);

        virtual ~BtAudioAccessoryService();

    public:

        BOOLEAN GetAudioAlwaysOnAccessory() const;


        void SetAudioAlwaysOnAccessory(BOOLEAN audio_always_on_accessory);


        BOOLEAN GetUseInbandRinging() const;


        virtual void SetUseInbandRinging(BOOLEAN use_inband_ringing);

    public:

        virtual BOOLEAN IsConnected() const = 0;


        virtual BOOLEAN IsRinging() const = 0;


        virtual BOOLEAN IsInCall() const = 0;


        virtual BtRequestState ConnectRequest() = 0;


        virtual BtRequestState DisconnectRequest() = 0;


        virtual BtRequestState TransferAudioToPhoneRequest() = 0;


        virtual BtRequestState TransferAudioToAccessoryRequest() = 0;


        virtual UINT8 GetMicrophoneGain() const = 0;


        virtual BtRequestState SetMicrophoneGainRequest(INT8 gain_offset) = 0;


        virtual UINT8 GetSpeakerGain() const = 0;


        virtual BtRequestState SetSpeakerGainRequest(INT8 gain_offset) = 0;

    private:
        BOOLEAN m_audio_always_on_accessory;

        BOOLEAN m_use_inband_ringing;
};  // BtAudioAccessoryService

#endif  // BtAudioAccessoryService_hpp

