/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_CustomIMelodyAudioReference_hpp)
#define Apoxi_AudioNewAPI_CustomIMelodyAudioReference_hpp

#include <Audio/CustomRingerAudioReference.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS

class CustomIMelodyAudioReference : public CustomRingerAudioReference
{
    friend class CustomRingerAudioReference;

    public:
        virtual ~CustomIMelodyAudioReference();

        virtual enumClassType GetClassType() const;

    protected:
        CustomIMelodyAudioReference(AudioPlayer::ConstBuffer buffer, UINT32 buffer_size);
        CustomIMelodyAudioReference(AudioPlayer::Buffer buffer, UINT32 buffer_size, BOOLEAN take_ownership);

};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_CustomIMelodyAudioReference_hpp


