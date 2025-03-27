/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_PresetAudioReference_hpp)
#define Apoxi_AudioNewAPI_PresetAudioReference_hpp

#include <Auxiliary/WString.hpp>
#include <Audio/AudioReference.hpp>

class PresetAudioReference : public AudioReference
{
    public:
        virtual ~PresetAudioReference();

        typedef UINT ToneID;

    protected:
        PresetAudioReference(ToneID tone_id);


    public:
        WString GetPresetName() const;
        virtual enumClassType GetClassType() const;

        ToneID GetToneID() const;
        void SetToneID(ToneID val);

    protected:
        ToneID m_tone_id;
};

#endif  // Apoxi_AudioNewAPI_PresetAudioReference_hpp


