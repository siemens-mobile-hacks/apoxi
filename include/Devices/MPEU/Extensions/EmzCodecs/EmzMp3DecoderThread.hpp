/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzMp3DecoderThread_hpp)
#define EmzMp3DecoderThread_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioDecoder.hpp>
#include "EmzMp3Decoder.hpp"

class EmzMp3DecoderThread : public Thread {

    typedef Thread Base;

    public:

        virtual INT ThreadFn();

    private:

        int m_exited;
        Semaphore m_thread_sem;
        Semaphore m_stop_sem;

        EmzMp3Decoder* m_device;
        void* m_base;

        EmzMp3DecoderThread();

        virtual ~EmzMp3DecoderThread();

        virtual CodecDevice::ResultType Start(  EmzMp3Decoder* parent);

        virtual void Stop();

        CodecDevice::ResultType ConvertResultCode(INT32 result_code);

        void DecodeBufferSynchronously(EmzMp3Decoder::OperationInfo& op);

        CodecDevice::ResultType SetConfig(  const UINT8* config_stream,
                                            UINT32& config_len,
                                            const CodecDevice::AudioDecoderParameters& params,
                                            CodecDevice::AudioStreamInfo& stream_info);

    friend class EmzMp3Decoder; // creates/destroys EmzMp3DecoderThread

};

#endif // EmzMp3DecoderThread_hpp

