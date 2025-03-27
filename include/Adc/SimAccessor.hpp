/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Adc_SimAccessor_hpp)
#define Adc_SimAccessor_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Application.hpp>
#include <Kernel/UserDispatcher.hpp>
#include <Kernel/MessageReferrer.hpp>
#include <Kernel/Os/Mutex.hpp>

#include <Apc/SimMiscTypes.hpp>
#include <Apc/NetworkTypes.hpp>
#include <Apc/ImageData.hpp>
#include <Apc/Sms.hpp>
#include <Apc/StackMsgArgument.hpp>
#include <Apc/SimLockTypes.hpp>
#include <Apc/LockTypes.hpp>
#include <Apc/Message.hpp>

/*  ========================================================================
    DataAvailability
    ======================================================================== */

enum DataAvailability {
    DataAccessible,
    DataNotPresent,
    DataAccessUndefined
};


class DataHandler;

// ///////////////////////////////////////////////////////

const INT c_maxpending_messages     = 8;
const INT c_timeout_seconds         = 30;

// Record sizes //////////////////////////////////////////

const INT c_plmn_rec_size           = 3;
const INT c_acm_rec_size            = 3;
const INT c_puct_rec_size           = 5;
const INT c_ecc_rec_size            = 3;
const INT c_ccp_rec_size            = 14;
const INT c_tst_file_size           = 8;

// Sim File Ids //////////////////////////////////////////

// Dedicated File Ids
const SimFileId c_df_mf_id          = 0x3F00;
const SimFileId c_df_gsm_id         = 0x7F20;
const SimFileId c_df_telecom_id     = 0x7F10;
const SimFileId c_df_graphics_id    = 0x5F50;
const SimFileId c_df_mexe_id        = 0x5F3C;
const SimFileId c_df_orange_id      = 0x7f40;
const SimFileId c_df_cingular_id    = 0x7f66;

// Common Elementary File Ids
const SimFileId c_ef_elp_id         = 0x2F05;
const SimFileId c_ef_acm_id         = 0x6F39;
const SimFileId c_ef_acmmax_id      = 0x6F37;
const SimFileId c_ef_vgcs_id        = 0x6FB1;
const SimFileId c_ef_vgcss_id       = 0x6FB2;
const SimFileId c_ef_vbs_id         = 0x6FB3;
const SimFileId c_ef_vbss_id        = 0x6FB4;
const SimFileId c_ef_ecc_id         = 0x6FB7;
const SimFileId c_ef_sst_id         = 0x6F38;
const SimFileId c_ef_plmnsel_id     = 0x6F30;
const SimFileId c_ef_plmnselwact_id = 0x6F60;
const SimFileId c_ef_puct_id        = 0x6F41;
const SimFileId c_ef_smsp_id        = 0x6F42;
const SimFileId c_ef_smss_id        = 0x6F43;
const SimFileId c_ef_smsr_id        = 0x6F47;
const SimFileId c_ef_lp_id          = 0x6F05;
const SimFileId c_ef_imsi_id        = 0x6F07;
const SimFileId c_ef_spn_id         = 0x6F46;
const SimFileId c_ef_cbmi_id        = 0x6F45;
const SimFileId c_ef_cbmid_id       = 0x6F48;
const SimFileId c_ef_cbmir_id       = 0x6F50;
const SimFileId c_ef_ccp_id         = 0x6F3D;
const SimFileId c_ef_img_id         = 0x4F20;
const SimFileId c_ef_adn_id         = 0x6F3A;
const SimFileId c_ef_fdn_id         = 0x6F3B;
const SimFileId c_ef_sms_id         = 0x6F3C;
const SimFileId c_ef_msisdn_id      = 0x6F40;
const SimFileId c_ef_lnd_id         = 0x6F44;
const SimFileId c_ef_sdn_id         = 0x6F49;
const SimFileId c_ef_bdn_id         = 0x6F4D;
const SimFileId c_ef_ad_id          = 0x6FAD;
const SimFileId c_ef_loci_id        = 0x6F7E;
const SimFileId c_ef_emlpp_id       = 0x6FB5;
const SimFileId c_ef_spdi_id        = 0x6FCD;
const SimFileId c_ef_cmi_id         = 0x6F58;
const SimFileId c_ef_mbdn_id        = 0x6FC7;
const SimFileId c_ef_cfis_id        = 0x6FCB;
const SimFileId c_ef_mbi_id         = 0x6Fc9;

const SimFileId c_ef_ext1_id        = 0x6F4A;
const SimFileId c_ef_ext2_id        = 0x6F4B;
const SimFileId c_ef_ext3_id        = 0x6F4C;
const SimFileId c_ef_ext4_id        = 0x6F4E;
const SimFileId c_ef_ext6_id        = 0x6FC8;
const SimFileId c_ef_ext7_id        = 0x6FCC;

// Cphs Elementary File Ids
const SimFileId c_ef_vmsg_wtng_id   = 0x6F11;
const SimFileId c_ef_call_fwrd_id   = 0x6F13;
const SimFileId c_ef_opname_str_id  = 0x6F14;
const SimFileId c_ef_cust_serv_id   = 0x6F15;
const SimFileId c_ef_cphsinfo_id    = 0x6F16;
const SimFileId c_ef_mbox_no_id     = 0x6F17;
const SimFileId c_ef_opn_str_srt_id = 0x6F18;
const SimFileId c_ef_cphs_info_no_id= 0x6F19;

// Cingular Elementary File Ids
const SimFileId c_ef_tst_id         = 0x6FD2;

// Orange File Ids
const SimFileId c_ef_dynamic_id     = 0x6f9F;
const SimFileId c_ef_dynamic2_id    = 0x6f92;
const SimFileId c_ef_param_id       = 0x6f9B;

// EONS
const SimFileId c_ef_opl_id         = 0x6FC6;
const SimFileId c_ef_pnn_id         = 0x6FC5;

// Mexe
const SimFileId c_ef_mexest_id      = 0x4F40;
const SimFileId c_ef_orpk_id        = 0x4F41;
const SimFileId c_ef_arpk_id        = 0x4F42;
const SimFileId c_ef_tprpk_id       = 0x4F43;

// SimAccessor ///////////////////////////////////////////

class SimAccessor {
    public:
        friend class SimUserDispatcher;
        friend class MessageReceivedCondition;
        friend class MessageSendableCondition;
        friend class MessageStartCondition;
        friend class MessageQueueEmptyCondition;

        friend class UsimPlmnListDispatcher;
        friend class UsimSmsParamDispatcher;

#if defined(APOXI_ENABLE_USIM_PHONEBOOK)
        friend class UsimPbAccessor;
#endif

        SimAccessor();
        virtual ~SimAccessor();

        void Init();
        void Cleanup() const;
        void Reset();
        
        BOOLEAN GetFdnState() const { return m_fdn_state; }
        void SetFdnState(BOOLEAN state) { m_fdn_state = state; }

        BOOLEAN GetBdnState() const { return m_bdn_state; }
        void SetBdnState(BOOLEAN state) { m_bdn_state = state; }

        BOOLEAN IsAdnReadWritableIfFdnActive() const { return m_adn_rw_state; }
        void SetAdnReadWritableState(BOOLEAN state) { m_adn_rw_state = state; }

        BOOLEAN IsBdnReadWritableIfBdnNotActive() const { return m_bdn_rw_state; }
        void SetBdnReadWritableState(BOOLEAN state) { m_bdn_rw_state = state; }

        void SetSimInfo(const SimInfo & siminfo);
        void SetSimIndicator(const SimIndicator indicator);
        SimIndicator GetSimIndicator();
        const SimChangedState & GetSimChangedState() const { return m_sim_info.changed_state; }

        BOOLEAN GetSimInfo(SimInfo & siminfo);

        static BOOLEAN IsSimAccessAllowed();
        static BOOLEAN IsSimPresent();
        static BOOLEAN IsUsimInserted();

        void CancelAllRequests();

// Fileinfo
        UINT GetFileLength(SimFileId fileid);
        SimUpdateStatus GetFileInfo(SimFileId fileid, UINT & filesize, UINT & recordlength, ChvNo & chvno);
        DataAvailability GetDataAvailability(SimFileId fileid);

// ModifyLock
        BOOLEAN ModifyLock(const SecLockCommand & command, SecLockStates & lockstates);

// Imei
        BOOLEAN         GetImei(Imei & imei);
// Loci
        BOOLEAN         GetLociData(LociData & locidata);
// Pref Languages
        SimUpdateStatus GetPrefLanguageArray(INT startpos, LanguageArray & langarray);
        SimUpdateStatus UpdatePrefLanguageArray(INT startpos, const LanguageArray & langarray);
        UINT GetPrefLanguageFileLength() { return GetFileLength(c_ef_lp_id); }
// Pref Ext Languages
        SimUpdateStatus GetPrefExtLanguageArray(INT startpos, ExtLanguageArray & langarray);
        SimUpdateStatus UpdatePrefExtLanguageArray(INT startpos, const ExtLanguageArray & langarray);
        UINT GetPrefExtLanguageFileLength() { return GetFileLength(c_ef_elp_id); }

// Phonebook
        BOOLEAN         GetPhoneBookInfo(PhoneBookInfo & info);
        SimUpdateStatus GetPhoneBookEntry(INT recno, PhoneBookType phonebooktype,
                                          INT & textlength, INT & datalength, UINT8 * data);
        SimUpdateStatus UpdatePhoneBookEntry(INT recno, PhoneBookType phonebooktype,
                                             INT datalength, const UINT8 * data);
        SimUpdateStatus GetPhoneBookCountInfo(PhoneBookCntType phonebooktype, 
                                              INT & records, INT & usedrecords);

        SimUpdateStatus ActivateFdn();
        SimUpdateStatus DeactivateFdn();

        BOOLEAN IsFdnActivated() const { return m_fdn_state; }
        BOOLEAN IsBdnActivated() const { return m_bdn_state; }

        SimUpdateStatus ActivateBdn();
        SimUpdateStatus DeactivateBdn();

// Prefered Plmns
        SimUpdateStatus GetPlmnList(UINT8 * plmnlist, INT length);
        SimUpdateStatus UpdatePlmnList(INT start, const UINT8 * plmnlist, INT length);
        UINT GetPrefPlmnFileLength() { return GetFileLength(c_ef_plmnsel_id); }

// Prefered Plmns with ACT
        SimUpdateStatus GetPlmnwActList(UsimPlmn * plmnlist, INT count);
        SimUpdateStatus UpdatePlmnwActList(INT start, const UsimPlmn * plmnlist, INT length);
        UINT GetPlmnwActFileLength();

// Acm
        SimUpdateStatus GetAcm(INT recno, Acm & data, AcmSelector selector);
        SimUpdateStatus UpdateAcm(INT recno, const Acm & data, AcmSelector selector);

// Acm Max
        SimUpdateStatus GetMaxAcm(Acm & data);
        SimUpdateStatus UpdateMaxAcm(const Acm & data);
// Puct
        SimUpdateStatus GetPuct(Puct & puct);
        SimUpdateStatus UpdatePuct(const Puct & puct);

// Sst
        SimUpdateStatus GetServiceTable(SimServiceTable & sst);
// Spn & Spdi
        SimUpdateStatus GetSpn(ServiceProviderStruct & spn);
        SimUpdateStatus GetSpdiInfo(INT & length);
        SimUpdateStatus GetSpdiData(INT length, UINT8 * buffer);

// Ecc
        SimUpdateStatus GetEccArray(EccArray & eccarray, INT & length);

// Chvs
        ChvStatus VerifyChv(ChvNo chvno, const CHAR * chvptr, ChvAttemptsStruct & chvattempts);
        ChvStatus ChangeChv(ChvNo chvno, const CHAR * oldchvptr, const CHAR * newchvptr, 
                            ChvAttemptsStruct & chvattempts);
        ChvStatus UnblockChv(ChvNo chvno, const CHAR * unbchvptr, const CHAR * newchvptr, 
                             ChvAttemptsStruct & chvattempts);

        ChvStatus EnableChv1(const CHAR * chvptr, ChvAttemptsStruct & chvattempts);
        ChvStatus DisableChv1(const CHAR * chvptr, ChvAttemptsStruct & chvattempts);

        ChvStatus EnablePin(ChvNo chvno, const CHAR * chvptr, ChvAttemptsStruct & chvattempts);
        ChvStatus DisablePin(ChvNo chvno, const CHAR * chvptr, ChvAttemptsStruct & chvattempts);

        UINT GetSmsrCount();
        SimUpdateStatus GetSmsr(INT recno, UINT8 & link, SmsrData &smsr);
        SimUpdateStatus UpdateSmsr(INT recno, UINT8 link, const SmsrData &smsr);

// Sms Parameters
        BOOLEAN GetSmsParamFileSizes(UINT8 & reclength, INT & bufferlen);
        SimUpdateStatus GetSmsParam(INT recno, UINT8 * data, INT len);
        SimUpdateStatus UpdateSmsParam(INT recno, const UINT8 * data, INT bufferlen);

// SimToolkit icons
        BOOLEAN GetSimIconDescription(INT recno, SimIconDescription & data);
        BOOLEAN GetSimImage(const SimImageDescriptor & imgdesc, SimImage & data);

// CBMI 
        UINT GetCbmiFileLength() { return GetFileLength(c_ef_cbmi_id); }
        SimUpdateStatus GetCbmi(INT recno, CbmiData & data);
        BOOLEAN GetCbmi(UINT8 * data, INT maxlen);
        SimUpdateStatus UpdateCbmi(INT recno, const CbmiData & data);
// CBMI Range
        UINT GetCbmirFileLength() { return GetFileLength(c_ef_cbmir_id); }
        SimUpdateStatus GetCbmir(INT recno, CbmiRange & data);
        BOOLEAN GetCbmir(UINT8 * data, INT maxlen);
        SimUpdateStatus UpdateCbmir(INT recno, const CbmiRange & data);
// CCP 
#if defined(APOXI_ADC_CCP_CODE)
        UINT GetCcpFileLength() { return GetFileLength(c_ef_ccp_id); }
        SimUpdateStatus GetCcp(INT recno, CcpData & data);
        SimUpdateStatus UpdateCcp(INT recno, const CcpData & data);
#endif

// EMLPP
        SimUpdateStatus GetEmlpp(UINT8 & priority, UINT8 & fastcallsetup);

// EONS
        SimUpdateStatus GetPnnInfo(INT & recordcount, INT & recordlength);
        SimUpdateStatus GetPnnRecord(INT recordno, INT recordsize, UINT8 * buffer);
        SimUpdateStatus GetOplInfo(INT & recordcount, INT & recordlength);
        SimUpdateStatus GetOplRecord(INT recordno, INT recordsize, UINT8 * buffer);
// Mexe
        SimUpdateStatus GetMexeSt(UINT8 & mexest);
        SimUpdateStatus GetMexeRootPublicKeyProperty(SimFileId fileid, UINT & recordcount, UINT & recordlength);
        SimUpdateStatus GetMexeRootPublicKeyRecord(SimFileId fileid, UINT recordno, UINT recordsize, UINT8 * buffer);
        SimUpdateStatus GetMexeCertificateContent(SimFileId fileid, UINT size, UINT offset, UINT8 * buffer);

// CPHS Interface
        SimUpdateStatus GetCphsIst(CphsIstArray & data);
        SimUpdateStatus GetCphsVmwf(CphsVmwfArray & data);
        SimUpdateStatus UpdateCphsVmwf(const CphsVmwfArray & data);
        SimUpdateStatus GetCphsCfuf(CphsCfufArray & data);
        SimUpdateStatus UpdateCphsCfuf(const CphsCfufArray & data);
        SimUpdateStatus GetCphsOnm(CphsOnmName & data);
        SimUpdateStatus GetCphsOns(CphsOnsName & data);
        SimUpdateStatus GetCphsCsp(LineSelector selector, CphsCspArray & data);
        SimUpdateStatus UpdateCphsCsp(LineSelector selector, INT noofgroup, const CphsCspArray & data);
// MRU Property
        SimUpdateStatus UpdateMruProperty(UINT16 type, UINT8 index, UINT8 bitnumber, UINT8 bitvalue);

// Orange dyn flags
        SimUpdateStatus GetDynamicFlag(UINT8 & data);
        SimUpdateStatus GetDynamic2Flag(UINT8 & data);
        SimUpdateStatus UpdateDynamicFlag(UINT8 data);
        SimUpdateStatus UpdateDynamic2Flag(UINT8 data);
        SimUpdateStatus GetOrangeParam(SimEfOrangeParam & data);
        SimUpdateStatus UpdateOrangeParam(const SimEfOrangeParam & data);
// Cingular
        SimUpdateStatus GetTstFile(UINT8 * data);

// Generic Interface
        SimUpdateStatus GetSimData(SimFileId df_id, SimFileId ef_id, BOOLEAN istransparent, UINT16 offset, 
                                   UINT8 * data, INT maxlen, BOOLEAN usimcommand = FALSE);
        SimUpdateStatus SetSimData(SimFileId df_id, SimFileId ef_id, BOOLEAN istransparent, 
                                   UINT16 offset, const UINT8 * data, UINT8 length, BOOLEAN usimcommand = FALSE);
        SimUpdateStatus GetUsimFileProperty(SimFileId df_id, SimFileId ef_id, UINT & filesize, UINT & recordlength);
        SimUpdateStatus UsimSelect(SimFileId df_id, SimFileId ef_id);
        SimUpdateStatus GetSimFileProperty(SimFileId df_id, SimFileId ef_id, UINT & filesize, UINT & recordlength);

// SMS
        BOOLEAN ActivateSmsUsage();
        Sms::StorageType GetInitialPrefferedStorageMedia() const { return m_prefered_storage_media; }
        Sms::StorageType GetPreferredStorageMedia() const { return m_prefered_storage_media; }
        void SetInitialPrefferedStorageMedia(Sms::StorageType type) { m_prefered_storage_media = type; }

// Simtoolkit Simulation Interface
        BOOLEAN SendProactiveCommand(SimApduData * apdu, UINT8 & responsevalue);
        BOOLEAN SendProactiveCommandConfirmation();

        BOOLEAN GetSimPduCount(INT &pdu_count);
        BOOLEAN GetNvRamPduCount(INT &pdu_count);
// CMI 
        UINT GetCmiCount();
        SimUpdateStatus GetCmi(UINT recno, CmiRecord & cmirecord);
// MBI 
        UINT GetMbiCount(UINT & recordlength);
        SimUpdateStatus GetMbi(UINT recno, UINT8 * mbidata, UINT recordlength);
        SimUpdateStatus UpdateMbi(UINT recno, const UINT8 * mbidata, UINT recordlength);



// DR methods
    private:
        MdhResult MdhRegister(MdhViewHdl &view_hdl);
    public:
        MdhResult MdhMakeView(MdhViewHdl &view_hdl);
        MdhResult MdhSetViewConfig(MdhViewHdl view_hdl, const MdhViewConfig &view_config);
        MdhResult MdhUpdateSmsStatus(MdhViewHdl view_hdl, INT recno, UINT8 recordstatus, BOOLEAN complete);
        SimUpdateStatus MdhUpdateSmsStatus(MdhViewHdl view_hdl, INT recno, UINT8 recordstatus);
        MdhResult MdhSetStorageMedia(MdhWorkMedia work_media);
        MdhResult MdhGetSms(MdhViewHdl view_hdl, INT recno, TpduConc &tpduconc, MdhTimeStamp & timestamp, MdhExtendedData & ext_data);
        SimUpdateStatus MdhGetSms(MdhViewHdl view_hdl, INT recno, Tpdu &tpdu, MdhTimeStamp & timestamp, MdhExtendedData & ext_data);
        MdhResult MdhUpdateSms(MdhViewHdl view_hdl, INT recno, const TpduNode &tpdunode, UINT8 &no_saved, 
                               INT &storedrecno, MdhTimeStamp & timestamp);
        SimUpdateStatus MdhUpdateSms(MdhViewHdl view_hdl, INT recno, const Tpdu &tpdu, 
                               INT & storedrecno, MdhTimeStamp & timestamp);
        MdhResult MdhGetSmsReport(MdhViewHdl view_hdl, INT recno, SmsrData &data);
        static MdhWorkMedia SmsToMdhWorkMediaTranslation(Sms::StorageType work_media);
        static Sms::StorageType MdhToSmsWorkMediaTranslation(MdhWorkMedia work_media);
        MdhResult MdhDeleteSms(MdhViewHdl view_hdl, INT recno, const MdhDeletionCmd & cmd);
        MdhResult MdhSetSmsExtendedData(MdhViewHdl view_hdl, INT recno, const MdhExtendedData & ext_data);

        BOOLEAN MdhRequestCsmsRefNo(UINT16 & ref_no);

// Others
        SimUpdateStatus GetLastSimUpdateStatus();
        SimCardType DetectSimCardType();
        SmsMoreMessageType QuerySmsMoreMessageType();

#if defined(APOXI_ICC_USIM)
// service tables
        SimUpdateStatus GetUsimUst(UsimUst & ust);
        SimUpdateStatus GetUsimEst(UsimEst & est);
// loci files
        SimUpdateStatus GetUsimCsLoci(LociData & data);
        SimUpdateStatus GetUsimPsLoci(PsLociData & data);

// pref plmn lists
        SimUpdateStatus GetUsimPlmnList(UsimReadType type, UsimPlmn * plmnlist,  
                                        INT maxcount, INT & noofplmn);
        SimUpdateStatus UpdateUsimPlmn(INT pos, const UsimPlmn & plmn, UsimUpdateAction action);  
// pref lang files
        SimUpdateStatus GetUsimLanguageList(UsimLangFileType filetype, ExtLanguage * langlist, 
                                            INT maxcount, INT & nooflang);
        SimUpdateStatus UpdateUsimLanguage(UsimLangFileType, INT pos, const UsimLanguage & lang, UsimUpdateAction action);  

// ecc
        SimUpdateStatus GetUsimEccRecord(INT recno, UsimEccRecord & record);
// smsparams
        SimUpdateStatus GetUsimSmsParam(INT recno, UINT8 * data, INT len, INT & alphalen);
        SimUpdateStatus UpdateUsimSmsParam(INT recno, const UINT8 * data, INT bufferlen);
// file property
        SimUpdateStatus GetUsimFileProperty(UsimReadType type, UsimFileProperty & property);
        
#endif

    private:
        struct SimAccessorStruct {
            StackMsgArgId     inid;
            StackMsgArgId     outid;
            MessageReferrer * msgref;
            Application *     app;
            UINT16            priority;
            Ticks             timestamp;
            UINT32            param;
        };

        Mutex               m_mutex;
        static SimInfo      m_sim_info;
        static SimCardType  m_simtype;

        SimAccessorStruct   m_pendingmsg[c_maxpending_messages];

        SimUpdateStatus     m_last_update_status;

        BOOLEAN             m_fdn_state;
        BOOLEAN             m_bdn_state;
        BOOLEAN             m_adn_rw_state;
        BOOLEAN             m_bdn_rw_state;

        Sms::StorageType    m_prefered_storage_media;

        MdhViewHdl          m_main_view_hdl;

        void    ActivateMessage(StackMsgArgId id, UINT32 param = 0);
        void    DeactivateMessage(StackMsgArgId id, UINT32 param = 0);
        BOOLEAN IsMessageReceived(StackMsgArgId id, UINT32 param);
        BOOLEAN IsMessageSendable(StackMsgArgId id, UINT32 param);
        BOOLEAN IsMessageQueueEmpty();

        void StartSendingSignal(UserDispatcher & ud, BOOLEAN generic_active = FALSE);
        void FinishSendingSignal(UserDispatcher & ud);
        StackMsgArgument * GetArgument(StackMsgArgId id, UINT32 param = 0);
        StackMsgArgument * ExecuteStackMessage(StackMsgArgId id, StackMsgArgument* arg, UINT32 param = 0);
        StackMsgArgument * ProcessStackMessage(StackMsgArgId id, StackMsgArgument* sendarg); 

        BOOLEAN SendApdu(const SimFileId df_id, BOOLEAN df_res, 
                         const SimFileId ef_id, BOOLEAN ef_res, 
                         SimApduData * apdu);

};

// SimUserDispatcher /////////////////////////////////////

class SimUserDispatcher : public UserDispatcher {
    typedef UserDispatcher Base;

    public:
        SimUserDispatcher(SimAccessor * accessor);
        virtual ~SimUserDispatcher();

        static BOOLEAN HasParamAttribute(StackMsgArgId id);
        static BOOLEAN HasParam(StackMsgArgument * arg, UINT32 param);

    protected:
        virtual BOOLEAN OnMessage(const Message &msg);
    
    private:
        SimAccessor * m_accessor;
    
};

#endif // Adc_SimAccessor_hpp

