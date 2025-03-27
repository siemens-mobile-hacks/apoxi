/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Devices\Messages\TransportTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apoxi_Devices_TransportNotificationMsg_hpp)
#define Apoxi_Devices_TransportNotificationMsg_hpp

#include <Kernel/Message.hpp>
#include <Devices/AbstractTransport.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class TransportNotificationMsg
    ====================================================================== */

class TransportNotificationMsg : public ContextMsg {
    public:
        TransportNotificationMsg(ExecutionContext* context, const AbstractTransport::NotificationMsgType& msg_type);
        virtual ~TransportNotificationMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const AbstractTransport::NotificationMsgType& GetMsgType() const { return m_msg_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 9100
            };
        
    private:
        static const MsgMetaData m_meta_data;
        AbstractTransport::NotificationMsgType m_msg_type;
        
    };

#endif // Apoxi_Devices_TransportNotificationMsg_hpp

