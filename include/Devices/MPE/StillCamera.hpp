 /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StillCamera_hpp)
#define Apoxi_StillCamera_hpp

#include <Auxiliary/DataSink.hpp>
#include <Devices/MPE/Camera.hpp>
#include <AddOns/MultiMedia/JpegEncoder.hpp>

class RamData;

class StillCamera : public Camera {
    
    typedef Camera Base;
    
    public:
        #include <Devices/StillCameraInterface.hpp>
        
        virtual BOOLEAN Open();
    
        virtual BOOLEAN Close();

        
    protected:
        friend class CameraConfig;
            
        
    private:
    
        #define MAX_BUFFER_INFO_INDEX  20
    
        enum CaptureState {
            Init,
            StartRunning,
            GetCaptureBuffer,
            ImageCaptured,
            ImageEncodingBegin,
            ImageEncoded,
            ErrorGetCaptureBuffer,
            ErrorImageCaptured,
            ErrorImageEncoded           
        };
        
/*      enum CallBackState {
            Nothing,
            CbGDDCaptureResult,
            CbJPEGImageEncoded          
        };
*/              
        typedef struct BufferInfoType {
            INT picture_number;
            CaptureState state;
//          UINT32 length;
            UINT8 HUGE* capture_buffer;
            DataSink* data_sink;
            JpegEncoder* encoder;
        } BufferInfoType; 
        
        
        BOOLEAN m_capture_in_use;
        INT m_jpeg_quality;
        INT m_picture_count;

            
        static CbImageCaptured m_cb_image_captured;
        static CbImageEncoded m_cb_image_encoded;
        static CbCaptureFinished m_cb_capture_finished;
        
        static void* m_app_context;
        static BOOLEAN m_cancel_capture;
        static UINT32 m_pool_handle;
        static INT m_pool_index;
        
        JpegEncoder::EncodingParameters* m_encoding_params;
        Image::MetaData m_meta_data;
                    
        BufferInfoType m_buffer_info[MAX_BUFFER_INFO_INDEX];

        // callbacks
        // callback from GDD for still camera, where buffer for raw data will be passed to
        static void Cb_GDD_GetCaptureBuffer(void* context, UINT8 HUGE **buffer, UINT32 size);
        
        // callback from GDD where an image has been captured as RAW data in to buffer
        static void Cb_GDD_ImageCaptured(INT result, void* context, UINT8 HUGE* captured_buffer, UINT32 size);

        // callback from GDD for the asynchronous result 
        static void Cb_GDD_CaptureResult(INT result, void* context);
        
        // callback from JpegEncoder, when an RAW data image has been encoded to JPEG
        static void Cb_JPEG_ImageEncoded(INT result, void* context, DataSink& sink);
        
        BOOLEAN         FreeImageBuffer();
        BOOLEAN         GetImageBuffer(UINT8 no_of_pictures, ImageSizeType size);

        BOOLEAN         Encode(BufferInfoType* bufferInfoPtr,UINT32 length);


        BufferInfoType* GetUsedImageBuffer(UINT8 HUGE* captured_buffer);
        BufferInfoType* GetUsedImageBuffer(DataSink* sink);
        BufferInfoType* GetNextImageBuffer(DataSink* sink);

        void ResetBufferInfo();
        INT GetEncodedPictureCount() const;

};

#endif  // Apoxi_StillCamera_hpp

