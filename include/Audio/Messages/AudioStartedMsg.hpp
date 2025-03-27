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


#if !defined(Apoxi_Audio_AudioStartedMsg_hpp)
#define Apoxi_Audio_AudioStartedMsg_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Audio/AudioActiveReference.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AudioStartedMsg
    ====================================================================== */

class AudioStartedMsg : public Message {
    public:
        AudioStartedMsg(const SharedPtr<AudioActiveReference>& active_reference);
        virtual ~AudioStartedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveReference(const SharedPtr<AudioActiveReference>& active_reference) { m_active_reference = active_reference; }
        const SharedPtr<AudioActiveReference>& GetActiveReference() const { return m_active_reference; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9009
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioActiveReference> m_active_reference;
        
    };

#endif // Apoxi_Audio_AudioStartedMsg_hpp

