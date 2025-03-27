/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiVideoRendererExp_hpp)
#define EmApoxiVideoRendererExp_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiVideoDefines.hpp"

typedef void* EmApoxiVideoRendererHandle;
typedef void (*tFrameRenderCallback)(EmApoxiUINT32 aResultCode,void *aContext,EmApoxiUINT8* aSrc);
typedef void (*tCallback)(EmApoxiUINT32 aResultCode);

EmApoxiVideoRendererHandle EmApoxiVideoRendererCreate(  
                    tEmApoxiVideoRect       display_rect,
                    tEmApoxiVideoDataFormat video_data_format,
                    tEmApoxiCameraImageFormat       image_format,
                    tEmApoxiContext         context,
                    tFrameRenderCallback    fp_frame_render_callback );

void EmApoxiVideoRendererDelete(
                    EmApoxiVideoRendererHandle video_renderer);

EmApoxiBOOLEAN EmApoxiVideoRendererEnable(
                    EmApoxiVideoRendererHandle video_renderer);

EmApoxiBOOLEAN EmApoxiVideoRendererDisable(
                    EmApoxiVideoRendererHandle video_renderer);

EmApoxiBOOLEAN EmApoxiVideoRendererSetImageFormat(
                    EmApoxiVideoRendererHandle video_renderer,
                    tEmApoxiCameraImageFormat image_format );

EmApoxiBOOLEAN EmApoxiVideoRendererSetRectangle(
                    EmApoxiVideoRendererHandle video_renderer,
                    tEmApoxiVideoRect display_rect );

EmApoxiBOOLEAN EmApoxiVideoRendererRenderFrame(
                    EmApoxiVideoRendererHandle video_renderer,
                    EmApoxiUINT8* p_frame_buffer,
                    EmApoxiUINT32 buffer_length);

EmApoxiUINT32 EmApoxiVideoRendererSetLCDParams (
                    EmApoxiVideoRendererHandle video_renderer,
                    tEmApoxiLCDParams   lcd_param,
                    EmApoxiUINT32       param_value );

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiVideoRendererExp_hpp

