/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "wickhara_latest_dv\lnz_apoxi\Apoxi\Devices\RtcMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Devices_RtcMsgTypes_hpp)
#define Devices_RtcMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Devices/RealTimeClock.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class RtcInfoMsg
    ====================================================================== */

class RtcInfoMsg : public Message {
    public:
        RtcInfoMsg(const RealTimeClock::RtcInfo& rtc_info);
        virtual ~RtcInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const RealTimeClock::RtcInfo& GetRtcInfo() const { return m_rtc_info; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9050
            };
        
    private:
        static const MsgMetaData m_meta_data;
        RealTimeClock::RtcInfo m_rtc_info;
        
    };

#endif // Devices_RtcMsgTypes_hpp

