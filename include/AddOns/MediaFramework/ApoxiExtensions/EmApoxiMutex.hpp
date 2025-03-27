/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */


#if !defined (EmApoxiMutex_hpp)
#define EmApoxiMutex_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

//Forward Declaration of APOXI class in EmApoxi Layer
class Mutex;


class EmApoxiMutex {
    public:

        EmApoxiMutex(EmApoxiINT32* l_p_result);

        ~EmApoxiMutex();

        EmApoxiBOOLEAN Create(EmApoxiBOOLEAN locked = EmApoxiTRUE);

        EmApoxiBOOLEAN Obtain();

        void Release();
    private:

        Mutex *m_p_mutex;

    friend class EmApoxiMutexObtainer;

};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //EmApoxiMutex_hpp

