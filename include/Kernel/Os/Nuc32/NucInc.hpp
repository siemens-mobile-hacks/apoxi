/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Os_NucInc_hpp)
#define Apoxi_Os_NucInc_hpp

#if !defined(APOXI_RTOS_NUC32)
    #error Os/NucInc.hpp can only be included with APOXI_RTOS_NUC32 configuration
#endif

#include <string.h>

#undef BOOLEAN
#undef BYTE
#undef CHAR
#undef INT
#undef INT8
#undef INT16
#undef INT32
#undef LONG
#undef UINT
#undef UINT8
#undef UINT16
#undef UINT32
#undef WCHAR

#define BOOLEAN NUCLEUS_H_BOOLEAN
#define BYTE NUCLEUS_H_BYTE
#define CHAR NUCLEUS_H_CHAR
#define INT NUCLEUS_H_INT
#define INT8 NUCLEUS_H_INT8
#define INT16 NUCLEUS_H_INT16
#define INT32 NUCLEUS_H_INT32
#define LONG NUCLEUS_H_LONG
#define UINT NUCLEUS_H_UINT
#define UINT8 NUCLEUS_H_UINT8
#define UINT16 NUCLEUS_H_UINT16
#define UINT32 NUCLEUS_H_UINT32
#define WCHAR NUCLEUS_H_WCHAR

#include <nucleus.h>

#undef BOOLEAN
#undef BYTE
#undef CHAR
#undef INT
#undef INT8
#undef INT16
#undef INT32
#undef LONG
#undef UINT
#undef UINT8
#undef UINT16
#undef UINT32
#undef WCHAR

#include <limits.h>

#endif  // Apoxi_Os_NucInc_hpp


