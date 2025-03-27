/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */
#if !defined (EmApoxiPlayerEnum_hpp)
#define EmApoxiPlayerEnum_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

enum EmApoxiMmfResult {
            EmApoxiSuccess,
            EmApoxiMediaTypeDifferent,
            EmApoxiMediaNotSupported,
            EmApoxiOutOfMemory,
            EmApoxiSmallBuffer,
            EmApoxiNullParameter,
            EmApoxiInvalidParameter,
            EmApoxiInvalidState,
            EmApoxiFeatureNotSupported,
            EmApoxiInvalidAudioTrack,
            EmApoxiInvalidVideoTrack,
            EmApoxiFileNotFound,
            EmApoxiEmptyFile,
            EmApoxiInvalid3gppFile,
            EmApoxiIncomplete3gppFile,
            EmApoxiOpenFileFailure,
            EmApoxiInvalidMp3File,
            EmApoxiCorruptMp3File,
            EmApoxiVidResNotSupported,
            EmApoxiAudSamplFreqNotSupported,
            // This FPS is not supported 
            EmApoxiFpsNotSupported,
            EmApoxiNetworkErrConnErr,
            EmApoxiNetworkErrConnLostErr,
            EmApoxiNetworkErrConnectFailed,
            EmApoxiNetworkErrBandWidthTooHigh,
            EmApoxiNetworkErrUrlNotFound,
            EmApoxiNetworkErrUrlNotStreamable,
            EmApoxiNetworkErrSdpParseError,
            EmApoxiNetworkErrSdpFileOpenError,
            EmApoxiNetworkErrHTTPError,
            EmApoxiNetworkErrRtpDataError,
            EmApoxiNetworkErrUnknownServError,
            EmApoxiNetworkErrBufferingTimeoutError,
            EmApoxiGeneralError
        };
        
        /* The Mmfr API completion messages are communicated to the upper layer 
            through the message types mentioned below*/
        enum EmApoxiMmfMsgType {
            EmApoxiPauseApiCompletionMsg,
            EmApoxiPlayApiCompletionMsg,
            EmApoxiRecordApiCompletionMsg,
            EmApoxiRewindApiCompletionMsg,
            EmApoxiFastForwardApiCompletionMsg,
            EmApoxiStopApiCompletionMsg,
            EmApoxiInitCompletionMsg,
            EmApoxiUninitCompletionMsg,
            EmApoxiEofReachedMsg,
            EmApoxiCriticalErrorMsg,
            EmApoxiNetworkMsgRtcpByeReceived,           
            EmApoxiBufferingStart,
            EmApoxiBufferingComplete,
            EmApoxiMediaInfoObtainedMsg,
            /* Message that communicates completion of destruction of first MediaPlayer */
            MediaPlayerDestroyed,
            /* Message that communicates completion of destruction of first MediaRecorder */
            MediaRecorderDestroyed,

            /* This message is sent when a play is internally issued becuase of a repeat-count */
            EmApoxiPlayApiRepeatedMsg,
        };
        
        enum EmApoxiMmfModeType {
            EmApoxiMmfModeUnspecific=0,
            EmApoxiMmfModePureAudio,
            EmApoxiMmfModeAudioVideo,
            EmApoxiMmfModeEnd
        };

        enum EmApoxiPlayerState {
                EmApoxiUnInitializedState,
                EmApoxiInsideDefaultSelectMedia,
                EmApoxiInitializedState,
                EmApoxiPlayingState,
                EmApoxiPausedState,
                EmApoxiRewindingState,
                EmApoxiFastForwardingState,
                EmApoxiAwaitingPlayRespState,
                EmApoxiAwaitingRewindRespState,
                EmApoxiAwaitingFastForwardRespState,
                EmApoxiAwaitingPauseRespState,
                EmApoxiAwaitingStopRespState,
                EmApoxiAwaitingInitResp,
                EmApoxiEofProcessing,
                EmApoxiBufferingCompleteState,
                EmApoxiBufferingStartState,
                EmApoxiErrorProcessing,
                EmApoxiErrorState,
                EmApoxiWaitingToDestroy,
                
                /* Impact of these states on streaming ?? */
                EmApoxiReadyState,
                EmApoxiEofReceivedState

        };

        enum EmApoxiTrackSelection {
                EmApoxiAudioAndVideo,
                EmApoxiAudioOnly,
                EmApoxiVideoOnly
        };

#endif // DOXYGEN_SHOULD_SKIP_THIS  
#endif //EmApoxiPlayerEnum_hpp

