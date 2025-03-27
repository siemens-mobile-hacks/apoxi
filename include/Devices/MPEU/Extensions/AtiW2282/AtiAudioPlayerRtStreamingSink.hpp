/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AtiAudioPlayerRtStreamingSink_hpp)
#define Apoxi_AtiAudioPlayerRtStreamingSink_hpp

#include <Audio/RtStreaming/RtStreamingConn.hpp>
#include <Audio/RtStreaming/RtStreamingSource.hpp>
#include <Audio/RtStreaming/RtStreamingSink.hpp>
#include <Audio/RtStreaming/RtStreamingBuffer.hpp>
#include <gci_common.h>
#include <gci_audio.h>
#include <Devices/MPEU/Extensions/AtiW2282/AtiAudioPlayer.hpp>

class AtiAudioPlayerSinkThread;

class AtiAudioPlayerRtStreamingSink : public RtStreamingSink {

    friend class AtiAudioPlayer;
    friend class AtiAudioPlayerSinkThread;

public:
    AtiAudioPlayerRtStreamingSink();
    AtiAudioPlayerRtStreamingSink(AudioActiveReference &audio_ref);

    void ReleaseSemaphore() {m_wait_semaphore.Release();}

protected:
    virtual void StopOnCause (RtStreamingConn::StopCause cause);
    virtual void GetBufferInfo(BufferInfo & buf_info) const;

    virtual BOOLEAN StartAction();
    virtual BOOLEAN StopAction(RtStreamingConn::StopCause cause);
    
    virtual BOOLEAN OpenAction();
    virtual BOOLEAN CloseAction();

    RtStreamingBuffer m_buffers[2];

private:
    AtiAudioPlayerSinkThread * m_sink_thread;
    Semaphore m_wait_semaphore;
    AudioActiveReference &m_audio_ref;
    BOOLEAN m_stop_requested_by_conn;
};

#endif  // Apoxi_AtiAudioPlayerRtStreamingSink_hpp

