/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Gsm97_MdhTypes_hpp)
#define Apc_Gsm97_MdhTypes_hpp

#include <Apc/SignalTypes.hpp>
#include <Auxiliary/BitField.hpp>


typedef UINT8 MdhViewHdl;

#if defined(APOXI_SUPPORT_SMS_DELETION_CMD_GORS)
const MdhViewHdl c_undefined_view_handle = (MdhViewHdl)DR_UNDEFINED_VIEW;
#else
const MdhViewHdl c_undefined_view_handle = 0xFF;
#endif


enum MdhWorkMedia {
    MdhNoMedia          = DR_NONE,
    MdhOnlySim          = DR_ONLY_SIM,
    MdhOnlyNvram        = DR_ONLY_NVRAM,
    MdhPrefferedSim     = DR_PREFERRED_SIM,
    MdhPrefferedNvram   = DR_PREFERRED_NVRAM,
    MdhSharedMem        = DR_SHARED_MEM
};

enum MdhStatus {
    MdhSuccessful       = DR_SUCCESSFUL,
    MdhError            = DR_ERROR,
    MdhUndefined,
};

enum MdhCause {
    MdhNoCause                      = DR_NO_CAUSE,
    MdhFirstReached                 = DR_FIRST_REACHED,
    MdhLastReached                  = DR_LAST_REACHED,
    MdhNothingFound                 = DR_NOTHING_FOUND,
    MdhSmsrNotSaved                 = DR_SMSR_NOT_SAVED,
    MdhErrSmsrLinkNotFound          = DR_ERR_SMSR_LINK_NOT_FOUND,
    MdhErrSmsrNotAvailable          = DR_ERR_SMSR_NOT_AVAILABLE,
    MdhWarnMemoryExceeded           = DR_WARN_MEMORY_EXCEEDED,
    MdhRejStartupInProgress         = DR_REJ_STARTUP_IN_PROGRESS,
    MdhRejMemoryExceeded            = DR_REJ_MEMORY_EXCEEDED,
    MdhRejSimIsFull                 = DR_REJ_SIM_IS_FULL,
    MdhRejSimIsNotInView            = DR_REJ_SIM_IS_NOT_IN_VIEW,
    MdhRejSimNoSms                  = DR_REJ_SIM_NO_SMS,
    MdhRejLastView                  = DR_REJ_LAST_VIEW,
    MdhErrClientWasNotRegistered    = DR_ERR_CLIENT_WAS_NOT_REGISTERED,
    MdhErrNoEntriesFound            = DR_ERR_NO_ENTRIES_FOUND,
    MdhErrViewNotAvailable          = DR_ERR_VIEW_NOT_AVAILABLE,
    MdhErrOutOfRange                = DR_ERR_OUT_OF_RANGE,
    MdhErrOutOfView                 = DR_ERR_OUT_OF_VIEW,
    MdhErrMaxClients                = DR_ERR_MAX_CLIENTS,
    MdhErrMaxViews                  = DR_ERR_MAX_VIEWS,
    MdhErrIndexNotCreated           = DR_ERR_INDEX_NOT_CREATED,
    MdhErrFilterIsNotSupported      = DR_ERR_FILTER_IS_NOT_SUPPORTED,
    MdhErrStorageMedia              = DR_ERR_STORAGE_MEDIA,
    MdhErrNotEnoughMemory           = DR_ERR_NOT_ENOUGH_MEMORY,
    MdhErrParameters                = DR_ERR_PARAMETERS,
    MdhApplicationError             = DR_APPLICATION_ERROR,

#if defined(DR_WARN_SM_STORAGE_SIM_IS_FULL)
    MdhWarnSmStorageSimIsFull       = DR_WARN_SM_STORAGE_SIM_IS_FULL,
#else
    MdhWarnSmStorageSimIsFull,
#endif
#if defined(DR_SM_STORAGE_SIM_IS_FREE)
    MdhSmStorageSimIsFree           = DR_SM_STORAGE_SIM_IS_FREE,
#else
    MdhSmStorageSimIsFree,
#endif

#if defined(APOXI_SUPPORT_SMS_DELETION_CMD_GORS)
    MdhNothingToProcess             = DR_NOTHING_TO_PROCESS,
#else
    MdhNothingToProcess,
#endif
};

struct MdhResult {
    MdhStatus   status;
    MdhCause    cause;
};

struct TpduConc {
    T_PDU   pdu;
    UINT8   pdu_no;
    INT     next;
    INT     prev;
};

struct TpduNode {
    T_PDU       pdu;
    TpduNode    *next;
};

enum MdhSorting {
    MdhSortByPosition   = DR_SORT_BY_POSITION,
    MdhSortByDate       = DR_SORT_BY_DATE,
};

enum MdhFilter {
    MdhFilterUsed               = DR_FTR_USED,
    MdhFilterFree               = DR_FTR_FREE,
    MdhFilterAll                = DR_FTR_ALL,
    MdhFilterAllDisplay         = DR_FTR_ALL_DISPLAY,
    MdhFilterToBeRead           = DR_FTR_TO_BE_READ,
    MdhFilterRead               = DR_FTR_READ,
    MdhFilterInbox              = DR_FTR_INBOX,
    MdhFilterToBeSent           = DR_FTR_TO_BE_SENT,
    MdhFilterSent               = DR_FTR_SENT,
    MdhFilterOutbox             = DR_FTR_OUTBOX,
    MdhFilterUnknown            = DR_FTR_UNKNOWN,
    MdhFilterVoiceMsgWaiting    = DR_FTR_VOICE_MSG_WAITING,
    MdhFilterFaxWaiting         = DR_FTR_FAX_MSG_WAITING,
    MdhFilterEmailWaiting       = DR_FTR_EMAIL_MSG_WAITING,
    MdhFilterOtherMsgWaiting    = DR_FTR_OTHER_MSG_WAITING,
};

struct MdhViewConfig {
    MdhSorting      sort;
    MdhFilter       filter;
    MdhWorkMedia    storage;
};

enum MdhTransmitCause {
    MdhSmBoot         = DR_SM_BOOT,
    MdhSmSimReset     = DR_SM_SIM_RESET, 
    MdhSmSimtkRefresh = DR_SM_SIMTK_REFRESH,
    MdhSmUnknown      = DR_SM_UNKNOWN
};
enum MdhSmsrLocation {
    MdhSmsrNone     = DR_SR_NONE,
    MdhSmsrEf       = DR_SR_EF_SMSR,
    MdhNoSmsrEf     = DR_SR_NOT_EF_SMSR,
    MdhSharedMemory = DR_SR_SHARED_MEM,
    MdhRamBuffer    = DR_SR_RAM_BUFF
};

enum MdhWaitIndicatorLevel {
    MdhWaitLevel1    = DR_WAIT_LEVEL_1,
    MdhWaitLevel2    = DR_WAIT_LEVEL_2,
    MdhWaitLevel3    = DR_WAIT_LEVEL_3,
    MdhWaitLevelCphs = DR_WAIT_LEVEL_CPHS,
    MdhWaitLevelClient  = DR_WAIT_LEVEL_CLIENT,
    MdhWaitNoLevel   = DR_WAIT_NOLEVEL
};

enum MdhWaitIndicatorSetting {
    MdhWaitSetInactive = DR_WAIT_SET_INACTIVE,
    MdhWaitSetActive = DR_WAIT_SET_ACTIVE,
    MdhWaitSetUnknown = DR_WAIT_SET_UNKNOW,
};

enum MdhWaitIndicatorSmsType {
    MdhWaitSmsStore =   DR_WAIT_SMS_STORE,
    MdhWaitSmsDiscard = DR_WAIT_SMS_DISCARD,
    MdhWaitSmsUnknown = DR_WAIT_SMS_UNKNOWN
};

enum MdhWaitType {
    MdhVoiceMailMessage  = DR_WAIT_VOICEMAIL,
    MdhFaxMessage        = DR_WAIT_FAX,
    MdhEmailMessage      = DR_WAIT_EMAIL,
    MdhOtherMessage      = DR_WAIT_OTHER,
    MdhVoiceMail2Message = DR_WAIT_VOICEMAIL_2,
    MdhNofMdhWaitTypes   = DR_NU_WAIT_TYPES
};


struct MdhWaitIndicator {
    MdhWaitIndicatorLevel   level;
    UINT8                   count;
    MdhWaitIndicatorSetting setting;
    MdhWaitIndicatorSmsType smstype;
    BOOLEAN                 update;
    INT                     pos;
};


const INT c_undefined_pdu_pos = T_DR_UNDEFINED_POS;

struct MdhWaitIndicatorArray {
    MdhWaitIndicator val[MdhNofMdhWaitTypes];
};


struct MdhSetWaitIndicator {
    UINT8   count;
    BOOLEAN update;
};

class MdhSetWaitIndicatorArray 
{
    public:
        MdhSetWaitIndicatorArray() { memset(val,0,sizeof(val)); }
        void SetIndicator(MdhWaitType type, BOOLEAN update, UINT8 count = 0) {
            if((INT)type >= (INT)MdhVoiceMailMessage && (INT)type < (INT)MdhNofMdhWaitTypes) {
                val[type].update = update;
                val[type].count = count;
            }
        }
    MdhSetWaitIndicator val[MdhNofMdhWaitTypes];
};

#if defined(APOXI_SUPPORT_MOSMS_TIMESTAMP)
    typedef T_DR_TIME MdhTimeStamp;
    const MdhTimeStamp MdhInitTimeStamp = DR_INIT_MO_SM_TIME;
#else
    typedef UINT32 MdhTimeStamp;
    const MdhTimeStamp MdhInitTimeStamp = 0xFFFFFFFF;
#endif

// MdhExtendedData (ms.h T_DR_MMI_PROPERTY)
#if defined(APOXI_ENABLE_SMS_EXTENDED_DATA)
    const INT c_mdh_max_ext_data = DR_MAX_MMI_PROPERTY;
#else
    const INT c_mdh_max_ext_data = 4;
#endif

class MdhExtendedData {

    public:

        MdhExtendedData() { 
        
        #if defined(APOXI_ENABLE_SMS_EXTENDED_DATA)
            INT i = 0;
            for(i; i < c_mdh_max_ext_data; i++) {
                val[i] = DR_INIT_MMI_PROPERTY.A[i];
            }
        #else
            memset(val, 0, sizeof(val));
        #endif
        }

        MdhExtendedData & operator =(const MdhExtendedData &ext_data) {
            // prevent from self assignment
            if (&ext_data != this) {
                INT i = 0;
                for(i; i < c_mdh_max_ext_data; i++) {
                    val[i] = ext_data.val[i];
                }
            }
            return (*this);
        }

        UINT32 GetExtData() const{
            UINT32 data = 0;
            INT i = 0;
            for(i; i < c_mdh_max_ext_data; i++) {
                data |= val[i] << (8*i);
            }
            return data;
        }

        void SetExtData(UINT32 ext_data) {
            INT i = 0;
            for(i; i < c_mdh_max_ext_data; i++) {
                val[i] = (UINT8)(ext_data & 0xFF);
                ext_data >>= 8;
            }
        }

        UINT8 val[c_mdh_max_ext_data];
};

#define MdhInitExtendedData MdhExtendedData()


class MdhDeletionCmd 
{
    public:
        void SetRead(BOOLEAN value = TRUE) { val.SetBit(0,value); }
        void SetUnread(BOOLEAN value = TRUE) { val.SetBit(1,value); }
        void SetSent(BOOLEAN value = TRUE) { val.SetBit(2,value); }
        void SetUnsent(BOOLEAN value = TRUE) { val.SetBit(3,value); }
        void SetUnknown(BOOLEAN value = TRUE) { val.SetBit(4,value); }
        // bit 5 and 6 reserved
        void SetSmsr(BOOLEAN value = TRUE) { val.SetBit(7,value); }

        UINT8 Get() const { return val.Get(); } 

        BitField8 val;
};

class MdhGors 
{
    public:
        // default constructor
        MdhGors() : m_buffer(0), m_length(0) { } 


        // copy constructor
        MdhGors(const MdhGors & gors) : m_buffer(0), m_length(0) {
            if(! gors.IsEmpty()) {
                m_buffer = new UINT8[gors.m_length];    
                m_length = gors.m_length;
                memcpy(m_buffer,gors.m_buffer,gors.m_length);
            }
        } 

        // destructor
        ~MdhGors() { 
            delete[] m_buffer; m_length = 0; 
        } 

        // assignment operator
        MdhGors & operator = (const MdhGors & gors) {
            if(&gors!=this) {
                delete[] m_buffer; 
                m_length = 0; 
                if(! gors.IsEmpty()) {
                    m_buffer = new UINT8[gors.m_length];    
                    m_length = gors.m_length;
                    memcpy(m_buffer,gors.m_buffer,gors.m_length);
                }
            }
            return *this;
        }

        // is the PDU deleted (starting from 0 position) ?
        BOOLEAN IsPduDeleted(INT tpdupos) const {
            INT bytepos = tpdupos / 8;
            if(bytepos<m_length && m_buffer!=0) {
                BitField8 val(m_buffer[bytepos]);
                return val.GetBit(tpdupos % 8);
            }
            return FALSE;
        }

        // is the buffer empty ?
        BOOLEAN IsEmpty() const {
            return m_buffer==0 || m_length==0;
        }


        // copys data from buffer into object
        void Fill(const UINT8 * buffer, INT bufferlen) {
            delete[] m_buffer; 
            m_length = 0; 
            if(buffer!=0 && bufferlen>0) {
                m_buffer = new UINT8[bufferlen];    
                m_length = bufferlen;
                memcpy(m_buffer,buffer,bufferlen);
            }
        } 

    private:
        UINT8 * m_buffer;
        INT     m_length;
};


#endif


