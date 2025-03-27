/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(AddOns_Translation_ValueTextMap_hpp)
#define AddOns_Translation_ValueTextMap_hpp

#include <Kernel/Types.hpp>

class ValueTextMap {
    public:
        struct Table {
            INT value;
            const WCHAR *text;
        };  // ValueTextMapStruct 

        explicit ValueTextMap(const Table *table_ref = 0);

        ~ValueTextMap();

        const WCHAR* GetText (INT value) const;

        static INT InvalidValue() { return (m_invalid_value); }

        static const WCHAR* InvalidText() { return (&m_invalid_char); }

    private:
        static const INT m_invalid_value;
        static const WCHAR m_invalid_char;      // guaranteed invalid unicode character
        static const WCHAR *m_value_not_found;
        static const WCHAR *m_table_not_exists;
        const Table *m_table_ref;
};  // ValueTextMap

#endif  // AddOns_Translation_ValueTextMap_hpp


