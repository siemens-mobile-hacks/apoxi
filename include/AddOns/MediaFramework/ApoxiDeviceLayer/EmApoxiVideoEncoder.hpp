/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiVideoEncoderhpp)
#define EmApoxiVideoEncoderhpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
class VideoEncoder;

class EmApoxiVideoEncoder {
    public:

        enum ParameterType {
            BitRate,
            MaxOutputBufferLength,
            InputFrameLength,
            FrameRateNumerator,
            FrameRateDenominator,
            QualityLevel,
            ConfigStreamLength,
            EndOfParameterType
        };

        enum FrameCodingType {
            IFrame, 
            PFrame, 
            EndOfFrameCodingType
        };

        typedef void (*CbFrameEncoded)( EmApoxiCodecManager::ResultType result,
                                        void* context,
                                        EmApoxiUINT8 HUGE* out_buf,
                                        EmApoxiUINT32 out_buf_len,
                                        FrameCodingType frame_type);

        EmApoxiCodecManager::ResultType AllocateOutputBuffers(
                                                    EmApoxiUINT8 HUGE** &out_buf_array,
                                                    EmApoxiUINT8& out_buf_count,
                                                    EmApoxiUINT32& out_buf_len) ;

        EmApoxiCodecManager::ResultType RegisterCallbackFunctions(
                                        void* context,
                                        CbFrameEncoded cb_frame_encoded);

        EmApoxiCodecManager::ResultType EncodeFrame(EmApoxiUINT8 HUGE* in_buf,
                                                    EmApoxiUINT32 time_stamp,
                                                    EmApoxiUINT32 key_frame_ind,
                                                    EmApoxiUINT8 HUGE* out_buf);

        EmApoxiCodecManager::ResultType SetParameters(  const ParameterType* types_array,
                                                        const EmApoxiUINT32* values_array,
                                                        EmApoxiUINT8 array_count);

        EmApoxiCodecManager::ResultType GetParameters(  const ParameterType* types_array,
                                                        EmApoxiUINT32* values_array,
                                                        EmApoxiUINT8 array_count);

        EmApoxiCodecManager::ResultType GetConfigStream(EmApoxiUINT8 HUGE* out_buf,
                                                            EmApoxiUINT32& out_buf_len);

        EmApoxiCodecManager::ResultType AssignCaptureBufferPool(
                                                EmApoxiUINT32 buf_pool_handle);

        EmApoxiCodecManager::ResultType StartVideoEncoder(const EmApoxiCodecManager::VideoEncoderParameters& params,
                                        EmApoxiCodecManager::VideoEncoderInfo& enc_info);
        void Stop();
        
        EmApoxiVideoEncoder();

        ~EmApoxiVideoEncoder();

    private:
        EmApoxiVideoEncoder(const EmApoxiVideoEncoder& encoder) {}

        EmApoxiVideoEncoder& operator=(const EmApoxiVideoEncoder& encoder) { }

        VideoEncoder    *m_VideoEncoder;

        CbFrameEncoded m_EncodeCbFxn;

        void *m_Context;

        friend void sEmApoxiVideoEncoderFrameEncodedCb(EmApoxiINT32 result,
                                                    void* context,
                                                    void *out_buf,
                                                    EmApoxiUINT32 out_buf_len,
                                                    EmApoxiINT32 frame_coding_type);


};

#endif
#endif // Apoxi_CodecManager_hpp

