/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_ToneAudioPlayer_hpp)
#define Apoxi_AudioNewAPI_ToneAudioPlayer_hpp

#include <Audio/DwdPlayer.hpp>
#include <Audio/ToneAudioReference.hpp>

class AudioManager;
class AudioActiveReference;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class ToneAudioPlayer : public DwdPlayer
{
    public:

        virtual ~ToneAudioPlayer();
        
        virtual AudioSourceType GetSource() const; //override.

        virtual void Play(AudioActiveReference& active_reference);
        virtual void Stop(AudioActiveReference& active_reference);
        virtual void Suspend(AudioActiveReference& active_reference);
        virtual void ResumeSuspended(AudioActiveReference& active_reference);
        virtual void StopSuspended(AudioActiveReference& active_reference); 

        

        virtual BOOLEAN SetPlayPosition(AudioActiveReference &playing_reference);

        virtual BOOLEAN GetPlayPosition(AudioActiveReference &playing_reference);

        virtual BOOLEAN GetTotalPlayTime(AudioActiveReference &playing_reference);

        static AudioDeviceBase* GetInstance();
        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;
        
    protected:
        virtual UINT16 GetDeviceID() const; //overwrite
        
        virtual BOOLEAN Play_Allocate(AudioActiveReference &audio_ref);
        virtual BOOLEAN Play_Implementation(AudioActiveReference &playing_ref);
        virtual BOOLEAN Stop_Implementation(AudioActiveReference &playing_reference);
        virtual BOOLEAN Suspend_Implementation(AudioActiveReference &playing_reference);
        virtual BOOLEAN Resume_Implementation(AudioActiveReference &playing_reference);     

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, ConstBuffer buffer, UINT32 buffer_size);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromPreset(MimeType mime_type, AudioPreset::AudioPresetSoundToneId tone_id);

private:
    ToneAudioPlayer();

    ToneAudioPlayer(const ToneAudioPlayer& obj);


        static ToneAudioPlayer m_singleton_instance;
        
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_ToneAudioPlayer_hpp


