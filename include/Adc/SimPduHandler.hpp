/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_SimPduHandler_hpp)
#define Adc_SimPduHandler_hpp

#include <Auxiliary/WString.hpp>
#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/DateTime.hpp>
#include <Auxiliary/FixedPtrArray.hpp>
#include <Auxiliary/ProviderListener.hpp>
#include <Auxiliary/BlobObject.hpp>
#include <Auxiliary/IndexTable.hpp>

#include <Apc/SignalTypes.hpp>
#include <Apc/MessageTypeIndicator.hpp>
#include <Apc/DataCodingScheme.hpp>
#include <Apc/ShortMessageStatus.hpp>
#include <Adc/BaseDataHandler.hpp>
#include <Apc/MdhSmsStackMsgArgs.hpp>

/*  ========================================================================
    SmsFilterType
    ======================================================================== */
enum SmsFilterType {
    AllSmsFilterType          = 0,
#if defined (APOXI_SMS_NEW_PROVIDERS)
    InboxSmsFilterType        = 1,
    OutboxSmsFilterType       = 2,
    ArchiveSmsFilterType      = 3,
    StatusReportSmsFilterType = 4,
    UnreadSmsFilterType       = 5,
#else
    UnreadSmsFilterType       = 1,
    ReadSmsFilterType         = 2,
    UnsentSmsFilterType       = 3,
    SentSmsFilterType         = 4
#endif
};

/*  ========================================================================
    SmsDeleteStatus
    ======================================================================== */
enum SmsDeleteStatus {
    SmsDeleteRead =     0x01,           // 0000 0001
    SmsDeleteUnread =   0x02,           // 0000 0010
    SmsDeleteSent =     0x04,           // 0000 0100
    SmsDeleteUnsent =   0x08            // 0000 1000
};

/*  ========================================================================
    SmsWStringCache
    ======================================================================== */

class SmsWStringCache
{
    public:
        enum {
            c_invalid_rec_no = 0x2000
        };

    class Entry
    {
        public:
            Entry(INT size) { m_recno=c_invalid_rec_no; m_text.PreAlloc(size+1); }

            UINT16              GetRecNo() const { return m_recno; }
            const WString &     GetText() const { return m_text; }
            void SetData(UINT16 recno, const WString & text) { m_recno=recno; m_text = text; }

        private:
            UINT16      m_recno;
            WString     m_text;
    };

    typedef FixedPtrArray<Entry> CacheArray;

    public:
        SmsWStringCache();
        ~SmsWStringCache();
        
        void Init(INT noofentries, INT noofchars);
        UINT16 Put(const WString & string, UINT16 newrecno, UINT16 & cacheidx);

        const WString & GetWString(INT index) const {
            ASSERT_DEBUG(m_cachearray[index]!=0);
            return m_cachearray[index]->GetText();
        };
        UINT16 GetRecNo(INT index) const {
            ASSERT_DEBUG(m_cachearray[index]!=0);
            return m_cachearray[index]->GetRecNo();
        };
        void SetData(INT index, UINT16 recno, const WString & text) {
            ASSERT_DEBUG(m_cachearray[index]!=0);
            m_cachearray[index]->SetData(recno, text);
        };


    private:
        INT                m_noofentries;
        INT                m_noofchars;
        CacheArray         m_cachearray;
        INT                m_iterator;
};

/*  ========================================================================
    ConcatenetedStatus
    ======================================================================== */
enum ConcatenetedStatus {
    NormalSms = 0,
    ConcatenetedSms = 1,
    PartlyConcatenetedSms = 2, 
    InvalidSms = 3
};

/*  ========================================================================
    TpduCountType
    ======================================================================== */
enum TpduCountType {
    SimTpdus = 0,
    NvramTpdus = 1,
    SmsReportTpdus = 2,
    OverallTpdus = 3,
    NoOfCountTypes = 4
};

class SimPduHandler;

/*  ========================================================================
    TpduHeaderInformation
    ======================================================================== */
struct TpduPhoneNumberPersist
{
    UINT8 m_data[12];

    void Clear() { 
        memset(m_data,0xFF,sizeof(m_data)); 
        m_data[0] = 0; 
    }
    BOOLEAN IsEqual(const TpduPhoneNumberPersist & persist) const { 
        return memcmp(m_data, persist.m_data, sizeof(m_data))==0; 
    }
    void Set(const PhoneNumber & phno) {
        Clear();
        memcpy(m_data,phno.GetRawBCDBuffer(),phno.GetRawBCDLength());
    }
};

/*  ========================================================================
    TpduHeaderInformation
    ======================================================================== */
struct TpduHeaderInformation
{
        void Init();
        void Clear();

        void SetTpduInformation(Tpdu & tpdu, Sms::StorageType storagetype, MdhTimeStamp timestamp, MdhExtendedData ext_data);

        BOOLEAN                         IsValid() const;
        Tpdu::Status                    GetStatus() const { return (Tpdu::Status)m_status; }
        void                            SetStatus(Tpdu::Status status) { m_status = status; }
        MessageTypeIndicator::Type      GetMessageType() const { return (MessageTypeIndicator::Type)m_bitfield.m_msg_type; }
        DataCodingScheme::MessageClass  GetMessageClass() const { return (DataCodingScheme::MessageClass)m_bitfield.m_msg_class; }
        DataCodingScheme::GroupId       GetGroupId() const { return (DataCodingScheme::GroupId)m_bitfield.m_coding_group; }
        ShortMessageStatus              GetShortMessageStatus() const {  return m_msg_status; }
        DataCodingScheme                GetDcs() const { return m_dcs; }
        ProtocolIdentifier              GetPid() const { return m_protid; }
        const DateTime::Persist &       GetDateTime() const { return m_datetime; } 
        void                            SetDateTime(const DateTime::Persist & datetime) { m_datetime = datetime; } 
        BOOLEAN                         IsDateTimeValid() const { return ! m_datetime.IsZero(); }
        BOOLEAN                         ReplyPathExists() const { return m_bitfield.m_reply_path_exists; }
        const TpduPhoneNumberPersist &  GetPhoneNumber() const { return m_phnr; }
//      BOOLEAN                         IsPhoneNumberValid() const { return ! GetPhoneNumber().IsInvalid(); }
        BOOLEAN                         IsConcateneted() const { return m_bitfield.m_is_concateneted; }
        UINT16                          GetConcRefNo() const { return m_conc_ref_no; }
        UINT8                           GetConcMaxNo() const { return m_conc_max_no; }
        UINT8                           GetConcSeqNo() const { return m_conc_seq_no; }

        SmsPortNo                       GetSmsPortNo() const { return m_sms_port_no; }
        UINT8                           GetPayloadSize() const { return m_payload_size; }
        
        UINT32                          GetExtendedData() const { return m_extended_data; }

        UINT16                          GetInternalRecNo() const { return m_int_ref_no; }
        void                            SetInternalRecNo(UINT16 ref_no) { m_int_ref_no = ref_no; }
        ConcatenetedStatus              GetConcatenetedStatus() const { return (ConcatenetedStatus)m_bitfield.m_concateneted_status; }
        void                            SetConcatenetedStatus(ConcatenetedStatus status) { m_bitfield.m_concateneted_status = status; }

        const SmsReferenceNumber&       GetReferenceNumber() const { return (m_refno); }
        Sms::StorageType                GetSmsStorageType() const { return (Sms::StorageType)m_storagetype; }   
        void                            SetSmsStorageType(Sms::StorageType type) { m_storagetype = type; }  

        static UINT16                   GetMaxConcRefNo() { return m_max_conc_ref_no; }
        UINT8                           GetConcatenetedTpduNum() const { return m_conc_num; }               
        void                            SetConcatenetedTpduNum(UINT8 conc_num) { m_conc_num = conc_num; }   
        UINT8                           GetSimStoredTpduNum() const { return m_sim_stored; }                
        UINT8                           GetFlashStoredTpduNum() const { return m_flash_stored; }                
        void                            SetSimFlashStoredTpduNum(UINT8 sim_num, UINT8 flash_num) { 
                                            m_sim_stored = sim_num; 
                                            m_flash_stored = flash_num; 
                                        }   
#if defined(APOXI_ENABLE_CONC_SMS_SCA_CHECK)
        UINT32                          GetScaHash() const { return m_sca_hash; }   
#endif
        UINT16                          GetWStringCashPos() const { return m_cache_pos; }   
        void                            SetWStringCashPos(UINT16 pos) { m_cache_pos = pos; }    

        BOOLEAN                         HasWrongStatus() const { return m_wrong_status; }
        void                            SetWrongStatus(BOOLEAN status) { m_wrong_status = status;}


//  private:
        TpduPhoneNumberPersist          m_phnr;             // 12 byte
        DateTime::Persist               m_datetime;         // 4  byte
#if defined(APOXI_ENABLE_CONC_SMS_SCA_CHECK)
        UINT32                          m_sca_hash;         // 4  byte
#endif
        DataCodingScheme                m_dcs;              // 2  byte
        SmsPortNo                       m_sms_port_no;      // 2  byte
        UINT16                          m_conc_ref_no;      // 2  byte 
        UINT16                          m_int_ref_no;       // 2  byte
        struct {                                            
            UINT                        m_reply_path_exists   : 1;
            UINT                        m_is_concateneted     : 1;
            UINT                        m_concateneted_status : 2;
            UINT                        m_msg_type            : 4;
            UINT                        m_msg_class           : 4;
            UINT                        m_coding_group        : 4;   
        } m_bitfield;                                       // 2  byte 
        UINT8                           m_conc_max_no;      // 1  byte
        UINT8                           m_conc_seq_no;      // 1  byte
        UINT8                           m_storagetype;      // 1  byte
        SmsReferenceNumber              m_refno;            // 1  byte
        ShortMessageStatus              m_msg_status;       // 1  byte
        UINT8                           m_payload_size;     // 1  byte
        ProtocolIdentifier              m_protid;           // 1  byte
        UINT8                           m_conc_num;         // 1  byte
        UINT8                           m_status;           // 1  byte
        UINT8                           m_sim_stored;       // 1  byte
        UINT8                           m_flash_stored;     // 1  byte
        UINT16                          m_cache_pos;        // 2  bytes
                                                            // Sum = 43 bytes + 1 = 44 bytes
        BOOLEAN                         m_wrong_status;     // 1  byte
                                                            // Sum = 42 bytes
        static UINT16                   m_max_conc_ref_no;
        UINT32                          m_extended_data;    // 4 additional bytes
};


/*  ========================================================================
    TpduCache
    ======================================================================== */
class TpduCache
{
    typedef FixedPtrArray<Tpdu> TpduCacheArray;

    public:
        TpduCache(UINT16 maxcache, SimPduHandler * handler);
        ~TpduCache();

        Tpdu *   GetTpdu(UINT16 tpduno, MdhViewHdl viewhdl, MdhTimeStamp & timestamp, MdhExtendedData & ext_data);
        BOOLEAN  MarkAsInvalid(UINT16 tpduno);
        void     Clear();
        void     Resize(UINT16 maxcache);
        void     SetStatus(UINT16 tpduno, Tpdu::Status status);
    #if defined(APOXI_ENABLE_SMS_EXTENDED_DATA)
        BOOLEAN  UpdateExtendedData(UINT16 tpduno, MdhExtendedData ext_data);
    #endif


    private:
        UINT16             m_counter;
        UINT16             m_maxcache;
        TpduCacheArray     m_cached_tdpus;
        IndexTable<UINT16> m_cached_tdpu_nos;
        IndexTable<UINT32> m_cached_timestamps;
    #if defined(APOXI_ENABLE_SMS_EXTENDED_DATA)
        IndexTable<UINT32> m_cached_extended_data;
    #endif

        SimPduHandler *    m_handler;
};

const UINT16 c_max_smsr_in_ram = 5;
const UINT16 c_max_smsr_pdus = 20;
const UINT16 c_max_sim_pdus = DR_MAX_SUPPORTED_SIM_SMS;
const UINT16 c_max_nvram_pdus = DR_MAX_NVRAM_SMS;
const UINT16 c_max_pdus = c_max_sim_pdus + c_max_nvram_pdus + c_max_smsr_pdus;
const UINT16 c_max_table1 = c_max_pdus/2;
const UINT16 c_max_table2 = c_max_pdus - c_max_table1;
const INT16  c_max_reloadable_pdus = 30;
const UINT8  c_default_max_pdu_per_sms = 255;
const UINT16 c_max_smsr_length = 40;

/*  ========================================================================
    SimPduHandler
    ======================================================================== */


class SimPduHandler : public BaseDataHandler
{
    struct TpduCount {
        UINT16 m_sum;
        UINT16 m_free;
#if defined (APOXI_SMS_NEW_PROVIDERS)
        UINT16 m_read;
        UINT16 m_unread;
        UINT16 m_sent;
        UINT16 m_unsent;
#endif
    };

    struct SmsrCache {
        Tpdu::Status   m_status;
        INT            m_link;
        UINT8          m_data[c_max_smsr_length];
    };

    typedef BaseDataHandler Base;
    
    typedef FixedPtrArray<TpduHeaderInformation> TpduHeaderInformationArray;

    friend class CompoundSmsItem;
    friend class CompoundTpduItem;
    friend class TpduCache;

    public:
        SimPduHandler();
        virtual ~SimPduHandler();

        void Reset();
        void Refresh();

        void Init(SimAccessor * handler);

        BOOLEAN ChangePreferredStorageMedia(Sms::StorageType storagetype);
        Sms::StorageType GetPreferredStorageMedia() const;

        INT GetProgress() const { return m_progress; }

        BOOLEAN    Update(ProviderListener * listener);

        void       ReloadNewMsgTpdu(Tpdu &tpdu, INT tpduno);
        void       ReloadTpdu(INT tpduno);
        BOOLEAN    StoreTpdu(const Tpdu &tpdu, INT tpduno = 0);
        BOOLEAN    StoreTpdu(const Tpdu &tpdu, const Sms::StorageType storage_type);
        BOOLEAN    StoreTpdu(const Tpdu &tpdu, const Sms::StorageType storage_type, INT & dst_tpduno);
        BOOLEAN    RefreshData(INT tpduno, MdhTimeStamp timestamp);
        BOOLEAN    RefreshStatusData(INT tpduno, Tpdu::Status newstatus);
        INT    GetMaxCount() const { return (INT)m_max_count; }

#if defined(APOXI_SMS_NEW_PROVIDERS)
        INT GetInboxCount() const { return (INT)m_inbox_count; }
        INT GetOutboxCount() const { return (INT)m_outbox_count; }
        INT GetArchiveCount() const { return (INT)m_archive_count; }
        INT GetStatusReportCount() const { return (INT)m_statusreport_count; }
        INT GetUnreadCount() const { return (INT)m_unread_count; }

        INT GetProviderCount(SmsFilterType filter){ return GetRecnoTableSize(filter); }

        INT  GetOccupiedTpduCount(TpduCountType type) const;
        INT  GetEmptyTpduCount(TpduCountType type) const;
        INT  GetMaxTpduCount(TpduCountType type) const;

        INT  GetReadTpduCount(TpduCountType type) const;
        INT  GetUnreadTpduCount(TpduCountType type) const;
        INT  GetSentTpduCount(TpduCountType type) const;
        INT  GetUnsentTpduCount(TpduCountType type) const;

    #if defined(_DEBUG)
        UINT32 GetSortDuration(SmsFilterType filter);
        UINT32 GetIndexDuration();
        INT    GetIterationDepth(SmsFilterType filter);
    #endif
#else
        INT    GetReadCount() const { return (INT)m_read_count; }
        INT    GetUnreadCount() const { return (INT)m_unread_count; }
        INT    GetSentCount() const { return (INT)m_sent_count; }
        INT    GetUnsentCount() const { return (INT)m_unsent_count; }
#endif
        const TpduCount & GetTpduCount(TpduCountType type) { 
            ASSERT_DEBUG((INT)type >= (INT)SimTpdus && (INT)type < (INT)NoOfCountTypes);
            return m_count_table[type];
        }

        INT                    GetSmsTpduPosition(INT recno, SmsFilterType filter_type);
        Tpdu *                 GetSmsTpdu(INT recno, SmsFilterType filter_type);
        TpduHeaderInformation * GetSmsInformation(INT recno, SmsFilterType filter_type);
        BOOLEAN                GetSmsWString(INT recno, SmsFilterType filter_type, WString & wstr);
        BOOLEAN                GetHeaderText(INT recno, SmsFilterType filter_type, WString & wstr);

        BOOLEAN                SetSmsStatus(INT recno, SmsFilterType filter_type, Tpdu::Status newstatus);
        BOOLEAN                DeleteAllSms(SmsFilterType filter_type);
        BOOLEAN                DeleteAllSms(SmsDeleteStatus criteriamask, BOOLEAN smsreports);
        BOOLEAN                GetSmsDebugWString(INT recno, SmsFilterType filter_type, WString & wstr);

        BOOLEAN                IsSmsFilterTypeMatch(SmsFilterType filter, INT recno);

        static void SetEmptyNumberText(const WCHAR * text) { m_missing_part_text = text; }
        static UINT8 GetConcSmsPduMaxNo() { return m_max_conc_pdu_no; }
        static void SetConcSmsPduMaxNo(UINT8 no) { ASSERT_DEBUG(no>0); m_max_conc_pdu_no = no; }
        static BOOLEAN IsPartlyConcSmsStateChangeable() { return m_csms_state_changeable; }
        static void SetPartlyConcSmsStateChangeable(BOOLEAN changeable) { m_csms_state_changeable = changeable; }
        static void SetMaxNoOfPduCache(UINT16 pdu_no_cache) { ASSERT_DEBUG(pdu_no_cache>0); m_pdu_no_cache = pdu_no_cache; }
        static void SetSmsHeaderCacheParams(INT noofentries, INT noofchars) {
            m_no_cache_header = noofentries;
            m_no_cache_chars = noofchars;
        }
        static void EnablePidCheckForConcSms(BOOLEAN pidcheck) { m_csms_pid_check_enabled = pidcheck; }

        BOOLEAN         IsSubSystemInitialized() const { return m_init_sub_system; }

        BOOLEAN         InitSmsTransmit(INT simno, INT nvramno);
        BOOLEAN         StoreSmsTransmit(Tpdu & tpdu, INT tpduno, MdhWorkMedia workmedia, MdhTimeStamp timestamp, MdhExtendedData ext_data);
        BOOLEAN         UpdateTransmit(ProviderListener * listener);

        void            OnMdhSmsDeletion(const MdhSmsDeletionIndArg & arg);

        void            OnNewStatusReportArrived(const MdhNewStatusReportIndArg & arg);
        BOOLEAN         IsReloadInProgress() const { return m_reloadinprogress; }

        BOOLEAN         GetNextFreeTpduNo(const Sms::StorageType storage_type, INT & tpduno);
        BOOLEAN         IsSpaceLeftOnStorageMedia(const Sms::StorageType storage_type, INT required_tpdus = 1);
        BOOLEAN         IsSpaceLeftOnStorageMedia(TpduCountType type, INT required_tpdus = 1);
        TpduCountType   GetTpduCountType(const Sms::StorageType storage_type);
                
        Sms::StorageType GetStorageMediaPrimitive(const Sms::StorageType storage_type);
        
        BOOLEAN         CopyTo(INT tpduno, const Sms::StorageType storage_type, ProtocolIdentifier pid, INT & dst_tpduno);
        BOOLEAN         CopyTo(INT tpduno, const Sms::StorageType storage_type, INT & dst_tpduno);

        INT             FindRowByTpduNumber(INT tpduno, SmsFilterType filter);

        BOOLEAN         SetSmsExtendedData(INT recno, const MdhExtendedData & ext_data);

    private:
        TpduHeaderInformation * GetTpduHeaderInformationPtr(INT idx) { 
            ASSERT_DEBUG(idx<c_max_pdus);
            if(idx<c_max_table1) {
                return &m_header_entries1[idx];
            } else {
                return &m_header_entries2[idx-c_max_table1];
            }
        }

        BOOLEAN         ReloadMarkedPdus(BOOLEAN allowbuildindextable = TRUE);
        BOOLEAN         InitStorageSubSystem();

        INT             GetTpduNo(INT recno, SmsFilterType filter_type);
        INT             GetConcatenedTpduNo(UINT16 intrecno, UINT8 conc_seq_no);

        BOOLEAN         LoadAllTpduHeaderInformation(ProviderListener * listener);
        BOOLEAN         CreateTpduHeaderInformationObjects();
        void            DeleteTpduHeaderInformationObjects();
        BOOLEAN         LoadTpduHeaderInformation(INT tpduno);
        BOOLEAN         UpdateTpduStatus(INT tpduno, Tpdu::Status recordstatus);
        BOOLEAN         GetTpduWString(INT tpduno, WString & wstr);
        void            UpdateInternalInformation();
        void            UpdateInternalInformation(INT tpduno);
        void            MakeIndextables();

        void            ClearSmsrData();
        INT             PutSmsrData(INT link, const UINT8 * data, INT length, BOOLEAN withsca);
        BOOLEAN         GetSmsrTpdu(INT pos, Tpdu & tpdu);
        INT             GetSmsrTpduPos(INT link);
        void            DeleteSmsrTpdu(INT link);
        BOOLEAN         LoadPossibleSmsrTpdu();

        Tpdu *          GetTpduPrimitive(INT recno, MdhTimeStamp & timestamp, MdhExtendedData & ext_data);
        Tpdu *          GetTpduPrimitive(INT recno);

        Sms::StorageType GetTpduStorageMediaTypePrimitive(INT recno); 

        BOOLEAN         UpdateTpduStatusPrimitive(INT recno, UINT8 status, BOOLEAN readwrite);
        BOOLEAN         StoreTpduPrimitive(INT recno, const Tpdu & tpdu, INT & position);

        BOOLEAN         GetSimPduCount(INT &pdu_count);
        BOOLEAN         GetNvRamPduCount(INT &pdu_count);
        BOOLEAN         GetSmsrPduCount(INT &pdu_count);

        void            ClearCsmsRecCache(INT no);
        void            PutStringIntoCache(TpduHeaderInformation * headerinfo, Tpdu & tpdu, INT tpduno);

        BOOLEAN         GetStorageMediaInformation(const Sms::StorageType storage_type, Sms::StorageType & basic_type, INT required_tpdus = 1);
        BOOLEAN         CopyTpdu(const Tpdu &tpdu, Sms::StorageType storage_type, ProtocolIdentifier pid, BOOLEAN pid_valid, INT & dst_tpduno);
        BOOLEAN         CopyTo(INT tpduno, const Sms::StorageType storage_type, ProtocolIdentifier pid, BOOLEAN pid_valid, INT & dst_tpduno);


#if defined(APOXI_SMS_NEW_PROVIDERS)

        void ResetTpduCountType(TpduCountType type);

    #if defined(_DEBUG)
        void InitDebugMemberVariables();
        void SetSortDuration(UINT32 time, SmsFilterType filter);
        void SetIterationDepth(SmsFilterType filter);
    #endif

        DateTime::Persist GetDateTime(INT recno, SmsFilterType filter) {
            INT tpduno = GetTpduNo(recno, filter);
            
            if(tpduno < 0) {
                DateTime::Persist dt_zero = {0};
                return dt_zero;
            }
            TpduHeaderInformation * headerinfo = GetTpduHeaderInformationPtr(tpduno);
            ASSERT_DEBUG(headerinfo != 0);

            return headerinfo->GetDateTime();
        }

        INT  Partition(UINT16 a[], INT first, INT last, SmsFilterType filter);
        void QuickSort(SmsFilterType filter);
        void QuickSort(UINT16 a[], INT first, INT last, SmsFilterType filter);
        void Swap(UINT16 & a, UINT16 & b);

        UINT16 * GetRecnoTable(SmsFilterType filter);
        INT      GetRecnoTableSize(SmsFilterType filter);
#endif

        MdhViewHdl m_viewhdl;
        UINT16     m_nvram_offset;

        INT     m_progress;
        BOOLEAN m_synchronized;
        BOOLEAN m_init_sub_system;
        BOOLEAN m_reloadinprogress;

        UINT16  m_tpdu_count;

#if defined(APOXI_SMS_NEW_PROVIDERS)
        UINT16  m_inbox_count;
        UINT16  m_outbox_count;
        UINT16  m_archive_count;
        UINT16  m_statusreport_count;
        UINT16  m_unread_count;

    #if defined(_DEBUG)
        UINT32 m_indexing_time;
        INT m_count_iteration;
        
        UINT32 m_sorttime_inbox;
        UINT32 m_sorttime_outbox;
        UINT32 m_sorttime_archive;
        UINT32 m_sorttime_status;
        UINT32 m_sorttime_unread;

        INT m_iteration_inbox;
        INT m_iteration_outbox;
        INT m_iteration_archive;
        INT m_iteration_status;
        INT m_iteration_unread;
    #endif
#else
        UINT16  m_read_count;
        UINT16  m_unread_count;
        UINT16  m_sent_count;
        UINT16  m_unsent_count;
#endif

        UINT16  m_max_count;
        UINT16  m_smsr_count;
        UINT16  m_smsr_offset;

        INT16 m_pdu_reload[c_max_reloadable_pdus];

        TpduCache * m_tpdu_cache;

        TpduCount m_count_table[NoOfCountTypes];

        static UINT8   m_max_conc_pdu_no;   
        static BOOLEAN m_csms_state_changeable;
        static UINT16  m_pdu_no_cache;
        static UINT16  m_no_cache_header;
        static UINT16  m_no_cache_chars;
        static BOOLEAN m_csms_pid_check_enabled;


        static const WCHAR * m_missing_part_text;

        static TpduHeaderInformation m_header_entries1[c_max_table1];
        static TpduHeaderInformation m_header_entries2[c_max_table2];
        static SmsrCache             m_smsr_cache[c_max_smsr_pdus];


        static UINT16 m_recnos[c_max_pdus];

#if defined(APOXI_SMS_NEW_PROVIDERS)
        static UINT16 m_inbox_recnos[c_max_pdus];
        static UINT16 m_outbox_recnos[c_max_pdus];
        static UINT16 m_archive_recnos[c_max_pdus];
        static UINT16 m_statusreport_recnos[c_max_pdus];
        static UINT16 m_unread_recnos[c_max_pdus];
#elif !defined(APOXI_DISABLE_FILTERED_SMS_PROVIDERS) 
        static UINT16 m_read_recnos[c_max_pdus];
        static UINT16 m_unread_recnos[c_max_pdus];
        static UINT16 m_sent_recnos[c_max_pdus];
        static UINT16 m_unsent_recnos[c_max_pdus];
#endif
        static UINT16 m_delete_recnos[c_max_pdus];
        static UINT16 m_csms_recs[c_default_max_pdu_per_sms+1];

        SmsWStringCache m_wstringcache;
};


#endif

