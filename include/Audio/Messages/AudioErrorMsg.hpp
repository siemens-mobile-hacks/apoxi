/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\wickhara_apoxitest_host\lnz_apoxi\Apoxi\Audio\Messages\AudioTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apoxi_Audio_AudioErrorMsg_hpp)
#define Apoxi_Audio_AudioErrorMsg_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Auxiliary/SharedPtr.hpp>
#include <Audio/AudioError.hpp>

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AudioErrorMsg
    ====================================================================== */

class AudioErrorMsg : public Message {
    public:
        AudioErrorMsg(const SharedPtr<AudioReference>& audio_reference, const AudioError::ErrorType& audio_error);
        virtual ~AudioErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetAudioReference(const SharedPtr<AudioReference>& audio_reference) { m_audio_reference = audio_reference; }
        const SharedPtr<AudioReference>& GetAudioReference() const { return m_audio_reference; }
        void SetAudioError(const AudioError::ErrorType& audio_error) { m_audio_error = audio_error; }
        const AudioError::ErrorType& GetAudioError() const { return m_audio_error; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9004
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioReference> m_audio_reference;
        AudioError::ErrorType m_audio_error;
        
    };

#endif // Apoxi_Audio_AudioErrorMsg_hpp

