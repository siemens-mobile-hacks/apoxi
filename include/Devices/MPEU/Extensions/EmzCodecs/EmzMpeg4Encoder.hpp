/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzMpeg4Encoder_hpp)
#define EmzMpeg4Encoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoEncoder.hpp>
#include "EmzUtils.hpp"

const UINT8 c_emz_codecs_max_num_of_mpeg4_enc_inst = 1;

class EmzMpeg4EncoderThread;

class EmzMpeg4Encoder : public VideoEncoder {

    typedef VideoEncoder Base;

    public:

        virtual ~EmzMpeg4Encoder();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType GetCapabilities(VideoCodecCapabilities& caps);

        virtual ResultType Open();

        virtual ResultType Close();

        virtual ResultType Start();

        virtual ResultType Stop(CbResult cb_video_decoder_stopped,
                                void* context);

        virtual ResultType SetConfig( const VideoEncoderParameters& params,
                                      UINT32& out_buf_max_len);

        virtual ResultType SetDynamicConfig( VideoEncoderDynParameters &params);

        virtual ResultType AllocateOutputBuffers( UINT8& out_buf_count,
                                                  UINT32& out_buf_len);

        virtual ResultType RegisterCallbackFunctions( void* context,
                                                      CbVideoFrameEncoded cb_frame_encoded);

        virtual ResultType EncodeFrame( UINT8 HUGE* in_buf,
                                        UINT32 time_stamp,
                                        UINT32 key_frame_ind);

        virtual ResultType ReleaseOutputBuffer(UINT8 HUGE* out_buf);

        virtual ResultType GetConfigStream( UINT8 HUGE*& out_buf,
                                            UINT32& out_buf_len);

        virtual ResultType ReleaseConfigStreamBuffer(UINT8 HUGE* buf);

        virtual ResultType FlushBuffers(CbResult cb_video_encoder_flushed,
                                        void* context);
        
        virtual ResultType SetCodec(CodecType codec);

        virtual ResultType InsertKeyFrame();

    private:

        enum StateType {
            IdleState = 0,
            OpeningState,
            OpenState,
            ClosingState
        };

        struct StateFlags {
            UINT m_state                        :2; 
            UINT m_out_buffers_allocated        :1; 
            UINT m_callback_funcs_registered    :1; 
            UINT m_close_requested              :1; 
            UINT m_stop_requested               :1; 
            UINT m_set_config_called            :1; 
            UINT m_encode_op_running            :1; 
            UINT m_flush_requested              :1; 
        };

        class OperationInfo {

            public:
                enum OperationType {
                    EncodeFrameOp
                };

                OperationType m_op; 
                UINT8 HUGE* m_in_buf; 
                UINT32 m_time_stamp; 
                UINT32 m_key_frame_ind; 
                UINT8 HUGE* m_out_buf; 

                OperationInfo();

                OperationInfo(  OperationType op,
                                        UINT8 HUGE* in_buf,
                                        UINT32 time_stamp,
                                        UINT32 key_frame_ind,
                                        UINT8 HUGE* out_buf);

                OperationInfo(const OperationInfo& op_info);

                OperationInfo& operator=(const OperationInfo& op_info);

                virtual ~OperationInfo();
        }; // OperationInfo

        CbVideoFrameEncoded m_cb_frame_encoded;

        static EmzMpeg4Encoder* m_exist_this_ptr_array[c_emz_codecs_max_num_of_mpeg4_enc_inst];
        void* m_client_context;
        UINT32 m_in_buf_len;
        UINT32 m_out_buf_len;
        UINT8 m_out_buf_array_count;
        UINT8 HUGE** m_out_buf_array;
        UINT32 m_out_buf_pool;
        StateFlags m_flags;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        CodecType m_codec;
        EmzMpeg4EncoderThread* m_thread;
        CbResult m_cb_stop;
        void* m_context_stop;
        CbResult m_cb_flush;
        void* m_context_flush;

        EmzMpeg4Encoder();

        void ReleaseEncoder();

    friend class EmzCodecsLib; // creates/destroys the EmzMpeg4Encoder

    friend class EmzMpeg4EncoderThread;

};

#endif // EmzMpeg4Encoder_hpp

