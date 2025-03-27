/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzH264Decoder_hpp)
#define EmzH264Decoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>
#include "EmzUtils.hpp"

class EmzH264DecoderThread;

const UINT8 c_emz_codec_max_num_of_h264_dec_inst = 3;

class EmzH264Decoder : public VideoDecoder {

    typedef VideoDecoder Base;

    public:

        virtual ~EmzH264Decoder();

        virtual CodecManager::ResultType GetCapabilities(CodecManager::VideoCodecCapabilities& caps);

        virtual CodecManager::ResultType AllocateOutputBuffers( UINT8& out_buf_count,
                                                                UINT32& out_buf_len);
        virtual CodecManager::ResultType GetNumberOfInitialDecodeOperations(UINT8& operations);

        virtual CodecManager::ResultType RegisterCallbackFunctions( void* context,
                                                                    CbFrameDecoded cb_frame_decoded,
                                                                    CbInBufferFree cb_in_buf_free);

        virtual CodecManager::ResultType DecodeFrame(   const UINT8 HUGE* in_buf,
                                                        UINT32 in_buf_len,
                                                        UINT16 flags);

        virtual CodecManager::ResultType DecodePacket(  const UINT8 HUGE* in_buf,
                                                        UINT32 in_buf_len,
                                                        UINT16 flags);

        virtual CodecManager::ResultType ReleaseOutputBuffer(const UINT8 HUGE* out_buf);

        virtual CodecManager::ResultType NotifyOutputBufferReleased(const UINT8 HUGE* out_buf);

        virtual CodecManager::ResultType Flush();

        virtual CodecManager::ResultType Reset();

        virtual CodecManager::ResultType SetParameters( const ParameterType* types_array,
                                                        const UINT32* values_array,
                                                        UINT8 array_count);

        virtual CodecManager::ResultType GetParameters( const ParameterType* types_array,
                                                        UINT32* values_array,
                                                        UINT8 array_count);

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
            UINT m_decode_op_running            :1; 
            UINT m_reset_requested              :1; 
        };

        class OperationInfo {
            public:
                enum OperationType {
                    DecodeFrameOp,
                    DecodePacketOp,
                    SetParametersOp
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

        static EmzH264Decoder* m_exist_this_ptr_array[c_emz_codec_max_num_of_h264_dec_inst];
        void* m_client_context;
        UINT8 HUGE** m_out_buf_array;
        UINT8 m_out_buf_max_count;
        UINT8 m_out_buf_cur_used_count;
        StateFlags m_flags;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        EmzH264DecoderThread* m_thread;
        ParameterType* m_types_arr;
        UINT32* m_values_arr;

        EmzH264Decoder();

        virtual CodecManager::ResultType Start( const UINT8* config_stream,
                                                UINT32& config_len,
                                                const CodecManager::VideoDecoderParameters& params,
                                                CodecManager::VideoStreamInfo& stream_info);

        virtual void Stop();

        void ReleaseDevice();

    friend class EmzCodecsLib; // creates/destroys EmzH264Decoder

    friend class EmzH264DecoderThread;

};

#endif // EmzH264Decoder_hpp

