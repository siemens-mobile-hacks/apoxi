/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TriggerTimer_hpp)
#define Apoxi_TriggerTimer_hpp

#include <Auxiliary/Macros.hpp>
#include <Kernel/Timer.hpp>

template <class T> class TriggerTimer : public Timer {
    typedef Timer Base;

    public:
        TriggerTimer();
        TriggerTimer(T *t, UINT32 timeout, BOOLEAN autotimer = FALSE);
        virtual ~TriggerTimer();

        void Init(T *t, UINT32 timeout, BOOLEAN autotimer = FALSE);

    protected:
        virtual void OnTimer();

    private:
        T   *m_t;
};

/*  ------------------------------------------------------------------------
    TriggerTimer
    ------------------------------------------------------------------------ */
template <class T>
TriggerTimer<T>::TriggerTimer() : 
    m_t(0) 
{
}   // TriggerTimer

/*  ------------------------------------------------------------------------
    TriggerTimer
    ------------------------------------------------------------------------ */
template <class T>
TriggerTimer<T>::TriggerTimer(T *t, UINT32 timeout, BOOLEAN autotimer) :
    Base(timeout, autotimer), 
    m_t(t) 
{
}   // TriggerTimer

/*  ------------------------------------------------------------------------
    ~TriggerTimer
    ------------------------------------------------------------------------ */
template <class T>
TriggerTimer<T>::~TriggerTimer()
{
    m_t = 0;
}   // ~TriggerTimer

/*  ------------------------------------------------------------------------
    Init
    ------------------------------------------------------------------------ */
template <class T>
void TriggerTimer<T>::Init(T *t, UINT32 timeout, BOOLEAN autotimer) 
{
    Base::Init(timeout, autotimer);
    m_t = t;
}   // Init

/*  ------------------------------------------------------------------------
    OnTimer
    ------------------------------------------------------------------------ */
template <class T>
void TriggerTimer<T>::OnTimer()
{
    ASSERT(m_t != 0);
    m_t->OnTimer();
}   // OnTimer

#endif  // Apoxi_TriggerTimer_hpp


