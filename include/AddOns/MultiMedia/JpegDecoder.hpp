/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_JpegDecoder_hpp)
#define Apoxi_JpegDecoder_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS


#include <AddOns/jpeglib/jpeglib.h>

class BinData;

class JpegDecoder {
    public:
        enum Error {
            NoError, 
            DecoderInitError, 
            ProgressiveJpegNotSupportedError, 
            OutOfMemoryError, 
            DecodingError
        };

    protected:
        JpegDecoder();
        virtual ~JpegDecoder();

    public:
        static JpegDecoder* GetInstance();

        /*  TODO: rename this method in future releases. No releasing
            is done, just a cleanup of the decoder. */
        void ReleaseInstance();

        BOOLEAN Attach(const BinData &data);

        INT GetWidth() const;
        INT GetHeight() const;

        BOOLEAN BeginDecoding(const BinData &data);

        BOOLEAN DecodeNextScanline();

        void InitPixelColorAccess();

        Color GetNextPixelColor();

        const UINT8* GetScanline() const {return (UINT8*)m_scanline[0];}
        
        void EndDecoding();

        Error GetLastError() const;

    protected:
        void ConnectDataSourceManager(j_decompress_ptr cinfo, 
            const BinData &data);

        void CleanUp();

        BOOLEAN InitDecoderLib(const BinData &data);
        void FreeJpeg();
        void SetErr(Error code, BOOLEAN cleanup = TRUE);

    protected:
        struct ErrorMgr : public jpeg_error_mgr {
            static void ErrorExit(j_common_ptr cinfo);
            static void OutputMessage(j_common_ptr cinfo);

            // Jmp buffer for return to caller.
            jmp_buf setjmp_buffer;
        };

        struct BinDataSourceMgr : public jpeg_source_mgr {
            static void InitSource(j_decompress_ptr cinfo);
            static boolean FillInputBuffer(j_decompress_ptr cinfo);
            static void SkipInputData(j_decompress_ptr cinfo, long num_bytes);
            static void TermSource(j_decompress_ptr cinfo);
            
            const BinData *m_data;
            UINT32 m_data_idx;
            JOCTET *m_buffer;
        };

    protected:
        BOOLEAN m_optimize_for_16bpp;

        jpeg_decompress_struct m_dinfo;
        ErrorMgr m_err_mgr;
        JSAMPARRAY m_scanline;
        JDIMENSION m_width;
        JDIMENSION m_height;

        INT m_scanline_idx;

        Error m_last_error;

        static JpegDecoder *c_decoder;
        static BOOLEAN c_sem_created;
        static Semaphore c_sem;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_JpegDecoder_hpp


