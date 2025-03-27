/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioNewAPI_VoiceMemoAudioReference_hpp)
#define Apoxi_AudioNewAPI_VoiceMemoAudioReference_hpp

#include <Audio/StreamAudioReference.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class VoiceMemoAudioReference : public StreamAudioReference
{
    public:
        VoiceMemoAudioReference(const Path& filename, Mode mode, DspFormat format);

        VoiceMemoAudioReference(BufferType buffer_handle, BufferByteType buffer_size, Mode mode,  DspFormat format);

        VoiceMemoAudioReference(const String& filename, Mode mode, DspFormat format);

        VoiceMemoAudioReference(Mode mode, DspFormat format);

        virtual ~VoiceMemoAudioReference();

        virtual enumClassType GetClassType() const;

        virtual UINT16 GetDelay(void) const;
};
#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_AudioNewAPI_VoiceMemoAudioReference_hpp


