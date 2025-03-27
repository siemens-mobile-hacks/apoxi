/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtiConfig_hpp)
#define AtiConfig_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>
#include <AddOns/CodecManager/AudioCapturerEncoder.hpp>

extern "C"{
#include <gci_audio.h>
}

// Volume definition
const tGciAudioVolume GciVolume = 100; // Volume in percent 0=mute,100=max (as described by ATI)
#endif

