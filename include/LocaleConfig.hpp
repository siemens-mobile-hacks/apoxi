/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_LocaleConfig_hpp)
#define Apoxi_LocaleConfig_hpp

#include <Kernel/Types.hpp>
#include <Gui/Locale.hpp>

struct PagingMap;

class LocaleConfig {
    public:
        static INT GetSettingsCount();

        static const Locale::LocaleData& GetSetting(INT idx);

        static INT GetLanguageCount();

        static INT GetLanguageId(const WCHAR* iso2_code);

        static LanguageManager::LanguageType GetLanguageType(INT lang_id);

        static INT GetStringCount();

        static const WCHAR* const* GetTranslationTable();

        static const PagingMap& GetPagingMap(INT idx);
};

#endif  // Apoxi_LocaleConfig_hpp

