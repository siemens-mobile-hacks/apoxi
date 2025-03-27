/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_JapaneseTextRenderer_hpp)
#define Apoxi_JapaneseTextRenderer_hpp

#include <Gui/AbstractTextRenderer.hpp>
#include <Gui/EditorDocument.hpp>

class JapaneseTextRenderer : public AbstractTextRenderer {
    typedef AbstractTextRenderer Base;

    public:
        virtual ~JapaneseTextRenderer();

        static JapaneseTextRenderer& GetInstance();

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
                             INT* last_completely_fitting_word_length = 0);

    protected:
        virtual Size GetGlyph(const WCHAR* cur_text_pos,
                              const WCHAR* substitution_char,
                              INT n_chars,
                              GlyphPtr glyph,
                              INT& parsed_glyphs,
                              BOOLEAN& is_diacritic);

    private:
        JapaneseTextRenderer();

        BOOLEAN IsAllowedAsLineStart(WCHAR chr) const;

        BOOLEAN IsAllowedAsLineEnd(WCHAR chr) const;
};


#endif // Apoxi_JapaneseTextRenderer_hpp

