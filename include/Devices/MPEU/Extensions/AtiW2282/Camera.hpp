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
#include <Kernel/System.hpp>
#include <Kernel/Types.hpp>
#include <Gui/Rect.hpp>

// GDD include
#ifdef APOXI_RTOS_WIN32
    #ifdef APOXI_ATI_SUPPORT
        extern "C" {
            #include <gdd.h>
        };
    #endif // #ifdef APOXI_ATI_SUPPORT
#endif

class Camera : public AbstractLockableDevice {
    typedef AbstractLockableDevice Base;

    public:
        #include <Devices/CameraInterface.hpp>

    protected:

        virtual BOOLEAN& GetLock() {return m_lock[GetIndex()];}
        INT GetZoom();
        UINT16 CalcCameraScalingRate(ImageSizeType imageType, INT device_zoom_level);

        void SetState(CameraState camera_state);

        INT m_last_error;
        INT m_zoom_level;
        INT m_brightness_level;
        INT m_contrast_level;
        Rect m_rect;
        ImageSizeType m_capture_image_size;
        TransformationType m_capture_transformation;
        TransformationType m_view_image_transformation;

    private:

        typedef struct ParameterStruct {
                    INT min;
                    INT def;
                    INT max;
                    INT step;
                } ParameterStruct;


                enum ParameterType {
                    BrightnessParameter = 0,
                    ContrastParameter
                };

        static BOOLEAN m_lock[2];

        CameraState m_camera_state;
        INT m_display_idx;  // display index where the camera viewfinder should be displayed

        AntiFlickerType m_antiflicker_mode;
        FilterType m_filter;

        ScalingMethodType m_scaling_method;
        TwilightType m_twilight_mode;

        ParameterStruct m_DeviceParameterLimits[2];
        ParameterLimits m_CameraParameterLimits[2];
        
        FlashType m_flash;

        void ConvertCameraToDeviceLimits(ParameterType type);
        void StoreCameraParameterLimits(ParameterType type, gdd_limits_type limits);
        INT CalcCameraValue(ParameterType type, INT deviceValue);
        BOOLEAN CheckDeviceBrightnessContrastLevel(ParameterType type, INT val);
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


