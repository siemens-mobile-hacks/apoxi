/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ThaiTextRenderer_hpp)
#define Apoxi_ThaiTextRenderer_hpp

#include <Gui/AbstractTextRenderer.hpp>
#include <Gui/EditorDocument.hpp>
#include <Auxiliary/WString.hpp>

class ThaiTextRenderer : public AbstractTextRenderer {
    typedef AbstractTextRenderer Base;

    public:
        enum CharacterClass {
            Ctrl = 0,   // Control character
            Non = 1,    // Non-Thai character
            Cons = 2,   // Consonant
            LV = 3,     // Leading Vowel
            FV1 = 4,    // Following Vowel, Type 1
            FV2 = 5,    // Following Vowel, Type 2
            FV3 = 6,    // Following Vowel, Type 3
            BV1 = 7,    // Below Vowel, Type 1
            BV2 = 8,    // Below Vowel, Type 2
            BD = 9,     // Below Diacritic
            Tone = 10,  // Tone
            AD1 = 11,   // Above Diacritic, Type 1
            AD2 = 12,   // Above Diacritic, Type 2
            AD3 = 13,   // Above Diacritic, Type 3
            AV1 = 14,   // Above Vowel, Type 1
            AV2 = 15,   // Above Vowel, Type 2
            AV3 = 16    // Above Vowel, Type 3
        };

        enum RenderType {
            Render = 0,     
            Compose = 1,    
            Control = 2     
        };

        virtual ~ThaiTextRenderer();

        static ThaiTextRenderer& GetInstance();

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

        virtual BOOLEAN IsStandaloneCharacter(const WCHAR* text,
                                              INT index);

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

        struct ThaiFontHint {
            XYDIM (*m_cons_offsets)[46];            




            XYDIM (*m_diacritics_offsets)[19][5];   











            XYDIM m_above_level_y_offset;           
            XYDIM m_top_level_y_offset;             
            XYDIM m_lo_chula_y_offset;              
            XYDIM m_mai_tho_toplevel_x_offset;      

            XYDIM m_yo_ying_diacritic_lines;        

            XYDIM m_tho_than_diacritic_lines;       

        };

    protected:
        ThaiTextRenderer();

        virtual BOOLEAN BeginGlyphRetrieval(const WCHAR* text_start,
                                            const Font& font,
                                            TextAttr text_attr);

        virtual Size GetGlyph(const WCHAR* cur_text_pos,
                              const WCHAR* substitution_char,
                              INT char_count,
                              GlyphPtr glyph,
                              INT& parsed_glyphs,
                              BOOLEAN& is_diacritic);

    private:
        INT PrepareText(const WCHAR* text, INT from, INT char_count);

        CharacterClass GetThaiCharacterClass(WCHAR chr) const;

        RenderType GetThaiRenderType(WCHAR cur_char, WCHAR prev_char) const;

        BOOLEAN HasAscender(WCHAR chr) const;

        INT8 GetDiacriticsIndex(WCHAR chr) const;

        WString m_buffer;

        XYDIM m_prev_x_offset;

        ThaiFontHint* m_font_hints;

        Glyph m_yo_ying;
        UINT8 FONT_HUGE* m_yo_ying_data;
        Glyph m_tho_than;
        UINT8 FONT_HUGE* m_tho_than_data;

        BOOLEAN m_contains_sara_am;
        BOOLEAN m_calculate_diacritic_offsets;
};


#endif // Apoxi_SimpleTextRenderer_hpp

