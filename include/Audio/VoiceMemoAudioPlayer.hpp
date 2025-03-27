/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_VoiceMemoAudioPlayer_hpp)
#define Apoxi_AudioNewAPI_VoiceMemoAudioPlayer_hpp

#include <Audio/StreamAudioPlayer.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class VoiceMemoAudioPlayer : public StreamAudioPlayer
{
    typedef StreamAudioPlayer Base;
    public:
 
        virtual ~VoiceMemoAudioPlayer();

        virtual void Play(AudioActiveReference& active_reference);
        virtual void Stop(AudioActiveReference& active_reference);
        virtual void Suspend(AudioActiveReference& active_reference);
        virtual void ResumeSuspended(AudioActiveReference& active_reference);
        virtual void StopSuspended(AudioActiveReference& active_reference);
        virtual SharedPtr<AudioActiveReference> StartRecording(const AudioReference &audio_ref);
        virtual void StopRecording(AudioActiveReference &active_reference);     

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRfsFile(MimeType mime_type, const Path& path);
        // This function should be used in case of playback
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, ConstBuffer buffer, UINT32 buffer_size);
        // This function should be used in case of recording
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, Buffer buffer, UINT32 buffer_size);
        virtual SharedPtr<AudioReference> CreateAudioReferenceFromStream(MimeType mime_type, AudioPlayer::GetAudioBufferFunction func, void* user_data = 0);

        virtual SharedPtr<AudioActiveReference> Record(const AudioReference &audio_ref);

        /* Stop recording.
         * See Record(). If RAM has been set as media then StreamAudioReference::GetRecordedSize can be used to get the recorded buffer size
         * @param active_reference A reference to the active recording.
         */
        virtual void StopRecord(AudioActiveReference &active_reference);

        virtual AudioSourceType GetSource() const; //override


        virtual BOOLEAN SetPlayPosition(AudioActiveReference &playing_reference);

        virtual BOOLEAN GetPlayPosition(AudioActiveReference &playing_reference);

        virtual BOOLEAN GetTotalPlayTime(AudioActiveReference &playing_reference);

        static AudioDeviceBase* GetInstance();
        virtual Vector<AudioPlayer::MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;
    
    protected:
        virtual BOOLEAN Play_Allocate(AudioActiveReference &audio_ref);
        virtual BOOLEAN Play_Implementation(AudioActiveReference &playing_ref);
        virtual BOOLEAN Stop_Implementation(AudioActiveReference &active_reference);
        virtual BOOLEAN Suspend_Implementation(AudioActiveReference &playing_reference);
        virtual BOOLEAN Resume_Implementation(AudioActiveReference &playing_reference);     
        
        virtual BOOLEAN OnSdlSignal(UINT16 func_id, UINT8 handle, UINT16 drv_id, INT8 return_code, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
        virtual void OnRecordingFinished(INT8 return_code, UINT32 param);       
        
        virtual UINT16 GetDeviceID() const; //override
    private:
    VoiceMemoAudioPlayer();

    VoiceMemoAudioPlayer(const VoiceMemoAudioPlayer& obj);


        static VoiceMemoAudioPlayer m_singleton_instance;
        INT MapFormat( StreamAudioReference::DspFormat format);     
        INT MapMode (StreamAudioReference::Mode mode);      

};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_VoiceMemoAudioPlayer_hpp


