/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TextPackConnector_hpp)
#define Apoxi_TextPackConnector_hpp

#include <Gui/AcacTypes.hpp>
#include <Gui/BasicPackConnector.hpp>
#include <Gui/AcacLanguage.hpp>


class TextPackConnector {
    public:

        static void Init();

        static BOOLEAN IsTextPackAvailable();

        static UINT16 GetNumberOfLanguages();

        static BOOLEAN GetLanguageNames(const WCHAR **language_names, UINT32 size);

        static BOOLEAN SetActiveLanguage(EntryId id);

        static BOOLEAN SetActiveLanguageByIndex(UINT16 index);

        static BOOLEAN SetActiveLanguage(const AcacLanguage *lang);

        static EntryId GetActiveLanguageId();

        static INT32 GetIndexOfActiveLanguage();

        static const AcacLanguage *GetLanguage(EntryId id);

        static const AcacLanguage *GetLanguageAt(UINT16 index);

        static const AcacLanguage **GetLanguages();

        static const WCHAR *GetText(UINT16 index);

        static BOOLEAN ContainsLanguage(EntryId id);

        static INT32 GetIndexOfLanguage(const AcacLanguage *language);

    private:

        static const AcacLanguage *     m_active_language;

        static INT32                    m_active_language_index;

        static TextPack *               m_language_pack;
};

#endif  // Apoxi_TextPackConnector_hpp

