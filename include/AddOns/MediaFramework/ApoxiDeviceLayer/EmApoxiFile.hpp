/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiFile_hpp)
#define EmApoxiFile_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EFOApoxiLayer.hpp"

class File;

void* FileDataOpen (const char* p_filename, EFOFileOpenMode openmode);

void FileDataClose ( void* p_object);

EmApoxiUINT32 FileDataRead (void* p_object, 
                        void* p_buffer,  
                        EmApoxiUINT32  offset,  
                        EmApoxiUINT32  bytes_to_read );

EmApoxiUINT32 FileDataWrite (void* p_object, 
                        void* p_buffer,  
                        EmApoxiUINT32  offset,  
                        EmApoxiUINT32  bytes_to_write );

EmApoxiBOOLEAN FileDataGetSize ( void* p_object, EmApoxiUINT32 &size);

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiFile_hpp

