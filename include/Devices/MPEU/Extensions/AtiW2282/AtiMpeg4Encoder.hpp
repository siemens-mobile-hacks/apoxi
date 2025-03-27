/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AtiMpeg4Encoder_hpp)
#define AtiMpeg4Encoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoEncoder.hpp>

const UINT8 c_ati_codecs_max_num_of_mpeg4_enc_inst = 1;

class AtiMpeg4Encoder : public VideoEncoder {

    typedef VideoEncoder Base;

    public:

        virtual ~AtiMpeg4Encoder();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType GetCapabilities(VideoCodecCapabilities& caps);

        virtual ResultType Open();

        virtual ResultType Close();

        virtual ResultType SetConfig(
                            const VideoEncoderParameters& params,
                            UINT32& out_buf_max_len);

        virtual ResultType SetDynamicConfig(VideoEncoderDynParameters &params);

        virtual ResultType AllocateOutputBuffers(
                                                UINT8& out_buf_count,
                                                UINT32& out_buf_len);

        virtual ResultType RegisterCallbackFunctions(
                                            void* context,
                                            CbVideoFrameEncoded cb_video_frame_encoded);
                                            
        virtual ResultType Start();
        
        virtual ResultType Stop(
                                CbResult cb_video_encoder_stopped,
                                void* context);
                                            
        virtual ResultType EncodeFrame( UINT8 HUGE* in_buf,
                                        UINT32 time_stamp,
                                        UINT32 key_frame_ind);

        virtual ResultType ReleaseOutputBuffer(UINT8 HUGE* out_buf);

        virtual ResultType GetConfigStream(
                                            UINT8 HUGE*& out_buf,
                                            UINT32& out_buf_len);

        virtual ResultType ReleaseConfigStreamBuffer(UINT8 HUGE* buf);

        virtual ResultType FlushBuffers(
                                            CbResult cb_video_encoder_flushed,
                                            void* context);

        virtual ResultType InsertKeyFrame();

    protected:

        virtual ResultType SetCodec(CodecType codec);

    private:

        enum StateType {
            IdleState = 0, 
            OpeningState,
            OpenState,
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

        static void CbNotifyBuffersFlushed(INT result, void* context);

        static void CbNotifyFrameEncoded(   INT result,
                                            void* context,
                                            UINT8* out_buf,
                                            UINT32 out_buf_len_used,
                                            UINT32 time_stamp,
                                            INT vop_coding_type );

        static void CbNotifyStopped(    INT result,
                                        void* context);

        static void CbGetBuffer(    void* context,
                                    UINT8** out_buf,
                                    UINT32 out_buf_len );

        CbVideoFrameEncoded m_cb_frame_encoded;
        CbResult m_cb_buffers_flushed;
        CbResult m_cb_stopped;

        static AtiMpeg4Encoder* m_exist_this_ptr_array[c_ati_codecs_max_num_of_mpeg4_enc_inst];
        void* m_client_context_frame_encoded;
        void* m_client_context_flushed;
        void* m_client_context_stopped;     
        UINT32 m_in_buf_len;
        UINT32 m_venc_out_buf_max_len;
        UINT8 m_out_buf_array_count;
        UINT32 m_out_buf_pool;
        StateFlags m_flags;
        CodecType m_codec;
        void* m_base;

        AtiMpeg4Encoder();

        void ResetEncoder();

        ResultType ConvertResultCode(INT result_code);

        static BOOLEAN IsValidContext(void* context);

    friend class AtiCodecsLib; // creates/destroys the AtiMpeg4Encoder

};

#endif // AtiMpeg4Encoder_hpp

