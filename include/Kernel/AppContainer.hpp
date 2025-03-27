/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AppContainer_hpp)
#define Apoxi_AppContainer_hpp

#include <Kernel/ApoxiThread.hpp>
#include <Kernel/Os/Os.hpp>
#include <Kernel/Timer.hpp>
#include <Kernel/AppContainerRoutingTable.hpp>
#include <Kernel/MsgQueue.hpp>
#include <Kernel/MsgCategory.hpp>
#include <Kernel/Os/Mutex.hpp>

class Application;
class Message;
class MessageReferrer;
class Condition;

class AppContainer : public ApoxiThread {
    typedef ApoxiThread Base;

    public:
        AppContainer();

        virtual ExecutionContext& GetContext();

        virtual const ExecutionContext& GetContext() const;

        void Run();

        virtual INT ThreadFn();

        BOOLEAN HasFocus() const;

        Application* GetActiveApplication() const { return m_active_app; }

        void Attach(Application* app);

        void Detach(Application* app);

        void MsgLoop();

        void Wait(const Condition& cond) { m_scheduler.Wait(GetActiveApplication(), cond); }
        
        void RegisterMessage(Application* app, MsgId msg_id);

        void UnregisterMessage(const Application* app, MsgId msg_id);

        BOOLEAN IsMessageRegistered(const Message& msg) const;

        void AddTimer(Timer* timer) { m_timer_list.Insert(timer); }

        void RemoveTimer(Timer* timer) { m_timer_list.Remove(timer); m_msg_queue.DeleteTimerTimeoutMsg(*timer); }

        const Timer* NextExpiringTimer() { return m_timer_list.GetFront(); }

        BOOLEAN Enqueue(const MessageReferrer& msg_ref);

        void TriggerIsrDataProcessing() { m_msg_queue.TriggerIsrDataProcessing(); }

        BOOLEAN ContainsUserInputMsg() const;

        BOOLEAN IsRunning() { return (m_running || AllApplicationsRunning()); };

        void TransferFocus(Application* app) const;

        void GrabFocus(Application* app,
                       INT priority = -1,
                       BOOLEAN assign_to_win = TRUE) const;

    private:
        friend class Timer;
        friend class MsgQueue;
        friend class System;
        friend void Os::DbgOutStackUsage();

        BOOLEAN m_running;
        INT m_app_count;            // Number of applications in the container
        Application *m_active_app;
        Scheduler m_scheduler;
        TimerList m_timer_list;
        MsgQueue m_msg_queue;
        AppContainerRoutingTable m_message_routing_table;
        LinkedList<Application> m_app_list;
        
        void RouteMessage(Message& msg);
        void RouteRegisteredMessage(Message& msg);
        void SendMessage(Application* app, Message& msg);
        BOOLEAN AllApplicationsRunning();
        BOOLEAN IsShutdownAllowed();
};

#endif  // Apoxi_AppContainer_hpp


