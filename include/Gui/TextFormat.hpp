/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextFormat_hpp)
#define Apoxi_TextFormat_hpp

#include <Config/GuiObjectFactory.hpp>

class Font;
class ResourceParser;

class TextFormat {
    public:
        enum TextAlign {
            Default,
            Left,
            Centered,
            Right
        };

        typedef UINT8 TextAttr;

        //  Note: If you extend TextAttr, don't forget to increase the bit-vector in the
        //  class TextFormat.
        enum TextAttrValues {
            Normal          = 0,
            Underlined      = (1 << 0),
            Italic          = (1 << 1),
            Bold            = (1 << 2),
            Strikethrough   = (1 << 3)
        };

        enum FontAlign {
            Top,
            Baseline,
            Bottom
        };

        TextFormat();

        TextFormat(INT system_font_id,
                   TextAlign text_align = Default, 
                   TextAttr text_attr = TextFormat::Normal, 
                   FontAlign font_align = Top);

        TextFormat(const Font& font,
                   TextAlign text_align = Default, 
                   TextAttr text_attr = TextFormat::Normal, 
                   FontAlign font_align = Top);

        void Init(INT system_font_id,
                  TextAlign text_align = Default, 
                  TextAttr text_attr = Normal, 
                  FontAlign font_align = Top);

        void Init(const Font& font,
                  TextAlign text_align = Default, 
                  TextAttr text_attr = Normal, 
                  FontAlign font_align = Top);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id);

        void SetFont(const Font& font);

        void SetFont(INT system_font_id);

        const Font& GetFont() const;

        void SetTextAlign(TextAlign text_align) { m_bits.text_align = text_align; }

        TextAlign GetTextAlign() const { return (TextAlign)m_bits.text_align; }

        void SetTextAttr(TextAttr text_attr) { m_bits.text_attr = text_attr; }

        TextAttr GetTextAttr() const { return (TextAttr)m_bits.text_attr; }

        void SetFontAlign(FontAlign font_align) { m_bits.font_align = font_align; }

        FontAlign GetFontAlign() const { return (FontAlign)m_bits.font_align; }

        BOOLEAN operator==(const TextFormat& text_format) const;
        BOOLEAN operator!=(const TextFormat& text_format) const;

    private:
        struct {
            UINT text_align      : 2;
            UINT text_attr       : 4;
            UINT font_align      : 2;
            UINT use_system_font : 1;
        } m_bits;
        union {
            const Font* m_font;
            INT m_system_font_id;
        };
};

typedef TextFormat::TextAlign TextAlign;
typedef TextFormat::FontAlign FontAlign;
typedef TextFormat::TextAttr TextAttr;

#endif  // Apoxi_TextFormat_hpp


