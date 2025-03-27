/*  ------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH &amp; Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "auzinger_apoxi_test_dv\lnz_apoxi\Apoxi\Apc\SmsArgs.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/


#if !defined(Apc_SmsStackMsgArgs_hpp)
#define Apc_SmsStackMsgArgs_hpp

#include <Apc/StackMsgArgument.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/SimDataTypes.hpp>
#include <Apc/Sms.hpp>
#include <Apc/MdhTypes.hpp>
#include <Apc/SimTkTypes.hpp>


/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */

/*  ======================================================================
    Class SmsNewMessageIndArg
    ====================================================================== */

class SmsNewMessageIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsNewMessageIndArg();
        
        static const SmsNewMessageIndArg& Cast(const StackMsgArgument& arg);
        void SetStorageType(const Sms::StorageType& storage_type) { m_storage_type = storage_type; }
        const Sms::StorageType& GetStorageType() const { return m_storage_type; }
        void SetStoragePosition(INT storage_position) { m_storage_position = storage_position; }
        INT GetStoragePosition() const { return m_storage_position; }
        void SetProtocolIdentifier(const ProtocolIdentifier& protocol_identifier) { m_protocol_identifier = protocol_identifier; }
        const ProtocolIdentifier& GetProtocolIdentifier() const { return m_protocol_identifier; }
        void SetDataCodingScheme(const DataCodingScheme& data_coding_scheme) { m_data_coding_scheme = data_coding_scheme; }
        const DataCodingScheme& GetDataCodingScheme() const { return m_data_coding_scheme; }
        void SetOaPhoneNumber(const PhoneNumber& oa_phone_number) { m_oa_phone_number = oa_phone_number; }
        const PhoneNumber& GetOaPhoneNumber() const { return m_oa_phone_number; }
        
        enum  {
            ID = 2560
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsNewMessageIndArg*) arg); }
        
        Sms::StorageType m_storage_type;
        INT m_storage_position;
        ProtocolIdentifier m_protocol_identifier;
        DataCodingScheme m_data_coding_scheme;
        PhoneNumber m_oa_phone_number;
        
    };

// Inline definitions
inline const SmsNewMessageIndArg& SmsNewMessageIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsNewMessageIndArg!\n");
    return ((SmsNewMessageIndArg &) arg);
}



/*  ======================================================================
    Class SmsNewStatusReportIndArg
    ====================================================================== */

class SmsNewStatusReportIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsNewStatusReportIndArg();
        
        static const SmsNewStatusReportIndArg& Cast(const StackMsgArgument& arg);
        void SetStorageType(const Sms::StorageType& storage_type) { m_storage_type = storage_type; }
        const Sms::StorageType& GetStorageType() const { return m_storage_type; }
        void SetStoragePosition(INT storage_position) { m_storage_position = storage_position; }
        INT GetStoragePosition() const { return m_storage_position; }
        void SetReferenceNumber(const SmsReferenceNumber& reference_number) { m_reference_number = reference_number; }
        const SmsReferenceNumber& GetReferenceNumber() const { return m_reference_number; }
        void SetShortMessageStatus(const ShortMessageStatus& short_message_status) { m_short_message_status = short_message_status; }
        const ShortMessageStatus& GetShortMessageStatus() const { return m_short_message_status; }
        void SetSmsrLocation(const MdhSmsrLocation& smsr_location) { m_smsr_location = smsr_location; }
        const MdhSmsrLocation& GetSmsrLocation() const { return m_smsr_location; }
        void SetRecipientPhoneNumber(const PhoneNumber& recipient_phone_number) { m_recipient_phone_number = recipient_phone_number; }
        const PhoneNumber& GetRecipientPhoneNumber() const { return m_recipient_phone_number; }
        
        enum  {
            ID = 2561
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsNewStatusReportIndArg*) arg); }
        
        Sms::StorageType m_storage_type;
        INT m_storage_position;
        SmsReferenceNumber m_reference_number;
        ShortMessageStatus m_short_message_status;
        MdhSmsrLocation m_smsr_location;
        PhoneNumber m_recipient_phone_number;
        
    };

// Inline definitions
inline const SmsNewStatusReportIndArg& SmsNewStatusReportIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsNewStatusReportIndArg!\n");
    return ((SmsNewStatusReportIndArg &) arg);
}



/*  ======================================================================
    Class SmsSendCnfArg
    ====================================================================== */

class SmsSendCnfArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsSendCnfArg();
        
        static const SmsSendCnfArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetResult(const Sms::Result& result) { m_result = result; }
        const Sms::Result& GetResult() const { return m_result; }
        void SetShortMessageFailure(BOOLEAN short_message_failure) { m_short_message_failure = short_message_failure; }
        BOOLEAN IsShortMessageFailure() const { return m_short_message_failure; }
        void SetShortMessageFailureCause(const ShortMessageFailureCause& short_message_failure_cause) { m_short_message_failure_cause = short_message_failure_cause; }
        const ShortMessageFailureCause& GetShortMessageFailureCause() const { return m_short_message_failure_cause; }
        void SetReferenceNumber(const SmsReferenceNumber& reference_number) { m_reference_number = reference_number; }
        const SmsReferenceNumber& GetReferenceNumber() const { return m_reference_number; }
        
        enum  {
            ID = 2562
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsSendCnfArg*) arg); }
        
        SimTkTransactionId m_tid;
        Sms::Result m_result;
        BOOLEAN m_short_message_failure;
        ShortMessageFailureCause m_short_message_failure_cause;
        SmsReferenceNumber m_reference_number;
        
    };

// Inline definitions
inline const SmsSendCnfArg& SmsSendCnfArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsSendCnfArg!\n");
    return ((SmsSendCnfArg &) arg);
}



/*  ======================================================================
    Class SmsSendRejArg
    ====================================================================== */

class SmsSendRejArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsSendRejArg();
        
        static const SmsSendRejArg& Cast(const StackMsgArgument& arg);
        void SetTid(const SimTkTransactionId& tid) { m_tid = tid; }
        const SimTkTransactionId& GetTid() const { return m_tid; }
        void SetResult(const Sms::Result& result) { m_result = result; }
        const Sms::Result& GetResult() const { return m_result; }
        
        enum  {
            ID = 2563
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsSendRejArg*) arg); }
        
        SimTkTransactionId m_tid;
        Sms::Result m_result;
        
    };

// Inline definitions
inline const SmsSendRejArg& SmsSendRejArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsSendRejArg!\n");
    return ((SmsSendRejArg &) arg);
}



/*  ======================================================================
    Class SmsCapacityExceededArg
    ====================================================================== */

class SmsCapacityExceededArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsCapacityExceededArg();
        
        static const SmsCapacityExceededArg& Cast(const StackMsgArgument& arg);
        void SetWarningLevel(const Sms::WarningLevel& warning_level) { m_warning_level = warning_level; }
        const Sms::WarningLevel& GetWarningLevel() const { return m_warning_level; }
        
        enum  {
            ID = 2564
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsCapacityExceededArg*) arg); }
        
        Sms::WarningLevel m_warning_level;
        
    };

// Inline definitions
inline const SmsCapacityExceededArg& SmsCapacityExceededArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsCapacityExceededArg!\n");
    return ((SmsCapacityExceededArg &) arg);
}



/*  ======================================================================
    Class SmsCapacityAvailableArg
    ====================================================================== */

class SmsCapacityAvailableArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsCapacityAvailableArg();
        
        static const SmsCapacityAvailableArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2565
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsCapacityAvailableArg*) arg); }
        
    };

// Inline definitions
inline const SmsCapacityAvailableArg& SmsCapacityAvailableArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsCapacityAvailableArg!\n");
    return ((SmsCapacityAvailableArg &) arg);
}



/*  ======================================================================
    Class SmsGetMoreMessageStatusIndArg
    ====================================================================== */

class SmsGetMoreMessageStatusIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsGetMoreMessageStatusIndArg();
        
        static const SmsGetMoreMessageStatusIndArg& Cast(const StackMsgArgument& arg);
        void SetSmsMoreMessageType(const SmsMoreMessageType& sms_more_message_type) { m_sms_more_message_type = sms_more_message_type; }
        const SmsMoreMessageType& GetSmsMoreMessageType() const { return m_sms_more_message_type; }
        
        enum  {
            ID = 2566
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsGetMoreMessageStatusIndArg*) arg); }
        
        SmsMoreMessageType m_sms_more_message_type;
        
    };

// Inline definitions
inline const SmsGetMoreMessageStatusIndArg& SmsGetMoreMessageStatusIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsGetMoreMessageStatusIndArg!\n");
    return ((SmsGetMoreMessageStatusIndArg &) arg);
}



/*  ======================================================================
    Class SmsConfigIndArg
    ====================================================================== */

class SmsConfigIndArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsConfigIndArg(UINT32 timer);
        SmsConfigIndArg();
        
        static const SmsConfigIndArg& Cast(const StackMsgArgument& arg);
        void SetTimer(UINT32 timer) { m_timer = timer; }
        UINT32 GetTimer() const { return m_timer; }
        
        enum  {
            ID = 2508
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsConfigIndArg*) arg); }
        
        UINT32 m_timer;
        
    };

// Inline definitions
inline const SmsConfigIndArg& SmsConfigIndArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsConfigIndArg!\n");
    return ((SmsConfigIndArg &) arg);
}



/*  ======================================================================
    Class SmsSendReqArg
    ====================================================================== */

class SmsSendReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsSendReqArg(const Tpdu& tpdu, const GsmService& service = InvalidGsmService);
        SmsSendReqArg();
        
        static const SmsSendReqArg& Cast(const StackMsgArgument& arg);
        void SetTpdu(const Tpdu& tpdu) { m_tpdu = tpdu; }
        const Tpdu& GetTpdu() const { return m_tpdu; }
        void SetService(const GsmService& service) { m_service = service; }
        const GsmService& GetService() const { return m_service; }
        
        enum  {
            ID = 2509
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsSendReqArg*) arg); }
        
        Tpdu m_tpdu;
        GsmService m_service;
        
    };

// Inline definitions
inline const SmsSendReqArg& SmsSendReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsSendReqArg!\n");
    return ((SmsSendReqArg &) arg);
}



/*  ======================================================================
    Class SmsSetMoreMessageReqArg
    ====================================================================== */

class SmsSetMoreMessageReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsSetMoreMessageReqArg(const SmsMoreMessageType& sms_more_message_type);
        SmsSetMoreMessageReqArg();
        
        static const SmsSetMoreMessageReqArg& Cast(const StackMsgArgument& arg);
        void SetSmsMoreMessageType(const SmsMoreMessageType& sms_more_message_type) { m_sms_more_message_type = sms_more_message_type; }
        const SmsMoreMessageType& GetSmsMoreMessageType() const { return m_sms_more_message_type; }
        
        enum  {
            ID = 2510
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsSetMoreMessageReqArg*) arg); }
        
        SmsMoreMessageType m_sms_more_message_type;
        
    };

// Inline definitions
inline const SmsSetMoreMessageReqArg& SmsSetMoreMessageReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsSetMoreMessageReqArg!\n");
    return ((SmsSetMoreMessageReqArg &) arg);
}



/*  ======================================================================
    Class SmsGetMoreMessageStatusReqArg
    ====================================================================== */

class SmsGetMoreMessageStatusReqArg : public StackMsgArgument {
    friend class CommonStackMsgArgsDestroyTableNode;
    public:
        SmsGetMoreMessageStatusReqArg();
        
        static const SmsGetMoreMessageStatusReqArg& Cast(const StackMsgArgument& arg);
        
        enum  {
            ID = 2511
            };
        
    private:
        
        static void Destroy(StackMsgArgument* arg) { delete ((SmsGetMoreMessageStatusReqArg*) arg); }
        
    };

// Inline definitions
inline const SmsGetMoreMessageStatusReqArg& SmsGetMoreMessageStatusReqArg::Cast(const StackMsgArgument& arg) {
    ASSERT_INFO((arg.Id() == ID), L"StackMsgArgument failed to cast to SmsGetMoreMessageStatusReqArg!\n");
    return ((SmsGetMoreMessageStatusReqArg &) arg);
}


#endif // Apc_SmsStackMsgArgs_hpp

