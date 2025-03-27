/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Condition_hpp)
#define Apoxi_Condition_hpp

#include <Auxiliary/TriggerTimer.hpp>

class ExecutionContext;


class Condition {
    public:
        Condition();
        virtual ~Condition();

        virtual BOOLEAN IsTrue() const = 0;
};

class BooleanCondition : public Condition {
    typedef Condition Base;

    public:
        BooleanCondition();

        virtual ~BooleanCondition();

        void Init();

        void SetTrue();

        virtual BOOLEAN IsTrue() const;

    private:
        BOOLEAN m_is_true;
        ExecutionContext* m_context;

        static void SetTrueCallback(void* arg);
};

class TimeoutCondition : public BooleanCondition {
    typedef BooleanCondition Base;

    public:
        TimeoutCondition();
        TimeoutCondition(UINT32 timeout);

        virtual ~TimeoutCondition();

        void Init(UINT32 timeout);

        BOOLEAN IsTimerExpired() const { return m_timer_expired; }

    private:
        friend class TriggerTimer<TimeoutCondition>;

        BOOLEAN m_timer_expired;
        TriggerTimer<TimeoutCondition> m_timer;

        virtual void OnTimer();
};

#endif  // Apoxi_Condition_hpp


