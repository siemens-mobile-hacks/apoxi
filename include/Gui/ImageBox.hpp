/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ImageBox_hpp)
#define Apoxi_ImageBox_hpp

#include <Gui/DrawableObject.hpp>
#include <Gui/ImageObtainer.hpp>
#include <Gui/DeviceContext.hpp>
#include <Auxiliary/TriggerTimer.hpp>

class Bitmap;

class ImageBox : public DrawableObject {
    typedef DrawableObject Base;

    public:
        enum {
            ID = 11
        };

        typedef Bitmap* BitmapPtr;  // this typedef should be private, but the ARM-compiler does not accept this

        ImageBox();

        ImageBox(Control* control, const BitmapRes* bitmap = 0);

        ImageBox(Control* control,
                 const ImageObtainer& obtainer,
                 XYDIM width = -1,
                 XYDIM height = -1,
                 BOOLEAN autostart = TRUE,
                 BOOLEAN buffering = TRUE,
                 BOOLEAN cleanup_buffer = FALSE);
        
        virtual ~ImageBox();

        void Init(Control* control, const BitmapRes* bitmap = 0, XYDIM width = -1, XYDIM height = -1);

        void Init(Control* control,
                  const ImageObtainer& obtainer,
                  XYDIM width = -1,
                  XYDIM height = -1,
                  BOOLEAN autostart = TRUE,
                  BOOLEAN buffering = TRUE,
                  BOOLEAN cleanup_buffer = FALSE);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetBitmap(const BitmapRes* bitmap, XYDIM width = -1, XYDIM height = -1);

        void SetImageObtainer(const ImageObtainer& obtainer,
                              XYDIM width = -1,
                              XYDIM height = -1,
                              BOOLEAN buffering = TRUE);

        ImageObtainer& GetImageObtainer() { return m_obtainer; }

        const ImageObtainer& GetImageObtainer() const { return m_obtainer; }

        virtual XYDIM GetDefaultWidth() const;

        virtual XYDIM GetDefaultHeight() const;

        INT GetFrame() const { return m_frame; }

        void Start(BOOLEAN play_only_once = FALSE);

        void Restart();

        void Stop();

        Bitmap* GetImageBuffer(INT frame_idx) const;
        
        static BOOLEAN IsBufferAvailable(XYDIM scaled_width, XYDIM scaled_height, INT frame_count);

        void SetBufferingEnabled(BOOLEAN buffering) { m_bits.buffering_enabled = buffering; }

        BOOLEAN IsBufferingEnabled() const {return m_bits.buffering_enabled;}

        BOOLEAN IsDecodingFinished() const { return (BOOLEAN)m_bits.finished_decoding;}

        BOOLEAN IsDecoding() const {return (BOOLEAN)m_bits.is_decoding;}

        BOOLEAN IsPlayOnceEnabled() const { return (BOOLEAN)m_bits.play_only_once; }

        BOOLEAN IsPreviewShown() const { return (BOOLEAN)m_bits.show_preview; }
    
        BOOLEAN SetTransformation(DeviceContext::TransformationMode transformation);

        DeviceContext::TransformationMode GetTransformation() const { return m_transformation; }

        const BitmapRes* GetBitmap() const { return 0; }

    protected:
        virtual void Refresh(const Rect& rect);

        virtual void Cleanup();
        
        virtual BOOLEAN OnMessage(const Message& msg);
        
        virtual void OnMove(XYDIM dx, XYDIM dy);

        virtual void OnResize(XYDIM dx, XYDIM dy);

    private:
        enum State {
            Stopped     = 0,
            AutoStart   = 1,
            Running     = 2,
            Finished    = 3
        };

        struct {
            UINT buffering_enabled      : 1;
            UINT buffer_available       : 1;
            UINT finished_decoding      : 1;
            UINT is_decoding            : 1;
            UINT bounds_set_by_props    : 1;
            UINT cleanup_buffer         : 1;
            UINT play_only_once         : 1;
            UINT state                  : 2;
            UINT registered_dec_msg     : 1;
            UINT show_preview           : 1;
            UINT rotated                : 1;
            UINT currently_rotating     : 1;
        } m_bits;
        
        Bitmap** m_bmp_buffer;
        
        INT m_frame;
        INT m_frame_count;

        UINT8 m_overall_progress;
        UINT8 m_decoded_frame;
        UINT8 m_repeat_idx;
        DeviceContext::TransformationMode m_transformation;
        
        ImageObtainer m_obtainer;   
        TriggerTimer<ImageBox> m_anim_timer;

        static BOOLEAN m_initialized;
        static UINT32 m_alloc_buf_count;
        static Semaphore m_sem;

        void AdjustSize(XYDIM& width, XYDIM& height);
        void StopDecoding();
        void StartDecoding();
        BOOLEAN IsFullBufferingAvailable() const { return (BOOLEAN)m_bits.buffer_available; }
        void InitProperties();
        void OnTimer();
        State GetState() const { return (State)m_bits.state; }
        BOOLEAN ObtainBuffer(XYDIM width, XYDIM height);
        void ReleaseBuffer(INT frame_idx, BOOLEAN is_decoding);
        void ReleaseAllBuffers();
        void PrepareImageBuffers();
        BOOLEAN CreateNextBufferedFrame();
        BOOLEAN IsVisible() const;

        void CleanupBuffer();

        void GetInternalSize(XYDIM& width, XYDIM& height);

        friend class TriggerTimer<ImageBox>;
        friend class ImageBoxView;
};

class ImageBoxView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        virtual ~ImageBoxView();

    private:
        virtual void Draw(const Component& component, 
                          DeviceContext* dc, 
                          const Rect& repaint_rect) const;

        void StartAnimTimer(ImageBox& image_box, const Ticks& ticks) const;
};

#endif  // Apoxi_ImageBox_hpp


