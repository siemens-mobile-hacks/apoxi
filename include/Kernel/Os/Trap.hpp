/*  ------------------------------------------------------------------------
    Copyright (C) 2004 COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Os_Trap_hpp)
#define Apoxi_Os_Trap_hpp


#if defined(APOXI_RTOS_WIN32)
    #include <Kernel/Os/Win32/Trap.hpp>
#elif defined(APOXI_RTOS_OSE166)
    #include <Kernel/Os/Ose166/Trap.hpp>
#elif defined(APOXI_RTOS_NUC32)
    #include <Kernel/Os/Nuc32/Trap.hpp>
#else
    #error Class Trap is not implemented for that operating system!
#endif


#endif  // Apoxi_Os_Trap_hpp


