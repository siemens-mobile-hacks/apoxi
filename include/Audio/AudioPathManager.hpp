/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioPathManager_hpp)
#define Apoxi_AudioNewAPI_AudioPathManager_hpp

#include <Kernel/MessageHook.hpp>
#include <Audio/AudioPath.hpp>
#include <Audio/AudioAccessoryDetails.hpp>
#include <Apc/SignalHandler/SignalMapTableEntry.hpp> // For ProcessPtr
#include <Apc/Accessory.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS

class AudioMessageHook : public MessageHook
{   
    public:
        virtual BOOLEAN OnMessage(Message& message);
};
#endif

class AudioPathManager
{
    protected:
        //Use GetInstance() instead.
        AudioPathManager();

    public:
        virtual ~AudioPathManager();
        static AudioPathManager* GetInstance();


#ifndef DOXYGEN_SHOULD_SKIP_THIS

        static void OnSdlSignal_AccessoryInd(const ProcessPtr &process_ptr);
#endif //DOXYGEN_SHOULD_SKIP_THIS

        BOOLEAN CanLinkAudioPath(AudioPath& path);

        BOOLEAN IsPathActive(AudioPath& path);

        BOOLEAN AddAudioPath(AudioPath& path);

        BOOLEAN RemoveAudioPath(AudioPath& path);

        void RemoveAllAudioPaths(BOOLEAN upLink = TRUE, BOOLEAN downLink = TRUE);

        BOOLEAN LinkAccessory(const AudioDeviceBase::AudioSourceType source, AudioAccessoryDetails& accessory);

        void UpdateAudioPaths(AudioDeviceBase::AudioSourceType requester_audio_source = AudioDeviceBase::DspAudioSource);

        void EnableUplinkAudioPaths(BOOLEAN enable = TRUE);

        BOOLEAN Enable3dSound(BOOLEAN enable = TRUE);

        BOOLEAN IsCallActive();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        static void OnCallBegin(); 

        static void OnCallEnd();

        static void OnRecordingBegin(); 

        static void OnRecordingEnd();

        static void OnFlipStatusChanged(BOOLEAN flipOpen);

        static void OnChargerConnected(BOOLEAN connected);

        static void UpdateFlipStatus();

        //Initialize audio paths and message hooks
        void Initialize();
    protected:
        void AddPath_Implementation(AudioPath& path);

        void RemovePath_Implementation(AudioPath& path);

        enum UplinkMaskType
        {
            UplinkMaskActiveCall = 0x1,
            UplinkMaskRecording = 0x2,
            UplinkMaskFlipOpen = 0x4
        };

        enum CarkitMaskType
        {
            CarKitConnected = 0x1,
            ChargerConnected = 0x2
        };

    //Helper functions
    private:
        typedef LinkedList<AudioPath> ActivePathList;

        AudioPath* FindPathInActiveList(AudioPath& path);
        void InitPathList(ActivePathList& pathList);
        static UINT16 Map_UplinkPath_APOXI2Drv (const AudioPath::UplinkPathType uplinkPath);
        static UINT16 Map_DownlinkPath_APOXI2Drv (const AudioPath::DownlinkPathType downlinkPath);

        Accessory::Type On_HeadsetStatusChanged(const HeadSet& headset);

        BOOLEAN IsTTYActive();
    private:
        AudioMessageHook m_charger_message_hook;

        AudioMessageHook m_flip_message_hook;

        static AudioPathManager* m_instance;

        ActivePathList m_activePathList;

        //Indicates whether uplink paths are enabled or disabled
        BOOLEAN m_uplink_paths_enabled;

        static UINT8 m_uplink_mask;

        BOOLEAN m_active_call;

        static UINT8 m_hf_carkit_mask;
        
#endif //DOXYGEN_SHOULD_SKIP_THIS
};

#endif  // Apoxi_AudioNewAPI_AudioPathManager_hpp

