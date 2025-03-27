/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_JpegEncoder_hpp)
#define Apoxi_JpegEncoder_hpp

class Threadlet;
class BinData;
class DataSink;

#include <AddOns/jpeglib/jpeglib.h>
#include <Gui/ImageEncoder.hpp>

class JpegEncoder : public ImageEncoder {
    typedef ImageEncoder Base;

    public:
        class EncodingParameters : public ImageEncoder::EncodingParameters {
            typedef ImageEncoder::EncodingParameters Base;

            public:
                enum EncodingFormat {
                    Yuv420,
                    Yuv422
                };

                EncodingParameters(XYDIM width,
                                   XYDIM height,
                                   INT quality_level,
                                   EncodingFormat encoding_format = Yuv422) :
                    Base(width, height),
                    m_quality_level(quality_level),
                    m_encoding_format(encoding_format)
                {};
            
                void SetQualityLevel(INT level) { m_quality_level = level; }
                
                INT GetQualityLevel() const { return m_quality_level; }
                
                void SetEncodingFormat(EncodingFormat format) { m_encoding_format = format; }

                EncodingFormat GetEncodingFormat() const { return m_encoding_format; }

                #if defined(APOXI_COMPAT_2_8_0)

                    enum ImageColorFormatType {
                        Rgb565Format,
                        Yuv420pFormat,
                        Yuv422iFormat
                    };

                    EncodingParameters(XYDIM width,
                                       XYDIM height,
                                       INT quality_level,
                                       ImageColorFormatType color_format) :
                        Base(width, height),
                        m_quality_level(quality_level),
                        m_encoding_format(Yuv422),
                        m_color_format(color_format)
                    {};

                    void SetColorFormat(ImageColorFormatType color_format) { m_color_format = color_format; }

                    ImageColorFormatType GetColorFormat() const { return m_color_format; }
                #endif // APOXI_COMPAT_2_8_0

            private:
                INT m_quality_level;
                EncodingFormat m_encoding_format;

                #if defined(APOXI_COMPAT_2_8_0)
                    ImageColorFormatType m_color_format;
                #endif
        };
        
        JpegEncoder(const EncodingParameters& param);

        virtual ~JpegEncoder();

        virtual BOOLEAN Encode(BinData& src,
                               const Image::MetaData& src_params,
                               DataSink& dest,
                               BOOLEAN block = TRUE,
                               void* context = 0,
                               Cb_ImageEncoded = 0
                               );

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
        BOOLEAN TraverseScanlines(BinData& src, JSAMPLE* buffer);

        BOOLEAN EncodeScanline(BinData& src, JSAMPLE* buffer);

        BOOLEAN InitEncoderLib(DataSink &dest);

        void CleanUp();

        void FreeJpeg();

        void SendCallback(DataSink& dest);

        void ConnectDataDestinationManager(j_compress_ptr cinfo, DataSink &sink);

        void SetErr(Error code, BOOLEAN cleanup = TRUE);

        struct ErrorMgr : public jpeg_error_mgr {
            static void ErrorExit(j_common_ptr cinfo);
            static void OutputMessage(j_common_ptr cinfo);

            // Jmp buffer for return to caller.
            jmp_buf setjmp_buffer;
        };

        struct DataDestinationMgr : public jpeg_destination_mgr {
            static void InitDestination(j_compress_ptr cinfo);
            static boolean EmptyOutputBuffer(j_compress_ptr cinfo);
            static void TermSource(j_compress_ptr cinfo);

            DataSink *m_destination;

            JOCTET *m_buffer;
        };

        
        Cb_ImageEncoded m_callback;

        void* m_callback_context;
        
        
        jpeg_compress_struct m_cinfo;

        JSAMPROW m_scanline[1];
    
        JDIMENSION m_width;
        JDIMENSION m_height;
        INT m_bits;
        JSAMPARRAY m_raw_data[3];

        INT m_scanline_idx;

        Image::MetaData::ColorSpace m_color_space;
        EncodingParameters::EncodingFormat m_encoding_format;

        ErrorMgr m_err_mgr;
};

#endif  // Apoxi_JpegEncoder_hpp


