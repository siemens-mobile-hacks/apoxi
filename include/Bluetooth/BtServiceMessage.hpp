/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\BtServiceMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtServiceMessage_hpp)
#define Bluetooth_BtServiceMessage_hpp

#include <Kernel/Message.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtService.hpp>
#include <Bluetooth/BtServiceMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtServiceMessage
    ====================================================================== */

class BtServiceMessage : public Message {
    public:
        BtServiceMessage(BtService* service);
        virtual ~BtServiceMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetService(BtService* service) { m_service = service; }
        BtService* GetService() const { return m_service; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10300
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtService* m_service;
        
    };


/*  ======================================================================
    Class BtRequestStateChangedMessage
    ====================================================================== */

class BtRequestStateChangedMessage : public BtServiceMessage {
    public:
        BtRequestStateChangedMessage(BtService* service, const BtRequestType& request_type, const BtRequestState& old_request_state, const BtRequestState& new_request_state);
        virtual ~BtRequestStateChangedMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetRequestType(const BtRequestType& request_type) { m_request_type = request_type; }
        const BtRequestType& GetRequestType() const { return m_request_type; }
        void SetOldRequestState(const BtRequestState& old_request_state) { m_old_request_state = old_request_state; }
        const BtRequestState& GetOldRequestState() const { return m_old_request_state; }
        void SetNewRequestState(const BtRequestState& new_request_state) { m_new_request_state = new_request_state; }
        const BtRequestState& GetNewRequestState() const { return m_new_request_state; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10305
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtRequestType m_request_type;
        BtRequestState m_old_request_state;
        BtRequestState m_new_request_state;
        
    };

#endif // Bluetooth_BtServiceMessage_hpp

