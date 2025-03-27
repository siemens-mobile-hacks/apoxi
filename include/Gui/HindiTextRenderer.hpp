/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_HindiTextRenderer_hpp)
#define Apoxi_HindiTextRenderer_hpp

#include <Gui/AbstractTextRenderer.hpp>

class HindiTextRenderer : public AbstractTextRenderer {
    typedef AbstractTextRenderer Base;

    public:
        virtual ~HindiTextRenderer();

        static HindiTextRenderer& GetInstance() { return m_instance; }

    protected:
        HindiTextRenderer();

        virtual Size GetGlyph(const WCHAR* cur_text_pos,
                              const WCHAR* substitution_char,
                              INT n_chars,
                              GlyphPtr glyph,
                              INT& parsed_glyphs,
                              BOOLEAN& is_diacritic);

    private:
        static HindiTextRenderer m_instance;
};


#endif // Apoxi_HindiTextRenderer_hpp

