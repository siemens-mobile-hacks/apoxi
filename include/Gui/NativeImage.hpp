/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NativeImage_hpp)
#define Apoxi_NativeImage_hpp

#include <Gui/ImageDecoder.hpp>
#include <Auxiliary/SwitchedRleCompression.hpp>

struct BitmapRes;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/*  Internal class which represents the decoder for
    native images. The class may not be used by
    the MMI in a direct manner and the interface
    may be changed in future releases. */
class NativeImageDecoder : public ImageDecoder {
    typedef ImageDecoder Base;
    
    public:
        static NativeImageDecoder* GetInstance();

        // @see ImageDeocder::GetMetaData
        virtual BOOLEAN GetMetaData(Image& image, Image::MetaData* meta_data);

        // @see ImageDeocder::BeginDecoding
        virtual BOOLEAN BeginDecoding(const Image& image, INT frame_idx = 0);

        // @see ImageDeocder::EndDecoding
        virtual void EndDecoding(const Image& image, INT frame_idx = 0);

        /*  Returns a pointer to the scanline buffer. May only invoked
            inside NativeImageDecoder::BeginDecoding and NativeImageDecoder::EndDecoding. */
        UINT8* GetScanlineBuffer() const { return m_scanline_buffer; }

        /*  Returns the size of the scanline in bytes. May only invoked
            inside NativeImageDecoder::BeginDecoding and NativeImageDecoder::EndDecoding. */
        UINT GetScanlineSize() const { return m_scanline_size; }

        /*  Returns a pointer to the alpha buffer. May only invoked
            inside NativeImageDecoder::BeginDecoding and NativeImageDecoder::EndDecoding. */
        UINT8* GetAlphaBuffer() const { return m_alpha_buffer; }

        /*  Decodes a scanline into the scanline buffer and the alpha buffer. May only invoked
            inside NativeImageDecoder::BeginDecoding and NativeImageDecoder::EndDecoding. */
        BOOLEAN DecodeScanline(INT scanline_idx,
                               INT old_scanline_idx,
                               UINT8* dest_buffer = 0);

        /*  Returns the frame index where the decoder is used. May only invoked
            inside NativeImageDecoder::BeginDecoding and NativeImageDecoder::EndDecoding. */
        INT GetFrameIndex() const { return m_frame_idx; }

    private:
        BOOLEAN m_compressed;
        BOOLEAN m_indexed;
        UINT32 m_frame_offset;
        UINT8 m_alpha_bits;
        INT m_frame_idx;
        UINT m_scanline_size;
        UINT8* m_scanline_buffer;
        UINT m_width;
        UINT8* m_index_buffer;
        UINT8* m_alpha_buffer;
        ColorValue* m_local_color_table;
        BinData* m_bin_data;
        SwitchedRleCompression::Context m_compression_context;

        static NativeImageDecoder m_decoder;

        NativeImageDecoder();
        INT16 GetInt16Value(const UINT8* buffer) const;
        INT32 GetInt32Value(const UINT8* buffer) const;
        BOOLEAN ReadLocalColorTable();
        BOOLEAN DecodeIndexedScanline(INT scanline_idx,
                                      INT old_scanline_idx,
                                      UINT8* dest_buffer);

        UINT GetIndexedAlphaByteCount() const;
};
#endif // DOXYGEN_SHOULD_SKIP_THIS

class NativeImage : public Image {
    typedef Image Base;

    public:
        enum {
            ID = 6
        };

        NativeImage();

        NativeImage(Bitmap* bitmap);

        NativeImage(const BitmapRes* bitmap_res);

        NativeImage(BinData* bin_data);

        NativeImage(const BitmapRes* const* animation_res,
                    UINT frame_count,
                    UINT32 frame_delay = 0);

        virtual ~NativeImage();

        void Init(Bitmap* bitmap);

        void Init(const BitmapRes* bitmap_res);

        void Init(BinData* bin_data);

        void Init(const BitmapRes* const* animation_res,
                  INT frame_count,
                  UINT32 frame_delay = 0);
        
        virtual BOOLEAN IsInstanceOf(INT id) const;

        virtual BOOLEAN Draw(DeviceContext* dc,
                             XYDIM x,
                             XYDIM y,
                             INT frame_idx,
                             XYDIM scaled_width = -1,
                             XYDIM scaled_height = -1,
                             const Rect& clip_rect = Rect()) const;

        virtual const BinData* GetBinData() const;

        virtual INT GetNextFrame(INT frame_idx) const;
        
        void SetFrameDelay(UINT32 frame_delay);

        virtual UINT32 GetFrameDelay(INT frame_idx) const;

        virtual BOOLEAN IsCopyrighted() const;

        BOOLEAN IsCompressed(INT frame_idx = 0) const;

        virtual BOOLEAN DecodeSynchronously() const;

    protected:
        virtual void* BeginScanlineDrawing(INT frame_idx) const;

        virtual void EndScanlineDrawing(void* context) const;

        virtual void DrawScanline(void* context,
                                  DeviceContext* dc,
                                  XYDIM x,
                                  XYDIM y,
                                  INT scanline_idx,
                                  INT old_scanline_idx) const;


        virtual BOOLEAN IsTransparent(void* context) const;

        virtual ColorValue GetTransparentColor(void* context) const;

    private:
        enum ImageType {
            SingleImageType,
            ConstSingleImageType,
            ConstAnimationType,
            BinDataType,
            UndefinedType
        };

        struct {
            UINT compressed          : 1;
            UINT copyrighted         : 1;
            UINT transparent         : 1;
        } m_bits;

        ColorValue m_transparent_color;
        ImageType m_type;
        UINT16 m_frame_delay;   
        union {
            Bitmap                  *m_bitmap;
            const BitmapRes         *m_bitmap_res;
            const BitmapRes* const  *m_animation_res;
            BinData                 *m_bin_data;
        };

        void SetTransparent(BOOLEAN transparent) { m_bits.transparent = transparent; }
        void SetTransparentColor(ColorValue color_value) { m_transparent_color = color_value; }
        void SetCopyrighted(BOOLEAN copyrighted) { m_bits.copyrighted = copyrighted; }
        INT16 GetDefaultFrameDelay() const { return 300; }
        void InitProperties();
        friend class NativeImageDecoder;
};

#endif  //Apoxi_NativeImage_hpp

