/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "views\Schwenkr_viewBT\lnz_apoxi\Apoxi\Bluetooth\BPP\BtBppServiceMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtBppServiceMessage_hpp)
#define Bluetooth_BtBppServiceMessage_hpp

#include <Bluetooth/BtServiceMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtBppRequestStateChangedMessage
    ====================================================================== */

class BtBppRequestStateChangedMessage : public BtRequestStateChangedMessage {
    public:
        BtBppRequestStateChangedMessage(BtService* service, const BtRequestType& request_type, const BtRequestState& old_request_state, const BtRequestState& new_request_state);
        virtual ~BtBppRequestStateChangedMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10316
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtBppServiceMessage_hpp

