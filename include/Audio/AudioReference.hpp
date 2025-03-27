/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioReference_hpp)
#define Apoxi_AudioReference_hpp

// @TODO check if neeeded
#include <Auxiliary/ObjectReferrer.hpp> //For ReferableObject

#include <Auxiliary/SharedPtr.hpp>
#include <Auxiliary/MimeTypeTable.hpp> // for MimeType

//@TODO remove, along with condition member and impl in cpp;
// note: this has unbelievable dependencies
#include <Kernel/Condition.hpp>

#include <Config/AudioAccessoriesRegistration.hpp> //project-specific, in Config directory. For AudioPathControlModeType

class BinData;
class Semaphore;

class AudioReference : public ReferableObject
{
    public:
        AudioReference();
        virtual ~AudioReference();

        enum enumClassType
        {
            ClassType_AudioReference,
            ClassType_CustomRingerAudioReference,
            ClassType_CustomSmafPhraseAudioReference,
            ClassType_CustomSmafMelodyAudioReference,
            ClassType_CustomToneAudioReference,
            ClassType_PresetAudioReference,
            ClassType_RingerAudioReference,
            ClassType_SimpleAudioReference,
            ClassType_ToneAudioReference,
            ClassType_VoiceMemoAudioReference,
            ClassType_PCMAudioReference,
            ClassType_CustomIMelodyAudioReference,
            ClassType_MP3AudioReference,
#ifdef APOXI_YAMAHA_MAPI_SUPPORT
            ClassType_MapiAudioReference,
            ClassType_InitCommandMapiAudioReference,
#endif
//#ifdef APOXI_LIB_MEDIAFRAMEWORK
            ClassType_CombinedDeviceAudioReference,
//#endif
            ClassType_End
        };
        
        virtual enumClassType GetClassType() const = 0;

        enum PredefinedSoundDataSource {
            InvalidSoundDataSource = 0,
            FileSoundDataSource,
            RamSoundDataSource,
            StreamSoundDataSource,
            PresetSoundDataSource,
            BinDataSoundDataSource,             
            UnknownSoundDataSource,
            FmRadioSoundDataSource,
            PredefinedSoundDataSourceEnd
        };

        typedef INT SoundDataSource;

        class TotalPlayTimeContainer
        {
        public:
            UINT32 m_total_play_time_1;
            UINT32 m_total_play_time_2;
            UINT32 m_total_play_time_3;
            UINT32 m_total_play_time_4;
        };

        friend class AudioPriorityManager;
        friend class RingerAudioPlayer;
        friend class ToneAudioPlayer;

        void SetRepeatCount(UINT16 repeat_count = 0)
        {
            m_repeat_count = repeat_count;
        }

        UINT16 GetRepeatCount() const
        {
            return m_repeat_count;
        }

        BOOLEAN GetRepeatable() const;

        virtual BOOLEAN CanPlayTogetherWith(const AudioReference &audio_ref) const;

                void SetExclusionGroup(INT exclusion_group) {
            m_exclusion_group = exclusion_group;
        }
        
        INT GetExclusionGroup() const {
            return m_exclusion_group;
        }
                
        void SetContinue(BOOLEAN val = TRUE)
        {
            m_continue = val;
        }

        BOOLEAN GetContinue() const
        {
            return m_continue;
        }


#ifndef DOXYGEN_SHOULD_SKIP_THIS

        void LockProperties(BOOLEAN lock = TRUE);
#endif //DOXYGEN_SHOULD_SKIP_THIS

        typedef UINT VolumeLevel;

        void SetVolume(VolumeLevel val);
        
        VolumeLevel GetVolume() const;
        
        BOOLEAN GetVolumeSet() const;

        typedef UINT PriorityType;
        typedef UINT PriorityGroupType;

        void SetPriority(PriorityType val);
        PriorityType GetPriority() const;
        
        void SetPriorityGroup(PriorityGroupType group);
        PriorityGroupType GetPriorityGroup() const;

        void SetIgnoreManagement(BOOLEAN val = TRUE)
        {
            m_ignore_management = val;
        }

        BOOLEAN GetIgnoreManagement() const
        {
            return  m_ignore_management;
        }


        typedef UINT8 ChannelNumber;
        
        void SetChannel(ChannelNumber val);
        
        ChannelNumber GetChannel() const;
        
        
        virtual ChannelNumber GetNumberOfChannels() const;

        virtual VolumeLevel GetChannelVolume() const;
        
        virtual void SetChannelVolume(VolumeLevel val);
        
        typedef INT16 BalanceLevel;

        virtual BalanceLevel GetBalance() const;

        virtual void SetBalance(BalanceLevel value);

        typedef INT16 ToneLevel;

        virtual ToneLevel GetTone() const;

        virtual void SetTone(ToneLevel value);

        void SetTimeout(UINT32 timeout);

        UINT32 GetTimeout() const;


        void SetStartPosition(const UINT32 startPosition);

        UINT32 GetStartPosition() const;

        BOOLEAN GetTotalPlayTime(UINT32 &total1,
                                 UINT32 &total2,
                                 UINT32 &total3,
                                 UINT32 &total4);

        void SetPitch(const INT32 pitch);

        INT32 GetPitch() const;

        void GetPitchRange(INT32 &minPitch, INT32 &maxPitch) const;

        void SetTempo(const INT32 tempo);

        INT32 GetTempo() const;

        void SetRate(const INT32 rate);

        INT32 GetRate() const;

        void GetRateRange(INT32 &minRate, INT32 &maxRate) const;

        AudioPathControl::AudioPathControlModeType GetPathControlMode() const;
        void SetPathControlMode(AudioPathControl::AudioPathControlModeType mode);

        void SetGetTotalPlayTimeWaitCondition(const UINT32 totalPlayTime1,
                                                     const UINT32 totalPlayTime2,
                                                     const UINT32 totalPlayTime3,
                                                     const UINT32 totalPlayTime4,
                                                     BOOLEAN val = TRUE);

        void InitGetTotalPlayTimeWaitCondition(UINT32 time);

        BOOLEAN InProgress() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    protected:              
        UINT16 m_repeat_count;
        BOOLEAN m_continue;

        VolumeLevel m_volume; 
        BOOLEAN m_volume_set; //Otherwise use player's default volume.
        BOOLEAN m_ignore_management; //See SetIgnoreManagement().

        PriorityType m_priority;
        PriorityGroupType m_priority_group;
        BalanceLevel m_balance;
        ToneLevel m_tone;
        
        ChannelNumber m_channel;

        UINT32 m_timeout; 

        BOOLEAN m_properties_lock; 

        UINT32 m_start_position;
        
        
        INT32 m_pitch;
        INT32 m_tempo;
        INT32 m_rate;
    
    public:
        // @todo tota_play_time stuff:
        // 1: should not be public
        // 2: shoul be improved (4 play times; progress; etc)
        Semaphore* m_total_play_time_wait;
        TotalPlayTimeContainer m_total_play_times;
        BOOLEAN m_get_total_play_time_progress;
    
        MimeType GetMimeType() const {
            return m_mime_type;
        }

        void SetMimeType(MimeType mime_type) {
            m_mime_type = mime_type;
        }

        SoundDataSource GetSoundDataSource() const {
            return m_sound_data_source;
        }

        void SetSoundDataSource(SoundDataSource sound_data_source) {
            m_sound_data_source = sound_data_source;
        }

        void SetBinData(BinData* bin_data) {
            m_bin_data = bin_data;
        }
        
        BinData* GetBinData() const {
            return m_bin_data;
        }
        
#endif //DOXYGEN_SHOULD_SKIP_THIS

    private:
        AudioPathControl::AudioPathControlModeType m_path_control_mode;
        MimeType m_mime_type;
        SoundDataSource m_sound_data_source;
        BinData* m_bin_data;
                INT m_exclusion_group;
};

#endif  // Apoxi_AudioReference_hpp

