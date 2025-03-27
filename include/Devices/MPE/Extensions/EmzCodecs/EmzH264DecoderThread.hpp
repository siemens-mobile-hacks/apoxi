/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzH264DecoderThread_hpp)
#define EmzH264DecoderThread_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/VideoDecoder.hpp>
#include "EmzH264Decoder.hpp"

extern "C"{
#include <EmzCodecs/H264Decoder/exp_h264_smp_decoder.h>
}

class EmzH264DecoderThread : public Thread {

    typedef Thread Base;

    public:

        virtual INT ThreadFn();

    private:

        int m_exited;
        Semaphore m_thread_sem;
        Semaphore m_stop_sem;
        EmzH264Decoder* m_device;
        tBaseVideoDecoder* m_base;
        void* m_stack;

        EmzH264DecoderThread();

        virtual ~EmzH264DecoderThread();

        CodecManager::ResultType Start( const UINT8* config_stream,
                                        UINT32& config_len,
                                        const CodecManager::VideoDecoderParameters& params,
                                        CodecManager::VideoStreamInfo& stream_info,
                                        EmzH264Decoder* parent);

        void Stop();

        CodecManager::ResultType SetParameters( const VideoDecoder::ParameterType* types_array,
                                                const UINT32* values_array,
                                                UINT8 array_count);

        CodecManager::ResultType GetParameters( const VideoDecoder::ParameterType* types_array,
                                                UINT32* values_array,
                                                UINT8 array_count);

        CodecManager::ResultType ConvertResultCode(INT32 result_code);


        void DecodeFrameSynchronously(EmzH264Decoder::OperationInfo& op);

        void DecodePacketSynchronously(EmzH264Decoder::OperationInfo& op);

        void Reset();

    friend class EmzH264Decoder; // creates/destroys EmzH264DecoderThread

};

#endif // EmzH264DecoderThread_hpp

