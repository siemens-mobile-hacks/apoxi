/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Os_hpp)
#define Apoxi_Os_hpp


#include <Kernel/Types.hpp>

#if defined(APOXI_POWERSAVING_TIMER_ALIGNMENT_RANGE)
    #define APOXI_POWERSAVING_TIMER_ALIGNMENT_LOWER_BOUND APOXI_POWERSAVING_TIMER_ALIGNMENT_RANGE/2
    #define APOXI_POWERSAVING_TIMER_ALIGNMENT_UPPER_BOUND APOXI_POWERSAVING_TIMER_ALIGNMENT_RANGE/2
#endif

#if !defined(APOXI_POWERSAVING_TIMER_ALIGNMENT_LOWER_BOUND)
    #define APOXI_POWERSAVING_TIMER_ALIGNMENT_LOWER_BOUND 0
#endif

#if !defined(APOXI_POWERSAVING_TIMER_ALIGNMENT_UPPER_BOUND)
    #define APOXI_POWERSAVING_TIMER_ALIGNMENT_UPPER_BOUND 0
#endif

const UINT32 c_apoxi_powersaving_timer_alignment_lower_bound = APOXI_POWERSAVING_TIMER_ALIGNMENT_LOWER_BOUND;
const UINT32 c_apoxi_powersaving_timer_alignment_upper_bound = APOXI_POWERSAVING_TIMER_ALIGNMENT_UPPER_BOUND;

#if defined(APOXI_RTOS_WIN32)
    // no more include necessary
#elif defined(APOXI_RTOS_OSE166)
    // no more include necessary
#elif defined(APOXI_RTOS_NUC32)
    // no more include necessary
#else
    #error Unknown operating system or no operating system defined!
#endif

#include <Kernel/Os/Thread.hpp>
#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/Os/Trap.hpp>
#include <Kernel/Os/Scheduler.hpp>
#include <Kernel/Os/SystemTimer.hpp>
#include <Kernel/Os/OsStrLib.hpp>
#include <Kernel/Os/OsClass.hpp>


#endif  // Apoxi_Os_hpp

