/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtiMpeg4Decoder_hpp)
#define AtiMpeg4Decoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>

class AtiMpeg4DecoderThread;

const UINT8 c_ati_codec_max_num_of_mpeg4_dec_inst = 1;

class AtiMpeg4Decoder : public VideoDecoder {

    typedef VideoDecoder Base;

    public:

        virtual ~AtiMpeg4Decoder();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType Open(VideoDecoderInfo& dec_info);

        virtual ResultType Close();

        virtual ResultType Start(
                                CbResultAndTimeInfo cb_video_decoder_started,
                                void* context);

        virtual ResultType Stop(
                                CbResult cb_video_decoder_stopped,
                                void* context);

        virtual ResultType SetConfig(
                            const UINT8* config_stream,
                            UINT32& config_len,
                            const VideoDecoderParameters& params,
                            VideoStreamInfo& stream_info);



        virtual ResultType GetCapabilities(
                                                    VideoCodecCapabilities& caps);

        virtual ResultType AllocateOutputBuffers(
                                                UINT8& out_buf_count,
                                                UINT32& out_buf_len);

        virtual ResultType RegisterCallbackFunctions(
                                                void* context,
                                                CbFrameDecoded cb_frame_decoded,
                                                CbInBufferFree cb_in_buf_free);

        virtual ResultType SetAssociatedAudioCh(
                                        UINT32 audio_channel);

        virtual ResultType SetVideoClockTime(
                                        UINT32 time_ms);

        virtual ResultType GetCurrentVideoClockTime(
                                        UINT32& time_ms);

        virtual ResultType DecodeFrame(
                                        const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        UINT16 flags,
                                        UINT32 time_stamp);

        virtual ResultType DecodePacket(
                                        const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        UINT16 flags);

        virtual ResultType ReleaseOutputBuffer(
                                                const UINT8 HUGE* out_buf);

        virtual ResultType FlushBuffers(
                                        CbResult cb_video_decoder_flushed,
                                        void* context);

    protected:

        virtual ResultType SetCodec(CodecType codec);

    private:

        enum StateType {
            IdleState = 0, 
            OpeningState,
            OpenState,
            StartingState,
            StartedState,
            StoppingState,
            ClosingState
        };

        struct StateFlags {
            UINT m_state                        :3; 
            UINT m_out_buffers_allocated        :1; 
            UINT m_callback_funcs_registered    :1; 
            UINT m_set_config_called            :1; 
            UINT m_stop_requested               :1; 
            UINT m_close_requested              :1; 
        };

        static void CbNotifyInBufferFree(   void* context,
                                            UINT8* in_buf);

        static void CbNotifyStarted(INT result, void* context, UINT32 time_ms);

        static void CbNotifyStopped(INT result, void* context);

        static void CbNotifyBuffersFlushed(INT result, void* context);
        
        CbInBufferFree m_cb_in_buf_free;
        CbResultAndTimeInfo m_cb_started;
        CbResult m_cb_stopped;
        CbResult m_cb_buffers_flushed;

        static AtiMpeg4Decoder* m_exist_this_ptr_array[c_ati_codec_max_num_of_mpeg4_dec_inst];
        
        void* m_client_context_inbuf_free;
        void* m_client_context_start;
        void* m_client_context_stop;
        void* m_client_context_flush;
        
        UINT8 m_out_buf_max_count;
        UINT8 m_out_buf_cur_used_count;
        UINT32 m_out_buf_len;
        StateFlags m_flags;
        CodecType m_codec;
        void* m_base;

        AtiMpeg4Decoder();

        void ReleaseDecoder();

        ResultType ConvertResultCode(INT result_code);

        static BOOLEAN IsValidContext(void* context);

    friend class AtiCodecsLib; // creates/destroys AtiMpeg4Decoder

};

#endif // AtiMpeg4Decoder_hpp

