/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_RadioAudioDevice_hpp)
#define Apoxi_AudioNewAPI_RadioAudioDevice_hpp

#include <Audio/DwdPlayer.hpp>
#include <Audio/RadioAudioDevice.hpp>
#include <Audio/SimpleAudioDevice.hpp>
#include <Audio/DwdDevice.hpp>
#include <Audio/audio_private.hpp>
#include <Auxiliary/WString.hpp>


class RadioAudioDevice : public SimpleAudioDevice,  public DwdDevice
{
    friend class DwdPlayer;

    public:

        enum NotificationType
        {
            NotificationTypeStationFound,
            NotificationTypeBandLimitsReached,
        };

        enum StereoMode
        {
            ModeStereo = 0,
            ModeMono = 1
        };

        enum AudioChannel
        {
            AudioChannelLeft,
            AudioChannelRight,
            AudioChannelBoth
        };

        enum BandLimits
        {
            BandLimitsEuropeUs = 0, // Default
            BandLimitsJapan = 1
        };

        enum SeekMode
        {
            SeekModeAuto,
            SeekModeManual
        };

        enum SeekDirection
        {
            SeekDirectionUp,
            SeekDirectionDown
        };

        enum SearchStopLevel
        {
            SearchStopLevelLow,     // Default
            SearchStopLevelMid,
            SearchStopLevelHigh
        };

        struct StationInfo {

            WString         m_sender_name;

            UINT32          m_frequency;

            UINT8           m_level;

            StereoMode      m_stereo_mode;
        };

    public:
        virtual ~RadioAudioDevice();


        static RadioAudioDevice& GetInstance();


        virtual BOOLEAN Enable(BOOLEAN suspend_all_others = FALSE);


        virtual BOOLEAN Disable();


        BOOLEAN SetStereoMode(RadioAudioDevice::StereoMode mode = RadioAudioDevice::ModeStereo);


        RadioAudioDevice::StereoMode GetStereoMode() const;


        BOOLEAN SelectMuteChannel(RadioAudioDevice::AudioChannel channel = RadioAudioDevice::AudioChannelBoth);


        RadioAudioDevice::AudioChannel GetSelectedMuteChannel() const;


        virtual BOOLEAN SetMute(BOOLEAN enable = TRUE, MuteDirection direction = UpDownlinkDirection);


        BOOLEAN GetChannelMuteState(RadioAudioDevice::AudioChannel channel = RadioAudioDevice::AudioChannelBoth) const;


        BOOLEAN SetBandLimits(RadioAudioDevice::BandLimits limits);


        RadioAudioDevice::BandLimits GetBandLimits() const;


        BOOLEAN SetHighCutControl(BOOLEAN hcc_on = TRUE);


        BOOLEAN GetHighCutControl() const;


        BOOLEAN SetHighLowSideLoInjection(BOOLEAN high = TRUE);


        BOOLEAN GetHighLowSideLoInjection() const;


        BOOLEAN SetSearchStopLevel(RadioAudioDevice::SearchStopLevel level);


        RadioAudioDevice::SearchStopLevel GetSearchStopLevel() const;


        BOOLEAN SeekStation(RadioAudioDevice::SeekDirection direction, RadioAudioDevice::SeekMode mode);


        BOOLEAN SetStation(UINT32 frequency);


        BOOLEAN GetStationInfo(RadioAudioDevice::StationInfo& info);


        virtual AudioSourceType GetSource() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
        //If new volume concept than use the AudioDeviceBase::SetVolume
        //otherwise overwrite the existing function to use the old functions

        //virtual BOOLEAN SetVolume(VolumeLevel volume);
        virtual BOOLEAN ApplyDeviceVolume();

        virtual BOOLEAN Play_Allocate(AudioActiveReference &playing_reference);

    protected:
        virtual UINT16 GetDeviceID() const; //overwrite

    private:


        RadioAudioDevice();


        RadioAudioDevice(const RadioAudioDevice& obj);


        BOOLEAN InitDevice();

        BOOLEAN SetCurrentConfiguration();

        void OnAudioSdlSignal(UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);

        BandLimits m_bandlimits;

        aud_radio_config_data_type m_config;

        StationInfo m_station_info;

        AudioChannel m_mute_channel;

        BooleanCondition m_read_status_wait_condition;

        static RadioAudioDevice m_instance;

        static BOOLEAN m_is_initialized;

#endif // DOXYGEN_SHOULD_SKIP_THIS

}; // class RadioAudioDevice

#endif  // Apoxi_AudioNewAPI_RadioAudioDevice_hpp

