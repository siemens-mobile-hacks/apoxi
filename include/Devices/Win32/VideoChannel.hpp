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

#ifdef APOXI_COMPAT_2_8_0
        /*  Obsolete - removed in Apoxi 2.9.0 and later.
            Defines the types of available video parameters.
            The values can be set by VideoChannel::SetParam */
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

        typedef void (*CbResult)(BOOLEAN result,
                                 void* context);

#ifdef APOXI_COMPAT_2_8_0
        /*  Obsolete - use the changed typedef instead.
            Callback function that is invoked by the VideoChannel when a
            frame has been rendered.
            @param result           A result (error) code from the lower layer
            @param context          A context (e.g. this pointer) that has been
                                    passed to the VideoChannel object when
                                    VideoChannel::Open
                                    has been invoked.
            @param frame_buf        Pointer to the video frame buffer
                                    that has been rendered.
            @see RenderFrame*/
        typedef void (*CbVideoFrameRendered)(INT result,
                                             void* context,
                                             const UINT8 HUGE* frame_buf);

        /*  Obsolete - not needed anymore.
            Callback function that is invoked by the VideoChannel when a
            frame has been rendered.
            @param result           <em>TRUE</em> if the operation was
                                    succesfull. Otherwise, <em>FALSE</em>.
            @param context          A context (e.g. this pointer) that has been
                                    passed to the VideoChannel object when
                                    VideoChannel::Open
                                    has been invoked.
            @param frame_buf        Pointer to the video frame buffer
                                    that has been rendered.
            @see RenderFrame*/
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
        /*  Obsolete - use the overloaded function instead.
            Opens the video channel and sets the bounding rectangle for the video frames, which will be
            used to display the video content set by VideoChannel::RenderFrame. VideoChannel::Close
            should be invoked when the no frames are rendered anymore.
            @param video_frame_rect     [IN/OUT] Position and size of area to be filled with video.
            @param cb_frame_rendered    [IN] Pointer to callback function which is called when the rendering
                                        of a frame has been completed (i. e. the frame is written to the display
                                        buffer, the transfer of frame from display buffer to LCD is not
                                        included).
            @param context              Context (e.g. this pointer) of the calling application.
                                        This context will be passed in the callback function.
            @return                     TRUE if the video channel could be opened.
            @see CbVideoFrameRendered*/
        BOOLEAN Open(Rect& video_frame_rect, CbVideoFrameRendered cb_frame_rendered, void* context = 0);

        /*  Opens the video channel and sets the bounding rectangle for the video frames, which will be
            used to display the video content set by VideoChannel::RenderFrame. VideoChannel::Close
            should be invoked when the no frames are rendered anymore.
            @param cb_frame_rendered    [IN] Pointer to callback function which is called when the rendering
                                        of a frame has been completed (i. e. the frame is written to the display
                                        buffer, the transfer of frame from display buffer to LCD is not
                                        included).
            @param context              Context (e.g. this pointer) of the calling application.
                                        This context will be passed in the callback function.
            @return                     TRUE if the video channel could be opened.
            @see CbVideoFrameRendered*/
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
        /*  Obsolete - removed in Apoxi 2.9.0 and later.
            Parameterizes the rendering path and configures the transformation blocks.
            @param type     [IN] Type of the parameter to be configured
            @param value        [IN] Value to which the parameter type should be set
            @return         TRUE if the setting of the parameter was successful */
        BOOLEAN SetParam(VideoParameterType type, UINT32 value);

        /*  Obsolete - removed in Apoxi 2.9.0 and later.
            Reads out parameters of the rendering path and transformation blocks.
            Parameters are set with the complementary function VideoChannel::SetVideoParam.
            @param type     [IN] Type of the parameter to be configured.
            @param value    [OUT] Current value of the parameter.
            @return         TRUE if the setting of the parameter was successful. */
        BOOLEAN GetParam(VideoParameterType type, UINT32* value) const;
#endif // APOXI_COMPAT_2_8_0

#ifdef APOXI_COMPAT_2_6_0
        /*  Obsolete - use the method SetVideoSize instead.
            Sets the actual size of the video in pixels. The actual size can be determined
            by analyzing the transport format of the video or the encoded elementary stream directly.
            (Compare to 'extended size' as defined by some codec standards, which is the actual size
            rounded up to a full integer number of macroblocks)
            @param video_size       [IN] Actual size of the decoded video as determined by analyzing
                                    the videos transport format or the elementary stream */

        void SetSize(Size video_size)
        {
        #ifdef APOXI_COMPAT_2_8_0
            SetVideoSize(video_size);
        #endif //  APOXI_COMPAT_2_8_0
        }
#endif // APOXI_COMPAT_2_6_0

#ifdef APOXI_COMPAT_2_8_0
        /*  Obsolete - use the overloaded function instead.
            Sets the actual size of the video in pixels. The actual size can be determined
            by analyzing the transport format of the video or the encoded elementary stream directly.
            (Compare to 'extended size' as defined by some codec standards, which is the actual size
            rounded up to a full integer number of macroblocks)
            @param video_size       [IN] Actual size of the decoded video as determined by analyzing
                                    the videos transport format or the elementary stream */
        void SetVideoSize(Size video_size);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetVideoSize(   Size actual_video_size,
                                Size extended_video_size,
                                Point left_top_offset);

#ifdef APOXI_COMPAT_2_8_0
        /*  Obsolete - use the overloaded method instead.
            Defines a sub rectangle within the decoded video.
            The coordinates are relative to the upper left corner of the video. The rectangle may never
            exceed the size of the decoded video i.e. the cropping rectangle must always lie completely within the video.
            Together with video frame rectangle this implicitly also defines a zoom factor - the content of the
            cropping rectangle is zoomed up or down to best fit to the video frame rectangle. This is limited by the capability
            of the transformation blocks for zoom and crop (i.e. in most cases the hardware).
            @param crop_rect    [IN/OUT] Position and size of area to be cut out from the original video.
            @return             TRUE if the setting of the parameter was possible in the transformation blocks.
                                If it was not possible FALSE is returned and the cropping rectangle contains the best effort
                                of the transformation blocks to fit to the desired rectangle. */
        BOOLEAN SetCropRect(Rect& crop_rect);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetCropRect(Rect& crop_rect, Rect& effective_playback_rect);

#ifdef APOXI_COMPAT_2_6_0
        /*  Obsolete - use the method SetPlaybackRect instead.
            Adjusts the size and position of the actual video area on the screen.
            The rectangle is initially set when opening a channel with DisplayChannel::Open but can be changed dynamically with this method.
            @param video_frame_rect     [IN/OUT] Position and size of screen area to be filled with video.
            @return                     TRUE if the setting of the parameter was possible in the underlying HW.
                                        If it was not possible, FALSE is returned and the  video frame rectangle
                                        contains the best effort of the hardware to fit the desired rectangle. */
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
        /*  Obsolete - use the function SetPlaybackRect instead.
            Adjusts the size and position of the actual video area on the screen.
            The rectangle is initially set when opening a channel with DisplayChannel::Open but can be changed dynamically with this method.
            @param video_frame_rect     [IN/OUT] Position and size of screen area to be filled with video.
            @return                     TRUE if the setting of the parameter was possible in the underlying HW.
                                        If it was not possible, FALSE is returned and the  video frame rectangle
                                        contains the best effort of the hardware to fit the desired rectangle. */
        BOOLEAN SetFrameRect(Rect& video_frame_rect);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetPlaybackRect(Rect& playback_rect,
                                TransformationType playback_transformation,
                                ScalingMethodType scaling_method);

#ifdef APOXI_COMPAT_2_8_0
        /*  Reads out the capabilities of the underlying layers to fulfill a certain programming for the video rectangles.
            Constraints generally come in due to the utilized hardware blocks.
            Underlying layers try to achieve a best effort to reach the desired rectangles - if this cannot be achieved
            the nearest possible rectangles are returned. It is ensured, that these rectangles will never be larger.
            The returned rectangles can the be used in VideoChannel::SetCropRect and VideoChannel::AdjustFrameRect which guarantees that
            these functions will be successful.
            @param video_frame_rect     [IN/OUT] Position and size of screen area to be filled with video.
            @param crop_rect            [IN/OUT] Position and size of area to be cut out from the original video.
            @return                     TRUE if the setting of the parameter *would be* possible in the underlying hardware.
                                        If itwas not possible, FALSE is returned and the video frame rectangle and cropping rectangle
                                        contain the best effort of the hardware to fit the desired rectangles */
        BOOLEAN QueryRects(Rect& video_frame_rect, Rect& crop_rect);
#endif // APOXI_COMPAT_2_8_0

        BOOLEAN SetPlaybackAndViewfinderOrder(
                            VideoAndViewfinderOrderType video_viewfinder_order);

    private:
        Rect m_playback_rect;
        const DDrvAtomPtr m_video_frame_buf;
        INT m_display_idx;
};

#endif  // Apoxi_VideoChannel_hpp


