/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Camera_hpp)
#define Apoxi_Camera_hpp

#include <Devices/AbstractLockableDevice.hpp>
#include <Kernel/Types.hpp>
#include <Gui/Rect.hpp>

#define APOXI_CAMERA_TWINVIEWFINDER_SUPPORT

class Camera : public AbstractLockableDevice {
    typedef AbstractLockableDevice Base;
    
    public: 

        #include <Devices/CameraInterface.hpp>
    
    protected:
    
        virtual BOOLEAN& GetLock() {return m_lock[GetIndex()];}
        
        void SetState(CameraState camera_state);
        
        INT m_last_error;
        INT m_zoom_level;
        INT m_brightness_level;
        INT m_contrast_level;
        INT m_exposure_level;
        Rect m_rect;
        ImageSizeType m_capture_image_size;
        TransformationType m_capture_transformation;
        TransformationType m_view_image_transformation;
        FlashType m_flash;
        WhiteBalanceType m_white_balance;
        
        MeteringType m_metering_mode;
        
    private:

        static BOOLEAN m_lock[2];

        CameraState m_camera_state;
        INT m_display_idx;  // display index where the camera viewfinder should be displayed

#ifdef APOXI_CAMERA_TWINVIEWFINDER_SUPPORT
        typedef struct ViewfinderInfo {
            BOOLEAN set;
            Rect rect;
            TransformationType transformation;
            ScalingMethodType scaling;
        } ViewfinderInfo;
        
        BOOLEAN m_twinviewfinder_enabled;
        
        ViewfinderInfo m_viewfinder_info[2];
#endif
        AntiFlickerType m_antiflicker_mode;
        FilterType m_filter;
        
        ScalingMethodType m_scaling_method;
        TwilightType m_twilight_mode;

};

inline INT Camera::GetLastError() const
{
    return m_last_error;
}

inline INT Camera::GetDisplayIndex() const
{
    return m_display_idx;
}

#endif  // Apoxi_Camera_hpp


