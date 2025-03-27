/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "src\hauth_bip_apoxi_test_sv\lnz_apoxi\Apoxi\Bluetooth\BIP\BtBipServiceMsg.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtBipServiceMsg_hpp)
#define Bluetooth_BtBipServiceMsg_hpp

#include <Bluetooth/BtServiceMessage.hpp>
#include <Bluetooth/BIP/BtBipService.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtBipRequestStateChangedMsg
    ====================================================================== */

class BtBipRequestStateChangedMsg : public BtRequestStateChangedMessage {
    public:
        BtBipRequestStateChangedMsg(BtService* service, const BtRequestType& request_type, const BtRequestState& old_request_state, const BtRequestState& new_request_state);
        virtual ~BtBipRequestStateChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10500
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
};

/*  ======================================================================
    Class BtBipPutImageNextPacketMsg
    ====================================================================== */

class BtBipPutImageNextPacketMsg : public BtServiceMessage {
    public:
        BtBipPutImageNextPacketMsg(BtService* service);
        virtual ~BtBipPutImageNextPacketMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10502
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
};


/*  ======================================================================
    Class BtBipGetImageNextPacketMsg
    ====================================================================== */

class BtBipGetImageNextPacketMsg : public BtServiceMessage {
    public:
        BtBipGetImageNextPacketMsg(BtService* service);
        virtual ~BtBipGetImageNextPacketMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10503
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
};


/*  ======================================================================
    Class BtBipServiceMsg
    ====================================================================== */

class BtBipServiceMsg : public BtServiceMessage {
    public:
        BtBipServiceMsg(BtService* service, const BtBipService::MsgType& msg_type);
        virtual ~BtBipServiceMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const BtBipService::MsgType& GetMsgType() const { return m_msg_type; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10504
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtBipService::MsgType m_msg_type;
        
};

#endif

/*  ======================================================================
    Class BtBipProgressMsg
    ====================================================================== */

class BtBipProgressMsg : public BtServiceMessage {
    public:
        BtBipProgressMsg(BtService* service, const BtRequestType& request_type, UINT32 bytes_processed);
        virtual ~BtBipProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const BtRequestType& GetRequestType() const { return m_request_type; }
        UINT32 GetBytesProcessed() const { return m_bytes_processed; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10506
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtRequestType m_request_type;
        UINT32 m_bytes_processed;
        
    };

#endif // Bluetooth_BtBipServiceMsg_hpp

