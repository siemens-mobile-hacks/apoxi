/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Date_h)
#define Apoxi_Date_h

#include <Auxiliary/WString.hpp>

class Date {
    public:
        enum Format {
            ShortDateDM,
            ShortDateWDM,
            ShortDateDMY,
            ShortDateWDMY,
            LongDateDM,
            LongDateWDM,
            LongDateDMY,
            LongDateWDMY,
        };

        enum Day {
            Monday = 0,
            Tuesday = 1,
            Wednesday = 2,
            Thursday = 3,
            Friday = 4,
            Saturday = 5,
            Sunday = 6
        };

        enum Month {
            January = 1,
            February = 2,
            March = 3,
            April = 4,
            May = 5,
            June = 6,
            July = 7,
            August = 8,
            September = 9,
            October = 10,
            November = 11,
            December = 12
        };

        enum PresetDate {
            Today,
            Tomorrow,
            TheDayAfterTomorrow,
            Yesterday,
            TheDayBeforeYesterday
        };

        // struct must not be larger then 32 bit because of DataItem usage
        struct Persist {
            UINT8  m_day;
            UINT8  m_month;
            UINT16 m_year;
        };

        Date();
        Date(PresetDate pd);
        Date(INT day,INT month,INT year);

        Date(const Persist & dstruct);

        BOOLEAN IsZero() const;

        BOOLEAN IsValid(const BOOLEAN accept_zeroed_date = TRUE) const;

        INT GetDay() const { return m_day; }
        INT GetMonth() const { return m_month; }
        INT GetYear() const { return m_year; }              // YYYY Format
        INT GetYearYY() const;                              // YY Format
        INT GetYearYYYY() const { return m_year; }          // YYYY Format

        void SetDay(INT day) { m_day = day; }
        void SetMonth(INT month) { m_month = month; }
        void SetYear(INT year) { m_year = year; }           // YYYY Format

        const WCHAR* MonthName() const { return MonthName(m_month); }
        const WCHAR* ShortMonthName() const { return ShortMonthName(m_month); }
        const WCHAR* DayName() const { return DayName(DayOfWeek()); }
        const WCHAR* ShortDayName() const { return ShortDayName(DayOfWeek()); }

        WString GetWString(Format date_format) const;
        WString GetWString(const WCHAR *format) const;

        BOOLEAN IsLeapYear() const { return IsLeapYear(m_year); }

        INT DayOfYear() const;
        INT WeekOfYear() const;
        Day DayOfWeek() const;

        INT DaysInMonth() const;

        INT DaysInYear() const  { return DaysInYear(m_year); }

        void AddDays(INT ndays);

        BOOLEAN operator==(const Date &date) const;

        BOOLEAN operator!=(const Date &date) const;

        BOOLEAN operator<(const Date &date) const;

        BOOLEAN operator<=(const Date &date) const;

        BOOLEAN operator>(const Date &date) const;

        BOOLEAN operator>=(const Date &date) const;

        static INT Compare(const Date::Persist & t1, const Date::Persist & t2);

        void operator<<(const Date::Persist & date);
        void operator>>(Date::Persist & date) const;

        static const WCHAR* MonthName(INT month);
        static const WCHAR* ShortMonthName(INT month);
        static const WCHAR* DayName(Day day);
        static const WCHAR* ShortDayName(Day day);
        static INT Compare(const Date &d1,const Date &d2);
        static BOOLEAN IsLeapYear(UINT16 year);
        static UINT16 DaysInYear(UINT16 year);

    protected:
        UINT8 m_day;
        UINT8 m_month;
        UINT16 m_year;

        static const UINT8 days_in_month[12];
        static const WCHAR *day_name[7];
        static const WCHAR *short_day_name[7];
        static const WCHAR *month_name[13];
        static const WCHAR *short_month_name[13];

    private:
        template <class T> 
        T AdjustRange(T value, T range) {
            if (value < 0)
                value = 0;
            else if (value > range)
                value = range;

            return value;
        }
};

typedef Date::Format DateFormat;

#endif  // Apoxi_Date_h


