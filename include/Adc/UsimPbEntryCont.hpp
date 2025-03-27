/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_UsimPbEntryCont_hpp)
#define Adc_UsimPbEntryCont_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/FixedPtrArray.hpp>
#include <Auxiliary/IndexTable.hpp>
#include <Auxiliary/DynamicBitVector.hpp>

#include <Adc/UsimPbEntry.hpp>
#include <Adc/UsimPbAddData.hpp>

/*  ------------------------------------------------------------------------
    UsimPbEntryCont
    ------------------------------------------------------------------------ */
// container class which caches all necessary phonebook data, like
// ADN, UID, SNE, EMAIL, ANR, GRP in form of other data structures 

const INT c_invalid_usim_position = -2;

class UsimPbEntryCont
{
    private:
        enum {
            BITS_PER_UINT = sizeof(UINT) * 8,
        };

    public:
        UsimPbEntryCont(UINT nr_entries, 
                         UINT groupsperentry, 
                         BOOLEAN hiddeninfo,
                         BOOLEAN syncsupported, 
                         UINT anrperentry,
                         UINT sneperentry,
                         UINT emailperentry,
                         BOOLEAN sorted = FALSE);
        ~UsimPbEntryCont();

        void SetReady(BOOLEAN ready = TRUE) { m_ready = ready; }
        BOOLEAN IsReady() const { return m_ready; }

        UINT GetMaxEntries() const { return m_max_entries; }

        void Reset() { DeleteAllData(); }

        INT  PutData(UINT recno, const PhoneNumber & phno, const WString & wstr);
        BOOLEAN PutAdditionalData(UINT recno, const UsimPbRwRecord & record);

        // delete methods
        void DeleteData(UINT recno);
        void DeleteAllData();
        void DeleteAllObjects();

        void DeleteAdditionalData(UINT recno);

        UsimPbEntry * GetEntry(UINT idx) const;

        // Hiddeninfo
        BOOLEAN HasHiddenInfo() const { return m_hidden_info!=0; }
        UINT8 GetHiddenInfo(UINT idx) const;
        BOOLEAN SetHiddenInfo(UINT idx, UINT8 hiddeninfo);

        // Uid
        BOOLEAN HasUid() const { return m_sync_info!=0; }
        UINT16 GetUid(UINT idx) const;
        BOOLEAN SetUid(UINT idx, UINT16 uid);

        // Group
        BOOLEAN HasGroups() const { return m_grouping_info!=0; }
        UINT8 GetGroup(UINT idx, UINT grpidx) const;
        BOOLEAN SetGroup(UINT idx, UINT grpidx, UINT8 grp);
        BOOLEAN SetGroupVector(UINT idx, UINT grplength, const UINT8 * grpvector);
        const UINT8 * GetGroupVector(UINT idx);


        // ANR
        BOOLEAN HasAnr() const { return m_anr_entries.IsReady(); }
        const PhoneNumber & GetAnrPhoneNumber(UINT idx, UINT anrdx) const;
        UINT8 GetAnrAasRecordId(UINT idx, UINT anrdx) const;
        UINT8 GetAnrRecno(UINT idx, UINT anridx) const;
        BOOLEAN SetAnr(UINT idx, UINT anrdx, const PhoneNumber & phno, UINT8 aasrecid);
        BOOLEAN SetAnrPhoneNumber(UINT idx, UINT anrdx, const PhoneNumber & phno);
        BOOLEAN SetAnrAasRecordId(UINT idx, UINT anrdx, UINT8 aasrecid);
        BOOLEAN SetAnrRecno(UINT idx, UINT anridx, UINT8 recno);

        // SNE
        BOOLEAN HasSne() const { return m_sne_entries.IsReady(); }
        const WString & GetSne(UINT idx, UINT sneidx) const;
        BOOLEAN SetSne(UINT idx, UINT sneidx, const WString & wstr, UINT8 recno);
        UINT8 GetSneRecno(UINT idx, UINT sneidx) const;

        // EMAIL
        BOOLEAN HasEmail() const { return m_email_entries.IsReady(); }
        const WString & GetEmail(UINT idx, UINT emailidx) const;
        BOOLEAN SetEmail(UINT idx, UINT emailidx, const WString & wstr, UINT8 recno);
        UINT8 GetEmailRecno(UINT idx, UINT emailidx) const;

        INT   GetFirstFreeSimPosition();
        INT   GetExistingCount() { return m_effcount; }

        void DbgOut(UINT idx) const;

    private:
        FixedPtrArray<UsimPbEntry> m_entries;
        DynamicBitVector *         m_used_entries;
        UINT8 *                    m_grouping_info;
        UINT8 *                    m_hidden_info;
        UINT16 *                   m_sync_info;
        UINT8 *                    m_aasrecid_info;
        UsimPbAddData              m_anr_entries;
        UsimPbAddData              m_sne_entries;
        UsimPbAddData              m_email_entries;
        UINT                       m_max_entries;
        UINT                       m_effcount;

        BOOLEAN                    m_sorted;
        BOOLEAN                    m_ready;
        UINT8                      m_groupsperentry;
        UINT8                      m_anrperentry;
        UINT8                      m_sneperentry;
        UINT8                      m_emailperentry;
        
        void InsertData(UINT recno, INT simpos, const PhoneNumber & phno, const WString & wstr);
        INT  FindInsertPosition(const WString & wstr);

};


#endif //#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#endif


