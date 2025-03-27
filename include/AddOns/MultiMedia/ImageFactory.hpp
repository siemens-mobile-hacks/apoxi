/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageFactory_hpp)
#define Apoxi_ImageFactory_hpp

class Image;
class BinData;

class ImageFactory {
    public:     
        static Image* CreateImage(BinData* data, BOOLEAN* success = 0);

        static INT GetImageId(const BinData& data);
    
        static void DestroyImage(Image* image);
};


#endif // Apoxi_ImageFactory_hpp


