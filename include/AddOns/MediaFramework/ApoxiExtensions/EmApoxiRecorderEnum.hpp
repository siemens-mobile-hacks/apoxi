/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */
#if !defined (EmApoxiRecorderEnum_hpp)
#define EmApoxiRecorderEnum_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

/* The Rec Prefix to the states are added to avaoid clash with the Player enumeration */
        enum EmApoxiRecorderState {
            EmApoxiRecUnInitializedState = 0,
            EmApoxiRecInitalizedState,
            EmApoxiRecPreviewState,
            EmApoxiRecRecordingState,
            EmApoxiRecPausedState,
            EmApoxiRecAwaitingRecordRespState,
            EmApoxiRecAwaitingPauseRespState,
            EmApoxiRecAwaitingStopRespState,
            EmApoxiRecAwaitingInitResp,
            EmApoxiRecEofProcessing,
            EmApoxiRecErrorProcessing,
            EmApoxiRecErrorState,
            EmApoxiRecWaitingToDestroy
        };

    
#endif // DOXYGEN_SHOULD_SKIP_THIS  
#endif //EmApoxiRecorderEnum_hpp

