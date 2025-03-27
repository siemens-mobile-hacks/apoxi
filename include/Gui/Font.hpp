/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Font_hpp)
#define Apoxi_Font_hpp

#include <Kernel/Types.hpp>
#include <Gui/TextFormat.hpp>

// Internal 
struct Glyph {
    INT GetWidth() const { return m_width; }
    const UINT8 FONT_HUGE* GetData() const { return m_data; }

    INT m_width;                    // Character width in pixels
    const UINT8 FONT_HUGE* m_data;  // Pointer to the character bitmap
};

#define GlyphPtr Glyph FONT_HUGE* 

// Internal 
struct GlyphHeader {
    UINT16 m_offset;                // Offset of the bitmap-data
    UINT8 m_low_byte;               // Low-byte of unicode-character
    UINT8 m_width;                  // Width of the character
};

#define GlyphHeaderPtr GlyphHeader FONT_HUGE* 

// The following definition allows a more readable forward-declaration for generated fonts
#define GlyphTab struct { GlyphHeader* m_glyph_header; UINT8* m_data; }

// Internal 
struct GlyphIndexTab {
    UINT8 m_glyph_count[256];               // Number of glyphs - 1!
    const GlyphHeaderPtr m_glyph_tab[256];
};

#define GlyphIndexTabPtr GlyphIndexTab FONT_HUGE* 

// Internal 
struct FontRes {
    XYDIM height;
    XYDIM baseline;
    XYDIM gap_to_next_char;
    const GlyphIndexTabPtr normal_glyph_index_tab;
    const GlyphIndexTabPtr italic_glyph_index_tab;
    const GlyphIndexTabPtr bold_glyph_index_tab;
    const GlyphIndexTabPtr italic_bold_glyph_index_tab;
    const WCHAR* name;
    Glyph invalid_glyph;
};

class Font {
    public:
        enum SystemFontId {
            Client = 0,
            ActiveTitle,
            InactiveTitle,
            Softkeys,
            Menu,
            TextEditor,
            SystemFontIdCount   // mandatory last entry
        };

        Font();

        virtual ~Font();

        virtual const WCHAR* GetName() const = 0;

        virtual void GetGlyph(WCHAR chr, TextAttr text_attr, GlyphPtr glyph) const = 0;

        virtual INT GetHeight() const = 0;

        virtual INT GetBaseline() const = 0;

        virtual INT GetGapToNextChar(WCHAR character = 0) const = 0;

        virtual BOOLEAN SupportsTextAttr(TextAttr text_attr) const = 0;

        INT GetTextWidth(const WCHAR* text,
                         TextAttr text_attr,
                         INT from = 0,
                         INT n_chars = -1,
                         BOOLEAN include_gap = FALSE) const;

        BOOLEAN operator == (const Font& font) const;

        BOOLEAN operator != (const Font& font) const { return !(*this == font); }
};

typedef Font::SystemFontId SystemFontId;

#endif  // Apoxi_Font_hpp


