/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AbstractScheduler_hpp)
#define Apoxi_AbstractScheduler_hpp


#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/LinkedList.hpp>


class AbstractScheduler;
class AppContainer;
class Condition;
class Message;
class Application;

class AbstractAppContext : public Linkable<AbstractAppContext> {

    public:
        AbstractAppContext(AbstractScheduler* scheduler, Application* app);

        virtual ~AbstractAppContext();

        virtual void StartUp();
        
        void Stop() { m_running = FALSE; }
        
        virtual void MsgLoop() = 0;
        
        virtual void SendMsg(Message& msg) = 0;

        virtual void Wait(const Condition& cond) = 0;

        BOOLEAN IsRunning() const { return m_running; }
        
        const Application* GetApplication() const { return m_app; } ;

    protected:
        BOOLEAN m_running;
        AbstractScheduler* m_scheduler;
        Application* m_app;
};


class AbstractScheduler {

    public:
        AbstractScheduler(AppContainer* cont);
        virtual ~AbstractScheduler();

        void AddAppContext(Application* app);

        void RemoveAppContext(const Application* app);

        virtual AbstractAppContext* CreateAppContext(Application* app) = 0;

        AbstractAppContext* GetAppContext(const Application* app) const;

        virtual void StartUp() = 0;

        virtual void SendMsg(const Application* app, Message& msg) = 0;
        
        virtual void Reschedule() = 0;
        
        virtual void Wait(const Application* app, const Condition& cond) = 0;
        
        virtual void ShutDown();

    protected:
        friend class Os;
        friend class AppContainer;

        BOOLEAN m_unblock_focus_messages;
        AppContainer* m_cont;
        LinkedList<AbstractAppContext> m_appcntxt_list;
        LinkedList<AbstractAppContext> m_rem_appcntxt_list;
};

#endif


