/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FsmEngine_hpp)
#define Apoxi_FsmEngine_hpp

#include <Auxiliary/ObjectObtainer.hpp>
#include <Auxiliary/NonCloneable.hpp>


#ifndef DOXYGEN_SHOULD_SKIP_THIS

// Internal utility macros
#define FSM_TRANS_NEXT(classname, actionname, statename) \
    { \
        (FsmEngine::ActionMemFunPtr) &classname::actionname, \
        &classname::s_fsm_state_info_##statename \
    }

#define FSM_TRANS_EXIT(classname, actionname) \
    { \
        (FsmEngine::ActionMemFunPtr) &classname::actionname, \
        0 \
    }

#define FSM_TRANS_COUNT(classname, statename) \
    ( sizeof(classname::s_fsm_trans_list_##statename) / sizeof(FsmEngine::EventInfo) )


#define FSM_INTERNAL_EVENTS \
    NoEvent = 0

#define FSM_STATE_FROM_NAME(statename) s_fsm_state_info_##statename

#define FSM_DECLARE_STATE(statename) \
    static  const FsmEngine::EventInfo  s_fsm_trans_list_##statename[]; \
    static  const FsmEngine::StateInfo  s_fsm_state_info_##statename


#define FSM_DEFINE_STATE(classname, statename) \
    const FsmEngine::EventInfo  classname::s_fsm_trans_list_##statename[] =


#define FSM_EVENT_NEXT(classname, eventname, statename, actionname) \
    { \
        FSM_TRANS_NEXT(classname, actionname, statename), \
        eventname \
    }


#define FSM_EVENT_EXIT(classname, eventname, actionname) \
    { \
        FSM_TRANS_EXIT(classname, actionname), \
        eventname \
    }


#define FSM_STATE_ELSE(classname, statename, actionname) \
    ;\
    const FsmEngine::StateInfo  classname::s_fsm_state_info_##statename = \
    { \
        #classname"::"#statename, \
        classname::s_fsm_trans_list_##statename, \
        FSM_TRANS_COUNT(classname, statename), \
        FSM_TRANS_NEXT(classname, actionname, statename) \
    }


#define FSM_STATE_EXIT(classname, statename, actionname) \
    ;\
    const FsmEngine::StateInfo  classname::s_state_info_##statename = \
    { \
        #classname ".." #statename, \
        classname::s_fsm_trans_list_##statename, \
        FSM_TRANS_COUNT(classname, statename), \
        FSM_TRANS_EXIT(classname, actionname) \
    }


class FsmEngine {

    public:
        typedef INT  EventType;

        enum {
            FSM_INTERNAL_EVENTS
        };

        class Actor : public NonCloneable {

            public:
                virtual const CHAR *    GetTraceInfo() const;

            protected:
                EventType   NoAction(FsmEngine &, EventType, ObjectObtainer &) const
                {
                    return NoEvent;
                }
        };

        typedef EventType   (Actor::*ActionMemFunPtr)
                            (FsmEngine &, EventType, ObjectObtainer &);
        struct  StateInfo;

        struct  TransInfo {
            ActionMemFunPtr     action;
            const StateInfo *   follow_state;
        };

        struct  EventInfo {
            TransInfo           trans;
            EventType           event;
        };

        struct  StateInfo {
            const CHAR *        state_name;
            const EventInfo *   trans_tab;
            UINT8               trans_cnt;
            TransInfo           trans_def;
        };

        class   StateReferrer {

            public:
                inline  StateReferrer();

                inline  StateReferrer(const StateInfo &     state_info,
                                      Actor *               actor_ptr);

                inline  void                SetState(const StateInfo &  state_info);
                inline  const StateInfo &   GetState() const;

                inline  Actor &             GetActor() const;

            private:
                Actor *                     m_actor_ptr;
                const StateInfo *           m_state_ptr;
        };

        FsmEngine();

        inline  UINT            GetStackDepth() const;

        void                    Init(StateReferrer  stack[],
                                     UINT           max_depth);

        void                    Push(const StateReferrer &  referrer);
        void                    Pop();
        void                    Super();

        BOOLEAN                 IsInState(const StateInfo &     test_state,
                                          UINT                  scope = 0) const;

        void                    ExternalEvent(const ObjectObtainer &    event_holder);

        inline  void            ExternalEvent(EventType             event_type,
                                              ObtainableObject *    event_data_ptr);

        void                    StateAsString(String &  out_str) const;

    private:
        UINT                m_max_depth;
        UINT                m_fsm_depth;
        UINT                m_fsm_scope;
        StateReferrer *     m_fsm_stack;

        void                TraceState(const CHAR *  name_str) const;
        inline  BOOLEAN     IsValidScope(UINT   scope) const;
};


FsmEngine::StateReferrer::StateReferrer() :
    m_actor_ptr(0),
    m_state_ptr(0)
{
}


FsmEngine::StateReferrer::StateReferrer(const StateInfo &   state_info,
                                        Actor *             actor_ptr) :
    m_actor_ptr(actor_ptr),
    m_state_ptr(&state_info)
{
}


void    FsmEngine::StateReferrer::SetState(const StateInfo &  state_info)
{
    m_state_ptr = &state_info;
}


const FsmEngine::StateInfo &    FsmEngine::StateReferrer::GetState()
const
{
    ASSERT_DEBUG(m_state_ptr != 0);

    return  *m_state_ptr;
}


FsmEngine::Actor &  FsmEngine::StateReferrer::GetActor()
const
{
    ASSERT_DEBUG(m_actor_ptr != 0);

    return  *m_actor_ptr;
}

void    FsmEngine::ExternalEvent(EventType              event_type,
                                 ObtainableObject *     event_data_ptr)
{
    ExternalEvent( ObjectObtainer(event_data_ptr, FALSE, event_type) );
}


BOOLEAN     FsmEngine::IsValidScope(UINT    level)
const
{
    return  ( (level > 0) && (level <= GetStackDepth()) );
}


UINT  FsmEngine::GetStackDepth()
const
{
    return m_fsm_depth;
}

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // Apoxi_FsmEngine_hpp

