/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_CodecDevice_hpp)
#define Apoxi_CodecDevice_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Macros.hpp>

class CodecDevice {

    public:

        typedef INT32 AudioChannelId;

        struct AudioChannel {
            AudioChannelId m_id;
        };

        typedef UINT32 TimestampMSec;

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

        enum DirectionType {
            UnspecificDirection,
            DecodingDirection,
            EncodingDirection,
            EndOfDirectionType
        };

        enum AmrIfFormat {
            AmrFrameFormatUndefined = 0,
                        AmrFrameFormatConformance, /* KB: Added to ensure match with tGciAudioAmrInterfaceFormatConfig in gci_audio.h */
            AmrFrameFormatIf1,
            AmrFrameFormatIf2,
            AmrFrameFormatMime, /* KB: Added to ensure match with tGciAudioAmrInterfaceFormatConfig in gci_audio.h */
            AmrFrameFormatEnd
        };

        enum EncQualityConfig {
            EncQualityLow,
            EncQualityMid,
            EncQualityHigh
        };

        enum AmrDtxConfig {
            AmrDtxOff = 0,
            AmrDtxOn,
            AmrDtxEnd
        };

        enum AacFormat {
            AacFormatAdts = 0,
            AacFormatAdif,
            AacFormatRaw,
            AacFormatEnd
        };

        enum MonoSteroConfig {
            Mono = 0,
            Stereo,
            DualMono,
            MonoStereoConfigEnd
        };

        struct AudioIOBuffer {
            UINT8* m_buffer;
            UINT32 m_buffer_len;
            BOOLEAN m_last_buffer;
            TimestampMSec m_time;
        };

        struct VideoStreamInfo {
            CodecType m_stream_type;
            UINT32 m_max_bit_rate;
            UINT16 m_ext_width;
            UINT16 m_ext_height;
            UINT16 m_actual_width;
            UINT16 m_actual_height;
            UINT32 m_out_frame_length;
            UINT16 m_frame_rate_numerator;
            UINT16 m_frame_rate_denominator;
            INT m_left_offset;
            INT m_top_offset;
        };
        struct VideoDecoderInfo {
            LocationType m_location;
            BOOLEAN m_clock_support;
        };

        struct VideoEncoderInfo {
            LocationType m_location;
            UINT32 m_in_buf_max_len;
        };

        struct VideoCodecCapabilities {

            VideoCodecCapabilities() : m_array_of_supported_codecs(0) {}

            ~VideoCodecCapabilities() {delete [] m_array_of_supported_codecs;}

            UINT8 m_num_of_supported_codecs;
            CodecType* m_array_of_supported_codecs;
            UINT16 m_min_width;
            UINT16 m_max_width;
            UINT16 m_min_height;
            UINT16 m_max_height;
            UINT16 m_min_frame_rate_numerator;
            UINT16 m_min_frame_rate_denominator;
            UINT16 m_max_frame_rate_numerator;
            UINT16 m_max_frame_rate_denominator;
            UINT32 m_min_bit_rate;
            UINT32 m_max_bit_rate;
            UINT16 m_min_quality_level;
            UINT16 m_max_quality_level;
            UINT32 m_application_categories;
        };

        struct VideoEncoderParameters {
            UINT16 m_actual_width;
            UINT16 m_actual_height;
            UINT16 m_frame_rate_numerator;
            UINT16 m_frame_rate_denominator;
            UINT32 m_bit_rate;
            UINT32 m_timer_resolution;
            UINT16 m_quality_level;
            UINT32 m_application_category;
        };

        struct VideoDecoderParameters {
            UINT16 m_quality_level;
            UINT32 m_max_bit_rate;
            UINT16 m_actual_width;
            UINT16 m_actual_height;
            UINT32 m_length_of_length_field;
            UINT32 m_length_of_header_length_field;
        };

        struct AudioStreamInfo {
            CodecType m_codec_type;
            UINT32 m_sampling_frequency;
            UINT32 m_num_of_channels;
        };

        struct AudioCodecCapabilities {

            AudioCodecCapabilities() : m_array_of_supported_codecs(0) {}

            ~AudioCodecCapabilities() {delete [] m_array_of_supported_codecs;}

            UINT8 m_num_of_supported_codecs;
            CodecType* m_array_of_supported_codecs;
            UINT16 m_min_quality_level;
            UINT16 m_max_quality_level;
            UINT32 m_application_categories;
        };

        struct AudioDecoderParameters {
            CodecType m_audio_codec;
            UINT16 m_quality_level;
            INT m_format;
        };

        struct AudioEncoderParameters {
            UINT32 m_input_sampling_frequency;
            INT m_channel_mode;
            INT m_bit_allocation_method;
            UINT32 m_block_len;
            UINT32 m_num_of_subbands;
            INT16 m_bit_pool;
        };

        struct Properties {

            Properties() : m_array_of_supported_codecs(0) {}

            ~Properties() {delete [] m_array_of_supported_codecs;}

            DirectionType m_direction;
            BOOLEAN m_combined_device;
            CodecType* m_array_of_supported_codecs;
            UINT m_num_of_supported_codecs;
        };

        typedef void (*CbResult)(   ResultType result,
                                    void* context);

        typedef void (*CbResultAndTimeInfo)(ResultType result,
                                            void* context,
                                            UINT32 time_ms);

        virtual ~CodecDevice() {}

        virtual ResultType GetProperties(Properties& properties) = 0;

    protected:

        CodecDevice() {}

        virtual ResultType SetCodec(CodecType codec) = 0;

    private:

        CodecDevice(const CodecDevice& device) { ASSERT_DEBUG(FALSE); }

        CodecDevice& operator=(const CodecDevice& device) {
            if (&device != this) ASSERT_DEBUG(FALSE); return *this;
        }

    friend class CodecManager;

};

#endif // Apoxi_CodecDevice_hpp

