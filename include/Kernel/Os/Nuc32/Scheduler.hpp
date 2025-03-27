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


typedef struct  {
    jmp_buf buf;
} _JUMP_BUFFER;

union JmpBuf {
    jmp_buf jb_std;
    _JUMP_BUFFER jb;
};

typedef UINT32 StackAtom;

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

        StackAtom   *GetAppStackBase();
        UINT32      GetAppStackSize();

    private:
        #if defined(APOXI_ENABLE_STACK_CHECK)
            /* Checks the stack for overflows
                @return     TRUE if ok
                        FALSE if a stack overflow occured */
            BOOLEAN CheckStack() const;
        #endif
        
        StackAtom *m_app_stackbase;
        UINT32 m_app_stacksize;

        JmpBuf m_jmpbuf;

        Message* m_msg;
};

#endif

