/*  ------------------------------------------------------------------------ 
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved. 
    ------------------------------------------------------------------------ 
    This document contains proprietary information belonging to COMNEON. 
    Passing on and copying of this document, use and communication of its 
    contents is not permitted without prior written authorisation. 
    ------------------------------------------------------------------------ */ 
#if !defined(Apoxi_Devices_VideoCamera_hpp) 
#define Apoxi_Devices_VideoCamera_hpp 
 
#if defined(APOXI_RTOS_WIN32)
    #if defined(APOXI_ATI_SUPPORT)
        #include <Devices/MPEU/Extensions/AtiW2282/VideoCamera.hpp>
    #else
    #include <Devices/Win32/VideoCamera.hpp>
    #endif
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/VideoCamera.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/VideoCamera.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/VideoCamera.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/VideoCamera.hpp>
#else
    #error Platform not supported!
#endif
 
#endif //Apoxi_Devices_VideoCamera_hpp

