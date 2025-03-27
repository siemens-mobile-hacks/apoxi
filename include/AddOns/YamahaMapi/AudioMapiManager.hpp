/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioMapiManager_hpp)
#define Apoxi_AudioMapiManager_hpp

#include <Audio/AudioReference.hpp> // for PriorityType
#include <Audio/AudioActiveReference.hpp>


class AudioMapiManager
{       
    public:
        enum MapiCommandCodeType {
            CommandGetMode = 0,
            CommandSetMode = 1,// needs priority
            CommandResetMode = 2,// needs priority
            CommandInitialize = 3,// needs priority
            CommandTerminate = 4,
            CommandCheckLoad = 5,// needs priority
            CommandCheckUnload = 6,
            CommandGetContentsData = 7,
            CommandGetPhraseList = 8,
            CommandRealtimeMidiOpen = 9,// needs priority
            CommandRealtimeMidiSendCh = 10,
            CommandRealtimeStartTimer = 11,
            CommandRealtimeStopTimer = 12,
            CommandRealtimeMidiClose =13,
            CommandRealtimeMidiSendSysExMessage = 14,
            CommandRealtimeMidiSetApiVolume = 15,
            CommandRealtimeMidiGetChVolume = 16,
            CommandPhraseAudioLoad = 17,// needs priority
            CommandPhraseAudioOpen = 18,
            CommandPhraseAudioStandby = 19,
            CommandPhraseAudioControl = 20,
            CommandPhraseAudioStart = 21,
            CommandPhraseAudioStop = 22,
            CommandPhraseAudioClose = 23,
            CommandPhraseAudioUnload = 24,
            CommandPhraseGetPosition = 25,
            CommandPhraseSetEvHandler = 26,
            CommandPhraseGetLink = 27,
            CommandPhraseSetLink = 28,
            CommandPhraseKill = 29,
            CommandPhraseSetData = 30,// needs priority
            CommandPhraseSeek = 31,
            CommandPhraseGetLength = 32,
            CommandPhraseSetVolume = 33,
            CommandPhraseSetPanpot = 34,
            CommandPhrasePlay = 35,
            CommandPhraseStop = 36,
            CommandPhraseRemoveData = 37,
            CommandPhraseGetStatus = 38,
            CommandPhrasePause = 39,
            CommandPhraseRestart = 40,
            CommandMelodyControl = 41,
            CommandMelodyOpenArgInit = 42,
            CommandMelodyOpen = 43,
            CommandMelodyStandby = 44,
            CommandMelodyWaitReady = 45,
            CommandMelodyStart = 46,
            CommandMelodyStop = 47,
            CommandMelodySeek = 48,
            CommandMelodyClose = 49,
            CommandMelodyLoad = 50,// needs priority
            CommandMelodyUnload = 51,
            CommandDeviceControl = 52, // note: restricted use: only for (1) vibrator and (2) volume; usage (2) is allowed only for MapiAudioPlayer
            CommandInvalid = 0xff,
            CommandEnd
        };

        struct MapiCommandType {
            MapiCommandCodeType command_code;
            UINT32 parm1;
            UINT32 parm2;
            UINT32 parm3;
            UINT32 parm4;
            UINT32 parm5;
            UINT32 parm6;
            UINT32 parm7;
        };

        enum RequestAcceptanceType {
            RequestExecuted = 0, // request has been accepted and has been executed
            RequestRejected = 1, // the request has been rejected and has NOT been executed
            RequestUnexpectedCommand = 100, // the signal received belongs to a different command
            RequestTimeout = 101, // the request has been accepted and forwarded, but no result message has been received by the priority manager
            RequestAudMapiFailure = 102     // the return-code from AUD_mapi was not aud_rc_ok.
        };


        struct RequestOutcomeType {
            RequestAcceptanceType acceptance_outcome;
            INT32 mapi_return_value;                // the result of the mapi command
        };
        
        static RequestOutcomeType IFX_MAPI(MapiCommandCodeType command_code, UINT32 parm1, UINT32 parm2, UINT32 parm3, UINT32 parm4, UINT32 parm5, UINT32 parm6, UINT32 parm7);

        // callback registration
        static void SetStopCallback(BOOLEAN (*cb_stop)(const AudioActiveReference &active_ref) );

    private:
        // class is actually a namespace workaround, not meant to be instantiated
        AudioMapiManager(); 
        ~AudioMapiManager();
};

#endif  // Apoxi_AudioMapiManager_hpp

