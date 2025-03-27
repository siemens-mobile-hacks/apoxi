/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AtiAudioPlayerRtStreamingConn_hpp)
#define Apoxi_AtiAudioPlayerRtStreamingConn_hpp

#include <Audio/RtStreaming/RtStreamingConn.hpp>

class AtiAudioPlayerRtStreamingSink;
class DataSourceRtStreamingSource;

class AtiAudioPlayerRtStreamingConn : public RtStreamingConn{

    public:

        AtiAudioPlayerRtStreamingConn(AtiAudioPlayerRtStreamingSink *snk, DataSourceRtStreamingSource *src);

    protected:

    private:

};
                             
#endif  // Apoxi_AtiAudioPlayerRtStreamingConn_hpp

