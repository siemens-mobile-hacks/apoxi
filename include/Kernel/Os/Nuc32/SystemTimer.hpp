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
#include <Kernel/Os/Os.hpp>

struct tic_timer_s;

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

        BOOLEAN IsActive() const { return m_active; };

    private:
        BOOLEAN m_active;
        BOOLEAN m_autotimer;
        UINT32 m_timeout;
        tic_timer_s* m_hdl;
        Ticks m_started;

        struct _call_back {
            CallBackFn fn;
            void* arg;
            SystemTimer* m_system_timer;
        } m_callback;

        static void OnTimer(void *arg);
};

#endif  // Apoxi_SystemTimer_hpp


