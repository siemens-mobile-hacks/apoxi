/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\BtRequestOperationMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtRequestOperationMessage_hpp)
#define Bluetooth_BtRequestOperationMessage_hpp

#include <Kernel/Message.hpp>
#include <Bluetooth/BtOperationBase.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtRequestOperationMessage
    ====================================================================== */

class BtRequestOperationMessage : public Message {
    public:
        BtRequestOperationMessage(const BtOperationPtr& operation);
        virtual ~BtRequestOperationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetOperation(const BtOperationPtr& operation) { m_operation = operation; }
        const BtOperationPtr& GetOperation() const { return m_operation; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10099
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtOperationPtr m_operation;
        
    };

#endif // Bluetooth_BtRequestOperationMessage_hpp

