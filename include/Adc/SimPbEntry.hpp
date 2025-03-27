/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimPbEntry_hpp)
#define Adc_SimPbEntry_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>

class SimPbEntry
{
    public:
        SimPbEntry();
        SimPbEntry(const SimPbEntry & entry);

        ~SimPbEntry(); // destructor not virtual !!!

        INT                 GetRecNo() const { return m_recno; }
        const WString &     GetName() const { return m_name; }
        const PhoneNumber & GetPhoneNumber() const { return m_phonenumber; }
        UINT8               GetCphsStatus() const { return m_cphsstatus; }
        UINT8               GetCmiRecordNo() const { return m_cmi_no; }

        BOOLEAN             HasData() const;
        INT                 GetCphsIndexLevelIndicator() const { return (INT)(m_cphsstatus & 0x0F); }
        BOOLEAN             HasCphsPremiumServiceIndicator() const { return (INT)(m_cphsstatus & 0x10) > 0; }
        BOOLEAN             HasCphsNetworkSpecificIndicator() const { return (INT)(m_cphsstatus & 0x20) > 0; }

        void SetData(INT recno, const PhoneNumber & phno, const WString & name, UINT8 cphsstatus, UINT8 cmi_no);
        void ClearData();
        void ResetData();

        SimPbEntry & operator = (const SimPbEntry & szCopy);

    private:
        INT         m_recno;
        WString     m_name;
        PhoneNumber m_phonenumber;
        UINT8       m_cphsstatus;   // only used for CPHS_INFNUM entries
        UINT8       m_cmi_no;       // only used for BDN entries        
};

const SimPbEntry * const c_unread_entry = (SimPbEntry *)-1;


#endif


