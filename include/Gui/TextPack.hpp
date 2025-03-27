/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextPack_hpp)
#define Apoxi_TextPack_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/AcacLanguage.hpp>
#include <Gui/DataPack.hpp>

class TextPack : public DataPack {
    public:
        typedef DataPack Base;

        TextPack(const UINT8 *data);

        virtual ~TextPack();

        const AcacLanguage *GetLanguage(UINT16 index) const;

    private:
        TextPackData*       m_text_pack_data;

        AcacLanguage **     m_languages;

        friend class BasicPackConnector;
};
#endif //Apoxi_TextPack_hpp


