/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DeviceContext_hpp)
#define Apoxi_DeviceContext_hpp

class VirtualDisplay;
class Control;
class Font;
class BitmapDc;
class Bitmap;
struct BitmapRes;
#include <Gui/TextFormat.hpp>
#include <Gui/Pen.hpp>
#include <Gui/Brush.hpp>
#include <Gui/Rect.hpp>
#include <Gui/BidiManager.hpp>

class DeviceContext {
    public:
        // Obsolete - provided for backward compatibility with APOXI-versions < 1.1
        enum RasterOp {
            OverpaintRop,
            AndRop,
            OrRop,
            XorRop,
            NXorRop,
            InvertRop
        };
        
        enum TransformationMode {
            NoTransformation,
            MirrorRot180,
            Mirror,     
            Rot180,     
            MirrorRot270,
            Rot90,
            Rot270,
            MirrorRot90
        };

        enum AlphaBlendingMode {
            MaskAlphaBlending,
            ImmediateAlphaBlending
        };

        DeviceContext(); 

        DeviceContext(const DeviceContext* dc);

        DeviceContext(VirtualDisplay* display, Control* control = 0); 

        virtual ~DeviceContext();

        void Init(VirtualDisplay* display, Control* control = 0); 

        void Init(const DeviceContext* dc);

        void SetTextFormat(const TextFormat& text_format) { m_text_format = text_format; }

        const TextFormat& GetTextFormat() const { return m_text_format; }

        void SetTextAlign(TextAlign text_align) { m_text_format.SetTextAlign(text_align); }

        TextAlign GetTextAlign() const { return m_text_format.GetTextAlign(); }

        void SetTextAttr(TextAttr text_attr) { m_text_format.SetTextAttr(text_attr); }

        TextAttr GetTextAttr() const { return m_text_format.GetTextAttr(); }

        void SetFont(const Font& font);

        const Font& GetFont() const;

        void SetFontAlign(FontAlign font_align) { m_text_format.SetFontAlign(font_align); }

        FontAlign GetFontAlign() const { return m_text_format.GetFontAlign(); }

        void SetPen(const Pen& pen) { m_pen = pen; }

        const Pen& GetPen() const { return m_pen; }

        void SetPenColor(const Color& color) { m_pen.SetColor(color); }

        void SetPenColor(SystemColorId system_color_id);

        const Color& GetPenColor() const { return m_pen.GetColor(); }

        void SetPenColorValue(ColorValue color_value) { m_pen.SetColorValue(color_value); }

        ColorValue GetPenColorValue() const { return m_pen.GetColorValue(); }

        void SetPenColorRgb(UINT8 red,
                            UINT8 green,
                            UINT8 blue,
                            UINT8 alpha = 255) { m_pen.SetColorRgb(red, green, blue, alpha); }

        void SetPenColorHsv(UINT8 hue,
                            UINT8 saturation,
                            UINT8 value,
                            UINT8 alpha = 255) { m_pen.SetColorHsv(hue, saturation, value, alpha); }

        void SetPenStyle(PenStyle pen_style) { m_pen.SetStyle(pen_style); }

        PenStyle GetPenStyle() const { return m_pen.GetStyle(); }

        void SetBrush(const Brush& brush) { m_brush = brush; }

        const Brush& GetBrush() const { return m_brush; }

        void SetBrushColor(const Color& color) { m_brush.SetColor(color); }

        void SetBrushColor(SystemColorId system_color_id);

        const Color& GetBrushColor() const { return m_brush.GetColor(); }

        void SetBrushColorValue(ColorValue color_value) { m_brush.SetColorValue(color_value); }

        ColorValue GetBrushColorValue() const { return m_brush.GetColorValue(); }

        void SetBrushColorRgb(UINT8 red,
                              UINT8 green,
                              UINT8 blue,
                              UINT8 alpha = 255) { m_brush.SetColorRgb(red, green, blue, alpha); }

        void SetBrushColorHsv(UINT8 hue,
                              UINT8 saturation,
                              UINT8 value,
                              UINT8 alpha = 255) { m_brush.SetColorHsv(hue, saturation, value, alpha); }

        void SetBrushStyle(BrushStyle brush_style) { m_brush.SetStyle(brush_style); }

        BrushStyle GetBrushStyle() const { return m_brush.GetStyle(); }
        
        void SetClipRect(const Rect& clip_rect);

        Rect GetClipRect() const;
    
        void BeginUpdate();

        void EndUpdate();

        void UpdateDisplay() const;

        void DrawPixel(XYDIM x, XYDIM y);

        Color GetPixelColor(XYDIM x, XYDIM y) const;

        void DrawLine(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2);

        void DrawLine(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, INT thickness);

        void DrawRect(const Rect& rect, BOOLEAN fill = FALSE);

        void DrawRect(XYDIM left,
                      XYDIM top,
                      XYDIM right,
                      XYDIM bottom,
                      BOOLEAN fill = FALSE) { DrawRect(Rect(left, top, right, bottom), fill); }

        void FillRect(const Rect& rect);

        void FillRect(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom) { FillRect(Rect(left, top, right, bottom)); }
        
        void InvertRect(const Rect& rect);

        void InvertRect(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom) { InvertRect(Rect(left, top, right, bottom)); }

        void ClearRect(const Rect& rect);

        void ClearRect(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom) { ClearRect(Rect(left, top, right, bottom)); }

        void DrawCircle(XYDIM x, XYDIM y, XYDIM radius, BOOLEAN fill = FALSE);

        void FillCircle(XYDIM x, XYDIM y, XYDIM radius) {
            #ifdef APOXI_ENABLE_CIRCLE_DRAWING
                DrawRawCircle(x, y, radius, TRUE);
            #endif
        }
        
        void DrawPolygon(const XYDIM x[], const XYDIM y[], INT edges_count, BOOLEAN fill = FALSE);

        void FillPolygon(const XYDIM x[],
                         const XYDIM y[],
                         INT edges_count,
                         const BitmapRes* texture = 0);

        void DrawArc(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, INT start_angle, INT arc_angle);

        void FillArc(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, INT start_angle, INT arc_angle);

        void DrawRoundRect(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, XYDIM arc_width, XYDIM arc_height);

        void FillRoundRect(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, XYDIM arc_width, XYDIM arc_height);

        void Scroll(const Rect& rect, XYDIM dx, XYDIM dy);

        void DrawText(XYDIM x,
                      XYDIM y,
                      const WCHAR* text,
                      INT from = 0,
                      INT char_count = -1,
                      BidiManager::ParagraphContext* context = 0);

        void DrawTextInvert(XYDIM x, XYDIM y, const WCHAR* text, INT from = 0, INT char_count = -1);

        void DrawTextBox(const Rect& box_rect,
                         const WCHAR* text,
                         INT from = 0,
                         INT char_count = -1,
                         BOOLEAN center_vertical = FALSE,
                         XYDIM line_gap = 0);

        void DrawBitmap(XYDIM x,
                        XYDIM y,
                        const BitmapRes& bmp,
                        TransformationMode trans_mode = NoTransformation);
        
        void DrawGsmBitmap(XYDIM x, XYDIM y, const UINT8* src);

        XYDIM GetWidth() const { return m_width; }

        XYDIM GetHeight() const { return m_height; }
        
        Size GetTextSize(const WCHAR* text, INT from = 0, INT char_count = -1) const;

        VirtualDisplay* GetDisplay() const { return m_display; }

        XYDIM GetAbsX() const { return m_abs_x; }

        XYDIM GetAbsY() const { return m_abs_y; }

        void SetControl(Control* control);

        static BOOLEAN Obtain(const Ticks& timeout);

        static void Release() { m_sem.Release(); }

        void SetAlphaBlendingMode(AlphaBlendingMode mode);

        AlphaBlendingMode GetAlphaBlendingMode() const;

        BOOLEAN IsInForeground() { return !IsOverlappedDrawing(); }

        void SetRasterOp(RasterOp raster_op) {}

        RasterOp GetRasterOp() const { return (RasterOp)OverpaintRop; }

#if defined(APOXI_COMPAT_2_9_0)

        Size GetTextSizeForFont(const Font& font,
                                const WCHAR* text,
                                TextAttr text_attr = TextFormat::Normal,
                                INT from = 0,
                                INT char_count = -1) const;

        INT  GetTextLine(const WCHAR* text,
                         INT char_count = -1,
                         XYDIM max_width = -1,
                         BOOLEAN incl_all_ws_at_eol = FALSE,
                         Size* total_size = 0,
                         INT* ws_at_eol_nr = 0,
                         XYDIM* ws_at_eol_width = 0) const;

        INT  GetTextLineForFont(const Font& font,
                                const WCHAR* text,
                                TextAttr text_attr = TextFormat::Normal,
                                INT char_count = -1,
                                XYDIM max_width = -1,
                                BOOLEAN incl_all_ws_at_eol = FALSE,
                                Size* total_size = 0,
                                INT* ws_at_eol_nr = 0, 
                                XYDIM* ws_at_eol_width = 0) const;

        INT GetMaxTextLen(const WCHAR* text,
                          TextAttr text_attr = TextFormat::Normal,
                          XYDIM max_width = -1,
                          Size* total_size = 0,
                          INT from = 0,
                          INT char_count = -1) const;
#endif // APOXI_COMPAT_2_9_0

    protected:
        virtual void SetAbsX(XYDIM abs_x);
        virtual void SetAbsY(XYDIM abs_y);
        virtual void SetWidth(XYDIM width);
        virtual void SetHeight(XYDIM height);
        void UpdateAbsPos(XYDIM dx, XYDIM dy);
        void SetDisplay(VirtualDisplay* display) { m_display = display; }
        Control* GetControl() { return m_control; }
        virtual void AdjustBoundingRect();
        
    private:
        struct TextLine {
            INT index;
            INT count;
            INT x;
        };

        struct ClipStack {
            Rect prev_clip_rect;
            Rect cfc_rect;
            Control* prev_control;
        };

        class StylePainter {
            public:
                StylePainter(DeviceContext* dest_dc, const Rect& bounds);
                ~StylePainter();
                BOOLEAN IsValid() const { return m_bitmap_dc != 0; }
                DeviceContext* GetContext() const;

            private:
                DeviceContext* m_dest_dc;
                Bitmap* m_bitmap;
                BitmapDc* m_bitmap_dc;
                Rect m_bounds;
        };

#ifdef APOXI_ENABLE_ALPHA_BLENDING
        AlphaBlendingMode m_alpha_blend_mode;
#endif
        UINT8 m_updating;           // > 0 if BeginUpdate has been called
        BOOLEAN m_masked;
        XYDIM m_abs_x;
        XYDIM m_abs_y;
        XYDIM m_width;
        XYDIM m_height;
        VirtualDisplay* m_display;
        Pen m_pen;
        Brush m_brush;
        TextFormat m_text_format;
        Rect m_clip_rect;
        Control* m_control;         // control where drawing operations happen
        Control* m_current_control; // current control used for iterating through all controls in front of m_control

        static BOOLEAN m_initialized;
        static Semaphore m_sem;
        static const INT c_max_drawsync_recursion_depth;    // maximum allowed recursion depth
        static INT m_recursion_depth;                       // counts current recursion depth
        static ClipStack m_clip_stack[];

        void IntersectWithDisplay(Rect& rect) const;

        BOOLEAN PrepareForDrawing(Rect& rect);

        void DrawDiagLine(XYDIM left, XYDIM top, XYDIM right, XYDIM bottom);
        void DrawRawText(XYDIM x,
                         XYDIM y,
                         const WCHAR* text,
                         INT from,
                         INT char_count,
                         BidiManager::ParagraphContext* context);
        void DrawTextLine(XYDIM x1, XYDIM x2, XYDIM y);

        #ifdef APOXI_ENABLE_CIRCLE_DRAWING
            void DrawRawCircle(XYDIM x, XYDIM y, XYDIM radius, BOOLEAN fill);
            void DrawCirclePoints(XYDIM x, XYDIM y, XYDIM x_diff, XYDIM y_diff, BOOLEAN fill);
            void DrawClippedCirclePoints(XYDIM x, XYDIM y, XYDIM x_diff, XYDIM y_diff, BOOLEAN fill);
        #endif // APOXI_ENABLE_CIRCLE_DRAWING

        BOOLEAN IsOverlappedDrawing();
        void BeginOverlappedDrawing();
        void SetLeftOverlappedClipRect();
        void SetTopOverlappedClipRect();
        void SetRightOverlappedClipRect();
        void SetBottomOverlappedClipRect();
        void EndOverlappedDrawing();

        // helper methods for clipping a diagonal line
        #ifdef APOXI_ENABLE_DIAGONAL_LINE_DRAWING
            UINT8 GetClippingCode (XYDIM x, XYDIM y) const;
            XYDIM SearchMidpoint (XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, XYDIM stop_val, BOOLEAN search_for_y) const;
            BOOLEAN GetClippedPoints(XYDIM &x1, XYDIM &y1, XYDIM &x2, XYDIM &y2) const;
        #endif // APOXI_ENABLE_DIAGONAL_LINE_DRAWING

        #ifdef APOXI_ENABLE_ARC_DRAWING
            // helper methods for drawing an arc
            void DrawHorizArcLine(XYDIM x1, XYDIM y, XYDIM x2, BOOLEAN no_clip);
            void DrawVertArcLine(XYDIM x, XYDIM y1, XYDIM y2, BOOLEAN no_clip);
            void FillArcRect(XYDIM x1, XYDIM y1, XYDIM x2, XYDIM y2, BOOLEAN no_clip);
            void DrawArcPixel(XYDIM x, XYDIM y,BOOLEAN no_clip);
        #endif // APOXI_ENABLE_ARC_DRAWING
};  // DeviceContext

typedef DeviceContext::RasterOp RasterOp;

#endif  // Apoxi_DeviceContext_hpp

