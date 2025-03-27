/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Semaphore_hpp)
#define Apoxi_Semaphore_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Os/Ticks.hpp>

class Semaphore : public NonCloneable {
    public:
        Semaphore();

        virtual ~Semaphore();

        BOOLEAN Create(INT init_val = 0, INT max_val = -1);

        BOOLEAN Obtain(const Ticks& timeout = Ticks::Infinite());

        void Release();

    private:
        UINT32 m_hdl;
};

#endif  // Apoxi_Semaphore_hpp

