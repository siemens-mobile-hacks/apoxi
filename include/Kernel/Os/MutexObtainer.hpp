/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(MutexObtainer_hpp)
#define MutexObtainer_hpp

#include <Kernel/Os/Os.hpp>

class Mutex;

class MutexObtainer {
    public:
        MutexObtainer(Mutex* mtx, const Ticks& timeout);

        MutexObtainer(Mutex* mtx);

        ~MutexObtainer() { Release(); }

        BOOLEAN IsObtained() const { return m_obtained; }

        BOOLEAN Obtain(const Ticks& timeout);

        BOOLEAN Obtain();

        void Release();

    private:
        BOOLEAN m_obtained;
        Mutex* m_mutex;
};

#endif  // MutexObtainer_hpp


