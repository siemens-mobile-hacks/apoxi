/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Scheduler_hpp)
#define Apoxi_Scheduler_hpp

#include <setjmp.h>
#include <Kernel/AbstractScheduler.hpp>

union JmpBuf {
    jmp_buf jb_std;
    _JUMP_BUFFER jb;
};

typedef UINT32 StackAtom;

static const INT c_stack_size = 10000;


class Scheduler : public AbstractScheduler {

    public:
        typedef AbstractScheduler Base;

        Scheduler(AppContainer *cont);

        virtual ~Scheduler();

        virtual AbstractAppContext* CreateAppContext(Application *app);

        virtual void StartUp();

        virtual void SendMsg(const Application *app, Message &msg);

        virtual void Reschedule();

        virtual void Wait(const Application *app, const Condition &cond);

    private:
        JmpBuf m_jmpbuf;
};


class AppContext : public AbstractAppContext {

    public:
        typedef AbstractAppContext Base;

        AppContext(Scheduler *scheduler, Application *app);

        virtual ~AppContext();

        virtual void StartUp();

        virtual void MsgLoop();

        virtual void SendMsg(Message &msg) ;

        virtual void Wait(const Condition &cond);

    private:
        StackAtom m_stack[c_stack_size];
        JmpBuf m_jmpbuf;
        Message* m_msg;
};

#endif


