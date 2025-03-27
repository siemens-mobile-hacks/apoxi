/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined (EmApoxiSemaphore_hpp)
#define EmApoxiSemaphore_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

/* Forward Declaration for Apoxi Thread Class implementation using Pimple */
class Semaphore;
 
 class EmApoxiSemaphore  {
     public:
         EmApoxiSemaphore(EmApoxiINT32* l_p_result);
 
         ~EmApoxiSemaphore();

         EmApoxiBOOLEAN Create(EmApoxiINT init_val = 0, 
                                EmApoxiINT max_val = -1);

         EmApoxiBOOLEAN Obtain();

         void Release();
 
     private:
         Semaphore *m_p_semaphore;
         
 };
 
#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  // EmApoxiSemaphore_hpp


