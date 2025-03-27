/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DecodingThreadlet_hpp)
#define Apoxi_DecodingThreadlet_hpp

#include <Gui/Bitmap.hpp>
#include <Gui/Image.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Kernel/Threadlet.hpp>

class DecodingThreadlet : public Threadlet {
    typedef Threadlet Base;
    
    public:
        virtual ~DecodingThreadlet();
    
        static DecodingThreadlet* CreateInstance(Image* image,
                                                 Bitmap* bitmap,
                                                 INT frame_idx);

        virtual void ReleaseInstance(); 

        virtual INT Fn();
        

    private:
        DecodingThreadlet(Image* image,
                          Bitmap* bitmap,
                          INT frame_idx);

        Image* m_image;
        Bitmap* m_bitmap;
        INT m_frame_idx;
        ImageObtainer m_image_obt;
};



#endif // Apoxi_DecodingThreadlet_hpp

