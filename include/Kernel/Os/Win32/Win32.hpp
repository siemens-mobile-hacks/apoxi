/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Win32_hpp)
#define Apoxi_Win32_hpp

#include <Kernel/Os/Win32/WinInc.hpp>

typedef CRITICAL_SECTION    CriticalSection;
typedef WIN32_INT           ThreadPriority; 
typedef DWORD               ThreadDataIndex;
typedef WIN32_WCHAR*        ThreadName; 
typedef LPVOID              SharedMem;

struct Task {
    HANDLE hdl;
};

struct SharedMemHdl {
    HANDLE hdl;
};

#endif  // Apoxi_Win32_hpp

