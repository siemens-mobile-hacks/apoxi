/*  ------------------------------------------------------------------------
Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */
#if !defined(Apoxi_DataSourceRtStreamingSource_hpp)
#define Apoxi_DataSourceRtStreamingSource_hpp

#include <Audio/RtStreaming/RtStreamingEndPoint.hpp>
#include <Audio/RtStreaming/RtStreamingSource.hpp>
#include <Audio/RtStreaming/RtStreamingBuffer.hpp>
#include <Afs/Rfs/FileDataSource.hpp>
#include <Kernel/Os/Semaphore.hpp>

class RtStreamingConn;
class RtStreamingBuffer;
class DataSourceRtStreamingBufferFillThread;


class DataSourceRtStreamingSource : public RtStreamingSource {

friend DataSourceRtStreamingBufferFillThread;

public:
    DataSourceRtStreamingSource(DataSourcePtr ds);

protected:
    virtual BOOLEAN OpenAction();
    virtual BOOLEAN StartAction(const BufferInfo & buf_info);
    virtual BOOLEAN StopAction();
    virtual BOOLEAN CloseAction();
    virtual void    OnBufferSwitch(RtStreamingBuffer &buffer);

    UINT8 m_no_of_buffers;
    UINT32 m_buf_size;
    UINT32 m_cur_file_offset;
    INT8 m_cur_buffer_returned;
    BOOLEAN m_stop_requested_by_conn;
    DataSourcePtr m_cur_src;
    Semaphore m_fill_semaphore;
   
    RtStreamingBuffer * buffers;
    
private:

    DataSourceRtStreamingBufferFillThread  * m_buf_thread;
};

#endif  // Apoxi_DataSourceRtStreamingSource_hpp

