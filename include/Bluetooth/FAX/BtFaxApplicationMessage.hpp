/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\FAX\BtFaxApplicationMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtFaxApplicationMessage_hpp)
#define Bluetooth_BtFaxApplicationMessage_hpp

#include <Bluetooth/BtApplicationMessage.hpp>
#include <Bluetooth/BtDevice.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtFaxApplicationMessage
    ====================================================================== */

class BtFaxApplicationMessage : public BtApplicationMessage {
    public:
        BtFaxApplicationMessage(const BtResultCode& result);
        virtual ~BtFaxApplicationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10030
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtFaxConnectMessage
    ====================================================================== */

class BtFaxConnectMessage : public BtFaxApplicationMessage {
    public:
        BtFaxConnectMessage(const BtResultCode& result, const BtDevice& device);
        virtual ~BtFaxConnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDevice(const BtDevice& device) { m_device = device; }
        const BtDevice& GetDevice() const { return m_device; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10031
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtDevice m_device;
        
    };


/*  ======================================================================
    Class BtFaxDisconnectMessage
    ====================================================================== */

class BtFaxDisconnectMessage : public BtFaxApplicationMessage {
    public:
        BtFaxDisconnectMessage(const BtResultCode& result);
        virtual ~BtFaxDisconnectMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10032
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtFaxApplicationMessage_hpp

