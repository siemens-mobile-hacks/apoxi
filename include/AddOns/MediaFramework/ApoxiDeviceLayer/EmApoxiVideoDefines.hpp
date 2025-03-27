/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(EmApoxiVideoDefines_hpp)
#define EmApoxiVideoDefines_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include "EmApoxiDataTypes.hpp"

#define EMAPOXI_VGA_SIZE_X              640       // X size.
#define EMAPOXI_VGA_SIZE_Y              480       // Y size.
#define EMAPOXI_CIF_SIZE_X              352       // X size.
#define EMAPOXI_CIF_SIZE_Y              288       // Y size.
#define EMAPOXI_QVGA_SIZE_X             320       // X size.
#define EMAPOXI_QVGA_SIZE_Y             240       // Y size.
#define EMAPOXI_QCIF_SIZE_X             176       // X size.
#define EMAPOXI_QCIF_SIZE_Y             144       // Y size.
#define EMAPOXI_QQVGA_SIZE_X            160       // X size.
#define EMAPOXI_QQVGA_SIZE_Y            120       // Y size.
#define EMAPOXI_QQCIF_SIZE_X             88       // X size.
#define EMAPOXI_QQCIF_SIZE_Y             72       // Y size.
#define EMAPOXI_SQCIF_SIZE_X            128       // X size.
#define EMAPOXI_SQCIF_SIZE_Y             96       // Y size.
#define EMAPOXI_QSIF_SIZE_X             176       // X size.
#define EMAPOXI_QSIF_SIZE_Y             112       // Y size.
#define EMAPOXI_QSIFSP_SIZE_X           160       // X size.
#define EMAPOXI_QSIFSP_SIZE_Y           112       // Y size.


// Camera Brightness and Contrast Defines.
#define EMAPOXI_CAM_BRIGHTNESS_MAX      10
#define EMAPOXI_CAM_BRIGHTNESS_MIN      0
#define EMAPOXI_CAM_CONTRAST_MAX        10
#define EMAPOXI_CAM_CONTRAST_MIN        0

// LCD Contrast Defines.
#define EMAPOXI_LCD_CONTRAST_MAX        10
#define EMAPOXI_LCD_CONTRAST_MIN        0

typedef enum {
    EmApoxiCameraImageFormat_CIF        = 0,    //  GDD_CAM_CIF_FORMAT         = 0, 
    EmApoxiCameraImageFormat_QCIF       = 1,    //  GDD_CAM_QCIF_FORMAT        = 1,
    EmApoxiCameraImageFormat_QQCIF      = 2,    //  GDD_CAM_QQCIF_FORMAT       = 2,
    EmApoxiCameraImageFormat_VGA        = 3,    //  GDD_CAM_VGA_FORMAT         = 3,
    EmApoxiCameraImageFormat_QVGA       = 4,    //  GDD_CAM_QVGA_FORMAT        = 4,
    EmApoxiCameraImageFormat_QQVGA      = 5,    //  GDD_CAM_QQVGA_FORMAT       = 5,
    EmApoxiCameraImageFormat_SQCIF      = 6,    //  GDD_CAM_SQCIF_FORMAT       = 6,
    EmApoxiCameraImageFormat_QSIF       = 7,    //  GDD_CAM_QSIF_FORMAT        = 7,
    EmApoxiCameraImageFormat_QSIFSP     = 8,    //  GDD_CAM_QSIFSP_FORMAT      = 8,
    EmApoxiCameraImageFormat_Count      = 9     //  GDD_CAM_NOF_IMAGE_FORMATS  = 9
}tEmApoxiCameraImageFormat;

typedef enum {
    EmApoxiYUYVYUYV,    //  GDD_YUYVYUYV,
    EmApoxiRGB          //  GDD_RGB    
}tEmApoxiVideoDataFormat;

typedef enum {
    EmApoxiFPS_7_5,
    EmApoxiFPS_15
} tEmApoxiCameraFrameRate;

typedef enum {
    EmApoxiLCDParamsContrast,
    EmApoxiLCDParamsCount
}tEmApoxiLCDParams;

typedef enum {
    EmApoxiCameraParamsContrast,
    EmApoxiCameraParamsBrightness,
    EmApoxiCameraParamsNightMode,
    EmApoxiCameraParamsZoom,
    EmApoxiCameraParamsCount
}tEmApoxiCameraParams;

typedef void * tEmApoxiContext;

typedef struct {
    EmApoxiUINT16 left;
    EmApoxiUINT16 top;
    EmApoxiUINT16 right;
    EmApoxiUINT16 bottom;
} tEmApoxiVideoRect;

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiVideoDefines_hpp

