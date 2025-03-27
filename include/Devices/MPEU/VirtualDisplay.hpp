/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------*/

#if !defined(Apoxi_Devices_MPEU_VirtualDisplay_hpp)
#define Apoxi_Devices_MPEU_VirtualDisplay_hpp

class VideoChannel;

#include <Kernel/Types.hpp>
#include <Devices/AbstractDevice.hpp>
#include <Gui/Bitmap.hpp>
#include <Gui/Rect.hpp>
#include <Gui/ColorTable.hpp>
#include <Gui/Color.hpp>
#include <Gui/Font.hpp>
#include <Kernel/Os/SystemTimer.hpp>

class VirtualDisplay : public AbstractDevice {
    typedef AbstractDevice Base;
    
    public:
        enum Type {
            Monochrome,
            Planes2,
            Planes4,
            Planes8,
            BitsPerPixel8,
            BitsPerPixel16,
            BitsPerPixel24,
            BitsPerPixel32
        };

        VirtualDisplay(INT index = 0);

        VirtualDisplay(XYDIM width, XYDIM height, INT bits_per_pixel, BOOLEAN planes = FALSE, DDrvAtomPtr buffer = 0);

        VirtualDisplay(Bitmap* bitmap, INT bits_per_pixel, BOOLEAN planes = FALSE);

        virtual ~VirtualDisplay();

        void Init(XYDIM width, XYDIM height,  INT bits_per_pixel, BOOLEAN planes = FALSE, DDrvAtomPtr buffer = 0);

        void Init(Bitmap* bitmap, INT bits_per_pixel, BOOLEAN planes = FALSE);

        virtual const WCHAR* GetName() const;
                
        ControlArg Control(INT command, ControlArg arg);

        XYDIM GetWidth() const { return m_bitmap.GetWidth();}

        XYDIM GetHeight() const { return m_bitmap.GetHeight(); }
    
        Bitmap* GetBitmap() { return &m_bitmap; }

        Type GetType() { return m_type; }

        void SetBlitRect(const Rect& rect = Rect()) { m_blit_rect = rect; }

        const Rect& GetBlitRect() const { return m_blit_rect; };

        void AdjustBlitRect(const Rect& rect) { m_blit_rect.Union(rect); }

        virtual void Refresh();
        
        void SetPixel(XYDIM x, XYDIM y);
        
        void FillRect(const Rect& rect);

            void BitBlit(XYDIM dest_x,
                     XYDIM dest_y,
                     const BitmapRes& bmp,
                     const Rect& clip_rect,
                     UINT8 trans_mode = 0);

        void Scroll(const Rect& rect, XYDIM dx, XYDIM dy);

        void DrawChar(XYDIM x, XYDIM y, const Glyph& glyph, INT height);

        void SetColorValue(ColorValue color_value, UINT8 alpha = 255);

        ColorValue GetColorValue() const { return m_color_value; }

        void SetColor(Color color);

        Color GetColor() const { return m_color; }

        ColorValue ConvertToColorValue(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha) const;

        Color GetPixelColor(XYDIM x, XYDIM y) const;
        
        INT GetScanlineAtomCount() const { return m_scanline_atom_count; }

        void SetAlphaBlendingMode(BOOLEAN mode) { 
                                                    #ifdef APOXI_ENABLE_ALPHA_BLENDING
                                                        m_alpha_mode = mode; 
                                                    #endif
                                                }

        BOOLEAN GetAlphaBlendingMode() const { 
                                                #ifdef APOXI_ENABLE_ALPHA_BLENDING
                                                    return m_alpha_mode; 
                                                #else
                                                    return TRUE;
                                                #endif
                                                }
    private:
#ifdef APOXI_ENABLE_ALPHA_BLENDING
        BOOLEAN m_alpha_mode;
#endif
        Bitmap m_bitmap;
        Rect m_blit_rect;
        Type m_type;
        ColorValue m_color_value;
        Color m_color;
        INT m_pixel_atom_count;
        INT m_scanline_atom_count;
        INT m_plane_count;
        INT m_scanline_inc;
        INT m_plane_inc;
        DDrvAtomPtr m_data;
        DDrvAtomPtr m_scanline_buffer;

        void ScrollHorizontal(const Rect& rect, XYDIM dx);
        void ScrollVertical(const Rect& rect, XYDIM dy);
};

class ScanlineAccessor {
    public:
        ScanlineAccessor(VirtualDisplay* display, XYDIM x, XYDIM y, XYDIM width) :
            m_data((UINT16 GDI_HUGE*)display->GetBitmap()->GetBits()),
            m_count(width)
        {
            m_data += (display->GetScanlineAtomCount() >> 1) * y + x;
        }

        BOOLEAN HasNext() { return (m_count > 0); };

        void Draw(UINT8 red, UINT8 green, UINT8 blue)
        {
            *m_data = ((ColorValue)((((red) >> 3U) << 11U) | (((green) >> 2U) << 5U) | ((blue) >> 3U)));
            
            #if defined(APOXI_DISPLAY_FORMAT_BIG_ENDIAN)
                *m_data = ((*m_data & 0xffU) << 8U) | ((*m_data & 0xff00U)) >> 8U;
            #endif
            m_data++;
            m_count--;
        }
        
        void Draw(ColorValue cv)
        {
            *m_data = cv;
            m_data++;
            m_count--;
        }

        void Next() {
            m_data++;
            m_count--;
        }

    private:
        UINT16 GDI_HUGE* m_data;
        XYDIM m_count;
        
};

#endif  // Apoxi_Devices_MPEU_VirtualDisplay_hpp

