/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Pen_hpp)
#define Apoxi_Pen_hpp

#include <Gui/Color.hpp>

class Pen {
    public:
        enum PenStyle {
            Solid,
            Dotted,
            Dashed,
            SemiDashed
        };

        Pen(PenStyle style = Solid, Color color = Color());

        void SetStyle(PenStyle style) { m_style = style; }

        PenStyle GetStyle() const { return m_style; }

        void SetColor(const Color& color) { m_color = color; }

        const Color& GetColor() const { return m_color; }

        void SetColorValue(ColorValue color_value) { m_color.SetValue(color_value); }

        ColorValue GetColorValue() const { return m_color.GetValue(); }

        void SetColorRgb(UINT8 red, UINT8 green, UINT8 blue, UINT8 alpha = 255) { m_color.SetRgb(red, green, blue, alpha); }

        void SetColorHsv(UINT8 hue, UINT8 saturation, UINT8 value, UINT8 alpha = 255) { m_color.SetHsv(hue, saturation, value, alpha); }

    private:
        PenStyle    m_style;
        Color       m_color;
};

typedef Pen::PenStyle PenStyle;

#endif  // Apoxi_Pen_hpp


