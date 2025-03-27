/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioActiveReference_hpp)
#define Apoxi_AudioActiveReference_hpp

#include <Audio/AudioReference.hpp>
#include <Auxiliary/ObjectReferrer.hpp> //For ReferableObject
#include <Kernel/Timer.hpp>

class AudioDeviceBase;

class AudioActiveReference : public ReferableObject, private Timer
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    protected:
        AudioActiveReference();
#endif //DOXYGEN_SHOULD_SKIP_THIS
    public:
        virtual ~AudioActiveReference();
        static SharedPtr<AudioActiveReference> Create();
        bool operator==(const AudioActiveReference& other) const;

        enum enumClassType
        {
            ClassType_AudioActiveReference
            //When you add to this, you will have to search for all uses of the enums,
            //because this is not a complete subsitute for dynamic_cast<> - it can not check base classes.
        };

// change xxx

        virtual enumClassType GetClassType() const;

        void SetReference(AudioReference& audio_ref);
//      SharedPtr<AudioReference> GetReference();
        SharedPtr<const AudioReference> GetReference() const;
        const AudioReference* GetAudioReference() const;

        void SetDevice(AudioDeviceBase* audio_player);
        AudioDeviceBase* GetDevice();
        const AudioDeviceBase* GetDevice() const;

        // @todo comment
        void Stop();

        BOOLEAN Suspend();

        BOOLEAN Resume();

        typedef AudioReference::VolumeLevel VolumeLevel;
        
        BOOLEAN SetVolume(VolumeLevel val);
        
        // @todo rename, comment
        BOOLEAN GetVolumeSet() const {
            return m_mmi_volume_has_been_set;
        }

        VolumeLevel GetVolume() const {
            return m_mmi_volume;
        }
        
        // @todo check if removable
        BOOLEAN SetChannelVolume(VolumeLevel val);
        
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    // @todo check if removable
        BOOLEAN GetSuspended() const;// kept only so legacy code works without changes
        BOOLEAN GetWaiting() const;// kept only so legacy code works without changes
        
        // @todo check if removable
        BOOLEAN IsActive();

        // @todo internal
        enum PlaybackState {
            InitialState,
            WaitingState,
            PlayingState,
            SuspendedState,
            StoppedState
        };

        PlaybackState GetPlaybackState() const {
            return m_playback_state;
        }

        void SetPlaybackState(PlaybackState s) {
            m_playback_state = s;
        }

        typedef UINT32 HandleInsidePlayer;

        HandleInsidePlayer GetHandleInsidePlayer() const {
            return m_handle_inside_player;
        }

        void SetHandleInsidePlayer(HandleInsidePlayer handle_inside_player) {
            m_handle_inside_player = handle_inside_player;
        }       

        void EnableTimeout();
        
        BOOLEAN TimeoutHasOccurred() const {
            return m_timeout_has_occurred;
        }
        
        void SetHasBeenStoppedVoluntarily() {
            m_has_been_stopped_voluntarily = TRUE;
        }
        
        BOOLEAN GetHasBeenStoppedVoluntarily() const {
            return m_has_been_stopped_voluntarily;
        }
        
        void SetIsInVoluntarySuspension(BOOLEAN b) {
            m_is_in_voluntary_suspension = b;
        }
        
        BOOLEAN GetIsInVoluntarySuspension() const {
            return m_is_in_voluntary_suspension;
        }
        
        void SetExclusionGroup(INT exclusion_group) {
            m_exclusion_group = exclusion_group;
        }
        
        INT GetExclusionGroup() const {
            return m_exclusion_group;
        }
        
        // having a true/false setter does not make sense
        void SetInnerRef() {
            m_is_inner_ref = TRUE;
        }
        
        BOOLEAN IsInnerRef() const {
            return m_is_inner_ref;
        }

        virtual void OnStopped();

        // todo internal
        void SetDriverVolume(VolumeLevel volume) {
            m_driver_volume = volume;
        }
        
        // todo internal
        VolumeLevel GetDriverVolume() const {
            return m_driver_volume;
        }


        BOOLEAN SetPlayPosition(UINT32 startPosition);

        BOOLEAN GetPlayPosition();

        BOOLEAN SetPitch(INT32 pitch);

        INT32 GetPitch() const;

        void GetPitchRange(INT32 &minPitch, INT32 &maxPitch) const;

        BOOLEAN SetTempo(INT32 tempo);

        INT32 GetTempo() const;

        BOOLEAN SetRate(INT32 rate);

        INT32 GetRate() const;

        void GetRateRange(INT32 &minRate, INT32 &maxRate) const;
        
        BOOLEAN GetTotalPlayTime(UINT32 &total1,
                                 UINT32 &total2,
                                 UINT32 &total3,
                                 UINT32 &total4);
        
    protected:
        virtual void OnTimer();
        
    protected:
        BOOLEAN m_is_in_voluntary_suspension;
        BOOLEAN m_has_been_stopped_voluntarily;
        AudioDeviceBase* m_device;
        VolumeLevel m_mmi_volume;
        VolumeLevel m_driver_volume;
        BOOLEAN m_mmi_volume_has_been_set; //xxx Otherwise use player's default volume.
        
        BOOLEAN m_timeout_has_occurred;

        SharedPtr<AudioReference> m_audio_reference;
        PlaybackState m_playback_state;

        HandleInsidePlayer m_handle_inside_player;      
        
    private:
        INT m_exclusion_group;      
        BOOLEAN m_is_inner_ref;
    
        //friend class AudioPriorityManager;
      
#endif //DOXYGEN_SHOULD_SKIP_THIS
};

#endif  // Apoxi_AudioActiveReference_hpp


