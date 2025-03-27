/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RomFont_hpp)
#define Apoxi_RomFont_hpp

#include <Kernel/Types.hpp>
#include <Gui/Font.hpp>

class RomFont : public Font {
    typedef Font Base;
    
    public:
        RomFont();

        RomFont(const FontRes& font_res);

        virtual ~RomFont();

        void Set(const FontRes& font_res) { m_font_res = font_res; }

        virtual const WCHAR* GetName() const;

        virtual void GetGlyph(WCHAR chr, TextAttr text_attr, GlyphPtr glyph) const;

        virtual INT GetHeight() const;

        virtual INT GetBaseline() const;

        virtual INT GetGapToNextChar(WCHAR character = 0) const;

        virtual BOOLEAN SupportsTextAttr(TextAttr text_attr) const;

    private:
        FontRes m_font_res;
};

#endif  // Apoxi_RomFont_hpp


