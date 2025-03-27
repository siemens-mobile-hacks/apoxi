/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioAccessoryDetails_hpp)
#define Apoxi_AudioNewAPI_AudioAccessoryDetails_hpp

#include <Audio/AudioPlayer.hpp>
#include <Audio/AudioDeviceBase.hpp>
#include <Audio/AudioPath.hpp>
#include <Auxiliary/WString.hpp>


class AudioAccessoryDetails : public Linkable<AudioAccessoryDetails>
{
    public:

        enum AudioAccessoryConfigurationType
        {
            AudioAccessoryCfgNormal = 0x1,
            AudioAccessoryCfgHeadset = 0x2,
            AudioAccessoryCfgStereoPhones = 0x4,
            AudioAccessoryCfgBackspeaker_NormalMic = 0x8,
            AudioAccessoryCfgBluetoothHeadset = 0x10,
            AudioAccessoryCfgBluetoothHandsfree = 0x20,
            AudioAccessoryCfgTTY = 0x40,
            AudioAccessoryCfgCarKit = 0x80,
            AudioAccessoryCfgBluetoothHeadsetRinger = 0x100,
            AudioAccessoryCfgExtRingerHeadset = 0x200,
            AudioAccessoryCfgExtRingerStereoPhones = 0x400,
            AudioAccessoryCfgExtRingerBackspeaker = 0x800,
            AudioAccessoryCfgRecordingNormal  = 0x1000,
            AudioAccessoryCfgRecordingBackspeaker  = 0x2000,
            AudioAccessoryCfgUserDefined1  = 0x4000,
            AudioAccessoryCfgUserDefined2  = 0x8000,
            AudioAccessoryCfgUserDefined3  = 0x10000,
            AudioAccessoryCfgUserDefined4  = 0x20000,
            AudioAccessoryCfgUserDefined5  = 0x40000,
            AudioAccessoryCfgUserDefined6  = 0x80000,
            AudioAccessoryCfgUserDefined7  = 0x100000,
            AudioAccessoryCfgUserDefined8  = 0x200000,
            AudioAccessoryCfgUserDefined9  = 0x400000,
            AudioAccessoryCfgUserDefined11 = 0x800000,
            AudioAccessoryCfgUserDefined12 = 0x1000000,
            AudioAccessoryCfgUserDefined13 = 0x2000000,
            AudioAccessoryCfgUserDefined14 = 0x4000000,
            AudioAccessoryCfgUserDefined15 = 0x8000000,
            AudioAccessoryCfgUserDefined16 = 0x10000000,
            AudioAccessoryCfgUserDefined17 = 0x20000000,
            AudioAccessoryCfgUserDefined18 = 0x40000000,
            AudioAccessoryCfgUserDefined19 = 0x80000000,
            CompatibleWithEverything = 0xFFFFFFFF
        };

        AudioAccessoryDetails(const AudioAccessoryConfigurationType configuration,
                        const AudioPath& uplink,
                        const AudioPath& downlink,
                        BOOLEAN active,
                        const UINT compat_setting,
                        const WString &type_name,
                        const WString &actual_name = "");

        AudioAccessoryDetails::AudioAccessoryConfigurationType GetConfigurationType() const;


        AudioPath& GetUplinkPath() const;

        AudioPath& GetDownlinkPath() const;

        UINT GetCompatibilitySettings() const;

        WString GetName() const;

        void SetActualName(const WString &actual_name);

        WString GetActualName() const;

        void SetConnected(BOOLEAN connected, BOOLEAN update_path = TRUE);
        BOOLEAN GetConnected() const;
        void SetConnectedOld(BOOLEAN connected, BOOLEAN update_path = TRUE, AudioDeviceBase::AudioSourceType audio_source = AudioDeviceBase::DspAudioSource);

        typedef UINT32 ConnectedAccessoriesType;
        static ConnectedAccessoriesType GetConnectedAccessories();


        BOOLEAN IsActive() const;

        virtual void SetVolume(AudioDeviceBase::VolumeLevel val);

        virtual AudioDeviceBase::VolumeLevel GetVolume() const;

        virtual void TurnVolume(BOOLEAN turn_up);

        void UpdateConfiguration();

        BOOLEAN GetUpdatePath() const;

        BOOLEAN CanActivateAudioPaths() const;

        void EnableEcNr(BOOLEAN ecnr) {
            m_enable_ecnr = ecnr;
        }

        BOOLEAN IsEcNrActive() {
            return m_enable_ecnr;
        }
        
#ifndef DOXYGEN_SHOULD_SKIP_THIS

        BOOLEAN GetActivePathStatus();
        
        void SetActivePathStatus(BOOLEAN status);

        virtual void OnAudioPathConnected(BOOLEAN connected, BOOLEAN update_path);

        void SetSelected(BOOLEAN selected);
#endif  
protected:

        WString m_type_name, m_actual_name;
        AudioAccessoryConfigurationType m_accessory_id;
        BOOLEAN m_active;//Indicates if the accessory is connected
        BOOLEAN m_paths_active;//Indicates if the accessory paths are connected
        AudioPath m_uplinkPath;
        AudioPath m_downlinkPath;
        UINT m_compat_setting; // AudioAccessoryConfigurationType's that can work in parallel with this one
        BOOLEAN m_update_path; // indicates that for this accessory the audio paths have to be updated once the AudioPathManager::UpdateAudioPaths() is called
        BOOLEAN m_enable_ecnr; // flag to indicate if echo cancelation/noise reduction should be enabled for this accessory

private:
        static ConnectedAccessoriesType m_connected_accessories;
        BOOLEAN m_is_selected;
};

#endif  // Apoxi_AudioNewAPI_AudioAccessoryDetails_hpp

