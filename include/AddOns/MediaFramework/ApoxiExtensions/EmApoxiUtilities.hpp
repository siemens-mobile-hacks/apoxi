/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined (EmApoxiUtilities_hpp)
#define EmApoxiUtilities_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiPlayerEnum.hpp"
#include "EmApoxiRecorderEnum.hpp"

EmApoxiMmfModeType TranslateMmfModeType(EmApoxiUINT32 mmf_mode_type);
EmApoxiUINT32 TranslatePlayerState(EmApoxiPlayerState mmf_player_state);
EmApoxiUINT32 TranslateRecorderState(EmApoxiRecorderState mmf_recorder_state);

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //EmApoxiUtilities_hpp

