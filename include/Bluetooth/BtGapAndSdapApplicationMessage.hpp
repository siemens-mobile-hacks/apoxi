/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshot\lnz_development\src\Apoxi\Bluetooth\BtGapAndSdapApplicationMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtGapAndSdapApplicationMessage_hpp)
#define Bluetooth_BtGapAndSdapApplicationMessage_hpp

#include <Bluetooth/BtApplicationMessage.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtGapAndSdapApplicationMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtGapAndSdapApplicationMessage
    ====================================================================== */

class BtGapAndSdapApplicationMessage : public BtApplicationMessage {
    public:
        BtGapAndSdapApplicationMessage(const BtResultCode& result);
        virtual ~BtGapAndSdapApplicationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10010
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtGapAndSdapRemoteRequestMessage
    ====================================================================== */

class BtGapAndSdapRemoteRequestMessage : public BtGapAndSdapApplicationMessage {
    public:
        BtGapAndSdapRemoteRequestMessage(const BtResultCode& result, const BtDeviceAddress& device_address, const WString& device_name);
        virtual ~BtGapAndSdapRemoteRequestMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDeviceAddress(const BtDeviceAddress& device_address) { m_device_address = device_address; }
        const BtDeviceAddress& GetDeviceAddress() const { return m_device_address; }
        void SetDeviceName(const WString& device_name) { m_device_name = device_name; }
        const WString& GetDeviceName() const { return m_device_name; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10011
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtDeviceAddress m_device_address;
        WString m_device_name;
        
    };


/*  ======================================================================
    Class BtPasskeyRequiredMessage
    ====================================================================== */

class BtPasskeyRequiredMessage : public BtGapAndSdapRemoteRequestMessage {
    public:
        BtPasskeyRequiredMessage(const BtResultCode& result, const BtDeviceAddress& device_address, const WString& device_name);
        virtual ~BtPasskeyRequiredMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10012
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtAuthorizationRequiredMessage
    ====================================================================== */

class BtAuthorizationRequiredMessage : public BtGapAndSdapRemoteRequestMessage {
    public:
        BtAuthorizationRequiredMessage(const BtResultCode& result, const BtDeviceAddress& device_address, const WString& device_name, const BtProfile& profile);
        virtual ~BtAuthorizationRequiredMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetProfile(const BtProfile& profile) { m_profile = profile; }
        const BtProfile& GetProfile() const { return m_profile; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10013
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtProfile m_profile;
        
    };


/*  ======================================================================
    Class BtGapAndSdapNotificationMessage
    ====================================================================== */

class BtGapAndSdapNotificationMessage : public BtGapAndSdapApplicationMessage {
    public:
        BtGapAndSdapNotificationMessage(const BtResultCode& result);
        virtual ~BtGapAndSdapNotificationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10014
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtRemoteDevicePairMessage
    ====================================================================== */

class BtRemoteDevicePairMessage : public BtGapAndSdapNotificationMessage {
    public:
        BtRemoteDevicePairMessage(const BtResultCode& result);
        virtual ~BtRemoteDevicePairMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10015
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtGapAndSdapApplicationMessage_hpp

