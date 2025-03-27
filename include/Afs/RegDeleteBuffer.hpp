/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */     
/* Contains Registry Interface declarations and global defines */

#if !defined(Apoxi_RegDeleteBuffer_hpp)
#define Apoxi_RegDeleteBuffer_hpp
#include <Afs/RegDefines.hpp>


class RegDeletionBufferEntry {
    
    public:
    
        RegDeletionBufferEntry() {}

        ~RegDeletionBufferEntry() {}

        void ResetDeletionBuffer();

        void Init(UINT8* raw_memory);

        void FreeDeletionBuffer(INT16 transaction_id);

        void MoveNextElements(INT16 index);

        UINT GetDelBufCount();

        void AddToDeleteBuffer(INT16 file_id, INT16 transac_id);

        void IncrementDelBufCount();

        void DecrementDelBufCount();

    private:
        UINT m_del_count;

        UINT8* m_reg_del_node_buffer;
};
#endif


