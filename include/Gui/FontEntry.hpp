/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FontEntry_hpp)
#define Apoxi_FontEntry_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/TextFormat.hpp>
#include <Gui/Font.hpp>

class FontEntry : public Font{
    typedef Font Base;

    public:

        FontEntry(const FontData *data, const GlyphData *glyphs);

        virtual ~FontEntry();

        EntryId GetId() const { return m_data->id; };

        virtual const WCHAR *GetName() const;

        virtual void GetGlyph(WCHAR chr, TextAttr text_attr, GlyphPtr glyph) const;

        virtual INT GetHeight() const;

        virtual INT GetBaseline() const;

        virtual INT GetGapToNextChar(WCHAR character = 0) const;

        virtual BOOLEAN SupportsTextAttr(TextAttr text_attr) const;

        const WCHAR *GetFontFamilyName() const;

        BOOLEAN SupportsUnicodeRange(WCHAR from, WCHAR to) const;

        UINT16 GetNumGlyphs() const;

        BOOLEAN SupportsStyle(WCHAR chr, TextAttr text_attr) const;

    protected:
        UINT8 *GetGlyphStartPos(WCHAR chr) const;

    private:

        const FontData *        m_data;

        const GlyphData *       m_glyphs;

        Glyph                   m_invalid_glyph;
};
#endif //Apoxi_FontEntry_hpp


