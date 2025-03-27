/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "lnz_apoxi\Apoxi\Obex\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Obex_ObexTransportMsg_hpp)
#define Obex_ObexTransportMsg_hpp
#include <Kernel/Message.hpp>
#include <Obex/ObexTypes.hpp>
#include <Obex/ObexOperationId.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class ObexTransportMsg
    ====================================================================== */
class ObexTransportMsg : public Message {
    public:
        ObexTransportMsg(const ObexTransportMsgType& msg_type, const ObexTransportId& transport_id, const ObexOperationId& operation_id = ObexOperationId());
        virtual ~ObexTransportMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ObexTransportMsgType& GetMsgType() const { return m_msg_type; }
        const ObexTransportId& GetTransportId() const { return m_transport_id; }
        const ObexOperationId& GetOperationId() const { return m_operation_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 11004
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ObexTransportMsgType m_msg_type;
        ObexTransportId m_transport_id;
        ObexOperationId m_operation_id;
        
    };
#endif // Obex_ObexTransportMsg_hpp


