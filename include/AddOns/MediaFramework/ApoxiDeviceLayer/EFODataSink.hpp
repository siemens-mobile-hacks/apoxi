/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EFODataSink_hpp)
#define EFODataSink_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EFOApoxiLayer.hpp"
#include "EmApoxiDataTypes.hpp"

class EmApoxiDataSink;

EmApoxiUINT32 DataSinkWrite (   void* p_object,
                        void* p_buffer,  
                        EmApoxiUINT32  offset,  
                        EmApoxiUINT32  bytes_to_write );

EmApoxiBOOLEAN DataSinkGetSize (void* p_object, EmApoxiUINT32 &size);

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EFODataSink_hpp

