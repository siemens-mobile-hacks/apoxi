/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Timer_hpp)
#define Apoxi_Timer_hpp

#include <Auxiliary/LinkedList.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Kernel/Os/Os.hpp>

class ExecutionContext;
class Animation;

class Timer : public Linkable<Timer> {
    public:
        Timer();

        Timer(UINT32 timeout, BOOLEAN autotimer = FALSE);

        virtual ~Timer();

        void Init(UINT32 timeout, BOOLEAN autotimer = FALSE);

        void Start();

        UINT32 Stop();

        void Resume();

        void Restart();

        void SetTimeout(UINT32 timeout);

        UINT32 GetTimeout() { return m_timeout.GetMilliSeconds(); };

        BOOLEAN IsActive() const { return m_bits.active; };

        BOOLEAN operator <(const Timer& timer) const;

    protected:
        ExecutionContext* m_context;
        
        virtual void OnTimer();

    private:
        struct {
            UINT autotimer      : 1;
            UINT active         : 1;
            UINT stopped        : 1;
        } m_bits;

        Ticks   m_timeout;
        Ticks   m_expire;
        Ticks ExpireTicks() const { return m_expire; };

        void Expired();

        friend class AppContainer;
        friend class Application;
        friend class Animation; // provides backward compatibility with APOXI-versions < 1.4.0
        friend class ServiceThread;
};


typedef SortedLinkedList<Timer> TimerList;

#endif  // Apoxi_Timer_hpp


