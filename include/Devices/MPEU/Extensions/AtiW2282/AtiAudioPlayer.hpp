/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AtiAudioPlayer_hpp)
#define Apoxi_AudioNewAPI_AtiAudioPlayer_hpp

#include <Audio/CombinedDeviceAudioReference.hpp>
#include <Audio/TimeFeatureObject.hpp>
#include <Audio/StreamAudioPlayer.hpp>
#include <Audio/RtStreaming/DataSourceRtStreamingSource.hpp>

#include <gci_common.h>
#include <gci_audio.h>

#include "AtiAudioPlayerRtStreamingConn.hpp"
#include "AtiAudioPlayerRtStreamingSink.hpp"
#include "NonsharedBinDataDataSource.hpp"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class AtiAudioPlayer : public StreamAudioPlayer
{

    friend class AtiAudioPlayerRtStreamingSink; 

    public:
        AtiAudioPlayer();
        virtual ~AtiAudioPlayer();

        void Initialize();

        virtual AudioSourceType GetSource() const; //override

        virtual void Play(AudioActiveReference& active_reference);

        virtual void Stop(AudioActiveReference& active_reference);

        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;

        virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const;

        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;

        virtual void Suspend(AudioActiveReference& active_reference);

        virtual void ResumeSuspended(AudioActiveReference& active_reference);

        virtual SharedPtr<AudioActiveReference> StartRecording(const AudioReference &audio_ref);

        /* Stop recording.
         * @param active_reference A reference to the active recording.
         */
        virtual void StopRecording(AudioActiveReference &active_reference);

        virtual BOOLEAN IsFeatureSupported(Feature feature, MimeType mime_type = c_mime_unknown, AudioReference::SoundDataSource sound_data_source = AudioReference::InvalidSoundDataSource) const;

        virtual BOOLEAN ExecuteFeature(Feature feature, GenericObject* data = 0);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromStream(MimeType mime_type, GetAudioBufferFunction func, void* user_data = 0);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, Buffer buffer, UINT32 buffer_size);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type, ConstBuffer buffer, UINT32 buffer_size);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromRfsFile(MimeType mime_type, const Path& path);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromBinData(MimeType mime_type, BinData* bin_data);

        virtual BOOLEAN GetPlayPosition(AudioActiveReference &active_reference);

        virtual BOOLEAN GetTotalPlayTime(AudioActiveReference &active_reference);

        static AudioDeviceBase* GetInstance();
        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;

        //function is called when error occurs in playback
        void OnDriverError(AudioActiveReference& active_reference, AudioError::AudReturnCode error_code);
        //function is called when error occurs while reading data
        void OnSourceError(AudioActiveReference& active_reference, AudioError::AudReturnCode error_code);

    protected:

        virtual UINT16 GetDeviceID() const;//override

        virtual BOOLEAN Play_Allocate(AudioActiveReference &audio_ref);

        //GCI callbacks

        static void OnCbCommonStart(tGciResult result, void* context);
        static void OnCbCommonStop(tGciResult result, void* context);
        static void OnCbCommonStartRecord(tGciResult result, void* context);
        static void OnCbCommonStopRecord(tGciResult result, void* context);
        static void OnCbCommonResume(tGciResult result, void* context);
        static void OnCbCommonAllBuffersProcessed(tGciResult result, void* context);
        static void OnCbSuspend(tGciResult result, CombinedDeviceAudioReference::TimeStampType time, tGciAudionegByteOffset negByteOffset, void* context);
        static void OnCbReady(void* context);
        static void OnCbReadyStreaming(void* context);
        static void OnCbNotification(tGciAudioNotification notification, void* context);

        Semaphore m_wait_semaphore;

        //Boolean value which is set to TRUE only when XMF,AMR or WAVE playback finishes till the end
        BOOLEAN m_finished;

    private:

        static AtiAudioPlayer m_singleton_instance;

        //Map containing the pairs of GciHandles and apropriate buffers allocated for playback
        SimpleMap<UINT32, UINT8*> m_buffers;

        //m_handle_counter contains the number of currently allocated GCI handles 
        INT8 m_handle_counter;
        
        //needed for transfering time between callback and the function which is waiting
        UINT32 m_time;

        // Gci handle used for CbDataReady callback
        tGciAudioHandle *m_gci_handles[3];

        // Sources and Sinks for streaming
        DataSourceRtStreamingSource *m_srcs[3];
        AtiAudioPlayerRtStreamingSink *m_snks[3];
        AtiAudioPlayerRtStreamingConn *m_conns[3];

};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_AtiAudioPlayer_hpp


