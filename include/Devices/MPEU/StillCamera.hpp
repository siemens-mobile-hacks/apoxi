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
#include <Devices/MPEU/Camera.hpp>
#include <AddOns/MultiMedia/JpegEncoder.hpp>

class RamData;

//send by m_cb_capture_finished()
#define STOPPED_NORMALLY            (0)
#define STOPPED_BY_USER_CANCEL      (1)
#define STOPPED_BY_NO_BUFFER_FOUND  (2)
#define STOPPED_BY_GDD_PROBLEM      (3)

//send by m_cb_image_captured()
#define IMAGE_CAPTURED_OK           (0)

//send by m_cb_image_encoded()
#define IMAGE_ENCODED_OK            (0)

class StillCamera : public Camera {
    
    typedef Camera Base;
    
    public:
        #include <Devices/StillCameraInterface.hpp>
        
        virtual BOOLEAN Close();

    protected:
        friend class CameraConfig;
            
    private:
    
        #define MAX_BUFFER_INFO_INDEX  (19)
    
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
        
            enum CallBackState {
            Nothing,
            CbGDDCaptureResult,
            CbJPEGImageEncoded          
        };
                
        typedef struct BufferInfoType {
                    BOOLEAN Use;
                    UINT16 PictNo;
                    CaptureState State;
                    UINT32 Buflen;
                    UINT8 HUGE* BufPtr;
                    RamData* RamDataPtr;
                    Image::MetaData* MetaDataPtr;
                    DataSink* TargetSinkPtr;
                } BufferInfoType; 
        
        UINT16 m_no_of_pictures;
        UINT16 m_picture_counter;
        INT m_jpeg_quality;
        BOOLEAN m_capture_in_use;
        DataSink* m_target_sink_ptr;
        INT       m_image_buffer_counter;   
            
        static CbImageCaptured m_cb_image_captured;
        static CbImageEncoded m_cb_image_encoded;
        static CbCaptureFinished m_cb_capture_finished;
        static void* m_context_appl;
        
        JpegEncoder::EncodingParameters* m_jpeg_encoder_param;
        JpegEncoder* m_jpeg_encoder;    
                    
        static UINT32  m_pool_handle;
        UINT8          m_frame_rate_subsampling;
        static BOOLEAN m_capture_canceled;
                static UINT32  m_jpeg_encoder_counter;
               
                BufferInfoType m_buffer_info[MAX_BUFFER_INFO_INDEX+1];
                UINT16         m_buffer_info_index;
        // callbacks
        // callback from GDD for still camera, where buffer for raw data will be passed to
        static void Cb_GDD_GetCaptureBuffer(void* context, UINT8 HUGE **buffer, UINT32 size);
        
        // callback from GDD where an image has been captured as RAW data in to buffer
        static void Cb_GDD_ImageCaptured    (INT result, void* context, UINT8 HUGE* captured_buffer, UINT32 size);

        // callback from GDD for the asynchronous result 
        static void Cb_GDD_CaptureResult(INT result, void* context);
        
        // callback from JpegEncoder, when an RAW data image has been encoded to JPEG
        static void Cb_JPEG_ImageEncoded    (INT result, void* context, DataSink& sink);
        
        BOOLEAN         DeleteOneImageBuffer(UINT8 HUGE* buff_ptr);
        BOOLEAN         DeleteOneMetaBuffer(Image::MetaData* MetaDataPtr);
        BOOLEAN         FreeImageBuffer();
        BOOLEAN         GetImageBuffer(UINT8 no_of_pictures, ImageSizeType size);
        BOOLEAN         Encode(BufferInfoType* bufferInfoPtr,UINT32 length);
        void            DeleteJpegSoftwareEncoder();
        void            DeleteJpegSoftwareEncoderCallBack(CallBackState state);
        BOOLEAN         SetJpegSoftwareEncoder(XYDIM width, XYDIM height, INT quality_level);
        BOOLEAN         IsMultiShot();
        BOOLEAN         GetOneImageBuffer(UINT8 HUGE **buffer);
        BufferInfoType* GetUsedImageBuffer(UINT8 HUGE* captured_buffer);
        BufferInfoType* GetUsedImageBuffer(DataSink* sink);
        BufferInfoType* GetNextImageBuffer(DataSink* sink);
        BOOLEAN         DeleteAllUsedImageBuffer();
        BOOLEAN         ResetAllBufferInfo(UINT16 MaxNumber,DataSink** sink_ptr);
        UINT16          GetNofEncodeImages();
        static  void    SetCancleFlag(BOOLEAN capture_cancled);
        static  BOOLEAN GetCancleFlag();

                typedef void (*Cb_JpegEncoded)(INT result, void* context, DataSink* dest);   
};

#endif  // Apoxi_StillCamera_hpp

