/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ThemeConfig_hpp)
#define Apoxi_ThemeConfig_hpp

class Theme;
#include <Kernel/Types.hpp>

class ThemeConfig {
    public:
        static const Theme& GetTheme(INT idx);

        static INT GetThemeCount();

        static INT GetFontId(SystemFontId id, const Theme &theme);
};

#endif  // Apoxi_ThemeConfig_hpp

