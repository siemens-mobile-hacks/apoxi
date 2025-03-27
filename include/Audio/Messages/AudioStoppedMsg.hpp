/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Audio\Messages\AudioTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Apoxi_Audio_AudioStoppedMsg_hpp)
#define Apoxi_Audio_AudioStoppedMsg_hpp
#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Auxiliary/SharedPtr.hpp>
#include <Audio/AudioDeviceBase.hpp>
#include <Audio/AudioActiveReference.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class AudioStoppedMsg
    ====================================================================== */
class AudioStoppedMsg : public Message {
    public:
        AudioStoppedMsg(const SharedPtr<AudioActiveReference>& active_reference, BOOLEAN auto_stopped, const AudioDeviceBase::StopCause& stop_cause, const AudioDeviceBase::AudioErrorType& audio_error_type);
        virtual ~AudioStoppedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveReference(const SharedPtr<AudioActiveReference>& active_reference) { m_active_reference = active_reference; }
        const SharedPtr<AudioActiveReference>& GetActiveReference() const { return m_active_reference; }
        void SetAutoStopped(BOOLEAN auto_stopped) { m_auto_stopped = auto_stopped; }
        BOOLEAN IsAutoStopped() const { return m_auto_stopped; }
        void SetStopCause(const AudioDeviceBase::StopCause& stop_cause) { m_stop_cause = stop_cause; }
        const AudioDeviceBase::StopCause& GetStopCause() const { return m_stop_cause; }
        void SetAudioErrorType(const AudioDeviceBase::AudioErrorType& audio_error_type) { m_audio_error_type = audio_error_type; }
        const AudioDeviceBase::AudioErrorType& GetAudioErrorType() const { return m_audio_error_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioActiveReference> m_active_reference;
        BOOLEAN m_auto_stopped;
        AudioDeviceBase::StopCause m_stop_cause;
        AudioDeviceBase::AudioErrorType m_audio_error_type;
        
    };
#endif // Apoxi_Audio_AudioStoppedMsg_hpp

