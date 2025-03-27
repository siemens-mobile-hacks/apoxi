/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Os_WinInc_hpp)
#define Apoxi_Os_WinInc_hpp

#if !defined(APOXI_RTOS_WIN32)
    #error Os/WinInc.hpp can only be included with APOXI_RTOS_WIN32 configuration
#endif

// Hide WIN32 types

#define BOOLEAN WIN32_BOOLEAN
#define UCHAR   WIN32_UCHAR
#define CHAR    WIN32_CHAR
#define WCHAR   WIN32_WCHAR

#define INT8    WIN32_INT8
#define UINT8   WIN32_UINT8

#define INT16   WIN32_INT16
#define UINT16  WIN32_UINT16

#define INT32   WIN32_INT32
#define UINT32  WIN32_UINT32

#define INT     WIN32_INT
#define UINT    WIN32_UINT

#define LONG    WIN32_LONG
#define ULONG   WIN32_ULONG

#define Action  WIN32_Action

// our minimal system requirements: win nt 4.0 or win98
// this ensures support of winsock2.h and IsDebuggerPresent()
#define _WIN32_WINNT 0x0400
#define _WIN32_WINDOWS 0x0410

#if defined(_CPPUNWIND)
    #error Exception handling is enabled! APOXI requires exception handling to be disabled!
#endif

#if (_MSC_VER >= 1300)
    #include <winsock2.h>
#endif

#include <windows.h>
#include <basetsd.h>
#include <limits.h>
#include <stdio.h>
#include <direct.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <io.h>

#undef SERVICE_DISABLED     // disable WinNT define in winnt.h
#undef TRANSPARENT          // disable WinNT define in wingdi.h (coming up with gfs v18.11)
#undef O_RDONLY             // disable define in fcntl.h
#undef O_WRONLY             // disable define in fcntl.h
#undef O_RDWR               // disable define in fcntl.h
#undef O_CREAT              // disable define in fcntl.h
#undef O_TRUNC              // disable define in fcntl.h

#undef GLOBAL
#define GLOBAL

#undef BOOLEAN
#undef CHAR
#undef UCHAR
#undef WCHAR
#undef INT8
#undef UINT8
#undef INT16
#undef UINT16
#undef INT32
#undef UINT32
#undef INT
#undef UINT
#undef LONG
#undef ULONG

#undef TRUE
#undef FALSE
#undef Action

#undef GetDateFormat
#undef GetTimeFormat
#undef SendMessage
#undef GetObject

#undef MessageBox
#ifdef UNICODE
    #define WIN32_MessageBox MessageBoxW
#else
    #define WIN32_MessageBox MessageBoxA
#endif

#undef MoveFile
#ifdef UNICODE
    #define WIN32_MoveFile MoveFileW
#else
    #define WIN32_MoveFile MoveFileA
#endif

#undef DeleteFile
#ifdef UNICODE
    #define WIN32_DeleteFile DeleteFileW
#else
    #define WIN32_DeleteFile DeleteFileA
#endif

#endif  // Apoxi_Os_WinInc_hpp

