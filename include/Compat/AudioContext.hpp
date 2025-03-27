/*  ------------------------------------------------------------------------
Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(MultiMedia_AudioContext_hpp)
#define MultiMedia_AudioContext_hpp

#include <Devices/Device.hpp>

#if defined(APOXI_PLATFORM_BP30) && defined(APOXI_3GPP_REL_97_DOWNGRADE)
  #include <Compat/Devices/BP30/Audio.hpp>
#endif


class AudioContext {
    public:     
        AudioContext(Audio::AudioDevice device = Audio::DeviceBuzzer);      

        virtual ~AudioContext();
        
        Audio::AudioDevice GetDevice() const { return m_device; }
        
        void SetAudioMode(Audio::AudioMode mode);

        Audio::AudioMode GetMode() const { return m_mode; }

        void SetPriority(Audio::AudioPriority priority) { m_priority = priority; }

        Audio::AudioPriority GetPriority() const { return m_priority; }
        
        void SetVolume(UINT8 volume);

        UINT8 GetVolume() const { return m_volume; }
        
        void SetMute(BOOLEAN mute);
        
        BOOLEAN IsMute() const { return m_mute; }

        virtual BOOLEAN PlaySound(Audio::AudioToneId sound, INT repeats = 1);

        virtual BOOLEAN PlaySound(Audio::ToneData* sound);

        virtual void StopSound();
            
    private:
        BOOLEAN                 m_mute;
        UINT8                   m_volume;
        Audio::AudioDevice      m_device;
        Audio::AudioMode        m_mode;
        Audio::AudioPriority    m_priority;
};

#endif // MultiMedia_AudioContext_hpp


