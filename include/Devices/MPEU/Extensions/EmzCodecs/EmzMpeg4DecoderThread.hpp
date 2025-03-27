/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzMpeg4DecoderThread_hpp)
#define EmzMpeg4DecoderThread_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>
#include "EmzMpeg4Decoder.hpp"

extern "C"{
#include <EmzCodecs/Mpeg4SpDecoder/exp_MP4SP_VD.h>
#include <EmzCodecs/Mpeg4SpDecoder/exp_H263_VD.h>
}

class EmzMpeg4DecoderThread : public Thread {

    typedef Thread Base;

    public:

        virtual INT ThreadFn();

    private:

        int m_exited;
        Semaphore m_thread_sem;
        Semaphore m_stop_sem;

        EmzMpeg4Decoder* m_device;
        tBaseVideoDecoder* m_base;

        EmzMpeg4DecoderThread();

        virtual ~EmzMpeg4DecoderThread();

        virtual VideoDecoder::ResultType Start( EmzMpeg4Decoder* parent);

        virtual void Stop();

        virtual VideoDecoder::ResultType SetConfig(
                            const UINT8* config_stream,
                            UINT32& config_len,
                            const VideoDecoder::VideoDecoderParameters& params,
                            VideoDecoder::VideoStreamInfo& stream_info);

        VideoDecoder::ResultType ConvertResultCode(INT32 result_code);


        void DecodeFrameSynchronously(EmzMpeg4Decoder::OperationInfo& op);

        void DecodePacketSynchronously(EmzMpeg4Decoder::OperationInfo& op);

    friend class EmzMpeg4Decoder; // creates/destroys EmzMpeg4DecoderThread

};

#endif // EmzMpeg4DecoderThread_hpp

