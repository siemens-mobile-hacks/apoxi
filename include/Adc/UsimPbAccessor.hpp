/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Adc_UsimPbAcessor_hpp)
#define Adc_UsimPbAcessor_hpp

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)


#include <Kernel/Types.hpp>
#include <Kernel/UserDispatcher.hpp>
#include <Kernel/MessageReferrer.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Apc/SignalTypes.hpp>
#include <Apc/UsimPbTypes.hpp>
#include <Adc/SimAccessor.hpp>

//
//
//  USIM PB Simulation
//
//

#if defined(APOXI_USIM_PB_SIMULATION)
    // maximum record size
    const INT c_max_record_size =   254;
    // ADN description
    const INT c_no_adn_files    =   2;
    const INT c_no_adn1_recs    =   200;
    const INT c_no_adn2_recs    =   150;

    const INT c_no_adn_all      =   c_no_adn1_recs+c_no_adn2_recs;

    const INT c_no_adn1_rec_size=   36;
    const INT c_no_adn2_rec_size=   34;
    // GAS description
    const INT c_no_gas_recs =   10;
    const INT c_no_gas_rec_size =   20;
    // AAS description
    const INT c_no_aas_recs =   6;
    const INT c_no_aas_rec_size =   20;
    // ANR description
    const INT c_no_anr_per_rec  =   3;
    const INT c_no_anr_rec_size =   15;
    // GRP description
    const INT c_no_grp_rec_size =   6;
    // SNE description
    const INT c_no_sne_per_rec  =   2;
    const INT c_no_sne_rec_size =   100;
    // EMAIL description
    const INT c_no_email_per_rec=   2;
    const INT c_no_email_rec_size=  100;

    struct AdnRecord {
        UINT8 m_data[c_max_record_size];
    };
    struct GasRecord {
        UINT8 m_data[c_no_gas_rec_size];
    };
    struct AasRecord {
        UINT8 m_data[c_no_aas_rec_size];
    };
    struct GrpRecord {
        UINT8 m_data[c_no_grp_rec_size];
    };
    struct AnrRecord {
        UINT8 m_data[c_no_anr_rec_size];
    };
    struct SneRecord {
        UINT8 m_data[c_no_sne_rec_size];
    };
    struct EmailRecord {
        UINT8 m_data[c_no_email_rec_size];
    };

    struct SimulAdn {
        AdnRecord   m_rec[c_no_adn_all];
        GrpRecord   m_grp[c_no_adn_all];
        AnrRecord   m_anr[c_no_adn_all][c_no_anr_per_rec];
        SneRecord   m_sne[c_no_adn_all][c_no_sne_per_rec];
        EmailRecord m_email[c_no_adn_all][c_no_email_per_rec];
        UINT16      m_uid[c_no_adn_all];
        UINT8       m_hiddenkey[c_no_adn_all];
    };
    struct SimulGas {
        GasRecord m_rec[c_no_gas_recs];
    };
    struct SimulAas {
        AasRecord m_rec[c_no_aas_recs];
    };
#endif

//
//
//  UsimPbAccessor
//
//

class UsimPbAccessor 
{
    public:

        UsimPbAccessor();
        virtual ~UsimPbAccessor();

        void Init(SimAccessor * sim_accessor);
        void Reset();

        static BOOLEAN IsUsimAccessAllowed() { 
#if defined(APOXI_USIM_PB_SIMULATION)
            return SimAccessor::IsSimAccessAllowed(); 
#else
            return SimAccessor::IsSimAccessAllowed() && SimAccessor::IsUsimInserted(); 
#endif
        }

        BOOLEAN IsUsimPbSelected() const { return m_selected_location!=UsimPbNotSelected; }

        UsimPbLocation GetSelectedUsimPb() const { return m_selected_location; }

        // this is directly called from APC to set the data necessary in time
        void SetUsimPbSelection(UsimPbLocation location, const T_PB_DESCRIPTOR & desc) { 
            m_selected_location = location; 
            m_desc = desc;
        }


        // get information about the phonebooks
        UsimPbResult GetLocation(UsimPbLocReport & report);
        // select a phonebook and retrieve information
        UsimPbResult SelectLocation(UsimPbLocation location, BOOLEAN cachefilling);
        // read a phonebook record
        UsimPbResult ReadPbRecord(INT recno, 
                                  UsimPbRwRecord & record, 
                                  UsimPbRefRecord & refrecord); 
        // update a phonebook record
        UsimPbResult UpdatePbRecord(INT recno, 
                                    INT startrecno,
                                    const UsimPbChangedField & changes, 
                                    const UsimPbRwRecord & record,
                                    UINT16 & uid); 
        // read linked data of a phonebook record
        UsimPbResult ReadRefData(UsimPbRefType reftype,
                                 INT recno, 
                                 INT ref_recno,
                                 INT handle,
                                 T_DATA & data); 
        // update linked data of a phonebook record
        UsimPbResult UpdateRefData(UsimPbRefType reftype,
                                   INT recno, 
                                   INT & ref_recno,
                                   INT handle,
                                   const T_DATA & data); 
        // read additional data type 3 files
        UsimPbResult ReadAddData(UsimPbAddType type,
                                 INT handle,
                                 INT recno, 
                                 T_DATA & data);
        // update additional data type 3 files
        UsimPbResult UpdateAddData(UsimPbAddType type, 
                                   INT handle,
                                   INT recno, 
                                   T_DATA & data); 
        // get the fill status
        UsimPbResult UpdateFillStatus();
        // stops the usim phonebook 
        UsimPbResult UsimPbStop();

        // indicates a change
        void IndicateChange() { m_change_indication = TRUE; }



        static BOOLEAN HasParamAttribute(StackMsgArgId id);
        static BOOLEAN HasParam(StackMsgArgument * arg, UINT32 param);


        // returns the number of ADN files within the phonebook, an ADN file together
        // with other files of phonebook we call a "slice"
        UINT GetSliceCount() const;
        // returns the number of ADN records of all ADN files 
        UINT GetTotalRecordCount() const;
        // returns the slice number which the recno belongs to 
        UINT GetSliceNo(UINT recno) const;

        // return the record size of the ADN of a slice
        UINT GetAdnRecordSize(UINT slice) const;
        // return the maximum record size of all ADNs
        UINT GetMaxAdnRecordSize() const;
        // return the alpha identifier size of the ADN of a slice
        UINT GetAdnAlphaIdSize(UINT slice) const;
        // return the record count of the ADN of a slice
        UINT GetAdnRecordCount(UINT slice) const;
        // return the used record count of the ADN of a slice
        UINT GetAdnUsedRecordCount(UINT slice) const;
        // return the free record count of the ADN of a slice
        UINT GetAdnFreeRecordCount(UINT slice) const;
        // get the number of possible EXT records
        UINT GetExtRecordCount(UINT slice) const;
        // get the number of used EXT records
        UINT GetExtUsedRecordCount(UINT slice) const;
        // get the number of free EXT records
        UINT GetExtFreeRecordCount(UINT slice) const;

        // return the maximum number of groups per ADN record for all slices
        UINT GetMaxGroupPerAdnEntry() const;
        // return the number of group per ADN record of a slice, can be 0 if no groups
        // are supported then also no GAS is present
        UINT GetGroupPerAdnEntry(UINT slice) const;
        // return the GAS record size / count of a slice, current implementation only uses the
        // information of slice 0, because the assumption is that only one shared EF-GAS exists
        BOOLEAN IsGasSupported(UINT slice = 0) const;
        UINT GetGasRecordSize(UINT slice = 0) const;
        UINT GetGasRecordCount(UINT slice = 0) const;
        UINT GetGasUsedRecordCount(UINT slice = 0) const;
        UINT GetGasFreeRecordCount(UINT slice = 0) const;
        INT  GetGasHandle(UINT slice = 0) const;

        // return the AAS record size / count of a slice, current implementation only uses the
        // information of slice 0, beacuse the assumption is that only one shared EF-AAS exists
        BOOLEAN IsAasSupported(UINT slice = 0) const;
        UINT GetAasRecordSize(UINT slice = 0) const;
        UINT GetAasRecordCount(UINT slice = 0) const;
        UINT GetAasUsedRecordCount(UINT slice = 0) const;
        UINT GetAasFreeRecordCount(UINT slice = 0) const;
        INT GetAasHandle(UINT slice = 0) const;

        // indicates if hidden key information is supported, indicates if file EF-PBC is present
        BOOLEAN IsHiddenKeySupported() const;
        // indicates if phonebook control is supported, indicates presence of EF-UID etc.
        BOOLEAN IsSyncSupported() const;

        // ANR
        // return the number of ANRs per ADN record supported, can be 0 
        UINT GetAnrPerAdnEntry() const;
        // returns the to be used handle when reading/updating an entry
        INT GetAnrHandle(UINT slice, UINT entityno);
        // returns the recordsize which shall be used for allocating memory for the transfer buffer
        // this size also include the additional 2 bytes for SFI and record identifier
        UINT8 GetAnrRecordSize(UINT slice, UINT entityno);
        // returns the total number of ANR records
        UINT GetAnrRecordCount(UINT slice, UINT entityno) const;
        // returns the used number of ANR records
        UINT GetAnrUsedRecordCount(UINT slice, UINT entityno) const;
        // returns the free number of ANR records
        UINT GetAnrFreeRecordCount(UINT slice, UINT entityno) const;
        // returns the linktype if Type2/Type3 then the last two bytes of record shall be ignored
        UsimPbLinkType GetAnrFileType(UINT slice, UINT entityno);

        // SNE
        // return the number of SNEs per ADN record supported, can be 0 
        UINT GetSnePerAdnEntry() const;
        // returns the to be used handle when reading/updating an entry
        INT GetSneHandle(UINT slice, UINT entityno);
        // returns the recordsize which shall be used for allocating memory for the transfer buffer
        // this size also include the additional 2 bytes for SFI and record identifier
        UINT8 GetSneRecordSize(UINT slice, UINT entityno);
        // returns the total number of SNE records
        UINT GetSneRecordCount(UINT slice, UINT entityno) const;
        // returns the used number of SNE records
        UINT GetSneUsedRecordCount(UINT slice, UINT entityno) const;
        // returns the free number of SNE records
        UINT GetSneFreeRecordCount(UINT slice, UINT entityno) const;
        // returns the linktype if Type2/Type3 then the last two bytes of record shall be ignored
        UsimPbLinkType GetSneFileType(UINT slice, UINT entityno);

        // EMAIL
        // return the number of emails per ADN record supported, can be 0 
        UINT GetEmailPerAdnEntry() const;
        // returns the to be used handle when reading/updating an entry
        INT GetEmailHandle(UINT slice, UINT entityno);
        // returns the recordsize which shall be used for allocating memory for the transfer buffer
        // this size also include the additional 2 bytes for SFI and record identifier
        UINT8 GetEmailRecordSize(UINT slice, UINT entityno);
        // returns the total number of SNE records
        UINT GetEmailRecordCount(UINT slice, UINT entityno) const;
        // returns the used number of SNE records
        UINT GetEmailUsedRecordCount(UINT slice, UINT entityno) const;
        // returns the free number of SNE records
        UINT GetEmailFreeRecordCount(UINT slice, UINT entityno) const;
        // returns the linktype if Type2/Type3 then the last two bytes of record shall be ignored
        UsimPbLinkType GetEmailFileType(UINT slice, UINT entityno);

    private:    
        SimAccessor *    m_sim_accessor;
        T_PB_DESCRIPTOR  m_desc;
        UsimPbLocation   m_selected_location;
        UsimPbFillStatus m_fill_status;
        BOOLEAN          m_change_indication;

#if defined(APOXI_USIM_PB_SIMULATION)
        SimulAdn m_adn;
        SimulGas m_gas;
        SimulAas m_aas;
        void GenerateTestData();
#endif

};


#endif // APOXI_ENABLE_USIM_PHONEBOOK

#endif // Adc_UsimPbAcessor_hpp

