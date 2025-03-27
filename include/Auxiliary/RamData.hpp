/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_RamData_hpp)
#define Auxiliary_RamData_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BinData.hpp>

class RamData : public BinData {
    typedef BinData Base;

    public:
        static RamData* CreateInstance(void HUGE *buffer,
                                       UINT32 length,
                                       DrmLocalId id = c_drm_invalid_local_id);

        virtual BOOLEAN Read(UINT32 idx, UINT8& val) const;
        
        virtual UINT32 Read(UINT32 idx, void *val, UINT32 nbytes) const;
        
        virtual UINT32 GetLength() const;

        virtual BinData* Clone() const;

        virtual MemMap* ObtainMemMap(UINT32 idx, UINT32 size) const;
        
        virtual void ReleaseMemMap(MemMap** h_map) const;

        void* GetBuffer() const { return (void*) m_buffer_ptr; }

    protected:
        RamData(void HUGE *buffer, UINT32 length, DrmLocalId id = c_drm_invalid_local_id);
        virtual ~RamData();

    private:
        UINT32 m_buffer_length;
        UINT8 HUGE* m_buffer_ptr;
};

#endif  // Auxiliary_RamData_hpp

