/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EmzAacDecoder_hpp)
#define Apoxi_EmzAacDecoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioDecoder.hpp>
#include "EmzUtils.hpp"

class EmzAacDecoderThread;

const UINT8 c_emz_codec_max_num_of_aac_dec_inst = 1;

class EmzAacDecoder : public AudioDecoder {

    typedef AudioDecoder Base;

    public:

        virtual ~EmzAacDecoder();

        virtual ResultType GetProperties(Properties& properties);

        virtual ResultType Open();

        virtual void Close();

        virtual ResultType SetConfig(   const UINT8* config_stream,
                                        UINT32& config_len,
                                        const AudioDecoderParameters& params,
                                        AudioStreamInfo& stream_info);

        virtual ResultType GetCapabilities( AudioCodecCapabilities& caps);

        virtual ResultType AllocateOutputBuffers(
                                            UINT8 HUGE** &out_buf_array,
                                            UINT8& out_buf_count,
                                            UINT32& out_buf_len,
                                            DecodingFunctionType& dec_fct);

        virtual ResultType RegisterCallbackFunctions( void* context,
                                                      CbFrameDecoded cb_frame_decoded);

        virtual ResultType DecodeFrame( const UINT8 HUGE* in_buf,
                                        UINT32 in_buf_len,
                                        const UINT8 HUGE* out_buf,
                                        UINT32 out_buf_len);

        virtual ResultType DecodeBuffer( const UINT8 HUGE* in_buf,
                                         UINT32 in_buf_len,
                                         const UINT8 HUGE* out_buf,
                                         UINT32 out_buf_len);

        virtual ResultType SetParameters( const ParameterType* types_array,
                                          const UINT32* values_array,
                                          UINT8 array_count);

        virtual ResultType GetParameters( const ParameterType* types_array,
                                          UINT32* values_array,
                                          UINT8 array_count);
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
            UINT m_stop_requested               :1; 
            UINT m_decode_op_running            :1; 
        };

        class OperationInfo {
            public:
                enum OperationType {
                    DecodeBufferOp,
                    DecodeFrameOp,
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

        static EmzAacDecoder* m_exist_this_ptr_array[c_emz_codec_max_num_of_aac_dec_inst];
        void* m_client_context;
        UINT32 m_max_out_frame_len;
        UINT32 m_out_buf_len;
        UINT8 HUGE** m_out_buf_array;
        UINT8 m_out_buf_array_count;
        StateFlags m_flags;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        CodecType m_codec;
        EmzAacDecoderThread* m_thread;

        EmzAacDecoder();


        ResultType FreeOutputBuffers();

        void ReleaseDecoder();

    friend class EmzCodecsLib; // creates/destroys EmzAacDecoder

    friend class EmzAacDecoderThread;

};

#endif // Apoxi_EmzAacDecoder_hpp

