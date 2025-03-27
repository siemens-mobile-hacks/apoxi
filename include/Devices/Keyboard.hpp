/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Devices_Keyboard_hpp)
#define Apoxi_Devices_Keyboard_hpp


#if defined(APOXI_RTOS_WIN32)
    #include <Devices/Win32/Keyboard.hpp>
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/Keyboard.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/Keyboard.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/Keyboard.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/Keyboard.hpp>
#else
    #error Platform not supported!
#endif

#endif  // Apoxi_Devices_Keyboard_hpp

