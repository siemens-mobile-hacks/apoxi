/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_DataSource_hpp)
#define Auxiliary_DataSource_hpp

#include <Auxiliary/DrmAsset.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

class DataSource;

typedef NiSharedPtr<DataSource> DataSourcePtr;

class DataSource
{
    public:
        virtual ~DataSource();

        virtual BOOLEAN Open() = 0;

        virtual BOOLEAN Close() = 0;

        virtual BOOLEAN IsOpen() const = 0;

        virtual BOOLEAN Read(void HUGE *buffer, UINT32 count) = 0;

        virtual BOOLEAN Read(void HUGE *buffer, UINT32 max_count,
            UINT32 &bytes_read) = 0;

        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 count)
            = 0;

        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer,
            UINT32 max_count, UINT32 &bytes_read) = 0;

        virtual BOOLEAN GetSize(UINT32 &size) const = 0;

        const DrmAsset& GetDrmAsset() const { return m_drm_asset; }

    protected:
        DataSource(DrmLocalId id);

        const DrmAsset m_drm_asset;
};

#endif  // Auxiliary_DataSource_hpp

