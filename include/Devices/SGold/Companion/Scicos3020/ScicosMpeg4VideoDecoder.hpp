/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ScicosMpeg4VideoDecoder_hpp)
#define ScicosMpeg4VideoDecoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>

const UINT8 c_scicos_codec_if_max_num_of_vid_dec_inst = 1;

class ScicosMpeg4VideoDecoder : public VideoDecoder {

    typedef VideoDecoder Base;

    public:

        virtual ~ScicosMpeg4VideoDecoder();

        virtual CodecManager::ResultType GetCapabilities(CodecManager::VideoCodecCapabilities& caps);

        virtual CodecManager::ResultType AllocateOutputBuffers( UINT8& out_buf_count,
                                                                UINT32& out_buf_len);

        virtual CodecManager::ResultType GetNumberOfInitialDecodeOperations(UINT8& operations);

        virtual CodecManager::ResultType RegisterCallbackFunctions( UINT32 context,
                                                                    CbFrameDecoded cb_frame_decoded,
                                                                    CbInBufferFree cb_in_buf_free);

        virtual CodecManager::ResultType DecodeFrame(   const UINT8 HUGE* in_buf,
                                                        UINT32 in_buf_len,
                                                        UINT16 flags);

        virtual CodecManager::ResultType DecodePacket(  const UINT8 HUGE* in_buf,
                                                        UINT32 in_buf_len,
                                                        UINT16 flags);

        virtual CodecManager::ResultType SkipFrames(const UINT8 HUGE** out_buf_array,
                                                    UINT8 out_buf_count = 1);

        virtual CodecManager::ResultType ReleaseOutputBuffer(const UINT8 HUGE* out_buf);

        virtual CodecManager::ResultType Flush();

        virtual CodecManager::ResultType SetParameters( const ParameterType* types_array,
                                                        const UINT32* values_array,
                                                        UINT8 array_count);

        virtual CodecManager::ResultType GetParameters( const ParameterType* types_array,
                                                        UINT32* values_array,
                                                        UINT8 array_count);

        CodecManager::ResultType SetOutputFrame(const UINT8 HUGE* src_buf,
                                                UINT32 src_buf_len,
                                                UINT8 HUGE*& dec_out_buf);

        CodecManager::ResultType GetOutputFrame(const UINT8 HUGE* dec_out_buf,
                                                UINT8 HUGE* dest_buf,
                                                UINT32& dest_buf_len);

    private:

        enum StateType {
            NotInUseState = 0,
            StartingState,
            StartedState,
            StoppingState
        };

        struct StateFlags {
            UINT state                      :2; 
            UINT out_buffers_allocated      :1; 
            UINT callback_funcs_registered  :1; 
            UINT stop_requested             :1; 
        };

        static void CbNotifyFrameDecoded(   UINT32 context,
                                            INT32 result,
                                            UINT32 time_stamp,
                                            UINT8* out_buf);

        static void CbNotifyInBufferFree(   UINT32 context,
                                            INT32 result,
                                            UINT8* in_buf);

        CbFrameDecoded m_cb_frame_decoded;
        CbInBufferFree m_cb_in_buf_free;

        static ScicosMpeg4VideoDecoder* m_exist_this_ptr_array[c_scicos_codec_if_max_num_of_vid_dec_inst];
        UINT32 m_client_context;
        UINT32 m_out_buf_len;
        UINT8* m_out_buf_pool_handle;
        UINT8 HUGE** m_out_buf_array;
        UINT8 m_out_buf_array_max_count;
        UINT8 m_out_buf_array_curr_count;
        StateFlags m_flags;

        ScicosMpeg4VideoDecoder();

        virtual CodecManager::ResultType Start( const UINT8* config_stream,
                                                UINT32& config_len,
                                                const CodecManager::VideoDecoderParameters& params,
                                                CodecManager::VideoStreamInfo& stream_info);

        virtual void Stop();

        CodecManager::ResultType ConvertResultCode(INT32 result_code);

        static BOOLEAN IsValidContext(UINT32 context);

        void ReleaseDecoder();

    friend class ScicosCodecIfLib; // creates/destroys ScicosMpeg4VideoDecoder

};

#endif // ScicosMpeg4VideoDecoder_hpp


