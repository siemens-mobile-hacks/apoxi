/*  ------------------------------------------------------------------------ 
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved. 
    ------------------------------------------------------------------------ 
    This document contains proprietary information belonging to COMNEON. 
    Passing on and copying of this document, use and communication of its 
    contents is not permitted without prior written authorisation. 
    ------------------------------------------------------------------------ */ 
#if !defined(Apoxi_Devices_StillCamera_hpp) 
#define Apoxi_Devices_StillCamera_hpp 
 

#if defined(APOXI_RTOS_WIN32)
    #if defined(APOXI_ATI_SUPPORT)
        #include <Devices/MPEU/Extensions/AtiW2282/StillCamera.hpp>
    #else
    #include <Devices/Win32/StillCamera.hpp>
    #endif
#elif defined(APOXI_PLATFORM_BP30)
    #include <Devices/BP30/StillCamera.hpp>
#elif defined(APOXI_PLATFORM_MPE)
    #include <Devices/MPE/StillCamera.hpp>
#elif defined(APOXI_PLATFORM_MPEU)
    #include <Devices/MPEU/StillCamera.hpp>
#elif defined(APOXI_PLATFORM_MP1U)
    #include <Devices/SGold/StillCamera.hpp>
#else
    #error Platform not supported!
#endif
 
#endif //Apoxi_Devices_StillCamera_hpp

