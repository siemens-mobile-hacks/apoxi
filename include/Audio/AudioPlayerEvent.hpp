/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioPlayerEvent_hpp)
#define Apoxi_AudioPlayerEvent_hpp

#include <Audio/AudioActiveReference.hpp>
#include <Audio/AudioError.hpp>
class AudioPlayer;

struct AudioPlayerEvent {
    
    AudioPlayerEvent():
        m_player(0),
        m_handle(0),
        m_playback_state(AudioActiveReference::InitialState),
        m_reason(InvalidReason),
        m_send_error_message(FALSE),
        m_error_code(0)
        {}
    
    AudioPlayer* m_player;

    AudioActiveReference::HandleInsidePlayer m_handle;

    AudioActiveReference::PlaybackState m_playback_state;

    enum Reason {
        InvalidReason = 0,
        CommandReason,
        NaturalReason, // e.g. finish after EOF
        DriverReason
    };  

    Reason m_reason;

    BOOLEAN m_send_error_message;

    AudioError::AudReturnCode m_error_code;
};

#endif //Apoxi_AudioPlayerEvent_hpp

