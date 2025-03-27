/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmzSbcEncoderThread_hpp)
#define EmzSbcEncoderThread_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>
#include <AddOns/CodecManager/CodecManager.hpp>
#include <AddOns/CodecManager/AudioEncoder.hpp>
#include "EmzSbcEncoder.hpp"

class EmzSbcEncoderThread : public Thread {

    typedef Thread Base;

    public:

        virtual INT ThreadFn();

    private:

        int m_exited;
        Semaphore m_thread_sem;
        Semaphore m_stop_sem;
        EmzSbcEncoder* m_device;
        void* m_base;
        void* m_base_config;
        void* m_stack;

        EmzSbcEncoderThread();

        virtual ~EmzSbcEncoderThread();

        CodecManager::ResultType Start(
                            const CodecManager::AudioEncoderParameters& params,
                            EmzSbcEncoder* parent);

         void Stop();

        CodecManager::ResultType ConvertResultCode(INT32 result_code);

        void EncodeBufferSynchronously(EmzSbcEncoder::OperationInfo& op);

        void Reset();

        CodecManager::ResultType SetParameters(
                                const AudioEncoder::ParameterType* types_array,
                                const UINT32* values_array,
                                UINT8 array_count);

    friend class EmzSbcEncoder; // creates/destroys EmzSbcEncoderThread

};

#endif // EmzSbcEncoderThread_hpp

