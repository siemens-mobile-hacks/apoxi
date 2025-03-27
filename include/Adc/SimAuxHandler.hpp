
/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimAuxHandler_hpp)
#define Adc_SimAuxHandler_hpp

#include <Adc/BaseDataHandler.hpp>
#include <Auxiliary/FixedPtrArray.hpp>
#include <Apc/StackWrapper.hpp>

/*  ========================================================================
                            Limitations
    ========================================================================*/

const INT c_max_plmns = 50;                                     // = 50 plmns
const INT c_max_plmn_buffer_size = c_max_plmns*3;               // = 50 plmns
const INT c_max_languages = 30;                                 // = 30 languages
const INT c_max_lang_buffer_size = c_max_languages*1;           // = 30 languages
const INT c_max_extlanguages = 30;                              // = 30 languages
const INT c_max_ext_lang_buffer_size = c_max_extlanguages*2;    // = 30 languages

const INT c_max_cbmi = 30;                                      // = 30 cbmi entries
const INT c_max_cbmir = 30;                                     // = 30 cbmir entries

const INT c_max_ccp = 5;                                        // = 5 ccp entries

const INT c_max_ecc_records = 10;                               // = 10 usim ecc records

const INT c_max_cmi_records = 10;                               // = 10 cmi records

const INT c_max_mbi_record_length = 5;                          // = 5 bytes per mbi record


struct SimLockStates;
class SimAccessor;

/*  ========================================================================
                            EONS structures
    ========================================================================*/

class PnnEntry 
{
    public:
        PnnEntry() : m_longci(FALSE), m_shortci(FALSE) {}

        WString m_longname;
        WString m_shortname;
        BOOLEAN m_longci;
        BOOLEAN m_shortci;
};

class OplEntry 
{
    public:
        enum {
            c_opl_buffer_len = 8
        };

        OplEntry(const UINT8 * buffer) { memcpy(m_buffer,buffer,c_opl_buffer_len); }

    // content is define in 3GPP TS 31.102 4.2.59
        BOOLEAN IsBcdPlmnMatching(BcdPlmn checkplmn) const { 
            return StackWrapper::IsBcdPlmnMatching(checkplmn,((UINT16)m_buffer[0]<<8)+m_buffer[1],m_buffer[2]);
        }
        UINT16  GetLacLow() const { return ((UINT16)m_buffer[3]<<8) + m_buffer[4]; }
        UINT16  GetLacHigh() const { return ((UINT16)m_buffer[5]<<8) + m_buffer[6]; }
        BOOLEAN HasEntireLacRange() const { return GetLacLow()==0x0000 && GetLacHigh()==0xFFFE; }
        INT     GetPnnRecordId() { return (INT)m_buffer[7]; }
        BOOLEAN HasPnnRecordId() const { return m_buffer[7]!=0x00 && m_buffer[7]!=0xFF; }
        

        UINT8 m_buffer[c_opl_buffer_len];
};

/*  ========================================================================
                            Mexe structures
    ========================================================================*/

enum MexeCertType 
{
    OperatorRootPublicKey,
    AdministratorRootPublicKey,
    ThirdPartyRootPublicKey
};

// is for internal use only, holds the Mexe descriptor entries of the SIM/USIM of the ORPK,ARPK,TPRPK
// files in the DF-Mexe directory
class MexeDescriptor 
{
    public:
        MexeDescriptor(MexeCertType type, const UINT8 * buffer, UINT16 len) {
            ASSERT_DEBUG(len>=10);
            m_length = len;     
            m_type = type;
            m_buffer = new UINT8[len];
            ASSERT_DEBUG(m_buffer!=0);
            memcpy(m_buffer,buffer,len); 
        }

        ~MexeDescriptor() {
            delete[] m_buffer;
            m_buffer = 0;
            m_length = 0;
        }

        MexeCertType GetMexeCertType() const { 
            return m_type;
        }

    // content is defined in 3GPP TS 51.011 10.4.4.2
    
        BOOLEAN IsValid() const { 
            ASSERT_DEBUG(m_buffer!=0); return (*m_buffer & 0x01)==0x00;
        }
        
        BOOLEAN IsAuthorityCert() const { 
            ASSERT_DEBUG(m_buffer!=0); return (m_buffer[1] & 0x01)==0x01;
        }
        
        UINT GetCertType() const { 
            ASSERT_DEBUG(m_buffer!=0); return (UINT)(m_buffer[2]);
        }

        SimFileId GetSimFileId() const { 
            ASSERT_DEBUG(m_buffer!=0); return (SimFileId)((m_buffer[3]<<8)+m_buffer[4]);
        }

        UINT16 GetCertOffset() const { 
            ASSERT_DEBUG(m_buffer!=0); return (UINT16)((m_buffer[5]<<8)+m_buffer[6]);
        }

        UINT16 GetCertLength() const { 
            ASSERT_DEBUG(m_buffer!=0); return (UINT16)((m_buffer[7]<<8)+m_buffer[8]);
        }

        UINT8 GetKeyIdLength() const { 
            ASSERT_DEBUG(m_buffer!=0); return (m_buffer[9]);
        }

        UINT8 * GetKeyIdBuffer() const { 
            ASSERT_DEBUG(m_buffer!=0); 
            return (GetKeyIdLength()>0) ? &m_buffer[10] : 0;
        }

    private:
        UINT8 *      m_buffer;
        UINT16       m_length;
        MexeCertType m_type;
};

class SimMexeCertificate 
{
    public:
        SimMexeCertificate(MexeDescriptor * certdesc, UINT8 * certbuffer, UINT16 certsize) 
        {
            ASSERT_DEBUG(certsize>0);
            ASSERT_DEBUG(certdesc!=0);
            ASSERT_DEBUG(certbuffer!=0);
            m_certdesc = certdesc;      
            m_certsize = certsize;      
            m_certbuffer = certbuffer;
        }

        ~SimMexeCertificate() {
            delete[] m_certbuffer;
            m_certbuffer = 0;
            m_certsize = 0;
            m_certdesc = 0;
        }

        MexeCertType GetMexeCertType() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0); return m_certdesc->GetMexeCertType();
        }

        BOOLEAN IsValid() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0); return m_certdesc->IsValid();
        }

        BOOLEAN IsAuthorityCert() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0); return m_certdesc->IsAuthorityCert();
        }

        UINT GetCertType() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0); return m_certdesc->GetCertType();
        }

        UINT16 GetCertSize() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0); return m_certsize;
        }

        const UINT8 * GetCertBuffer() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0); return m_certbuffer;
        }

        UINT8 GetKeyIdLength() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0);  return m_certdesc->GetKeyIdLength();
        }

        UINT8 * GetKeyIdBuffer() const { 
            ASSERT_DEBUG(m_certdesc!=0 && m_certbuffer!=0);  return m_certdesc->GetKeyIdBuffer();
        }

    private:
        MexeDescriptor * m_certdesc; 
        UINT16           m_certsize; 
        UINT8 *          m_certbuffer;
};

/*  ========================================================================
                            Helper function
    ========================================================================*/

INT FindFirstByte(const UINT8 * address, INT size, UINT8 eos);

/*  ========================================================================
                            SimAuxHandler
    ========================================================================*/

class SimAuxHandler : public BaseDataHandler
{
    typedef BaseDataHandler Base;

    public:
        SimAuxHandler();
        virtual ~SimAuxHandler();

// Reset
        void Reset();

// InitResult
        void SetInitResult(const SimInitResult & initresult);
        SimInitResult GetInitResult() const;

// Resetable/Refreshable by Simtoolkit
        BOOLEAN IsSimResetPossible() const;
        void SetSimResetPossible(BOOLEAN resetable);
        BOOLEAN IsSimRefreshPossible() const;
        void SetSimRefreshPossible(BOOLEAN refreshable);

// Chv1/Chv2 checking
        BOOLEAN DetectChvProtection(UINT16 fileid, ChvNo & chvno);

// Ofm
        BOOLEAN IsOfmToBeActivated();

// Imsi
        void SetImsi(const Imsi & imsi);
        BOOLEAN GetImsiString(WString & imsi) const;
        BcdPlmn GetImsiBcdPlmn() const;

// Imei
        BOOLEAN GetImeiString(WString & imei);

// Plmn lookup
        BOOLEAN LookupPlmnName(const Plmn & plmn, WString & longname, WString & shortname, 
                               NetType & nettype, WString & countryname);

// Spn & Spdi
        BOOLEAN GetSpnData(WString & spnstr, BOOLEAN & condition);
        BOOLEAN CheckSpnData(const Plmn & regplmn, BOOLEAN & showregplmn,   
                             BOOLEAN & showspnname, WString & spnname,
                             BOOLEAN use_spn_display_condition);

// Loci
        BOOLEAN RetrieveLociData(LociData & locidata);
        BOOLEAN GetLocationUpdateStatus(LocationUpdateStatus & status);
        BOOLEAN GetLocationBcdPlmn(BcdPlmn & plmn);
        BOOLEAN GetLocationLac(UINT16 & lac);

// SimInfo
        BOOLEAN GetSimInfo(SimInfo & siminfo) const;

        void SetSimLockStatus(const SimLockStates & lockstates);
        BOOLEAN GetSimLockStates(SimLockStates & lockstates) const;

// SimErrorCode
        void SetSimErrorCode(const SimErrorCode errorcode);
        BOOLEAN GetSimErrorCode(SimErrorCode & errorcode) const;

// Iccid
        BOOLEAN GetIccidString(WString & iccid) const;

// Prefered Plmns
        UINT8   GetPlmnCount() const;
        UINT8   GetMaxPlmnCount() const;
        BOOLEAN RetrievePlmnList();
        BcdPlmn GetBcdPlmn(INT idx) const;
        BOOLEAN UpdatePlmn(INT idx, BcdPlmn plmn);
        BOOLEAN InsertPlmn(INT idx, BcdPlmn plmn);
        BOOLEAN DeletePlmn(INT idx);
        BOOLEAN DeleteAllPlmns();

// Prefered Plmns PlmnwACT
        BOOLEAN IsPlmnwactPresent() { return m_plmnwact_present; }

        BOOLEAN RetrievePlmnwactList();
        BcdPlmn GetBcdPlmnwAct(INT idx) const;
        UINT16  GetPlmnAct(INT idx) const;

        BOOLEAN DeletePlmnwAct(INT idx);
        BOOLEAN DeleteAllPlmnwAct();
        BOOLEAN InsertPlmnwAct(INT idx, BcdPlmn plmn, UINT16 rat);
        BOOLEAN UpdatePlmnwAct(INT idx, BcdPlmn plmn, UINT16 rat);

// Pref Languages
        UINT8   GetLanguageCount() const;
        UINT8   GetMaxLangCount() const;
        Language GetLanguage(INT idx) const;
        BOOLEAN RetrieveLanguageList();
        BOOLEAN UpdateLanguage(INT idx, Language language);
        BOOLEAN InsertLanguage(INT idx, Language language);
        BOOLEAN DeleteLanguage(INT idx);
        BOOLEAN DeleteAllLanguages();

// Pref Ext Languages
        UINT8   GetExtLanguageCount(INT instance_nr) const;
        UINT8   GetMaxExtLangCount(INT instance_nr) const;
        WString GetExtLanguage(INT idx, INT instance_nr) const;
        BOOLEAN RetrieveExtLanguageList(INT instance_nr);
        BOOLEAN UpdateExtLanguage(INT idx, const WString & language, INT instance_nr);
        BOOLEAN InsertExtLanguage(INT idx, const WString & language, INT instance_nr);
        BOOLEAN DeleteExtLanguage(INT idx, INT instance_nr);
        BOOLEAN DeleteAllExtLanguages(INT instance_nr);

        WString GetActiveExtLanguage() const;
        void SetActiveExtLanguage(const WString & language);

// Puct
        BOOLEAN GetPuctData(WString & currencycode, UINT & eppu, INT & exponent);
        BOOLEAN UpdatePuctData(const WString & currencycode, UINT eppu, INT exponent);

// Acm
        BOOLEAN GetAcm(UINT32 & value, AcmSelector selector = Acm1);
        BOOLEAN UpdateAcm(UINT32 value, AcmSelector selector = Acm1);
        BOOLEAN GetMaxAcm(UINT32 & value);
        BOOLEAN UpdateMaxAcm(UINT32 value);

// Ecc
        UINT8   GetEccCount() const;
        BOOLEAN RetrieveEccList();
        BOOLEAN GetEcc(UINT idx, WString & eccstr);

// Sst
        UINT8   GetSstCount() const;
        BOOLEAN RetrieveSst();
        BOOLEAN GetServiceValues(UINT idx, BOOLEAN & allocated, BOOLEAN & activated);

// Ccp
#if defined(APOXI_ADC_CCP_CODE)
        INT GetMaxCcpCount();
        INT GetCcpCount();
        BOOLEAN GetCcp(INT idx, UINT8 * ccp_rec);
        BOOLEAN UpdateCcp(INT idx, const UINT8 * ccp_rec);
#endif

// Cbmi
        UINT8   GetMaxCbmiCount() const;
        BOOLEAN RetrieveCbmi();
        BOOLEAN GetCbmi(UINT idx, UINT16 & cbmi);
        BOOLEAN UpdateCbmi(UINT idx, UINT16 cbmi);

// Cbmi ranges
        UINT8   GetMaxCbmiRangeCount() const;
        BOOLEAN RetrieveCbmiRanges();
        BOOLEAN GetCbmiRange(UINT idx, UINT16 & rangehigh, UINT16 & rangelow);
        BOOLEAN UpdateCbmiRange(UINT idx, UINT16 rangehigh, UINT16 rangelow);

// Cmi 
        UINT8   GetMaxCmiCount() const;
        BOOLEAN RetrieveCmi();
        BOOLEAN GetCmi(UINT idx, WString & alphaid, UINT8 & cmi);

// Mbi
        UINT8   GetMaxMbiCount() const;
        UINT8   GetMbiRecordSize() const;
        BOOLEAN RetrieveMbi();
        BOOLEAN GetMbiRecord(UINT idx, UINT8 * buffer);
        BOOLEAN UpdateMbiRecord(UINT idx, const UINT8 * buffer);

// Ccp
        UINT8   GetMaxCcpCount() const;
        BOOLEAN RetrieveCcp();
        BOOLEAN GetCcp(UINT idx, CcpData & data);
        BOOLEAN UpdateCcp(UINT idx, const CcpData & data);

// Fdn
        BOOLEAN GetFdnState() const;

// Emlpp
        BOOLEAN GetEmlppSubscription(EmlppPriorityLevel idx, BOOLEAN & subscribed);
        BOOLEAN GetEmlppSetupCallCondition(EmlppPriorityLevel idx, BOOLEAN & condition);
// EONS
        BOOLEAN RetrieveEonsData(BOOLEAN pnnenabled, BOOLEAN oplenabled);
        BOOLEAN GetEonsPlmnName(const BcdPlmn & checkplmn, UINT16 lac, WString & longname, WString & shortname);

// Mexe
        BOOLEAN InitMexe();
        UINT    GetSimMexeCertificateCount() const { return m_cert_count; }
        SimMexeCertificate * GetSimMexeCertificate(UINT idx);

// Mark unread for Simtoolkit
        void MarkImsiUnread() { m_imsi_ispresent = FALSE; }
        void MarkPrefPlmnUnread() { m_plmn_list_isupdated = FALSE; }
        void MarkPrefLangUnread() { m_lang_list_isupdated = FALSE; }
        void MarkPrefExtLangUnread() { 
                m_extlang[0].m_ext_lang_list_isupdated = FALSE; 
                m_extlang[1].m_ext_lang_list_isupdated = FALSE;
        }
        void MarkEccUnread() { m_ecc_ispresent = FALSE; }
        void MarkSstUnread() { m_sst_ispresent = FALSE; }
        void MarkSpnUnread() { m_spn_ispresent = FALSE; }
        void MarkCcpUnread() { m_ccp_ispresent = FALSE; }
        void MarkCbmiUnread() { m_cbmi_ispresent = FALSE; }
        void MarkCbmirUnread() { m_cbmir_ispresent = FALSE; }
        void MarkAcmUnread() { m_acm_ispresent = FALSE; }
        void MarkAcmMaxUnread() { m_acmmax_ispresent = FALSE; }
        void MarkPuctUnread() { m_puct_ispresent = FALSE; }

#if defined(APOXI_ICC_USIM)

// ECC USIM
    public:
        UINT8   GetUsimEccCount() const;
        BOOLEAN RetrieveUsimEccList();
        BOOLEAN GetUsimEcc(UINT idx, WString & eccstr, WString & alphaid, UINT8 & servicecategory);
    private:
        UsimEccRecord m_eccrecords[c_max_ecc_records];

// UST USIM
    public:
        UINT8   GetUstCount() const;
        BOOLEAN RetrieveUst();
        BOOLEAN IsUsimServiceAvailable(UINT idx, BOOLEAN & available);
    private:
        UsimUst m_ust;
        BOOLEAN m_ust_ispresent;

// EST USIM
    public:
        UINT8   GetEstCount() const;
        BOOLEAN RetrieveEst();
        BOOLEAN IsUsimServiceEnabled(UINT idx, BOOLEAN & enabled);
    private:
        UsimEst m_est;
        BOOLEAN m_est_ispresent;

#endif


    private:
        BOOLEAN CommitLanguageList();
        BOOLEAN CommitExtLanguageList(INT instance_nr);

        BOOLEAN CommitPlmnList();

        BOOLEAN RetrieveSpn();
        BOOLEAN RetrieveSpdiData();
        BOOLEAN IsPlmnInSpdiData(const Plmn & plmn);

        Imei * RetrieveImei();
        Puct * RetrievePuct();
        BOOLEAN RetrieveEmlpp();

        static WString ConvertBcdStreamToString(const UINT8 * stream, INT length, INT ignorenibble = 0);

    // decoding is done as described in 3GPP TS 31.102 V6.3.0 (4.2.58) and 3GPP TS 24.008 (10.5.3.5a)
        PnnEntry * CreatePnnEntry(UINT8 * buffer, INT len);
    // creates an oplentry if valid
        OplEntry * CreateOplEntry(UINT8 * buffer);

        SimInitResult m_initresult;

        BOOLEAN     m_sim_resetable;
        BOOLEAN     m_sim_refreshable;
        BOOLEAN     m_imsi_ispresent;
        BOOLEAN     m_imei_ispresent;
        BOOLEAN     m_plmnwact_present;
        BOOLEAN     m_plmn_list_isupdated;
        BOOLEAN     m_lang_list_isupdated;
        BOOLEAN     m_ext_lang_list_isupdated;
        BOOLEAN     m_acm_ispresent;
        BOOLEAN     m_acmmax_ispresent;
        BOOLEAN     m_puct_ispresent;

        BOOLEAN     m_ecc_ispresent;
        BOOLEAN     m_sim_info_isupdated;
        BOOLEAN     m_sim_lockstates_isupdated;
        BOOLEAN     m_sim_errorcode_isupdated;
        BOOLEAN     m_sst_ispresent;

        BOOLEAN     m_spn_isinitialized;
        BOOLEAN     m_spn_ispresent;
        BOOLEAN     m_spdi_isinitialized;
        BOOLEAN     m_spdi_ispresent;

        BOOLEAN     m_ccp_ispresent;
        BOOLEAN     m_cbmi_ispresent;
        BOOLEAN     m_cbmir_ispresent;
        BOOLEAN     m_emlpp_ispresent;
        BOOLEAN     m_emlpp_isupdated;

        Imsi          m_imsi;
        Imei          m_imei;
        SimLockStates m_sim_lockstates;
        SimErrorCode  m_sim_errorcode;
        BOOLEAN       m_sminitfinshed;

        UINT8       m_plmn_max_count;
        UINT8       m_plmn_count;
        UINT8       m_plmn_list[c_max_plmn_buffer_size];
        UsimPlmn    m_plmn_wact_list[c_max_plmns];

        UINT8       m_lang_max_count;
        UINT8       m_lang_count;
        Language    m_lang_list[c_max_languages];

        struct ExtLanguageBuffer {
            BOOLEAN     m_ext_lang_list_isupdated;
            UINT8       m_ext_lang_max_count;
            UINT8       m_ext_lang_count;
            ExtLanguage m_ext_lang_list[c_max_extlanguages];
        };

        ExtLanguageBuffer m_extlang[2];

        ExtLanguageBuffer & GetExtLanguageBuffer(INT instance_nr) {
            ASSERT_DEBUG(instance_nr==0 || instance_nr==1);
            return m_extlang[instance_nr];
        };
        const ExtLanguageBuffer & GetExtLanguageBuffer(INT instance_nr) const {
            ASSERT_DEBUG(instance_nr==0 || instance_nr==1);
            return m_extlang[instance_nr];
        };

        ExtLanguage m_active_ext_lang;

        ServiceProviderStruct m_spn;

        Puct        m_puct;
        UINT8       m_ecc_count;
        EccArray    m_eccarray;
        UINT8           m_sst_count;
        SimServiceTable m_sst;

        UINT8      m_cbmi_max_count;
        UINT8      m_cbmi_list[c_max_cbmi*2];

        UINT8      m_cbmir_max_count;
        UINT8      m_cbmir_list[c_max_cbmir*4];

        UINT8      m_ccp_max_count;
        UINT8      m_ccp_list[c_max_ccp*14];

        UINT8      m_emlpp_priority;
        UINT8      m_emlpp_fastcallsetup;
// CMI
        BOOLEAN    m_cmi_ispresent;
        UINT8      m_cmi_max_count;
        CmiRecord  m_cmi_records[c_max_cmi_records];

// EONS
        UINT8      m_eons_initialized;
        UINT8      m_eons_present;
        FixedPtrArray<PnnEntry>  m_pnn_entries;
        FixedPtrArray<OplEntry>  m_opl_entries;
        Plmn *     m_spdi_entries;
        INT        m_spdi_plmn_count;

// Mexe
        BOOLEAN    m_mexe_initialized;
        FixedPtrArray<MexeDescriptor>  m_mexe_entries;
        UINT       m_cert_count;

// MBI
        BOOLEAN    m_mbi_ispresent;
        UINT8      m_mbi_max_count;
        UINT8      m_mbi_record_size;
        UINT8 *    m_mbi_buffer;

};

#endif

