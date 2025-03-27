/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Devices_Charger_hpp)
#define Apoxi_Devices_Charger_hpp


#if defined(APOXI_RTOS_WIN32)
    #include <Devices/Win32/Charger.hpp>
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/Charger.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/Charger.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/Charger.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/Charger.hpp>
#else
    #error Platform not supported!
#endif

#endif  // Apoxi_Devices_Charger_hpp

