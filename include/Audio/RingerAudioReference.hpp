/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_RingerAudioReference_hpp)
#define Apoxi_AudioNewAPI_RingerAudioReference_hpp

#include <Audio/PresetAudioReference.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class RingerAudioReference : public PresetAudioReference
{
    public:
        virtual ~RingerAudioReference();

        static SharedPtr<RingerAudioReference> Create(ToneID key_tone_id);

        virtual enumClassType GetClassType() const;

    public:
        RingerAudioReference(ToneID key_tone_id);
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_RingerAudioReference_hpp


