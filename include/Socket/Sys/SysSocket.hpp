/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SysSock_hpp)
#define Apoxi_SysSock_hpp

#include <Socket/SocketTypes.hpp>

/*  ------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------ */

#if !defined(APOXI_SOCKET_SYSTEM_USNET) && \
    !defined(APOXI_SOCKET_SYSTEM_LWIP) && \
    !defined(APOXI_SOCKET_SYSTEM_WIN32) && \
    !defined(APOXI_SOCKET_SYSTEM_DUMMY) && \
    !defined(APOXI_SOCKET_SYSTEM_BSD)
    
    #if defined(APOXI_RTOS_OSE166) || defined(APOXI_RTOS_NUC32)
        #define APOXI_SOCKET_SYSTEM_LWIP
    #elif defined(APOXI_RTOS_WIN32)
        #define APOXI_SOCKET_SYSTEM_WIN32
    #elif defined(APOXI_RTOS_LINUX)
        #define APOXI_SOCKET_SYSTEM_BSD
    #else
        #error Could not determine system socket type
    #endif
#endif

#if defined(APOXI_SOCKET_SYSTEM_USNET)
    #include <Socket/Sys/GlUsnet/UsnetSysSocket.hpp>
#elif defined(APOXI_SOCKET_SYSTEM_LWIP)
    #include <Socket/Sys/GlLwip/LwipSysSocket.hpp>
#elif defined(APOXI_SOCKET_SYSTEM_BSD)
    #include <Socket/Sys/GlBsd/BsdSysSocket.hpp>
#elif defined(APOXI_SOCKET_SYSTEM_WIN32)
    #include <Socket/Sys/GlWin32/Win32SysSocket.hpp>
#elif defined(APOXI_SOCKET_SYSTEM_DUMMY)
    #include <Socket/Sys/GlDummy/DummySysSocket.hpp>
#else
    #error Unknown setting for socket system
#endif

#endif  // Apoxi_SysSock_hpp

