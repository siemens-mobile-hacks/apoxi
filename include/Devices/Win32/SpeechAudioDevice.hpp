/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(SpeechAudioDevice_hpp)
#define SpeechAudioDevice_hpp

#include "GenericAudioDevice.hpp"

class SpeechAudioDevice : public GenericAudioDevice {
    public:

        enum MuteDirection {
            MuteUplink,
            MuteDownlink,
            MuteUpDownlink
        };

        enum SpeechVolume {
            SpeechVolume1 = 1,
            SpeechVolume2,
            SpeechVolume3,
            SpeechVolume4,
            SpeechVolume5,
            SpeechVolume6,
            SpeechVolume7,
            SpeechVolume8
        };

        SpeechAudioDevice();
        virtual ~SpeechAudioDevice();   

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        

        AudioReturnCode SetVolume(SpeechVolume volume);

        AudioReturnCode Mute(BOOLEAN mute, MuteDirection direction);
    };

#endif // SpeechAudioDevice_hpp


