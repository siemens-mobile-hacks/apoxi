/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_EmzSbcEncoder_hpp)
#define Apoxi_EmzSbcEncoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioEncoder.hpp>
#include "EmzUtils.hpp"

class EmzSbcEncoderThread;

const UINT8 c_emz_codec_max_num_of_sbc_enc_inst = 2;

class EmzSbcEncoder : public AudioEncoder {

    typedef AudioEncoder Base;

    public:

        virtual ~EmzSbcEncoder();

        virtual CodecManager::ResultType GetCapabilities(
                                CodecManager::AudioCodecCapabilities& caps);

        virtual CodecManager::ResultType AllocateOutputBuffers(
                                            UINT8 HUGE** &out_buf_array,
                                            UINT8& out_buf_count,
                                            UINT32& out_buf_len,
                                            EncodingFunctionType& dec_fct);

        virtual CodecManager::ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbFrameEncoded cb_frame_encoded);

        virtual CodecManager::ResultType EncodeFrame(
                                                    const UINT8 HUGE* in_buf,
                                                    UINT32 in_buf_len,
                                                    const UINT8 HUGE* out_buf,
                                                    UINT32 out_buf_len);
        virtual CodecManager::ResultType EncodeBuffer(
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
            UINT m_encode_op_running            :1; 
            UINT m_reset_requested              :1; 
        };

        class OperationInfo {
            public:
                enum OperationType {
                    EncodeBufferOp,
                    EncodeFrameOp,
                    SetParametersOp
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

        CbFrameEncoded m_cb_frame_encoded;

        static EmzSbcEncoder* m_exist_this_ptr_array[c_emz_codec_max_num_of_sbc_enc_inst];
        void* m_client_context;
        UINT32 m_in_frame_len;
        UINT32 m_max_out_frame_len;
        UINT32 m_out_buf_len;
        UINT8 HUGE** m_out_buf_array;
        UINT8 m_out_buf_array_count;
        StateFlags m_flags;
        EmzUtils::Queue<OperationInfo> m_ops_queue;
        EmzSbcEncoderThread* m_thread;
        ParameterType* m_types_arr;
        UINT32* m_values_arr;

        EmzSbcEncoder();

        virtual CodecManager::ResultType Start(
                            const CodecManager::AudioEncoderParameters& params);

        virtual void Stop();

        CodecManager::ResultType FreeOutputBuffers();

        void ReleaseDevice();

    friend class EmzCodecsLib; // creates/destroys EmzSbcEncoder

    friend class EmzSbcEncoderThread;

};

#endif // Apoxi_EmzSbcEncoder_hpp

