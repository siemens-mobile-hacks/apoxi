/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzMpeg4EncoderThread_hpp)
#define EmzMpeg4EncoderThread_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoEncoder.hpp>
#include "EmzMpeg4Encoder.hpp"

extern "C"{
#include <EmzCodecs/Mpeg4SpEncoder/exp_emz_MPEG4SP_video_enc.h>
#include <EmzCodecs/Mpeg4SpEncoder/exp_emz_H263_video_enc.h>
}

class EmzMpeg4EncoderThread : public Thread {

    typedef Thread Base;

    public:

        virtual INT ThreadFn();

    private:

        int m_exited;
        Semaphore m_thread_sem;
        Semaphore m_stop_sem;

        EmzMpeg4Encoder* m_device;
        tBaseVideoEncoder* m_base;

        UINT8 HUGE*        m_conf_buf;

        EmzMpeg4EncoderThread();

        virtual ~EmzMpeg4EncoderThread();

        CodecDevice::ResultType Start(EmzMpeg4Encoder* video_enc);

        void Stop();


        CodecDevice::ResultType SetConfig(const CodecDevice::VideoEncoderParameters& params,
                                          UINT32& out_buf_max_len);

        CodecDevice::ResultType GetConfigStream(    UINT8 HUGE*& out_buf,
                                                    UINT32& out_buf_len);

        CodecDevice::ResultType ReleaseConfigStreamBuffer(UINT8 HUGE* buf);

        CodecDevice::ResultType ConvertResultCode(INT32 result_code);

        void EncodeFrameSynchronously(EmzMpeg4Encoder::OperationInfo& op);


        void Reset();

    friend class EmzMpeg4Encoder; // creates/destroys EmzMpeg4EncoderThread

};

#endif // EmzMpeg4EncoderThread_hpp

