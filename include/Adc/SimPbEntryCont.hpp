/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimPbEntryCont_hpp)
#define Adc_SimPbEntryCont_hpp

#include <Auxiliary/FixedPtrArray.hpp>
#include <Auxiliary/IndexTable.hpp>
#include <Auxiliary/DynamicBitVector.hpp>

#include <Adc/SimPbEntry.hpp>


const INT c_invalid_position = -2;

class SimPbEntryCont
{
    private:
        enum {
            BITS_PER_UINT = sizeof(UINT) * 8,
        };

    public:
        SimPbEntryCont(INT nr_entries, BOOLEAN sorted = FALSE);
        ~SimPbEntryCont();

        void SetReady(BOOLEAN ready = TRUE) { m_ready = ready; }
        BOOLEAN IsReady() const { return m_ready; }

        INT GetMaxEntries() const { return m_max_entries; }
        INT GetTextLength() const { return m_text_length; }
        void SetTextLength(INT length) { m_text_length = length; }

        void Reset() { DeleteAllData(); }

        INT  PutData(INT recno, const PhoneNumber & phno, const WString & wstr, 
                     UINT8 cphsstatus, UINT8 cmi_no);
        void DeleteData(INT recno);
        void DeleteAllData();
        void DeleteAllObjects();

        SimPbEntry * GetEntry(INT idx) const;

        INT          GetFirstFreeSimPosition();
        INT          GetExistingCount() { return m_effcount; }

    private:
        BOOLEAN                    m_sorted;
        BOOLEAN                    m_ready;
        FixedPtrArray<SimPbEntry>  m_entries;
        INT                        m_max_entries;
        INT                        m_text_length;
        INT                        m_effcount;
        DynamicBitVector *         m_used_entries;


        void InsertData(INT recno, INT simpos, const PhoneNumber & phno, const WString & wstr, 
                        UINT8 cphsstatus, UINT8 cmi_no);
        INT  FindInsertPosition(const WString & wstr);

};

#endif


