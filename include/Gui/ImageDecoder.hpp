/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageDecoder_hpp)
#define Apoxi_ImageDecoder_hpp

#include <Gui/Image.hpp>

class ImageDecoder {
    public:
        ImageDecoder(BOOLEAN shared = TRUE, const Ticks& timeout = Ticks(200));

        virtual ~ImageDecoder();

        virtual BOOLEAN GetMetaData(Image& image, Image::MetaData* meta_data) = 0;

        virtual BOOLEAN BeginDecoding(const Image& image, INT frame_idx = 0);

        virtual void EndDecoding(const Image& image, INT frame_idx = 0);

    private:
        BOOLEAN m_shared;
        Ticks m_timeout;
        Semaphore m_sem;
};


#endif // Apoxi_ImageDecoder_hpp


