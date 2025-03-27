/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EmApoxiOs_hpp)
#define EmApoxiOs_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiTicks.hpp"


class EmApoxiTicks;


class EmApoxiOs {
    
    public:
        EmApoxiOs();

        ~EmApoxiOs();
        
        static EmApoxiTicks GetTicks();

        static void Sleep(EmApoxiUINT32 timeout);

        static void* Alloc(EmApoxiINT32 size, EmApoxiUINT32 heapid = 0 );

        static void* Realloc(void* oldaddress, EmApoxiINT32 newsize, 
                            EmApoxiBOOLEAN shallcopy = EmApoxiFALSE);

        static void Free(void* p);

        static void* HugeAlloc(EmApoxiUINT32 size, EmApoxiUINT32 heapid = 0 );

        static void HugeFree(void* p);

        


};

EmApoxiUINT32 EmApoxiFFS_get_raw_free_space_in_global_pool();

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiOs_hpp

