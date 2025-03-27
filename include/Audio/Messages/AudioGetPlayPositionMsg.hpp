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


#if !defined(Apoxi_Audio_AudioGetPlayPositionMsg_hpp)
#define Apoxi_Audio_AudioGetPlayPositionMsg_hpp

#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Audio/AudioActiveReference.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class AudioGetPlayPositionMsg
    ====================================================================== */

class AudioGetPlayPositionMsg : public Message {
    public:
        AudioGetPlayPositionMsg(const SharedPtr<AudioActiveReference>& active_reference, UINT32 param1, UINT32 param2, UINT32 param3, UINT32 param4);
        virtual ~AudioGetPlayPositionMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveReference(const SharedPtr<AudioActiveReference>& active_reference) { m_active_reference = active_reference; }
        const SharedPtr<AudioActiveReference>& GetActiveReference() const { return m_active_reference; }
        void SetParam1(UINT32 param1) { m_param1 = param1; }
        UINT32 GetParam1() const { return m_param1; }
        void SetParam2(UINT32 param2) { m_param2 = param2; }
        UINT32 GetParam2() const { return m_param2; }
        void SetParam3(UINT32 param3) { m_param3 = param3; }
        UINT32 GetParam3() const { return m_param3; }
        void SetParam4(UINT32 param4) { m_param4 = param4; }
        UINT32 GetParam4() const { return m_param4; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9011
            };
        
    private:
        static const MsgMetaData m_meta_data;
        SharedPtr<AudioActiveReference> m_active_reference;
        UINT32 m_param1;
        UINT32 m_param2;
        UINT32 m_param3;
        UINT32 m_param4;
        
    };

#endif // Apoxi_Audio_AudioGetPlayPositionMsg_hpp

