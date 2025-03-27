/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioPriorityManager_hpp)
#define Apoxi_AudioPriorityManager_hpp

#include <Kernel/SubSystem.hpp>
#include <Audio/AudioActiveReference.hpp>
//#include <Audio/AudioError.hpp>
#include <Audio/AudioPlayerEvent.hpp>

class AudioReference;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


class AudioPriorityManager : public SubSystem
{
protected:
    AudioPriorityManager();

public:
    virtual ~AudioPriorityManager();
    virtual const WCHAR* GetName() const;
    virtual BootSequenceState InvokeAt() const;
    virtual void OnPowerUp();

    static AudioPriorityManager* GetInstance();

    SharedPtr<AudioActiveReference> Play(const AudioReference& audio_ref);
    void Stop(AudioActiveReference& active_ref);
    BOOLEAN Suspend(AudioActiveReference& active_ref);
    BOOLEAN Resume(AudioActiveReference& active_ref);

    // regardless of their priorities.  
    // xxx param
    void SuspendAllPlayingSounds(const AudioActiveReference& suspended_by);

    // xxx resume policy
    void ResumeSuspendedBy(const AudioActiveReference& suspended_by);
    
    void StopAllSounds();

    // xxx @todo    
    static void OnCallEnd();

private:        
    enum PlaybackRequestOutcome {       
        PlaybackRequestRejected, 
        PlaybackRequestAcceptedForLater,
        PlaybackRequestAcceptedForImmediatePlayback, 
    };
    
    AudioPriorityManager::PlaybackRequestOutcome RequestPlayback(const AudioReference& audio_ref,
            SharedPtr<AudioActiveReference>& low_same_group_ref) const; 
        
        void SuspendExcludedRefs(const AudioReference& audio_ref);
    
    void RemoveFromSuspendedRefs(AudioActiveReference& active_ref);
    void RemoveFromWaitingRefs(AudioActiveReference& active_ref);
    void RemoveFromPlayingRefs(AudioActiveReference& active_ref);

    void AcknowledgePlaybackStopped(AudioActiveReference& active_ref, AudioPlayerEvent::Reason reason);
    void AcknowledgePlaybackStarted(AudioActiveReference& active_ref);
    void AcknowledgePlaybackSuspended(AudioActiveReference& active_ref);

    void StopOrSuspendAndWait(AudioActiveReference& active_ref, BOOLEAN stop);
    void SuspendAndWait(AudioActiveReference& active_ref);
    void StopAndWait(AudioActiveReference& active_ref);
    
    static AudioPriorityManager m_instance;
    
    typedef Vector<AudioActiveReference* > ActiveRefList;
    ActiveRefList m_playing_refs;
    ActiveRefList m_suspended_refs;
    ActiveRefList m_waiting_refs;
    void RemoveRefFromCollection(AudioActiveReference* active_ref, ActiveRefList& collection);
    
public:
    void ApplyPathControlTable(const AudioActiveReference& active_ref, BOOLEAN force_update = FALSE);
    void OnAccessoryAvailabilityChanged(BOOLEAN force_update = FALSE);

    void ReceivePlayerEvent(const AudioPlayerEvent& event);
    SharedPtr<AudioActiveReference> GetActiveReference(AudioReference* audio_ref) const;

    void UpdatePlayingVolumes();
    void UpdatePlayingRefVolume(AudioActiveReference& active_ref);
private:    
    friend void AudioPmEventHandler();
    //This class is defined in the AudioPriorityManager.cpp and uses private members of the AudioPriorityManager, therefore I defined it as friend.
    friend class AudioPmResumeThreadlet;

    AudioActiveReference* m_ref_to_wait_for;
    AudioActiveReference* m_inner_ref_to_wait_for;
    BOOLEAN IsConditionSatisfied(BOOLEAN inner) const;
    BOOLEAN IsConditionEmpty() const;
    BOOLEAN IsInnerConditionEmpty() const;
    BOOLEAN m_suspend_is_acceptable_in_wait;
    BOOLEAN WaitForPlayer(AudioActiveReference& active_ref, UINT32 timeout);

    AudioActiveReference* FindManagedRef(const AudioPlayer* player, AudioActiveReference::HandleInsidePlayer handle) const;
    BOOLEAN IsManagedRef(const AudioActiveReference* active_ref) const;

    friend void AudioPmAutomaticResume(AudioReference::PriorityGroupType priority_group);
    void AutomaticResume(AudioReference::PriorityGroupType priority_group);
    
    // play: TRUE means play, FALSE means resume
    void PlayOrResumeUnconditionally(AudioActiveReference& active_ref, BOOLEAN play);
    void PlayUnconditionally(AudioActiveReference& active_ref);
    void ResumeUnconditionally(AudioActiveReference& active_ref);
    AudioPlayer* GetPlayerWithRoom(const SharedPtr<AudioActiveReference>& new_arrival_ref, SharedPtr<AudioActiveReference>& low_same_group_ref);
    BOOLEAN GetPlayerAndPlay(SharedPtr<AudioActiveReference>& new_arrival_ref, SharedPtr<AudioActiveReference>& low_same_group_ref);
    
    BOOLEAN StartManagingReference(AudioActiveReference* active_ref);
    void StopManagingReference(AudioActiveReference* active_ref);
    LinkedList<SharedPtr<AudioActiveReference> > m_managed_refs;
    
    AudioActiveReference* GetPathControlRelevantRef() const;
    
    // Moved from the cpp-file to here, because of linker errors.
    enum AudioPmEventType {
        PlayerAudioPmEventType,
        ResumeRequestAudioPmEventType
    };
    
    struct AudioPmTypeSelectorEvent {
        INT m_event_type;
    };

    struct AudioPmResumeRequestEvent {
        INT m_event_type;
        UINT m_priority_group;
        UINT32 m_desired_resume_time_ms;
    };

    // cf. AudioPlayerEvent; redefined for use in union
    struct AudioPmPlayerEvent {
        INT m_event_type;
        AudioPlayer* m_player;
        AudioActiveReference::HandleInsidePlayer m_handle;
        AudioActiveReference::PlaybackState m_playback_state;
        AudioPlayerEvent::Reason m_reason;
        BOOLEAN m_send_error_message;
        AudioError::AudReturnCode m_error_code;
    };

public:
    union AudioPmEvent {
        AudioPmTypeSelectorEvent type_selector;
        AudioPmPlayerEvent audio_player_event;
        AudioPmResumeRequestEvent resume_request_event; 
    };
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioPriorityManager_hpp

