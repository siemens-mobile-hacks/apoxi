/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StateMachine_hpp)
#define Apoxi_StateMachine_hpp

#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/Os/SemObtainer.hpp>

class EventData;
struct StateStruct;

class StateMachine : public NonCloneable
{
protected:
    enum {
        EVENT_IGNORED = 0xFE,
        CANNOT_HAPPEN
    };

    UINT8 m_currentState;

protected:
    StateMachine(INT maxStates);

    void ExternalEvent(const UINT8[], EventData* = 0);

    void InternalEvent(UINT8, EventData* = 0);

    virtual const StateStruct* GetStateMap() = 0;

    Semaphore& GetSempahore() const { return m_sem; }

private:
    const INT m_maxStates;
    BOOLEAN m_eventGenerated;
    EventData *m_pEventData;
    mutable Semaphore m_sem;

private:
    void StateEngine();
};

typedef void (StateMachine::*StateFunc)(EventData *);

struct StateStruct
{
    StateFunc pStateFunc;
};

#define LOCK_STATE_MACHINE SemObtainer state_machine_so(&GetSempahore());


#define BEGIN_STATE_MAP                             \
public:                                             \
virtual const StateStruct* GetStateMap() {          \
    static const StateStruct StateMap[] = {

#define STATE_MAP_ENTRY(entry)                      \
    { (StateFunc)(entry) },

#define END_STATE_MAP                               \
    { (StateFunc)0 }                                \
    };                                              \
    return &StateMap[0]; }



#define BEGIN_TRANSITION_MAP                        \
    static const UINT8 TRANSITIONS[] = {            \


#define TRANSITION_MAP_ENTRY(entry)                 \
    (entry),

#define END_TRANSITION_MAP(data)                    \
    0 };                                            \
    ExternalEvent(TRANSITIONS, (data));


#endif  // Apoxi_StateMachine_hpp

