/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Mmi_CameraSettings_hpp)
#define Mmi_CameraSettings_hpp

/*  
    This class exists only to provide an interface with the Apoxi/StillCamera class.

    This allows us to put the functionality in another class without having to clutter 
    up the CameraApp class. All functions directly/indirectly call the interfaces provided
    by CameraInterface.hpp file. As a result, all the functions of this class are public.

    There is one member variable that is aa reference to the StillCamera class. This is because
    it would be easier to store the reference once than to make function calls to retrieve the 
    reference (either from CameraApp or from DeviceManager) everytime it has to be used.
*/
class CameraSettings 
{
    
public:
    
    //Not really needed, just for debug info
    CameraSettings();

    //Not really needed, but just there for completeness
    ~CameraSettings();

    BOOLEAN                 Init(StillCamera* stillcamera_ref, UINT8 display_idx);

    BOOLEAN                 SetBrightness(INT brightness);
    INT                     GetBrightness() const;

    BOOLEAN                 SetContrast(INT contrast);
    INT                     GetContrast() const;

    BOOLEAN                 SetZoom(Camera::ActionType zoom);
    INT                     GetZoom() const;    //Not supported by Apoxi yet

    BOOLEAN                 SetImageSize(Camera::ImageSizeType size);
    Camera::ImageSizeType   GetImageSize() const;

    BOOLEAN                 SetFlash(StillCamera::FlashType flash);
    StillCamera::FlashType      GetFlash() const;
    
    BOOLEAN                 SetAntiFlicker(Camera::AntiFlickerType antiflicker);
    Camera::AntiFlickerType GetAntiFlicker() const;

    BOOLEAN                 SetWhiteBalance(Camera::WhiteBalanceType wb);
    //WhiteBalanceType      GetWhiteBalance();  //Not supported by the interface right now
  
    BOOLEAN                 SetTwilight(Camera::TwilightType twilight);
    Camera::TwilightType        GetTwilight() const;
    
     BOOLEAN                SetJPEGQuality(INT quality);
     INT                                GetJPEGQuality() const;

     BOOLEAN                    SetTransformation(Camera::TransformationType transType);
     Camera::TransformationType GetTransformation() const; 

     BOOLEAN                SetFilter(Camera::FilterType filter);
     Camera::FilterType     GetFilter() const;



private:
    StillCamera*    m_camera_ref;
    INT             m_zoom_level;
    UINT8           m_display_idx;
};


#endif

