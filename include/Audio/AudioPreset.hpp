/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioPreset_hpp)
#define Apoxi_AudioNewAPI_AudioPreset_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/WString.hpp>

class AudioPreset : public Linkable<AudioPreset> //Items in a LinkedList need to inherit from Linkable. I don't know why. murrayc.
{
    public:
        typedef UINT ToneID;
        
        AudioPreset();

        enum PresetToneType
        {
            NoToneType,
            ToneType,
            RingerType
        };

        enum AudioPresetSoundToneId
        {
            PresetSoundToneDTMF0,
            PresetSoundToneDTMF1,
            PresetSoundToneDTMF2,
            PresetSoundToneDTMF3,
            PresetSoundToneDTMF4,
            PresetSoundToneDTMF5,
            PresetSoundToneDTMF6,
            PresetSoundToneDTMF7,
            PresetSoundToneDTMF8,
            PresetSoundToneDTMF9,
            PresetSoundToneDTMFHash,
            PresetSoundToneDTMFAsterix,

            PresetSoundToneKeyTone1,
            PresetSoundToneKeyTone2,
            PresetSoundToneKeyTone3,
            PresetSoundToneKeyTone4,
            PresetSoundToneKeyTone5,
             
            PresetSoundToneSvSubscriberBusy,
            PresetSoundToneSvCongestion,
            PresetSoundToneSvRadioPatAck,
            PresetSoundToneSvRadioPathNotAvail,
            PresetSoundToneSvErrorInfo,
            PresetSoundToneSvCallWaiting,

            PresetSoundToneInfoFreeTone,
            PresetSoundToneInfoConnection,
            PresetSoundToneInfoDisconnect,
            PresetSoundToneInfoDeviceIn,
            PresetSoundToneInfoDeviceOut,
            PresetSoundToneInfoMsgFull,
            PresetSoundToneInfoUssd,
            PresetSoundToneInfoMinutteMinder,
            PresetSoundToneInfoError1,
            PresetSoundToneInfoError2,
            PresetSoundToneInfoSmsInCall,
            PresetSoundToneInfoBroadcastInCall,
            PresetSoundToneInfoAlarmInCall,
            PresetSoundToneInfoLowBatInCall,
            PresetSoundToneInfoPowerOff,  
            PresetSoundToneInfoPowerOn,   
            PresetSoundToneInfoSingleBeep,
            PresetSoundToneInfoPositiveAcknowledgement,
            PresetSoundToneInfoNegativeAcknowledgement,
            PresetSoundToneInfoAutoRedial,
            PresetSoundToneInfoNetworkAttention,
            PresetSoundToneInfoDialTone,
            PresetSoundToneInfoLowBat,
            PresetSoundToneRinger1,
            PresetSoundToneUnknown  
        };

        AudioPreset(const WString &name, ToneID tone_id, PresetToneType tone_type, BOOLEAN ignore_management = FALSE, AudioPresetSoundToneId apoxi_tone_id = PresetSoundToneUnknown);
        virtual ~AudioPreset();

        ToneID GetToneID() const;
        
        AudioPresetSoundToneId GetApoxiToneID() const;
        
        WString GetName() const;

        PresetToneType GetToneType() const;

        BOOLEAN GetIgnoreManagement() const;


    protected:
        ToneID m_tone_id;
        AudioPresetSoundToneId m_apoxi_tone_id;
        WString m_name;
        PresetToneType m_tone_type;
        BOOLEAN m_ignore_management; //See AudioReference::SetIgnoreManagement().
};

#endif  // Apoxi_AudioNewAPI_AudioPreset_hpp


