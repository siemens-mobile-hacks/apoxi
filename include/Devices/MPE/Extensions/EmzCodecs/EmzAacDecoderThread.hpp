/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzAacDecoderThread_hpp)
#define EmzAacDecoderThread_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioDecoder.hpp>
#include "EmzAacDecoder.hpp"

#ifndef APOXI_EMZ_AAC_PLUS_V2_DEC_ENABLED
#define APOXI_EMZ_AAC_PLUS_V2_DEC_ENABLED
#endif //APOXI_EMZ_AAC_PLUS_V2_DEC_ENABLED

class EmzAacDecoderThread : public Thread {

    typedef Thread Base;

    public:

        virtual INT ThreadFn();

    private:

        int m_exited;
        Semaphore m_thread_sem;
        Semaphore m_stop_sem;
        EmzAacDecoder* m_device;
        void* m_base;
        void* m_frame_info;
        void* m_stack;

        EmzAacDecoderThread();

        virtual ~EmzAacDecoderThread();

        CodecManager::ResultType Start( const UINT8* config_stream,
                                        UINT32& config_len,
                                        const CodecManager::AudioDecoderParameters& params,
                                        CodecManager::AudioStreamInfo& stream_info,
                                        EmzAacDecoder* parent);

        void Stop();

        CodecManager::ResultType ConvertResultCode(INT32 result_code);

        void DecodeBufferSynchronously(EmzAacDecoder::OperationInfo& op);

        void Reset();

    friend class EmzAacDecoder; // creates/destroys EmzAacDecoderThread

};

#endif // EmzAacDecoderThread_hpp

