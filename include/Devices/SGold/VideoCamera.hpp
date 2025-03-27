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
#include <Devices/VideoCamera.hpp>

class VideoCamera : public AbstractVideoCamera 
{
    typedef AbstractVideoCamera Base;   

    public:

        APOXI_PUBLIC_INTERFACE_VIDEOCAMERA

    protected:

        
    private:

        // ToDo: check whether signature of callbacks are equal to the GDD 2.2 ones
        static void GetCaptureBuffer_GDD_CB(void*, UINT8 HUGE ** buffer, UINT32 size);
        static void VideoFrameCaptured_GDD_CB(int result, void* context, UINT8 HUGE * buffer, UINT32 buf_len_used);
        static void NotifyCaptureBufferStatus_GDD_CB(void* context, UINT8 free_buffer_count);

        FrameRateType m_framerate;
        
        static UINT32 m_buffer_length;
        
        static UINT32 m_starting_time;          // frame count or timestamp
        
        static UINT32 m_pool_handle;

        static Cb_NotifyCaptureBufferStatus m_cb_notify_status;
        static Cb_FrameCaptured m_cb_frame_captured;
};

#endif  // Apoxi_VideoCamera_hpp

