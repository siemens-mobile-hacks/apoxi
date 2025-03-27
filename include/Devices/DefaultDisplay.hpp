/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if defined(APOXI_RTOS_WIN32)
    #include <Devices/Win32/DefaultDisplay.hpp>
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/DefaultDisplay.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/DefaultDisplay.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/DefaultDisplay.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/DefaultDisplay.hpp>
#else
    #error UNDEFINED PLATFORM
#endif

