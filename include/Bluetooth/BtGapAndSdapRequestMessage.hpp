/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "Snapshots\APOXI_DEVELOPMENT_SV\lnz_apoxi\Apoxi\Bluetooth\BtGapAndSdapRequestMessage.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Bluetooth_BtGapAndSdapRequestMessage_hpp)
#define Bluetooth_BtGapAndSdapRequestMessage_hpp

#include <Bluetooth/BtRequestMessage.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtGapAndSdapRequestMessage.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class BtGapAndSdapRequestMessage
    ====================================================================== */

class BtGapAndSdapRequestMessage : public BtRequestMessage {
    public:
        BtGapAndSdapRequestMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtGapAndSdapRequestMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10210
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtStateChangedMessage
    ====================================================================== */

class BtStateChangedMessage : public BtGapAndSdapRequestMessage {
    public:
        BtStateChangedMessage(const BtResultCode& result, UINT32 request_id, const BtStackState& stack_state);
        virtual ~BtStateChangedMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetStackState(const BtStackState& stack_state) { m_stack_state = stack_state; }
        const BtStackState& GetStackState() const { return m_stack_state; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10211
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtStackState m_stack_state;
        
    };


/*  ======================================================================
    Class BtLocalSettingsMessage
    ====================================================================== */

class BtLocalSettingsMessage : public BtGapAndSdapRequestMessage {
    public:
        BtLocalSettingsMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtLocalSettingsMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10212
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtLocalNameMessage
    ====================================================================== */

class BtLocalNameMessage : public BtLocalSettingsMessage {
    public:
        BtLocalNameMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtLocalNameMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10213
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDiscoverabilityMessage
    ====================================================================== */

class BtDiscoverabilityMessage : public BtLocalSettingsMessage {
    public:
        BtDiscoverabilityMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtDiscoverabilityMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10214
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtPairabilityMessage
    ====================================================================== */

class BtPairabilityMessage : public BtLocalSettingsMessage {
    public:
        BtPairabilityMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtPairabilityMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10215
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtConnectabilityMessage
    ====================================================================== */

class BtConnectabilityMessage : public BtLocalSettingsMessage {
    public:
        BtConnectabilityMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtConnectabilityMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10216
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtProfileActivationMessage
    ====================================================================== */

class BtProfileActivationMessage : public BtLocalSettingsMessage {
    public:
        BtProfileActivationMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtProfileActivationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10217
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtSendPasskeyMessage
    ====================================================================== */

class BtSendPasskeyMessage : public BtGapAndSdapRequestMessage {
    public:
        BtSendPasskeyMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtSendPasskeyMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10218
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtRespondAuthorizationMessage
    ====================================================================== */

class BtRespondAuthorizationMessage : public BtGapAndSdapRequestMessage {
    public:
        BtRespondAuthorizationMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtRespondAuthorizationMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10219
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDeviceSearchMessage
    ====================================================================== */

class BtDeviceSearchMessage : public BtGapAndSdapRequestMessage {
    public:
        BtDeviceSearchMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtDeviceSearchMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10220
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtRemoteDeviceMessage
    ====================================================================== */

class BtRemoteDeviceMessage : public BtGapAndSdapRequestMessage {
    public:
        BtRemoteDeviceMessage(const BtResultCode& result, UINT32 request_id, const BtDeviceAddress& device_address, const BtDeviceAndServiceClass& device_and_service_class, UINT8 signal_strength);
        virtual ~BtRemoteDeviceMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDeviceAddress(const BtDeviceAddress& device_address) { m_device_address = device_address; }
        const BtDeviceAddress& GetDeviceAddress() const { return m_device_address; }
        void SetDeviceAndServiceClass(const BtDeviceAndServiceClass& device_and_service_class) { m_device_and_service_class = device_and_service_class; }
        const BtDeviceAndServiceClass& GetDeviceAndServiceClass() const { return m_device_and_service_class; }
        void SetSignalStrength(UINT8 signal_strength) { m_signal_strength = signal_strength; }
        UINT8 GetSignalStrength() const { return m_signal_strength; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10221
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtDeviceAddress m_device_address;
        BtDeviceAndServiceClass m_device_and_service_class;
        UINT8 m_signal_strength;
        
    };


/*  ======================================================================
    Class BtRemoteDeviceNameMessage
    ====================================================================== */

class BtRemoteDeviceNameMessage : public BtGapAndSdapRequestMessage {
    public:
        BtRemoteDeviceNameMessage(const BtResultCode& result, UINT32 request_id, const BtDeviceAddress& device_address, const WString& device_name);
        virtual ~BtRemoteDeviceNameMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDeviceAddress(const BtDeviceAddress& device_address) { m_device_address = device_address; }
        const BtDeviceAddress& GetDeviceAddress() const { return m_device_address; }
        void SetDeviceName(const WString& device_name) { m_device_name = device_name; }
        const WString& GetDeviceName() const { return m_device_name; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10222
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtDeviceAddress m_device_address;
        WString m_device_name;
        
    };


/*  ======================================================================
    Class BtCancelSearchMessage
    ====================================================================== */

class BtCancelSearchMessage : public BtGapAndSdapRequestMessage {
    public:
        BtCancelSearchMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtCancelSearchMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10223
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtSetRemoteDeviceNameMessage
    ====================================================================== */

class BtSetRemoteDeviceNameMessage : public BtGapAndSdapRequestMessage {
    public:
        BtSetRemoteDeviceNameMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtSetRemoteDeviceNameMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10224
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDevicePairMessage
    ====================================================================== */

class BtDevicePairMessage : public BtGapAndSdapRequestMessage {
    public:
        BtDevicePairMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtDevicePairMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10225
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDeviceUnpairMessage
    ====================================================================== */

class BtDeviceUnpairMessage : public BtGapAndSdapRequestMessage {
    public:
        BtDeviceUnpairMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtDeviceUnpairMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10226
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDeviceTrustMessage
    ====================================================================== */

class BtDeviceTrustMessage : public BtGapAndSdapRequestMessage {
    public:
        BtDeviceTrustMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtDeviceTrustMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10227
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtDeviceUntrustMessage
    ====================================================================== */

class BtDeviceUntrustMessage : public BtGapAndSdapRequestMessage {
    public:
        BtDeviceUntrustMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtDeviceUntrustMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10228
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtQuerySupportedProfilesMessage
    ====================================================================== */

class BtQuerySupportedProfilesMessage : public BtGapAndSdapRequestMessage {
    public:
        BtQuerySupportedProfilesMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtQuerySupportedProfilesMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10229
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtHsSupportedProfileMessage
    ====================================================================== */

class BtHsSupportedProfileMessage : public BtGapAndSdapRequestMessage {
    public:
        BtHsSupportedProfileMessage(const BtResultCode& result, UINT32 request_id, const WString& hs_profile_name, BOOLEAN hs_has_remote_volume_control);
        virtual ~BtHsSupportedProfileMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetHsProfileName(const WString& hs_profile_name) { m_hs_profile_name = hs_profile_name; }
        const WString& GetHsProfileName() const { return m_hs_profile_name; }
        void SetHsHasRemoteVolumeControl(BOOLEAN hs_has_remote_volume_control) { m_hs_has_remote_volume_control = hs_has_remote_volume_control; }
        BOOLEAN IsHsHasRemoteVolumeControl() const { return m_hs_has_remote_volume_control; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10230
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_hs_profile_name;
        BOOLEAN m_hs_has_remote_volume_control;
        
    };


/*  ======================================================================
    Class BtHfSupportedProfileMessage
    ====================================================================== */

class BtHfSupportedProfileMessage : public BtGapAndSdapRequestMessage {
    public:
        BtHfSupportedProfileMessage(const BtResultCode& result, UINT32 request_id, const WString& hf_profile_name, UINT16 hf_supported_features);
        virtual ~BtHfSupportedProfileMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetHfProfileName(const WString& hf_profile_name) { m_hf_profile_name = hf_profile_name; }
        const WString& GetHfProfileName() const { return m_hf_profile_name; }
        void SetHfSupportedFeatures(UINT16 hf_supported_features) { m_hf_supported_features = hf_supported_features; }
        UINT16 GetHfSupportedFeatures() const { return m_hf_supported_features; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10231
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_hf_profile_name;
        UINT16 m_hf_supported_features;
        
    };


/*  ======================================================================
    Class BtPaSupportedProfileMessage
    ====================================================================== */

class BtPaSupportedProfileMessage : public BtGapAndSdapRequestMessage {
    public:
        BtPaSupportedProfileMessage(const BtResultCode& result, UINT32 request_id, const WString& pa_profile_name);
        virtual ~BtPaSupportedProfileMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetPaProfileName(const WString& pa_profile_name) { m_pa_profile_name = pa_profile_name; }
        const WString& GetPaProfileName() const { return m_pa_profile_name; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10232
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_pa_profile_name;
        
    };


/*  ======================================================================
    Class BtServiceVerifyMessage
    ====================================================================== */

class BtServiceVerifyMessage : public BtGapAndSdapRequestMessage {
    public:
        BtServiceVerifyMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtServiceVerifyMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10233
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };


/*  ======================================================================
    Class BtServiceVerifyResultMessage
    ====================================================================== */

class BtServiceVerifyResultMessage : public BtGapAndSdapRequestMessage {
    public:
        BtServiceVerifyResultMessage(const BtResultCode& result, UINT32 request_id, const BtDeviceAddress& device_address, const WString& device_name, void* data, UINT16 data_size);
        virtual ~BtServiceVerifyResultMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetDeviceAddress(const BtDeviceAddress& device_address) { m_device_address = device_address; }
        const BtDeviceAddress& GetDeviceAddress() const { return m_device_address; }
        void SetDeviceName(const WString& device_name) { m_device_name = device_name; }
        const WString& GetDeviceName() const { return m_device_name; }
        void SetData(void* data) { m_data = data; }
        void* GetData() const { return m_data; }
        void SetDataSize(UINT16 data_size) { m_data_size = data_size; }
        UINT16 GetDataSize() const { return m_data_size; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 10234
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BtDeviceAddress m_device_address;
        WString m_device_name;
        void* m_data;
        UINT16 m_data_size;
        
    };


/*  ======================================================================
    Class BtCancelVerifyMessage
    ====================================================================== */

class BtCancelVerifyMessage : public BtGapAndSdapRequestMessage {
    public:
        BtCancelVerifyMessage(const BtResultCode& result, UINT32 request_id);
        virtual ~BtCancelVerifyMessage();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 10235
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

#endif // Bluetooth_BtGapAndSdapRequestMessage_hpp

