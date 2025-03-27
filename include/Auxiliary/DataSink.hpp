/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_DataSink_hpp)
#define Auxiliary_DataSink_hpp

#include <Auxiliary/DrmAsset.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

class DataSink;

typedef NiSharedPtr<DataSink> DataSinkPtr;

class DataSink
{
    public:
        virtual ~DataSink();

        virtual BOOLEAN Open() = 0;

        virtual BOOLEAN Close() = 0;

        virtual BOOLEAN IsOpen() const = 0;

        virtual UINT32 Write(const void HUGE *buf, UINT32 nbytes) = 0;

        virtual UINT32 Write(UINT32 offset, const void HUGE *buf,
            UINT32 nbytes) = 0;

        virtual BOOLEAN GetSize(UINT32 &size) const = 0;

        const DrmAsset& GetDrmAsset() const { return m_drm_asset; }

    protected:
        DataSink(DrmLocalId id);

        const DrmAsset m_drm_asset;
};

#endif  // Auxiliary_DataSink_hpp


