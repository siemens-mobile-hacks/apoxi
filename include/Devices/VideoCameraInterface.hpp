/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class VideoCamera {
#endif
    public:
    enum FrameRateType {
        Fps3_7_5 = 0,
        Fps5,
        Fps7_5,
        Fps10,
        Fps12,
        Fps15,
        Fps24,
        Fps25,
        Fps30,
        EndOfFpsType
    };

    enum BufferLocation {
        HostLocation,
        CompanionLocation
    };

    typedef void (*Cb_FrameCaptured)(INT ret, void* context, 
                                     UINT8 HUGE* buf, UINT32 size, UINT32 stamp);

        typedef void (*Cb_NotifyCaptureBufferStatus)(void* context, UINT8 free_buffer_count);
        
        typedef void (*Cb_VideoCaptureStopped)(INT ret, void* context);
        
        typedef void (*Cb_VideoCapturePaused)(INT ret, void* context);
    VideoCamera(INT device_id); 
    
    virtual ~VideoCamera(); 
    
    
    
    virtual const WCHAR* GetName() const; 
    
        virtual BOOLEAN Open(); 
    
    
    BOOLEAN SetFrameRate(FrameRateType frame_rate); 
    
    FrameRateType GetFrameRate() const; 
    
    BOOLEAN GetSupportedFrameRates(const FrameRateType* &array, UINT8& count) const; 
    
#if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetImageSize(ImageSizeType size); 
#endif  // #if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetCaptureImageSize(ImageSizeType capture_image_size,
                                            TransformationType capture_transformation 
                                                                = Camera::NoTransformation);
        
    virtual BOOLEAN GetSupportedImageSizes(const ImageSizeType* &array, UINT8& count) const; 
    
        BOOLEAN ReleaseCaptureBuffer(UINT8 HUGE* buf); 
        
#if defined(APOXI_COMPAT_2_8_0) 

        BOOLEAN AllocateCaptureBuffers(UINT32& handle,
                                       UINT8& buf_count, 
                                       UINT32 buf_len = 0, 
                                       BufferLocation buf_location = HostLocation); 
#endif  // #if defined(APOXI_COMPAT_2_8_0)
        
        BOOLEAN AllocateCaptureBuffers(UINT8& buf_count,
                                       UINT32 buf_len = 0);
        
    BOOLEAN FreeCaptureBuffers(); 
    
    virtual BOOLEAN StartViewfinder(/*BOOLEAN block = TRUE*/); 
    
    BOOLEAN StartVideoCapture(void* context, 
                              Cb_FrameCaptured cb_frame_captured, 
                              Cb_NotifyCaptureBufferStatus cb_notify_captbuf_status, 
                              UINT32 starting_time = 0); 
    
        BOOLEAN StopVideoCapture(Cb_VideoCaptureStopped cb_video_capture_stopped = 0,
                                    void* context = 0);
        
        BOOLEAN PauseVideoCapture(Cb_VideoCapturePaused cb_video_capture_paused = 0,
                                  void* context = 0);
        
        BOOLEAN UnPauseVideoCapture(UINT32 new_video_capture_clock_time);

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

