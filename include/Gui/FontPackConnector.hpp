/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FontPackConnector_hpp)
#define Apoxi_FontPackConnector_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/BasicPackConnector.hpp>
#include <Gui/FontEntry.hpp>
#include <Gui/FontPack.hpp>

class FontPackConnector {
    public:
        static void Init();

        static BOOLEAN IsFontPackAvailable();

        static INT GetNumberOfFonts();

        static BOOLEAN GetFontNames(const WCHAR **font_names, INT size);

        static BOOLEAN SetActiveFont(const INT index);

        static INT GetActiveFontIndex();

        static const FontEntry *GetFont(INT index);

        static BOOLEAN ContainsFont(FontId id);

    private:
        static INT                  m_active_font_index;

        static FontEntry *          m_active_font;

        static FontPack *           m_font_pack;

};
#endif //Apoxi_FontPackConnector_hpp


