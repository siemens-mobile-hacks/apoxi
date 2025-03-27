/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_VideoChannel_hpp)
#define Apoxi_VideoChannel_hpp


#include <Kernel/Types.hpp>
#include <Gui/Rect.hpp>

class VideoChannel {
    public:
        enum VideoParameterType {
            Rotate,
            Mirror,
            Flip,
            Antitearing,
            SmartOverlay,
            ZoomFactorMin,
            ZoomFactorMax
        };      

        VideoChannel(INT display_idx = 0);

        ~VideoChannel();

        BOOLEAN Open(Rect& video_frame_rect, void (*CbVideoFrameRendered)(), void* context = 0);


        void Close();

        void RenderFrame(void* frame_buffer, UINT32 length, UINT32 frame_id, BOOLEAN auto_skip_frame = FALSE);
    

        BOOLEAN IsOpen() const;
    
        UINT32 GetRefreshDelay() const;
        
        BOOLEAN SetParam(VideoParameterType type, UINT32 value);

        BOOLEAN GetParam(VideoParameterType type, UINT32* value) const;

#ifdef APOXI_COMPAT_2_6_0
        void SetSize(Size video_size) {SetVideoSize(video_size);}
#endif
        void SetVideoSize(Size video_size);

        BOOLEAN SetCropRect(Rect& crop_rect);

#ifdef APOXI_COMPAT_2_6_0
        BOOLEAN AdjustFrameRect(Rect& video_frame_rect) {SetFrameRect(video_frame_rect);}
#endif
        BOOLEAN SetFrameRect(Rect& video_frame_rect);
        
        BOOLEAN QueryRects(Rect& video_frame_rect, Rect& crop_rect);

    private:
        Rect m_video_frame_rect;
        const DDrvAtomPtr m_video_frame_buffer;
};      

#endif  // Apoxi_VideoChannel_hpp


