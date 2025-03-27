 /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_VideoCamera_hpp)
#define Apoxi_VideoCamera_hpp

#include <Kernel/System.hpp>
#include <Kernel/Types.hpp>
#include <Devices/MPEU/Camera.hpp>

class VideoCamera : public Camera {
    typedef Camera Base;    

    public:
        #include <Devices/VideoCameraInterface.hpp>
                
    protected:
        friend class CameraConfig;
        
    private:

        static void GetCaptureBuffer_GDD_CB(void*, UINT8 HUGE ** buffer, UINT32 size);
        
        static void VideoFrameCaptured_GDD_CB(int result, void* context, UINT8 HUGE * buffer, UINT32 buf_len_used);
        
        static void NotifyCaptureBufferStatus_GDD_CB(void* context, UINT8 free_buffer_count);

        FrameRateType m_framerate;
        
        static UINT32 m_buffer_length;
        
        static UINT32 m_starting_time;          // frame count or timestamp
        
        static UINT32 m_pool_handle;
        
        static void* m_context;

        static Cb_NotifyCaptureBufferStatus m_cb_notify_status;
        static Cb_FrameCaptured m_cb_frame_captured;
        static Cb_VideoCaptureStopped m_cb_video_capture_stopped;
        static Cb_VideoCapturePaused m_cb_video_capture_paused;
};

#endif  // Apoxi_VideoCamera_hpp

