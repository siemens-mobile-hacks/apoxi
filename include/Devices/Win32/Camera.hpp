/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_Win32_Camera_hpp)
#define Apoxi_Devices_Win32_Camera_hpp


#include <Devices/AbstractLockableDevice.hpp>
#include <Gui/Size.hpp>
#include <Gui/Rect.hpp>

class CamWin32;

class Camera : public AbstractLockableDevice {
    typedef AbstractLockableDevice Base;

    #include <Devices/CameraInterface.hpp>
    
    protected:
        INT m_last_error;
        INT m_zoom_level;
        INT m_brightness_level;
        INT m_contrast_level;
        Rect m_rect;    // the current viewfinder rectangle
        ImageSizeType m_capture_image_size;

        CamWin32* m_cam_win32;

        virtual BOOLEAN& GetLock() { return m_lock[GetIndex()]; }

        void SetState(CameraState state) {m_state = (CameraState)state; }
        
    private:
        static BOOLEAN m_lock[2];
        CameraState m_state;
        INT m_display_idx;  // display index where the camera viewfinder should be displayed
        
        AntiFlickerType m_antiflicker_mode;
        FilterType m_filter;
        TransformationType m_capture_transformation;
        ScalingMethodType m_scaling_method;
        TwilightType m_twilight_mode;
        FlashType m_flash;
        WhiteBalanceType m_white_balance;
        

};

inline Camera::CameraState Camera::GetState() const 
{
    return m_state;
}


inline INT Camera::GetDisplayIndex() const
{
    return m_display_idx;
} 


inline INT Camera::GetLastError() const
{
    return m_last_error;
} 

#endif  // Apoxi_Devices_Win32_Camera_hpp


