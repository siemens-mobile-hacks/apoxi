/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Nuc32_Thread_hpp)
#define Apoxi_Nuc32_Thread_hpp

#include <Auxiliary/SimpleMap.hpp>
#include <Kernel/Os/Nuc32/Scheduler.hpp>

#define c_max_thread_name_length 8

#if !defined(APOXI_THREAD_PRIORITY_NORMAL)
    #define APOXI_THREAD_PRIORITY_NORMAL 100
#endif

struct NU_TASK_STRUCT;

typedef NU_TASK_STRUCT* ThreadId;   

class Thread {
    public:
        enum PriorityLevel {
            PriorityBackground5 = APOXI_THREAD_PRIORITY_NORMAL + 5, 
            PriorityBackground4 = APOXI_THREAD_PRIORITY_NORMAL + 4,
            PriorityBackground3 = APOXI_THREAD_PRIORITY_NORMAL + 3,
            PriorityBackground2 = APOXI_THREAD_PRIORITY_NORMAL + 2,
            PriorityBackground1 = APOXI_THREAD_PRIORITY_NORMAL + 1,
            PriorityNormal      = APOXI_THREAD_PRIORITY_NORMAL,     
            PriorityForeground1 = APOXI_THREAD_PRIORITY_NORMAL - 1,
            PriorityForeground2 = APOXI_THREAD_PRIORITY_NORMAL - 2,
            PriorityForeground3 = APOXI_THREAD_PRIORITY_NORMAL - 3,
            PriorityForeground4 = APOXI_THREAD_PRIORITY_NORMAL - 4,
            PriorityForeground5 = APOXI_THREAD_PRIORITY_NORMAL - 5, 
        };
        
        Thread();
        virtual ~Thread();

        void SetRequestedStackSize(UINT32 size);
        UINT32 GetRequestedStackSize() { return m_requested_stacksize; }

        BOOLEAN Run(UINT32 stacksize = 0, void *stack = 0);

        virtual INT ThreadFn() = 0;

        INT GetPriority() const { return m_priority; }
        BOOLEAN SetPriority(INT priority);

        BOOLEAN IncreasePriority();
        BOOLEAN DecreasePriority();

        void SetName(const CHAR* name);
        const CHAR* GetName() const { return m_name; };

        INT Suspend() const;
        INT Resume() const;
        INT Yield() const;

        BOOLEAN Terminate(INT exit_code = 0);

        static ThreadId GetThreadId();
        static void SetThreadData(void *data);
        static void* GetThreadData();

    private:
        friend class Os;
        
        enum Status {
            THREAD_INVALID,
            THREAD_RUNNING,
            THREAD_SUSPENDED,
            THREAD_TERMINATED
        };

        mutable Status m_status;
        INT m_priority;
        UINT32 m_requested_stacksize;
        StackAtom* m_stack;
        CHAR m_name[c_max_thread_name_length];
        
        NU_TASK_STRUCT* m_thread_data;
        
        Thread(const Thread& thread);
        Thread& operator=(const Thread& thread);
        
        static BOOLEAN m_sem_initialized;
        static SimpleMap<ThreadId, void *> m_thread_data_map;   // The map storing the thread data.

        static void ThreadStartProc(UINT32 argc, void* param);
};

#endif  // Apoxi_Nuc32_Thread_hpp


