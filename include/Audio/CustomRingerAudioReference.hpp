/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_CustomRingerAudioReference_hpp)
#define Apoxi_AudioNewAPI_CustomRingerAudioReference_hpp

#include <Audio/AudioReference.hpp>
#include <Audio/AudioPlayer.hpp>

class CustomRingerAudioReference : public AudioReference
{
    public:
        virtual ~CustomRingerAudioReference();

        enum Format {
            FormatSmaf,
            FormatMidi,
            FormatRmd,
            FormatImelody,
            FormatBuzzer,
            FormatSmafPhrase,
        };

        
        static SharedPtr<CustomRingerAudioReference> Create(AudioPlayer::ConstBuffer buffer, UINT32 buffer_size, Format format);

        static SharedPtr<CustomRingerAudioReference> Create(AudioPlayer::Buffer buffer, UINT32 buffer_size, Format format, BOOLEAN take_ownership);


        virtual enumClassType GetClassType() const;

        AudioPlayer::ConstBuffer GetBuffer() const;
        UINT32 GetBufferSize() const;
        Format GetFormat() const;

    protected:
        CustomRingerAudioReference(AudioPlayer::ConstBuffer buffer, UINT32 buffer_size, Format format);
        CustomRingerAudioReference(AudioPlayer::Buffer buffer, UINT32 buffer_size, Format format, BOOLEAN take_ownership);

    protected:
        AudioPlayer::ConstBuffer m_buffer;
        UINT32 m_buffer_size;
        Format m_format;
        BOOLEAN m_data_owned;
};

#endif  // Apoxi_AudioNewAPI_CustomRingerAudioReference_hpp


