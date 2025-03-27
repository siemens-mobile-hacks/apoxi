/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_AudioMsgProcessor_hpp)
#define Apoxi_Devices_AudioMsgProcessor_hpp

#include <Apc/SignalHandler/StackMsgProcessor.hpp>

/*  ========================================================================
    AudioMsgProcessor
    ======================================================================== */
#ifndef DOXYGEN_SHOULD_SKIP_THIS
class AudioMsgProcessor : public StackMsgProcessor
{
    public:
        static void ProcessAudioSpeechCtrlRequest(INT ControlType, INT link_path, BOOLEAN mute, INT volume);

}; // AudioMsgProcessor
#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif // Apoxi_Devices_AudioMsgProcessor_hpp


