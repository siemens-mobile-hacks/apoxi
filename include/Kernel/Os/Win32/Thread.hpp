/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Thread_hpp)
#define Apoxi_Thread_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Types.hpp>

#if !defined(APOXI_THREAD_PRIORITY_NORMAL)
    #define APOXI_THREAD_PRIORITY_NORMAL 0
#endif

#define c_max_thread_name_length 8

#undef Yield

/*----------------------------------------------------------------
                                Thread
  ----------------------------------------------------------------*/

typedef UINT32 ThreadId;

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

        void SetRequestedStackSize(UINT32 /*size*/) {}

        UINT32 GetRequestedStackSize() { return 0; }

        BOOLEAN Run(UINT32 stacksize = 4096, void *stack = 0);

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
        INT m_priority;
        UINT32 m_hdl;
        CHAR m_name[c_max_thread_name_length];

        Thread(const Thread& thread);

        Thread& operator=(const Thread& thread);

};

#endif  // Apoxi_Thread_hpp

