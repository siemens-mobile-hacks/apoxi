/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(EmApoxiVideoCaptureExp_hpp)
#define EmApoxiVideoCaptureExp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include "EmApoxiVideoDefines.hpp"

typedef void (*tEmApoxiFrameCapturedCallback)(EmApoxiINT ret, void* context,
                EmApoxiUINT8* buffer, EmApoxiUINT32 size, EmApoxiUINT32 stamp);

typedef void* (*tEmApoxiNotifyBufferStatus) (void *context, 
                                             EmApoxiUINT8 free_buffer_count);

enum EmApoxiTwilightType {
    EmApoxiTwilightOff,
    EmApoxiTwilightOn,
    EmApoxiTwilightAuto     
};

enum EmApoxiImageSizeType {
    EmApoxiQqcifSize,           // 88x72
    EmApoxiSqcifSize,           // 128x96
    EmApoxiQqvgaSize,           // 160x120
    EmApoxiQcifSize,            // 176x144
    EmApoxiQsifSize,            // 276x120
    EmApoxiQvgaSize,            // 320x240
    EmApoxiCifSize,         // 352x288      0,3 mp
    EmApoxiVgaSize,         // 640x480
    EmApoxiSvgaSize,            // 800x600
    EmApoxiXgaSize,         // 1024x768
    EmApoxiSize1Mp,         // 1152x864     1,0 mp 
    EmApoxiSize1_3Mp,           // 1280x960     1,3 mp
    EmApoxiSxgaSize,            // 1280x1024    1.3 mp
    EmApoxiUxgaSize,            // 1600x1200    2,0 mp
    EmApoxiSize2Mp,         // 1728x1152    2,0 mp
    EmApoxiSize3Mp,         // 2048x1536    3,0 mp
    EmApoxiEndOfImageSizeType
};

enum EmApoxiFrameRateType {
    EmApoxiFps3_7_5 = 0,
    EmApoxiFps5,
    EmApoxiFps7_5,
    EmApoxiFps10,
    EmApoxiFps12,
    EmApoxiFps15,
    EmApoxiFps24,
    EmApoxiFps25,
    EmApoxiFps30,
    EmApoxiEndOfFpsType
};

enum EmApoxiCameraError {
    EmApoxiNoError,
    EmApoxiCameraAlreadyLockedError,
    EmApoxiCameraNotReadyError,
    EmApoxiUnsupportedCameraFeature,
    EmApoxiCameraNotInitializedError,
    EmApoxiBufferNotAvailableError,
    EmApoxiBufferAllocationError,
    EmApoxiApplicationControlError,
    EmApoxiUnsupportedFrameRateError,
    EmApoxiInvalidCameraParameter,
    EmApoxiInvalidSizeError
};

enum EmApoxiCameraState {
    CameraStateIdle = 0,
    CameraStateViewFinding,
    CameraStateRecording,
    CameraStatePaused
};

enum EmApoxiActionType {
    EmApoxiDecrease,
    EmApoxiReset,
    EmApoxiIncrease
};

class VideoCamera;

class EmApoxiVideoCapturer
{
    public:
        EmApoxiVideoCapturer();
        
        ~EmApoxiVideoCapturer();
        EmApoxiBOOLEAN  Init(
                        EmApoxiFrameRateType    frame_rate,
                        EmApoxiImageSizeType    image_size,
                        tEmApoxiFrameCapturedCallback   fr_captured_cb,
                        tEmApoxiNotifyBufferStatus      ntfy_bf_status_cb,
                        EmApoxiUINT             num_bfrs,
                        tEmApoxiVideoRect       capture_rect,
                        tEmApoxiContext         context,
                        EmApoxiUINT             camera_device_id = 0);
        

        tEmApoxiFrameCapturedCallback   GetFrameCapturedCb() 
                                { return m_fp_frame_captured_callback; };           
        
        tEmApoxiNotifyBufferStatus   GetEmApoxiNotifyBufferStatusCb()
                                { return m_fp_notify_buffer_status; };      

        EmApoxiBOOLEAN EmApoxiEnableViewFinder();

        EmApoxiBOOLEAN EmApoxiDisableViewFinder();
        
        EmApoxiBOOLEAN EmApoxiEnableCapture();

        EmApoxiBOOLEAN EmApoxiDisableCapture();

        EmApoxiBOOLEAN EmApoxiPauseCapture();

        EmApoxiBOOLEAN EmApoxiVideoCaptureSetRect
                            (tEmApoxiVideoRect capture_rect);

        EmApoxiBOOLEAN EmApoxiVideoCaptureSetImageSize(
                            EmApoxiImageSizeType image_size);

        EmApoxiBOOLEAN EmApoxiVideoCaptureSetFrameRate
                            (EmApoxiFrameRateType frame_rate);

    
        EmApoxiBOOLEAN EmApoxiVideoCaptureSetBrightness(EmApoxiINT value);
        
        EmApoxiBOOLEAN EmApoxiVideoCaptureSetContrast(EmApoxiINT value);
        
        EmApoxiBOOLEAN EmApoxiVideoCaptureSetZoom(EmApoxiActionType action, 
                                        EmApoxiUINT8 step_size);
            EmApoxiBOOLEAN EmApoxiVideoCaptureSetTwilightMode
                                        (EmApoxiTwilightType twilight_mode);
    

        EmApoxiBOOLEAN ReleaseBuffer(EmApoxiUINT8 HUGE* buffer);

        void* GetContext(){return m_context;}
        

    private:
        
        /* Translation Functions for the Enums :

        The functions translate the EmApoxi Enums 
        (used by the capturer component) to 
        the enums of the Camera Device.
        */
        
        EmApoxiFrameRateType        m_frame_rate;
        EmApoxiImageSizeType        m_image_size;
        EmApoxiCameraState          m_state;
        EmApoxiUINT                 m_camera_device_id;
            
        tEmApoxiVideoRect               m_capture_rect;
        VideoCamera*                    m_p_video_camera;   
        tEmApoxiFrameCapturedCallback   m_fp_frame_captured_callback;
        tEmApoxiNotifyBufferStatus      m_fp_notify_buffer_status;
        void*                           m_context;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiVideoCaptureExp_hpp

