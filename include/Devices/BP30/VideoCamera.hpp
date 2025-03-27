 /* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_VideoCamera_hpp)
#define Apoxi_VideoCamera_hpp

#include <Devices/BP30/Camera.hpp>

class VideoCamera : public Camera {
    typedef Camera Base;    

    public:
        #include <Devices/VideoCameraInterface.hpp>

    protected:

    private:
        // tbd: check whether signature of callbacks are equal to the GDD 2.2 ones
        static UINT8 HUGE* GetCaptureBuffer_GDD_CB(/*UINT8 HUGE ** buffer, UINT32 size*/);
        static void VideoFrameCaptured_GDD_CB(int result, UINT8 HUGE * buffer, UINT32 size, UINT32 stamp);
        static void NotifyCaptureBufferStatus_GDD_CB(void* context, UINT8 free_buffer_count);

        FrameRateType m_fps;
        
        static UINT32 m_starting_time;          // frame count or timestamp
        
        static UINT32 m_pool_handle;

        static Cb_NotifyCaptureBufferStatus m_cb_notify_status;
        static Cb_FrameCaptured m_cb_frame_captured;
};

inline VideoCamera::FrameRateType VideoCamera::GetFrameRate() const 
{
    return m_fps;
} 

#endif  // Apoxi_VideoCamera_hpp

