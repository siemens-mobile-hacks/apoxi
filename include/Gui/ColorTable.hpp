/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ColorTable_hpp)
#define Apoxi_ColorTable_hpp

struct Palette {
    UINT8 red;
    UINT8 green;
    UINT8 blue;
};

struct ColorTable {
    INT GetColorCount() const       { return m_color_count; }
    UINT8 GetRed(INT index) const   { return m_palette[index].red; }
    UINT8 GetGreen(INT index) const { return m_palette[index].green; }
    UINT8 GetBlue(INT index) const  { return m_palette[index].blue; }
    const Palette* GetRgb(INT index) const { return &m_palette[index]; }

    const Palette* m_palette;
    INT m_color_count;
};

#endif  // Apoxi_ColorTable_hpp


