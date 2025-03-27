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
File        : MediaPlayer.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added private members
------------------------------------------------------------------------ */

#if !defined(MediaPlayer_hpp)
#define MediaPlayer_hpp

#include <Kernel/Types.hpp>
#include <AddOns/MediaFramework/MediaManager.hpp>
#include <AddOns/MediaFramework/DisplaySettings.hpp>

#include "MediaInfo.hpp"
#include "MediaManager.hpp"

class MediaPlayerImpl;
class BinData;
class AudioReference;

class  MediaPlayer {
    public:
        enum State {
            UnInitializedState,
            InsideDefaultSelectMedia,
            InitializedState,
            PlayingState,
            PausedState,
            RewindingState,
            FastForwardingState,
            AwaitingPlayRespState,
            AwaitingRewindRespState,
            AwaitingFastForwardRespState,
            AwaitingPauseRespState,
            AwaitingStopRespState,
            AwaitingInitResp,
            EofProcessing,
            BufferingCompleteState,
            BufferingStartState,
            ErrorProcessing,
            ErrorState,
            DestroyedState,
                            
            /* Impact of these states on streaming ?? */
            ReadyState,
            EofReceivedState
        
        };

        enum TrackSelection {
            AudioAndVideo,
            AudioOnly,
            VideoOnly
        };

        virtual ~MediaPlayer();

        virtual MediaManager::MmfResult SelectMediaTracks(TrackSelection track_selection,
                                    UINT audio_track_id,
                                    UINT video_track_id);

        virtual MediaManager::MmfResult SetDisplaySettings(const DisplaySettings& display_settings);

        virtual MediaManager::MmfResult Play();

        virtual MediaManager::MmfResult Pause();

        virtual MediaManager::MmfResult Stop();

        virtual MediaManager::MmfResult Rewind(INT rate);

        virtual MediaManager::MmfResult FastForward(INT rate);

        virtual MediaManager::MmfResult GetState(MediaPlayer::State& state) const;

        virtual MediaManager::MmfResult SetPosition(INT32 position);

        virtual MediaManager::MmfResult GetPosition(UINT32& position) const;

        virtual MediaManager::MmfResult SetDisplayLocation(INT x, INT y);

        virtual MediaManager::MmfResult Zoom(BOOLEAN zoom_up);

        virtual MediaManager::MmfResult Unzoom();

        virtual MediaManager::MmfResult SetVolumeLevel(UINT volume_level);

        virtual MediaManager::MmfResult SetBassLevel(UINT level);

        virtual MediaManager::MmfResult SetTrebleLevel(UINT level);

        virtual MediaManager::MmfResult SetBalanceLevel(UINT level);

        virtual MediaManager::MmfResult SetPlaybackContrast(UINT level);

        virtual MediaManager::MmfResult SetPlaybackVideoQuality(DisplaySettings::VideoQuality video_quality);

        virtual MediaManager::MmfResult GetFirstVideoFrame(UINT8* buffer, UINT32& buffer_length);
        
        virtual MediaManager::MmfResult SetRepeatCount(UINT16 repeat_count = 1) ;
        
        virtual MediaManager::MmfResult SetContinue(BOOLEAN continue_flag = FALSE) ;

        virtual MediaManager::MmfResult SetPriority(UINT32 priority = 0) ;

        virtual UINT16 GetRepeatCount() const ;

        virtual BOOLEAN GetContinue() const ;

        virtual UINT32 GetPriority() const ;

        virtual AudioReference* GetAudioReference(void) const;


#ifdef ENABLE_STREAMING

        virtual MediaManager::MmfResult GetBuffLevel(UINT32 &buff_level);

        virtual MediaManager::MmfResult SetBufferingTime(UINT32 buff_level);
#endif
    private:
        
        MediaPlayer(const char* location,
                    MediaInfo& media_info,
                    MimeType& media_mime_type,
                    MediaManager::MmfResult& mmf_result,
                    void* msg_dispatcher,
                    UINT32 audio_priority_value=0,
                    MediaManager::MmfModeType mmf_mode=MediaManager::MmfModeAudioVideo);

        MediaPlayer(const BinData* media_source,
                    MediaInfo& media_info,
                    MimeType& media_mime_type,
                    MediaManager::MmfResult& mmf_result,
                    void* msg_dispatcher,
                    UINT32 audio_priority_value=0,
                    MediaManager::MmfModeType mmf_mode=MediaManager::MmfModeAudioVideo);

        void DestroyInstance();

        MediaPlayerImpl* m_p_media_player_impl;
        
        void* media_player_data;
        
        friend class MediaManager;
};

#endif // MediaPlayer_hpp

