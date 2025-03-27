/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\bt_avrcp_multiconnection\lnz_apoxi\Apoxi\Bluetooth\AVRCP\BtAvrcpServiceMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(Bluetooth_BtAvrcpServiceMessage_hpp)
#define Bluetooth_BtAvrcpServiceMessage_hpp
#include <Bluetooth/BtServiceMessage.hpp>
/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class BtAvrcpRequestStateChangedMessage
    ====================================================================== */
class BtAvrcpRequestStateChangedMessage : public BtRequestStateChangedMessage {
    public:
        BtAvrcpRequestStateChangedMessage(BtService* service, const BtRequestType& request_type, const BtRequestState& old_request_state, const BtRequestState& new_request_state);
        virtual ~BtAvrcpRequestStateChangedMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10455
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif // Bluetooth_BtAvrcpServiceMessage_hpp

