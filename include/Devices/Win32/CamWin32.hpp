#/* ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(CamWin32_hpp)
#define CamWin32_hpp

#include <Devices/Win32/MmiSimClient.hpp>
#include <Config/DisplayConfig.hpp>



class CamWin32 {

public:

    enum Property {
        BrightnessProperty = 0,
        ContrastProperty,
        CompressionProperty,
        EndOfProperty
    };

    enum PropertyType {
        DefaultValue,
        CurrentValue,
        AutoValue,
        EndOfPropertyType
    };

    enum ImageSizeType {
        QqcifSize,          // 88x72
        SqcifSize,          // 128x96
        QqvgaSize,          // 160x120
        QcifSize,           // 176x144
        QsifSize,           // 276x120
        QvgaSize,           // 320x240
        CifSize,            // 352x288      0,3 mp
        VgaSize,            // 640x480
        SvgaSize,           // 800x600
        XgaSize,            // 1024x768
        Size1Mp,            // 1152x864     1,0 mp 
        Size1_3Mp,          // 1280x960     1,3 mp
        UxgaSize,           // 1600x1200    2,0 mp
        Size2Mp,            // 1728x1152    2,0 mp
        Size3Mp,            // 2048x1536    3,0 mp
        EndOfImageSizeType
    };

    enum ColorFormatType {
        DefaultFormat,
        RawFormat,
        JpegFormat,
        PngFormat,
        EndOfColorType
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

    enum ImageFormatType {
        YUV420
    };

    enum FrameRateType {
        Fps5 = 0,
        Fps7_5,
        Fps10,
        Fps12,
        Fps15,
        Fps24,
        Fps25,
        Fps30,
        EndOfFpsType
    };
    
    /********************************************************/
    /*     for documentation of methods see Camera.hpp      */
    /********************************************************/

    static CamWin32* GetInstance();
    BOOLEAN Init();
    
    virtual ~CamWin32();

    BOOLEAN Enable(INT device_idx=0);
    void Disable();


    BOOLEAN GetPropertyRange(INT property,INT &min,INT &max,INT &interval,INT &def,INT &cur);

    
    BOOLEAN SetProperty(INT property, INT type, INT value);
    

    BOOLEAN GetCurrentImage(UINT8 HUGE* &buffer, UINT32& length);
    
    
    BOOLEAN GetCurrentImageBufferSize(UINT32& length);
        
    
    BOOLEAN SetImageSize(ImageSizeType size,UINT8 &max_zoom_level);


    BOOLEAN GetSupportedImageSizes(const ImageSizeType* &array, UINT8& count);


    BOOLEAN SetSensorImageSize(ImageSizeType size,UINT8 &max_zoom_level);

    BOOLEAN GetSupportedSensorImageSizes(const ImageSizeType* &array, UINT8& count);
    
    
    BOOLEAN SetColorFormat(ColorFormatType color_format);


    BOOLEAN SetTwilightModeEnabled(BOOLEAN twilight_mode);


    BOOLEAN SetColorModeEnabled(BOOLEAN color_mode);
        
    
    BOOLEAN SetTransformation(TransformationType trans);

    
    void SetViewFinder(const Rect& vf_rect,UINT8 display_idx);


    BOOLEAN StartViewFinder();


    BOOLEAN FreezeViewFinder();


    BOOLEAN StopViewFinder();

    
    BOOLEAN SetZoomLevel(UINT8 zoom);

    
    INT GetMaxZoomLevel();
        
    
    BOOLEAN StartVideoCapture(ImageFormatType format_type);


    BOOLEAN StopVideoCapture();


    BOOLEAN GetSupportedFrameRates(const FrameRateType* &array, UINT8& count);

        
    BOOLEAN SetFrameRate(FrameRateType frame_rate);
    

    void RegisterGetBufferCB(UINT8 HUGE* (*CB_GetBuffer)());
    
    
    void RegisterFrameCapturedCB(void (*CB_FrameCaptured)(INT ret, UINT8 HUGE* buf, UINT32 size, UINT32 stamp));

    static void ViewFinder_CB(double Time, BYTE *pBuffer, long BufferLen);

    
private:
    static CamWin32 m_cam;
    CamWin32();
    static MmiSimClient* m_mmisim_client;

    //viewfinder rectangle
    static Rect m_vf_rect;
    
    static INT m_display_idx;
    BOOLEAN m_jpeg_enabled;
    
    UINT8 m_compression_ratio;

};



#endif //CamWin32_hpp

