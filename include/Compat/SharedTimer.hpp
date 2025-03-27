/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SharedTimer_hpp)
#define Apoxi_SharedTimer_hpp

#include <Kernel/Timer.hpp>
#include <Kernel/UserDispatcher.hpp>

class SharedTimer : public Timer, public UserDispatcher {
    typedef Timer Base;

    public:
        SharedTimer();
        SharedTimer(UINT32 timeout, BOOLEAN autotimer = FALSE);
        virtual ~SharedTimer();

        void Init(UINT32 timeout, BOOLEAN autotimer = FALSE);

        void Start();
        void Stop();
        void Resume();
        void Restart();
        
    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

    private:
        enum MsgArg {
            TimerStart,
            TimerStop,
            TimerResume,
            TimerRestart
        };
};

template <class T> class SharedTriggerTimer : public SharedTimer {
    typedef SharedTimer Base;

    public:
        SharedTriggerTimer();
        SharedTriggerTimer(T* t, UINT32 timeout, BOOLEAN autotimer = FALSE);
        virtual ~SharedTriggerTimer();

        void Init(T* t, UINT32 timeout, BOOLEAN autotimer = FALSE);

    protected:
        virtual void OnTimer();

    private:
        T   *m_t;
};

/*  ------------------------------------------------------------------------
    TriggerTimer
    ------------------------------------------------------------------------ */
template <class T>
SharedTriggerTimer<T>::SharedTriggerTimer() : 
    m_t(0) 
{
}   // TriggerTimer

/*  ------------------------------------------------------------------------
    TriggerTimer
    ------------------------------------------------------------------------ */
template <class T>
SharedTriggerTimer<T>::SharedTriggerTimer(T* t, UINT32 timeout, BOOLEAN autotimer) :
    Base(timeout, autotimer), 
    m_t(t) 
{
}   // TriggerTimer

/*  ------------------------------------------------------------------------
    ~TriggerTimer
    ------------------------------------------------------------------------ */
template <class T>
SharedTriggerTimer<T>::~SharedTriggerTimer()
{
    m_t = 0;
}   // ~TriggerTimer

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template <class T>
void SharedTriggerTimer<T>::Init(T* t, UINT32 timeout, BOOLEAN autotimer) 
{
    Base::Init(timeout, autotimer);
    m_t = t;
}   // Init

/*  ------------------------------------------------------------------------
    OnTimer
    ------------------------------------------------------------------------ */
template <class T>
void SharedTriggerTimer<T>::OnTimer()
{
    ASSERT_DEBUG(m_t != 0);
    m_t->OnTimer();
}   // OnTimer

#endif  // Apoxi_SharedTimer_hpp

