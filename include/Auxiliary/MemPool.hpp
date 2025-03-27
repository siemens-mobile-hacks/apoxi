/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MemPool_hpp)
#define Apoxi_MemPool_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/BitVector.hpp>

class MemPoolEntry : public Linkable<class MemPoolEntry> {
    public:
        MemPoolEntry();

        void* Alloc(INT size);
        void Release(void *p,INT size);

        inline BOOLEAN Contains(void *data) const {
            INT *p = (INT *) data;
            return(p >= m_data && p < (m_data + AtomCount));
        }

    private:
        enum {
            BytesPerUnit = 8,
            UnitCount = 128,

            MemSize = BytesPerUnit * UnitCount,
            BytesPerAtom = sizeof(INT),
            AtomCount = MemSize / BytesPerAtom,
            AtomsPerUnit = BytesPerUnit / BytesPerAtom
        };

        BitVector<UnitCount> m_bitmap;
        INT m_data[AtomCount];

        INT SizeToUnits(INT size) const;
        void* UnitIdxToAddr(INT blockidx);
        INT AddrToUnitIdx(void *addr) const;
};

class MemPool {
    public:
        MemPool();
        virtual ~MemPool();

        void* Alloc(INT size);
        void Release(void *data,INT size);

    private:
        MemPoolEntry m_mpe;

        // prevent cloning of a MemPool
        MemPool(const MemPool& mem_pool);

        // prevent cloning of a Dispatcher
        MemPool& operator=(const MemPool& mem_pool);
};

#endif  // Apoxi_MemPool_hpp


