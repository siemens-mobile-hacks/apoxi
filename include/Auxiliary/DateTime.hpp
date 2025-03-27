/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_DateTime_h)
#define Apoxi_DateTime_h

#include <Auxiliary/WString.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>
#include <Auxiliary/TimeSpan.hpp>
#include <Auxiliary/TimeZone.hpp>

/*  ------------------------------------------------------------------------
                                Types
    ------------------------------------------------------------------------ */
class DateTime : public Date
{
    public:
        typedef Date Base;

        enum {
            RelativeBaseYear = 1970
        };
        
        enum Alignment{
            Zero,             //DateTime is not related to any TimeZone
            UniversalTime,    //DateTime is related to UT, equal to GMT(00:00) DST: 0 (Std.Time)
            LocalTime         //DateTime is related to LocalTime, except temporary TimeZone is set valid    
        };//Alignment   

        // struct must not be larger then 32 bit because of DataItem usage
        struct Persist {
            struct {
                UINT16 m_month  : 4;
                UINT16 m_minute : 6;
                UINT16 m_second : 6;
            } m_data1;
            struct {
                UINT16 m_day    : 5;
                UINT16 m_hour   : 5;
            } m_data2;
            struct {
                UINT16 m_year;
            } m_data3;

            void Reset() {
                m_data1.m_month  = 0;
                m_data1.m_minute = 0;
                m_data1.m_second = 0;
                m_data2.m_day    = 0;
                m_data2.m_hour   = 0;
                m_data3.m_year   = 0;
            }
            BOOLEAN IsZero() const {
                return m_data1.m_month==0 || m_data2.m_day==0 || m_data3.m_year==0;
            }
            BOOLEAN IsLater(const Persist & datetime) const {
                if(m_data3.m_year>datetime.m_data3.m_year) return TRUE;
                if(m_data1.m_month>datetime.m_data1.m_month) return TRUE;
                if(m_data2.m_day>datetime.m_data2.m_day) return TRUE;
                if(m_data2.m_hour>datetime.m_data2.m_hour) return TRUE;
                if(m_data1.m_minute>datetime.m_data1.m_minute) return TRUE;
                if(m_data1.m_second>datetime.m_data1.m_second) return TRUE;
                return FALSE;
            }
        };

        DateTime(Alignment alignment);  
        
        DateTime(PresetDate pd = Today);
        
        DateTime(const DateTime& date_time);            

        DateTime(INT day,INT month,INT year);

        DateTime(INT day, INT month, INT year,
                 INT hour, INT minute, INT second = 0, INT millisecond = 0,
                 Alignment alignment= Zero);    

        DateTime(const Persist & dstruct);
        
        DateTime(INT day,INT month,INT year, const Time &timeval, Alignment alignment= Zero);

        DateTime(UINT32 absoluteseconds, Alignment alignment= Zero);
        
        UINT32 GetAbsoluteDay() const;
        UINT32 GetAbsoluteSeconds() const;
        
    #if !defined(APOXI_RTOS_OSE166)

        UINT64 GetAbsoluteMilliseconds() const;
    #endif

        void AddTimeSpan(const TimeSpan & timespan);
        void SubTimeSpan(const TimeSpan & timespan);

        void SetDate(const Date & dateval);
        void SetTime(const Time & timeval) {
            m_time = timeval;
        }
        void SetDateTime(const Date & dateval, const Time & timeval);

        const Time& GetTime() const {
            return m_time;
        }

        Time GetTime() {
            return m_time;
        }

        Date GetDate() const;

        void SetHour(INT hour) {
            m_time.SetHour(hour);
        }
        INT  GetHour() const {
            return m_time.GetHour();
        }
        void SetMinute(INT minute) {
            m_time.SetMinute(minute);
        }
        INT  GetMinute() const {
            return m_time.GetMinute();
        }
        void SetSecond(INT second)  {
            m_time.SetSecond(second);
        }
        INT  GetSecond() const {
            return m_time.GetSecond();
        }       
        void SetMillisecond(INT millisecond)  {
            m_time.SetMillisecond(millisecond);
        }
        INT  GetMillisecond() const {
            return m_time.GetMillisecond();
        }       
            
        Alignment GetAlignment() const { return m_alignment; }      

        BOOLEAN operator==(const DateTime &datetime) const;

        BOOLEAN operator!=(const DateTime &datetime) const;

        BOOLEAN operator<(const DateTime &datetime) const;

        BOOLEAN operator<=(const DateTime &datetime) const;

        BOOLEAN operator>(const DateTime &datetime) const;

        BOOLEAN operator>=(const DateTime &datetime) const;

        DateTime & operator += (const TimeSpan & timespan);

        DateTime operator + (const TimeSpan & timespan) const;

        DateTime & operator -= (const TimeSpan & timespan);

        DateTime operator - (const TimeSpan & timespan) const;

        TimeSpan GetInterval(const DateTime & datetime);

        WString Format(const WCHAR *format) const;

        void operator<<(const DateTime::Persist & time);
        void operator>>(DateTime::Persist & time) const;

        static INT Compare(const DateTime &d1,const DateTime &d2);

        static INT Compare(const DateTime::Persist & d1, const DateTime::Persist & d2);
        
        static void SetLocalTimeZone(const TimeZone& tz) { m_local_tz= tz; }

        static const TimeZone& GetLocalTimeZone() { return m_local_tz; }

        static void SetTemporaryLocalTimeZone(const TimeZone& tz) { m_temp_tz= tz; }

        static const TimeZone& GetTemporaryLocalTimeZone() { return m_temp_tz; }

        static const TimeZone& GetCurrentLocalTimeZone() { return m_temp_tz.IsOffsetInvalid() ? m_local_tz : m_temp_tz; }       
        
    private:
        Time m_time;                
        
        Alignment m_alignment;      

        static TimeZone m_local_tz; //persistent
        
        static TimeZone m_temp_tz;  //transient
        
    
        // ANSI C
        struct tm {
            INT tm_sec;     /* seconds after the minute - [0,59] */
            INT tm_min;     /* minutes after the hour - [0,59] */
            INT tm_hour;    /* hours since midnight - [0,23] */
            INT tm_mday;    /* day of the month - [1,31] */
            INT tm_mon;     /* months since January - [0,11] */
            INT tm_year;    /* years since 1900 */
            INT tm_wday;    /* days since Sunday - [0,6] */
            INT tm_yday;    /* days since January 1 - [0,365] */        
        };//struct tm

        BOOLEAN ShiftRelativeToLocalTimeZone(const TimeZone &tz);       
        INT WStrFTime(WCHAR *s, INT maxsize, const WCHAR *format, const struct tm *t) const;
        WCHAR* WStrNum(WCHAR *s, INT value, INT length) const;

};//class DateTime

#endif

