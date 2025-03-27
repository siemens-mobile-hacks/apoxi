/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */


#if !defined (EmApoxiMutexObtainer_hpp)
#define EmApoxiMutexObtainer_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"
#include "EmApoxiMutex.hpp"

//Forward Declaration of APOXI class in EmApoxi Layer
class MutexObtainer;


class EmApoxiMutexObtainer {
    public:

    EmApoxiMutexObtainer(const EmApoxiMutex* mutex);
    ~EmApoxiMutexObtainer();
    
    private:

    MutexObtainer *m_p_mutex_obtainer;

};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //EmApoxiMutexObtainer

