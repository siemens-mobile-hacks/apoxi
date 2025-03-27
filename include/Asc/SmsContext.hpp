/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsContext_hpp)
#define Asc_SmsContext_hpp

#include <Kernel/Types.hpp>

#include <Auxiliary/PhoneNumber.hpp>
#include <Apc/ProtocolIdentifier.hpp>
#include <Apc/DataCodingScheme.hpp>
#include <Apc/ValidityPeriod.hpp>
#include <Apc/InformationElement.hpp>
#include <Apc/MessageTypeIndicator.hpp>
#include <Apc/SimDataTypes.hpp>
#include <Apc/CommandType.hpp>

/*  ========================================================================
    SmsContext - 
    ======================================================================== */
class SmsContext {
    public:
        SmsContext(MessageTypeIndicator::Type mt = MessageTypeIndicator::InvalidType);
        ~SmsContext();

        void Clear();

        BOOLEAN ReadSmsProfile(INT profile_number = 0);

        BOOLEAN IsValid() const;
        
        void SetSubmitParameter(const PhoneNumber &service_center_address,
                                const PhoneNumber &destination_address,              
                                const ProtocolIdentifier &protocol_identifier,
                                const DataCodingScheme &data_coding_scheme,
                                const ValidityPeriod &valitity_period,
                                BOOLEAN status_report_request,
                                BOOLEAN reply_path,
                                BOOLEAN reject_duplicates);
        
        void SetCommandParameter(const PhoneNumber &service_center_address, 
                                 const PhoneNumber &destination_address, 
                                 const ProtocolIdentifier &protocol_identifier, 
                                 SmsReferenceNumber message_number, 
                                 const CommandType &command_type, 
                                 BOOLEAN status_report_request);

        void SetMessageType(MessageTypeIndicator::Type mt) { m_mt = mt; }

        void SetServiceCenterAddress(const PhoneNumber &sca);
        void SetDestinationAddress(const PhoneNumber &da);
        void SetProtocolIdentifier(const ProtocolIdentifier &pid) { m_pid = pid; }
        void SetRequestStatusReport(BOOLEAN srr)  { m_srr = srr; }
        void SetSmsReferenceNumber(SmsReferenceNumber mr)  { m_mr = mr; }

        void SetDataCodingScheme(const DataCodingScheme &dcs) { m_dcs = dcs; }
        void SetValidityPeriod(const ValidityPeriod &vp)  { m_vp = vp; }
        void SetRequestReplyPath(BOOLEAN rp)  { m_rp = rp; }
        void SetRejectDuplicates(BOOLEAN rd)  { m_rd = rd; }
        
        void SetCommandType(const CommandType &ct)  { m_ct = ct; }
        void SetMessageNumber(SmsReferenceNumber mn)  { m_mn = mn; }

        void SetConcatenatedReferenceNoType(InformationElement::Identifier conc_refno_type);
        void SetDestinationApplicationPortAddress(SmsPortNo destination_port_no) { m_destination_port_no = destination_port_no; }
        void SetOriginatorApplicationPortAddress(SmsPortNo originator_port_no) { m_originator_port_no = originator_port_no; }

        void SetSingleSrrPerSmsEnabled(BOOLEAN single_srr) { m_single_srr = single_srr; }

        MessageTypeIndicator::Type GetMessageType() const { return m_mt; }

        const PhoneNumber& GetServiceCenterAddress() const { return m_sca; }
        const PhoneNumber& GetDestinationAddress() const { return m_da; }
        ProtocolIdentifier GetProtocolIdentifier() const { return m_pid; }
        BOOLEAN GetRequestStatusReport() const { return m_srr; }
        SmsReferenceNumber GetSmsReferenceNumber() const { return m_mr; }

        DataCodingScheme GetDataCodingScheme() const { return m_dcs; }
        const ValidityPeriod& GetValidityPeriod() const { return m_vp; }
        BOOLEAN GetRequestReplyPath() const { return m_rp; }
        BOOLEAN GetRejectDuplicates() const { return m_rd; }
        BOOLEAN IsSingleSrrPerSmsEnabled() const { return m_single_srr; }

        CommandType GetCommandType() const { return m_ct; }
        SmsReferenceNumber GetMessageNumber() const { return m_mn; }

        InformationElement::Identifier GetConcatenatedReferenceNoType() const;
        SmsPortNo GetDestinationApplicationPortAddress() const { return (m_destination_port_no); }
        SmsPortNo GetOriginatorApplicationPortAddress() const { return (m_originator_port_no); }
        
        BOOLEAN ShallRequestStatusReport() const { DBG_OUT((0, L"\nObsolete: SmsContext::ShallRequestStatusReport(): Use SmsContext::GetRequestStatusReport() instead!!!\n")); return GetRequestStatusReport(); }
        BOOLEAN ShallRequestReplyPath() const { DBG_OUT((0, L"\nObsolete: SmsContext::ShallRequestReplyPath(): Use SmsContext::GetRequestReplyPath() instead!!!\n")); return GetRequestReplyPath(); }
        BOOLEAN ShallRejectDuplicates() const { DBG_OUT((0, L"\nObsolete: SmsContext::ShallRejectDuplicates(): Use SmsContext::GetRejectDuplicates() instead!!!\n")); return GetRejectDuplicates(); }

    private:
        // common
        MessageTypeIndicator::Type m_mt; // TP-MTI: TP-Message-Type-Indicator - 3GPP 23.040 V5.1.0 [9.2.3.1]
        PhoneNumber  m_sca;              // service center address
        PhoneNumber  m_da;               // TP-DA: TP-Destination-Address (3GPP 23.040 V5.1.0 [9.2.3.8])
        ProtocolIdentifier m_pid;        // TP-PID: TP-Protocol-Identifier (3GPP 23.040 V5.1.0 [9.2.3.9])
        BOOLEAN m_srr;                   // TP-SRR: TP-Status-Report-Request (3GPP 23.040 V5.1.0 [9.2.3.5])

        SmsReferenceNumber m_mr;         // TP-MR: TP-Message-Reference (3GPP 23.040 V5.1.0 [9.2.3.6])

        // SMS submit type only
        DataCodingScheme m_dcs;          // TP-DCS: TP-Data-Coding-Scheme (3GPP 23.040 V5.1.0 [9.2.3.10])
        ValidityPeriod m_vp;             // TP-VP: TP-Validity-Period (3GPP 23.040 V5.1.0 [9.2.3.12])
        BOOLEAN  m_rp;                   // TP-RP: TP-Reply-Path (3GPP 23.040 V5.1.0 [9.2.3.17])
        BOOLEAN m_rd;                    // TP-RD: TP-Reject-Duplicates (3GPP 23.040 V5.1.0 [9.2.3.25])
        BOOLEAN m_single_srr;

        // SMS command type only
        CommandType m_ct;                // TP-CT: TP-Command-Type (3GPP 23.040 V5.1.0 [9.2.3.19])
        SmsReferenceNumber m_mn;         // TP-MN: TP-Message-Number (3GPP 23.040 V5.1.0 [9.2.3.18])

        // UDH specific settings
        InformationElement::Identifier  m_conc_refno_type; // part of TP-UDH - type of concatenated reference number (8bit or 16bit)
        SmsPortNo m_destination_port_no; // part of TP-UDH - define application port ID     
        SmsPortNo m_originator_port_no;  // part of TP-UDH - define application port ID     
};

#endif  // Asc_SmsContext_hpp


