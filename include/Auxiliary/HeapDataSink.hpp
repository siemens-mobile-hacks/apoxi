/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HeapDataSink_hpp)
#define Apoxi_HeapDataSink_hpp

#include <Auxiliary/DataSink.hpp>
#include <Auxiliary/Vector.hpp>

class HeapDataSink;

typedef NiSharedPtr<HeapDataSink> HeapDataSinkPtr;

class HeapDataSink : public DataSink
{
    typedef DataSink Base;

    friend class HeapDataSource;

    public:
        HeapDataSink(UINT32 block_size,
            DrmLocalId id = c_drm_invalid_local_id);

        virtual ~HeapDataSink();

        virtual BOOLEAN Open();

        virtual BOOLEAN Close();

        virtual BOOLEAN IsOpen() const;

        virtual UINT32 Write(const void HUGE *buf, UINT32 nbytes);

        virtual UINT32 Write(UINT32 offset, const void HUGE *buf,
            UINT32 nbytes);

        virtual BOOLEAN GetSize(UINT32 &size) const;

    private:
            BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 count);


        UINT8 m_open_state;
        Vector<UINT8*> m_blocks;
        UINT32 m_data_length;
        const UINT32 m_block_size;
};

#endif  // Apoxi_HeapDataSink_hpp

