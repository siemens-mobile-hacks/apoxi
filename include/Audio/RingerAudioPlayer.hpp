/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RingerAudioPlayer_hpp)
#define Apoxi_RingerAudioPlayer_hpp

#include <Audio/DwdPlayer.hpp>
#include <Config/AudioCapabilities.hpp> //project-specific, in Config directory.
#include <Audio/AudioPreset.hpp>
#include <Audio/CustomRingerAudioReference.hpp>
#include <Auxiliary/WString.hpp>
#include <Audio/audio_private.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class RingerAudioPlayer : public DwdPlayer
{
    public:
        virtual ~RingerAudioPlayer();
    
        virtual AudioSourceType GetSource() const; //override

        virtual void Play(AudioActiveReference& active_reference);
        virtual void Stop(AudioActiveReference& active_reference);
        virtual void Suspend(AudioActiveReference& active_reference);
        virtual void ResumeSuspended(AudioActiveReference& active_reference);
        virtual void StopSuspended(AudioActiveReference& active_reference);     
        virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const;


        virtual BOOLEAN SetPlayPosition(AudioActiveReference &playing_reference);

        virtual BOOLEAN GetPlayPosition(AudioActiveReference &playing_reference);

        virtual BOOLEAN GetTotalPlayTime(AudioActiveReference &playing_reference);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRfsFile(MimeType mime_type, const Path& path);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, ConstBuffer buffer, UINT32 buffer_size);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromPreset(MimeType mime_type, AudioPreset::AudioPresetSoundToneId tone_id);

        static AudioDeviceBase* GetInstance();
        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;
    protected:
    RingerAudioPlayer();

    RingerAudioPlayer(const RingerAudioPlayer& obj);


        virtual BOOLEAN Play_Allocate(AudioActiveReference &playing_ref);
        virtual BOOLEAN Play_Implementation(AudioActiveReference &playing_ref);
        virtual BOOLEAN Stop_Implementation(AudioActiveReference &playing_reference);
        virtual BOOLEAN Suspend_Implementation(AudioActiveReference &playing_reference);
        virtual BOOLEAN Resume_Implementation(AudioActiveReference &playing_reference);
        virtual BOOLEAN StopSuspend_Implementation(AudioActiveReference &playing_reference);

    
        // from AudioDeviceBase
        virtual BOOLEAN SetVolume_Implementation(VolumeLevel volume);   
    
    #if 0

        virtual BOOLEAN SetChannelVolume(AudioActiveReference &active_reference, VolumeLevel volume);
        virtual BOOLEAN SetChannelVolume_Implementation(AudioActiveReference &active_reference, VolumeLevel volume);
    #endif
        
        virtual BOOLEAN OnSdlSignal(UINT16 func_id, UINT8 handle, UINT16 drv_id, INT8 return_code, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
        
        VolumeLevel m_channel_volume[5];

        virtual UINT16 GetDeviceID() const; //overwrite
        INT MapFormat(CustomRingerAudioReference::Format format);
    private:
        
        enum Constants 
        {
            c_max_channels = 4
        };
        
        static RingerAudioPlayer m_singleton_instance;
        
        // The reason for c_max_channels+1 is that the driver counts the channels from 1 to 4.
        // Otherwise the handle cannot be set in case of channel 4 because the list goes only to from index 0 to 3.
        INT32 m_channel_used_by_handle[c_max_channels+1];
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_RingerAudioPlayer_hpp


