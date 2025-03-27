/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageRef_hpp)
#define Apoxi_ImageRef_hpp

#include <Afs/Ffs/FfsTypes.hpp>
#include <ImageBrowser/Common/MediaRef.hpp>
#include <ImageBrowser/ImageMetaData.hpp>
#include <Afs/Rfs/FileBinData.hpp>

class Image;

class ImageRef : public MediaRef
{
    typedef MediaRef Base;

    public:
        ImageRef();

#if defined(APOXI_INCLUDE_DRM)
        ImageRef(const DrmInfo &drm_info);
#endif

        virtual ~ImageRef();

        virtual MetaData& GetMetaData();
        virtual const MetaData& GetMetaData() const;

        virtual void SetMetaData(const MetaData &meta_data);

#if defined(APOXI_INCLUDE_DRM)
        virtual WString GetAssetInfo();
#endif

        Image* GetImage(BOOLEAN buffer_to_ram = TRUE);

        const ImageObtainer GetImageObtainer();
        void SetImage(Image *image);

        BOOLEAN IsImageInitialized() const;

        void ReleaseImage();

        //ImageObtainer GetThumbnail();

        Image* CreateImageObject(BinData *bd,BOOLEAN buffer_to_ram = TRUE);

        Image* CreateImageObject(const BinData *bd,BOOLEAN buffer_to_ram = TRUE);


#if defined(APOXI_INCLUDE_DRM)
        Image* CreateImageObject(BinData *fbd,FfsDrmAttrib attrib);
#endif

        void ReleaseThumbnail();

        //const ImageObtainer CreateThumbnail();

        //BOOLEAN SaveThumbnail(const ImageObtainer& img_obtainer);

    private:
        ImageMetaData m_meta_data;
        Image *m_image;
        FileBinData *m_fbd;


#if defined(APOXI_INCLUDE_DRM)

        Image * ValidateImage(BinData *bd);
        //
        Image* CreateImageObject(FfsDrmAttrib attrib);
#endif

        Image* ConstructImage(BinData *bd);
        //
        Image* CreateImageObject(BOOLEAN buffer_to_ram = TRUE);
};

#endif  // Apoxi_ImageRef_hpp
