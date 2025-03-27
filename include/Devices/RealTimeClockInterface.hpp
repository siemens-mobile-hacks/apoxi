/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined DOXYGEN_SHOULD_SKIP_THIS
class RealTimeClock {
#endif
    public:
        struct DateAndTime {
            UINT8 hour;
            UINT8 minute;
            UINT8 second;
            UINT8 day;
            UINT8 month;
            INT16 gmt_bias;
            UINT16 millisec;
            UINT16 year;
        };

        enum RtcInfo {
            DataNotValid,   
            TimeChanged,    
            DateChanged,    
            MinuteTick,     
            AlarmReached    
        };

        virtual ~RealTimeClock();

        virtual const WCHAR* GetName() const;

        static ControlArg Control(INT command, ControlArg arg);

        static DateAndTime GetLocalDateAndTime();

        static DateTime GetLocalDateTime();

        static DateTime GetSecureDateTime();

        static BOOLEAN IsSecureClockValid();

        static void SetSleepMode();

        static BOOLEAN SetLocalDate(Date* date);

        static BOOLEAN SetLocalTime(Time* time);

        static BOOLEAN SetLocalDateTime(DateTime* date_time);

        static void SetAlarm(DateTime* date_time);

        static void ClearAlarm();

        static DateTime GetAlarm();

        static BOOLEAN IsRTCStartUpEvent();

        static void CleanUp();

    private:
        static RealTimeClock m_real_time_clock;

        RealTimeClock();

#if defined DOXYGEN_SHOULD_SKIP_THIS
};
#endif

