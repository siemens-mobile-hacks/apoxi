/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ScicosMpeg4VideoEncoder_hpp)
#define ScicosMpeg4VideoEncoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoEncoder.hpp>

const UINT8 c_scicos_codec_if_max_num_of_vid_enc_inst = 1;

class ScicosMpeg4VideoEncoder : public VideoEncoder {

    typedef VideoEncoder Base;

    public:

        virtual ~ScicosMpeg4VideoEncoder();

        virtual CodecManager::ResultType GetCapabilities(CodecManager::VideoCodecCapabilities& caps);

        virtual CodecManager::ResultType AllocateOutputBuffers( UINT8 HUGE** &out_buf_array,
                                                                UINT8& out_buf_count,
                                                                UINT32& out_buf_len);

        virtual CodecManager::ResultType RegisterCallbackFunctions( UINT32 context,
                                                                    CbFrameEncoded cb_frame_encoded);

        virtual CodecManager::ResultType EncodeFrame(   UINT8 HUGE* in_buf,
                                                        UINT32 in_buf_len,
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

        static void CbNotifyFrameEncoded(   UINT32 context,
                                            INT32 result,
                                            UINT8* out_buf,
                                            UINT32 out_buf_len,
                                            UINT32 frame_type);

        CbFrameEncoded m_cb_frame_encoded;

        static ScicosMpeg4VideoEncoder* m_exist_this_ptr_array[c_scicos_codec_if_max_num_of_vid_enc_inst];
        UINT32 m_client_context;
        UINT32 m_out_buf_len;
        UINT8 m_out_buf_array_count;
        UINT8 HUGE** m_out_buf_array;
        UINT32* m_time_stamp_array;
        UINT8* m_config_stream_buf;
        UINT32 m_config_stream_buf_len;
        StateFlags m_flags;

        ScicosMpeg4VideoEncoder();

        virtual CodecManager::ResultType Start(CodecManager::VideoEncoderParameters& params);

        virtual void Stop();

        virtual CodecManager::ResultType ReleaseOutputBuffers();

        CodecManager::ResultType ConvertResultCode(INT32 result_code);

        static BOOLEAN IsValidContext(UINT32 context);

        void ReleaseEncoder();


    friend class ScicosCodecIfLib; // creates/destroys the ScicosMpeg4VideoEncoder

};

#endif // ScicosMpeg4VideoEncoder_hpp


