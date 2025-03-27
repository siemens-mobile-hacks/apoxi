/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (DerivedApoxiThread_hpp)
#define DerivedApoxiThread_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include <Kernel/ServiceThread.hpp>
#include "EmApoxiDataTypes.hpp"

class EmApoxiSemaphore;

class DerivedApoxiThread : public Thread
{

    public :
        DerivedApoxiThread(EmApoxiBOOLEAN* p_retValue=0);

        ~DerivedApoxiThread(); 
        
        virtual EmApoxiINT ThreadFn();
        
        EmApoxiBOOLEAN ObtainSemaphore();
        
        void ReleaseSemaphore();

        void RegisterThreadFnPtr(EmApoxiINT ((*ap_ThreadFn)(void* )), void* context);

    private:
        EmApoxiSemaphore *m_p_apoxi_semaphore;
        EmApoxiINT (*m_p_ThreadFn)(void* );
        void* m_p_context;

};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //DerivedApoxiThread_hpp

