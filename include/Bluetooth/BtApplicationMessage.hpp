/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshot\lnz_development\src\Apoxi\Bluetooth\BtApplicationMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtApplicationMessage_hpp)
#define Bluetooth_BtApplicationMessage_hpp

#include <Kernel/Message.hpp>
#include <Bluetooth/BtTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtApplicationMessage
    ====================================================================== */

class BtApplicationMessage : public Message {
    public:
        BtApplicationMessage(const BtResultCode& result);
        virtual ~BtApplicationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetResult(const BtResultCode& result) { m_result = result; }
        const BtResultCode& GetResult() const { return m_result; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10000
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtResultCode m_result;
        
    };

#endif // Bluetooth_BtApplicationMessage_hpp

