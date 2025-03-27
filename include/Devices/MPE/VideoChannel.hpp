/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_Devices_MPE_VideoChannel_hpp)
#define Apoxi_Devices_MPE_VideoChannel_hpp


#include <Kernel/Types.hpp>
#include <Gui/Rect.hpp>

class VideoChannel {

    public:

#ifdef APOXI_COMPAT_2_8_0

        enum VideoParameterType {
            Rotate,
            Mirror,
            Flip,
            Antitearing,
            SmartOverlays,
            YuvToRgbConversion,
            ZoomFactorHorizontalMin,
            ZoomFactorHorizontalMax,
            ZoomFactorVerticalMin,
            ZoomFactorVerticalMax
        };
#endif // APOXI_COMPAT_2_8_0

        enum TransformationType {
            NoTransformation,
            Rotation90Transformation,
            Rotation180Transformation,
            Rotation270Transformation,
            MirrorTransformation,
            MirrorRotate90Transformation,
            MirrorRotate180Transformation,  // same as flip
            MirrorRotate270Transformation
        };

        enum ScalingMethodType {
            NoScaling,
            LetterboxScaling,
            BestFitScaling
        };

        enum VideoAndViewfinderOrderType {
            ViewfinderOverVideoPlayback,
            VideoPlaybackOverViewfinder
        };

        typedef void (*CbResult)(   BOOLEAN result,
                                    void* context);

#ifdef APOXI_COMPAT_2_8_0

        typedef void (*CbVideoFrameRendered)(INT result,
                                            void* context,
                                            const UINT8 HUGE* frame_buf);

        typedef void (*CbVideoFrameRenderedNew)(BOOLEAN result,
                                            void* context,
                                            const UINT8 HUGE* frame_buf);
#else // APOXI_COMPAT_2_8_0

        typedef void (*CbVideoFrameRendered)(BOOLEAN result,
                                            void* context,
                                            const UINT8 HUGE* frame_buf);
#endif // APOXI_COMPAT_2_8_0

        VideoChannel(INT display_idx = 0);

        ~VideoChannel();

#ifdef APOXI_COMPAT_2_8_0

        BOOLEAN Open(Rect& video_frame_rect, CbVideoFrameRendered cb_frame_rendered, void* context = 0);

        BOOLEAN Open(CbVideoFrameRenderedNew cb_frame_rendered, void* context);
#else // APOXI_COMPAT_2_8_0

        BOOLEAN Open(CbVideoFrameRendered cb_frame_rendered, void* context);
#endif // APOXI_COMPAT_2_8_0

        void Close();

        BOOLEAN Start(CbResult cb_video_channel_started, void* context);

        BOOLEAN Stop(CbResult cb_video_channel_stopped, void* context);

        void RenderFrame(void* frame_buf, UINT32 length, UINT32 timestamp, BOOLEAN auto_release_frame = FALSE);

        BOOLEAN IsOpen() const;

        UINT32 GetRefreshDelay() const;

#ifdef APOXI_COMPAT_2_8_0

        BOOLEAN SetParam(VideoParameterType type, UINT32 value);

        BOOLEAN GetParam(VideoParameterType type, UINT32* value) const;
#endif // APOXI_COMPAT_2_8_0

#ifdef APOXI_COMPAT_2_6_0

        void SetSize(Size video_size)
        {
        #ifdef APOXI_COMPAT_2_8_0
            SetVideoSize(video_size);
        #endif //  APOXI_COMPAT_2_8_0
        }
#endif // APOXI_COMPAT_2_6_0

#ifdef APOXI_COMPAT_2_8_0

        void SetVideoSize(Size video_size);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetVideoSize(   Size actual_video_size,
                                Size extended_video_size,
                                Point left_top_offset);

#ifdef APOXI_COMPAT_2_8_0

        BOOLEAN SetCropRect(Rect& crop_rect);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetCropRect(Rect& crop_rect, Rect& effective_playback_rect);

#ifdef APOXI_COMPAT_2_6_0

        BOOLEAN AdjustFrameRect(Rect& video_frame_rect)
        {
        #ifdef APOXI_COMPAT_2_8_0
            return SetFrameRect(video_frame_rect);
        #else
            return FALSE;
        #endif //  APOXI_COMPAT_2_8_0
        }
#endif // APOXI_COMPAT_2_6_0

#ifdef APOXI_COMPAT_2_8_0

        BOOLEAN SetFrameRect(Rect& video_frame_rect);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetPlaybackRect(Rect& playback_rect,
                                TransformationType playback_transformation,
                                ScalingMethodType scaling_method);

#ifdef APOXI_COMPAT_2_8_0

        BOOLEAN QueryRects(Rect& video_frame_rect, Rect& crop_rect);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetPlaybackAndViewfinderOrder(
                            VideoAndViewfinderOrderType video_viewfinder_order);

    private:

        enum StateType {
            IdleState = 0, 
            OpeningState,
            OpenState,
            StartingState,
            StartedState,
            StoppingState,
            ClosingState
        };

        struct StateFlags {
            UINT m_state                        :3; 
            UINT m_video_size_set               :1; 
            UINT m_playback_rect_set            :1; 
        };

        static void CbNotifyVideoFrameRendered( INT result,
                                                void *context,
                                                UINT8 * frame_buf);
        static void CbNotifyStarted(INT result, void* context);
        static void CbNotifyStopped(INT result, void* context);

#ifdef APOXI_COMPAT_2_8_0
        CbVideoFrameRenderedNew m_cb_video_frame_rendered;
#else // APOXI_COMPAT_2_8_0
        CbVideoFrameRendered m_cb_video_frame_rendered;
#endif // APOXI_COMPAT_2_8_0
        CbResult                m_cb_stopped;
        CbResult                m_cb_started;

        INT                 m_display_idx;
        StateFlags          m_flags;

        TransformationType  m_transformation;
        ScalingMethodType   m_scaling_method;
        Rect                m_playback_rect;
        Rect                m_effective_playback_rect;
        Rect                m_crop_rect;
        Rect                m_actual_video_rect;
        Size                m_extended_video_size;
        void*               m_client_context_frame_rendered;
        void*               m_client_context_start;
        void*               m_client_context_stop;

        BOOLEAN ConvertResultCode(INT result_code);

        void ResetVideoChannel();

};

#endif  // Apoxi_Devices_MPE_VideoChannel_hpp

