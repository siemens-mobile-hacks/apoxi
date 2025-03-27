/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_LanguageManager_hpp)
#define Apoxi_LanguageManager_hpp

#if !defined(APOXI_MAX_LANGUAGE_COUNT)
#define APOXI_MAX_LANGUAGE_COUNT 16
#endif

#include <Kernel/Types.hpp>
#include <Gui/TextPackConnector.hpp>

class LanguageManager {
    public:
        enum LanguageType {
            English, German, Chinese, Arabic, Thai, Hebrew, Vietnamese, Japanese,
            Hindi, Italian, French, Greek, Afrikaans, Albanian, Armenian, Basque,
            Breton, Catalan, Corsican, Croatian, Czech, Danish, Dutch, Esperanto,
            Estonian, Finnish, Hungarian, Icelandic, Indonesian, Irish,
            Latin, Latvian, Lithuanian, Macedonian, Malay, Maltese, Norwegian,
            Polish, Portuguese, Romanian, Serbian, Slovak, Slovenian, Spanish,
            Swahili, Swedish, Turkish, Xhosa, Zulu, Bulgarian, Byelorussian,
            Russian, SerboCroatian, Ukrainian
        };

        static void SetActiveLanguage(INT lang_id);

        static INT GetActiveLanguage() { return m_active_lang_id; }

        static BOOLEAN HasActiveLanguageChanged() { return m_has_lang_changed; }

        static void SetActiveLanguageType(LanguageType lang_type);

        static LanguageType GetActiveLanguageType();

        static const WCHAR* Translate(const WCHAR* text, INT ambiguous_hint = -1);
        
        static const WCHAR* ReTranslate(const WCHAR* text);

        static INT MapIso639(const WCHAR* code);

        static const WCHAR* GetString(INT index);
        
    private:
        static BOOLEAN m_has_lang_changed;
        static BOOLEAN m_initialized;
        static INT m_active_lang_id;
        static INT16 m_last_lang[APOXI_MAX_LANGUAGE_COUNT];
};

extern const WCHAR* Tr(const WCHAR* text);

extern const WCHAR* AmbiguousTr(const WCHAR* text, INT ambiguous_hint);

#endif  // Apoxi_LanguageManager_hpp

