/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractTextRenderer_hpp)
#define Apoxi_AbstractTextRenderer_hpp

#include <Gui/DeviceContext.hpp>
#include <Gui/EditorDocument.hpp>
#include <Gui/Font.hpp>

class AbstractTextRenderer {
    public:
        virtual ~AbstractTextRenderer();

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
                             INT* last_whitespace_index = 0);

        static XYDIM GetItalicIncrement(INT font_height);

        static Vector<INT> GetWrapPositions(const WCHAR* text,
                                            const Font& font,
                                            TextAttr text_attr,
                                            WrapPolicy policy,
                                            XYDIM width);


    protected:
        AbstractTextRenderer();

        virtual BOOLEAN BeginGlyphRetrieval(const WCHAR* text_start,
                                            const Font& font,
                                            TextAttr text_attr);

        virtual void EndGlyphRetrieval();

        virtual Size GetGlyph(const WCHAR* cur_text_pos,
                              const WCHAR* substitution_char,
                              INT char_count,
                              GlyphPtr glyph,
                              INT& parsed_glyphs,
                              BOOLEAN& is_diacritic) = 0;

        void DrawGlyphInItalic(VirtualDisplay* display,
                               INT font_height,
                               const Glyph& glyph,
                               XYDIM x,
                               XYDIM y,
                               const Rect& clip_rect);

        BOOLEAN ObtainMutex() { return m_mutex.Obtain(); }

        void ReleaseMutex() { m_mutex.Release(); }

        const WCHAR* m_text_start;

        const Font* m_font;

        TextAttr m_text_attr;

    private:
        Mutex m_mutex;
};


#endif // Apoxi_AbstractTextRenderer_hpp

