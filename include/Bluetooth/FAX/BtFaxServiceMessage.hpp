/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\FAX\BtFaxServiceMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtFaxServiceMessage_hpp)
#define Bluetooth_BtFaxServiceMessage_hpp

#include <Bluetooth/BtServiceMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtFaxRequestStateChangedMessage
    ====================================================================== */

class BtFaxRequestStateChangedMessage : public BtRequestStateChangedMessage {
    public:
        BtFaxRequestStateChangedMessage(BtService* service, const BtRequestType& request_type, const BtRequestState& old_request_state, const BtRequestState& new_request_state);
        virtual ~BtFaxRequestStateChangedMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10320
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtFaxServiceMessage_hpp

