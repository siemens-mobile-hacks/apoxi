/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Time_hpp)
#define Apoxi_Time_hpp

#include <Auxiliary/WString.hpp>

class Time {
    public:
        enum Format {
            TimeHM,
            TimeHMS
        };

        // struct must not be larger then 32 bit because of DataItem usage
        struct Persist {
            UINT8 m_hour;
            UINT8 m_minute;
            UINT8 m_second;
        };

        Time();

        Time(INT hour, INT minute, INT second = 0, INT millisecond = 0);

        Time(const Persist & tstruct);

        void SetHour(INT hour);

        INT GetHour() const { return m_hour; }

        void SetMinute(INT minute);

        INT GetMinute() const { return m_minute; }

        void SetSecond(INT second);

        INT GetSecond() const { return m_second; }

        void SetMillisecond(INT millisecond);

        INT GetMillisecond() const { return m_millisecond; }

        WString GetWString(Format time_format) const;

        WString GetWString(const WCHAR *format) const;

        BOOLEAN operator==(const Time &time) const;

        BOOLEAN operator!=(const Time &time) const;

        BOOLEAN operator<(const Time &time) const;

        BOOLEAN operator<=(const Time &time) const;

        BOOLEAN operator>(const Time &time) const;

        BOOLEAN operator>=(const Time &time) const;

        static INT Compare(const Time& t1, const Time& t2);

        static INT Compare(const Time::Persist & t1, const Time::Persist & t2);

        void operator<<(const Time::Persist & time);
        void operator>>(Time::Persist & time) const;

    private:
        UINT8 m_hour;
        UINT8 m_minute;
        UINT8 m_second;
        UINT16 m_millisecond;

        template <class T> 
        T AdjustRange(T value, T range) {
            if (value < 0)
                value = 0;
            else if (value > range)
                value = range;

            return value;
        }
};

typedef Time::Format TimeFormat;

#endif  // Apoxi_Time_hpp


