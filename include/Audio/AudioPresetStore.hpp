/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_AudioPresetStore_hpp)
#define Apoxi_AudioNewAPI_AudioPresetStore_hpp

#include <Kernel/SubSystem.hpp>

#include <Audio/AudioPreset.hpp>
#include <Auxiliary/SharedPtr.hpp>


class PresetAudioReference;

// this is only for backup, it will delete in the future
extern const WCHAR* c_single_beep;
extern const WCHAR* c_tone_supervisory_subsciber_busy;
extern const WCHAR* c_free_tone;
extern const WCHAR* c_tone_supervisory_call_waiting;

class AudioPresetStore : public SubSystem //Inherit from SubSystem because this is a singleton.
{
    protected:
        AudioPresetStore();

    public:
        virtual ~AudioPresetStore();

        virtual const WCHAR* GetName() const;

        virtual BootSequenceState InvokeAt() const;

        virtual void OnPowerUp();

        static AudioPresetStore* GetInstance();

        typedef LinkedList<AudioPreset> PresetList;
        const PresetList& GetPresetList() const;

        SharedPtr<PresetAudioReference> CreateReference(const WString &preset_name) const;
        SharedPtr<PresetAudioReference> CreateReference(AudioPreset::AudioPresetSoundToneId apoxi_tone_id) const;

        typedef AudioPreset::PresetToneType PresetToneType;
        typedef AudioPreset::ToneID ToneID;

        void AddItem(const WString &name, ToneID tone_id, PresetToneType tone_type, BOOLEAN ignore_mangement = FALSE);

        void AddItem(const WString &name, AudioPreset::AudioPresetSoundToneId apoxi_tone_id, ToneID tone_id, PresetToneType tone_type, BOOLEAN ignore_mangement = FALSE);

        WString GetPresetName(const PresetAudioReference& file_reference) const;

    protected:
        PresetList m_preset_list;
        static AudioPresetStore m_instance;

        const AudioPreset* GetPresetForName(const WString &preset_name) const;
        const AudioPreset* GetPresetByID(AudioPreset::AudioPresetSoundToneId preset_ID) const;
};

#endif  // Apoxi_AudioNewAPI_AudioPresetStore_hpp


