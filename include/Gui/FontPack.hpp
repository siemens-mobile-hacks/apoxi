/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FontPack_hpp)
#define Apoxi_FontPack_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/FontEntry.hpp>
#include <Gui/DataPack.hpp>

class FontPack : public DataPack {
    public:
        typedef DataPack Base;

        FontPack(UINT8 *data);

        virtual ~FontPack();

        const FontEntry *GetFont(INT index) const;

        const FontEntry **GetFonts() const;

    private:

        FontPackData *      m_font_pack_data;

        FontEntry **        m_fonts;

        friend class BasicPackConnector;
};
#endif //Apoxi_FontPack_hpp


