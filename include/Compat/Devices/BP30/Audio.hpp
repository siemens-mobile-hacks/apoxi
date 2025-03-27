/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Audio_hpp)
#define Apoxi_Audio_hpp

#include <Kernel/Types.hpp>
#include <Devices/AbstractDevice.hpp>

#include <stack/driver.h>

class Audio : public AbstractDevice {
    public:

        struct SingleTone {
            UINT16 freq;
            UINT16 dur;
        };

        struct ToneData {
            SingleTone *tones;
            UINT16 nof_tones;
            UINT16 nof_repeats;
        };

        enum AudioPriority {
            PriorityHigh    = 3,
            PriorityMedium  = 2,
            PriorityLow     = 1,
            PriorityNone    = 0
        };

        enum AudioDevice {
            DeviceNone     = 0x0000,
            DeviceBuzzer   = 0x0001,
            DeviceEarPiece = 0x0002,
            DeviceTrembler = 0x0004,
            DeviceOut      = 0x000f,
            DeviceMic      = 0x0010,
            DeviceIn        = 0x00f0
        };
        
        enum AudioMode {
            ModeNormal,
            ModeHeadset,
            ModeHandsfree
        }; 

        enum AudioToneId { 
            ToneDtmf0 = 0,
            ToneDtmf1,  
            ToneDtmf2,  
            ToneDtmf3,  
            ToneDtmf4,  
            ToneDtmf5,  
            ToneDtmf6,  
            ToneDtmf7,  
            ToneDtmf8,  
            ToneDtmf9,  
            ToneDtmfHash,
            ToneDtmfStar,
            ToneSupervisorySubsciberBusy,
            ToneSupervisoryCongestion,
            ToneSupervisoryRadioPathAck,        
            ToneSupervisoryRadioPathNotAvail,
            ToneSupervisoryError,           
            ToneSupervisoryCallWaiting,     
            ToneInfoFree,                   
            ToneInfoLowBat,                 
            ToneInfoConnection,             
            ToneInfoDisconnect,             
            ToneInfoPowerOn,                    
            ToneInfoPowerOff,               
            ToneInfoDeviceIn,               
            ToneInfoDeviceOut,              
            ToneInfoMsgFull,                    
            ToneInfoUssd,                   
            ToneInfoMinuteBeep,
            ToneInfoSmsReceived,
            ToneInfoBroadcast,
            ToneInfoAlarm,
            ToneInfoAutoRedial,
            ToneInfoNetworkAttention,
            ToneInfoDialTone,
            ToneInfoLowBatInCall,
            ToneKey1,                       
            ToneKey2,                       
            ToneKey3,                       
            ToneKey4,                       
            ToneBroadcast1,                 
            ToneBroadcast2,                 
            ToneBroadcast3,                 
            ToneBroadcast4,                 
            ToneMessage1,                   
            ToneMessage2,                   
            ToneMessage3,                   
            ToneMessage4,                   
            ToneMessage5,                   
            ToneMessage6,                   
            ToneMessage7,                   
            ToneMessage8,                   
            ToneMessage9,                   
            ToneMessage10,                  
            ToneMessageSingleBeep,          
            ToneRinging1,                   
            ToneRinging2,                   
            ToneRinging3,                   
            ToneRinging4,                   
            ToneRinging5,                   
            ToneRinging6,                   
            ToneRinging7,                   
            ToneRinging8,                   
            ToneRinging9,                   
            ToneRinging10,                  
            ToneRinging11,                  
            ToneRinging12,
            ToneRinging13,
            ToneRinging14,
            ToneRinging15,
            ToneRinging16,
            ToneRinging17,
            ToneRinging18,
            ToneRinging19,
            ToneRinging20,
            ToneRinging21,
            ToneRinging22,
            ToneRinging23,
            ToneRinging24,
            ToneRinging25,
            ToneRinging26,
            ToneRinging27,
            ToneRinging28,
            ToneRinging29,
            ToneRinging30,
            ToneRinging31,
            ToneRinging32,
            ToneRinging33,
            ToneRinging34,
            ToneRinging35,
            ToneRinging36,
            ToneRinging37,
            ToneRinging38,
            ToneRinging39,
            ToneRinging40,
            ToneRinging41,
            ToneRinging42,
            ToneRinging43,
            ToneRinging44,
            ToneRinging45,
            ToneRinging46,
            ToneRinging47,
            ToneRinging48,
            ToneUserDefined,
            ToneAlarm1,
            AudioInvalidTone
        };               
        
        // Mute direction
        enum MuteDirection {
            MuteUplink      = aud_direction_uplink,
            MuteDownlink    = aud_direction_downlink,
            MuteTch         = aud_direction_updownlink
        };

        // Speech volume: Steps for speech volume are available, with a 3 dB 
        // change for each step. 
        enum SpeechVolume {
            SpeechVolume1 = aud_speech_volume_1,
            SpeechVolume2 = aud_speech_volume_2,
            SpeechVolume3 = aud_speech_volume_3,
            SpeechVolume4 = aud_speech_volume_4,
            SpeechVolume5 = aud_speech_volume_5,
            SpeechVolume6 = aud_speech_volume_6,
            SpeechVolume7 = aud_speech_volume_7,
            SpeechVolume8 = aud_speech_volume_8
        };
                                                                   
        virtual const WCHAR* GetName() const;                        
        
        Audio ();
        
        virtual ~Audio();

        static void Init();                                          
                                                                   
        static BOOLEAN StartTone(AudioToneId tone_id, 
                                 INT nof_repeats = 0,
                                 AudioDevice device = DeviceBuzzer, 
                                 AudioPriority priority = PriorityNone);
                                                                   
        static BOOLEAN StartTone(const ToneData *tone_data,
                                 AudioDevice device = DeviceBuzzer, 
                                 AudioPriority priority = PriorityNone);
                                 
        static void StopTone();
        
        enum VibratorMode
        {
            VibratorModeAsync1 = Aud_vibrator_mode_async_1,
            VibratorModeAsync2 = Aud_vibrator_mode_async_2,
            VibratorModeSync1 = Aud_vibrator_mode_sync_1,
            VibratorModeSync2 = Aud_vibrator_mode_sync_2
        };

        enum VibratorOnTime
        {
            VibratorOnTime400ms = Aud_vibrator_on_400ms,
            VibratorOnTime600ms = Aud_vibrator_on_600ms,
            VibratorOnTime800ms = Aud_vibrator_on_800ms,
            VibratorOnTime1000ms = Aud_vibrator_on_1000ms,
            VibratorOnTimeOn = Aud_vibrator_on
        };
  
        enum VibratorOffTime
        {
            VibratorOffTime200ms = Aud_vibrator_off_200ms,
            VibratorOffTime300ms = Aud_vibrator_off_300ms,
            VibratorOffTime400ms = Aud_vibrator_off_400ms,
            VibratorOffTime600ms = Aud_vibrator_off_600ms,
            VibratorOffTimeOff = Aud_vibrator_off
        };

        //TODO: Are these sensible default values? Murray.
        static BOOLEAN StartVibrator(VibratorMode mode = VibratorModeAsync1,  VibratorOnTime on = VibratorOnTimeOn, VibratorOffTime off = VibratorOffTimeOff);

            static void StopVibrator();          

        static BOOLEAN IsTremblerOn() { return IsVibratorOn(); }
        
        static BOOLEAN IsVibratorOn() { return m_vibrator_on; }
                                                                   
        static void SetVolume(UINT8 volume, AudioDevice device);

        static void SetMute(BOOLEAN mute, AudioDevice device);
        
        static void SetAudioMode(AudioMode audio_mode);

        // Enable uplink and downlink audio path for speech. 
        // The volume level will be level last set with SetVolumeSpeech.
        static BOOLEAN InitSpeech();

        // Powers down the audio path, both uplink and downlink.
        static BOOLEAN ReleaseSpeech();

        // Change the speaker volume. 
        // The audio driver only stores the volume in RAM. 
        static BOOLEAN SetVolumeSpeech(SpeechVolume vol);

        // The audio driver only stores the volume in RAM. 
        static BOOLEAN MuteSpeech(BOOLEAN mute, MuteDirection dir);
    
        static BOOLEAN IsEnabled();
        
    private:
        // Id used for AUD_allocate_resource
        enum ResourceID {
            ToneID      = 1,
            RingerID    = 2,
            SpeechID    = 3
        };

        static BOOLEAN m_vibrator_on;
        static AudioPriority m_priority;
        static BOOLEAN m_init;

            
        //DWD Resources handles:
        static INT8 m_tone;
        static INT8 m_ringer;
        static INT8 m_speech;
        static INT8 m_dwd_resource_vibrator; //Also known as trembler.
        static UINT8 m_no_speech_volume;
    };
#endif  // Apoxi_Audio_hpp

