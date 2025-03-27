/*  ------------------------------------------------------------------------ 
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved. 
    ------------------------------------------------------------------------ 
    This document contains proprietary information belonging to COMNEON. 
    Passing on and copying of this document, use and communication of its 
    contents is not permitted without prior written authorisation. 
    ------------------------------------------------------------------------ */ 
#if !defined(Apoxi_Devices_Camera_hpp) 
#define Apoxi_Devices_Camera_hpp 
 

#if defined(APOXI_RTOS_WIN32)
    #if defined(APOXI_ATI_SUPPORT)
        #include <Devices/MPEU/Extensions/AtiW2282/Camera.hpp>
    #else
    #include <Devices/Win32/Camera.hpp>
    #endif
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/Camera.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/Camera.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/Camera.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/Camera.hpp>
#else
    #error Platform not supported!
#endif

#endif //Apoxi_Devices_Camera_hpp

