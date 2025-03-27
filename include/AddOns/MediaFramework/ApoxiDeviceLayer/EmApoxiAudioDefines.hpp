/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EmApoxiAudioDefines_hpp)
#define EmApoxiAudioDefines_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

#define EMAPOXI_DEFAULT_VOLUME  50
#define EMAPOXI_MAX_VOLUME      100
#define EMAPOXI_MIN_VOLUME      0

typedef void (*tEaadCallBackFxn)(EmApoxiUINT8** audio_buffer,EmApoxiUINT16* size,void *userdata);
typedef void * tEmApxAudDeviceHdl;

typedef enum
{
    Eaad8000PlaybackSampRate,
    Eaad11025PlaybackSampRate,
    Eaad12000PlaybackSampRate,
    Eaad16000PlaybackSampRate,
    Eaad22050PlaybackSampRate,
    Eaad24000PlaybackSampRate,
    Eaad32000PlaybackSampRate,
    Eaad44100PlaybackSampRate,
    Eaad48000PlaybackSampRate,
    EaadInvalidPlaybackSampRate
}EaadPlayBackSamplingRate;

typedef enum
{
    Eaad4_75RecordSampRate,
    Eaad5_15RecordSampRate,
    Eaad5_90RecordSampRate,
    Eaad6_70RecordSampRate,
    Eaad7_40RecordSampRate,
    Eaad7_95RecordSampRate,
    Eaad10_20RecordSampRate,
    Eaad12_20RecordSampRate,
    EaadFullRecordSampRate,
    EaadInvalidRecordSampRate,
}EaadRecordSamplingRate;

typedef enum
{
    EaadStereoMode,
    EaadMonoMode,
    EaadMonoReplicate,
    EaadInvalidNumChannels
}EaadNumChannels;

typedef enum
{
    EaadMediaAmrNb, 
    EaadMediaPcm
}EaadMediaType;

typedef enum
{
    EaadAttributeSamplingRate,  
    EaadAttributeNumChannels,   
    EaadAttributeMediaType,
    EaadAttributeVolume,
    EaadAttributePriority,
    EaadAttributeRepeatCount,
    EaadAttributeContinue,
    EaadAttributeAudioReference,
    EaadNumAttributes,
    EaadAttributeLastBytes,
    EaadAttributeIgnorePriority

}EaadAttributes;

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiAudioDefines_hpp

