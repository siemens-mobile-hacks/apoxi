/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(EmApoxiDataSink_hpp)
#define EmApoxiDataSink_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"


//Forward Declaration of APOXI enum in EmApoxi Layer
class DataSink;


class EmApoxiDataSink {
public:
        
        EmApoxiDataSink(void *p_sinkdata = 0);
        
        ~EmApoxiDataSink();
        
        EmApoxiUINT32 Write(EmApoxiUINT32  l_offset,
                            void *p_buffer,
                            EmApoxiUINT32  l_bytes_to_write );

        EmApoxiUINT32 EmApoxiDataSink::Write( void *p_buffer,                    
                                      EmApoxiUINT32  l_bytes_to_write) ;

        EmApoxiUINT32 GetLength();

private:
        
        //A private member pointer to the APOXI class. "Pimple" method. 
        DataSink *m_p_datasink;

};
#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiDataSink_hpp

