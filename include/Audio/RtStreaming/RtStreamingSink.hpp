/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_RtStreamingSink_hpp)
#define Apoxi_RtStreamingSink_hpp

#include    <Audio/RtStreaming/RtStreamingConn.hpp>
#include    <Audio/RtStreaming/RtStreamingEndPoint.hpp>
#include    <Audio/RtStreaming/RtStreamingBuffer.hpp>

class RtStreamingSink : public RtStreamingEndPoint {

    friend class RtStreamingConn;

public:
    RtStreamingSink();

protected:
    virtual void StopOnCause (RtStreamingConn::StopCause cause) = 0;
    
    virtual void GetBufferInfo(BufferInfo & buf_info) const = 0;

    virtual BOOLEAN StartAction() = 0;
        
    virtual BOOLEAN StopAction(RtStreamingConn::StopCause cause) = 0;

    void SwitchBuffer(RtStreamingBuffer &   buffer);
    
    virtual void    Attach();
    virtual void    Detach();
};

#endif  // Apoxi_RtStreamingSink_hpp

