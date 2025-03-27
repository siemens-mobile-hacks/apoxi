/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StreamingWriteInfo_hpp)
#define Apoxi_StreamingWriteInfo_hpp

#include <Auxiliary/StreamingInfo.hpp>

class StreamingWriteInfo : StreamingInfo {
    public: 
        // Constructors, destructor ---------------------------------------------------------------

        StreamingWriteInfo(void* data_to_write = 0, UINT32 write_byte_count = 0);

        ~StreamingWriteInfo();

        // Getters --------------------------------------------------------------------------------

        void* GetDataToWrite() const { return m_data; }

        UINT32 GetWriteByteCount() const { return m_write_byte_count; }

        UINT32 GetWrittenByteCount() const { return m_written_byte_count; }

        // Setters --------------------------------------------------------------------------------

        void SetDataToWrite(void* data) { m_data = data; }

        void SetWriteByteCount(UINT32 write_byte_count) { m_write_byte_count = write_byte_count; } 

        void SetWrittenByteCount(UINT32 written_byte_count) { m_written_byte_count = written_byte_count; }

        // Private part ---------------------------------------------------------------------------

    private: 
        void* m_data;

        UINT32 m_write_byte_count; 

        UINT32 m_written_byte_count; 

};

#endif  // Apoxi_StreamingWriteInfo_hpp

