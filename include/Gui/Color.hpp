/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (Apoxi_Color_hpp)
#define Apoxi_Color_hpp

#if defined(APOXI_DISPLAY_32BPP) || defined (APOXI_DISPLAY_24BPP)
typedef UINT32 ColorValue;
#else
typedef UINT16 ColorValue;
#endif

class Color {
    public:
        enum SystemColorId {
            ClientBackground = 0,
            ClientForeground = 1,
            ActiveFrameBackground = 2,
            ActiveFrameForeground = 3,
            InactiveFrameBackground = 4,
            InactiveFrameForeground = 5,
            SelectionBackground = 6,
            SelectionForeground = 7,
            Shaded = 8,
            ButtonBackground = 9,
            ButtonForeground = 10,
            ContextMenuBackground = 11,
            ActiveWindowTitle = 12,
            InactiveWindowTitle = 13,
            SystemColorIdCount = 14 // mandatory last entry
        };

        Color();

        Color(ColorValue color_value);

        Color(SystemColorId system_color_id);

        Color(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha = 255);

        void SetValue(ColorValue color_value);

        ColorValue GetValue() const;

        void SetRgb(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha = 255);

        void GetRgb(UINT8& red, UINT8& green, UINT8& blue, UINT8* alpha = 0) const;

        UINT8 GetRed() const { return m_red; }

        UINT8 GetGreen() const { return m_green; }

        UINT8 GetBlue() const { return m_blue; }

        UINT8 GetAlpha() const { return m_alpha; }
        
        void SetRed(UINT8 red) { m_red = red; }
        
        void SetGreen(UINT8 green) { m_green = green; }
        
        void SetBlue(UINT8 blue) { m_blue = blue; }
        
        void SetAlpha(UINT8 alpha) { m_alpha = alpha; }
        
        // SetHsv not implemented yet.
        /*  Sets the color to the value represented by hue, saturation and
            the value. Optionally an alpha-channel can be specified.*/
        void SetHsv(UINT16 hue, UINT8 saturation, UINT8 value, UINT8 alpha = 255);

        BOOLEAN operator==(const Color& color) const;

        BOOLEAN operator!=(const Color& color) const;

        Color Blend(const Color& background) const;
        
        ColorValue Blend(ColorValue background) const;
        
        static ColorValue Blend(ColorValue foreground, ColorValue background, UINT8 alpha = 255);

    private:
        UINT8 m_red;
        UINT8 m_green;
        UINT8 m_blue;
        UINT8 m_alpha;
};

typedef Color::SystemColorId SystemColorId;
typedef ColorValue SystemColor;     // obsolete since APOXI-1.6.3; simply use ColorValue instead

#endif  // Apoxi_Color_hpp


