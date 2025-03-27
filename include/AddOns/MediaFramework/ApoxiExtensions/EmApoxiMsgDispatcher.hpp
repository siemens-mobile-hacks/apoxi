/*
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */
#if !defined (EmApoxiMsgDispatcher_hpp)
#define EmApoxiMsgDispatcher_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/
#ifdef ENABLE_STREAMING
#include "EmApoxiInterface.hpp"
#endif

#include "EmApoxiAudioDeviceImpl.hpp"
#include "EmApoxiPlayerEnum.hpp"

typedef EmApoxiUINT32 (*tCallbackFnPtr)(EmApoxiUINT32);

void SendMessageToDispatcherToApp(EmApoxiMmfMsgType msg_type,
                                  void *m_p_msgdispatcher,
                                  void* instance,
                                  EmApoxiMmfResult mmf_result = EmApoxiSuccess
                                  );

void EmApoxiPostMessageToServiceThread(tEmApxAudDeviceHdl  m_h_aud_device,
                                       tCallbackFnPtr      m_cb_fn_ptr,
                                       void*               m_cb_data,
                                       EmApoxiBOOLEAN      m_is_audio_muted,
                                       EmApoxiBOOLEAN      m_start_stop_audio);

#ifdef ENABLE_STREAMING
void EmApoxiPostMessageToNetworkServiceThread(
    EmNetworkServiceThreadMsgType msg_type,
    EmNetworkExecCbFn *ap_cb_fn,
    void *ap_cb_fn_user_data);
#endif

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif  //EmApoxiMsgDispatcher_hpp

