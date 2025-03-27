/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AcacLanguage_hpp)
#define Apoxi_AcacLanguage_hpp

#include <Gui/AcacTypes.hpp>

class AcacLanguage {
    public:
        AcacLanguage(const LanguageData *data);


        virtual ~AcacLanguage();

        EntryId GetId() const { return m_data->id; };

        const WCHAR *GetName() const { return m_data->name; };

        const WCHAR *GetNativeName() const { return m_data->native_name; };

        UINT16 GetNumberOfStrings() const { return m_data->string_count; };

        const WCHAR* GetText(UINT16 index) const;

        INT32 GetIndexOf(const WCHAR *text) const;

    private:
        const LanguageData *        m_data;

        const TranslationTable *    m_trans_table;
};

#endif  // Apoxi_AcacLanguage_hpp

