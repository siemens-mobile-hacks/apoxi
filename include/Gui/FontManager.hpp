/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FontManager_hpp)
#define Apoxi_FontManager_hpp

#include <Gui/FontPackConnector.hpp>
#include <Gui/AcacTypes.hpp>
#include <Gui/TextFormat.hpp>

class FontManager {
    public:
        static BOOLEAN CanDisplay(WCHAR chr,
                                  INT index = m_active_font_index);

        static UINT16 GetNumberOfFonts();

        static UINT8 GetHeight(INT index = m_active_font_index);

        static const FontEntry* GetFont(INT index);

        static const FontEntry* GetFont(const WCHAR* name, UINT8 height);

        static INT GetIndexOfFont(const WCHAR* name, UINT8 height);

        static EntryId GetIdOfFont(const WCHAR *name, UINT8 height);

        static BOOLEAN SetActiveFont(INT index);

        static INT GetActiveFontIndex();

        static BOOLEAN SupportsUnicodeRange(WCHAR from,
                                            WCHAR to,
                                            INT index = m_active_font_index);

        static BOOLEAN GetGlyph(WCHAR chr, Glyph &glyph,
                                TextAttr text_attr = TextFormat::Normal,
                                INT font_index = m_active_font_index);

        static BOOLEAN GetGlyphs(const WCHAR *chr,
                                Glyph* glyphs,
                                INT count,
                                TextAttr text_attr = TextFormat::Normal,
                                INT font_index = m_active_font_index);

        static BOOLEAN SupportsStyle(WCHAR chr, TextAttr text_attr, INT index = m_active_font_index);

        static const WCHAR* GetFontName(INT index = m_active_font_index);

        static const WCHAR* GetFontFamilyName(INT index = m_active_font_index);

        static UINT8 GetBaseline(INT index = m_active_font_index);

        static INT GetNumGlyphs(INT index = m_active_font_index);

        static UINT8 GetGapToNextChar(WCHAR chr = 0, INT index = m_active_font_index);

        static void SetUseStaticFonts(BOOLEAN value);

        static BOOLEAN UseStaticFonts();

    private:

        static BOOLEAN GetGlyphs(const WCHAR *chr,
                                Glyph *glyphs,
                                INT count,
                                const FontEntry *font_entry,
                                TextAttr text_attr = TextFormat::Normal);


        static INT m_active_font_index;

        static BOOLEAN m_use_static_fonts;
};
#endif //Apoxi_FontManager_hpp


