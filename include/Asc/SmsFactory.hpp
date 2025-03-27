/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsFactory_hpp)
#define Asc_SmsFactory_hpp

#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/TimeSpan.hpp>

#include <Apc/BaseInformationElement.hpp>
#include <Apc/Sms.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Asc/SmsContext.hpp>
#include <Adc/SimPduHandler.hpp>

/*  ========================================================================
    SmsFactory - 
    ======================================================================== */
class SmsFactory {
    public:

        SmsFactory();
        ~SmsFactory();

        BOOLEAN Init(const SmsContext &context);
        void Reset(BOOLEAN reallocate = TRUE);


        BOOLEAN Append(const BaseInformationElement &data_ptr);
        BOOLEAN Append(const WString &text);
        BOOLEAN Append(const UINT8 *data_ptr, INT len);
        BOOLEAN Append(const BlobObject &blob);

        Sms::Result Assemble();

        Sms::Result Store(const Sms::StorageType storage_type);

        Sms::Result Store();

#if !defined(DOWNSTRIP_TO_GSM)
        Sms::Result Send(BOOLEAN wait_for_response = TRUE, GsmService service = CircuitSwitched);
#else
        Sms::Result Send(BOOLEAN wait_for_response = TRUE);
#endif

        INT SetSendingResult(Sms::Result last_sending_result, Sms::Result &subsequent_sending_result, SmsReferenceNumber reference_number = 0xFF);

        INT GetNoOfTpdus() const;

        const Tpdu& GetTpdu(INT i = 0) const;


        // -------------------------------------------------------------------------------
        // ATTENTION: the remove of the following obsolete methods is planned in APOXI_2.1
        // -------------------------------------------------------------------------------
        INT SetSendingResult(Sms::Result result, const SmsReferenceNumber &reference_number = 0xFF);

        // -------------------------------------------------------------------------------
        // ATTENTION: the remove of the following obsolete methods is planned in APOXI_1.4
        // -------------------------------------------------------------------------------
        SmsFactory(const PhoneNumber &service_centre_address, INT sms_profile_id);
        void Init(const PhoneNumber &service_centre_address = PhoneNumber(), INT sms_profile_id = 0);
        BOOLEAN InitSmsCommand(SmsReferenceNumber message_number,
                               const PhoneNumber &destination_address = PhoneNumber(),
                               const CommandType &command_type = CommandType(),
                               const ProtocolIdentifier &protocol_identifier = ProtocolIdentifier(),
                               BOOLEAN request_status_report = TRUE);
        BOOLEAN InitSmsSubmit(const PhoneNumber &destination_address = PhoneNumber(),
                              const ValidityPeriod &validity_period = ValidityPeriod(),
                              const ProtocolIdentifier &protocol_identifier = ProtocolIdentifier(),
                              BOOLEAN request_reply_path = TRUE, 
                              BOOLEAN request_status_report = TRUE,
                              BOOLEAN reject_duplicates = TRUE,
                              const DataCodingScheme &data_coding_scheme = DataCodingScheme());



    private:
        // defines, how the user-data is filled up (using Append method)
        enum AppendMode {
            BaseInformationElementOnly,     // user-data filled up by using BaseInformation elements only
            TextOnly,                       // text mode for writing user-data (SmsSubmit)
            DirectDataAccessOnly,           // direct user-data access (SmsCommand only)
            Undefined
        };

        SmsContext m_context;

        Tpdu m_active_tpdu;                 // used as base tpdu, holds whole shared header data.
        ElementList<Tpdu> m_tpdu_list;
        AppendMode m_append_mode;

        WString m_text; // data storage for text-payload
        BlobObject m_data;  // data storage for binary payload

        UINT16 m_conc_ref_no;
        BOOLEAN m_valid_conc_ref_no;

        BOOLEAN m_is_assembled;
        BOOLEAN m_is_sending;
        INT m_no_of_tpdus_to_send;
        Tpdu *m_pending_tpdu;   // points to the actual (sent) tpdu in non-blocking sending mode

        GsmService m_service;

        // Resets the UserData of the active tpdu m_active_tpdu
        void ResetActiveTpduData();

        // retrieve new concatenation reference number
        UINT16 RequestNewConcatenationReferenceNumber();

        // trims the active tpdu (m_active_tpdu)
        INT TrimActiveTpdu();
        
        // -------------------------------------------------------------------------------
        // ATTENTION: the remove of the following obsolete methods is planned in APOXI_1.4
        // -------------------------------------------------------------------------------
        INT m_sms_profile_id;                   // the remove of this member is planned in APOXI_1.4
        PhoneNumber m_service_center_address;
};

#endif  // Asc_SmsFactory_hpp


