/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_RomData_hpp)
#define Auxiliary_RomData_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/BinData.hpp>

class RomData : public BinData {
    typedef BinData Base;

    public:
        static RomData* CreateInstance(const void *buffer,
                                       UINT32 length,
                                       DrmLocalId id = c_drm_invalid_local_id);

        virtual BOOLEAN Read(UINT32 idx, UINT8& val) const;
        
        virtual UINT32 Read(UINT32 idx, void *val, UINT32 nbytes) const;
        
        virtual UINT32 GetLength() const;

        const void* GetBuffer() const { return (const void*) m_buffer_ptr; }

    protected:
        RomData(const void *buffer, UINT32 length, DrmLocalId id = c_drm_invalid_local_id);
        virtual ~RomData();

    private:
        UINT32 m_buffer_length;
        const Uint8BufPtr m_buffer_ptr;
};


#endif  // Auxiliary_RomData_hpp

