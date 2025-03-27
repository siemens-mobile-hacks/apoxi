/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiCodecUtilshpp)
#define EmApoxiCodecUtilshpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiCodecManager.hpp"
#include "EmApoxiAudioDecoder.hpp"
#include "EmApoxiVideoDecoder.hpp"
#include "EmApoxiVideoEncoder.hpp"

#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioDecoder.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>
#include <AddOns/CodecManager/VideoEncoder.hpp>

EmApoxiCodecManager::ResultType TranslateCodecResultType(CodecManager::ResultType aResult);

EmApoxiCodecManager::CodecType TranslateCodecType(CodecManager::CodecType aCodec);

CodecManager::CodecType TranslateCodecType(EmApoxiCodecManager::CodecType aCodec);

CodecManager::ApplicationCategoriesFlagsType TranslateApplicationCategoriesFlagsType
                                    (EmApoxiCodecManager::ApplicationCategoriesFlagsType aFlag);

EmApoxiCodecManager::LocationType TranslateLocationType(CodecManager::LocationType aLocation);

CodecManager::LocationType TranslateLocationType(EmApoxiCodecManager::LocationType aLocation);

EmApoxiAudioDecoder::ParameterType TranslateAudioDecoderParameterType(
                                                  AudioDecoder::ParameterType aParam);

AudioDecoder::ParameterType TranslateAudioDecoderParameterType(
                                                  EmApoxiAudioDecoder::ParameterType aParam);

EmApoxiAudioDecoder::DecodingFunctionType TranslateAudioDecoderDecodingFctType(
                                                       AudioDecoder::DecodingFunctionType aFct);

AudioDecoder::AacFormatType TranslateAacFormatType(EmApoxiAudioDecoder::AacFormatType aFormat);

EmApoxiVideoDecoder::ParameterType TranslateVideoDecoderParameterType
                                        (VideoDecoder::ParameterType aParam);

VideoDecoder::ParameterType TranslateVideoDecoderParameterType
                                    (EmApoxiVideoDecoder::ParameterType aParam);

EmApoxiVideoDecoder::FlagsType TranslateVideoDecoderFlagsType
                                (VideoDecoder::FlagsType aFlag);

EmApoxiVideoEncoder::ParameterType TranslateVideoEncoderParameterType
                            (VideoEncoder::ParameterType aParam);

VideoEncoder::ParameterType TranslateVideoEncoderParameterType
                            (EmApoxiVideoEncoder::ParameterType aParam);

EmApoxiVideoEncoder::FrameCodingType TranslateVideoEncoderCodingType
                                    (VideoEncoder::FrameCodingType aType);

#endif

#endif

