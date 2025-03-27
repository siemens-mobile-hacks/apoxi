/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_SimpleAudioReference_hpp)
#define Apoxi_AudioNewAPI_SimpleAudioReference_hpp

#include <Audio/AudioReference.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class SimpleAudioReference : public AudioReference
{
    public:
        virtual ~SimpleAudioReference();

        static SharedPtr<SimpleAudioReference> Create();

        virtual enumClassType GetClassType() const;

    protected:
        SimpleAudioReference();

    protected:
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_SimpleAudioReference_hpp


