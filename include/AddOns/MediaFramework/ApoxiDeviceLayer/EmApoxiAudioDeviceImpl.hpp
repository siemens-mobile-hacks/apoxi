/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined (EmApoxiAudioDeviceImpl_hpp)
#define EmApoxiAudioDeviceImpl_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiAudioDefines.hpp"

EmApoxiBOOLEAN EaadInit();

tEmApxAudDeviceHdl EaadCreate(tEaadCallBackFxn cb_fxn,
                             EaadMediaType media_type,void *user_data=0) ;

tEmApxAudDeviceHdl EaadDummyCreate(tEaadCallBackFxn cb_fxn);

EmApoxiBOOLEAN EaadDummyDestroy(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadSetProperty(tEmApxAudDeviceHdl hndl,EaadAttributes attribute,
                         EmApoxiUINT32 val);

EmApoxiBOOLEAN EaadGetProperty(tEmApxAudDeviceHdl hndl,EaadAttributes attribute,
                         EmApoxiUINT32 *val);

EmApoxiBOOLEAN EaadStartPlayBack(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadStartRecording(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadStopPlayBack(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadStopRecording(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadSuspend(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadResume(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadDestroy(tEmApxAudDeviceHdl hndl);

EmApoxiBOOLEAN EaadDeInit();                                                  

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif //EmApoxiAudioDeviceImpl_hpp

