/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_RtStreamingSource_hpp)
#define Apoxi_RtStreamingSource_hpp

#include <Audio/RtStreaming/RtStreamingEndPoint.hpp>

class RtStreamingConn;
class RtStreamingBuffer;


class RtStreamingSource : public RtStreamingEndPoint {

    friend class RtStreamingConn;

    public:
        RtStreamingSource();


    protected:
        void    NotifyDataReady();

        virtual BOOLEAN     StartAction(const BufferInfo &  buf_info) = 0;
        
        virtual BOOLEAN     StopAction() = 0;

        virtual void    OnBufferSwitch(RtStreamingBuffer &  buffer) = 0;

        virtual void    Attach();
        virtual void    Detach();
};

#endif  // Apoxi_RtStreamingSource_hpp

