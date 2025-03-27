/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FontConfig_hpp)
#define Apoxi_FontConfig_hpp

#include <Kernel/Types.hpp>
#include <Gui/ThaiTextRenderer.hpp>

class Font;

class FontConfig {
    public:
        static const Font& GetFont(INT idx);

        static INT GetFontCount();

        static ThaiTextRenderer::ThaiFontHint* GetThaiFontHints(const Font& font);
};

#endif  // Apoxi_FontConfig_hpp

