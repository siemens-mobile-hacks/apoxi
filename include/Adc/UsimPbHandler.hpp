/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_UsimPbHandler_hpp)
#define Adc_UsimPbHandler_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/Vector.hpp>

#include <Apc/SignalTypes.hpp>
#include <Apc/UsimPbTypes.hpp>

#include <Adc/UsimPbAccessor.hpp>
#include <Adc/UsimPbEntryCont.hpp>
#include <Adc/UsimPbCommit.hpp>

/*//////////////////////////////////////////////////////////////////////////////
//
// UsimPbHandler
//

class UsimPbHandler 
{
    public:
        // maximum supported number of records in GAS and AAS
        enum {
            c_max_supported_gas_recs = 20,
            c_max_supported_aas_recs = 20,
        };
        
        // GAS WString buffer, no dyn array used because of overhead
        struct GasArray {
            WString m_wstr[c_max_supported_gas_recs];
        };
        // AAS WString buffer, no dyn array used because of overhead
        struct AasArray {
            WString m_wstr[c_max_supported_aas_recs];
        };

        // constructor & desctructor
        UsimPbHandler();
        virtual ~UsimPbHandler();

        // pointer initializing
        void Init(UsimPbAccessor * accessor);
        // is access to the USIM phoenbook allowed
        BOOLEAN IsUsimAccessAllowed() { 
            return UsimPbAccessor::IsUsimAccessAllowed(); 
        }

        // resets the data structure and clears all buffers including structure data of accessor
        void Reset();
        // clears the cached data
        void ClearCachedData();

        //
        UsimPbAccessor * GetUsimPbAccessor() { ASSERT_DEBUG(m_pb_accessor!=0); return m_pb_accessor; }
        //
        UsimPbEntryCont * GetUsimPbEntryCont() { ASSERT_DEBUG(m_container!=0); return m_container; }


    // GAS and AAS handling
        // returns the number of GAS or AAS records
        UINT GetXasCount(UsimPbAddType type) const;
        // returns the records size of GAS or AAS records
        UINT GetXasSize(UsimPbAddType type) const;
        // returns the filehandle
        INT GetXasHandle(UsimPbAddType type) const;

        // loads the GAS or AAS records into cache
        BOOLEAN RetrieveXas(UsimPbAddType type);
        // returns a GAS or AAS string to caller
        BOOLEAN GetXasRecord(UsimPbAddType type, UINT recno, WString & name) const;
        // updates GAS or AAS string on USIM and cache
        BOOLEAN UpdateXasRecord(UsimPbAddType type, UINT recno, const WString & name);

    // phonebook handling
        // selects the phonebook
        BOOLEAN SelectPhonebook(UsimPbLocation location);
        // initializes the phonebook
        BOOLEAN InitializePhonebook();
        // deselects the phonebook
        BOOLEAN DeselectPhonebook();

        // called from ASC to indicate that startup is now finished
        void StartupFinished(UsimPbResult result);
        // post the usim ready message (defined in ASC) 
        void PostUsimPbReadyMsg();

        // returns the maximúm number of ADN records
        INT GetMaxCount();
        // get the number of existing records
        INT GetExistingCount();
        // get the next free position
        INT GetNextFreePosition();
        // returns the tag size dependend of the record position
        INT GetTagSize(UINT simpos);
        // returns the alpha tag size dependned of the record poistion
        INT GetAlphaTagSize(UINT simpos);
        // loads all entries from the phonebook
        BOOLEAN LoadAllEntries(Provider * parentprov, ProviderListener * listener = 0);
        // refreshing
        BOOLEAN RefreshData(INT recno);
        void Refresh();
        // delete all entries
        BOOLEAN DeleteEntries(ProviderListener * listener = 0);
        // updates an entry
        BOOLEAN UpdateEntry(INT recno, const WString & name, const PhoneNumber & bcdnr, INT & newrow);
        // deletes an entry
        BOOLEAN DeleteEntry(INT recno);
        // get progress
        INT GetProgress() const { return m_progress; }
        // get one entry from the container, whereas recno is the position inside container
        UsimPbEntry * GetEntry(INT recno);
        // get the group value if available of a phonebook entry
        BOOLEAN GetGroup(UINT simpos, UINT idx, UINT8 & group);
        // set the hidden info value of a phonebook entry
        BOOLEAN UpdateHiddenInfo(UINT simpos, UINT8 hiddeninfo);
        // set the group values of a phonebook entry
        BOOLEAN UpdateGroups(UINT simpos, const UsimPbGroups & groups);
        // set the anr values of a phonebook entry
        BOOLEAN UpdateAnr(UINT simpos, const PhoneNumberCommitArray & anr, const Uint8CommitArray & aas);
        // set the sne or email values of a phonebook entry
        BOOLEAN UpdateRefType(UsimPbRefType type, UINT simpos, const WStringCommitArray & email);
        // push/refreshes an entry which comes from APC
        BOOLEAN PushUsimPbEntry(const UsimPbReadAsyncIndArg & arg);
        // refresh an data XAS entry which comes from APC
        BOOLEAN RefreshUsimPbDataEntry(const UsimPbReadDataAsyncIndArg & arg);
        // refresh reference datas which comes direct from APC
        BOOLEAN RefreshUsimPbRefEntry(const UsimPbReadRefAsyncIndArg & arg);

    private:
        UsimPbResult LoadContainerEntry(INT recno);
        UsimPbResult LoadContainerRefEntries(INT recno, const UsimPbRefRecord & refrecord);

        void ClearRwBuffer(INT length);

        // buffers of GAS and AAS strings
        GasArray m_gas_entries;
        AasArray m_aas_entries;
        // states if GAS and AAS have been updated
        BOOLEAN     m_gas_isupdated;
        BOOLEAN     m_aas_isupdated;

        INT                 m_progress;
        UsimPbEntryCont *   m_container;
        UsimPbAccessor *    m_pb_accessor;
        BOOLEAN             m_pbinfo_initialized;
        UINT8 *             m_rwbuffer;
        INT                 m_rwbuffer_maxlength;

        BOOLEAN             m_refentry_loading;
        UsimPbResult        m_startup_result;

};


#endif // APOXI_ENABLE_USIM_PHONEBOOK

#endif


