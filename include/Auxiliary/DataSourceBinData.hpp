/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_DataSourceBinData_hpp)
#define Auxiliary_DataSourceBinData_hpp

#include <Auxiliary/BinData.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

class DataSource;

typedef NiSharedPtr<DataSource> DataSourcePtr;

class DataSourceBinData : public BinData
{
    typedef BinData Base;

    public:
        static DataSourceBinData* CreateInstance(
            const DataSourcePtr &data_source);

        virtual BOOLEAN Read(UINT32 idx, UINT8 &val) const;
        virtual UINT32 Read(UINT32 idx, void *buf, UINT32 nbytes) const;
        virtual UINT32 GetLength() const;
        virtual MemMap* ObtainMemMap(UINT32 idx, UINT32 size) const;
        virtual void ReleaseMemMap(MemMap **h_map) const;

    protected:
        DataSourceBinData(const DataSourcePtr &data_source);
        virtual ~DataSourceBinData();

        // The data source that is read from.
        DataSourcePtr m_data_source;
};

#endif  // Auxiliary_DataSourceBinData_hpp


