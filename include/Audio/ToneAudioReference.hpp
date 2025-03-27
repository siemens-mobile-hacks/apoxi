/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_ToneAudioReference_hpp)
#define Apoxi_AudioNewAPI_ToneAudioReference_hpp

#include <Audio/PresetAudioReference.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class ToneAudioReference : public PresetAudioReference
{
    public:
        virtual ~ToneAudioReference();

        static SharedPtr<ToneAudioReference> Create(ToneID key_tone_id);

        virtual enumClassType GetClassType() const;

    protected:
        ToneAudioReference(ToneID key_tone_id);

};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_ToneAudioReference_hpp


