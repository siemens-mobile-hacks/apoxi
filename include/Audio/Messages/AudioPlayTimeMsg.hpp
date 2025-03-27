/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "simonal_view_sgold_lite\lnz_apoxi\Apoxi\Devices\Messages\AudioTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Apoxi_Devices_AudioPlayTimeMsg_hpp)
#define Apoxi_Devices_AudioPlayTimeMsg_hpp
#include <Kernel/Os/Os.hpp>
#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class AudioPlayTimeMsg
    ====================================================================== */
class AudioPlayTimeMsg : public Message {
    public:
        AudioPlayTimeMsg(UINT32 play_time);
        virtual ~AudioPlayTimeMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPlayTime(UINT32 play_time) { m_play_time = play_time; }
        UINT32 GetPlayTime() const { return m_play_time; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9009
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT32 m_play_time;
        
    };
#endif // Apoxi_Devices_AudioPlayTimeMsg_hpp


