/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioPlayer_hpp)
#define Apoxi_AudioPlayer_hpp

#include <Audio/AudioDeviceBase.hpp>
#include <Audio/AudioPreset.hpp>
#include <Auxiliary/Vector.hpp>
#include <Auxiliary/SharedPtr.hpp>

// class AudioReference; would be enough with a different shared pointer
// AudioReference would be enough but the typedef of the callback function for streaming is defined there

class AudioActiveReference;
class Path;// from RFS
class BinData;

class AudioPlayer : public AudioDeviceBase
{
    public:
        AudioPlayer();
        virtual ~AudioPlayer();

        // No application-public interface. Players are used only by APOXI.
        // (However, they may be used as AudioDevices by an application, eg SetVolume.)
        
                // Reponsibilities of AudioPlayer (that cannot be expressed as functions to override):
                // Please consult the DSpec on this.
                // + Notification in case of error (in additionto the notifications following a playback command)
                // + Repeat count and AudioRestartedMsg


#ifndef DOXYGEN_SHOULD_SKIP_THIS

        virtual BOOLEAN SetPlayPosition(AudioActiveReference &active_reference);

        virtual BOOLEAN GetPlayPosition(AudioActiveReference &active_reference);

        virtual BOOLEAN GetTotalPlayTime(AudioActiveReference &active_reference);

        virtual BOOLEAN SetPitch(AudioActiveReference &active_reference);

        virtual BOOLEAN SetRate(AudioActiveReference &active_reference);

        virtual BOOLEAN SetTempo(AudioActiveReference &active_reference);



        virtual void Play(AudioActiveReference& active_reference) = 0;

        virtual void Stop(AudioActiveReference& active_reference) = 0;      
        
        //@todo virtual BOOLEAN CanPlay(AudioActiveReference& active_reference) const = 0;
        virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const { return TRUE; }
        
        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;
        
        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;

        virtual void Suspend(AudioActiveReference& active_reference);

        virtual void ResumeSuspended(AudioActiveReference& active_reference);

        virtual void StopSuspended(AudioActiveReference& active_reference);
        
        virtual SharedPtr<AudioActiveReference> StartRecording(const AudioReference &audio_ref);

        virtual void StopRecording(AudioActiveReference &active_reference);

        struct MimeTypeSupportInfo {
            MimeType m_mime_type;

            AudioReference::SoundDataSource m_sound_data_source;
            
            BOOLEAN m_is_playback_supported;
            
            UINT m_number_of_parallel_playbacks;

            BOOLEAN m_is_recording_supported;
        };

        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const {
            Vector<MimeTypeSupportInfo> empty;
            return empty;
        }
        
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRfsFile(MimeType mime_type, const Path& path);

        typedef const UINT16 HUGE* ConstBuffer;
        typedef UINT16 HUGE* Buffer;
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, Buffer buffer, UINT32 buffer_size);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, ConstBuffer buffer, UINT32 buffer_size);

        //moved the definition of the call back function GetAudioBufferFunction from StreamAudioReference to here. 
        typedef void (*GetAudioBufferFunction)( /* audiobuffer */ UINT8 ** , /*size */UINT16 *, /* application data */void* pUserData);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromStream(MimeType mime_type, GetAudioBufferFunction func, void* user_data = 0);


        virtual SharedPtr<AudioReference> CreateAudioReferenceFromPreset(MimeType mime_type, AudioPreset::AudioPresetSoundToneId tone_id);
        
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromBinData(MimeType mime_type, BinData* bin_data);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromExtensionSoundDataSource(MimeType mime_type, AudioReference::SoundDataSource sound_data_source);
                    
#endif //DOXYGEN_SHOULD_SKIP_THIS

};

#endif  // Apoxi_AudioPlayer_hpp

