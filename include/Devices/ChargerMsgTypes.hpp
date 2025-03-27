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
    defined in "auzinger_view_fp1g_dv_snap\lnz_apoxi\Apoxi\Devices\ChargerMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Devices_ChargerMsgTypes_hpp)
#define Devices_ChargerMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Apc/SignalTypes.hpp>
#include <Devices/Charger.hpp>

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class ChargerInfoMsg
    ====================================================================== */

class ChargerInfoMsg : public Message {
    public:
        ChargerInfoMsg(const Charger::ChargerMsgType& charger_msg_type);
        virtual ~ChargerInfoMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Charger::ChargerMsgType& GetChargerMsgType() const { return m_charger_msg_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9150
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Charger::ChargerMsgType m_charger_msg_type;
        
    };


/*  ======================================================================
    Class BatteryLoadLevelMsg
    ====================================================================== */

class BatteryLoadLevelMsg : public Message {
    public:
        BatteryLoadLevelMsg(const BatteryLoadLevel& arg);
        virtual ~BatteryLoadLevelMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetArg(const BatteryLoadLevel& arg) { m_arg = arg; }
        const BatteryLoadLevel& GetArg() const { return m_arg; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9151
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BatteryLoadLevel m_arg;
        
    };

#endif // Devices_ChargerMsgTypes_hpp

