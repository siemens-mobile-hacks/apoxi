/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StreamingReadInfo_hpp)
#define Apoxi_StreamingReadInfo_hpp

#include <Auxiliary/StreamingInfo.hpp>

class StreamingReadInfo : StreamingInfo {
    public:
        // Constructors, destructor ---------------------------------------------------------------

        StreamingReadInfo(UINT32 requested_byte_count = 0);

        ~StreamingReadInfo();

        // Getters --------------------------------------------------------------------------------

        void* GetDataRead() const { return m_data; }

        UINT32 GetRequestedByteCount() const { return m_requested_byte_count; }

        UINT32 GetAvailableByteCount() const { return m_available_byte_count; }

        BOOLEAN EndOfStream() const { return m_end_of_stream; }

        // Setters --------------------------------------------------------------------------------

        void SetDataRead(void* data) { m_data = data; }

        void SetRequestedByteCount(UINT32 requested_byte_count) { m_requested_byte_count = requested_byte_count; }

        void SetAvailableByteCount(UINT32 available_byte_count) { m_available_byte_count = available_byte_count; }

        void SetEndOfStream(BOOLEAN eos) { m_end_of_stream = eos; }


        // Private part ---------------------------------------------------------------------------

    private:
        void* m_data;

        UINT32 m_requested_byte_count;

        UINT32 m_available_byte_count;

        BOOLEAN m_end_of_stream;
};

#endif  // Apoxi_StreamingReadInfo_hpp

