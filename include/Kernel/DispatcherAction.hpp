/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DispatcherAction_hpp)
#define Apoxi_DispatcherAction_hpp

#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>

class Dispatcher;
class Action;

class DispatcherAction : public Linkable<DispatcherAction> {
    public:
        DispatcherAction(const Dispatcher& dispatcher, Action* action)
            : m_dispatcher(dispatcher), m_action(action) {}

        Action* GetAction() const { return (m_action); };
        const Dispatcher& GetDispatcher() const { return (m_dispatcher); }

    private:
        const Dispatcher& m_dispatcher;
        Action* m_action;
};

typedef LinkedList<DispatcherAction> DispatcherActionList;

#endif  // Apoxi_DispatcherAction_hpp


