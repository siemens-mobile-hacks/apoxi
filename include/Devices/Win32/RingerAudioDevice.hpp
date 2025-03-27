/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(RingerAudioDevice_hpp)
#define RingerAudioDevice_hpp

#include "GenericAudioDevice.hpp"

#include <Auxiliary/Lib.hpp>

class RingerAudioDevice : public GenericAudioDevice {
    public:

        enum RingTone {
            RingerInfoPowerOff,  
            RingerInfoPowerOn,   
            RingerInfoLowBat,
            RingerInfoConnection,
            RingerInfoError1,
            RingerInfoError2,
            RingerInfoDeviceIn,
            RingerInfoDeviceOut,
            RingerInfoMsgFull,
  
            RingerMessage1,
            RingerMessage2,
            RingerMessage3,
            RingerMessage4,
            RingerMessage5,
            RingerMessage6,
            RingerMessage7,
            RingerMessage8,
            RingerMessage9,
            RingerMessage10,

            RingerBroadcast1,
            RingerBroadcast2,
            RingerBroadcast3,
            RingerBroadcast4,
            RingerBroadcast5,
            RingerBroadcast6,
            RingerBroadcast7,
            RingerBroadcast8,
            RingerBroadcast9,
            RingerBroadcast10,

            RingerAlarm1,
            RingerAlarm2,
            RingerAlarm3,
            RingerAlarm4,
            RingerAlarm5,
            RingerAlarm6,
            RingerAlarm7,
            RingerAlarm8,
            RingerAlarm9,
            RingerAlarm10,

            Ringer1,    
            Ringer2,    
            Ringer3,    
            Ringer4,    
            Ringer5,    
            Ringer6,    
            Ringer7,    
            Ringer8,    
            Ringer9,    
            Ringer10,    
            Ringer11,    
            Ringer12,    
            Ringer13,    
            Ringer14,    
            Ringer15,    
            Ringer16,    
            Ringer17,    
            Ringer18,    
            Ringer19,    
            Ringer20,    
            Ringer21,    
            Ringer22,    
            Ringer23,    
            Ringer24,    
            Ringer25,    
            Ringer26,    
            Ringer27,    
            Ringer28,    
            Ringer29,    
            Ringer30,    
            Ringer31,    
            Ringer32,    
            Ringer33,    
            Ringer34,    
            Ringer35,    
            Ringer36,    
            Ringer37,    
            Ringer38,    
            Ringer39,    
            Ringer40,    
            Ringer41,    
            Ringer42,    
            Ringer43,    
            Ringer44,    
            Ringer45,    
            Ringer46,    
            Ringer47,    
            Ringer48,    
            Ringer49,    
            Ringer50,    

            RingerGame1,
            RingerGame2,
            RingerGame3,
            RingerGame4,
            RingerGame5,
            RingerGame6,
            RingerGame7,
            RingerGame8,
            RingerGame9,
            RingerGame10,
        };

        enum RingerDevice {
            RingerDeviceSound,
            RingerDeviceVibrator,
            RingerDeviceSoundAndVibrator
        };

        enum RingerVolume {
            RingerVolumeOff,
            RingerVolume1,
            RingerVolume2,
            RingerVolume3,
            RingerVolume4,
            RingerVolume5,
            RingerVolumeInCall
        };

        enum Format {
            FormatSmaf,             
            FormatMidi,             
            FormatSmafPhrase11,
            FormatRmd,      
            FormatImelody,  
            FormatBuzzer,   
        };

        enum Channel {
            ChannelAll,         
            Channel1,
            Channel2,   
            Channel3,   
            Channel4    
        };

        struct RingerToneInfo {
            RingTone ring_tone_id;
            String name;    
            UINT16 duration;
            BOOLEAN copyright;
        };

        struct StartParam {
            StartParam() {
                use_param = 1;
                Param1.ring_tone = RingerMessage1;
                play_count = 1;
                device = RingerDeviceSound;
            };
            UINT8 use_param;                
            union {
                struct {
                    RingTone ring_tone;     
                } Param1;
                struct {
                    BYTE* buffer;           
                    UINT32 buffer_size;     
                    Format format;          
                    Channel channel;        
                    UINT8 channel_volume;   
                } Param2;
                struct {
                    WCHAR path;             
//iii                   Location loc;       
                    Format format;          
                    Channel channel;        
                    UINT8 channel_volume;   
                } Param3;
            };
            UINT16 play_count;              
            RingerDevice device;            
        };

        RingerAudioDevice();
        virtual ~RingerAudioDevice();   

        virtual const WCHAR* GetName() const;

        virtual AudioReturnCode Init(Priority prio);

        void SetStartParam(const StartParam* p_start_param);

        virtual AudioReturnCode Start(BOOLEAN auto_release = TRUE);

        virtual AudioReturnCode Stop(UINT8 channel = 0);        

        AudioReturnCode SetVolume(RingerVolume volume = RingerVolume3);

        RingerToneInfo GetFixedRingerToneInfo(RingTone ring_tone);

        static AudioReturnCode WriteDefaultRingToneInfo2Ffs();

        static AudioReturnCode WriteRingToneInfo2Ffs(RingTone ring_tone, const RingerToneInfo* info);

        static AudioReturnCode ReadRingToneInfoFromFfs(RingTone ring_rone, RingerToneInfo* info);

    private:
        StartParam m_start_param;
        BOOLEAN m_start_param_set;
};

#endif // RingerAudioDevice_hpp


