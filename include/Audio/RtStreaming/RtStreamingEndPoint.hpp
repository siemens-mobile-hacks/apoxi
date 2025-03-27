/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_RtStreamingEndPoint_hpp)
#define Apoxi_RtStreamingEndPoint_hpp

#include "RtStreamingConn.hpp"
#include "RtStreamingBuffer.hpp"

class RtStreamingEndPoint {

    public:
        struct  BufferInfo {
            UINT32  latency_ms;     
            UINT32  buffer_size;    
        };
        
        RtStreamingEndPoint();

        virtual ~RtStreamingEndPoint();

        BOOLEAN             Open(RtStreamingConn &  conn);

        BOOLEAN             Close();

    protected:
        virtual BOOLEAN     OpenAction() = 0;
        
        virtual BOOLEAN     CloseAction() = 0;

        virtual void        Attach() = 0;
        virtual void        Detach() = 0;

        void                NotifyError();

        void                NotifyStoppedOnCause(RtStreamingConn::StopCause cause);

        // Sets the Conn Pointer
        void SetConn(RtStreamingConn &  conn) {m_conn_ptr = &conn;}

        RtStreamingConn &   GetConn()
        {
            ASSERT(m_conn_ptr != 0);
            return  *m_conn_ptr;
        }

    private:
        RtStreamingConn *   m_conn_ptr;
};

#endif  // Apoxi_RtStreamingEndPoint_hpp

