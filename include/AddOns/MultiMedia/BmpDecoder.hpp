/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_BmpDecoder_hpp)
#define Apoxi_BmpDecoder_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include <Gui/Image.hpp>
#include <Gui/ImageDecoder.hpp>
#include <Auxiliary/BinData.hpp>

#define INPUT_BUFFER_SIZE 4096

class BmpDecoder : public ImageDecoder {
    typedef ImageDecoder Base;

    public:
        static BmpDecoder* GetInstance();
        virtual ~BmpDecoder();

        virtual BOOLEAN GetMetaData(Image& image, Image::MetaData* meta_data);

        virtual BOOLEAN BeginDecoding(const Image& image, INT frame_idx = 0);

        virtual void EndDecoding(const Image& image, INT frame_idx = 0);
        
        BOOLEAN DecodeScanline(INT scanline_idx, INT old_scanline_idx);
    
        UINT8* GetScanlineBuffer() const { return m_scanline; }

    private:
        BmpDecoder();
        
        BOOLEAN Decode24BitRgb();
        BOOLEAN DecodeRgb();
        BOOLEAN Decode8BitRle();
        BOOLEAN Decode4BitRle();

        BOOLEAN FillInputBuffer();
        BOOLEAN RelocateInputBuffer(UINT32 pos);
        
        static BmpDecoder m_instance;
    
        UINT8* m_scanline;
        INT m_scanline_byte_count;
        UINT8* m_colortable;
        INT m_decompressed_scanline_idx;
        UINT32 m_offset;
        UINT32 m_abs_offset;
        UINT32 m_bytes_in_buffer;
        const BinData* m_data;

        UINT8* m_next_input_byte;
        UINT8 m_input_buffer[INPUT_BUFFER_SIZE];

        typedef struct BitmapFileHeader {
            UINT8  m_bfType[2];
            UINT32 m_bfSize;
            UINT16 m_res1;
            UINT16 m_res2;
            UINT32 m_image_start;
        } BMPFILEHEADER;

        typedef struct BitmapInfoHeader {
            UINT32 m_size;
            UINT32 m_width;
            UINT32 m_height;
            UINT16 m_planes;
            UINT16 m_bpp;
            UINT32 m_compression;
            UINT32 m_image_size;
            UINT32 m_xpels;
            UINT32 m_ypels;
            UINT32 m_clr_used;
            UINT32 m_clr_important;
            
        } BMPINFOHEADER;

        BMPFILEHEADER m_fileheader;
        BMPINFOHEADER m_infoheader;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //Apoxi_BmpDecoder_hpp

