/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_BinDataDataSource_hpp)
#define Auxiliary_BinDataDataSource_hpp

#include <Auxiliary/BinData.hpp>
#include <Auxiliary/BinDataOwner.hpp>
#include <Auxiliary/DataSource.hpp>

class BinDataDataSource : public DataSource
{
    typedef DataSource Base;

    public:
        BinDataDataSource(const BinDataPtr bin_data);

        virtual ~BinDataDataSource();

        virtual BOOLEAN Open();
        virtual BOOLEAN Close();

        virtual BOOLEAN IsOpen() const;

        virtual BOOLEAN Read(void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(void HUGE *buffer, UINT32 max_count, UINT32&bytes_read);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 max_count, UINT32 &bytes_read);
        virtual BOOLEAN GetSize(UINT32 &size) const;

    protected:
        // The data source that is read from.
        BinDataPtr m_bin_data;

        BOOLEAN m_is_open;
        UINT32  m_offset;
};

#endif  // Auxiliary_DataSourceBinData_hpp


