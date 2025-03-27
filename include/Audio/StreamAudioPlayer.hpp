/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_StreamAudioPlayer_hpp)
#define Apoxi_AudioNewAPI_StreamAudioPlayer_hpp


#include <Audio/DwdPlayer.hpp>
#include <Audio/StreamAudioReference.hpp>
#include <Kernel/Condition.hpp>
#include <Audio/audio_private.hpp>
#include <Audio/AudioActiveReference.hpp>

class StreamAudioPlayer : public DwdPlayer
{
    public:
        StreamAudioPlayer();
        virtual ~StreamAudioPlayer();
        
                typedef DwdPlayer Base;
        
        virtual SharedPtr<AudioActiveReference> Record(const AudioReference &audio_ref);

        virtual void StopRecord(AudioActiveReference &active_reference);

        virtual AudioSourceType GetSource() const; //override

        void SetRecordingDelay(UINT32 delay);

        //Get the recording delay. See SetRecordingDelay()
        UINT32 GetRecordingDelay() const;

        BOOLEAN IsRecording();
                
                virtual BOOLEAN CanPlay(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;


#ifndef DOXYGEN_SHOULD_SKIP_THIS

        void SetRecordedSize(StreamAudioReference::BufferByteType rec_size);
#endif //DOXYGEN_SHOULD_SKIP_THIS

    protected:

        virtual void OnRecordingFinished(INT8 return_code, UINT32 param);

        //These methods are used by AudioPriorityManager (a friend class), because we must handle the SDL signal outside of this class:
        SharedPtr<AudioActiveReference> GetRecordingReference();
        SharedPtr<const AudioActiveReference> GetRecordingReference() const;
        void ForgetRecordingReference();

        virtual BOOLEAN StopSuspend_Implementation(AudioActiveReference &playing_reference);

        //These methods are used by AudioPriorityManager (a friend class), because we must handle the SDL signal outside of this class:
        void SetRecordingWaitCondition(BOOLEAN val = TRUE);
        TimeoutCondition *m_recording_wait_condition; //See StopRecord() implementation.

        void ReconstructRecordingWaitCondition();

        UINT32 m_delay; //the recording delay

        INT MapMedia (StreamAudioReference::Media media);

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        SharedPtr<AudioActiveReference> m_p_record_ref;
        DwdHandleType m_recording_dwd_handle;
#endif //DOXYGEN_SHOULD_SKIP_THIS
};

#endif  // Apoxi_AudioNewAPI_StreamAudioPlayer_hpp

