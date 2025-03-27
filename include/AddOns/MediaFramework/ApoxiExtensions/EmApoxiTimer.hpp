/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EmApoxiTimer_hpp)
#define EmApoxiTimer_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiDataTypes.hpp"

/* Forward Declaration for Apoxi Timer Class implementation using Pimple */
class DerivedApoxiTimer;

typedef EmApoxiINT (*EmApoxiTimerFunc)(void *context);

class EmApoxiTimer
{
    public :
        EmApoxiTimer(EmApoxiUINT32* l_p_result = 0);

        ~EmApoxiTimer();

        void Init(EmApoxiUINT32  timeout, 
                EmApoxiBOOLEAN  autotimer = EmApoxiFALSE);
        
        void Start();

        EmApoxiUINT32 Stop();

        void SetTimeout(EmApoxiUINT32 timeout);

        void RegisterTimerFunction(EmApoxiTimerFunc p_timer_function,void *context=0);

        EmApoxiBOOLEAN IsActive();

    private:    
    
        DerivedApoxiTimer *m_p_derived_timer;   

};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiTimer_hpp

