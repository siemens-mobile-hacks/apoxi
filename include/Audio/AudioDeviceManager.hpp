/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioDeviceManager_hpp)
#define Apoxi_AudioDeviceManager_hpp



#include <Audio/AudioAccessoryStore.hpp>
#include <Audio/AudioDeviceBase.hpp>
#include <Audio/AudioPlayer.hpp>

#include <Audio/AudioVibratorDevice.hpp>
#include <Audio/SpeechSimpleAudioDevice.hpp>

#include <Audio/AudioPreset.hpp>

class Path;
class BinData;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
class AudioCallback;
#endif //DOXYGEN_SHOULD_SKIP_THIS


class AudioDeviceManager
{
    private:
        //Use GetInstance() instead.
        AudioDeviceManager();

    public:
        virtual ~AudioDeviceManager();
        static AudioDeviceManager& GetInstance();

        typedef enum {
            
            ToneDeviceID,
            RingerDeviceID,
            MIDIRingerDeviceID,
            VoiceMemoDeviceID,
            PCMDeviceID,
            MP3DeviceID,
            SpeechDeviceID,
            VibratorDeviceID,
            RadioDeviceID,
            YamahaMapiId, 

            AudioDeviceEndId
        } AudioDeviceID;

        AudioDeviceBase* GetDevice(AudioDeviceID device);

        AudioPlayer* GetAudioPlayer(const AudioReference &file_reference);
            
        SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type,  AudioPlayer::Buffer buffer, UINT32 buffer_size);

        SharedPtr<AudioReference> CreateAudioReferenceFromRamBuffer(MimeType mime_type,  AudioPlayer::ConstBuffer buffer, UINT32 buffer_size);

        SharedPtr<AudioReference> CreateAudioReferenceFromStream(MimeType mime_type, AudioPlayer::GetAudioBufferFunction func, void* user_data = 0);

        SharedPtr<AudioReference> CreateAudioReferenceFromPreset(MimeType mime_type, AudioPreset::AudioPresetSoundToneId tone_id);
            
        SharedPtr<AudioReference> CreateAudioReferenceFromBinData(MimeType mime_type, BinData* bin_data);           

        SharedPtr<AudioReference> CreateAudioReferenceFromExtensionSoundDataSource(MimeType mime_type, AudioReference::SoundDataSource sound_data_source);  

        SharedPtr<AudioReference> CreateAudioReferenceFromFFS(const String& filename);

        SharedPtr<AudioReference> CreateAudioReferenceFromRFS(const Path& path);


        static SharedPtr<AudioActiveReference> Play(const AudioReference &file_reference);
        
        static void SuspendAllPlayingSounds();

        static void StopAllSounds();
        
        static SharedPtr<AudioActiveReference> StartRecording(const AudioReference &audio_ref);

        static void StopRecording(AudioActiveReference &active_reference);      

        static BOOLEAN SetMasterVolume(AudioDeviceBase::VolumeLevel volume);

        static AudioDeviceBase::VolumeLevel GetMasterVolume();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        static void EnableEcNr(BOOLEAN enable);
#endif

        static BOOLEAN EnableMasterMute(BOOLEAN enable = TRUE);

        static BOOLEAN GetMasterMute();
        
        typedef AudioPlayer::AudioSourceType SourceType; //DSP, Ringer/PolyphonicChip

        BOOLEAN LinkAccessory(SourceType source, AudioAccessoryDetails &accessory);
        
        AudioAccessoryDetails::AudioAccessoryConfigurationType GetLinkedAccessory(SourceType source) const;

        typedef AudioAccessoryStore::AccessoryList AccessoryList; 
        // Gets the list of accessories. Convenience method for AudioAccessoryStore::GetAccessoryList
        const AccessoryList GetAccessoryList() const;   

        typedef void (*OnAudioMessageCallback)(const Message* message, void* pUserData);

        void SubscribeAudioMessageCallback(OnAudioMessageCallback func, void* pUserData = 0);

        void UnsubscribeAudioMessageCallback(OnAudioMessageCallback func, void* pUserData = 0);

        static void PostAudioUserDefinedMessage (UINT8 messageID, UINT16 senderID = 0, UINT32 param1 = 0, UINT32 param2 = 0, UINT32 param3 = 0, UINT32 param4 = 0);

                static void MapAndUpdateVolumes();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

        void PostAudioMessage (const Message& message) const;
#endif // DOXYGEN_SHOULD_SKIP_THIS

    protected:
        // singleton instance
        static AudioDeviceManager m_Instance;

        //master volume 
        static AudioDeviceBase::VolumeLevel m_master_volume;

        //master mute 
        static BOOLEAN m_master_mute;
        
        //state of echo cancelation and noise reduction
        static BOOLEAN m_ecnr_state;

        AudioAccessoryDetails::AudioAccessoryConfigurationType m_accessory; // See comment in GetLinkedAccessory() implementation.

        // Simple Devices available:
        // xxx @todo
        AudioVibratorDevice m_device_vibrator;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
        typedef LinkedList<AudioCallback> CallbackRegistrationList;
        // list of registered callback functions to be called when APOXI message has been sent
        CallbackRegistrationList m_callbackRegistrationList;
#endif
};

#endif  // Apoxi_AudioDeviceManager_hpp

