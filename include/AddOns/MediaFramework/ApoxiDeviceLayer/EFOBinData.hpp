/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EFOBinData_hpp)
#define EFOBinData_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EFOApoxiLayer.hpp"

class EmApoxiBinData;

EmApoxiUINT32 BinDataRead (void* p_object, 
                    void* p_buffer,  
                    EmApoxiUINT32  offset,  
                    EmApoxiUINT32  bytes_to_read );

EmApoxiBOOLEAN BinDataGetSize (void* p_object, EmApoxiUINT32 &size);

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EFOBinData_hpp

