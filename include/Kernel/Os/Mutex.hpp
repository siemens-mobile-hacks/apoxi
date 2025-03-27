/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Mutex_hpp)
#define Apoxi_Mutex_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/Os/Thread.hpp>

class Mutex : public NonCloneable {
    public:
        Mutex();

        virtual ~Mutex();

        BOOLEAN Create(BOOLEAN locked = TRUE);

        BOOLEAN Obtain(const Ticks& timeout = Ticks::Infinite());

        void Release();

    private:
        INT         m_count;
        Semaphore   m_sem;
        ThreadId    m_thread_id;
};

#endif  // Apoxi_Mutex_hpp


