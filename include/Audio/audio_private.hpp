/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioPrivate_hpp)
#define Apoxi_AudioPrivate_hpp


// xxx
//#define huge
//#define RINGER_PRESENT 1; //ifdef used in aud_drv.h
#if defined(APOXI_RTOS_WIN32)
#include <Devices/Win32/aud_drv.h>
#else
// xxx
//#include <stack/driver.h>
#endif

class Mutex;

// xxx
#if !defined(SGOLD) && !defined(SGOLDLITE)
//This is a temporary workaround. In future DWD expect to provide a version of aud_drv.h for SGOLD that declares the ringer functions.
#define APOXI_RINGER_DEVICE_PRESENT
#endif


Mutex& AudioGetMutex();

UINT32 percent2native(UINT32 vol, UINT32 volMin, UINT32 volMax);
UINT32 native2percent(UINT32 vol_native, UINT32 volMin, UINT32 volMax);

#endif  // Apoxi_AudioPrivate_hpp

