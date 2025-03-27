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
    defined in "src\wickhara_apoxitest_host\lnz_apoxi\Apoxi\Devices\LedMsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Devices_LedMsgTypes_hpp)
#define Devices_LedMsgTypes_hpp

#include <Kernel/Message.hpp>
#include <Devices/Led.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

#ifdef APOXI_LED_NEW_INTERFACE


/*  ======================================================================
    Class LedNotificationMsg
    ====================================================================== */

class LedNotificationMsg : public Message {
    public:
        LedNotificationMsg(INT led_id, INT sequence_id, const Led::Notification& notification);
        virtual ~LedNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        INT GetLedId() const { return m_led_id; }
        INT GetSequenceId() const { return m_sequence_id; }
        const Led::Notification& GetNotification() const { return m_notification; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9070
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_led_id;
        INT m_sequence_id;
        Led::Notification m_notification;
        
    };

#endif //APOXI_LED_NEW_INTERFACE

#endif // Devices_LedMsgTypes_hpp

