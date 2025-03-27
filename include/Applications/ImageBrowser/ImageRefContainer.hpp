/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageRefContainer_hpp)
#define Apoxi_ImageRefContainer_hpp

#include <ImageBrowser/Common/MediaRefContainer.hpp>
#include <ImageBrowser/ImageMetaData.hpp>

class ImageRef;
class ImageMetaData;

class ImageRefContainer : public MediaRefContainer
{
    typedef MediaRefContainer Base;

    public:
        ImageRefContainer();
        ImageRefContainer(const Path &database_path);
        virtual ~ImageRefContainer();

        virtual BOOLEAN Add(MediaRefPtr &media_ref,BOOLEAN free=TRUE);

        virtual BOOLEAN Delete(MediaRefPtr &media_ref, 
            BOOLEAN delete_file = FALSE);

        virtual BOOLEAN Rename(MediaRefPtr &media_ref, const WString &new_name);

        virtual UINT32 GetSizeOfRecord() const;
    protected:
        virtual MediaRefPtr CreateMediaRef() const;



        virtual FileFilterPtr GetMediaFileFilter() const;

        virtual BOOLEAN SetupMediaObject(MediaRefPtr &media_ref);
};

#endif  // Apoxi_ImageRefContainer_hpp
