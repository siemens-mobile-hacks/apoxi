/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\BtRequestMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtRequestMessage_hpp)
#define Bluetooth_BtRequestMessage_hpp

#include <Kernel/Message.hpp>
#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtRequestMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtRequestMessage
    ====================================================================== */

class BtRequestMessage : public Message {
    public:
        BtRequestMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtRequestMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetResult(const BtResultCode& result) { m_result = result; }
        const BtResultCode& GetResult() const { return m_result; }
        void SetRequestId(UINT32 request_id) { m_request_id = request_id; }
        UINT32 GetRequestId() const { return m_request_id; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10200
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtResultCode m_result;
        UINT32 m_request_id;
        
    };


/*  ======================================================================
    Class BtOpenMessage
    ====================================================================== */

class BtOpenMessage : public BtRequestMessage {
    public:
        BtOpenMessage(const BtResultCode& result, UINT32 request_id, const BtProfile& profile);
        virtual ~BtOpenMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetProfile(const BtProfile& profile) { m_profile = profile; }
        const BtProfile& GetProfile() const { return m_profile; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10201
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtProfile m_profile;
        
    };


/*  ======================================================================
    Class BtCloseMessage
    ====================================================================== */

class BtCloseMessage : public BtRequestMessage {
    public:
        BtCloseMessage(const BtResultCode& result, UINT32 request_id, const BtProfile& profile);
        virtual ~BtCloseMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetProfile(const BtProfile& profile) { m_profile = profile; }
        const BtProfile& GetProfile() const { return m_profile; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10202
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtProfile m_profile;
        
    };

#endif // Bluetooth_BtRequestMessage_hpp

