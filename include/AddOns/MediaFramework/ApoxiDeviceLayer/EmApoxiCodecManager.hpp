/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiCodecManagerhpp)
#define EmApoxiCodecManagerhpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

class EmApoxiCodecManager {

    public:
        enum ResultType {
            Success = 0,
            MediaNotSupported,
            OutOfMemory,
            SmallBuffer,
            NullParameter,
            InvalidParameter,
            InvalidFrameSize,
            FeatureNotSupported,
            GeneralError,
            MaxNumberOfCodersReached,
            MaxNumberOfOperationsReached,
            ArrayTooShort,
            InvalidState,
            EndOfResultType
        };

        enum CodecType {
            DefaultCodec = 0,
            UnknownCodec,
            Mpeg4Sp,    
            H263Bl,     
            GsmAmrNb,   
            Mpeg4Aac,       
            Qcelp,      
            Evrc,       
            Mp3,        
            Mpeg4AacPlusV1, 
            Mpeg4AacPlusV2, 
            H264Bp,         
            EndOfCodecType
        };

        enum ApplicationCategoriesFlagsType {
            StorageAppCatFlag = 0x1,
            StreamingAppCatFlag = 0x2,
            TelephonyAppCatFlag = 0x4,
            GreatestValueOfApplicationCategoriesFlagsType = TelephonyAppCatFlag
        };

        enum LocationType {
            HostLocation, 
            CompanionLocation, 
            EndOfLocationType
        };

        struct VideoStreamInfo {
            CodecType m_codec_type;
            EmApoxiUINT16 m_ext_width;
            EmApoxiUINT16 m_ext_height;
            EmApoxiUINT16 m_actual_width;
            EmApoxiUINT16 m_actual_height;
            EmApoxiUINT32 m_frame_length;
            EmApoxiUINT16 m_frame_rate_numerator;
            EmApoxiUINT16 m_frame_rate_denominator;
            EmApoxiINT m_top_offset;
            EmApoxiINT m_left_offset;
        };
        
        struct VideoEncoderInfo {
            LocationType m_location;
            EmApoxiUINT32 m_in_buf_max_len;
        };      

        struct VideoEncoderParameters {
            CodecType m_video_codec;
            EmApoxiUINT16 m_width;
            EmApoxiUINT16 m_height;
            EmApoxiUINT16 m_frame_rate_numerator;
            EmApoxiUINT16 m_frame_rate_denominator;
            EmApoxiUINT32 m_bit_rate;
            EmApoxiUINT32 m_timer_resolution;
            EmApoxiUINT16 m_quality_level;
            EmApoxiUINT32 m_application_category;
        };

        struct VideoDecoderParameters {
            CodecType m_video_codec;
            EmApoxiUINT16 m_quality_level;
            EmApoxiUINT16 m_width;
            EmApoxiUINT16 m_height;
        };

        struct AudioStreamInfo {
            CodecType m_codec_type;
            EmApoxiUINT32 m_sampling_frequency;
            EmApoxiUINT32 m_num_of_channels;
        };      

        struct AudioDecoderParameters {
            CodecType m_audio_codec;
            EmApoxiUINT16 m_quality_level;
            EmApoxiINT m_format;
        };

        static EmApoxiCodecManager::ResultType GetAudioStreamInfo( const EmApoxiUINT8* config_stream,
                                                    EmApoxiUINT32& config_len,
                                                    const EmApoxiCodecManager::AudioDecoderParameters& params,
                                                    EmApoxiCodecManager::AudioStreamInfo& stream_info);

};

#endif

#endif // Apoxi_CodecManager_hpp

