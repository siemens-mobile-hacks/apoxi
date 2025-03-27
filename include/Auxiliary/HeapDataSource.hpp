/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_HeapDataSource_hpp)
#define Auxiliary_HeapDataSource_hpp

#include <Auxiliary/DataSource.hpp>

class HeapDataSink;
class HeapDataSource;

typedef NiSharedPtr<HeapDataSink> HeapDataSinkPtr;

typedef NiSharedPtr<HeapDataSource> HeapDataSourcePtr;

class HeapDataSource : public DataSource
{
    typedef DataSource Base;

    public:
        HeapDataSource(const HeapDataSinkPtr &sink);

        virtual ~HeapDataSource();

        virtual BOOLEAN Open();
        virtual BOOLEAN Close();
        virtual BOOLEAN IsOpen() const;
        virtual BOOLEAN Read(void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(void HUGE *buffer, UINT32 max_count,
            UINT32&bytes_read);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer,
            UINT32 max_count, UINT32 &bytes_read);
        virtual BOOLEAN GetSize(UINT32 &size) const;

    private:
        HeapDataSinkPtr m_sink;
        BOOLEAN m_open;
        UINT32 m_cur_pos;
};

#endif  // Auxiliary_HeapDataSource_hpp

