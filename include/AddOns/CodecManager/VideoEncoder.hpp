/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_VideoEncoder_hpp)
#define Apoxi_VideoEncoder_hpp

#include <Kernel/Types.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/CodecDevice.hpp>

class VideoEncoder : public CodecDevice {
    public:

        enum FrameCodingType {
            IFrame, 
            PFrame, 
            EndOfFrameCodingType
        };

        struct VideoEncoderDynParameters {
            UINT16 m_frame_rate_numerator;
            UINT16 m_frame_rate_denominator;
            UINT32 m_bit_rate;
        };

        typedef void (*CbVideoFrameEncoded)(    ResultType result,
                                                void* context,
                                                UINT8 HUGE* out_buf,
                                                UINT32 out_buf_len_used,
                                                UINT32 time_stamp,                                              
                                                FrameCodingType vop_coding_type);

        virtual ResultType Open() = 0;

        virtual ResultType Close() = 0;

        virtual ResultType SetConfig(   const VideoEncoderParameters& params,
                                        UINT32& out_buf_max_len) = 0;

        virtual ResultType SetDynamicConfig(
                                        VideoEncoderDynParameters &params) = 0;

        virtual ResultType GetCapabilities(VideoCodecCapabilities& caps) = 0;

        virtual ResultType AllocateOutputBuffers(   UINT8& out_buf_count,
                                                    UINT32& out_buf_len) = 0;

        virtual ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbVideoFrameEncoded cb_video_frame_encoded) = 0;

        virtual ResultType Start() = 0;

        virtual ResultType Stop(
                                            CbResult cb_video_encoder_stopped,
                                            void* context) = 0;
                                            
        virtual ResultType EncodeFrame( UINT8 HUGE* in_buf,
                                        UINT32 time_stamp,
                                        UINT32 key_frame_ind) = 0;

        virtual ResultType ReleaseOutputBuffer(UINT8 HUGE* out_buf) = 0;

        virtual ResultType GetConfigStream( UINT8 HUGE*& out_buf,
                                            UINT32& out_buf_len) = 0;

        virtual ResultType ReleaseConfigStreamBuffer(UINT8 HUGE* buf) = 0;

        virtual ResultType FlushBuffers(    CbResult cb_video_encoder_flushed,
                                            void* context) = 0;

        virtual ResultType InsertKeyFrame() = 0;

    protected:

    private:

    friend class CodecManager;
};

#endif // Apoxi_VideoEncoder_hpp

