/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SoundMetaData_hpp)
#define Apoxi_SoundMetaData_hpp

#include <SoundBrowser/Common/MetaData.hpp>

struct SoundMetaDataRecord : public MetaDataRecord {
};

class SoundMetaData : public MetaData
{
    typedef MetaData Base;

    public:
        SoundMetaData();
#if defined(APOXI_INCLUDE_DRM)
        SoundMetaData(const Path &path, const DrmInfo &drm_info = DrmInfo(), 
            UINT32 size = 0);
#else
        SoundMetaData(const Path &path, UINT32 size = 0);
#endif
        virtual ~SoundMetaData();

        virtual MetaDataRecord& GetMetaDataRecord();

        virtual const MetaDataRecord& GetMetaDataRecord() const;

    private:
        SoundMetaDataRecord m_data;
};

#endif  // Apoxi_SoundMetaData_hpp
