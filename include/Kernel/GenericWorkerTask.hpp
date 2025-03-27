/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_GenericWorkerTask_hpp)
#define Apoxi_GenericWorkerTask_hpp

#include <Kernel/SubSystem.hpp>
#include <Kernel/Os/Os.hpp>
#include <Kernel/Os/MutexObtainer.hpp>

class Threadlet;

class GenericWorkerTask : public SubSystem, public Thread {
    public:
        virtual ~GenericWorkerTask();

        static GenericWorkerTask& GetInstance() { return m_generic_worker_task; }

        virtual const WCHAR* GetName() const;

        virtual void OnPowerUp();

        virtual void OnPowerDown();

        virtual BootSequenceState InvokeAt() const;

        virtual INT ThreadFn();

        BOOLEAN IsBusy() const;

    private:
        class WorkerTaskObtainer : public MutexObtainer {
            typedef MutexObtainer Base;

            public:
                WorkerTaskObtainer();
        };

        friend class WorkerTaskObtainer;
        friend class Threadlet;
        friend class Os;

        static BOOLEAN m_running;
        static LinkedList<Threadlet> m_queue;
        static Semaphore m_sem;
        static Mutex m_queue_mutex;
        static GenericWorkerTask m_generic_worker_task;

        GenericWorkerTask();

        static void AddThreadlet(Threadlet* threadlet);
        static Threadlet* GetThreadlet();
        static void RemoveThreadlet();
};

#endif  // Apoxi_GenericWorkerTask_hpp


