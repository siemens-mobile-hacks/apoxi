/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzMpeg4Decoder_hpp)
#define EmzMpeg4Decoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>
#include "EmzUtils.hpp"

class EmzMpeg4DecoderThread;

const UINT8 c_emz_codec_max_num_of_mpeg4_dec_inst = 1;

class EmzMpeg4Decoder : public VideoDecoder {

    typedef VideoDecoder Base;

    public:

        virtual ~EmzMpeg4Decoder();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType Open(VideoDecoderInfo& dec_info);

        virtual ResultType Close();

        virtual ResultType Start(CbResultAndTimeInfo cb_video_decoder_started,
                                void* context);

        virtual ResultType Stop(CbResult cb_video_decoder_stopped,
                                void* context);

        virtual ResultType SetConfig(
                            const UINT8* config_stream,
                            UINT32& config_len,
                            const VideoDecoderParameters& params,
                            VideoStreamInfo& stream_info);


        virtual ResultType GetCapabilities(
                                VideoCodecCapabilities& caps);

        virtual ResultType AllocateOutputBuffers(   UINT8& out_buf_count,
                                                        UINT32& out_buf_len);


        virtual ResultType RegisterCallbackFunctions(   void* context,
                                                        CbFrameDecoded cb_frame_decoded,
                                                        CbInBufferFree cb_in_buf_free);

        virtual ResultType SetAssociatedAudioCh(UINT32 audio_channel);

        virtual ResultType SetVideoClockTime(UINT32 time_ms);

        virtual ResultType GetCurrentVideoClockTime(UINT32& time_ms);


        virtual ResultType DecodeFrame( const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        UINT16 flags,
                                        UINT32 time_stamp);

        virtual ResultType DecodePacket(const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        UINT16 flags);

        virtual ResultType ReleaseOutputBuffer( const UINT8 HUGE* out_buf);


        virtual ResultType FlushBuffers( CbResult cb_video_decoder_flushed,
                                         void* context);


    protected:

        virtual ResultType SetCodec(CodecType codec);


    private:

        enum StateType {
            IdleState = 0, 
            OpeningState,
            OpenState,
            ClosingState
        };

        struct StateFlags {
            UINT m_state                        :2; 
            UINT m_set_config_called            :1; 
            UINT m_out_buffers_allocated        :1; 
            UINT m_callback_funcs_registered    :1; 
            UINT m_start_requested              :1; 
            UINT m_stop_requested               :1; 
            UINT m_close_requested              :1; 
            UINT m_decode_op_running            :1; 
            UINT m_flush_requested              :1; 
        };

        class OperationInfo {
            public:
                enum OperationType {
                    DecodeFrameOp,
                    DecodePacketOp
                };

                OperationType m_op; 
                UINT8* m_in_buf; 
                UINT32 m_in_buf_len; 
                UINT16 m_flags; 

                OperationInfo();

                OperationInfo(  OperationType op,
                                        UINT8* in_buf,
                                        UINT32 in_buf_len,
                                        UINT16 flags);

                OperationInfo(const OperationInfo& op_info);

                OperationInfo& operator=(const OperationInfo& op_info);

                virtual ~OperationInfo();
        }; // OperationInfo

        CbFrameDecoded m_cb_frame_decoded;
        CbInBufferFree m_cb_in_buf_free;

        static EmzMpeg4Decoder* m_exist_this_ptr_array[c_emz_codec_max_num_of_mpeg4_dec_inst];
        void* m_client_context;
        UINT8 HUGE** m_out_buf_array;
        UINT8 m_out_buf_max_count;
        UINT8 m_out_buf_cur_used_count;
        StateFlags m_flags;
        CodecType m_codec;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        EmzMpeg4DecoderThread* m_thread;
        CbResultAndTimeInfo m_cb_start;
        CbResult m_cb_stop;
        void* m_context_start;
        void* m_context_stop;
        CbResult m_cb_flush;
        void* m_context_flush;

        EmzMpeg4Decoder();

        void ReleaseDecoder();

    friend class EmzCodecsLib; // creates/destroys EmzMpeg4Decoder

    friend class EmzMpeg4DecoderThread;

};

#endif // EmzMpeg4Decoder_hpp

