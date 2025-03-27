/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioDecoder_hpp)
#define Apoxi_AudioDecoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

class AudioDecoder : public CodecDevice {
    public:

        enum ParameterType {
            QualityLevel,
            Format,
            EndOfParameterType
        };

        enum DecodingFunctionType {
            DecodeBufferFct,
            DecodeFrameFct
        };

        enum AacFormatType {
            AacRawFormat,
            AacAdifOrAdtsFormat,
            AacAdtsWithOneRawDataBlockFormat
        };

        typedef void (*CbFrameDecoded)( ResultType result,
                                        void* context,
                                        const UINT8 HUGE* out_buf,
                                        UINT32 out_buf_len,
                                        UINT32 in_buf_used);

        virtual ResultType Open() = 0;

        virtual void Close() = 0;

        virtual ResultType SetConfig(   const UINT8* config_stream,
                                        UINT32& config_len,
                                        const AudioDecoderParameters& params,
                                        AudioStreamInfo& stream_info) = 0;

        virtual ResultType GetCapabilities(AudioCodecCapabilities& caps) = 0;

        virtual ResultType AllocateOutputBuffers(
                                            UINT8 HUGE** &out_buf_array,
                                            UINT8& out_buf_count,
                                            UINT32& out_buf_len,
                                            DecodingFunctionType& dec_fct) = 0;

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbFrameDecoded cb_frame_decoded) = 0;

        virtual ResultType DecodeBuffer(    const UINT8 HUGE* in_buf,
                                            UINT32 in_buf_len,
                                            const UINT8 HUGE* out_buf,
                                            UINT32 out_buf_len) = 0;

        virtual ResultType DecodeFrame( const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        const UINT8 HUGE* out_buf,
                                        UINT32 out_buf_len) = 0;

        virtual ResultType SetParameters(   const ParameterType* types_array,
                                            const UINT32* values_array,
                                            UINT8 array_count) = 0;

        virtual ResultType GetParameters(   const ParameterType* types_array,
                                            UINT32* values_array,
                                            UINT8 array_count) = 0;

    protected:

    private:

    friend class CodecManager;

};

#endif // Apoxi_AudioDecoder_hpp

