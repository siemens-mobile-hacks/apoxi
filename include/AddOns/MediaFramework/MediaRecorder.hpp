/*
*******************************************************************************
                       Copyright eMuzed Inc., 2001-2004.
All rights Reserved, Licensed Software Confidential and Proprietary Information
    of eMuzed Incorporation Made available under Non-Disclosure Agreement OR
                            License as applicable.
*******************************************************************************
*/

/*
*******************************************************************************
Product     : MMFr and MM Apps on APOXI
Module      : MMFr
File        : MediaRecorder.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added private members
------------------------------------------------------------------------ */

#if !defined(MediaRecorder_hpp)
#define MediaRecorder_hpp

#include <Kernel/Types.hpp>
#include "PreComp.hpp"
#include <MediaFramework/MediaManager.hpp>
#include <MediaFramework/RecordSettings.hpp>

class DisplaySettings;
class MediaRecorderImpl;

class  MediaRecorder {
    public:
        
        enum MediaRecorderState {
            UnInitializedState,
            InitalizedState,
            PreviewState,
            AwaitingRecordRespState,
            RecordingState,
            AwaitingPauseRespState,
            PausedState,
            AwaitingStopRespState,
            AwaitingInitResp,
            EofProcessing,
            ErrorProcessing,
            ErrorState,
            DestroyedState
        };

         ~MediaRecorder();

        virtual MediaManager::MmfResult SetDisplaySettings(const DisplaySettings& display_settings);

        virtual MediaManager::MmfResult StartPreview();

        virtual MediaManager::MmfResult StopPreview();

        virtual MediaManager::MmfResult SetRecordSettings(const RecordSettings& record_settings);

        virtual MediaManager::MmfResult SetDisplayAndRecordSettings(
                            const DisplaySettings& display_settings,
                            const RecordSettings& record_settings);

        virtual MediaManager::MmfResult StartRecord ();

        virtual MediaManager::MmfResult PauseRecord();

        virtual MediaManager::MmfResult ResumeRecord();

        virtual MediaManager::MmfResult StopRecord();

        virtual MediaManager::MmfResult GetState(MediaRecorderState& state) const;

        virtual MediaManager::MmfResult GetPosition(UINT32& position) const;

        virtual MediaManager::MmfResult Zoom(BOOLEAN zoom_up);

        virtual MediaManager::MmfResult Unzoom();

        virtual MediaManager::MmfResult SetCameraNightMode(BOOLEAN night_mode_on);

        virtual MediaManager::MmfResult SetCameraMirroring(BOOLEAN mirroring_on);

        virtual MediaManager::MmfResult SetMute(BOOLEAN mute_on);
        
        virtual MediaManager::MmfResult SetPriority(UINT32 priority = 0) ;

        virtual UINT32 GetPriority() const ;

    private:
        MediaRecorder (MediaManager::MmfResult& mmf_result,
                        void *msg_dispatcher,
                        UINT32 audio_priority_value=0,
                        MediaManager::MmfModeType mmf_mode=MediaManager::MmfModeAudioVideo);

        void DestroyInstance();

        MediaRecorderImpl *m_p_media_recorder_impl;
        friend class MediaManager;      // constructs the MediaRecorder object
        
};

#endif // MediaRecorder_hpp

