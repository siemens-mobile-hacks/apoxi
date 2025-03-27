/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MetaData_hpp)
#define Apoxi_MetaData_hpp

#if defined(APOXI_INCLUDE_DRM)
    #include <Auxiliary/DrmInfo.hpp>
#endif
#include <Afs/Rfs/PathProfile.hpp>

struct MetaDataRecord {
    UINT8 m_mark_delete; 
    INT32 m_index;
    PathProfile m_resource_path_profile;
#if defined(APOXI_INCLUDE_DRM)
    DrmInfoPersistStructure m_drm_info;
#endif
    UINT32 m_size;

    MetaDataRecord();
    virtual ~MetaDataRecord();
};

class MetaData
{
    public:
        MetaData();

        virtual ~MetaData();

#if defined(APOXI_INCLUDE_DRM)
        void Init(const Path &path, const DrmInfo &drm_info = DrmInfo(), 
            UINT32 size = 0);
#else
        void Init(const Path &path, UINT32 size = 0);
#endif

        virtual MetaDataRecord& GetMetaDataRecord() = 0;

        virtual const MetaDataRecord& GetMetaDataRecord() const = 0;

        Path GetPath() const { return GetMetaDataRecord().m_resource_path_profile; }

        void SetPath(const Path &path) { path.WriteTo(GetMetaDataRecord().m_resource_path_profile); }

#if defined(APOXI_INCLUDE_DRM)

        void GetDrmInfo(DrmInfo &drm_info) const { drm_info.ReadFrom(GetMetaDataRecord().m_drm_info); }

        void SetDrmInfo(const DrmInfo &drm_info) { drm_info.WriteTo(&GetMetaDataRecord().m_drm_info); }
#endif

        UINT32 GetSize() const { return GetMetaDataRecord().m_size; }

        void SetSize(UINT32 size) { GetMetaDataRecord().m_size = size; }

        MimeType GetMimeType() const { return GetPath().GetMimeType(); }

        virtual WString GetInfoText() const;

        void SetDisplayedName(const WString &displayed_name) {  m_displayed_name = displayed_name; }

        const WString& GetDisplayedName() const { return m_displayed_name; }

        void SetMarkDelete(BOOLEAN mark_delete);

        BOOLEAN GetMarkDelete() const { return GetMetaDataRecord().m_mark_delete; }

        void SetIndex(INT32 index) { GetMetaDataRecord().m_index= index; }

        INT32 GetIndex() const { return GetMetaDataRecord().m_index; }
    private:
        
        WString m_displayed_name;
};

#endif  // Apoxi_MetaData_hpp
