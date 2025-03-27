 /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StillCamera_hpp)
#define Apoxi_StillCamera_hpp

#include <Devices/Win32/Camera.hpp>
#include <AddOns/MultiMedia/JpegEncoder.hpp>

class DataSink;

class StillCamera : public Camera {
    typedef Camera Base;

    public: 
    
        #include <Devices/StillCameraInterface.hpp>
        
        virtual BOOLEAN Open();
        
        virtual BOOLEAN Close();

    protected:      

    private:
    
        INT m_jpeg_quality;

        JpegEncoder* m_encoder;
        JpegEncoder::EncodingParameters* m_encoding_params;
        Image::MetaData m_source_prop;
                
        CbImageCaptured     m_cb_image_captured;
        CbImageEncoded      m_cb_image_encoded;
        CbCaptureFinished   m_cb_capture_finished;

        void* m_app_context;
        
        // callbacks
        // callback for still camera, where buffer for raw data will be passed to
        static void Cb_GDD_GetCaptureBuffer(void* context, UINT8 HUGE **buffer, UINT32 size);
        
        // callback where an image has been captured as RAW data in to buffer
        static void Cb_GDD_ImageCaptured(INT, void* context, UINT8 HUGE* captured_buffer, UINT32 size);
        
        // callback from JpegEncoder, when an RAW data image has been encoded to JPEG
        static void Cb_ImageEncoded(INT, void* context, DataSink& sink);    
};

inline INT StillCamera::GetJpegQuality() const 
{
    return m_jpeg_quality;
}

#endif  // Apoxi_StillCamera_hpp

