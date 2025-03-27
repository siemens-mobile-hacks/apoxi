/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_BinData_hpp)
#define Auxiliary_BinData_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/DrmAsset.hpp>

class MemMap {
    friend class BinData;
    typedef void HUGE* BufPtr;
    typedef UINT8 HUGE* Uint8BufPtr;

    public:
        MemMap(void *ptr, UINT32 len, INT id);

        virtual ~MemMap();

        BOOLEAN Read(UINT32 idx, UINT8& val) const;

        UINT32 Read(UINT32 idx, void* buf, UINT32 byte_count) const;

        UINT32 GetLength() const { return m_length; }

        const UINT8* GetHandle(UINT32 idx = 0) const;

    private:
        INT m_id;
        UINT32 m_length;
        Uint8BufPtr m_buf;
};


class BinData {
    public:
        typedef void HUGE* BufPtr;
        typedef UINT8 HUGE* Uint8BufPtr;

        virtual BOOLEAN Read(UINT32 idx, UINT8& val) const = 0;

        virtual UINT32 Read(UINT32 idx, void* buf, UINT32 byte_count) const = 0;

        virtual UINT32 GetLength() const = 0;

        const DrmAsset& GetDrmAsset() const { return m_drm_asset; }

        virtual void ReleaseInstance();

        virtual BinData* Clone() const;
        
        virtual MemMap* ObtainMemMap(UINT32 idx, UINT32 size) const;
        
        virtual void ReleaseMemMap(MemMap** h_map) const;

        MemMap* GetMemMap(UINT32 idx, UINT32 size) const { return ObtainMemMap(idx, size); }

    protected:
        BinData(DrmLocalId id = c_drm_invalid_local_id);
        virtual ~BinData();
        
    private:
        DrmAsset m_drm_asset;
};

#endif  // Auxiliary_BinData_hpp


