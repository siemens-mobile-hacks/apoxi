/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EmzMp3Decoder_hpp)
#define Apoxi_EmzMp3Decoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioDecoder.hpp>
#include "EmzUtils.hpp"

class EmzMp3DecoderThread;

const UINT8 c_emz_codec_max_num_of_mp3_dec_inst = 2;

class EmzMp3Decoder : public AudioDecoder {

    typedef AudioDecoder Base;

    public:

        virtual ~EmzMp3Decoder();

        virtual CodecManager::ResultType GetCapabilities(
                                CodecManager::AudioCodecCapabilities& caps);

        virtual CodecManager::ResultType GetAudioStreamInfo(
                            const UINT8* config_stream,
                            UINT32& config_len,
                            const CodecManager::AudioDecoderParameters& params,
                            CodecManager::AudioStreamInfo& stream_info);

        virtual CodecManager::ResultType AllocateOutputBuffers(
                                            UINT8 HUGE** &out_buf_array,
                                            UINT8& out_buf_count,
                                            UINT32& out_buf_len,
                                            DecodingFunctionType& dec_fct);

        virtual CodecManager::ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbFrameDecoded cb_frame_decoded);

        virtual CodecManager::ResultType DecodeFrame(
                                                    const UINT8 HUGE* in_buf,
                                                    UINT32 in_buf_len,
                                                    const UINT8 HUGE* out_buf,
                                                    UINT32 out_buf_len);
        virtual CodecManager::ResultType DecodeBuffer(
                                                    const UINT8 HUGE* in_buf,
                                                    UINT32 in_buf_len,
                                                    const UINT8 HUGE* out_buf,
                                                    UINT32 out_buf_len);

        virtual CodecManager::ResultType SetParameters(
                                            const ParameterType* types_array,
                                            const UINT32* values_array,
                                            UINT8 array_count);

        virtual CodecManager::ResultType GetParameters(
                                            const ParameterType* types_array,
                                            UINT32* values_array,
                                            UINT8 array_count);

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
            UINT m_decode_op_running            :1; 
            UINT m_reset_requested              :1; 
        };

        class OperationInfo {
            public:
                enum OperationType {
                    DecodeBufferOp,
                    DecodeFrameOp
                };

                OperationType m_op; 
                UINT8 HUGE* m_in_buf; 
                UINT32 m_in_buf_len; 
                UINT8 HUGE* m_out_buf; 
                UINT32 m_out_buf_len;  

                OperationInfo();

                OperationInfo(  OperationType op,
                                        UINT8* in_buf,
                                        UINT32 in_buf_len,
                                        UINT8 HUGE* out_buf,
                                        UINT32 out_buf_len);

                OperationInfo(const OperationInfo& op_info);

                OperationInfo& operator=(const OperationInfo& op_info);

                virtual ~OperationInfo();
        }; // OperationInfo

        CbFrameDecoded m_cb_frame_decoded;

        static EmzMp3Decoder* m_exist_this_ptr_array[c_emz_codec_max_num_of_mp3_dec_inst];
        void* m_client_context;
        UINT32 m_max_out_frame_len;
        UINT32 m_out_buf_len;
        UINT8 HUGE** m_out_buf_array;
        UINT8 m_out_buf_array_count;
        StateFlags m_flags;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        EmzMp3DecoderThread* m_thread;

        EmzMp3Decoder();

        virtual CodecManager::ResultType Start(
                            const UINT8* config_stream,
                            UINT32& config_len,
                            const CodecManager::AudioDecoderParameters& params,
                            CodecManager::AudioStreamInfo& stream_info);

        virtual void Stop();

        virtual CodecManager::ResultType FreeOutputBuffers();

        void ReleaseDevice();

    friend class EmzCodecsLib; // creates/destroys EmzMp3Decoder

    friend class EmzMp3DecoderThread;

};

#endif // Apoxi_EmzMp3Decoder_hpp

