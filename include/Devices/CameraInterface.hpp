/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class Camera {
#endif
    public:

        typedef struct ParameterLimits {
                INT min;
                INT def;
                INT max;
        } ParameterLimits; 

        enum AntiFlickerType {
            AntiFlickerNotSupported,
            AntiFlickerDisabled,
            AntiFlickerHz50,
            AntiFlickerHz60
        };
        
        enum WhiteBalanceType {
            AutoBalance,
            SunlightBalance,
            CloudyBalance,
            IncandescentBalance,
            FluorescentBalance
        };
        
        enum MeteringType {
            FullImageMetering,
            CenterBasedMetering
        };

        enum TransformationType {
            NoTransformation,
            Rotate90,
            Rotate180,
            Rotate270,
            Mirror,
            MirrorRotate90,
            MirrorRotate180,
            MirrorRotate270
        };
        
        enum FlashType {
            FlashNotSupported,
            FlashDisabled,
            FlashEnabled,
            AutomaticFlash,
            RedEyeReductionFlash
        };

        enum TwilightType {
            TwilightOff,
            TwilightOn,
            TwilightAuto
        };

        enum ImageSizeType {
            QqcifSize,
            Size96x96,
            SqcifSize,
            QqvgaSize,
            QcifSize,
            QsifSize,
            QvgaSize,
            CifSize,
            VgaSize,
            SvgaSize,
            XgaSize,
            Size1Mp,
            Size1_3Mp,
            SxgaSize,
            UxgaSize,
            Size2Mp,
            Size3Mp,
            EndOfImageSizeType
        };
        
        enum ScalingMethodType{
            NoScaling,
            LetterboxScaling,
            BestFitScaling
        };
        
        enum FilterType {
            NoFilter = 0,
            SepiaFilter,
            EmbossFilter,
            GrayScaleFilter,
            NegativeFilter,
            HorrorFilter = 50,
            HazeFilter = 51,
            GlassTileFilter = 52,
            PuzzleTileFilter = 53,
            OilpaintFilter = 54,
            PictureFrameFilter = 55,
            FilmFilter = 56,
            ConcaveFilter = 57,
            EndOfFilterType
        };
        
        enum ActionType {
            Decrease,
            Reset,
            Increase
        };

        enum CameraError {
            NoError,
            CameraAlreadyLockedError,
            CameraNotReadyError,
            UnsupportedCameraFeature,
            CameraNotInitializedError,
            BufferNotAvailableError,
            BufferAllocationError,
            VideoEncoderBufferAllocationError,
            ApplicationControlError,
            UnsupportedFrameRateError,
            InvalidCameraParameter,
            InvalidSizeError,
            JpegEncodingError,
            UserAbortedError
        };
        
        enum Result {
            ViewfinderStarted,
            ViewfinderStopped,
            BrightnessChanged,
            ContrastChanged,
            ExposureChanged,
            FilterChanged,
            AntiflickerChanged,
            TwilightChanged,
            WhiteBalanceChanged,
            FrameRateChanged,
            VideoCaptureStarted,            // not used yet, only for future use
            VideoCaptureStopped,
            VideoCapturePaused,
            VideoCaptureUnPaused            // not used yet, only for future use
        };

        enum CameraState {
            UnitializedState,
            IdleState,
            ViewfindingState,
            ViewfinderHiddenState,
            ImageCapturingState,
            VideoCapturingState,
            VideoCapturingHiddenState,
            ViewfinderHoldState,
            ViewfinderHoldHiddenState,
            VideoCapturingPausedState,
            ErrorState
        };

        Camera(INT category, INT device_id); 

        virtual ~Camera(); 

        virtual BOOLEAN Open(); 

        virtual BOOLEAN Close(); 

        INT GetDisplayIndex() const; 

        INT GetLastError() const; 

        CameraState GetState() const; 

#if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetCaptureTransformation(TransformationType trans); 
#endif  // #if defined(APOXI_COMPAT_2_8_0)

        TransformationType GetCaptureTransformation() const; 

        virtual BOOLEAN SetViewScalingMethod(ScalingMethodType scaling_method); 

        ScalingMethodType GetViewScalingMethod() const; 

        virtual BOOLEAN GetSupportedImageSizes(const ImageSizeType* &array, UINT8& count) const; 

#if defined(APOXI_COMPAT_2_8_0)     

        virtual BOOLEAN SetImageSize(ImageSizeType size); 
#endif  // #if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetCaptureImageSize(ImageSizeType capture_image_size,
                                            TransformationType capture_transformation = 
                                                                Camera::NoTransformation);
        
        ImageSizeType GetSelectedImageSize() const; 

        static const Size GetImageSizeDimensions(ImageSizeType size_type); 
        
        BOOLEAN SetFlash(FlashType flash);
        
        FlashType GetFlash() const;
        
        virtual BOOLEAN SetZoom(ActionType action, UINT8 step_size = 1); 
        
        virtual INT GetZoomLevelCount() const;

        BOOLEAN SetBrightness(INT brightness); 

        INT GetBrightness() const; 

        BOOLEAN GetBrightnessLimits(INT& min_level, INT& max_level, INT& def_level); 

        BOOLEAN SetContrast(INT level); 

        INT GetContrast() const; 

        BOOLEAN GetContrastLimits(INT& min_level, INT& max_level, INT& def_level);
        
        BOOLEAN SetExposure(INT level);
        
        INT GetExposure() const;
        
        BOOLEAN GetExposureLimits(INT& min_level, INT& max_level, INT& def_level);

        BOOLEAN SetTwilightMode(TwilightType twilight); 

        /*  TwilightAuto is currently not supported. When set, function returns FALSE and 
            last camera error is set to UnsupportedCameraFeature. */ 
        TwilightType GetTwilightMode() const; 
        
        BOOLEAN SetAntiFlickerMode(AntiFlickerType anti_flicker_mode); 
        
        AntiFlickerType GetAntiFlickerMode() const; 
        
        BOOLEAN SetFilter(FilterType filter); 
        
        FilterType GetFilter() const;
        
        BOOLEAN SetWhiteBalance(WhiteBalanceType white_balance_mode);
        
        WhiteBalanceType GetWhiteBalance() const;
        
        BOOLEAN SetMeteringMode(MeteringType metering_mode);
        
        MeteringType GetMeteringMode() const;
            
#if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetViewfinderRect(const Rect& vf_rect, 
                                          UINT8 display_idx = 0, 
                                          TransformationType transformation = NoTransformation); 
#endif  // #if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetViewfinderRect(Rect& vf_rect,
                                          INT display_idx = 0,
                                          TransformationType view_transformation = NoTransformation,
                                          ScalingMethodType view_scaling_method = NoScaling);
        
        BOOLEAN GetEffectiveViewfinderRect(Rect& effective_rect);
        
        BOOLEAN SetTwinViewfinderEnabled(BOOLEAN enabled);
        
        BOOLEAN IsTwinViewfinderEnabled() const;

        virtual BOOLEAN StartViewfinder(); 

        /* tbd: can maybe done in StartViewfinder - check availability in GDD */ 
        virtual BOOLEAN RestartViewfinder(); 

        virtual BOOLEAN StopViewfinder(); 

        virtual BOOLEAN HideViewfinder(); 

        virtual BOOLEAN ShowViewfinder();

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

