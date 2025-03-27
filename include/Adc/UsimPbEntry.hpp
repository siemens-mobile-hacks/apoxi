/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_UsimPbEntry_hpp)
#define Adc_UsimPbEntry_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>

/*  ------------------------------------------------------------------------
    UsimPbEntry
    ------------------------------------------------------------------------ */
// class which caches one ADN entry, WString, Phonenumber, Simpos

class UsimPbEntry
{
    public:
        UsimPbEntry();
        UsimPbEntry(const UsimPbEntry & entry);

        ~UsimPbEntry(); // destructor not virtual !!!

        // the position on the SIM, by meaning the number used for the stack but starting with 0
        UINT16              GetRecNo() const { return m_recno; }
        // the alpha identifier as a WSstring
        const WString &     GetName() const { return m_name; }
        // the phonenumber of the ADN record
        const PhoneNumber & GetPhoneNumber() const { return m_phonenumber; }
        // checks if entry either contains a phonenumber and/or a wstring
        BOOLEAN             HasData() const;
        // fill the data entry
        void SetData(UINT16 recno, const PhoneNumber & phno, const WString & name);
        // clear the phonenumber and wstring but recno is still remaining
        void ClearData();
        // clears all member
        void ResetData();

        UsimPbEntry & operator = (const UsimPbEntry & entry);

    private:
        WString     m_name;
        PhoneNumber m_phonenumber;
        UINT16      m_recno;
};

// defines an unused sim entry pointer
const UsimPbEntry * const c_unread_usim_entry = (UsimPbEntry *)-1;
// defines an invalid record number
const UINT16 c_invalid_usim_rec_number = ~0;



#endif //#if defined(APOXI_ENABLE_USIM_PHONEBOOK)

#endif


