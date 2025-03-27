/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_VideoDecoder_hpp)
#define Apoxi_VideoDecoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

class VideoDecoder : public CodecDevice {
    public:

        enum ParameterType {
            QualityLevel,
            EndOfParameterType
        };

        enum FlagsType {
            LastFrameFlag = 1<<0,
            LastPacketInFrameFlag = 1<<1,
            ImmediateDecodingFlag = 1<<2,
            GreatestValueOfFlagsType = ImmediateDecodingFlag
        };

        typedef void (*CbFrameDecoded)( ResultType result,
                                        void* context,
                                        const UINT8 HUGE* out_buf,
                                        UINT32 time_stamp);

        typedef void (*CbInBufferFree)( void* context,
                                        UINT8 HUGE* in_buf);

        virtual ResultType Open(VideoDecoderInfo& dec_info) = 0;

        virtual ResultType Close() = 0;

        virtual ResultType Start(
                                CbResultAndTimeInfo cb_video_decoder_started,
                                void* context) = 0;

        virtual ResultType Stop(CbResult cb_video_decoder_stopped,
                                void* context) = 0;

        virtual ResultType SetConfig(
                            const UINT8* config_stream,
                            UINT32& config_len,
                            const VideoDecoderParameters& params,
                            VideoStreamInfo& stream_info) = 0;

        virtual ResultType GetCapabilities(VideoCodecCapabilities& caps) = 0;

        virtual ResultType AllocateOutputBuffers(   UINT8& buf_count,
                                                    UINT32& buf_len) = 0;

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbFrameDecoded cb_frame_decoded,
                                        CbInBufferFree cb_in_buf_free) = 0;

        virtual ResultType SetAssociatedAudioCh(UINT32 audio_channel) = 0;

        virtual ResultType SetVideoClockTime(UINT32 time_ms) = 0;

        virtual ResultType GetCurrentVideoClockTime(UINT32& time_ms) = 0;

        virtual ResultType DecodeFrame( const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        UINT16 flags,
                                        UINT32 time_stamp) = 0;

        virtual ResultType DecodePacket(    const UINT8 HUGE* in_buf,
                                            UINT32 in_buf_len,
                                            UINT16 flags) = 0;

        virtual ResultType ReleaseOutputBuffer(const UINT8 HUGE* out_buf) = 0;

        virtual ResultType FlushBuffers(    CbResult cb_video_decoder_flushed,
                                            void* context) = 0;

    protected:

    private:

    friend class CodecManager;

};

#endif // Apoxi_VideoDecoder_hpp

