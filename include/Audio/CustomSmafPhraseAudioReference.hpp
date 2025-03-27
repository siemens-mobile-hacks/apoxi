/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_CustomSmafPhraseAudioReference_hpp)
#define Apoxi_AudioNewAPI_CustomSmafPhraseAudioReference_hpp

#include <Audio/CustomRingerAudioReference.hpp>


class CustomSmafPhraseAudioReference : public CustomRingerAudioReference
{
    public:
        virtual ~CustomSmafPhraseAudioReference();

        static SharedPtr<CustomSmafPhraseAudioReference> Create(AudioPlayer::ConstBuffer buffer, UINT32 buffer_size);

        static SharedPtr<CustomSmafPhraseAudioReference> Create(AudioPlayer::Buffer buffer, UINT32 buffer_size, BOOLEAN take_ownership);


        virtual enumClassType GetClassType() const;

        virtual ChannelNumber GetNumberOfChannels() const;
        
        virtual VolumeLevel GetChannelVolume() const;
        
        virtual void SetChannelVolume(VolumeLevel val);

        virtual BOOLEAN CanPlayTogetherWith(const AudioReference &audio_ref) const;
        
    protected:
        VolumeLevel m_channelVolume;

        CustomSmafPhraseAudioReference(AudioPlayer::ConstBuffer buffer, UINT32 buffer_size);
        CustomSmafPhraseAudioReference(AudioPlayer::Buffer buffer, UINT32 buffer_size, BOOLEAN take_ownership);

};

#endif  // Apoxi_AudioNewAPI_CustomSmafPhraseAudioReference_hpp


