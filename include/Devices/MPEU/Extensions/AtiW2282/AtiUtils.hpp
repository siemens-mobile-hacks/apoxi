/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtiUtils_hpp)
#define AtiUtils_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

extern "C"{
#include <gci_common.h>
#include <gci_audio.h>
}

namespace AtiUtils {
        /* Bitrate constansts for encoder settings */
        static const tGciAudioAmrBitrateConfig  c_GciAmrEncQualityLow   = GCI_AUDIO_AMR_BITRATE_4750;
        static const tGciAudioAmrBitrateConfig  c_GciAmrEncQualityMid   = GCI_AUDIO_AMR_BITRATE_7400;
        static const tGciAudioAmrBitrateConfig  c_GciAmrEncQualityHigh  = GCI_AUDIO_AMR_BITRATE_12200;
        static const tGciAudioBitrate           c_GciAacEncQualityLow   = 24000;
        static const tGciAudioBitrate           c_GciAacEncQualityMid   = 48000;
        static const tGciAudioBitrate           c_GciAacEncQualityHigh  = 96000;

        /******************************************************************************
        *                             ConvertFromGCIFormat                            *
        *                                   Functions                                 *
        *       Used for converting from GCI types to the types specified in the      *
        *                              CodecDevice class.                             *
        ******************************************************************************/

        CodecDevice::ResultType ConvertFromGCIFormat(tGciResult input);

        CodecDevice::AudioChannel ConvertFromGCIFormat(tGciAudioHandle input);

        UINT8* ConvertFromGCIFormat(UINT32* input);

        BOOLEAN ConvertFromGCIFormat(tGciBoolean input);

        CodecDevice::TimestampMSec ConvertFromGCIFormat(tGciAudioTimestampMSec input);

        /******************************************************************************
        *                              ConvertToGCIFormat                             *
        *                                  Functions                                  *
        *   Used for converting from CodecDevice class types to GCI specified types.  *
        *                                                                             *
        ******************************************************************************/

        tGciAudioHandle ConvertToGCIFormat(CodecDevice::AudioChannel input);

        tGciAudioAmrInterfaceFormatConfig ConvertToGCIFormat(CodecDevice::AmrIfFormat input);

        tGciAudioAmrBitrateConfig ConvertAMRToGCIFormat(CodecDevice::EncQualityConfig input);
        
        tGciAudioAmrDtxConfig ConvertToGCIFormat(CodecDevice::AmrDtxConfig input);

        tGciAudioAacFormat ConvertToGCIFormat(CodecDevice::AacFormat input);

        tGciAudioSamplingFreqHz ConvertToGCIFormat(UINT16 input);

        tGciAudioBitrate ConvertAACToGCIFormat(CodecDevice::EncQualityConfig input);

        tGciAudioMonoStereoConfiguration ConvertToGCIFormat(CodecDevice::MonoSteroConfig input);

        tGciAudioFormat ConvertToGCIFormat(CodecDevice::CodecType codec);

        UINT32* ConvertToGCIFormat(const UINT8* input);

        tGciBoolean ConvertToGCIFormat(BOOLEAN input);

        tGciAudioTimestampMSec ConvertToGCIFormat(CodecDevice::TimestampMSec input);
 };
#endif //AtiUtils_hpp

