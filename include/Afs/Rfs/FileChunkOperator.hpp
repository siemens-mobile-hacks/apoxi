/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileChunkOperator_hpp)
#define Apoxi_FileChunkOperator_hpp

#include <Kernel/Condition.hpp>

class File;

class FileChunkOperator
{
    public:
        enum Operation {
            ReadOffsetExact,
            ReadOffsetMax,
            WriteOffsetExact
        };

    public:
        FileChunkOperator(File &file, UINT32 chunk_size,
            BOOLEAN send_progress_messages);

        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 count);
        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 max_count,
            UINT32 &bytes_read);
        BOOLEAN Write(const void HUGE *buffer, UINT32 offset, UINT32 count);

        BOOLEAN Cancel();

    private:
        BOOLEAN Operate();

        static void OperateNextChunkCb(void *arg);
        void OperateNextChunk();

        void SendProgressMsg() const;
        inline UINT CalcProgress() const;

    private:
        File &m_file;
        const UINT32 m_chunk_size;
        const BOOLEAN m_send_progress_messages;

        void HUGE *m_read_buffer;
        const void HUGE *m_write_buffer;
        BOOLEAN m_cancelled;

        Operation m_operation;
        UINT32 m_offset;
        UINT32 m_count;
        UINT32 m_bytes_operated;

        BooleanCondition m_chunk_cond;
};

#endif  // Apoxi_FileChunkOperator_hpp

