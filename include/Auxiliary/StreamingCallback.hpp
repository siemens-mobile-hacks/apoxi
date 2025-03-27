/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StreamingCallback_hpp)
#define Apoxi_StreamingCallback_hpp

#include <Auxiliary/StreamingReadInfo.hpp>
#include <Auxiliary/StreamingWriteInfo.hpp>

class StreamingCallback {
    public:
        StreamingCallback();

        virtual ~StreamingCallback();

        virtual void Callback(StreamingInfo& info) = 0; 

        virtual void CallbackRead(StreamingReadInfo& read_info) = 0; 

        virtual void CallbackWrite(StreamingWriteInfo& write_info) = 0; 

}

#endif  // Apoxi_StreamingCallback_hpp

