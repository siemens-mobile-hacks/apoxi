/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(APOXI_StringUtil_h)
#define APOXI_StringUtil_h

#include <Kernel/Types.hpp>
#include <stdarg.h>

inline CHAR CharToUpper(CHAR ch)
{
    if ((ch >= 'a') && (ch <= 'z')) {
        ch = ch - 'a' + 'A';
    }

    return ch;
}

inline CHAR CharToLower(CHAR ch)
{
    if ((ch >= 'A') && (ch <= 'Z')) {
        ch = ch - 'A' + 'a';
    }

    return ch;
}

extern "C" INT StrPrintf(CHAR *str, const CHAR *fmt, ...);
extern "C" void strprintf(CHAR *buffer, const CHAR *format, va_list args, ...);

INT StrPrintf(CHAR *str, INT strSize, const CHAR *fmt, ...);
void strprintf(CHAR *buffer, INT bufSize, const CHAR *format, va_list args, ...);

#endif // APOXI_StringUtil_h

