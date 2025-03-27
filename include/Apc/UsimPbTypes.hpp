/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_UsimPbTypes_hpp)
#define Apc_UsimPbTypes_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>

#include <Apc/SignalTypes.hpp>
#include <Auxiliary/BitField.hpp>

/*  ========================================================================
                    Simulated structures from stack
    ========================================================================*/

// define types if stack does not support necessary symbols, then fake it, at least for simulation

#if ! defined(PB_MAX_SLICE)

#define PB_MAX_SLICE            2
#define PB_MAX_FILE_TYPE_ENTITY 10
#define PB_MAX_GROUP            10

#define PB_CLIENT_FLAG_AUTOLOAD 0

typedef SDL_Integer PB_RESULT;
#define PB_SUCCESSFUL         0  
#define PB_SUCCESSFUL_UID     1  
#define PB_SKIPPED            2  
#define PB_NO_FREE_RECORD     3  
#define PB_TO_FEW_FREE_EXT    4  
#define PB_BUFFER_IS_NULL     5  
#define PB_WRONG_REF_REC      6  
#define PB_DATA_TYPE_MISMATCH 7  
#define PB_WRONG_DATA_TYPE    8  
#define PB_WRONG_HANDLE       9  
#define PB_BUFFER_TO_SMALL    10  
#define PB_WRONG_REC_NUMBER   11  
#define PB_WRONG_STRUCTURE    12  
#define PB_NOT_LOCATED        13 
#define PB_NOT_SEL            14 
#define PB_NOT_EXIST          15 
#define PB_NOT_LOADED         16 
#define PB_WRONG_LOCATION     17  
#define PB_TECHNICAL_PROBLEM  18  

typedef SDL_Integer T_PB_LOCATION;
#define  PB_NOT_SELECTED    0
#define  PB_SIM             1
#define  PB_GLOBAL          2
#define  PB_APPL            3

typedef SDL_Integer T_PB_DATA;
#define  PB_AAS_DATA        0
#define  PB_GAS_DATA        1
#define  PB_CCP1_DATA       2
#define  PB_EXT1_DATA       3

typedef SDL_Integer T_PB_REF;
#define  PB_ANR_REF         0       
#define  PB_SNE_REF         1   
#define  PB_EMAIL_REF       2    

typedef SDL_Integer T_PB_SIGNAL_TYPE;
#define  PB_INDICATION      0       
#define  PB_RESPONSE        1   
#define  PB_REFRESH         2    
#define  PB_REF_REFRESH     3

typedef SDL_Integer T_PB_LINK_TYPE;
#define  PB_LINK_TYPE_1     0       
#define  PB_LINK_TYPE_2     1   
#define  PB_LINK_TYPE_3     2    

typedef struct {
    SDL_Boolean exist;
    SDL_Boolean last_used;
} T_PB_STATE;

typedef struct {
    T_PB_LOCATION current_loc;
    T_PB_STATE sim;
    T_PB_STATE usim_global;
    T_PB_STATE usim_appl;
} T_PB_LOC_REPORT;

typedef struct {
    byte    l_type; // T_PB_LINK_TYPE
    byte    handle;
    byte    nof_rec;
    byte    len_rec;
}  T_PB_FILE_DESC;

typedef struct {
    T_PB_FILE_DESC  A[PB_MAX_FILE_TYPE_ENTITY];
}  T_PB_FILE_IN_SLICE;

typedef struct {
    T_PB_FILE_DESC  A[PB_MAX_SLICE];
}  T_PB_UNIQUE_FILE;

typedef struct {
    T_PB_FILE_IN_SLICE  A[PB_MAX_SLICE];
}  T_PB_FILE_A;

typedef struct {
    byte  A[PB_MAX_SLICE];
}  T_PB_GROUP_NUMBER;

typedef struct {
    word        nof_entity;
    T_PB_FILE_A a;
}  T_PB_REF_FILE;


typedef struct {
    byte                nof_slice;
    T_PB_UNIQUE_FILE    adn;
    T_PB_UNIQUE_FILE    gas;
    T_PB_UNIQUE_FILE    aas;
    T_PB_UNIQUE_FILE    ccp1;

    T_PB_REF_FILE       anr;
    T_PB_REF_FILE       sne;
    T_PB_REF_FILE       email;

    SDL_Boolean         hidden_key_supported; 
    SDL_Boolean         sync_supported;
    T_PB_GROUP_NUMBER   nof_group;

}  T_PB_DESCRIPTOR;

typedef struct {
    byte  A[PB_MAX_FILE_TYPE_ENTITY];
}  T_PB_REFERENCE;

typedef struct {
    byte  A[PB_MAX_GROUP];
}  T_PB_GROUPING;

typedef struct {
    SDL_Boolean adn_core;
    SDL_Boolean grouping;
    SDL_Boolean pbc_hidden_info; 
}  T_PB_CHANGED_FIELD;

typedef struct {
   T_DATA           adn_core;
   T_PB_GROUPING    grouping;
   byte             pbc_hidden_info; 
   word             uid;
    T_PB_CHANGED_FIELD refresh_info;
}  T_PB_RECORD;

typedef struct {
    T_PB_REFERENCE  anr_ref;
    T_PB_REFERENCE  sne_ref;
    T_PB_REFERENCE  email_ref;  
}  T_PB_REF_RECORD;

typedef struct {
    byte    A[PB_MAX_SLICE];
}  T_PB_UNIQUE_FILE_FILL_STATUS;

typedef struct {
    byte    A[PB_MAX_FILE_TYPE_ENTITY];
}  T_PB_REF_FILE_FILL_STATUS_A;

typedef struct {
    T_PB_REF_FILE_FILL_STATUS_A A[PB_MAX_SLICE];
}  T_PB_REF_FILE_FILL_STATUS;

typedef struct {
    T_PB_UNIQUE_FILE_FILL_STATUS    adn;
    T_PB_UNIQUE_FILE_FILL_STATUS    gas;
    T_PB_UNIQUE_FILE_FILL_STATUS    aas;
    T_PB_UNIQUE_FILE_FILL_STATUS    ccp1;
    T_PB_UNIQUE_FILE_FILL_STATUS    ext1;
    T_PB_REF_FILE_FILL_STATUS       anr;
    T_PB_REF_FILE_FILL_STATUS       sne;
    T_PB_REF_FILE_FILL_STATUS       email;
}  T_PB_FILL_STATUS;

typedef struct {
    byte A[1];
} T_PB_CLIENT_FLAGS;

#endif

/*  ========================================================================
                                  Constants
    ========================================================================*/

// defines the maximum number of EF-ADNs per Phonebook
const INT c_pb_max_slices = PB_MAX_SLICE;

// defines the maximum number of linked entries per ADN record
const INT c_pb_max_file_type_per_record = PB_MAX_FILE_TYPE_ENTITY;

// defines the maximum number of groups per ADN record
const INT c_pb_max_groups = PB_MAX_GROUP;

// defines an invalid group value as defined in 3GPP 
const UINT8 c_no_group_value = 0x00;

// defines an invalid aas index value as defined in 3GPP 
const UINT8 c_no_aas_record_value = 0x00;

// defines the bit used for client auto loading  
const INT c_pb_client_autoload_flag = PB_CLIENT_FLAG_AUTOLOAD;


/*  ========================================================================
                                  UsimPbResult
    ========================================================================*/
// (ms.h: T_PB_SIGNAL_TYPE)
enum UsimPbSignalType {
    UsimPbIndication = PB_INDICATION,        
    UsimPbResponse = PB_RESPONSE,
    UsimPbRefresh = PB_REFRESH,   
    UsimPbRefRefresh = PB_REF_REFRESH       
};

/*  ========================================================================
                                  UsimPbResult
    ========================================================================*/
// (ms.h: PB_RESULT)
enum UsimPbResult {
    UsimPbSuccessful = PB_SUCCESSFUL,        
    UsimPbSuccessfulUid = PB_SUCCESSFUL_UID,
    UsimPbSkipped = PB_SKIPPED,
    UsimPbNoFreeRecord = PB_NO_FREE_RECORD,
    UsimPbTooFewExtRecs = PB_TO_FEW_FREE_EXT,
    UsimPbBufferIsNull = PB_BUFFER_IS_NULL,
    UsimPbWrongRefRecord = PB_WRONG_REF_REC,
    UsimPbDataTypeMismatch = PB_DATA_TYPE_MISMATCH,
    UsimPbWrongDataType = PB_WRONG_DATA_TYPE,
    UsimPbWrongHandle = PB_WRONG_HANDLE,
    UsimPbBufferTooSmall = PB_BUFFER_TO_SMALL,
    UsimPbWrongRecNumber = PB_WRONG_REC_NUMBER,
    UsimPbWrongStructure = PB_WRONG_STRUCTURE,
    UsimPbNotLocated = PB_NOT_LOCATED,
    UsimPbNotSel = PB_NOT_SEL,
    UsimPbNotExisting = PB_NOT_EXIST,
    UsimPbNotLoaded = PB_NOT_LOADED,
    UsimPbWrongLocation = PB_WRONG_LOCATION,
    UsimPbTechnicalProblem = PB_TECHNICAL_PROBLEM,
    UsimPbUndefined       
};

/*  ========================================================================
                                  UsimPbLocation
    ========================================================================*/
// (ms.h: T_PB_LOCATION)
enum UsimPbLocation {
    UsimPbNotSelected   = PB_NOT_SELECTED,
    UsimPbSim           = PB_SIM,
    UsimPbGlobal        = PB_GLOBAL,
    UsimPbApplication   = PB_APPL
};


/*  ========================================================================
                                  UsimPbAddType
    ========================================================================*/
// (ms.h: T_PB_DATA)
enum UsimPbAddType {
    UsimPbAas       = PB_AAS_DATA,
    UsimPbGas       = PB_GAS_DATA,
    UsimPbCcp1      = PB_CCP1_DATA,
    UsimPbExt1      = PB_EXT1_DATA,
    UsimPbInvalidAdd
};

/*  ========================================================================
                                  UsimPbRefType
    ========================================================================*/
// (ms.h: T_PB_REF_FILE)
enum UsimPbRefType {
    UsimPbAnr       = PB_ANR_REF,
    UsimPbSne       = PB_SNE_REF,
    UsimPbEmail     = PB_EMAIL_REF,
    UsimPbInvalidRef
};

/*  ========================================================================
                                  UsimPbLinkType
    ========================================================================*/
// (ms.h: T_PB_LINK_TYPE)
enum UsimPbLinkType {
    UsimPbType1     = PB_LINK_TYPE_1,
    UsimPbType2     = PB_LINK_TYPE_2,
    UsimPbType3     = PB_LINK_TYPE_3,
};


/*  ========================================================================
                             mapping of enums to chars
    ========================================================================*/

const CHAR * GetUsimPbRefTypeName(UsimPbRefType type);
const CHAR * GetUsimPbAddTypeName(UsimPbAddType type);
const CHAR * GetUsimPbLinkTypeName(UsimPbLinkType type);

/*  ========================================================================
                                  UsimPbRwRecord
    ========================================================================*/
// (ms.h: T_PB_RECORD)
class UsimPbRwRecord {
    public:
        // default constructor 
        UsimPbRwRecord();

        // buffer must be allocated and deleted outside 
        UsimPbRwRecord(INT length, UINT8 * buffer, 
                       INT grplength = 0, UINT8 * groupvector = 0, 
                       UINT8 hiddeninfo = 0x00);

        ~UsimPbRwRecord() {
            Clear();
        }

        void Clear();

        const UINT8 * GetAdnBuffer() const { return (UINT8*)m_record.adn_core.data_ptr; }
        const UINT8 * GetGroupVector() const { return &m_record.grouping.A[0]; }
        UINT8 GetHiddenInfo() const { return m_record.pbc_hidden_info; }
        UINT16 GetUid() const { return m_record.uid; }

        T_PB_RECORD m_record;
};

/*  ========================================================================
                                  UsimPbRefRecord
    ========================================================================*/
// (ms.h: T_PB_REF_RECORD)
class UsimPbRefRecord {
    public:
        UsimPbRefRecord();

        UsimPbRefRecord(const T_PB_REF_RECORD & record) {
            m_record = record;
        };

        UsimPbRefRecord & operator = (const UsimPbRefRecord & record) {
            if(&record != this) {
                m_record = record.m_record;
            }
            return *this;
        }

        void Clear();

        UINT8 GetAnrRecordNo(UINT idx) const { return m_record.anr_ref.A[idx]; }
        UINT8 GetSneRecordNo(UINT idx) const { return m_record.sne_ref.A[idx]; }
        UINT8 GetEmailRecordNo(UINT idx) const { return m_record.email_ref.A[idx]; }

        T_PB_REF_RECORD m_record;
};

/*  ========================================================================
                                  UsimPbChangedField
    ========================================================================*/
// (ms.h: T_PB_CHANGED_FIELD)
class UsimPbChangedField {
    public:
        UsimPbChangedField();

        UsimPbChangedField(const UsimPbChangedField & field) {
            m_field = field.m_field;
        };

        UsimPbChangedField(BOOLEAN adn, BOOLEAN groups = FALSE, BOOLEAN hiddeninfo = FALSE);

        UsimPbChangedField(const T_PB_CHANGED_FIELD & field) {
            m_field = field;
        };

        UsimPbChangedField & operator = (const UsimPbChangedField & field) {
            if(&field != this) {
                m_field = field.m_field;
            }
        }

        void Clear();

        void SetAdnChanged(BOOLEAN change = TRUE) { m_field.adn_core = change; }
        void SetGroupsChanged(BOOLEAN change = TRUE) { m_field.grouping = change; }
        void SetHiddenInfoChanged(BOOLEAN change = TRUE) { m_field.pbc_hidden_info = change; }

        T_PB_CHANGED_FIELD m_field;
};

/*  ========================================================================
                                  UsimPbGroups
    ========================================================================*/
// (ms.h: T_PB_GROUPING)
class UsimPbGroups {
    public:
        UsimPbGroups() { Clear(); }

        UsimPbGroups(const UsimPbGroups & groups) {
            m_groups = groups.m_groups;
            m_set = groups.m_set;
        };

        UsimPbGroups(const T_PB_GROUPING & groups) {
            m_groups = groups;
            m_set.Clear();
        };

        UsimPbGroups & operator = (const UsimPbGroups & groups) {
            if(&groups != this) {
                m_groups = groups.m_groups;
                m_set = groups.m_set;
            }
        }

        void Clear() { 
            memset(&m_groups,c_no_group_value,sizeof(m_groups)); 
            m_set.Clear();
        }

        void SetGroup(UINT idx, UINT8 group) { 
            m_groups.A[idx] = group;
            m_set.SetTrue(idx);
        }
        UINT8 GetGroup(UINT idx) const { 
            return m_groups.A[idx];
        }
        BOOLEAN WasChanged(UINT idx) const { 
            return m_set.GetBit(idx);
        }
        BOOLEAN IsUsed() const { 
            return m_set.Get()!=0;
        }

        T_PB_GROUPING m_groups;
        BitField16    m_set; 
};

/*  ========================================================================
                                  UsimPbLocReport
    ========================================================================*/
// (ms.h: T_PB_LOC_REPORT)
class UsimPbLocReport {
    public:
        UsimPbLocReport() { Clear(); }

        UsimPbLocReport & operator = (const UsimPbLocReport & location_info) {
            if(&location_info != this) {
                m_location_info = location_info.m_location_info;
            }
            return *this;
        }

        UsimPbLocation GetCurrentSelectedPb() const { return (UsimPbLocation)m_location_info.current_loc; }
        BOOLEAN IsSimPbExisting() const { return m_location_info.sim.exist; }
        BOOLEAN WasSimPbLastUsed() const { return m_location_info.sim.last_used; }
        BOOLEAN IsGlobalUsimPbExisting() const { return m_location_info.usim_global.exist; }
        BOOLEAN WasGlobalUsimPbLastUsed() const { return m_location_info.usim_global.last_used; }
        BOOLEAN IsApplUsimPbExisting() const { return m_location_info.usim_appl.exist; }
        BOOLEAN WasApplUsimPbLastUsed() const { return m_location_info.usim_appl.last_used; }

        void Clear() { 
            memset(&m_location_info,0x00,sizeof(m_location_info)); 
            m_location_info.current_loc = (T_PB_LOCATION)UsimPbNotSelected;
        }

        T_PB_LOC_REPORT m_location_info;
};

/*  ========================================================================
                                  UsimPbFillStatus
    ========================================================================*/
// (ms.h: T_PB_FILL_STATUS)
class UsimPbFillStatus {
    public:
        UsimPbFillStatus() { Clear(); }

        UsimPbFillStatus & operator = (const UsimPbFillStatus & status) {
            if(&status != this) {
                m_status = status.m_status;
            }
            return *this;
        }
        void Clear() { 
            memset(&m_status,0x00,sizeof(m_status)); 
        }

        T_PB_FILL_STATUS m_status;
};

#endif  // Apc_UsimPbTypes_hpp


