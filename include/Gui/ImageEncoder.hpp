/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageEncoder_hpp)
#define Apoxi_ImageEncoder_hpp

#include <Auxiliary/BinData.hpp>
#include <Auxiliary/DataSink.hpp>
#include <Gui/Image.hpp>


class ImageEncoder {
    public:
        class EncodingParameters {
            public: 
                EncodingParameters(XYDIM width, XYDIM height) : m_width(width), m_height(height) {};
                void SetWidth(XYDIM width) { m_width = width; }
                XYDIM GetWidth() const { return m_width; }
                void SetHeight(XYDIM height) { m_height = height; }
                XYDIM GetHeight() const { return m_height; }

            private:
                XYDIM m_width;
                XYDIM m_height;
        };

        enum Error {
            NoError, 
            EncoderInitError, 
            FormatNotSupportedError, 
            OutOfMemoryError, 
            EncodingError,
            DataSinkClosedError,
            CouldNotAllocateThreadletError
        };

        typedef void (*Cb_ImageEncoded)(INT result, void* context, DataSink &dest); 
        
        ImageEncoder();

        virtual ~ImageEncoder();

        virtual BOOLEAN Encode(BinData& src,
                               const Image::MetaData& src_params,
                               DataSink& dest,
                               BOOLEAN block = TRUE,
                               void* context = 0,
                               Cb_ImageEncoded callback = 0) = 0;
        
        virtual BOOLEAN Encode(const Image& src, DataSink& dest, BOOLEAN block = TRUE) = 0;
        
        const EncodingParameters* GetEncodingParams() const { return m_params; }
    
        Error GetLastError() const { return m_last_error; }

        BOOLEAN IsEncoding() const { return m_is_encoding; }

        void StopEncoding(BOOLEAN block = TRUE);

    protected:
        virtual BOOLEAN BeginEncoding(DataSink& dest);
        
        virtual BOOLEAN EndEncoding(DataSink& dest);

        void SetEncodingParams(const EncodingParameters* params) { m_params = params; }

        void SetLastError(Error error) { m_last_error = error; }

        BOOLEAN IsStopEncodingRequested() const { return m_stop_encoding; }

        virtual BOOLEAN EncodeSynchronously(BinData& src,
                                            const Image::MetaData& src_params,
                                            DataSink& dest);

        virtual BOOLEAN EncodeSynchronously(const Image& img, DataSink& dest);

        BOOLEAN ExecuteThreadlet(Threadlet* threadlet, BOOLEAN block);

    private:
        BOOLEAN m_is_encoding;          // TRUE if a threadlet encodes an image
        BOOLEAN m_stop_encoding;        // TRUE if the threadlet should stop the decoding
        const EncodingParameters* m_params;
        Error m_last_error;

        static BOOLEAN m_initialized;
        static Semaphore m_sem;

        BOOLEAN InitSemaphore();

        friend class EncodingThreadlet; // accesses members m_is_encoding and m_stop_encoding
};


#endif // Apoxi_ImageEncoder_hpp


