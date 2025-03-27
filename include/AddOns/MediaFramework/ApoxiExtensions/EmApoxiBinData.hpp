/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined (EmApoxiBinData_hpp)
#define EmApoxiBinData_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

//Forward Declaration of APOXI class in EmApoxi Layer
class BinData;

class EmApoxiBinData {
public:
        
        EmApoxiBinData(const BinData *p_bindata = 0);
        
        ~EmApoxiBinData();
        
        EmApoxiUINT32 Read(EmApoxiUINT32 idx, void *buffer, EmApoxiUINT32 nbytes);
        
        EmApoxiUINT32 GetLength() ; 
        
private:
        
        BinData *m_p_bindata;
        
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiBinData_hpp


