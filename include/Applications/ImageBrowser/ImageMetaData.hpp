/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageMetaData_hpp)
#define Apoxi_ImageMetaData_hpp

#include <ImageBrowser/Common/MetaData.hpp>

//const UINT8 img_browser_thumbnail_width = 30;
//const UINT8 img_browser_thumbnail_height = 30;

struct ImageMetaDataRecord : public MetaDataRecord {
    UINT16 m_width;
    UINT16 m_height;
    UINT8 m_frame;
    //UINT8 m_use_thumbnail;

    ImageMetaDataRecord(UINT16 width = 0, UINT16 height= 0, INT frame = 0);
    virtual ~ImageMetaDataRecord();
};

class ImageMetaData : public MetaData
{
    typedef MetaData Base;

    public:
        ImageMetaData();

#if defined(APOXI_INCLUDE_DRM)
        ImageMetaData(const Path &path, const DrmInfo &drm_info = DrmInfo(),
            UINT32 size = 0, XYDIM width = 0, XYDIM height = 0, INT frame = 0);
#else
        ImageMetaData(const Path &path, UINT32 size = 0, XYDIM width = 0,
            XYDIM height = 0, INT frame = 0);
#endif

        virtual ~ImageMetaData();

#if defined(APOXI_INCLUDE_DRM)
        void Init(const Path &path, const DrmInfo &drm_info = DrmInfo(),
            UINT32 size = 0, XYDIM width = 0, XYDIM height = 0, INT frame = 0);
#else
        void Init(const Path &path, UINT32 size = 0, XYDIM width = 0,
            XYDIM height = 0, INT frame = 0);
#endif

        virtual MetaDataRecord& GetMetaDataRecord();

        virtual const MetaDataRecord& GetMetaDataRecord() const;

        //BOOLEAN UseThumbnail() const;

        //void SetUseThumbnail(BOOLEAN use);

        //Path GetThumbnailPath() const;

        UINT16 GetWidth() const;

        void SetWidth(UINT16 width);

        UINT16 GetHeight() const;

        void SetHeight(UINT16 height);

        UINT8 GetFrame() const;

        void SetFrame(UINT8 frame);

        virtual WString GetInfoText() const;

    private:
        ImageMetaDataRecord m_data;
};

#endif  // Apoxi_ImageMetaData_hpp
