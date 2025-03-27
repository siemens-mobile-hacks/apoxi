/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_SpeechSimpleAudioDevice_hpp)
#define Apoxi_AudioNewAPI_SpeechSimpleAudioDevice_hpp
#include <Apc/SignalHandler/SignalMapTableEntry.hpp>    // For ProcessPtr
#include <Audio/SimpleAudioDevice.hpp>
#include <Audio/DwdDevice.hpp>

class SpeechSimpleAudioDevice : public SimpleAudioDevice, public DwdDevice
{
    private:
        //Use GetInstance() instead.
        SpeechSimpleAudioDevice();

    public:
        virtual ~SpeechSimpleAudioDevice();
        static SpeechSimpleAudioDevice* GetInstance();

        virtual BOOLEAN Enable(BOOLEAN suspend_all_others = FALSE);

        virtual BOOLEAN Disable();

        virtual BOOLEAN ApplyDeviceVolume();

        UINT16 GetNativeVolumeMin();

        UINT16 GetNativeVolumeMax();

        BOOLEAN SetMute(BOOLEAN uplink, BOOLEAN enable = TRUE);

        BOOLEAN GetMute(BOOLEAN uplink) const;
        
        virtual AudioSourceType GetSource() const; //override

#ifndef DOXYGEN_SHOULD_SKIP_THIS
        //overwrite the AudioDeviceBase function
        virtual BOOLEAN SetMute(BOOLEAN enable = TRUE, MuteDirection direction = UpDownlinkDirection);

        virtual BOOLEAN Play_Allocate(AudioActiveReference &playing_reference);

        //Callback function handling the MN_SPEECH_STATUS_IND signal
        static void OnSdlSignal_AudioSpeechStatusInd(const ProcessPtr &process_ptr);

    protected:
        BOOLEAN m_mute_uplink_enabled, m_mute_downlink_enabled;

        //The only instance of the speech device
        static SpeechSimpleAudioDevice* m_instance;

        virtual UINT16 GetDeviceID() const; //overwrite
#endif  //DOXYGEN_SHOULD_SKIP_THIS
};

#endif  // Apoxi_AudioNewAPI_SpeechSimpleAudioDevice_hpp


