/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioPath_hpp)
#define Apoxi_AudioNewAPI_AudioPath_hpp

#include "AudioDeviceBase.hpp" // for AudioSourceType


class AudioPath : public Linkable<AudioPath>
{
    public:
        enum AudioPathType
        {
            AudioPathDownlink,
            AudioPathUplink
        };

    /*The enum values should not be changed because path manager uses
     these values as there currently are
    */

        enum UplinkPathType
        {
            UplinkPathHandsetMic = 0x1,
            UplinkPathHeadsetMic = 0x2,
            //HF car kit mic
            UplinkCarKit = 0x4,
            UplinkPathI2S1_Rx = 0x8,
            UplinkPathTTY = 0x10,
            UplinkPathRecordingHandsetMic = 0x20,
            // this path has special settings that avoid some echo canceling issues
            UplinkPathDthfMic = 0x40,
            // Bluetooth inband ringing
            UplinkPathI2S1InbandRx = 0x80,
            UplinkPathNone = 0x0
        };

        enum DownlinkPathType
        {
            DownlinkPathEarpiece = 0x1,
            DownlinkPathMonoHeadset = 0x2,
            DownlinkPathStereoHeadset = 0x4,
            DownlinkPathBackspeaker = 0x8,
            DownlinkPathI2S1_Tx = 0x10,
            DownlinkPathTTY = 0x20,
            DownlinkCarKit = 0x40,
            DownlinkPathExtRingerMonoHeadset = 0x80,
            DownlinkPathExtRingerStereoHeadset = 0x100,
            DownlinkPathExtRingerBackspeaker = 0x200,
            DownlinkPathExtRingerI2S1_Tx = 0x400,
            DownlinkPathBackspeakerStereo = 0x800,
            DownlinkPathFmRadioBackspeaker = 0x1000,
            DownlinkPathFmRadioHeadset = 0x2000,
            DownlinkPathNone = 0x0
        };

        AudioPath(const AudioPath& path);

        AudioPath(const UplinkPathType uplinkPath);

        AudioPath(const DownlinkPathType downlinkPath);

        AudioPath::AudioPathType GetAudioPathType() const;

        UINT16 GetPath() const;

        AudioDeviceBase::AudioSourceType GetAudioSourceType() const;

        BOOLEAN operator==(const AudioPath& path) const;

        AudioPath & operator = (const AudioPath::UplinkPathType path);

        AudioPath & operator = (const AudioPath::DownlinkPathType path);
    private:
        UINT16 m_audio_path;
        AudioPathType m_path_type;
};

#endif  // Apoxi_AudioNewAPI_AudioPath_hpp

