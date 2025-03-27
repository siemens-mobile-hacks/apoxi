/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\HS\BtHsServiceMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtHsServiceMessage_hpp)
#define Bluetooth_BtHsServiceMessage_hpp

#include <Bluetooth/BtServiceMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtHsRequestStateChangedMessage
    ====================================================================== */

class BtHsRequestStateChangedMessage : public BtRequestStateChangedMessage {
    public:
        BtHsRequestStateChangedMessage(BtService* service, const BtRequestType& request_type, const BtRequestState& old_request_state, const BtRequestState& new_request_state);
        virtual ~BtHsRequestStateChangedMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10325
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtHsServiceMessage_hpp

