/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FmRadioAudioPlayer_hpp)
#define Apoxi_FmRadioAudioPlayer_hpp

#include <Audio/DwdPlayer.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class GenericFeatureData;

class FmRadioAudioPlayer : public DwdPlayer
{
    public:
        static AudioDeviceBase* GetInstance();
        virtual AudioSourceType GetSource() const;
        virtual Vector<MimeTypeSupportInfo> GetMimeTypeSupportInfo() const;

        virtual BOOLEAN CanSuspend(const AudioActiveReference& active_reference) const;
        virtual BOOLEAN CanResume(const AudioActiveReference& active_reference) const;

        virtual void Play(AudioActiveReference& active_reference);

        virtual void Stop(AudioActiveReference& active_reference);

        virtual BOOLEAN IsFeatureSupported(Feature feature, MimeType mime_type = c_mime_unknown,
            AudioReference::SoundDataSource sound_data_source = AudioReference::InvalidSoundDataSource) const;
        virtual BOOLEAN ExecuteFeature(Feature feature, GenericObject* data = 0);

        virtual SharedPtr<AudioReference> CreateAudioReferenceFromExtensionSoundDataSource(
            MimeType mime_type, AudioReference::SoundDataSource sound_data_source);

    protected:

            struct rds_group_0_type {
                    // Block A
                    UINT16 pi;
                    // Block B - LSB first
                    UINT16 segment_address  : 2;
                    UINT16 decoder_id  : 1;
                    UINT16 music_speech_switch  : 1;
                    UINT16 traffic_announcement  : 1;
                    UINT16 program_type  : 5;
                    UINT16 traffic_pi  : 1;
                    UINT16 ab_version  : 1;
                    UINT16 group_type  : 4;
                    // Block C
                    UINT16 alt_freq_or_pi;
                    // Block D - LSB first
                    UINT16 program_service_name_2  : 8;
                    UINT16 program_service_name_1  : 8;
            };

            struct rds_group_2_type {
                    // Block A
                    UINT16 pi;
                    // Block B - LSB first
                    UINT16 segment_address  : 4;
                    UINT16 ab_text  : 1;
                    UINT16 program_type  : 5;
                    UINT16 traffic_pi  : 1;
                    UINT16 ab_version  : 1;
                    UINT16 group_type  : 4;
                    // Block C - LSB first
                    UINT16 radiotext_2  : 8;
                    UINT16 radiotext_1  : 8;
                    // Block D - LSB first
                    UINT16 radiotext_4  : 8;
                    UINT16 radiotext_3  : 8;
            }; 
            
            virtual UINT16 GetDeviceID() const;

      virtual BOOLEAN Play_Allocate(AudioActiveReference &active_reference);
      virtual BOOLEAN Play_Implementation(AudioActiveReference &active_reference);
      virtual BOOLEAN Stop_Implementation(AudioActiveReference &active_reference);

      virtual BOOLEAN OnSdlSignal(UINT16 func_id, UINT8 handle, UINT16 drv_id,
          INT8 return_code, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);

      BOOLEAN SeekStationFeature(GenericFeatureData* data);
      BOOLEAN SetStationFeature(GenericFeatureData* data);
      BOOLEAN RssiLevelFeature(GenericFeatureData* data);
            BOOLEAN RdsFeature(GenericFeatureData* data);
            BOOLEAN RdsStationNameFeature(GenericFeatureData* data);
            BOOLEAN RdsRadioTextFeature(GenericFeatureData* data);
            BOOLEAN RdsRawDataFeature(GenericFeatureData* data);
            BOOLEAN RdsAlternativeFreqFeature(GenericFeatureData* data);

            static void OnRdsTimer(void* client_args);
            void DecodeRdsData();
            void UpdatePi(rds_group_0_type* rds_data);
            void UpdatePty(rds_group_0_type* rds_data);
            void UpdateTrafficProgram(rds_group_0_type* rds_data);
            void UpdateTrafficAnnouncement(rds_group_0_type* rds_data);
            void UpdateStationName(rds_group_0_type* rds_data);
            void UpdateRadioText(rds_group_2_type* rds_data);
            void UpdateAlternativeFrequencies(rds_group_0_type* rds_data);

            static void GetRdsData(UINT8* buffer, UINT16 buffer_size);

    private:
      FmRadioAudioPlayer();

      FmRadioAudioPlayer(const FmRadioAudioPlayer& obj);

      virtual ~FmRadioAudioPlayer();

      static FmRadioAudioPlayer m_singleton_instance;

            static UINT8* m_rds_buffer;
            static UINT16 m_buffer_size;

            SystemTimer m_rds_timer;

            BOOLEAN m_decode_station_name;
            BOOLEAN m_decode_radio_text;
            BOOLEAN m_send_raw_data;
            BOOLEAN m_send_alternative_freq;
      BOOLEAN m_is_decoding;

            BOOLEAN m_pi_changed;
            BOOLEAN m_station_name_complete;
            BOOLEAN m_radio_text_complete;
            BOOLEAN m_alt_freq_complete;
            BOOLEAN m_traffic_program;
            BOOLEAN m_traffic_announcement;
            BOOLEAN m_is_group_a;
            UINT16 m_program_identifier;
            UINT16 m_program_type;
            char m_station_name[9];
            char m_radio_text[65];
            UINT32* m_alt_freq;
            UINT32 m_nr_of_alt_freq;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_FmRadioAudioPlayer_hpp

