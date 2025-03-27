/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_AppMutex_hpp)
#define Apoxi_AppMutex_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Condition.hpp>
#include <Kernel/Os/Os.hpp>

class AppMutex : public NonCloneable {
    public:
        AppMutex();

        virtual ~AppMutex();

        BOOLEAN Create(BOOLEAN locked = TRUE);

        BOOLEAN Obtain(const Ticks& timeout = Ticks::Infinite());

        void Release();

    private:
        class CondListEntry : public Linkable<CondListEntry> {
            public:
                CondListEntry();
                virtual ~CondListEntry();

                BooleanCondition& GetCondition() { return m_cond; }

                #ifdef _DEBUG
                    Application* GetApplication() const { return m_app; }
                #endif

            private:
                #ifdef _DEBUG
                    Application* m_app;
                #endif

                BooleanCondition m_cond;
        };

        INT         m_count;
        Semaphore   m_sem;
        ThreadId    m_thread_id;
        Application* m_app;
        LinkedList<CondListEntry> m_list;
};

#endif  // Apoxi_AppMutex_hpp


