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
#include <Kernel/Os/Nuc32/Ticks.hpp>

struct TimerSem;

/*----------------------------------------------------------------
                            Semaphore
  ----------------------------------------------------------------*/

class Semaphore : public NonCloneable {
    public:
        Semaphore();
        virtual ~Semaphore();

        BOOLEAN Create(INT init_val = 0, INT max_val = -1);
        BOOLEAN Obtain(Ticks timeout = Ticks::Infinite());
        void Release();

    private:
        TimerSem* m_sem;
        
        static TimerSem* TimerSemCreate(INT init_val, INT max_val);
        static void TimerSemDelete(TimerSem *sem);
        static void TimerSemExpired(void *ctx);
        static BOOLEAN TimerSemWait(TimerSem *sem, unsigned long timeout);
        static void TimerSemSignal(TimerSem *sem);
};


#endif  // Apoxi_Semaphore_hpp

