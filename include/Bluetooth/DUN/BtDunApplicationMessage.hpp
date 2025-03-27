/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\DUN\BtDunApplicationMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtDunApplicationMessage_hpp)
#define Bluetooth_BtDunApplicationMessage_hpp

#include <Bluetooth/BtApplicationMessage.hpp>
#include <Bluetooth/BtDevice.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtDunApplicationMessage
    ====================================================================== */

class BtDunApplicationMessage : public BtApplicationMessage {
    public:
        BtDunApplicationMessage(const BtResultCode& result);
        virtual ~BtDunApplicationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10020
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDunConnectMessage
    ====================================================================== */

class BtDunConnectMessage : public BtDunApplicationMessage {
    public:
        BtDunConnectMessage(const BtResultCode& result, const BtDevice& device);
        virtual ~BtDunConnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDevice(const BtDevice& device) { m_device = device; }
        const BtDevice& GetDevice() const { return m_device; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10021
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtDevice m_device;
        
    };


/*  ======================================================================
    Class BtDunDisconnectMessage
    ====================================================================== */

class BtDunDisconnectMessage : public BtDunApplicationMessage {
    public:
        BtDunDisconnectMessage(const BtResultCode& result);
        virtual ~BtDunDisconnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10022
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtDunApplicationMessage_hpp

