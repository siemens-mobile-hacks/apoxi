/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageObtainer_hpp)
#define Apoxi_ImageObtainer_hpp

#include <Auxiliary/ObjectObtainer.hpp>
#include <Config/GuiObjectFactory.hpp>

class Image;
class ResourceParser;
struct BitmapRes;
class Bitmap;

class ImageObtainer : public ObjectObtainer {
    typedef ObjectObtainer Base;

    public: 
        ImageObtainer();

        ImageObtainer(Image* image, BOOLEAN disposeable = FALSE);

        ImageObtainer(const BitmapRes& bitmap);

        ImageObtainer(const Bitmap& bitmap);

        // needed because of a bug in the tasking-compiler
        ImageObtainer(const ImageObtainer& img_obt);

        virtual ~ImageObtainer();

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        Image* GetImage();

        const Image* GetImage() const;

        const BitmapRes* GetBitmap() const;
        
        XYDIM GetWidth() const;

        XYDIM GetHeight() const;
};

#endif // Apoxi_ImageObtainer_hpp

