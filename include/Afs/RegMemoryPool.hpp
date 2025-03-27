/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */     
/* Contains Registry Interface declarations and global defines */

#if !defined(Apoxi_RegMemoryPool_hpp)
#define Apoxi_RegMemoryPool_hpp
#include <Afs/RegDefines.hpp>
#include <Afs/RegNodeFile.hpp>
#include <Afs/RegDeleteBuffer.hpp>
#include <Afs/RegManager.hpp>


struct RegMemoryBuffer{
            UINT16 m_lru_count;
            RegNodeBuffer m_node_buffer;
};

typedef struct Transaction{
    INT16 m_file_id;
    INT16 m_transaction_id;
}RegDeletionBuffer, RegBackupHeader;

class RegMemoryPool {

    public:
        static BOOLEAN Init();

        static void FreeNodeBuffer(INT16 file_id);

        static RegNodeBuffer*  GetNodeBuffer(INT16 file_id);

        static RegDeletionBufferEntry* GetDeletionBuffer();

        static void FlushBuffers(INT16 transaction_id);

        
    private:

        static INT GetLruBuffer();

        static void IncrementLruCount(INT lru_index);

        static void AdjustLruValues();

        static void Sort(UINT16 array[]);

        static UINT8 m_memory_pool[c_reg_max_pool_buffers * c_reg_node_file_size_max];

        static RegMemoryBuffer  m_memory_buffer[c_reg_max_pool_buffers];

        static UINT8 m_memory_deletion_pool[c_max_interior_node_records * sizeof(RegDeletionBuffer)];

        static RegDeletionBufferEntry m_memory_deletion_entry;

        static RegManager m_manager;
        
        
};

#endif

