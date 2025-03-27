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
#if !defined(Obex_ObexMessages_hpp)
#define Obex_ObexMessages_hpp
#include <Kernel/Message.hpp>
#include <Obex/ObexTypes.hpp>
#include <Obex/ObexObject.hpp>
#include <Obex/ObexChannel.hpp>
#include <Obex/ObexAddress.hpp>
#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexOperationId.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class ObexMsg
    ====================================================================== */
class ObexMsg : public Message {
    public:
        ObexMsg(const ObexMsgType& msg_type, const ObexServerId& server_id, const ObexResult& result, const ObexOperationId& operation_id, const ObexChannel& channel, const ObexObject& object = ObexObject());
        virtual ~ObexMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ObexMsgType& GetMsgType() const { return m_msg_type; }
        const ObexServerId& GetServerId() const { return m_server_id; }
        const ObexResult& GetResult() const { return m_result; }
        const ObexOperationId& GetOperationId() const { return m_operation_id; }
        const ObexChannel& GetChannel() const { return m_channel; }
        const ObexObject& GetObject() const { return m_object; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 11000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ObexMsgType m_msg_type;
        ObexServerId m_server_id;
        ObexResult m_result;
        ObexOperationId m_operation_id;
        ObexChannel m_channel;
        ObexObject m_object;
        
    };
/*  ======================================================================
    Class ObexTriggerMsg
    ====================================================================== */
class ObexTriggerMsg : public Message {
    public:
        ObexTriggerMsg(const ObexProtocolId& protocol_id);
        virtual ~ObexTriggerMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ObexProtocolId& GetProtocolId() const { return m_protocol_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 11001
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ObexProtocolId m_protocol_id;
        
    };
/*  ======================================================================
    Class ObexAddrMsg
    ====================================================================== */
class ObexAddrMsg : public Message {
    public:
        ObexAddrMsg(const ObexResult& result, const ObexOperationId& operation_id, const ObexAddrPtr& addr_ptr = ObexAddrPtr());
        virtual ~ObexAddrMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const ObexResult& GetResult() const { return m_result; }
        const ObexOperationId& GetOperationId() const { return m_operation_id; }
        const ObexAddrPtr& GetAddrPtr() const { return m_addr_ptr; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 11002
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ObexResult m_result;
        ObexOperationId m_operation_id;
        ObexAddrPtr m_addr_ptr;
        
    };
#endif // Obex_ObexMessages_hpp


