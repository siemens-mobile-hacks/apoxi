/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class StillCamera {
#endif
    public:
        typedef void (*CbImageCaptured)(INT result, void* context, UINT16 frame);
        typedef void (*CbImageEncoded)(INT result, void* context, UINT16 frame);
        typedef void (*CbCaptureFinished)(INT result, void* context, UINT16 frame);
        

        StillCamera(INT device_id); 
    
        virtual ~StillCamera(); 
    
        virtual const WCHAR* GetName() const; 
    
        virtual BOOLEAN GetSupportedImageSizes(const ImageSizeType* &array, UINT8& count) const; 
    
#if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetImageSize(ImageSizeType size); 
#endif  // #if defined(APOXI_COMPAT_2_8_0)

        virtual BOOLEAN SetCaptureImageSize(ImageSizeType capture_image_size,
                                            TransformationType capture_transformation = 
                                                                Camera::NoTransformation);
    
        BOOLEAN SetJpegQuality(INT level); 
    
        INT GetJpegQuality() const; 
    
        BOOLEAN Capture(DataSink** sink_array, 
                        UINT16 count, 
                        void* context, 
                        CbImageCaptured cb_image_captured, 
                        CbImageEncoded cb_image_encoded, 
                        CbCaptureFinished cb_capture_finished); 
    
        BOOLEAN ConfigureMultiShot(UINT16 no_of_pictures, UINT8 frame_rate_subsampling); 
    
        BOOLEAN CancelCapture(); 

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

