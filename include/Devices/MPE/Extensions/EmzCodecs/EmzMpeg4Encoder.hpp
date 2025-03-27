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

const UINT8 c_emz_codecs_max_num_of_mpeg4_enc_inst = 2;

class EmzMpeg4EncoderThread;

class EmzMpeg4Encoder : public VideoEncoder {

    typedef VideoEncoder Base;

    public:

        virtual ~EmzMpeg4Encoder();

        virtual CodecManager::ResultType GetCapabilities(CodecManager::VideoCodecCapabilities& caps);

        virtual CodecManager::ResultType AllocateOutputBuffers( UINT8 HUGE** &out_buf_array,
                                                                UINT8& out_buf_count,
                                                                UINT32& out_buf_len);

        virtual CodecManager::ResultType RegisterCallbackFunctions( void* context,
                                                                    CbFrameEncoded cb_frame_encoded);

        virtual CodecManager::ResultType EncodeFrame(   UINT8 HUGE* in_buf,
                                                        UINT32 time_stamp,
                                                        UINT32 key_frame_ind,
                                                        UINT8 HUGE* out_buf);

        virtual CodecManager::ResultType SetParameters( const ParameterType* types_array,
                                                        const UINT32* values_array,
                                                        UINT8 array_count);

        virtual CodecManager::ResultType GetParameters( const ParameterType* types_array,
                                                        UINT32* values_array,
                                                        UINT8 array_count);

        virtual CodecManager::ResultType GetConfigStream(   UINT8 HUGE* out_buf,
                                                            UINT32& out_buf_len);

        virtual CodecManager::ResultType AssignCaptureBufferPool(
                                                UINT32 buf_pool_handle);

        virtual CodecManager::ResultType Flush();

        virtual CodecManager::ResultType Reset();

    private:

        enum StateType {
            IdleState = 0,
            StartingState,
            StartedState,
            StoppingState
        };

        struct StateFlags {
            UINT m_state                        :2; 
            UINT m_out_buffers_allocated        :1; 
            UINT m_callback_funcs_registered    :1; 
            UINT m_stop_requested               :1; 
            UINT m_encode_op_running            :1; 
            UINT m_reset_requested              :1; 
        };

        class OperationInfo {

            public:
                enum OperationType {
                    EncodeFrameOp,
                    SetParametersOp
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

        CbFrameEncoded m_cb_frame_encoded;

        static EmzMpeg4Encoder* m_exist_this_ptr_array[c_emz_codecs_max_num_of_mpeg4_enc_inst];
        void* m_client_context;
        UINT32 m_in_buf_len;
        UINT32 m_out_buf_len;
        UINT8 m_out_buf_array_count;
        UINT8 HUGE** m_out_buf_array;
        StateFlags m_flags;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        EmzMpeg4EncoderThread* m_thread;
        UINT32 m_capture_buffer_pool;
        ParameterType* m_types_arr;
        UINT32* m_values_arr;

        EmzMpeg4Encoder();

        virtual CodecManager::ResultType Start(
                            const CodecManager::VideoEncoderParameters& params,
                            CodecManager::VideoEncoderInfo& enc_info);

        virtual void Stop();

        virtual CodecManager::ResultType FreeOutputBuffers();

        void ReleaseDevice();

    friend class EmzCodecsLib; // creates/destroys the EmzMpeg4Encoder

    friend class EmzMpeg4EncoderThread;

};

#endif // EmzMpeg4Encoder_hpp

