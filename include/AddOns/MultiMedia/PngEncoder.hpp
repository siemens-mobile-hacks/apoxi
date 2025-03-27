/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PngEncoder_hpp)
#define Apoxi_PngEncoder_hpp


class Threadlet;
class BinData;
class DataSink;

#include <AddOns/libpng/png.h>
#include <Gui/ImageEncoder.hpp>

class PngEncoder : public ImageEncoder {
    typedef ImageEncoder Base;

    public:
        class EncodingParameters : public ImageEncoder::EncodingParameters {
            typedef ImageEncoder::EncodingParameters Base;

            public:
                enum EncodingFormat {
                    GrayScaleFormat,
                    RgbFormat,
                    PaletteFormat,
                    GrayScaleAlphaFormat,
                    RgbAlphaFormat
                };
 
                EncodingParameters(XYDIM width, XYDIM height) :
                    Base(width, height),
                    m_encoding_format(RgbFormat)
                {}

                void SetEncodingFormat(EncodingFormat format) { m_encoding_format = format; }

                EncodingFormat GetEncodingFormat() const { return m_encoding_format; }

                #if defined(APOXI_COMPAT_2_8_0)

                    enum ImageColorFormatType {
                        Rgb565Format,
                        Rgb888Format,
                        Rgba8888Format
                    };

                    EncodingParameters(XYDIM width, XYDIM height, ImageColorFormatType color_format) :
                        Base(width, height),
                        m_encoding_format(RgbFormat),
                        m_color_format(color_format)
                    {}

                    void SetColorFormat(ImageColorFormatType color_format) { m_color_format = color_format; }

                    ImageColorFormatType GetColorFormat() const { return m_color_format; }
                #endif // APOXI_COMPAT_2_8_0
                            
            private:
                EncodingFormat m_encoding_format;

                #if defined(APOXI_COMPAT_2_8_0)
                    ImageColorFormatType m_color_format;
                #endif
        };


        PngEncoder(const EncodingParameters& param);

        virtual ~PngEncoder();

        virtual BOOLEAN Encode(BinData& src,
                               const Image::MetaData& src_params,
                               DataSink& dest,
                               BOOLEAN block = TRUE,
                               void* context = 0,
                               Cb_ImageEncoded = 0);

        virtual BOOLEAN Encode(const Image& img,
                               DataSink& dest,
                               BOOLEAN block = TRUE);

    protected:
        virtual BOOLEAN BeginEncoding(DataSink& dest);

        virtual BOOLEAN EndEncoding(DataSink& dest);

        virtual BOOLEAN EncodeSynchronously(BinData& src,
                                            const Image::MetaData& src_params,
                                            DataSink& dest);

        virtual BOOLEAN EncodeSynchronously(const Image& img, DataSink& dest);

    private:
        BOOLEAN TraverseScanlines(BinData& src, png_byte* buffer);

        BOOLEAN EncodeScanline(BinData& src, png_byte* buffer);

        BOOLEAN InitEncoderLib(DataSink &dest);

        void CleanUp();

        void SendCallback(DataSink& dest);

        void SetError(Error code, BOOLEAN cleanup = TRUE);

        static void PngLibraryWriteFunction(png_structp png_struct, 
            png_bytep data, png_size_t length);

        static png_voidp PngLibraryMallocFunction(png_structp png_struct, 
            png_size_t size);

        static void PngLibraryFreeFunction(png_structp png_struct, 
            png_voidp ptr);
        
        Cb_ImageEncoded m_callback;

        void* m_callback_context;       
        
        png_structp m_png_ptr;
        png_infop m_info_ptr;

        png_bytep m_scanline[1];
    
        png_uint_32 m_width;
        png_uint_32 m_height;
        INT m_bits;
        INT m_bit_depth;
        Image::MetaData::ColorSpace m_color_format;

        static png_voidp m_huge_mem;
};

#endif  // Apoxi_PngEncoder_hpp

