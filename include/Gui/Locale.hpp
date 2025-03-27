/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Locale_hpp)
#define Apoxi_Locale_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>

struct PagingMap;

class Locale {
    public:
        enum TextAlignment {
            LeftToRight,
            RightToLeft
        };

        struct LocaleData {
            const WCHAR     **times;
            const WCHAR     **dates;
            WCHAR           decimal_separator;
            WCHAR           thousand_separator;
            const WCHAR     *currency_symbol;
            INT             lang_id;
            TextAlignment   text_align;
        };
        
        static void Set(const LocaleData& locale_data);

        static void SetTimeFormat(TimeFormat time_format, const WCHAR* time_str) { m_locale.times[time_format] = time_str; }

        static const WCHAR* GetTimeFormat(TimeFormat time_format) { return m_locale.times[time_format]; }

        static void SetDateFormat(DateFormat date_format, const WCHAR* date_str) { m_locale.dates[date_format] = date_str; }

        static const WCHAR* GetDateFormat(DateFormat date_format) { return m_locale.dates[date_format]; }

        static void SetDecimalSeparator(WCHAR separator) { m_locale.decimal_separator = separator; }

        static WCHAR GetDecimalSeparator() { return m_locale.decimal_separator; }

        static void SetThousandSeparator(WCHAR separator) { m_locale.thousand_separator = separator; }

        static WCHAR GetThousandSeparator() { return m_locale.thousand_separator; }

        static void SetCurrencySymbol(const WCHAR* symbol) { m_locale.currency_symbol = symbol; }

        static const WCHAR* GetCurrencySymbol() { return m_locale.currency_symbol; }

        static void SetLanguage(INT lang_id) { m_locale.lang_id = lang_id; }

        static INT GetLanguage() { return m_locale.lang_id; }

        static void SetTextAlignment(TextAlignment text_align) { m_locale.text_align = text_align; }

        static TextAlignment GetTextAlignment() { return m_locale.text_align; }

    private:
        static LocaleData m_locale;
};

#endif  // Apoxi_Locale_hpp


