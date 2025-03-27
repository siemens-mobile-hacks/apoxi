/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Nuc32_hpp)
#define Apoxi_Nuc32_hpp

#include <Kernel/Os/Nuc32/NucInc.hpp>

// ----------------------------------------------------------------
//
//                          constants
//
// ----------------------------------------------------------------
#define APOXI_NEVER_TIMEOUT NU_SUSPEND

// ----------------------------------------------------------------
//
//                          types
//
// ----------------------------------------------------------------

typedef unsigned char       ThreadPriority;
typedef char *              ThreadName;
typedef NU_TASK             Task;

#endif  // Apoxi_Nuc32_hpp

