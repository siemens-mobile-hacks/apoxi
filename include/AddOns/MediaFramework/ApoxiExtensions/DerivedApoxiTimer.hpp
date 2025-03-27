/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (DerivedApoxiTimer_hpp)
#define DerivedApoxiTimer_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include <Kernel/Types.hpp>
#include <Kernel/Timer.hpp>

#include "EmApoxiDataTypes.hpp"

typedef EmApoxiINT (*EmApoxiTimerFunc)(void* context);

class DerivedApoxiTimer: public Timer
{
    public:
        DerivedApoxiTimer();
    
        ~DerivedApoxiTimer();
        virtual void OnTimer();
        
        void RegisterTimerFunction(EmApoxiTimerFunc p_timer_function,void *context=0);

    private:
        EmApoxiTimerFunc m_p_timer_function;
        void            *m_context;

};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //DerivedApoxiTimer_hpp

