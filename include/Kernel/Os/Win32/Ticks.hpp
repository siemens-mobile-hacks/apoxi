/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Ticks_hpp)
#define Apoxi_Ticks_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/TickValue.hpp>
#include <limits.h>

class Ticks {
    public:
        Ticks() : m_ticks(0) {}

        Ticks(UINT32 ms) { SetMilliSeconds(ms); }

        Ticks(const Ticks &ticks) : m_ticks(ticks.m_ticks) {}

        explicit Ticks(const TickValue& tick_value) : m_ticks(tick_value.Get()) {}

        void SetEmpty() { m_ticks = 0; }

        BOOLEAN IsEmpty() const { return m_ticks == 0; }

        UINT32 GetExpiredTime() const;

        UINT32 GetExpiredTime(const Ticks &ticks) const { return ticks.m_ticks - m_ticks; }

        Ticks& operator =(const Ticks &ticks) { m_ticks = ticks.m_ticks; return *this; }

        Ticks operator +(const Ticks &ticks) const { 
            Ticks sum;
            sum.m_ticks = m_ticks + ticks.m_ticks;
            return sum;
        }

        Ticks& operator +=(const Ticks &ticks) { m_ticks += ticks.m_ticks; return *this; }

        Ticks operator -(const Ticks &ticks) const {
            Ticks diff;
            diff.m_ticks = m_ticks - ticks.m_ticks;
            return diff;
        }

        Ticks& operator -=(const Ticks &ticks) { m_ticks -= ticks.m_ticks; return *this; }

        BOOLEAN operator ==(const Ticks &ticks) const { return m_ticks == ticks.m_ticks; }

        BOOLEAN operator !=(const Ticks &ticks) const { return m_ticks != ticks.m_ticks; }

        BOOLEAN operator >(const Ticks &ticks) const { return m_ticks > ticks.m_ticks; }

        BOOLEAN operator <(const Ticks &ticks) const { return m_ticks < ticks.m_ticks; }

        BOOLEAN operator >=(const Ticks &ticks) const { return m_ticks >= ticks.m_ticks; }

        BOOLEAN operator <=(const Ticks &ticks) const { return m_ticks <= ticks.m_ticks; }

        static Ticks Infinite() {
            Ticks ticks; 
            ticks.m_ticks = ULONG_MAX;
            return ticks;
        }

    private:
        UINT32 m_ticks;

        void SetMilliSeconds(UINT32 time) { m_ticks = time; }

        UINT32 GetMilliSeconds() const { return m_ticks; }

        friend class Timer;
        friend class Os;
        friend class Semaphore;
        friend class SysSocket;
};

#endif  // Apoxi_Ticks_hpp


