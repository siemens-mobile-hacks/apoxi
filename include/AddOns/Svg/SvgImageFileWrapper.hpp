/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgImageFileWrapper_hpp)
#define Apoxi_SvgImageFileWrapper_hpp

#include "SvgIoWrapper.hpp"

class Image;
class SvgImageFileWrapper : public SvgIoWrapper
{
    public: 
        SvgImageFileWrapper(UINT8 *p_img_data, UINT32 img_data_length, UINT8 content_type, BOOLEAN *success); 
        virtual ~SvgImageFileWrapper(); 
        virtual UINT32 Read(UINT8 *p_dst_buffer, UINT32 bytes_wanted); 
    Image* GetImage() const;

    XYDIM GetWidth() const;
    XYDIM GetHeight() const;

    private: 
        Image *m_img; 
        void *m_decoded_data; 
        XYDIM m_width, m_height; 

        void ReSizeImage(); 
    INT32 Sqrt(INT32 n) const;
}; 
#endif

