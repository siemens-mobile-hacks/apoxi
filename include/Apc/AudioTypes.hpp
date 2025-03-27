/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_AudioTypes_hpp)
#define Apc_AudioTypes_hpp

#include <Apc/SignalTypes.hpp>
#include <Devices/PresetAudioReference.hpp>
#include <Audio/AudioPreset.hpp>


/*  ========================================================================
    AudioTone
        audio tone type (GSM 02.40 - GSM 11.14)
    ======================================================================== */
class AudioTone {
    public:
        AudioTone();
        AudioTone(const AudioToneType tone_type, const INT duration);
        AudioTone(const SdlByte sdl_tone_type, const T_DURATION &sdl_duration);

        AudioPreset::AudioPresetSoundToneId GetAudioDeviceToneId() const;

        AudioToneType GetToneType() const { return (m_tone_type); }

        INT32 GetDuration() const { return (m_duration); }

        const SharedPtr<PresetAudioReference> GetAudioDeviceToneRef() const;

    private:
        enum DurationUnits {
            Minutes         = 0x00,
            Seconds         = 0x01,
            TenthOfSeconds  = 0x02
        };

        AudioToneType      m_tone_type;
        INT32         m_duration;   // in milliseconds
};


#endif  // Apc_AudioTypes_hpp


