/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SimpleScheduler_hpp)
#define Apoxi_SimpleScheduler_hpp

#include <Kernel/AbstractScheduler.hpp>

class SimpleScheduler : public AbstractScheduler {

    public:
        typedef AbstractScheduler Base;

        SimpleScheduler(AppContainer* cont);

        virtual ~SimpleScheduler();

        virtual AbstractAppContext* CreateAppContext(Application* app);

        virtual void StartUp();

        virtual void SendMsg(const Application* app, Message& msg);

        virtual void Reschedule();

        virtual void Wait(const Application* app, const Condition& cond);
};


class SimpleAppContext : public AbstractAppContext {
    public:
        typedef AbstractAppContext Base;

        SimpleAppContext(SimpleScheduler* scheduler, Application* app);

        virtual ~SimpleAppContext();

        virtual void StartUp();

        virtual void MsgLoop();

        virtual void SendMsg(Message& msg);

        virtual void Wait(const Condition& cond);
};

#endif


