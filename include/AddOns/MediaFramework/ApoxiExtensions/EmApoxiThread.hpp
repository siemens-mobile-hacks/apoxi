/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EmApoxiThread_hpp)
#define EmApoxiThread_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

/* # define for setting the different Priority for Local Playback and Streaming */
#define PLAYBACK_PRIORITY 102
#define STREAMING_PRIORITY 141

/* Forward Declaration for Apoxi Thread Class implementation using Pimple */
class DerivedApoxiThread;

class EmApoxiThread
{

    public :
        EmApoxiThread(EmApoxiUINT32* l_p_result = 0);

        ~EmApoxiThread();
        
        void RegisterThreadFnPtr(EmApoxiINT ((*ap_ThreadFn)(void* )), void* context);

        EmApoxiBOOLEAN Run(EmApoxiUINT32  stacksize = 4096,  void *  stack = 0);
        
        EmApoxiINT GetPriority();

        EmApoxiBOOLEAN SetPriority(EmApoxiINT priority);

        EmApoxiINT ObtainPlaybackPriority();

        EmApoxiINT ObtainStreamingPriority();

        EmApoxiBOOLEAN ObtainSemaphore();

        void ReleaseSemaphore();

    private:
        DerivedApoxiThread  *m_p_derived_apoxi_thread;
};

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiThread_hpp

