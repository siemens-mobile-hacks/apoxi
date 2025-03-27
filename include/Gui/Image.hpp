/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Image_hpp)
#define Apoxi_Image_hpp

#include <Gui/Rect.hpp>
#include <Gui/Color.hpp>
#include <Auxiliary/ObjectObtainer.hpp>
#include <Kernel/Condition.hpp>

class BinData;
class NativeImage;
class PaintDc;
class Display;
class DeviceContext;
class Bitmap;

#define GET_16BPP_COLOR_VALUE(red, green, blue) ((ColorValue)((((red) >> 3U) << 11U) | (((green) >> 2U) << 5U) | ((blue) >> 3U)))

class IncrementalPdcUpdater {
    public:
        IncrementalPdcUpdater(const void* client, PaintDc& pdc, INT max_delay = 500);

        virtual ~IncrementalPdcUpdater();
        
        void Init();

        BOOLEAN TimeExpired() const;

        BOOLEAN Update(INT total_steps, INT completed_steps);

        void Finish() const;

        BOOLEAN UpdatesMainDisplay() const;

    protected:
        const void* m_client;
        INT m_max_delay;

        virtual void SendProgressMsg(INT total_steps, 
                                     INT completed_steps) const = 0;

        virtual void SendInterruptedMsg() const = 0;

        static INT CalcProgress(INT total_steps, INT completed_steps);

    private:
        mutable Ticks m_ticks;
        Display *m_main_display;
        BOOLEAN m_to_main_display;
        BOOLEAN m_updated_main_display;
        mutable BOOLEAN m_finished;
};

class ImageIncrementalPdcUpdater : public IncrementalPdcUpdater {
public:
    ImageIncrementalPdcUpdater(const void *client, PaintDc &pdc, INT max_delay = 500);
    virtual ~ImageIncrementalPdcUpdater();

    virtual void SendProgressMsg(INT total_steps, INT completed_steps) const;
    virtual void SendInterruptedMsg() const;
};

class Image : public ObtainableObject {
    typedef ObtainableObject Base;

    public:
        enum {
            ID = 43
        };
            
        enum ErrorCode {
            NoError                         = 0,
            UnspecifiedError                = 1,
            InvalidSizeError                = 2,
            InitializationError             = 3,
            ScanlineBufferError             = 4,
            MissingDataError                = 5,
            IsCurrentlyDecodedError         = 6,
            CouldNotAllocateThreadletError  = 7,
            ThreadletStoppedError           = 8,
            OutOfMemoryError                = 9,
            DecodingInterruptedError        = 10
            
        };

        enum ValidationResult {
            Valid,
            Invalid,
            InProgress
        };
            
        class MetaData {
            public:
                enum ColorSpace {
                    Rgb565ColorSpace,
                    Rgb888ColorSpace,           
                    Rgba8888ColorSpace,
                    Yuv420ColorSpace,
                    Yuv422ColorSpace
                    #if defined(APOXI_COMPAT_2_8_0)

                        , RgbColorSpace,
                        YuvColorSpace
                    #endif // APOXI_COMPAT_2_8_0
                };
                
                MetaData();
                ~MetaData();    // not virtual
                void SetWidth(XYDIM width) { m_width = width; }
                XYDIM GetWidth() const  { return m_width; }
                void SetHeight(XYDIM height) { m_height = height; }
                XYDIM GetHeight() const { return m_height; }
                void SetBitsPerPixel(INT8 bpp) { m_bpp = bpp; }
                INT8 GetBitsPerPixel() const { return m_bpp; }
                void SetFrameCount(INT frame_count) { m_frame_count = frame_count; }
                INT GetFrameCount() const { return m_frame_count; }
                void SetRepeatCount(INT repeat_count) { m_repeat_count = repeat_count; }
                INT GetRepeatCount() const { return m_repeat_count; }
                void SetColorSpace(ColorSpace color_space) { m_color_space = (INT8)color_space; }
                ColorSpace GetColorSpace() const { return (ColorSpace)m_color_space; }
                
            private:
                XYDIM m_width;
                XYDIM m_height;
                INT8 m_bpp;
                INT8 m_color_space;
                INT m_frame_count;
                INT m_repeat_count;
        };

        typedef Bitmap* BitmapPtr;  // this typedef should be private, but the ARM-compiler does not accept this

        Image();

        virtual ~Image();
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        BOOLEAN ConvertToBitmap(Bitmap* bitmap, INT frame_idx = 0, BOOLEAN block = TRUE);

        ValidationResult Validate(INT frame_idx = 0, BOOLEAN block = TRUE);

        virtual BOOLEAN Draw(DeviceContext* dc,
                             XYDIM x,
                             XYDIM y,
                             INT frame_idx,
                             XYDIM scaled_width = -1,
                             XYDIM scaled_height = -1,
                             const Rect& clip_rect = Rect()) const;

        void Draw(DeviceContext* dc, XYDIM x, XYDIM y) const;

        virtual INT GetNextFrame(INT frame_idx) const = 0;

        virtual UINT32 GetFrameDelay(INT frame_idx) const = 0;

        const MetaData& GetMetaData() const { return m_meta_data; }

        virtual const BinData* GetBinData() const;
        
        INT GetRepeatCount() const { return m_meta_data.GetRepeatCount(); }

        virtual BOOLEAN IsCopyrighted() const;

        INT GetFrameCount() const { return m_meta_data.GetFrameCount(); }

        XYDIM GetWidth() const { return m_meta_data.GetWidth(); }

        XYDIM GetHeight() const { return m_meta_data.GetHeight(); }

        XYDIM GetScaledWidth(XYDIM scaled_height) const;

        XYDIM GetScaledHeight(XYDIM scaled_width) const;

        INT8 GetBitsPerPixel() const { return m_meta_data.GetBitsPerPixel(); }

        void SetErrorCode(UINT8 error_code) const; 

        UINT8 GetErrorCode() const { return (UINT8)m_bits.error_code; }

        BOOLEAN IsCurrentlyDecoded() const { return (BOOLEAN)m_bits.is_currently_decoded; }
        
        void StopDecoding() const;

        void WaitUntilDecodingIsFinished() const { StopDecoding(); }

        virtual BOOLEAN DecodeSynchronously() const;

        virtual BOOLEAN IsBufferingAllowed() const;

        void SetBackgroundImage(Bitmap* background, INT frame_idx = 0);

        void ObtainBackgroundImages() { m_bits.obtain_bgr_images = TRUE; }

        virtual void DrawCorruptImageSign(DeviceContext* dc,
                                          XYDIM x,
                                          XYDIM y,
                                          XYDIM scaled_width,
                                          XYDIM scaled_height) const;

        void SetProgressMsgEnabled(BOOLEAN progress) {m_bits.send_progress = progress;}

        BOOLEAN IsProgressMsgEnabled() const {return (BOOLEAN)m_bits.send_progress;}

        Bitmap* GetImageBuffer(INT frame_idx) const;

#if defined(APOXI_COMPAT_2_0_0)

        INT GetId() const;
#endif

        static const UINT32 c_unlimited;

    protected:  
        class CleanupDrawingObtainer {
            public:
                CleanupDrawingObtainer(const Image& image);
                ~CleanupDrawingObtainer();
                BOOLEAN CheckForInterrupt() const;
            private:
                const Image& m_image;
        };

        virtual void* BeginScanlineDrawing(INT frame_idx = 0) const;

        virtual void EndScanlineDrawing(void* context) const;

        virtual void DrawScanline(void* context,
                                  DeviceContext* dc,
                                  XYDIM x,
                                  XYDIM y,
                                  INT scanline_idx,
                                  INT old_scanline_idx) const;      
        
        virtual XYDIM GetScanlineDiff(void* context,
                                      INT scanline_idx,
                                      INT old_scanline_idx) const;

        virtual BOOLEAN IsTransparent(void* context) const;

        virtual BOOLEAN HasAlphaChannel(void* context) const;

        virtual ColorValue GetTransparentColor(void* context) const;
        
        virtual BOOLEAN IsFullTraversingEnabled(void* context) const;
        
        virtual XYDIM GetFrameXPos(void* context) const;

        virtual XYDIM GetFrameWidth(void* context) const;

        virtual XYDIM GetFrameHeight(void* context) const;
        
        void SetMetaData(const MetaData& meta_data);

        void SetMetaData(XYDIM width, XYDIM heigth, INT8 bpp, INT frame_count, INT repeat_count);

        void SetWidth(XYDIM width) { m_meta_data.SetWidth(width); }

        void SetHeight(XYDIM height) { m_meta_data.SetHeight(height); } 

        void SetFrameCount(INT frame_count);

        void SetBitsPerPixel(INT8 bpp) { m_meta_data.SetBitsPerPixel(bpp); }

        void SetRepeatCount(INT repeat_count) { m_meta_data.SetRepeatCount(repeat_count); }

        void AdjustSize(XYDIM& width, XYDIM& height) const;

        BOOLEAN CheckForInterrupt() const;

        void SetPreviousFrameBuffering(BOOLEAN previous) const {m_bits.previous_frame = previous;}  

        BOOLEAN IsPreviousFrameBuffering() const {return m_bits.previous_frame;}

    private:
        MetaData m_meta_data;

        mutable struct {
            UINT previous_frame         : 1;    // should previous frame used as basis for current image
            UINT is_currently_decoded   : 1;    // TRUE if a threadlet decodes the image
            UINT stop_decoding          : 1;    // TRUE if the threadlet should stop the decoding
            UINT send_progress          : 1;    // when TRUE, progress messages will be sent. default is TRUE
            UINT error_code             : 8;
            UINT obtain_bgr_images      : 1;
        } m_bits; 

        mutable INT m_threadlet_count;
        mutable BitmapPtr* m_bmp_buffer;
    
        friend class CleanupDrawingObtainer;        // accesses to m_bits.is_currently_decoded and m_bits.stop_decoding
};



#endif // Apoxi_Image_hpp

