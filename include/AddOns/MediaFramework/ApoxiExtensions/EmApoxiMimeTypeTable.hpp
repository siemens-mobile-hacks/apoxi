/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined (EmApoxiMimeTypeTable_hpp)
#define EmApoxiMimeTypeTable_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

enum EmApoxiMimeType {
        EmApoxiMimeAudioRawAac,
        EmApoxiMimeAudioMpeg,
        EmApoxiMimeVideo3gpp,
        EmApoxiMimeAudio3gpp,
        EmApoxiMimeUnknown
 };

EmApoxiMimeType TranslateMimeType(EmApoxiUINT32 media_mime_type);

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //EmApoxiMimeTypeTable_hpp

