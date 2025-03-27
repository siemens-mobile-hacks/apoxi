/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StreamWriter_hpp)
#define Apoxi_StreamWriter_hpp

class StreamingCallback;
class StreamingWriteInfo;
#include <Auxiliary/Stream.hpp>

class StreamWriter {
    public:
        StreamWriter();

        virtual ~StreamWriter();

        // acceptability --------------------------------------------------------------------------

        virtual UINT32 DataAcceptable() const = 0;

        virtual BOOLEAN IsDataAcceptable(UINT32 byte_count) const = 0;

        // writing --------------------------------------------------------------------------------

        virtual void RequestWrite(StreamingWriteInfo& write_info,
                                  const StreamingCallback* callback_object = 0) = 0;

        // Positioning ----------------------------------------------------------------------------

        virtual BOOLEAN CanSeek() const = 0; 

        virtual void Seek(Stream::Origin origin, 
                          INT32 offset, 
                          StreamingInfo& info) = 0; 

        virtual UINT32 CurrentPosition(StreamingInfo& info) const = 0; 

        // Open, flushing, closing ----------------------------------------------------------------

        virtual void Open(StreamingInfo& info) = 0; 

        virtual void Flush(StreamingInfo& info) = 0; 

        virtual void Close(StreamingInfo& info) = 0; 
};

#endif  // Apoxi_StreamWriter_hpp


