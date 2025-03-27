/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaRef_hpp)
#define Apoxi_MediaRef_hpp
#include <Afs/Ffs/FfsTypes.hpp>
#include <Afs/Rfs/Path.hpp>
#if defined(APOXI_INCLUDE_DRM)
    #include <Auxiliary/DrmAsset.hpp>
#endif
#include <Auxiliary/BufferedData.hpp>

class MetaData;

class MediaRef
{
    protected:
        MediaRef();

    public:
        virtual ~MediaRef();

        virtual MetaData& GetMetaData() = 0;
        virtual const MetaData& GetMetaData() const = 0;

        virtual void SetMetaData(const MetaData &meta_data) = 0;

#if defined(APOXI_INCLUDE_DRM)
        virtual WString GetAssetInfo() = 0;
#endif

        BOOLEAN operator==(const MediaRef &media_ref) const;

        BOOLEAN IsDrmMedia( FfsDrmAttrib &attrib);

        BOOLEAN IsDrmMedia();

#if defined(APOXI_INCLUDE_DRM)

        INT GetLastDrmError() { return m_last_drm_error; }

        void SetLastDrmError(INT drm_error);

        DrmAsset* GetDrmAsset();

        void OpenRightsIssuerUrl();




        const BinData * GetDcf();
#endif

        BOOLEAN SendAsMms(const AtomItem* item);



    private:
#if defined(APOXI_INCLUDE_DRM)
        INT m_last_drm_error;
        DrmAsset m_drm_asset;
#endif
        AtomItem    *m_ptr_item;

};

#endif  // Apoxi_MediaRef_hpp
