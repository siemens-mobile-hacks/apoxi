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
File        : MediaManager.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added Error resutls
1st  October 2004       Nirmal U            Added messages for Streaming
------------------------------------------------------------------------ */

#if !defined(MediaManager_hpp)
#define MediaManager_hpp

class BinData;
class Stream;
class MediaPlayer;
class MediaRecorder;
class MediaInfo;
class MediaFrameworkCaps;

#include <Kernel/Types.hpp>
#include <Auxiliary/MimeTypeTable.hpp>
#include "PreComp.hpp"

class MediaManager {
    public:
        enum MmfResult {
            Success = 0,
            MediaTypeDifferent,
            MediaNotSupported,
            OutOfMemory,
            SmallBuffer,
            NullParameter,
            InvalidParameter,
            InvalidState,
            FeatureNotSupported,
            InvalidAudioTrack,
            InvalidVideoTrack,
            FileNotFound,
            EmptyFile,
            Invalid3gppFile,
            Incomplete3gppFile,
            OpenFileFailure,
            InvalidMp3File,
            CorruptMp3File,
            VidResNotSupported,
            AudSamplFreqNotSupported,
            // This FPS is not supported 
            FpsNotSupported,
            GeneralError
        };
        
        /* The Mmfr API completion messages are communicated to the upper layer 
            through the message types mentioned below*/
        enum MmfMsgType {
            PauseApiCompletionMsg,
            PlayApiCompletionMsg,
            RecordApiCompletionMsg,
            RewindApiCompletionMsg,
            FastForwardApiCompletionMsg,
            StopApiCompletionMsg,
            InitCompletionMsg,
            UninitCompletionMsg,
            EofReachedMsg,
            CriticalErrorMsg,
            NetworkMsgRtcpByeReceived,
            MediaTypeNotSupportedMsg,
            SamplingFrequencyNotSupportedMsg,
            NetworkErrConnErr,
            NetworkErrConnLostErr,
            NetworkErrUnknown,
            NetworkErrConnectFailed,
            NetworkErrBandWidthTooHigh,
            NetworkErrUrlNotFound,
            NetworkErrUrlNotStreamable,
            NetworkErrSdpParseError,
            NetworkErrSdpFileOpenError,
            NetworkErrHTTPError,
            NetworkErrRtpDataError,
            NetworkErrUnknownServError,
            NetworkErrCriticalError,
            BufferingStart,
            BufferingComplete,
            MediaInfoObtainedMsg,
            UnknownErrorMsg
        };

        static MediaManager& GetInstance();

        MediaPlayer* CreateMediaPlayer(const BinData* media_source,
                                       MediaInfo& media_info,
                                       MimeType& media_mime_type,
                                       void *mesg_dispatcher,
                                       MmfResult& result);

        MediaPlayer* CreateMediaPlayer(const char* media_source,
                                       MediaInfo& media_info,
                                       MimeType& media_mime_type,
                                       void *mesg_dispatcher,
                                       MmfResult& result);

        void DestroyMediaPlayer(MediaPlayer* media_player);

        MediaRecorder* CreateMediaRecorder(void *mesg_dispatcher, MmfResult& mmf_result);
        
        void DestroyMediaRecorder(MediaRecorder* media_recorder);

        const MediaFrameworkCaps* GetCapabilities() const;

    private:
        static BOOLEAN m_initialized;
        static Semaphore m_sem;
        static BOOLEAN m_is_player_recorder_created;

        MediaManager();
};

#endif // MediaManager_hpp

