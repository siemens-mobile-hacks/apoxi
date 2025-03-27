/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalTypes_hpp)
#define Apc_SignalTypes_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>

#include <Auxiliary/PhoneNumber.hpp>
#include <Auxiliary/WString.hpp>

#include <Apc/SsStatus.hpp>
#include <Apc/SsNotification.hpp>
#include <Apc/DataCodingScheme.hpp>

#include <stack/stack.h>

/*  ========================================================================
                                  SDL Types
    ========================================================================*/
typedef SDL_Integer SdlInteger;

typedef SDL_Character SdlCharacter;

typedef byte SdlByte;

typedef word SdlWord;

typedef ulong SdlUlong;

typedef SDL_Boolean SdlBoolean;
const SdlBoolean SdlTrue = SDL_True;
const SdlBoolean SdlFalse = SDL_False;

typedef SDL_PId ProcessId;


/*  ========================================================================
                                  Misc
    ========================================================================*/
typedef UINT8 SignalStrengthLevel;
typedef UINT8 SignalQualityLevel;
typedef UINT8 BatteryLoadLevel;

// ChargeEndReason (ms.h: T_CHR_CHARGE_END)
enum ChargeEndReason {
    ChargeEndBatteryFull = 0,
    ChargeEndChargerDisconnected = 1
};

// ChargeShutdownReason (ms.h: T_CHR_SHUTDOWN)
enum ChargeShutdownReason {
    ChargeShutdownBatteryEmpty = 0,
    ChargeShutdownBatteryIdError = 1
};

// sim error code (ms.h: T_SIM_ERROR_CODE)
typedef INT SimErrorCode;
const SimErrorCode c_sim_memory_error = (SimErrorCode)0x9240;
const SimErrorCode c_sim_security_error = (SimErrorCode)0x9804;
const SimErrorCode c_sim_secret_code_locked_error = (SimErrorCode)0x9804;

inline BOOLEAN IsSimMemoryError(SimErrorCode code) { return code==c_sim_memory_error; }
inline BOOLEAN IsSimSecurityError(SimErrorCode code) { return code==c_sim_security_error; }
inline BOOLEAN IsSimSecretCodeLockedError(SimErrorCode code) { return code==c_sim_secret_code_locked_error; }
inline BOOLEAN IsSimTechnicalProblemWithNoDiagnosticError(SimErrorCode code) { return ((UINT16)code & 0x6f00) == 0x6f00; }

const SignalStrengthLevel InvalidSignalStrengthLevel= 0xff;
const SignalQualityLevel  InvalidSignalQualityLevel= 0xff;

/*  ========================================================================
                                  PowerMode
    ========================================================================*/
enum PowerMode {
    PowerOffMode        = OM_MODE_POWER_OFF,    
    ChargerOnlyMode     = OM_MODE_CHARGE_ONLY,  
    NormalOnMode        = OM_MODE_ON,           
    SimulResetMode      = OM_MODE_SIMUL_RESET,  
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    AirplaneMode        = OM_MODE_AIRPLANE,
    PtstMode            = OM_MODE_PTST,
    SilentResetMode     = OM_SILENT_RESET,
    RegistrationMode    = OM_DEV_REGISTRATION
#else
    AirplaneMode,
    PtstMode,
    SilentResetMode,
    RegistrationMode
#endif
};

/*  ========================================================================
                                  Client
    ========================================================================*/

enum Client {
    MmiClient = MN_CLIENT_MMI,
    AtcClient = MN_CLIENT_ATC,
    NoClient  = MN_CLIENT_NONE
};

//
// SIM RELATED STUFF
//

/*  ========================================================================
                                  SimIndicator
    ========================================================================*/

enum SimIndicator {
    SimNotSet     = SI_SIM_NOT_SET,
    SimNotPresent = SI_SIM_NOT_PRESENT,
    SimPresent    = SI_SIM_PRESENT,
    SimError      = SI_SIM_ERROR,
    SimReady,           // SI_INIT_IND received and after SIM stuff is loaded
    SimFullAccess,      // SI_FULL_ACCESS_IND received 
    SimSmsReady,        // SI_SM_INIT_FINISHED_IND received
    SimUnblocked,       //SI_CHV_UNBLOCK_IND
    SimReadyForRegistration // SI_INIT_IND received 
};

/*  ========================================================================
                                  SimType
    ========================================================================*/

enum SimType {
    NormalSim          = NORMAL_SIM,
    NormalSpecialSim   = NORMAL_SPECIAL_SIM,
    ApprovalSim        = APPROVAL_SIM,
    ApprovalSpecialSim = APPROVAL_SPECIAL_SIM,
    ServiceCardSim     = SERVICE_CARD_SIM,
    CellTestSim        = CELL_TEST_SIM,
    NoCard             = NO_CARD
};

/*  ========================================================================
                                  SimInitResult
    ========================================================================*/

enum SimInitResult {
    NoOperation             = SI_NO_OPERATION,
    RestrictedOperation     = SI_RESTRICTED_OPERATION,
    UnrestrictedOperation   = SI_UNRESTRICTED_OPERATION,
    UndefinedOperation
};

/*  ========================================================================
                                  SimCallControlResult
    ========================================================================*/

enum SimCallControlResult {
    CcAllowed               = SI_CC_ALLOWED,
    CcNotAllowed            = SI_CC_NOT_ALLOWED,
    CcAllowedModified       = SI_CC_ALLOWED_MODIFIED,
    CcToolkitBusy           = SI_CC_TK_BUSY,
    CcSimError              = SI_CC_SIM_ERROR
};

/*  ========================================================================
                                  SimSsType
    ========================================================================*/

enum SimSsType {
    SiSsType                = SI_SS_TYPE,
    SiUssdTypeEarlyUsage    = SI_USSD_TYPE_EARLY_USAGE,
    SiUssdType              = SI_USSD_TYPE,
    SiNoSsType              = SI_NO_SS_TYPE,
    SiDtmfType              = SI_DTMF_TYPE
};

/*  ========================================================================
                                  SimPhase
    ========================================================================*/

typedef UINT8 SimPhase;

/*  ========================================================================
                                  SimFileType
    ========================================================================*/

enum SimFileType {
    TransparentFile = SI_TRANSPARENT,
    LinearFixedFile = SI_LINEAR_FIXED,
    CyclicFile = SI_CYCLIC,
};

/*  ========================================================================
                                  SimUpdateStatus
    ========================================================================*/

// Sim read update status (ms.h: T_SI_RD_UPD_STATUS)
enum SimUpdateStatus {
   Successfull                  = SI_SUCCESSFUL,            // 'SI_SUCCESSFUL'           OK
   Unsuccessfull                = SI_UNSUCCESSFUL,          // 'SI_UNSUCCESSFUL'         SI-detected 
   SimMemRetrySuccess           = SI_MEM_RETRY_SUCCESS,     // 'SI_MEM_RETRY_SUCCESS'    92 0x 
   MemoryError                  = SI_MEMORY_ERROR,          // 'SI_MEMORY_ERROR'         92 40 
   SimToolkitBusy               = SI_TOOLKIT_BUSY,          // 'SI_TOOLKIT_BUSY'         93 00 
   SimNoEfChoosen               = SI_NO_EF_CHOOSEN,         // 'SI_NO_EF_CHOOSEN'        94 00 
   SimInvalidAddress            = SI_INVALID_ADDRESS,       // 'SI_INVALID_ADDRESS'      94 02 
   ReferenceError               = SI_REFERENCE_ERROR,       // 'SI_REFERENCE_ERROR'      94 04 
   SimInconsistentCmd           = SI_INCONSISTENT_CMD,      // 'SI_INCONSISTENT_CMD'     94 08 
   SimNoChvInitialized          = SI_NO_CHV_INITIALIZED,    // 'SI_NO_CHV_INITIALIZED'   98 02 
   SecurityError                = SI_SECURITY_ERROR,        // 'SI_SECURITY_ERROR'       98 04 
   SimContradictWithChvState    = SI_CONTRADICT_CHV_STATE,  // 'SI_CONTRADICT_CHV_STATE' 98 08 
   SimContradictInvalidState    = SI_CONTRADICT_INVALID_STATE,  // 'SI_CONTRADICT_INVALID_STATE' 98 10
   SimNoAttemptLeft             = SI_NO_ATTEMPT_LEFT,       // 'SI_NO_ATTEMPT_LEFT'      98 40
   MaxValueReached              = SI_MAX_VALUE_REACHED,     // 'SI_MAX_VALUE_REACHED'    98 50
   SimToolkitResponeError       = SI_TK_RESPONSE_ERROR,     // 'SI_TK_RESPONSE_ERROR'    9E XX
   SimApplicationErrorP3        = SI_APP_ERR_P3,            // 'SI_APP_ERR_P3'           67 XX 
   SimApplicationErrorP1P2      = SI_APP_ERR_P1_P2,         // 'SI_APP_ERR_P1_P2'        6B XX 
   SimUnknownInstruction        = SI_UNKNOWN_INSTRUCTION,   // 'SI_UNKNOWN_INSTRUCTION'  6D XX
   SimWrongInstructionClass     = SI_WRONG_INSTR_CLASS,     // 'SI_WRONG_INSTR_CLASS'    6E XX 
   SimTechnicalProblem          = SI_TECHNICAL_PROBLEM,     // 'SI_TECHNICAL_PROBLEM'    6F XX 
   ApplicationError             = SI_APPLICATION_ERROR,     // 'SI_APPLICATION_ERROR'    other SIM-error 
   NotActivated                 = SI_NOT_ACTIVATED,         // 'SI_NOT_ACTIVATED'        unused 
   MemoryExceeded               = SI_MEMORY_EXCEEDED,       // 'SI_MEMORY_EXCEEDED'      no free record 
   SimExtMemoryExceeded         = SI_EXT_MEMORY_EXCEEDED,   // 'SI_EXT_MEMORY_EXCEEDED'  no free ext rec
   CannotReplaceSms             = SI_CANNOT_REPLACE_SMS,    // 'SI_CANNOT_REPLACE_SMS'   unused 
// When read beyond file end allowed by SI and happened e.g. for (IMG-data, SIM-lock data): 
   SimSuccessBeyondEnd          = SI_SUCCESS_BEYOND_END,    // 'SI_SUCCESS_BEYOND_END' 
// no valid extension record id was found in the phonebook: 
   SuccessInvalidExt            = SI_SUCCESS_INVALID_EXT,   // 'SI_SUCCESS_INVALID_EXT' 
   Undefined,
};

/*  ========================================================================
                                  SimRefreshType
    ========================================================================*/

// Sim refresh type (ms.h: T_SI_REFRESH_TYPE)
enum SimRefreshType {
    SmsRefresh          = SI_SMS_REFRESH,
    PhoneBookRefresh    = SI_PHONEBOOK_REFRESH,
    SmsParameterRefresh = SI_SMSP_REFRESH,
    CcpRefresh          = SI_CCP_REFRESH,
    EccpRefresh         = SI_ECCP_REFRESH,
    FileRefresh         = SI_FILE_REFRESH,
    PlmnRefresh         = SI_PLMN_REFRESH,
    AocRefresh          = SI_AOC_REFRESH,
    UndefinedRefreshType,
};

/*  ========================================================================
                                  PlmnUpdateType
    ========================================================================*/

// Plmn update command types (ms.h: T_SI_ACTION)
enum PlmnUpdateType {
    InsertPlmnAction   = SI_INSERT,
    DeletePlmnAction   = SI_DELETE,
    DeleteAllPlmnAction = SI_DELETE_ALL
};

/*  ========================================================================
                                  PhoneBookType
    ========================================================================*/

enum PhoneBookType {
    AdnPhoneBook        = SI_EF_ADN,
    FdnPhoneBook        = SI_EF_FDN,
    LndPhoneBook        = SI_EF_LND,
    MsisdnPhoneBook     = SI_EF_MSISDN,
    CphsMBoxPhoneBook   = SI_EF_CPHS_MBOX,
    SdnPhoneBook        = SI_EF_SDN,             
    BdnPhoneBook        = SI_EF_BDN,  
    CphsInfoNoPhoneBook = SI_EF_CPHS_INFNUM,
    MbdnPhoneBook       = SI_EF_MBDN
};

/*  ========================================================================
                                  PhoneBookType
    ========================================================================*/

enum PhoneBookCntType {
    AdnPhoneBookCnt         = SI_PHB_ADN,
    FdnPhoneBookCnt         = SI_PHB_FDN,
    LndPhoneBookCnt         = SI_PHB_LND,
    MsisdnPhoneBookCnt      = SI_PHB_MSISDN,
    CphsMBoxPhoneBookCnt    = SI_PHB_CPHS_MBOX,
    SdnPhoneBookCnt         = SI_PHB_SDN,             
    BdnPhoneBookCnt         = SI_PHB_BDN,  
    CphsInfoNoPhoneBookCnt  = SI_PHB_CPHS_INFNUM,
    MbdnPhoneBookCnt        = SI_PHB_MBDN,
    CfisPhoneBookCnt        = SI_PHB_CFIS,
    Ext1PhoneBookCnt        = SI_PHB_EXT1,
    Ext2PhoneBookCnt        = SI_PHB_EXT2,
    Ext4PhoneBookCnt        = SI_PHB_EXT4,
    Ext6PhoneBookCnt        = SI_PHB_EXT6,
    Ext7PhoneBookCnt        = SI_PHB_EXT7,
    InvalidPhoneBookCnt     = -1
};


/*  ========================================================================
                                  PhoneBookInfo
    ========================================================================*/

struct PhoneBookInfo {
    INT adn_size;
    INT adn_tagsize;
    INT msisdn_size;
    INT msisdn_tagsize;
    INT fdn_size;
    INT fdn_tagsize;
    INT lnd_size;
    INT lnd_tagsize;
    INT cphs_mbox_size;
    INT cphs_mbox_tagsize;
    INT sdn_size;
    INT sdn_tagsize;
    INT bdn_size;
    INT bdn_tagsize;
    INT cphs_infono_size;
    INT cphs_infono_tagsize;
    INT mbdn_size;              // this is not delivered by info request -> fileinfo
    INT mbdn_tagsize;           // this is not delivered by info request -> fileinfo
};

/*  ========================================================================
                                  SimPhoneBookEntry
    ========================================================================*/

const INT c_max_size_telephone_nr = MN_MAX_TEL_NUMBER;  // 23

const INT c_max_phonebook_entry_len = 128;

class SimPhoneBookEntry 
{
    public: 
        SimPhoneBookEntry() : m_length(0), m_data(0) { }

        SimPhoneBookEntry(const SimPhoneBookEntry & entry) : m_length(0), m_data(0) { 
            if(entry.m_length>0) {
                m_data = new UINT8[entry.m_length]; 
                if(m_data!=0) {
                    m_length = entry.m_length; 
                    memcpy(m_data,entry.m_data,m_length);
                }
            }
        }

        ~SimPhoneBookEntry() { 
            m_length = 0; 
            delete[] m_data; 
            m_data = 0;
        }

        void Push(INT length, const UINT8 * data) { 
            m_data = new UINT8[length]; 
            if(m_data!=0) {
                m_length = length; 
                memcpy(m_data,data,length);
            }
        }

        INT     m_length;
        UINT8 * m_data;
};

/*  ========================================================================
                                  SimCmiAlphaId
    ========================================================================*/

const INT c_max_cmi_alpha_id_size = 40;     // sizeof(T_SI_CMI_DATA); 

struct CmiRecord {
    INT   alphaidlength;
    UINT8 alphaid[c_max_cmi_alpha_id_size];
    UINT8 cmi;
};

 
/*  ========================================================================
                                  SmsParamRecord
    ========================================================================*/

const INT c_max_smsparam_entry_len = 64;

struct SmsParamRecord {
    UINT8  val[c_max_smsparam_entry_len];
    INT    length;
};

/*  ========================================================================
                                  SmsMoreMessageType
    ========================================================================*/

enum SmsMoreMessageType {
    SmsDisableMoreMessages                  = DISABLE_MORE_MESSAGES,
    SmsEnableMoreMessagesUntilTimerExpiry   = ENABLE_MORE_MESSAGES_UNTIL_TIMER_EXPIRY,
    SmsEnableMoreMessages                   = ENABLE_MORE_MESSAGES_PERMANENTLY,
    SmsUndefinedMoreMessages               
};


/*  ========================================================================
                                  ChvStatus
    ========================================================================*/

enum ChvStatus {
    NotAvailable                    = SI_CHV_NOT_AVAILABLE,
    Needed                          = SI_CHV_NEEDED,
    NotNeeded                       = SI_CHV_NOT_NEEDED,
    Blocked                         = SI_CHV_BLOCKED,
    UnblockingBlocked               = SI_CHV_UNBL_BLOCKED,
    Verified                        = SI_CHV_VERIFIED,
    Rejected                        = SI_CHV_REJECTED,
    InContradictionWithChvStatus    = SI_CHV_IN_CONTRADICTION_WITH_CHV_STATUS,
    TransactionFailed,              // transaction failed (no respond message retrieved)
    DataNotInitialized ,            // chv data is not jet initialized
    TranscationNotSupported         // transaction is not supported for this chv
    
};

/*  ========================================================================
                                  ChvNo
    ========================================================================*/

enum ChvNo {
    Chv1 = SI_CHV1,
    Chv2 = SI_CHV2,
    Alw  = SI_ALW,
    Rfu  = SI_RFU,
    Adm  = SI_ADM,
    Nev  = SI_NEV,
};


const INT c_max_chvs = 6;   // must be identic to the number of enums of the type AdcChvNo

// cardholder verification attempts
typedef UINT8 ChvAttempts;


/*  ========================================================================
                                  ChvAttemptsStruct
    ========================================================================*/
// attempts left (ms.h: T_SI_CHV_ATTEMPTS)

struct ChvAttemptsStruct {
    ChvAttempts  chv1AttemptsLeft;
    ChvAttempts  chv2AttemptsLeft;
    ChvAttempts  chv1UnblAttemptsLeft;
    ChvAttempts  chv2UnblAttemptsLeft;
};

/*  ========================================================================
                                  ChvData
    ========================================================================*/

struct ChvData {
    ChvNo       no;
    ChvStatus   status;
    ChvAttempts attempts_left;
    ChvAttempts unblocking_attempts_left;
};

/*  ========================================================================
                                  ChvAction
    ========================================================================*/

enum ChvAction {
    Chv1Enable = SI_CHV1_ENABLE_CMD,
    Chv1Disable = SI_CHV1_DISABLE_CMD,
    ChvVerify  = SI_CHV_VERIFY_CMD,
    ChvUnblock  = SI_CHV_UNBLOCK_CMD,
    ChvChange  = SI_CHV_CHANGE_CMD,
};

/*  ========================================================================
                                  LociData
    ========================================================================*/

struct LociData {
    UINT8 val[11];
};

/*  ========================================================================
                                  LocationUpdateStatus
    ========================================================================*/

enum LocationUpdateStatus {
    LociUpdated = 0,
    LociNotUpdated = 1,
    LociPlmnNotAllowed = 2,
    LociLocAreaNotAllowed  = 3,
    LociReserved = 7
};

/*  ========================================================================
                                  CbmiData
    ========================================================================*/
// (ms.h: T_SI_CBMI_DATA)

struct CbmiData {
    UINT8 val[2];
};

/*  ========================================================================
                                  CbmiRange
    ========================================================================*/
// (ms.h: T_SI_CBMI_RANGE)

struct CbmiRange {
    UINT16 low;
    UINT16 high;
};

/*  ========================================================================
                                  Language
    ========================================================================*/

typedef UINT8 Language;
const Language InvalidLanguage = 0xff;

// for internal use only
const INT c_sizeof_languagearray = 5;
const INT c_no_of_languages_array = 5;

// language orginal T_SI_LANG_LIST
struct LanguageArray {
    UINT8 val[c_sizeof_languagearray];
};

/*  ========================================================================
                                  ExtLanguage
    ========================================================================*/

// language orginal T_SI_EXT_LANG
struct ExtLanguage {
    UINT8 val[2];
    WString GetWString() const {
        WCHAR temp[3] = { 0, 0, 0 };
        if(val[0]!=0xFF && val[1]!=0xFF) {
            temp[0] = val[0];
            temp[1] = val[1];
        }
        return WString(temp);
    }
    void Set(const WString & str) {
        if(str.GetLength()==2) {
            val[0] = ((UINT8)str[0]) & 0x7F;
            val[1] = (UINT8)str[1] & 0x7F;
        } else {
            val[0] = 0xFF;
            val[1] = 0xFF;
        }
    }
};

const UINT16 InvalidExtLanguageVal = 0xffff;
const ExtLanguage InvalidExtLanguage = { 0xff, 0xff };

// for internal use only
const INT c_sizeof_extlanguagearray = 10;
const INT c_no_of_extlanguages_array = 5;

// language orginal T_SI_EXT_LANG_LIST
struct ExtLanguageArray {
    UINT8 val[c_sizeof_extlanguagearray];
};

/*  ========================================================================
                                  IccId
    ========================================================================*/

struct IccId {
    UINT8 val[10];
};

/*  ========================================================================
                                  SmsStatus
    ========================================================================*/

struct SmsStatus {
    UINT8 lastused;
    UINT8 notification;
};

/*  ========================================================================
                                  AcmSelector
    ========================================================================*/
enum AcmSelector {
    Acm1 = SI_ACM_1,
    Acm2 = SI_ACM_2,
};

/*  ========================================================================
                                  Acm
    ========================================================================*/

// Acm (ms.h: T_SI_ARR_3)
struct Acm {
    UINT8 val[3];
};

const Acm InvalidAcm = { 0xFF, 0xFF, 0xFF };

/*  ========================================================================
                                  Puct
    ========================================================================*/

// Puct (ms.h: T_SI_PUCT_DATA)
struct Puct {
    UINT8 val[5];
};

const Puct InvalidPuct = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };


/*  ========================================================================
                                  Imsi
    ========================================================================*/
// Imsi (ms.h: T_IMSI)
struct Imsi {
    UINT8 val[9];
};

/*  ========================================================================
                                  Imei
    ========================================================================*/
// Imei (ms.h: T_IMEI)
struct Imei {
    UINT8 val[10];
};

const Imei InvalidImei = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

/*  ========================================================================
                                  EmlppPriorityLevel
    ========================================================================*/
enum EmlppPriorityLevel {
    EmlppPriorityLevelA = 0,
    EmlppPriorityLevelB = 1,
    EmlppPriorityLevel0 = 2,
    EmlppPriorityLevel1 = 3,
    EmlppPriorityLevel2 = 4,
    EmlppPriorityLevel3 = 5,
    EmlppPriorityLevel4 = 6,
    EmlppPriorityLevelVoid
};

/*  ========================================================================
                                  SimServiceTable
    ========================================================================*/
// Sst (ms.h: T_SI_SST)
struct SimServiceTable {
    UINT8 val[16];
};


const INT c_max_sst_services = sizeof(SimServiceTable) * 4;    // stack defined, per UINT8 4 services

const SimServiceTable InvalidSimServiceTable = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/*  ========================================================================
                                  CcpData
    ========================================================================*/

// (ms.h: T_SI_CCP_DATA)
struct CcpData {
    UINT8 val[14];
};

const CcpData InvalidCcpData = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                                 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };


/*  ========================================================================
                                  EccSource 
    ========================================================================*/
enum EccSource {
    EccSourceSim,
    EccSourceNetwork,
    EccSourceBuiltin,
    EccSourceCustomized
};

/*  ========================================================================
                                  EccArray
    ========================================================================*/

// (ms.h: T_SI_ECC_ARRAY)
struct EccArray {
    UINT8 length;
    UINT8 val[15];
};

const EccArray InvalidEccArray = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/*  ========================================================================
                                  Ecc Network Handling Types
    ========================================================================*/

const INT c_max_ecc_network_number_length = 6;

// (ms.h: T_MN_ECC_NW_NUMBER)
struct EccNetworkNumber {
    UINT8 val[c_max_ecc_network_number_length];
};

// (ms.h: T_MN_ECC_NW_LIST_NUMBERS_ELEMENT)
struct EccNetworkElement {
    UINT8            m_category;
    EccNetworkNumber m_number;
};

const INT c_max_ecc_network_elements = 10;

// derived from T_MN_ECC_NW_LIST 
struct EccNetworkArray {
    EccNetworkElement m_elements[c_max_ecc_network_elements];
    INT               m_number;
};

/*  ========================================================================
                                  EccCategory
    ========================================================================*/
class EccCategory 
{
    public:
        EccCategory() {};
        EccCategory(UINT8 value) : m_val(value) {};
        EccCategory(const EccCategory & cat) : m_val(cat.GetValue()) {};
        
        BOOLEAN IsPolice() const { return m_val.GetBit(0); }
        BOOLEAN IsAmbulance() const { return m_val.GetBit(1); }
        BOOLEAN IsFireBrigade() const { return m_val.GetBit(2); }
        BOOLEAN IsMarineGuard() const { return m_val.GetBit(3); }
        BOOLEAN IsMountainRescue() const { return m_val.GetBit(4); }
        UINT8 GetValue() const { return m_val.Get(); }
        void SetValue(UINT8 value) { m_val.Set(value); }

        EccCategory & operator =(const EccCategory &cat)
        {
            if (&cat != this) {     // guard from self assignment
                m_val.Set(cat.GetValue());
            }
            return (*this);
        }

    private:
        BitField8 m_val;

};

/*  ========================================================================
                                  ServiceProviderStruct
    ========================================================================*/

struct ServiceProviderStruct {
    UINT8 dsplcond;
    UINT8 name[16];
};

const ServiceProviderStruct InvalidSpn = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/*  ========================================================================
                                  SimData
    ========================================================================*/
// (ms.h: T_SI_DATA)

struct SimData {
    UINT8 val[32];
};

/*  ========================================================================
                                  SmsrData
    ========================================================================*/
// (ms.h: T_SI_SMSR_DATA)

struct SmsrData {
    UINT8 val[29];
};

typedef BOOLEAN ExtIndicator;

/*  ========================================================================
                                  SimFileId
    ========================================================================*/

typedef UINT16 SimFileId;

/*  ========================================================================
                                  SimApdu
    ========================================================================*/

struct SimApdu {
    UINT8 val[261];
};

/*  ========================================================================
                                  SimApduData
    ========================================================================*/

struct SimApduData {
    SimApduData() : length(0) {}

    INT     length;
    SimApdu apdu;
};

/*  ========================================================================
                                  SimDfParameters
    ========================================================================*/

struct SimDfParameters {
    UINT8 val[36];
};

/*  ========================================================================
                                  SimEfParameters
    ========================================================================*/

struct SimEfParameters {
    UINT8 val[17];
};

/*  ========================================================================
                                  SimEfOrangeParam
    ========================================================================*/

struct SimEfOrangeParam {
    UINT8 val[37];
};

const INT c_size_of_orange_param = 37;

/*  ========================================================================
                                  LineSelector
    ========================================================================*/

enum LineSelector {
//
    Line1 = MN_SPEECH,
    //
    Line2 = MN_AUXILIARY_SPEECH,
    //
    InvalidLine
};

/*  ========================================================================
                                  CphsIstArray
    ========================================================================*/

// T_SI_CPHS_IST_ARRAY
struct CphsIstArray {
    UINT8 val[8];
};

/*  ========================================================================
                                  CphsVmwfArray
    ========================================================================*/

// T_SI_CPHS_VMWF_ARRAY
struct CphsVmwfArray {
    UINT8 val[2];
};

/*  ========================================================================
                                  CphsCfufArray
    ========================================================================*/

// T_SI_CPHS_CFUF_ARRAY
struct CphsCfufArray {
    UINT8 val[2];
};

/*  ========================================================================
                                  CphsOnmName
    ========================================================================*/

// T_SI_CPHS_ONM_ARRAY
struct CphsOnmName {
    UINT8 val[40];
};

/*  ========================================================================
                                  CphsOnsName
    ========================================================================*/

// T_SI_CPHS_ONS_ARRAY
struct CphsOnsName {
    UINT8 val[10];
};

/*  ========================================================================
                                  CphsCspArray
    ========================================================================*/

// T_SI_CPHS_CSP_ARRAY
struct CphsCspArray {
    UINT8 val[22];
};



//
// USIM RELATED STUFF
//

/*  ========================================================================
                                 SimCardType
    ======================================================================== */

enum SimCardType {
    Sim2G   =   0,  // UICCAP_CARD_TYPE_2G
    Sim3G   =   1,  // UICCAP_CARD_TYPE_3G
};

/*  ========================================================================
                                 UsimReadType
    ======================================================================== */

enum UsimReadType {
#if defined(APOXI_ICC_USIM)
    UsimReadNull = USIMAP_READ_NULL,
    UsimReadCurrUsim = USIMAP_READ_CURR_USIM,
    UsimReadCardType = USIMAP_READ_CARD_TYPE,
    UsimReadImsi = USIMAP_READ_IMSI,
    UsimReadAcc = USIMAP_READ_ACC,
    UsimReadStartHfn = USIMAP_READ_START_HFN,
    UsimReadHfnThreshold = USIMAP_READ_HFN_THRESHOLD,
    UsimReadCpbcch = USIMAP_READ_CPBCCH,
    UsimReadInvScan = USIMAP_READ_INV_SCAN,
    UsimReadHplmnTmr = USIMAP_READ_HPLMN_TMR,
    UsimReadRplmnAct = USIMAP_READ_RPLMN_ACT,
    UsimReadFplmn = USIMAP_READ_FPLMN,
    UsimReadPlmn = USIMAP_READ_PLMN_LIST,
    UsimReadOplmn = USIMAP_READ_OPLMN_LIST,
    UsimReadHplmn = USIMAP_READ_HPLMN_LIST,
    UsimReadCsLoci = USIMAP_READ_CS_LOCI,
    UsimReadPsLoci = USIMAP_READ_PS_LOCI,
    UsimReadGsmCiphKey = USIMAP_READ_GSM_CIPH_KEY,
    UsimReadGprsCiphKey = USIMAP_READ_GPRS_CIPH_KEY,
    UsimReadCsCiphKey = USIMAP_READ_CS_CIPH_KEY,
    UsimReadPsCiphKey = USIMAP_READ_PS_CIPH_KEY,
    UsimReadAcmInfo = USIMAP_READ_ACM_INFO,
    UsimReadAcmMax = USIMAP_READ_ACM_MAX,
    UsimReadPuct = USIMAP_READ_PUCT,
    UsimReadSpn = USIMAP_READ_SPN,
    UsimReadDck = USIMAP_READ_DCK,
    UsimReadUst = USIMAP_READ_UST,
    UsimReadEst = USIMAP_READ_EST,
    UsimReadCbmi = USIMAP_READ_CBMI_LIST,
    UsimReadCbmid = USIMAP_READ_CBMID_LIST,
    UsimReadCbmir = USIMAP_READ_CBMIR_LIST,
    UsimReadCcp2 = USIMAP_READ_CCP2,
    UsimReadBcch =USIMAP_READ_BCCH,
    UsimReadPlmnSel = USIMAP_READ_PLMNSEL,
    UsimReadLangDefault = USIMAP_READ_LANG_DEFAULT,
    UsimReadLangPl = USIMAP_READ_LANG_PL,
    UsimReadLangLi = USIMAP_READ_LANG_LI,
    UsimReadLangElp = USIMAP_READ_LANG_ELP,
    UsimReadLangLp = USIMAP_READ_LANG_LP,
    UsimReadLangEcc = USIMAP_READ_ECC
#else
    UsimReadNull = 0
#endif
};


/*  ========================================================================
                                 UsimUpdateAction
    ======================================================================== */
enum UsimUpdateAction {
#if defined(APOXI_ICC_USIM)
    UsimUpdateInsert = USIMAP_UPDATE_INSERT,
    UsimUpdateOverwrite = USIMAP_UPDATE_OVERWRITE,
    UsimUpdateDelete = USIMAP_UPDATE_DELETE,
    UsimUpdateDeleteAll = USIMAP_UPDATE_DELETE_ALL,
#else
    UsimUpdateInsert = 0
#endif
};

/*  ========================================================================
                                 UsimFileProperty
    ======================================================================== */

struct UsimFileProperty {
    SimFileType m_filetype;
    INT         m_filesize;
    INT         m_recordcount;
    INT         m_recordsize;
    ChvNo       m_readchv;
    ChvNo       m_updatechv;
};

/*  ========================================================================
                                 UsimUst
    ======================================================================== */

#if ! defined(USIMAP_SERVICE_TABLE_LEN)
    #define USIMAP_SERVICE_TABLE_LEN 16
#endif

struct UsimUst {
    UINT8 val[USIMAP_SERVICE_TABLE_LEN];    
};

/*  ========================================================================
                                 UsimEst
    ======================================================================== */

struct UsimEst {
    UINT8 val[USIMAP_SERVICE_TABLE_LEN];    
};


/*  ========================================================================
                                 PsLociData
    ======================================================================== */

struct PsLociData {
    UINT8 val[14];  
};

/*  ========================================================================
                                 UsimLangFileType
    ======================================================================== */

enum UsimLangFileType {
#if defined(APOXI_ICC_USIM)
    UsimLangDefault = LANG_FILE_DEFAULT,
    UsimLangPl      = LANG_FILE_PL,
    UsimLangLi      = LANG_FILE_LI,
    UsimLangElp     = LANG_FILE_ELP,
    UsimLangLp      = LANG_FILE_LP
#else
    UsimLangDefault = 0
#endif

};

/*  ========================================================================
                                 UsimLanguage
    ======================================================================== */

// language orginal T_USIMAP_LANG
struct UsimLanguage {
    UINT8 val[2];
    WString GetWString() const {
        WCHAR temp[3] = { 0, 0, 0 };
        if(val[0]!=0xFF) {
            temp[0] = val[0];
            if(val[1]!=0xFF) {
                temp[1] = val[1];
            }
        }
        return WString(temp);
    }
    void Set(const WString & str) {
        if(str.GetLength()>=1) {
            val[0] = ((UINT8)str[0]) & 0x7F;
            if(str.GetLength()>=2) {
                val[1] = (UINT8)str[1] & 0x7F;
            } else {
                val[1] = 0xFF;
            }
        } else {
            val[0] = 0xFF;
        }
    }
};

#if ! defined(USIMAP_LANG_LIST_LEN)
    #define USIMAP_LANG_LIST_LEN 10
#endif

const INT c_maxno_usim_langs = USIMAP_LANG_LIST_LEN;

// language request T_USIMAP_LANG_LIST
struct UsimLanguageList {
    UsimLanguage val[c_maxno_usim_langs];
};

/*  ========================================================================
                                 UsimEccRecord
    ======================================================================== */

#if ! defined(USIMAP_ALPHA_LEN)
    #define USIMAP_ALPHA_LEN 32
#endif

// structure defined in SI_READ_ECC_CNF
struct UsimEccRecord {
    UINT8  ecc[3];
    UINT16 length;
    UINT8  alphaid[USIMAP_ALPHA_LEN];
    UINT8  category;
};

/*  ========================================================================
     CfuServices 
    ======================================================================== */
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)

enum CfuDataSource {    // T_MN_CFU_DATA_SOURCE  
    CfuDataSourceInvalid = MN_CFU_SRC_VOID, 
    CfuDataSourceCphs = MN_CFU_SRC_SIM_CPHS,        
    CfuDataSourceCfis = MN_CFU_SRC_SIM_EF_CFIS,     
    CfuDataSourceNvram = MN_CFU_SRC_NVRAM,
    CfuDataSourceNetwork = MN_CFU_SRC_NETWORK
};  

enum CfuServiceCode {   // T_MN_CFU_OP_CODE 
    CfuInvalid = MN_CFU_OP_CODE_VOID,   
    CfuActivated = MN_CFU_OP_CODE_SET,      
    CfuDeactivated = MN_CFU_OP_CODE_RESET
};  

enum CfuArrayIndex {
    CfuTelephony = MN_CFU_TELEPHONY,    
    CfuTelephonyLine2 = MN_CFU_TELEPHONY_L2,        
    CfuFax = MN_CFU_FAX,
    CfuData = MN_CFU_DATA,

    CfuArrayAccessMaxLines = MN_CFU_MAX_SERVICES    // == 4
};  
#else
enum CfuDataSource {
    CfuDataSourceInvalid,   
    CfuDataSourceCphs,      
    CfuDataSourceCfis,      
    CfuDataSourceNvram,
    CfuDataSourceNetwork    
};
enum CfuServiceCode {
    CfuInvalid, 
    CfuActivated,       
    CfuDeactivated
};  
enum CfuArrayIndex {
    CfuTelephony,   
    CfuTelephonyLine2,      
    CfuFax,
    CfuData,
    CfuArrayAccessMaxLines  // == 4
};  

#endif

class CfuService 
{
    public:
        CfuService() : m_servicecode(CfuInvalid) {} 
        CfuService(const CfuService & service) 
            : m_servicecode(service.m_servicecode), 
              m_forwardno(service.m_forwardno)  {}  

        CfuService & operator =(const CfuService &service)
        {
            if (&service != this) {     // guard from self assignment
                m_servicecode = service.m_servicecode;
                m_forwardno = service.m_forwardno;
            }
            return (*this);
        }
        void Set(CfuServiceCode servicecode, const PhoneNumber & phno) {
            m_servicecode = servicecode;
            m_forwardno = phno;
        }
        CfuServiceCode GetCfuServiceCode() const { return m_servicecode; }
        const PhoneNumber & GetForwardPhoneNumber() const { return m_forwardno; }
        
    private:
        CfuServiceCode m_servicecode;
        PhoneNumber    m_forwardno;
};

class CfuServiceArray 
{
    public:
        CfuServiceArray() : m_source(CfuDataSourceInvalid) { }

        CfuServiceArray(const CfuServiceArray & array) {
            m_source = array.m_source;
            for(INT i=0; i<CfuArrayAccessMaxLines; i++) {
                m_val[i] = array.m_val[i];
            }
        }
        
        CfuServiceArray & operator =(const CfuServiceArray &array)
        {
            if (&array != this) {       // guard from self assignment
                m_source = array.m_source;
                for(INT i=0; i<CfuArrayAccessMaxLines; i++) {
                    m_val[i] = array.m_val[i];
                }
            }
            return (*this);
        }

        // merge the new array over the existing, means only changed values are set
        void Merge(const CfuServiceArray &array)
        {
            m_source = array.m_source;
            for(INT i=0; i<CfuArrayAccessMaxLines; i++) {
                if(array.m_val[i].GetCfuServiceCode()!=CfuInvalid) {
                    m_val[i] = array.m_val[i];
                }
            }
        }

        // dumps out the content for debugging reasons
        void DbgOut() const
        {
#if defined(_DEBUG)
            DBG_OUT((0," Source(%d) ",m_source));
            for(INT i=0; i<CfuArrayAccessMaxLines; i++) {
                DBG_OUT((0,"%d=Code(%d) ",i,m_val[i].GetCfuServiceCode()));
            }
#endif
        }

        const CfuService & GetCfuService(CfuArrayIndex idx) const { 
            ASSERT_DEBUG(idx<CfuArrayAccessMaxLines);
            return m_val[idx];
        }
        CfuDataSource GetCfuDataSource() const { return m_source; }

        CfuDataSource  m_source;
        CfuService     m_val[CfuArrayAccessMaxLines];
};




//
// AT RELATED STUFF
//

/*  ========================================================================
                                  PbRequestBehaviour 
    ========================================================================*/

enum PbRequestBehaviour  {
    PbRequestEmpty,
    PbRequestAutomatic,
    PbRequestMMI            ,
};


//
// CALL RELATED STUFF
//



/*  ========================================================================
                                    Call
    ========================================================================*/
typedef SdlInteger Tipd;
typedef SdlInteger Volume;

const SdlInteger    c_null_tipd = -1;           // NULL_TI_PD;
const SdlInteger    c_no_tipd = MN_NO_TI_PD;
const Tipd          c_mtc_mask = 0x80;          // msb of tipd set -> MTC

enum CallProgressInd {
    NoProgress              = MN_PROGRESS_NONE,
    Alerting                = MN_ALERTING,
    MtcAccepted             = MN_MT_CALL_ACCEPTED,
    InBandTonesAvailable    = MN_IN_BAND_TONES_AVAILABLE,
    InBandTonesNotAvailable = MN_IN_BAND_TONES_NOT_AVAILABLE,
    SpeechMtcAccepted       = MN_TCH_SPEECH_MT_CALL_ACCEPTED,
    SpeechTonesAvailable    = MN_TCH_SPEECH_TONES_AVAILABLE,
    SpeechTonesNotAvailable = MN_TCH_SPEECH_TONES_NOT_AVAILABLE,
    Speech                  = MN_TCH_SPEECH,
    Data                    = MN_TCH_DATA,
    NotSpeech               = MN_TCH_NOT_SPEECH,
    };


enum CallErrorCause{ // gsm 4.08, v7.7.0 p 636 - 637
    // normal class
    UnassignedNumber                = MN_UNASSIGNED_NUMBER,
    NoRoute                         = MN_NO_ROUTE,
    ChannelUnacceptable             = MN_CHANNEL_UNACCEPTABLE,
    OperatorBarring                 = MN_OPERATOR_BARRING,
    NormalCallClear                 = MN_NORMAL_CALL_CLEARING,
    UserBusy                        = MN_USER_BUSY,
    NoUserResponding                = MN_NO_USER_RESPONDING,
    UserAlertingNoAnser             = MN_USER_ALERTING_NO_ANSWER,
    CallRejected                    = MN_CALL_REJECTED,
    NumberChanged                   = MN_NUMBER_CHANGED,
    NonSelectedUserClearing         = MN_NON_SELECTED_USER_CLEARING,
    DestinationOutOfOrder           = MN_DESTINATION_OUT_OF_ORDER,
    InvalidNumberFormat             = MN_INVALID_NUMBER_FORMAT,
    FacilityRejected                = MN_FACILITY_REJECTED,
    ResponseToStatusEnquiry         = MN_RESPONSE_TO_STATUS_ENQUIRY,
    NormalUnspecified               = MN_NORMAL_UNSPECIFIED,
    // resource unvailable class
    NoCircuitAvailable              = MN_NO_CIRCUIT_AVAILABLE,
    NetworkOutOfOrder               = MN_NETWORK_OUT_OF_ORDER,
    TemporaryFailure                = MN_TEMPORARY_FAILURE,
    SwitchCongestion                = MN_SWITCH_CONGESTION,
    AccessInformationDiscarded      = MN_ACCESS_INFORMATION_DISCARDED,
    ReqeustedCircuitNotAvailable    = MN_REQUESTED_CIRCUIT_NOT_AVAILABLE,
    RessourcesUnavailable           = MN_RESOURCES_UNAVAILABLE,
    // service or option class not available
    QualityUnavailable              = MN_QUALITY_UNAVAILABLE,
    FacilityNotSubscribed           = MN_FACILITY_NOT_SUBSCRIBED,
    IncomingCallsBarredInCug        = MN_INCOMING_CALLS_BARRED_IN_CUG,
    BearerCapabilityNotAllowed      = MN_BEARER_CAPABILITY_NOT_ALLOWED,
    BearerCapabilityNotAvailable    = MN_BEARER_CAPABILITY_NOT_AVAILABLE,
    ServiceNotAvailable             = MN_SERVICE_NOT_AVAILABLE,
    AcmGreaterOrEqualToAcmmax       = MN_ACM_GREATER_OR_EQUAL_TO_ACMMAX,
    // service or option not implemented
    BearerServiceNotImplemented     = MN_BEARER_SERVICE_NOT_IMPLEMENTED, 
    FacilityNotImplemented          = MN_FACILITY_NOT_IMPLEMENTED,
    OnlyRestrictedDigital           = MN_ONLY_RESTRICTED_DIGITAL,
    ServiceNotImplemented           = MN_SERVICE_NOT_IMPLEMENTED,
    // Invalid message
    InvalidTi                       = MN_INVALID_TI,
    UserNotInCug                    = MN_USER_NOT_IN_CUG,
    IncompatibleDestination         = MN_INCOMPATIBLE_DESTINATION,
    InvalidTransitNetwork           = MN_INVALID_TRANSIT_NETWORK,
    SemanticsIncorrect              = MN_SEMANTICS_INCORRECT,
    // protocoll error
    InvalidMandatoryInformation     = MN_INVALID_MANATORY_INFORMATION,
    UnknowMsgType1                  = MN_UNKNOWN_MESSAGE_TYPE_1,
    UnexpectedMsgType               = MN_UNEXPECTED_MESSAGE_TYPE,
    UnexpectedIe                    = MN_UNEXPECTED_IE,
    ConditionalIeError              = MN_CONDITIONAL_IE_ERROR,
    UnknownMsgType2                 = MN_UNKNOWN_MESSAGE_TYPE_2,
    RecoveryOnTimerExpiry           = MN_RECOVERY_ON_TIMER_EXPIRY,
    ProtocolError                   = MN_PROTOCOL_ERROR,
    // interworking classes
    Interworking                    = MN_INTERWORKING,

    // the following stuff is Comneon/MN specific

    VoidCause                       = MN_VOID_CAUSE,
    OutofMemory                     = MN_OUT_OF_MEMORY,
    InvalidParam                    = MN_INVALID_PARAM,
    DataCallActive                  = MN_DATA_CALL_ACTIVE,
    SpeechCallActive                = MN_SPEECH_CALL_ACTIVE,
    DtmfRejDuringMocSetup           = MN_DTMF_REJECTED_DURING_MO_CALL_SETUP,
    MocSetupRejMissingAcmInfoInd    = MN_MOC_SETUP_REJ_DUE_TO_MISSING_ACM_INFO_IND,
    TempForbiddenCallAttempt        = MN_TEMPORARY_FORBIDDEN_CALL_ATTEMPT,
    CalledPartyBlacklisted          = MN_CALLED_PARTY_IS_BLACKLISTED,
    BlacklistFullNoAutoCallAttempts = MN_BLACKLIST_IS_FULL_NO_AUTO_CALL_ATTEMPTS,
    TempForbiddenCallAttemptNoService   = MN_TEMPORARY_FORBIDDEN_CALL_ATTEMPT_NO_SERVICE,
    TempForbiddenCallAttemptLimitedServe    = MN_TEMPORARY_FORBIDDEN_CALL_ATTEMPT_LIMITED_SERVICE,
    ClientTemporaryBarred           = MN_CLIENT_TEMPORARY_BARRED,
    DualServiceCallActive           = MN_DUAL_SERVICE_CALL_ACTIVE,
    AtcFclassNotSpeech              = MN_ATC_FCLASS_NOT_SPEECH,
    SiUnknownError                  = MN_SI_UNKNOWN_ERROR,
    DtmfRejCallHeldOrMparty         = MN_DTMF_REJECTED_DUE_TO_CALL_HELD_OR_MPARTY,
    ClientNotRegistered             = MN_CLIENT_NOT_REGISTRATED,
    ActiveClientGone                = MN_ACTIVE_CLIENT_GONE,
    DtmfRejDataTransmission         = MN_DTMF_REJECTED_DUE_TO_DATA_TRANSMISSION,
    NoAppropriateDtmfEntry          = MN_NO_APPROPRIATE_DTMF_ENTRY,
    SimStatusFailure                = MN_SIM_STATUS_FAILURE,
    // SIMTK specific stuff
    SimtkSetupModeNotSupported      = MN_SIMTK_SETUP_MODE_NOT_SUPPORTED,
    MmiNotRegistered                = MN_MMI_NOT_REGISTERED,
    SimtkSetupRejMissingAcmInfoInd  = MN_SIMTK_SETUP_REJ_DUE_TO_MISSING_ACM_INFO_IND,
    SimtkSetupRejByUser             = MN_SIMTK_SETUP_REJECTED_BY_THE_USER,
    SimtkSetupRejTimeOut            = MN_SIMTK_SETUP_REJECTED_TIME_OUT,
    SimtkCallConnected              = MN_SIMTK_CALL_CONNECTED,
    DisconnectDueToSimtkSetup       = MN_DISCONNECT_DUE_TO_SIMTK_SETUP,
    SimtkSetupRejPendingSimtkSetup  = MN_SIMTK_SETUP_REJ_DUE_TO_PENDING_SIMTK_SETUP,
    SimtkCallConnectedNoIconDisplay = MN_SIMTK_CALL_CONNECTED_NO_ICON_DISPLAY,
    PendingSimtkSetup               = MN_PENDING_SIMTK_SETUP,
    SimtkSimReset                   = MN_SIMTK_SIM_RESET,
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    DtmfRejectedDueToSupTimerExpiry = MN_DTMF_REJECTED_DUE_TO_SUP_TIMER_EXPIRY,
#else
    DtmfRejectedDueToSupTimerExpiry,
#endif

    RejByCallControl    = MN_REJ_BY_CALL_CONTROL,
    FdnFailed           = MN_FDN_FAILED,
    BdnFailed           = MN_BDN_FAILED,
    OnlyError           = MN_ONLY_ERROR,
    NotInSpeechCall     = MN_NOT_IN_SPEECH_CALL,
    InvalidAlsLine      = MN_INVALID_ALS_LINE,
    LndOverflow         = MN_LND_OVERFLOW,
    
    DtmfRejectedNoTchAvailable  = MN_DTMF_REJECTED_NO_TCH_AVAILABLE,
    NwFailureUnspecified        = MN_NW_FAILURE_UNSPECIFIED,
    MsNoService                 = MN_MS_NO_SERVICE,
    MsAccessClassBarred         = MN_MS_ACCESS_CLASS_BARRED,
    MsNoResource                = MN_MS_NO_RESOURCE,
    MsServiceBusy               = MN_MS_SERVICE_BUSY,
    MsFailureUnspecified        = MN_MS_FAILURE_UNSPECIFIED,
    
    ProactiveSimApplTerminatedByUser= MN_PROACTIVE_SIM_APPL_TERMINATED_BY_USER,
    
    //SimtkDtmfTransmitted          = MN_SIMTK_DTMF_TRANSMITTED, //311
    //SimtkDtmfTransmittedNoIconDisplay     = MN_SIMTK_DTMF_TRANSMITTED_NO_ICON_DISPLAY,  //312
    //UserDidNotAcceptCallSetup         = MN_USER_DID_NOT_ACCEPT_CALL_SETUP,  //313

    CcbsPossible            = MN_CCBS_POSSIBLE,  //283

    // ASC specific stuff
    ClientRejected    = 995,
    UnknownErrorCause = 996, //zukunftssicher durch hohe werte?
    CallChangedToSs   = 997,
    CallChangedToUssd = 998,
    NoCallError       = 999 
    };


enum CallRelatedSsCode {
    VoidSsCode              = MN_VOID_SS_SERV_CODE,
    Clip                    = MN_CLIP,
    Clir                    = MN_CLIR,
    Colp                    = MN_COLP,
    Colr                    = MN_COLR,
    AllForwardingSs         = MN_ALL_FORWARDING_SS,
    Cfu                     = MN_CFU,
    AllCondForwardingSs     = MN_ALL_COND_FORWARDING_SS,
    Cfb                     = MN_CFB,
    Cfnry                   = MN_CFNRY,
    Cfnrc                   = MN_CFNRC,
    ExplicitCallTransfer    = MN_EXPLICT_CALL_TRANSFER,
    Cw                      = MN_CW,
    Hold                    = MN_HOLD,
    MultiParty              = MN_MULTIPTY,
    Cug                     = MN_CUG,
    Aoci                    = MN_AOCI,
    Aocc                    = MN_AOCC,
    AllCallRestrictionsSs   = MN_ALL_CALL_RESTRICTIONS_SS,
    BarringOfOutgoingCalls  = MN_BARRING_OF_OUTGOING_CALLS,
    Baoc                    = MN_BAOC,
    Boic                    = MN_BOIC,
    BoicExHc                = MN_BOIC_EX_HC,
    BarringOfIncomingCalls  = MN_BARRING_OF_INCOMING_CALLS,
    Baic                    = MN_BAIC,
    BicRoam                 = MN_BIC_ROAM,
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    Cnap                    = MN_CNAP,
#else
    Cnap,

#endif
    Emlpp                   = MN_EMLPP,

    
    // additions for ASC
    UusService1             = 1000,         // hopefully there will never be more than 999 Supplementary Services
    UusService2,
    UusService3,
    AllUusServices,
    Fm,
    Msp,
    Mc,
    Cd,
    Ussd,
    AllSsServices,
    NoSsCode

};

enum GsmSignal {
    DialToneOn              = MN_SIG_DIAL_TONE_ON,
    RingBackToneOn          = MN_SIG_RING_BACK_TONE_ON,
    InterceptToneon         = MN_SIG_INTERCEPT_TONE_ON,
    CongestionToneOn        = MN_SIG_CONGESTION_TONE_ON,
    BusyToneOn              = MN_SIG_BUSY_TONE_ON,
    ConfirmToneOn           = MN_SIG_CONFIRM_TONE_ON,
    AnswerToneOn            = MN_SIG_ANSWER_TONE_ON,
    CallWaitToneOn          = MN_SIG_CALL_WAIT_TONE_ON,
    OffHookToneOn           = MN_SIG_OFF_HOOK_TONE_ON,
    TonesOff                = MN_SIG_TONES_OFF,
    AlertingOff             = MN_SIG_ALERTING_OFF,
    IeMissing               = MN_SIG_IE_MISSING
    };

enum CallEstCause {
    EmergencyCall   = EMERGENCY_CALL,
    CallReEst       = CALL_REEST,
    FullTchNeeded   = TCH_F_NEEDED,
    HalfTchSpeech   = SPEECH_TCH_H,
    HalfTchData     = DATA_TCH_H,
    LocationUpdate  = LOCATION_UPDATE,
    Other           = OTHER,
    UndefinedCallEstCause
    };


enum ClirMode{                              // GSM 02.81, 2.3.7
    SuppressPhoneNumber = MN_CLIR_INVOKE,   // restrict line identification
    DisplayPhoneNumber  = MN_CLIR_SUPPRESS, // do not restrict line identification
    DontCare            = MN_CLIR_NONE      // decision is done by network
    };


enum CugSelector{                           // used to carry CUG information
    PreferedCug = MN_PREFERENTIAL_CUG,      // use preferential CUG index
    CugIndex    = MN_CUG_INDEX,             // use CUG index gvien in param
    NoCug       = MN_NO_CUG                 // use none of them
    };


struct CugDescriptor {                      // GSM 02.85
    CugSelector selected_cug;               // carries CUG information
    INT         index;                      // CUG index, if given
    BOOLEAN     suppress_oa;                // suppress outgoing access
    };


enum CallState {
    MocSetup            = MN_MOC_CALL_SETUP,
    MocStarted          = MN_MOC_CALL_STARTED,
    MocActive           = MN_MOC_CALL_ACTIVE,
    MtcConfirmed        = MN_MTC_CALL_CONFIRMED,
    MtcSetup            = MN_MTC_CALL_SETUP,
    MtcBcNegotiated     = MN_MTC_BC_NEGOTIATED,
    MtcStarted          = MN_MTC_CALL_STARTED,
    MtcActive           = MN_MTC_CALL_ACTIVE,
    MocAsCallSetup      = MN_MOC_AS_CALL_SETUP,
    MtcAsCallSetup      = MN_MTC_AS_CALL_SETUP,
    MtcRejected         = MN_MTC_CALL_REJECTED,
    CallIsHeld          = MN_CALL_IS_HELD,
    CallIsRetrieved     = MN_CALL_IS_RETRIEVED,
    MptyIsActive        = MN_MPARTY_IS_ACTIVE,
    MptyIsHeld          = MN_MPARTY_IS_HELD,
    MptyIsRetrieved     = MN_MPARTY_IS_RETRIEVED,
    MptyIsSplitted      = MN_MPARTY_IS_SPLITTED,
    IsEct               = MN_IS_ECT,
    CallDiscReq         = MN_CALL_DISC_REQ,
    CallIsCleared       = MN_CALL_IS_CLEARED,
    CallModifyIndicated = MN_CALL_MODIFY_INDICATED,
    CallModifyStarted   = MN_CALL_MODIFY_STARTED,
    CallModifyCompleted = MN_CALL_MODIFY_COMPLETED,
    CallModifyRejected  = MN_CALL_MODIFY_REJECTED,
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    MocAlerted          = MN_MOC_CALL_ALERTED,
    CallIsDisconnected  = MN_CALL_IS_DISCONNECTED,
    CallIsDeflected     = MN_CALL_IS_DEFLECTED,
#else
    MocAlerted,
    CallIsDisconnected,
    CallIsDeflected,
#endif

#if defined(APOXI_3GPP_REL_4_5)
    MptyStarted             = MN_MPARTY_STARTED, /* Multi-Party built is started*/
    MptyRejected            = MN_MPARTY_REJECTED,/* Multi-Party built  was rejected from the network */     
    MptyRetrievedStarted    = MN_MPARTY_RETRIEVE_STARTED,/* Multi-Party retrieved was started */
    MptyRetrieveRejected    = MN_MPARTY_RETRIEVE_REJECTED,/* Multi-Party retrieved was rejected from the network */
    MpartySplitStarted      = MN_MPARTY_SPLIT_STARTED,/* Multi-Party splited was started */
    MptySplitRejected       = MN_MPARTY_SPLIT_REJECTED,/* Multi-Party splitted was rejected from the network */
    MptyHeldStarted         = MN_MPARTY_HELD_STARTED,/* Multi-Party held was started */
    MptyHeldRejected        = MN_MPARTY_HELD_REJECTED,/* Multi-Party held was was rejected from the network */
    CallDeflectionStarted   = MN_CALL_DEFLECTION_STARTED,/* Call Deflection was started */
    CallDeflectionRejected  = MN_CALL_DEFLECTION_REJECTED,/* Call Deflection was rejected from the network */
    CallHeldStarted         = MN_CALL_HELD_STARTED,/* MO/MT Call held was started */
    CallHeldRejected        = MN_CALL_HELD_REJECTED,/* MO/MT Call held was rejected from the network */
    CallRetrieveStarted     = MN_CALL_RETRIEVE_STARTED,/* MO/MT Call retrieved was started */
    CallRetrieveRejected    = MN_CALL_RETRIEVE_REJECTED,/* MO/MT Call retrieved was rejected from the network */
    EctStarted              = MN_ECT_STARTED,/* Explicit call transfer was started */
    EctRejected             = MN_ECT_REJECTED/* Explicit call transfer was rejected from the network */
#else

    MptyStarted, /* Multi-Party built is started*/
    MptyRejected,/* Multi-Party built  was rejected from the network */     
    MptyRetrievedStarted,/* Multi-Party retrieved was started */
    MptyRetrieveRejected,/* Multi-Party retrieved was rejected from the network */
    MpartySplitStarted,/* Multi-Party splited was started */
    MptySplitRejected,/* Multi-Party splitted was rejected from the network */
    MptyHeldStarted,/* Multi-Party held was started */
    MptyHeldRejected,/* Multi-Party held was was rejected from the network */
    CallDeflectionStarted,/* Call Deflection was started */
    CallDeflectionRejected,/* Call Deflection was rejected from the network */
    CallHeldStarted,/* MO/MT Call held was started */
    CallHeldRejected,/* MO/MT Call held was rejected from the network */
    CallRetrieveStarted,/* MO/MT Call retrieved was started */
    CallRetrieveRejected,/* MO/MT Call retrieved was rejected from the network */
    EctStarted,/* Explicit call transfer was started */
    EctRejected/* Explicit call transfer was rejected from the network */
#endif
};


enum CallType {
    NoDataCall      = MN_NO_DATA_CALL,
    FacsimileCall   = MN_FACSIMILE_CALL,
    DataCall        = MN_DATA_CALL,
    MmCall,
    VoidCallType
};

/*****
* T_DATA_CALL_TYPE 
* /vobs/ms-hosttest/mi/src/../../../ms-interface-src/pr/msap_msg_mn_ds.pr,70,9
******/

#if defined(APOXI_3GPP_REL_99)
enum DataCallType {
    CsdNone   = CSD_NONE,
    CsdDataT  = CSD_DATA_T,
    CsdDataNt = CSD_DATA_NT,
    CsdFax    = CSD_FAX,
    CsdWap    = CSD_WAP,
    CsdVoice,
    CsdMultimedia
};

#else
enum DataCallType {
    CsdNone   = CSD_NONE,
    CsdDataT  = CSD_DATA_T,
    CsdDataNt = CSD_DATA_NT,
    CsdFax    = CSD_FAX,
    CsdVoice  = CSD_VOICE,
    CsdMultimedia = CSD_MULTIMEDIA,
    CsdWap    = CSD_WAP
};
#endif

enum ServedCallApplication {
    AppUnknown  = MN_APPL_UNKNOWN,      // Application is unknown - default
    AppSpeech   = MN_APPL_SPEECH,       // Speech (MMI/ATC) is being served 
    AppData     = MN_APPL_DATA,         // Data (Data Services) is being served
    AppDual     = MN_APPL_DUAL,         // Dual Services (DS and ATC) is being served
    AppStkSpeech= MN_APPL_SIMTK_SPEECH  // Speech (initiated by SIM-Toolkit, processed by MMI) is being served
};

enum UusOutTextType {
    SendOnAny = MN_UUS1_MSG_OUT_ANY,
    SendOnSetup = MN_UUS1_MSG_OUT_SETUP,
    SendOnAlerting = MN_UUS1_MSG_OUT_ALERTING,
    SendOnConnect = MN_UUS1_MSG_OUT_CONNECT,
    SendOnDisconnect = MN_UUS1_MSG_OUT_DISCONNECT,
    SendOnRelease = MN_UUS1_MSG_OUT_RELEASE,
    SendOnReleaseComplete = MN_UUS1_MSG_OUT_REL_COMPL
};

const INT c_max_uus1_out_buffer_len = MAX_UUS1_OUT_BUFFER_LEN;

enum UusInTextType {
    ReceivedOnAnySetup = MN_UUS1_MSG_IN_SETUP,
    ReceivedOnAnyAlerting = MN_UUS1_MSG_IN_ALERTING,
    ReceivedOnProgress = MN_UUS1_MSG_IN_PROGRESS,
    ReceivedOnAnyConnect = MN_UUS1_MSG_IN_CONNECT,
    ReceivedOnAnyDisconnect = MN_UUS1_MSG_IN_DISCONNECT,
    ReceivedOnAnyRelease = MN_UUS1_MSG_IN_RELEASE,
    ReceivedOnAnyReleaseComplete = MN_UUS1_MSG_IN_REL_COMPL
};

struct UusText {
    UusOutTextType type;
    WString text;
};

/*  ------------------------------------------------------------------------
    Call Related SS enum types for MN_CRSS_REQ
    ------------------------------------------------------------------------ */   
enum CallRelatedSs {
    RelAllHeldCalls         = MN_REL_ALL_HELD_CALLS,
    RelAllActiveCalls       = MN_REL_ALL_ACT_CALLS,
    RelSpecificActiveCall   = MN_REL_SPECIFIC_ACT_CALL,
    HoldActiveCall          = MN_HOLD_ACTIVE_CALL,
    RetrieveCall            = MN_RETRIEVE_CALL,
    BuildMparty             = MN_BUILD_MPARTY,
    HoldMparty              = MN_HOLD_MPARTY,
    RetrieveMparty          = MN_RETRIEVE_MPARTY,
    SplitMparty             = MN_SPLIT_MPARTY,
    Ect                     = MN_ECT,
    ActivateCCBS            =   MN_ACTIVATE_CCBS,           // Manik added 06-Aug-2003
    InvokeCallDeflection    =   MN_INVOKE_CALL_DEFLECTION,  // Manik added 06-Aug-2003
    InvalidCallRelatedSs
};


/*  ------------------------------------------------------------------------
    Call Related SS enum types for MN_HOLD_CNF
    ------------------------------------------------------------------------ */

enum CallRelatedSsState {
    CallActive      = MN_CALL_ACTIVE,
    CallHeld        = MN_CALL_HELD,
    InvalidCallRelatedSsState
};

enum HoldIndicator {
    CallRetrieved   = MN_CALL_RETRIEVED, 
    CallOnHold      = MN_CALL_ON_HOLD,
    VoidHoldInd     = MN_VOID_HOLD_INDICATOR
};

enum EctCallState {
    EctAlerting         = MN_ECT_ALERTING,
    EctActive           = MN_ECT_ACTIVE,
    EctVoidCallState    = MN_VOID_ECT_CALLSTATE
};

enum RdnChoice {
    RdnPresentationAllowedAddr  = MN_RDN_PRESENTATION_ALLOWED_ADDR,
    RdnPresentationRestricted   = MN_RDN_PRESENTATION_RESTRICTED,
    RdnNumberNotAvailable       = MN_RDN_NUMBER_NOT_AVAILABLE,
    RdnPresentationRestrictAddr = MN_RDN_PRESENTATION_RESTRICT_ADDR,
    RdnVoidChoice               = MN_VOID_RDN_CHOICE
};

struct Subaddress {
    // TODO: Clariyfy sense of address (may change to PhoneNumber)
    BOOLEAN     available;
    PhoneNumber address;
};

struct Rdn {
    // TODO: check subaddress (what is, sense etc)
    RdnChoice   selector;   // enum
    PhoneNumber phone_number;
    Subaddress  subaddress;
};

struct EctIndicator {
    EctCallState    ect_callstate;
    Rdn             rdn;
};

enum CnameChoice {
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    NamePresentationAllowed     = MN_CNAME_NAME_PRES_ALLOWED,
    PresentationRestricted      = MN_CNAME_PRESENTATION_RESTRICTED,
    NameUnavailable             = MN_CNAME_NAME_UNAVAILABLE,
    NamePresentationRestricted  = MN_CNAME_NAME_PRES_RESTRICTED,
#else
    NamePresentationAllowed,
    PresentationRestricted,
    NameUnavailable,
    NamePresentationRestricted,
#endif
    CnameVoidChoice
};

const INT c_max_cname_string_len = 160;

struct CallingName {
    CnameChoice         cname_selector;
    DataCodingScheme    data_coding_scheme;
    WString             name_string;
};

struct NameIndicator {
    BOOLEAN         name_indicator_present;
    CallingName     calling_name;
};

struct NotifySsArg {
    CallRelatedSsCode   ss_code;            // which suppl. service (all services!!!)
    SsStatus            ss_status;          // quiescent, registered, activated
    SsNotification      ss_notification;    // call forwarded to calling,forwarding, forwared-to
    BOOLEAN             call_wait_indicator;// call waiting?
    HoldIndicator       call_hold_indicator;// call on hold or retrieved
    BOOLEAN             mpty_indicator;     // refers to mpty?
    INT                 cug_index;          // index of selected CUG
    BOOLEAN             clir_supp_rejected; // overrule category?
    EctIndicator        ect_indicator;      // 
    NameIndicator       name_indicator;     // CNAP Name indicator
};

enum NotificationDescription {
    UserSuspended = MN_USER_SUSPENDED,
    UserResumed =   MN_USER_RESUMED,
    BearerChange =  MN_BEARER_CHANGE,
};


enum AocChargingStatus {
    AocInformation          = Aoci,
    AocCharging             = Aocc,
    NoAoc                   = VoidSsCode,
    InvalidChargingStatus
    };

// CurrencyCode orginal T_SI_ARR_3
struct CurrencyCode {
    UINT8  val[3];
};

struct AocChargeData {
    ULONG   charge_value;
    INT     exponent;
};


/*  ------------------------------------------------------------------------
    Call Related SS enum types for MN_DIAGNOSTIC_IND
    ------------------------------------------------------------------------ */
enum DiagnosticCause {
    VoidDiagnostic         = MN_VOID_DIAGNOSTIC, 
    OutgCallsBarredWithCug = MN_OUTG_CALLS_BARRED_WITHIN_CUG,
    NoCugSelected          = MN_NO_CUG_SELECTED,
    UnknownCugIndex        = MN_UNKNOWN_CUG_INDEX,
    CugIndexIncompatible   = MN_CUG_INDEX_INCOMPATIBLE,
    CugCallFailure         = MN_CUG_CALL_FAILURE,
    ClirNotSubscribed      = MN_CLIR_NOT_SUBSCRIBED,
    CcbsAllowed            = MN_CCBS_ALLOWED,
    CcbsNotAllowed         = MN_CCBS_NOT_ALLOWED,
    UnknownDiagnosticCause
};
 
/*  ========================================================================
                                    SS
    ======================================================================== */
const INT c_max_size_ussd_string        = MN_MAX_USSD_STRING_LENGTH;            // 200
const INT c_max_no_basic_service_groups = MN_MAX_NUMBER_BASIC_SERVICE_GROUPS;   // 13
const INT c_password_len                = 4;

// typedef UINT8 SsErrorCode; 
// typedef UINT8 SsProblemTag;
// typedef UINT8 SsProblemCode;
// typedef UINT8 MnSsStatus;
typedef CallRelatedSsCode SsCode;
typedef CallErrorCause MnCause;
typedef CallErrorCause DcError;

enum SsOperationCode {
    UnkownSsCode            = MN_VOID_SS_OP_CODE,
    ScRegister              = MN_REGISTER_SS,
    ScErase                 = MN_ERASE_SS,
    ScActivate              = MN_ACTIVATE_SS,
    ScDeactivate            = MN_DEACTIVATE_SS,
    ScInterrogate           = MN_INTERROGATE_SS,
    ScNotify                = MN_NOTIFY_SS,
    ScRegisterPassword      = MN_REGISTER_PASSWORD,
    ScGetPassword           = MN_GET_PASSWORD,
    ScProcessUssd           = MN_PROCESS_UNSTRUCTURED_SS_DATA,
    ScForwardCheckIndication = MN_FORWARD_CHECK_SS_INDICATION,
    ScProcessUssdRequest    = MN_PROCESS_UNSTRUCTURED_SS_REQUEST,
    ScUssdRequest           = MN_UNSTRUCTURED_SS_REQUEST,
    ScUssdNotify            = MN_UNSTRUCTURED_SS_NOTIFY,
    ScForwardCugInfo        = MN_FORWARD_CUG_INFO,
    ScSplitMpty             = MN_SPLIT_MPTY,
    ScRetrieveMpty          = MN_RETRIEVE_MPTY,
    ScScHoldMpty            = MN_HOLD_MPTY,
    ScBuildMpty             = MN_BUILD_MPTY,
    ScForwardChargeAdvice   = MN_FORWARD_CHARGE_ADVICE,
    ScExplicitCt            = MN_EXPLICIT_CT,
    ScSetupUusText
};

/*  ------------------------------------------------------------------------
    Service Group Types
    ------------------------------------------------------------------------ */
enum ServiceGroup {
    UnknownSerivceGroup                 = MN_VOID_SERV_GROUP,
    AllTeleservices                     = MN_ALL_TELESERVICES,
    AllSpeechTransmissionServices       = MN_ALL_SPEECH_TRANSMISSION_SERVICES,
    Telephony                           = MN_TELEPHONY,
    EmergencyCalls                      = MN_EMERGENCY_CALLS,
    AllShortMessageServices             = MN_ALL_SHORT_MESSAGE_SERVICES,
    ShortMessageMtPp                    = MN_SHORT_MESSAGE_MT_PP,
    ShortMessageMoPp                    = MN_SHORT_MESSAGE_MO_PP,
    AllFacsimileTransmissionServices    = MN_ALL_FACSIMILE_TRANSMISSION_SERVICES,
    FacsimileGroup3AndAlterSpeech       = MN_FACSIMILE_GROUP3_AND_ALTER_SPEECH,
    AutomaticFacsimileGroup3            = MN_AUTOMATIC_FACSIMILE_GROUP3,
    FacsimileGroup4                     = MN_FACSIMILE_GROUP4,
    AllDataTeleservices                 = MN_ALL_DATA_TELESERVICES,
    AllTeleservicesExceptSms            = MN_ALL_TELESERVICES_EXCEPT_SMS,
    AllPlmnSpecificTs                   = MN_ALL_PLMN_SPECIFIC_TS,
    PlmnSpecificTs1                     = MN_PLMN_SPECIFIC_TS_1,
    PlmnSpecificTs2                     = MN_PLMN_SPECIFIC_TS_2,
    PlmnSpecificTs3                     = MN_PLMN_SPECIFIC_TS_3,
    PlmnSpecificTs4                     = MN_PLMN_SPECIFIC_TS_4,
    PlmnSpecificTs5                     = MN_PLMN_SPECIFIC_TS_5,
    PlmnSpecificTs6                     = MN_PLMN_SPECIFIC_TS_6,
    PlmnSpecificTs7                     = MN_PLMN_SPECIFIC_TS_7,
    PlmnSpecificTs8                     = MN_PLMN_SPECIFIC_TS_8,
    PlmnSpecificTs9                     = MN_PLMN_SPECIFIC_TS_9,
    PlmnSpecificTsA                     = MN_PLMN_SPECIFIC_TS_A,
    PlmnSpecificTsB                     = MN_PLMN_SPECIFIC_TS_B,
    PlmnSpecificTsC                     = MN_PLMN_SPECIFIC_TS_C,
    PlmnSpecificTsD                     = MN_PLMN_SPECIFIC_TS_D,
    PlmnSpecificTsE                     = MN_PLMN_SPECIFIC_TS_E,
    PlmnSpecificTsF                     = MN_PLMN_SPECIFIC_TS_F,
    AllBearerServices                   = MN_ALL_BEARER_SERVICES,
    AllDataCdaServices                  = MN_ALL_DATA_CDA_SERVICES,
    DataCda300Bps                       = MN_DATA_CDA_300_BPS,
    DataCda1200Bps                      = MN_DATA_CDA_1200_BPS,
    DataCda1200_75Bps                   = MN_DATA_CDA_1200_75_BPS,
    DataCda2400_Bps                     = MN_DATA_CDA_2400_BPS,
    DataCda4800_Bps                     = MN_DATA_CDA_4800_BPS,
    DataCda9600_Bps                     = MN_DATA_CDA_9600_BPS,
    AllDataCdsServices                  = MN_ALL_DATA_CDS_SERVICES,
    DataCds1200Bps                      = MN_DATA_CDS_1200_BPS,
    DataCds2400Bps                      = MN_DATA_CDS_2400_BPS,
    DataCds4800Bps                      = MN_DATA_CDS_4800_BPS,
    DataCds9600Bps                      = MN_DATA_CDS_9600_BPS,
    AllPadAccessCaServices              = MN_ALL_PAD_ACCESS_CA_SERVICES,
    PadAccessCa300Bps                   = MN_PAD_ACCESS_CA_300_BPS,
    PadAccessCa1200Bps                  = MN_PAD_ACCESS_CA_1200_BPS,
    PadAccessCa1200_75Bps               = MN_PAD_ACCESS_CA_1200_75_BPS,
    PadAccessCa2400Bps                  = MN_PAD_ACCESS_CA_2400_BPS,
    PadAccessCa4800Bps                  = MN_PAD_ACCESS_CA_4800_BPS,
    PadAccessCa9600Bps                  = MN_PAD_ACCESS_CA_9600_BPS,
    AllDataPdsServices                  = MN_ALL_DATA_PDS_SERVICES,
    DataPds2400Bps                      = MN_DATA_PDS_2400_BPS,
    DataPds4800Bps                      = MN_DATA_PDS_4800_BPS,
    DataPds9600Bps                      = MN_DATA_PDS_9600_BPS,
    AllAlternateSpeechDataCda           = MN_ALL_ALTERNATE_SPEECH_DATA_CDA,
    AllAlternateSpeechDataCds           = MN_ALL_ALTERNATE_SPEECH_DATA_CDS,
    AllSpeechFollByDataCda              = MN_ALL_SPEECH_FOLL_BY_DATA_CDA,
    AllSpeechFollByDataCds              = MN_ALL_SPEECH_FOLL_BY_DATA_CDS,
    AllDataCircuitAsynchronous          = MN_ALL_DATA_CIRCUIT_ASYNCHRONOUS,
    AllAsynchronousServices             = MN_ALL_ASYNCHRONOUS_SERVICES,
    AllDataCircuitSynchronous           = MN_ALL_DATA_CIRCUIT_SYNCHRONOUS,
    AllSynchronousServices              = MN_ALL_SYNCHRONOUS_SERVICES,
    AllPlmnSpecificBs                   = MN_ALL_PLMN_SPECIFIC_BS,
    PlmnSpecificBs1                     = MN_PLMN_SPECIFIC_BS_1,
    PlmnSpecificBs2                     = MN_PLMN_SPECIFIC_BS_2,
    PlmnSpecificBs3                     = MN_PLMN_SPECIFIC_BS_3,
    PlmnSpecificBs4                     = MN_PLMN_SPECIFIC_BS_4,
    PlmnSpecificBs5                     = MN_PLMN_SPECIFIC_BS_5,
    PlmnSpecificBs6                     = MN_PLMN_SPECIFIC_BS_6,
    PlmnSpecificBs7                     = MN_PLMN_SPECIFIC_BS_7,
    PlmnSpecificBs8                     = MN_PLMN_SPECIFIC_BS_8,
    PlmnSpecificBs9                     = MN_PLMN_SPECIFIC_BS_9,
    PlmnSpecificBsA                     = MN_PLMN_SPECIFIC_BS_A,
    PlmnSpecificBsB                     = MN_PLMN_SPECIFIC_BS_B,
    PlmnSpecificBsC                     = MN_PLMN_SPECIFIC_BS_C,
    PlmnSpecificBsD                     = MN_PLMN_SPECIFIC_BS_D,
    PlmnSpecificBsE                     = MN_PLMN_SPECIFIC_BS_E,
    PlmnSpecificBsF                     = MN_PLMN_SPECIFIC_BS_F,
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    AllVoiceGroupCallServices           = MN_ALL_VOICE_GROUP_CALL_SERVICES,
    VoiceGroupCallService               = MN_VOICE_GROUP_CALL,
    VoiceBroadcastService               = MN_VOICE_BROADCAST_CALL,
#else
    AllVoiceGroupCallServices,
    VoiceGroupCallService,
    VoiceBroadcastService,
#endif
    AuxiliarySpeech                     = MN_ALL_AUXILIARY_SPEECH_SERVICES,
    // Addtions for ASC
    AllServices,
    AllGPRSBearerServices,

};

enum SsInd {
    UnkownServiceInd    = MN_VOID_SERV_IND,
    TeleService         = MN_TELESERVICE,
    BearerService       = MN_BEARERSERVICE,
    TeleAndBearerServices
};

struct SsGroup {
    BOOLEAN present;
    SsInd ind;
    ServiceGroup value;
};

/*  ------------------------------------------------------------------------
    Forwarding Types
    ------------------------------------------------------------------------ */
struct ForwardingFeature {
    SsGroup basic_service;
    SsStatus ss_status;
    PhoneNumber forward_to_number;  // UINT8 forward_to_number[c_max_size_telephone_nr];
    UINT8 options;
    INT noreply_timer;
};

struct ForwardingFeatureList {
    ForwardingFeature data[c_max_no_basic_service_groups];
};

struct ForwardingInfo {
    SsCode sc;
    INT feature_list_size;
    ForwardingFeatureList feature_list;
};

/*  ------------------------------------------------------------------------
    Call barring Types
    ------------------------------------------------------------------------ */
struct CallBarringFeature {
    SsGroup basic_service;
    SsStatus ss_status;
};

struct CallBarringFeatureList{
    CallBarringFeature data[c_max_no_basic_service_groups];
};

struct CallBarringInfo {
    SsCode sc;
    INT feature_list_size;
    CallBarringFeatureList feature_list;
};

enum InterrogateSsChoice {
    SsStatusInterrogate                 = MN_SS_STATUS_INTERROGATE,
    SsForwardToNoInterrogate            = MN_SS_FORW_TO_NO_INTERROGATE,
    SsBasicServiceGroupListInterrogate  = MN_SS_BASIC_SERV_GROUP_LIST_INTERROGATE,
    SsForwwardFeatureListInterrogate    = MN_SS_FORW_FEATURE_LIST_INTERROGATE,
    SsCliRestrictInfoInterrogate        = MN_SS_CLI_RESTRICT_INFO_INTERROGATE,
    SsVoidInterrogate                   = MN_SS_VOID_INTERROGATE
};

struct SsGroupList {
    SsGroup data[c_max_no_basic_service_groups];
};

struct EmlppPriority {
    BOOLEAN                 in_use;
    EmlppPriorityLevel      value;
};

enum CliRestrictionOption {
    Permanent                   = MN_PERMANENT,
    TemporaryDefaultRestricted  = MN_TEMPORARY_DEFAULT_RESTRICTED,
    TemporaryDefaultAllowed     = MN_TEMPORARY_DEFAULT_ALLOWED,
    VoidCliRestriction          = MN_VOID_CLI_RESTRICTION
};

struct CliRestrictionInfo {
    SsStatus ss_status;
    CliRestrictionOption option;
    EmlppPriority   max_entitled_priority;
    EmlppPriority   default_priority;
};

struct InterrogateSsResult {
    InterrogateSsChoice     selector;
    SsStatus                ss_status;
    PhoneNumber             forward_to_number; // UINT8 forward_to_number[c_max_size_telephone_nr];
    INT                     basic_serv_group_list_size;
    SsGroup                 basic_serv_group_list[c_max_no_basic_service_groups];
    INT                     forward_feature_list_size;
    ForwardingFeature       forward_feature_list[c_max_no_basic_service_groups];
    CliRestrictionInfo      cli_restriction_info;
};

enum OverrideCategory {
    OverrideEnabled     = MN_OVERRIDE_ENABLED,
    OverrideDisabled    = MN_OVERRIDE_DISABLED,
    VoidOverride        = MN_VOID_OVERRIDE
};

struct SsData {
    SsCode ss_code;
    SsStatus ss_status;
    CliRestrictionOption cli_restriction_option;
    OverrideCategory override_category;
    SsGroupList basic_serv_group_list;
    EmlppPriority default_priority;
};


/*  ========================================================================
                                 Audio
    ======================================================================== */
/*  ------------------------------------------------------------------------
    AudioToneType
        external audio tone type (GSM 11.14) - defined in ms.h
    ------------------------------------------------------------------------ */
enum AudioToneType {
    DefaultTone          = DEFAULT_TONE,
    DialTone             = DIAL_TONE,
    CalledSubscriberBusy = CALLED_SUBSCRIBER_BUSY,
    CongestionTone       = CONGESTION_TONE,
    RadioPathAck         = RADIO_PATH_ACK,
    RadioPathNotAvail    = RADIO_PATH_NOT_AVAIL,
    ErrorTone            = ERROR_TONE,
    CallWaitingTone      = CALL_WAITING_TONE,
    RingingTone          = RINGING_TONE,
    GeneralBeep          = GENERAL_BEEP,
    PositiveAckTone      = POSITIVE_ACK_TONE,
    NegativeAckTone      = NEGATIVE_ACK_TONE,
};

/*  ------------------------------------------------------------------------
    AudioToneId
        Strange stuff! 
        Enums, typedefs etc. for L1 tone control messages. Must be removed 
        upon availability of audio drivers / audio control handler or 
        similar. Enum relies on same position as in aud_drv.h
    ------------------------------------------------------------------------ */
/*
enum AudioToneId {
    AudioToneDtmf0,                 // aud_tone_DTMF_0,
    AudioToneDtmf1,                 // aud_tone_DTMF_1,
    AudioToneDtmf2,                 // aud_tone_DTMF_2,
    AudioToneDtmf3,                 // aud_tone_DTMF_3,
    AudioToneDtmf4,                 // aud_tone_DTMF_4,
    AudioToneDtmf5,                 // aud_tone_DTMF_5,
    AudioToneDtmf6,                 // aud_tone_DTMF_6,
    AudioToneDtmf7,                 // aud_tone_DTMF_7,
    AudioToneDtmf8,                 // aud_tone_DTMF_8,
    AudioToneDtmf9,                 // aud_tone_DTMF_9,
    AudioToneDtmfHash,              // aud_tone_DTMF_hash,
    AudioToneDtmfAsterix,           // aud_tone_DTMF_asterix,

    AudioToneSvSubscriberBusy,      // aud_tone_sv_subscriber_busy,
    AudioToneSvCongestion,          // aud_tone_sv_congestion,
    AudioToneSvRadioPathAck,        // aud_tone_sv_radio_path_ack,
    AudioToneSvRadioPathNotAvail,   // aud_tone_sv_radio_path_not_avail,
    AudioToneSvErrorInfo,           // aud_tone_sv_error_info,
    AudioToneSvCallWaiting,         // aud_tone_sv_call_waiting,

    AudioToneInfoFreeTone,          // aud_tone_info_free_tone,
    AudioToneInfoLowBat,            // aud_tone_info_low_bat,

    AudioToneKey1,                  // aud_tone_key_1,
    AudioToneKey2,                  // aud_tone_key_2,
    AudioToneKey3,                  // aud_tone_key_3,
    AudioToneKey4,                  // aud_tone_key_4,

    AudioToneBroadcast1,            // aud_tone_broadcast_1,
    AudioToneBroadcast2,            // aud_tone_broadcast_2,
    AudioToneBroadcast3,            // aud_tone_broadcast_3,
    AudioToneBroadcast4,            // aud_tone_broadcast_4,

    AudioToneMessage1,              // aud_tone_message_1,
    AudioToneMessage2,              // aud_tone_message_2,
    AudioToneMessage3,              // aud_tone_message_3,
    AudioToneMessage4,              // aud_tone_message_4,

    AudioToneRinging1,              // aud_tone_ringing_1,
    AudioToneRinging2,              // aud_tone_ringing_2,
    AudioToneRinging3,              // aud_tone_ringing_3,
    AudioToneRinging4,              // aud_tone_ringing_4,
    AudioToneRinging5,              // aud_tone_ringing_5,
    AudioToneRinging6,              // aud_tone_ringing_6,
    AudioToneRinging7,              // aud_tone_ringing_7,
    AudioToneRinging8,              // aud_tone_ringing_8,
    AudioToneRinging9,              // aud_tone_ringing_9,
    AudioToneRinging10,             // aud_tone_ringing_10,
    AudioToneRinging11,             // aud_tone_ringing_11,
    AudioToneRinging12,             // aud_tone_ringing_12,

    AudioToneAlarm1,                // aud_tone_alarm_1

    AudioLastTone,                  // aud_last_tone

    AudioInvalidTone                // indicates that tone is not valid (needed for conversion)
};
*/

/*  ========================================================================
                                 CCBS
    ======================================================================== */

struct CcbsEntry {
    UINT8 ccbs_idx;
    PhoneNumber idle_subscriber_no;
    Subaddress  subaddress;
    ServiceGroup serv_group;    
};

typedef INT CcbsAction;

typedef INT CcbsStatus;

struct CcbsList{
    CcbsEntry ccbs_entry[5];
};


struct InterrogateCcbsResult{
    UINT8 ss_status;
    INT ccbs_que_length;
    CcbsList ccbs_list;
};


typedef BOOLEAN ReleaseComplete;




/*  ------------------------------------------------------------------------
    AudioDevice
    ------------------------------------------------------------------------ */
enum AudioDevice {
    DeviceSpeaker,                  // aud_ring_off -> turn off ring to activate speaker!!!
    DeviceBuzzer,                   // aud_ring_buzzer,
    DeviceVibrator,                 // aud_ring_vibrator,
    DeviceRingBuzzerVibrator,       // aud_ring_buzzer_vibrator
    };                  

struct AudioToneDuration {
    UINT8 units;
    UINT8 interval;
};

/*  ========================================================================
                                 Constants
    ======================================================================== */
const INT AdjustToneRpt     = 1;
const INT ClearToneRpt      = 3;
const INT KeyToneRpt        = 1;
const INT RingToneRpt       = 1;
const INT MsgAlertRpt       = 1;
const INT ErrorToneRpt      = 3;
const INT LowBattToneRpt    = 2;
const INT AlarmToneRpt      = 1;


/*****
* T_CHANNEL_MODE_RAW
* raw channel mode as received from network (GSM 04.08, 10.5.2.6)
* /vobs/ms-hosttest/mi/src/../../../stack-interface/globals/radio_res.pr,419,9
******/
/*
enum ChannelModeRaw{
    SignalingOnly   = MODE_SIGNALLING_ONLY,
    SpeechFull      = MODE_SPEECH_FULL,  
    SpeechHalf      = MODE_SPEECH_HALF,
    Data144         = MODE_DATA_144,       
    Data96          = MODE_DATA_96,
    Data48Full      = MODE_DATA_48_FULL,
    Data48Half      = MODE_DATA_48_HALF,    
    Data24Full      = MODE_DATA_24_FULL,    
    Data24Half      = MODE_DATA_24_HALF,
    SpeechFullV2    = MODE_SPEECH_FULL_V2,
    SpeechFullV3    = MODE_SPEECH_FULL_V3,  
    SpeechHalfV2    = MODE_SPEECH_HALF_V2,   
    SpeechHalfV3    = MODE_SPEECH_HALF_V3
};
*/

enum SignalStrengthMax{
    GsmSignalStrengthMax  = 63,
    UmtsSignalStrengthMax = 91
};

enum SignalQualityMax{
    GsmSignalQualityMax  = 7,
    UmtsSignalQualityMax = 49
};

//ms-interface-src/pr/ms_msg_mm_mn.pr,302,9)
enum GsmErrorCause {
    ImsiUnknownInHlr = ERR_IMSI_UNKNOWN_IN_HLR,
    IllegalMs = ERR_ILLEGAL_MS,
    ImsiUnknownInVlr = ERR_IMSI_UNKNOWN_IN_VLR,
    ImeiNotAccepted = ERR_IMEI_NOT_ACCEPTED,
    IllegalMe = ERR_ILLEGAL_ME,
    GprsNotAllowed = ERR_GPRS_NOT_ALLOWED,
    GprsGsmNotAllowed = ERR_GPRS_GSM_NOT_ALLOWED,
    MsIdentUnknown = ERR_MS_IDENT_UNKNOWN,
    ImpDetached = ERR_IMP_DETACHED,
    PlmnNotAllowed = ERR_PLMN_NOT_ALLOWED,
    LaNotAllowed = ERR_LA_NOT_ALLOWED,
    NatRoamingNotAllowed = ERR_NAT_ROAMING_NOT_ALLOWED,
    GprsPlmnNotAllowed = ERR_GPRS_PLMN_NOT_ALLOWED,
    NoSuitableCellsInLa = ERR_NO_SUITABLE_CELLS_IN_LA,
    MscNotReachable = ERR_MSC_NOT_REACHABLE,
    NetworkFailure = ERR_NETWORK_FAILURE,
    Congestion = ERR_CONGESTION,
    ServiceNotSupported = ERR_SERVICE_NOT_SUPPORTED,
    ReqServNotDescr = ERR_REQ_SERV_NOT_DESCR,
    ServiceTempOutOfOrder = ERR_SERVICE_TEMP_OUT_OF_ORDER,
    CallNotIdentified = ERR_CALL_NOT_IDENTIFIED,
    NoPdpContextActive = ERR_NO_PDP_CONTEXT_AKTIV,
    RetryOnNewCellBeg = ERR_RETRY_ON_NEW_CELL_BEG,
    RetryOnNewCellEnd = ERR_RETRY_ON_NEW_CELL_END,
    SemIncorrMsg = ERR_SEM_INCORR_MSG,
    InvManIe = ERR_INV_MAN_IE,
    MsgtypNotExists = ERR_MSGTYP_NOT_EXIST,
    MsgtypNotCompatible = ERR_MSGTYP_NOT_COMPATIBLE,
    InfElemNotExists = ERR_INF_ELEM_NOT_EXIST,
    ConIeErr = ERR_COND_IE_ERR,
    MsgNotCompatible = ERR_MSG_NOT_COMPATIBLE,
    ProtErrUnspecified = ERR_PROT_ERR_UNSPECIFIED,
#if !defined(APOXI_3GPP_REL_97_DOWNGRADE)
    MacFailure = ERR_MAC_FAILURE,
    SynchFailure = ERR_SYNCH_FAILURE,
    GsmAuthUnacceptable = ERR_GSM_AUTH_UNACCEPTABLE,
#else
    MacFailure,
    SynchFailure,
    GsmAuthUnacceptable,
#endif
    GsmNoCause
};

enum CallRefuseDirection {
#if defined(APOXI_ENABLE_MOC_CALL_RESTRICTION)
    IncommingRefuseDirection = MN_REFUSE_DIR_INCOMING,
    OutgoingRefuseDirection = MN_REFUSE_DIR_OUTGOING
#else
    IncommingRefuseDirection,
    OutgoingRefuseDirection
#endif
};
#endif  // Apc_SignalTypes_hpp

