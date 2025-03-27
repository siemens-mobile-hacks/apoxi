/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SimpleMutex_hpp)
#define Apoxi_SimpleMutex_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Os/SimpleSemaphore.hpp>
#include <Kernel/Os/Thread.hpp>

class SimpleMutex : public NonCloneable {
    public:
        SimpleMutex();

        virtual ~SimpleMutex();

        BOOLEAN Create(BOOLEAN locked = TRUE);

        void Obtain();

        void Release();

    private:
        INT m_count;
        SimpleSemaphore m_sem;
        ThreadId m_thread_id;
};

#endif  // Apoxi_SimpleMutex_hpp


