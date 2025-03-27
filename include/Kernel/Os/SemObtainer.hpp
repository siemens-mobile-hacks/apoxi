/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_SemObtainer_hpp)
#define Apoxi_SemObtainer_hpp

#include <Kernel/Os/Os.hpp>

class SemObtainer {
    public:
        SemObtainer(Semaphore* sem, const Ticks& timeout);

        SemObtainer(Semaphore* sem);

        ~SemObtainer() { Release(); }

        BOOLEAN IsObtained() const { return m_obtained; }

        BOOLEAN Obtain(const Ticks& timeout);

        BOOLEAN Obtain();

        void Release();

    private:
        BOOLEAN m_obtained;
        Semaphore* m_sem;
};

#endif  // Apoxi_SemObtainer_hpp


