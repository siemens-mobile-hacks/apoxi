/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SampleImages_hpp)
#define Apoxi_SampleImages_hpp

const UINT devil_size = 61;
const UINT wow_size = 64;
const UINT kissing_size = 61;
const UINT HUGE gif_image_size = 1851;
const UINT HUGE jpeg_image_size = 16035;
const UINT HUGE png_image_size = 978;

extern UINT8 devil[devil_size];
extern UINT8 wow[wow_size];
extern UINT8 kissing[kissing_size];
extern UINT8 HUGE gif_image[gif_image_size];
extern UINT8 HUGE jpeg_image[jpeg_image_size];
extern UINT8 HUGE png_image[png_image_size];

extern UINT8 g_drm_fl_res2_data[2363];
extern UINT8 g_drm_cd_j1k_data[1936];
extern UINT8 g_drm_cd_res2_data[2716];


#endif  // Apoxi_SampleImages_hpp
