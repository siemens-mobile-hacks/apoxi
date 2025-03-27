/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Os_OsStrLib_hpp)
#define Apoxi_Os_OsStrLib_hpp

#include <Kernel/Types.hpp>
#include <string.h>
#include <limits.h>

#if defined(APOXI_RTOS_NUC16) | defined(APOXI_RTOS_SIM166)

class OutputStream;
class InputStream;

#endif


    UINT GetStringLen(const char* s);
    UINT GetWStringLen(const wchar_t* w);

#if defined(APOXI_RTOS_NUC16) | defined(APOXI_RTOS_SIM166)

    OutputStream& operator << (OutputStream& ostr, const WCHAR w);
    //InputStream& operator >> (InputStream& istr, WCHAR& w);

#endif

#endif // Apoxi_Os_OsStrLib_hpp


