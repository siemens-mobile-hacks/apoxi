/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/
#if !defined(ToneAudioDevice_hpp)
#define ToneAudioDevice_hpp

#include <Devices/Win32/GenericAudioDevice.hpp>

class ToneAudioDevice : public GenericAudioDevice {
    public:

        enum Tone {
            ToneDTMF0,
            ToneDTMF1,
            ToneDTMF2,
            ToneDTMF3,
            ToneDTMF4,
            ToneDTMF5,
            ToneDTMF6,
            ToneDTMF7,
            ToneDTMF8,
            ToneDTMF9,
            ToneDTMFHash,
            ToneDTMFAsterix,

            ToneSvSubscriberBusy,
            ToneSvCongestion,
            ToneSvRadioPathAck,
            ToneSvRadioPathNotAvail,
            ToneSvErrorInfo,
            ToneSvCallWaiting,

            ToneInfoFreeTone,
            ToneInfoConnection,
            ToneInfoDisconnect,
            ToneInfoDeviceIn,
            ToneInfoDeviceOut,
            ToneInfoMsgFull,
            ToneInfoUssd,
            ToneInfoMinuteMinder,
            ToneInfoError1,
            ToneInfoError2,
            ToneInfoSmsInCall,
            ToneInfoBroadcastInCall,
            ToneInfoAlarmInCall,
            ToneInfoLowBatInCall,
            ToneInfoPowerOff,  
            ToneInfoPowerOn,   
            ToneInfoSingleBeep,
        };

        enum ToneType {
            NormalUserTone,
            DualUserTone,
            TripleUserTone,
        };

        struct UserTone {
            UINT16 frequency;   
            UINT16 duration;        
        };

        struct StartParam {
            StartParam() {
                use_tone = TRUE;
                tone = ToneDTMF0;
                play_count = 1;
                mix_factor = 0x4000;
            };
            BOOLEAN use_tone;               
            union {
                Tone tone;                  
                struct {
                    UserTone* user_tone;    
                    // Number of tones
                    UINT32 tone_count;      
                    // Type of tone
                    ToneType tone_type;     
                } UTone;
            };

            UINT16 play_count;              
            UINT16 mix_factor;              
        };

        ToneAudioDevice();
        virtual ~ToneAudioDevice(); 

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio);

        void SetStartParam(const StartParam* p_start_param);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        

    protected:
        INT ConvertTone2INT(Tone tone);

    private:
        StartParam m_start_param;
        BOOLEAN m_start_param_set;
};

#endif // ToneAudioDevice_hpp


