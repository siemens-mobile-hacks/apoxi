/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(EmApoxiDataTypes_hpp)
#define EmApoxiDataTypes_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/
#include <Kernel/Types.hpp>

#define EmApoxiFALSE           0
#define EmApoxiTRUE            !EmApoxiFALSE

typedef signed char          EmApoxiINT8 ;
typedef unsigned char        EmApoxiUINT8;
typedef short int            EmApoxiINT16;
typedef unsigned short int   EmApoxiUINT16;
typedef int                  EmApoxiINT32;
typedef unsigned int         EmApoxiUINT32;
typedef float                EmApoxiFLOAT;
typedef double               EmApoxiDOUBLE;
//typedef bool               EmApoxiBOOLEAN;
typedef char                 EmApoxiBOOLEAN;
typedef int                  EmApoxiINT;
typedef unsigned int         EmApoxiUINT;

#define EmApoxi_SUCCESS            0
#define EmApoxi_FAILURE            (-1)

#ifndef HUGE
#define HUGE
#endif


#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiDataTypes_hpp

