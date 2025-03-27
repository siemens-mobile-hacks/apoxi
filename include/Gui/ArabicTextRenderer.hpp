/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ArabicTextRenderer_hpp)
#define Apoxi_ArabicTextRenderer_hpp

#include <Gui/AbstractTextRenderer.hpp>

class ArabicTextRenderer : public AbstractTextRenderer {
    typedef AbstractTextRenderer Base;

    public:
        virtual ~ArabicTextRenderer();

        static ArabicTextRenderer& GetInstance();

        virtual XYDIM DrawText(DeviceContext* dc,
                               const Rect& clip_rect,
                               XYDIM x, 
                               XYDIM y, 
                               const WCHAR* text, 
                               INT from, 
                               INT char_count);

        virtual INT GetTextWidth(const WCHAR* text,
                                 const Font& font,
                                 TextAttr text_attr,
                                 INT from,
                                 INT char_count,
                                 BOOLEAN include_gap = FALSE);

        virtual INT WrapLine(const WCHAR* text,
                             const Font& font,
                             TextAttr text_attr,
                             INT char_count,
                             XYDIM max_width = -1,
                             WrapPolicy policy = (WrapPolicy)0, // this awkward construction is forced on us by the egold compiler. 0 is WhitespaceWrap
                             BOOLEAN include_gap_at_end = FALSE,
                             Size* total_size = 0,
                             INT* ws_at_eol_count = 0, 
                             XYDIM* ws_at_eol_width = 0,
                             INT* last_whitespace_index = 0);

    protected:
        ArabicTextRenderer();

        virtual Size GetGlyph(const WCHAR* cur_text_pos,
                              const WCHAR* substitution_char,
                              INT n_chars,
                              GlyphPtr glyph,
                              INT& parsed_glyphs,
                              BOOLEAN& is_diacritic);

    private:
        enum CharacterPosition {
            Final = 0,
            Medial = 1,
            Initial = 2,
            Isolated = 3
        };

        BOOLEAN IsBindingLetter(WCHAR chr) const;

        INT m_direction; // direction in which the text is parsed. DrawText and GetTextWidth need R2L, WrapLine needs L2R
};


#endif // Apoxi_ArabicTextRenderer_hpp

