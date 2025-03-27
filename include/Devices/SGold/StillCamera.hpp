 /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StillCamera_hpp)
#define Apoxi_StillCamera_hpp

#include <Devices/StillCamera.hpp>
#include <Auxiliary/DataSink.hpp>
#include <AddOns/MultiMedia/JpegEncoder.hpp>


class StillCamera : public AbstractStillCamera {
    
    typedef AbstractStillCamera Base;
    
    public:
        APOXI_PUBLIC_INTERFACE_STILLCAMERA
        
    protected:
        
        
    private:
        FlashType               m_flash;    
        UINT16                  m_no_of_pictures;
        INT                     m_jpeg_quality;
                
        static CbImageCaptured    m_cb_image_captured;
        static CbImageEncoded     m_cb_image_encoded;
        static CbCaptureFinished  m_cb_capture_finished;
        
        JpegEncoder::EncodingParameters* m_JpegEncoderParam;
        JpegEncoder*            m_JpegEncoder;  
                    
        static  UINT32          m_pool_handle;

        // callbacks
        // callback from GDD for still camera, where buffer for raw data will be passed to
        static void Cb_GDD_GetCaptureBuffer(void* context, UINT8 HUGE **buffer, UINT32 size);
        
        // callback from GDD where an image has been captured as RAW data in to buffer
        static void Cb_GDD_ImageCaptured(int result, void* context, UINT8 HUGE* captured_buffer, UINT32 size);

        // callback from GDD for the asynchronous result 
        static void Cb_GDD_CaptureResult(INT result, void* context);
        
        // callback from JpegEncoder, when an RAW data image has been encoded to JPEG
        static void Cb_JPEG_ImageEncoded(INT result, void* context, UINT8 HUGE *source, DataSinkPtr sink);
        
        BOOLEAN DeleteOneImageBuffer(UINT8 HUGE* buff_ptr);
        BOOLEAN FreeImageBuffer();
        BOOLEAN GetImageBuffer(UINT8 no_of_pictures, ImageSizeType size);
        BOOLEAN Encode();
        void    DeleteJpegSoftwareEncoder();
        BOOLEAN SetJpegSoftwareEncoder(XYDIM width, XYDIM height, INT quality_level);
#ifdef APOXI_GDD_2_0_INTERFACE
        BOOLEAN GetCameraImageSize(ImageSizeType size, gdd_image_size_format_type& gdd_image_size);
#endif      
};

#endif  // Apoxi_StillCamera_hpp

