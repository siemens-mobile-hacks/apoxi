/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_CustomToneAudioReference_hpp)
#define Apoxi_AudioNewAPI_CustomToneAudioReference_hpp

#include <Audio/AudioReference.hpp>


class CustomToneAudioReference : public AudioReference
{
    public:
        virtual ~CustomToneAudioReference();

        enum ToneType {
            NormalTone,
            DualTone,
            TripleTone
        };

        typedef INT16 DefaultAmplitude;

        static SharedPtr<CustomToneAudioReference> Create(const void *tone_data, ToneType tone_type, UINT32 no_of_tones);

        virtual enumClassType GetClassType() const;

        const void* GetBuffer() const;

        static CustomToneAudioReference::DefaultAmplitude GetDefaultAmplitude();
        
        ToneType GetToneType() const;
        void SetToneType(CustomToneAudioReference::ToneType type);
        
        UINT32 GetNumberOfTones() const;
        void SetNumberOfTones(UINT32 no_of_tones);

    protected:
        CustomToneAudioReference(const void *tone_data, ToneType tone_type, UINT32 no_of_tones);

    protected:
        const void *m_tone_data;
        ToneType m_tone_type;
        UINT32 m_no_of_tones;
};

#endif  // Apoxi_AudioNewAPI_CustomToneAudioReference_hpp


