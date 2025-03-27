/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PngDecoder_hpp)
#define Apoxi_PngDecoder_hpp

#include <AddOns/libpng/png.h>

class BinData;

class PngDecoder {
    public:
        enum Error {
            NoError, 
            NoPngFormatError, 
            DecoderInitError, 
            OutOfMemoryError, 
            DecodingError
        };

    protected:
        PngDecoder();
        virtual ~PngDecoder();

    public:
        static PngDecoder* GetInstance();
        void ReleaseInstance();

        static BOOLEAN IsPng(const BinData &data);

        BOOLEAN Attach(const BinData &data);

        INT GetWidth() const;
        INT GetHeight() const;
        BOOLEAN IsInterlaced() const;

        BOOLEAN BeginDecoding(const BinData &data);

        BOOLEAN IsTransparent() const;

        Color GetTransparentColor() const;

//      void GetTransparentColor(UINT8 &red, UINT8 &green, UINT8 &blue) const;

        BOOLEAN HasNativeAlphaChannel() const;

        BOOLEAN DecodeNextScanline();

        void InitPixelColorAccess(INT scanline_idx = 0);

        void GetNextPixelColor(UINT8 &red, UINT8 &green, UINT8 &blue, UINT8 &alpha);

        void EndDecoding();

        Error GetLastError() const;

    protected:
        void CleanUp();

        BOOLEAN InitDecoderLib();
        void FreePng();
        void SetErr(Error code, BOOLEAN cleanup = TRUE);

        static void PngLibraryReadFunction(png_structp png_struct, 
            png_bytep data, png_size_t length);
        static png_voidp PngLibraryMallocFunction(png_structp png_struct, 
            png_size_t size);
        static void PngLibraryFreeFunction(png_structp png_struct, 
            png_voidp ptr);

    protected:
        const BinData *m_data;

        png_structp m_png_ptr;
        png_infop m_info_ptr;
        png_bytep m_scanline;
        png_uint_32 m_width;
        png_uint_32 m_height;
        int m_bit_depth;
        int m_color_type;
        int m_interlace_type;

        BOOLEAN m_is_transparent;
        Color m_transparent_color;
        UINT8 m_trns_red;
        UINT8 m_trns_green;
        UINT8 m_trns_blue;

        BOOLEAN m_has_native_alpha_channel;

        BOOLEAN m_background_specified;
        ColorValue m_background_color;
        UINT8 m_bkgd_red;
        UINT8 m_bkgd_green;
        UINT8 m_bkgd_blue;

        UINT32 m_data_idx;
        INT m_scanline_idx;

        Error m_last_error;

        static PngDecoder *c_decoder;
        static BOOLEAN c_sem_created;
        static Semaphore c_sem;

        static png_voidp m_huge_mem;

        // The number of channels each pixel has, i.e. 4 (RGBA).
        static const INT c_pixel_channels;
};

#endif  // Apoxi_PngDecoder_hpp

