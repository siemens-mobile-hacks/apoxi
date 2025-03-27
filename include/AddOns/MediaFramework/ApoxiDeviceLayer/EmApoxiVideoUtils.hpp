/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiVideoUtils_hpp)
#define EmApoxiVideoUtils_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include "EmApoxiVideoDefines.hpp"
#include "EmApoxiVideoCaptureExp.hpp"

/*
********************IMPORTANT*********************************************
This EmApoxiLayer HPP should not be included by any of the 
components as it has VideoCamera's enums.
**************************************************************************
*/

gdd_cam_image_format_type GDDCameraImageFormatType (
                        tEmApoxiCameraImageFormat cam_image_format );

gdd_video_data_format_type GDDVideoDataFormatType (
                        tEmApoxiVideoDataFormat video_data_format);

gdd_cam_fps_type GDDCameraFrameRate (
                        tEmApoxiCameraFrameRate camera_frame_rate);

Camera::TwilightType EmApoxiTranslate(EmApoxiTwilightType twilight_mode);
Camera::ImageSizeType EmApoxiTranslate(EmApoxiImageSizeType image_size);
VideoCamera::CameraError EmApoxiTranslate(EmApoxiCameraError camera_error);
VideoCamera::ActionType EmApoxiTranslate(EmApoxiActionType action_type);
VideoCamera::FrameRateType EmApoxiTranslate(EmApoxiFrameRateType frame_rate);


#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiVideoUtils_hpp

