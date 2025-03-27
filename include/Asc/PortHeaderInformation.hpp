/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_PortHeaderInformation_hpp)
#define Asc_PortHeaderInformation_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Linkable.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Apc/InformationElement.hpp>

class Tpdu;
/*  ========================================================================
    PortHeaderInformation
    ======================================================================== */
class PortHeaderInformation : public Linkable <PortHeaderInformation>
{
    public:
        PortHeaderInformation(Tpdu *tpdu = 0);
        virtual ~PortHeaderInformation();

        const PhoneNumber&  GetPhoneNumber() const { return m_phnr; }
        UINT16 GetConcRefNo() const { return m_conc_ref_no; }
        UINT8 GetConcMaxNo() const { return m_conc_max_no; }
        UINT8 GetConcSeqNo() const { return m_conc_seq_no; }
        SmsPortNo GetSmsOriginatorPortNo() const { return m_sms_orig_port_no; }
        SmsPortNo GetSmsDestinationPortNo() const { return m_sms_dest_port_no; }
        UINT8 GetPayloadSize() const { return m_payload_size; }
        UINT8* GetPayloadData() const { return m_payload_data; }

        BOOLEAN HasSmsPortNo() const { return m_sms_dest_port_no != InvalidSmsPortNo; }
        BOOLEAN IsConcateneted() const { return m_is_concateneted; }

    private:
        UINT8 m_conc_max_no;
        UINT8 m_conc_seq_no;
        UINT8 m_payload_size;
        UINT8 m_payload_offset;
        UINT16 m_conc_ref_no;
        BOOLEAN m_is_concateneted;
        SmsPortNo m_sms_dest_port_no;
        SmsPortNo m_sms_orig_port_no;
        UINT8 *m_payload_data;
        Tpdu *m_tpdu;
        PhoneNumber m_phnr;

};

#endif  // Asc_PortHeaderInformation_hpp


