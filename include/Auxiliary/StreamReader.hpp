/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StreamReader_hpp)
#define Apoxi_StreamReader_hpp

class StreamingReadInfo;
class StreamingCallback;
#include <Auxiliary/Stream.hpp>

class StreamReader {
    public:
        StreamReader();

        virtual ~StreamReader();

        // availability ---------------------------------------------------------------------------

        virtual UINT32 DataAvailable() const = 0;

        virtual BOOLEAN IsDataAvailable(UINT32 byte_count) const = 0;

        // reading --------------------------------------------------------------------------------

        virtual void RequestRead(StreamingReadInfo& read_info,
                                 const StreamingCallback* callback_object = 0) = 0;

        virtual void DataProcessed(const void* begin_data, UINT32 byte_count) = 0;

        // Positioning ----------------------------------------------------------------------------

        virtual BOOLEAN CanSeek() const = 0;

        virtual void Seek(Stream::Origin origin, 
                          INT32 offset, 
                          StreamingInfo& info) = 0;

        virtual UINT32 CurrentPosition(StreamingInfo& info) const = 0;

        // opening, closing ----------------------------------------------------------------------

        virtual void Open(StreamingInfo& info) = 0;

        virtual void Close(StreamingInfo& info) = 0;

};

#endif  // Apoxi_StreamReader_hpp


