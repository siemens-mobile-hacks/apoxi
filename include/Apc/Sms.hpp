/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Sms_hpp)
#define Apc_Sms_hpp

#include <Auxiliary/PhoneNumber.hpp>

#include <Apc/CommandType.hpp>
#include <Apc/DataCodingScheme.hpp>
#include <Apc/MessageTypeIndicator.hpp>
#include <Apc/ParameterIndicator.hpp>
#include <Apc/ProtocolIdentifier.hpp>
#include <Apc/ShortMessageFailureCause.hpp>
#include <Apc/ShortMessageStatus.hpp>
#include <Apc/ValidityPeriod.hpp>

#include <Apc/SimDataTypes.hpp>
#include <Apc/Tpdu.hpp>
#include <Apc/UserData.hpp>
#include <Apc/MdhTypes.hpp>



/*  ========================================================================
    Sms - 3GPP TS 23.040 V5.1.0
    ======================================================================== */
class Sms {
    public:
        enum StorageType {
            Sim = MN_SIM_STORAGE,
            Flash = MN_FLASH_STORAGE_MODE,
            None = MN_STORAGE_NONE,
            SimPreferred,
            FlashPreferred,
            SharedMemory,
            Preferred
        };

        enum Result {
            UnassignedNumber            = MN_SMS_UNASSIGNED_NUMBER,
            OpDeterminedBarring         = MN_SMS_OP_DETERMINED_BARRING,
            CallBarred                  = MN_SMS_CALL_BARRED,
            CpNetworkFailure            = MN_SMS_CP_NETWORK_FAILURE,
            TransferRejected            = MN_SMS_TRANSFER_REJECTED,
            MemoryCapacityExceeded      = MN_SMS_MEMORY_CAPACITY_EXCEEDED,
            DestOutOfService            = MN_SMS_DEST_OUT_OF_SERVICE,
            UnidentifiedSubscriber      = MN_SMS_UNIDENTIFIED_SUBSCRIBER,
            FacilityRejected            = MN_SMS_FACILITY_REJECTED,
            UnknownSubscriber           = MN_SMS_UNKNOWN_SUBSCRIBER,
            NetworkOutOfOrder           = MN_SMS_NETWORK_OUT_OF_ORDER,
            TemporaryFailure            = MN_SMS_TEMPORARY_FAILURE,
            Congestion                  = MN_SMS_CONGESTION,
            ResourcesUnavailable        = MN_SMS_RESOURCES_UNAVAILABLE,
            FacilityNotSubscribed       = MN_SMS_FACILITY_NOT_SUBSCRIBED,
            ReqFaciltyNonImpl           = MN_SMS_REQ_FACILTY_NON_IMPL,
            InvalidReferenceValue       = MN_SMS_INVALID_REFERENCE_VALUE,
            SemantIncorrectMsg          = MN_SMS_SEMANT_INCORRECT_MSG,
            InvalidMandatoryInfo        = MN_SMS_INVALID_MANDATORY_INFO,
            MsgTypeNonExistent          = MN_SMS_MSG_TYPE_NON_EXISTENT,
            MsgNotCompatible            = MN_SMS_MSG_NOT_COMPATIBLE,
            IeNonExistent               = MN_SMS_IE_NON_EXISTENT,
            ProtocollError              = MN_SMS_PROTOCOLL_ERROR,
            Interworking                = MN_SMS_INTERWORKING,

            RpAck                       = MN_SMS_RP_ACK,
            TimerExpired                = MN_SMS_TIMER_EXPIRED,
            ForwAvailFailed             = MN_SMS_FORW_AVAIL_FAILED,
            ForwAvailAborted            = MN_SMS_FORW_AVAIL_ABORTED,

            TpInvalidMti                = MN_TP_INVALID_MTI,
            TpSrfNotInPhase1            = MN_TP_SRF_NOT_IN_PHASE1,
            TpRdfNotInPhase1            = MN_TP_RDF_NOT_IN_PHASE1,
            TpRpfNotInPhase1            = MN_TP_RPF_NOT_IN_PHASE1,
            TpUdhfNotInPhase1           = MN_TP_UDHF_NOT_IN_PHASE1,
            TpMissingValidityPeriod     = MN_TP_MISSING_VALIDITY_PERIOD,
            TpInvalidTimeStamp          = MN_TP_INVALID_TIME_STAMP,
            TpMissingDestAddress        = MN_TP_MISSING_DEST_ADDRESS,
            TpInvalidDestAddress        = MN_TP_INVALID_DEST_ADDRESS,
            TpMissingScAddress          = MN_TP_MISSING_SC_ADDRESS,
            TpInvalidScAddress          = MN_TP_INVALID_SC_ADDRESS,
            TpInvalidAlphabet           = MN_TP_INVALID_ALPHABET,
            TpInvalidUserDataLength     = MN_TP_INVALID_USER_DATA_LENGTH,
            TpMissingUserData           = MN_TP_MISSING_USER_DATA,
            TpUserDataTooLarge          = MN_TP_USER_DATA_TOO_LARGE,
            TpCmdReqNotInPhase1         = MN_TP_CMD_REQ_NOT_IN_PHASE1,
            TpInvalidDestAddrSpecCmds   = MN_TP_INVALID_DEST_ADDR_SPEC_CMDS,
            TpInvalidCmdDataLength      = MN_TP_INVALID_CMD_DATA_LENGTH,
            TpMissingCmdData            = MN_TP_MISSING_CMD_DATA,
            TpInvalidCmdData_Type       = MN_TP_INVALID_CMD_DATA_TYPE,
            TpCreationOfMnrFailed       = MN_TP_CREATION_OF_MNR_FAILED, 
            TpMtConnectionLost          = MN_TP_MT_CONNECTION_LOST,
            TpPendingMoSms              = MN_TP_PENDING_MO_SMS,

            NoError                     = MN_SMS_NO_ERROR,
            NoErrorNoIconDisplay        = MN_SMS_NO_ERROR_NO_ICON_DISPLAY,
            FdnFailed                   = MN_SMS_FDN_FAILED,
            BdnFailed                   = MN_SMS_BDN_FAILED,

            PpUnspecified               = SMS_PP_UNSPECIFIED,

            AssemblingError,

            TpduDataMissing,

            InvalidStoreLocation,

            UndefinedResult
        };

        enum WarningLevel { 
            CapacityExceed  = MdhRejMemoryExceeded,
            SimIsFull       = MdhRejSimIsFull,
            SimNotUsed      = MdhRejSimIsNotInView,
            NoSmsOnSim      = MdhRejSimNoSms, 
            WarningSimIsFull = MdhWarnSmStorageSimIsFull, 
            SimStorageGetsFree = MdhSmStorageSimIsFree, 
            MemoryFull  
        };
        Sms(Tpdu *tpdu);
        ~Sms();

        MessageTypeIndicator::Type GetType() const { return (m_sms_type); }
        PhoneNumber GetServiceCentreAddress() const;
        void SetServiceCentreAddress(const PhoneNumber &phone_number);
        UINT8* GetData() const { return (m_tp_data); }

    protected:
        enum {
            c_tpdu_size = 164, 
        };

        Tpdu *m_tpdu;
        UINT8 *m_tp_data;
        MessageTypeIndicator::Type m_sms_type;

        BOOLEAN GetBit(INT offset, UINT8 bit_no) const;
        void SetBit(INT offset, UINT8 bit_no, BOOLEAN flag);

        void Init();
};


/*  ========================================================================
    SmsDeliver - 3GPP TS 23.040 V5.1.0 [9.2.2.1]
    ======================================================================== */
class SmsDeliver : public Sms {
    public:
        typedef Sms Base;

        enum { ID = MessageTypeIndicator::Deliver };

        enum {
            c_max_guaranteed_user_data_size = 140
        };

        SmsDeliver(Tpdu *tpdu);
        ~SmsDeliver();

        BOOLEAN MoreMessagesToSend() const;

        BOOLEAN ReturnReport() const;

        BOOLEAN UserDataHeaderExists() const;

        BOOLEAN ReplyPathExists() const;
        void SetReplyPathExists(BOOLEAN flag = TRUE);

        PhoneNumber GetOriginatingAddress() const;

        ProtocolIdentifier GetProtocolIdentifier() const;
        void SetProtocolIdentifier(ProtocolIdentifier protocol_identifier);

        DataCodingScheme GetDataCodingScheme() const;

        CodedTimeStamp GetServiceCentreTimeStamp() const;

        UserData GetUserData() const;

        WString GetText() const;

        INT GetMaxUserDataSize() const;


        INT GetPayloadSize() const;
        INT GetPayloadOffset() const;
        UINT8* GetPayloadData() const;

    private:
        INT AddressOffset() const { return (1); }

        INT AfterAddressOffset() const;

        INT DataOffset() const;
        
};  // class SmsDeliver


/*  ========================================================================
    SmsSubmit - 3GPP TS 23.040 V5.1.0 [9.2.2.2]
    ======================================================================== */
class SmsSubmit : public Sms {
    friend class SmsFactory;
    public:
        typedef Sms Base;

        enum { ID = MessageTypeIndicator::Submit };

        enum {
            c_max_guaranteed_user_data_size = 140
        };

        SmsSubmit(Tpdu *tpdu);
        ~SmsSubmit();

        BOOLEAN RejectDuplicates() const;
        void SetRejectDuplicates(BOOLEAN flag = TRUE);

        ValidityPeriodFormat GetValidityPeriodFormat() const;
        void SetValidityPeriodFormat(const ValidityPeriodFormat &vpf);

        BOOLEAN RequestReport() const;
        void SetRequestReport(BOOLEAN flag = TRUE);

        BOOLEAN UserDataHeaderExists() const;
        void SetUserDataHeaderExists(BOOLEAN flag = TRUE);

        BOOLEAN RequestReplyPath() const;
        void SetRequestReplyPath(BOOLEAN flag = TRUE);

        SmsReferenceNumber GetMessageReference() const;
        void SetMessageReference(const SmsReferenceNumber &message_reference);

        PhoneNumber GetDestinationAddress() const;
        void SetDestinationAddress(const PhoneNumber &phone_number);

        ProtocolIdentifier GetProtocolIdentifier() const;
        void SetProtocolIdentifier(ProtocolIdentifier protocol_identifier);

        DataCodingScheme GetDataCodingScheme() const;
        void SetDataCodingScheme(const DataCodingScheme &dcs);

        ValidityPeriod GetValidityPeriod() const;
        void SetValidityPeriod(const ValidityPeriod &vp);

        UserData GetUserData() const;

        WString GetText() const;

        INT Trim();

        INT GetMaxUserDataSize() const;

    private:
        INT AddressOffset() const { return (2); }

        INT AfterAddressOffset() const;
        
        INT DataOffset() const;
};  // class SmsSubmit


/*  ========================================================================
    SmsStatusReport - 3GPP TS 23.040 V5.1.0 [9.2.2.3]
    ======================================================================== */
class SmsStatusReport : public Sms {
    public:
        typedef Sms Base;

        enum { ID = MessageTypeIndicator::StatusReport };

        enum {
            c_max_guaranteed_user_data_size = 131
        };

        SmsStatusReport(Tpdu *tpdu);
        ~SmsStatusReport();

        BOOLEAN MoreMessagesToSend() const;

        MessageTypeIndicator::Type GetInitialType() const;

        BOOLEAN UserDataHeaderExists() const;

        SmsReferenceNumber GetMessageReference() const;

        PhoneNumber GetRecipientAddress() const;

        CodedTimeStamp GetServiceCentreTimeStamp() const;

        CodedTimeStamp GetDischargeTime() const;

        ShortMessageStatus GetResultStatus() const;

        ParameterIndicator GetParameterIndicator() const;

        ProtocolIdentifier GetProtocolIdentifier() const;

        DataCodingScheme GetDataCodingScheme() const;

        UserData GetUserData() const;

        WString GetText() const;

        INT GetMaxUserDataSize() const;

    private:
        INT AddressOffset() const { return (2); }

        INT AfterAddressOffset() const;

        INT DataOffset() const;

};  // class SmsStatusReport


/*  ========================================================================
    SmsCommand - 3GPP TS 23.040 V5.1.0 [9.2.2.4]
    ======================================================================== */
class SmsCommand : public Sms {
    friend class SmsFactory;
    public:
        typedef Sms Base;

        enum { ID = MessageTypeIndicator::Command };

        enum {
            c_max_guaranteed_user_data_size = 146
        };

        SmsCommand(Tpdu *tpdu);
        ~SmsCommand();

        BOOLEAN RequestReport() const;
        void SetRequestReport(BOOLEAN flag = TRUE);

        BOOLEAN UserDataHeaderExists() const;
        void SetUserDataHeaderExists(BOOLEAN flag = TRUE);

        SmsReferenceNumber GetMessageReference() const;
        void SetMessageReference(const SmsReferenceNumber &message_reference);

        ProtocolIdentifier GetProtocolIdentifier() const;
        void SetProtocolIdentifier(ProtocolIdentifier protocol_identifier);

        CommandType GetCommandType() const;
        void SetCommandType(CommandType command_type);

        SmsReferenceNumber GetMessageNumber() const;
        void SetMessageNumber(SmsReferenceNumber message_number);

        PhoneNumber GetDestinationAddress() const;
        void SetDestinationAddress(const PhoneNumber &phone_number);

        UserData GetCommandData() const;

        INT Trim();

        INT GetMaxUserDataSize() const;

    private:
        INT AddressOffset() const { return (5); }

        INT AfterAddressOffset() const;

        INT DataOffset() const;

};  // class SmsCommand


#endif  // Apc_Sms_hpp

