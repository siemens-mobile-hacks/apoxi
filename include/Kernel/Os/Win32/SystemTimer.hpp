/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SystemTimer_hpp)
#define Apoxi_SystemTimer_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Ticks.hpp>

class SystemTimer {
    public:
        typedef void (*CallBackFn)(void*);

        SystemTimer();

        SystemTimer(UINT32 timeout, CallBackFn OnTimer, void* arg = 0, BOOLEAN autotimer = FALSE);

        ~SystemTimer();

        void Init(UINT32 timeout, CallBackFn OnTimer, void* arg = 0, BOOLEAN autotimer = FALSE);

        void SetTimeout(UINT32 timeout) { m_timeout = timeout; }
        UINT32 GetTimeout() const { return m_timeout; }

        void Start();

        UINT32 Stop();

        void Restart();

        BOOLEAN IsActive() const { return m_active; }

    private:
        friend class SystemTimerInternals;

        BOOLEAN m_active;
        BOOLEAN m_autotimer;
        UINT32 m_timeout;
        UINT m_timer_id;
        Ticks m_started;

        struct CallBack {
            CallBackFn m_fn;
            void* m_arg;
            SystemTimer* m_system_timer;
        };

        CallBack m_callback;
};

#endif  // Apoxi_SystemTimer_hpp

