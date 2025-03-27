/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_CompoundSmsItem_hpp)
#define Adc_CompoundSmsItem_hpp

#include <Apc/UserData.hpp>
#include <Apc/BaseInformationElement.hpp>
#include <Auxiliary/GenericObject.hpp>

#include <Adc/SimPduHandler.hpp>

//
// CompoundSmsItem
//

const GenericTypeId c_compound_sms_item_type  = c_apoxi_base_gentypes + 2;

class CompoundSmsItem : public GenericObject
{
    typedef GenericObject Base;

    public:
        CompoundSmsItem(SimPduHandler * handler, SmsFilterType filter_type, INT recno);

        virtual ~CompoundSmsItem();
        BOOLEAN StartIteration();
        BOOLEAN GetBaseInformationElement(BaseInformationElement & ie);

        virtual GenericObject * Copy() const;
        virtual BOOLEAN         IsEqual(GenericObject * object);
        virtual GenericTypeId   GetTypeId();

    private:
        BOOLEAN LoadFirstTpdu(BOOLEAN & isexisting);
        BOOLEAN LoadNextTpdu(BOOLEAN & isexisting);

        void InitializeUserDataHeader();

        SimPduHandler *         m_pdu_handler;
        SmsFilterType           m_filter_type;
        INT                     m_recno;

        TpduHeaderInformation * m_header_info;
        Tpdu *                  m_actual_pdu;
        INT                     m_tpduno;
        INT                     m_actual_seq_nr;
        INT                     m_max_count;
        UserDataHeader          m_udh;

        BOOLEAN                 m_at_pdu_start;
        BOOLEAN                 m_start_ie_parsing;
        BOOLEAN                 m_missing_pdu;
        BOOLEAN                 m_end_of_stream;
};

//
// CompoundTpduItem
//

const GenericTypeId c_compound_tpdu_item_type  = c_apoxi_base_gentypes + 3;

class CompoundTpduItem : public GenericObject
{
    typedef GenericObject Base;

    public:
        CompoundTpduItem(SimPduHandler * handler, SmsFilterType filter_type, INT recno);

        virtual ~CompoundTpduItem();

        virtual GenericObject * Copy() const;
        virtual BOOLEAN         IsEqual(GenericObject * object);
        virtual GenericTypeId   GetTypeId();

        BOOLEAN LoadFirstTpdu();
        BOOLEAN LoadNextTpdu();
        BOOLEAN GetTpdu(Tpdu & tpdu, INT & tpduno);
        BOOLEAN WriteTpdu(const Tpdu & tpdu, INT tpduno);

    private:
        BOOLEAN LoadFirstTpdu(BOOLEAN & isexisting);
        BOOLEAN LoadNextTpdu(BOOLEAN & isexisting);

        SimPduHandler *         m_pdu_handler;
        SmsFilterType           m_filter_type;
        INT                     m_recno;

        TpduHeaderInformation * m_header_info;
        Tpdu *                  m_actual_pdu;
        INT                     m_tpduno;
        INT                     m_actual_seq_nr;
        INT                     m_max_count;
        BOOLEAN                 m_missing_pdu;

};

#endif

