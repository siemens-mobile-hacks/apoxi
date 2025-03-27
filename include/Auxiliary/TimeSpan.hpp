/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_TimeSpan_h)
#define Apoxi_TimeSpan_h

#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>

class TimeSpan
{
    public:
        TimeSpan() : m_seconds(0) { }
        TimeSpan(UINT32 seconds) : m_seconds(seconds) { }
        TimeSpan(UINT hours, UINT minutes, UINT seconds = 0);

        UINT32 GetAbsoluteSeconds() const { return m_seconds; }
        UINT32 GetAbsoluteMinutes() const;
        UINT32 GetAbsoluteHours() const;
        UINT32 GetAbsoluteDays() const;
        UINT32 GetAbsoluteWeeks() const;

        void SetAbsoluteSeconds(UINT32 seconds) { m_seconds = seconds; }
        void SetAbsoluteMinutes(UINT minutes);
        void SetAbsoluteHours(UINT hours);
        void SetAbsoluteDays(UINT days);
        void SetAbsoluteWeeks(UINT days);

        UINT GetHour() const;
        UINT GetMinute() const;
        UINT GetSecond() const;

    private:
        UINT32 m_seconds;
};


#endif


