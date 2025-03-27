/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_PngImage_hpp)
#define Apoxi_PngImage_hpp

#include <Gui/Image.hpp>

class PngDecoder;
class PaintDc;

class PngImage : public Image {
    typedef Image Base;

    public:
        enum {
            ID = 4
        };

        PngImage();

        PngImage(BinData *data, BOOLEAN *success = 0);

        virtual ~PngImage();

        virtual BOOLEAN IsInstanceOf(INT id) const;

        BOOLEAN Init(BinData *data);

        virtual BOOLEAN Draw(DeviceContext *dc, XYDIM x, XYDIM y, 
            INT frame_idx, XYDIM scaled_width = -1, XYDIM scaled_height = -1, 
            const Rect &clip_rect = Rect()) const;

        virtual INT GetNextFrame(INT frame_idx) const;
        virtual UINT32 GetFrameDelay(INT frame_idx) const;
        virtual const BinData* GetBinData() const;

    protected:
        virtual BOOLEAN IsTransparent(void* context) const;
        
        virtual ColorValue GetTransparentColor(void* context) const;
        
        virtual BOOLEAN HasAlphaChannel(void* context) const;

        PngDecoder* BeginDrawing() const;

        void EndDrawing(PngDecoder &decoder) const;

        void SetupDrawingMode(const PngDecoder &decoder, XYDIM &scaled_width, 
            XYDIM &scaled_height, XYDIM x_origin, XYDIM y_origin, 
            INT frame_idx) const;

        inline void SmartDrawPixel(PngDecoder &decoder, PaintDc &pdc, 
            const Rect &clip_rect, XYDIM x, XYDIM y) const;

        inline void DrawPixel(PngDecoder &decoder, PaintDc &pdc, 
            const Rect &clip_rect, XYDIM x, XYDIM y, const Color &color) const;

        inline void DrawScaledPixel(PngDecoder &decoder, PaintDc &pdc, 
            const Rect &clip_rect, XYDIM x, XYDIM y, const Color &color) const;

        void SmartDrawScanline(PngDecoder &decoder, PaintDc &pdc, 
            const Rect &clip_rect, XYDIM y) const;

        virtual void DrawScanline(PngDecoder &decoder, PaintDc &pdc, 
            const Rect &clip_rect, XYDIM y, UINT thickness = 1) const;

        void DrawHeightScaledScanline(PngDecoder &decoder, PaintDc &pdc, 
            const Rect &clip_rect, XYDIM y) const;

        BOOLEAN DecodeNextScanline(DeviceContext *dc, PngDecoder &decoder, 
            XYDIM x, XYDIM y, XYDIM scaled_width, XYDIM scaled_height) const;

        void FreeImage();

    protected:
        BinData *m_data;
        BOOLEAN m_is_interlaced;

        mutable XYDIM m_x_origin;
        mutable XYDIM m_y_origin;

        mutable BOOLEAN m_scaling_width;
        mutable BOOLEAN m_scaling_height;
        mutable UINT32 m_shifted_pixel_width;
        mutable UINT32 m_shifted_pixel_height;
        mutable BOOLEAN m_scaled_right_edge_cutted;
        mutable BOOLEAN m_scaled_bottom_edge_cutted;
        mutable XYDIM m_scaled_width;
        mutable XYDIM m_scaled_height;
        mutable XYDIM m_last_unscaled_width_idx;
        mutable XYDIM m_last_unscaled_height_idx;

        static const UINT32 c_shift;
};

#endif  // Apoxi_PngImage_hpp

