/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_LockTypes_hpp)
#define Apc_LockTypes_hpp

#include <Kernel/Types.hpp>
#include <Kernel/Os/Os.hpp>

#include <Apc/SignalTypes.hpp>

/*  ========================================================================
                                  SecLockAction
    ========================================================================*/
// (ms.h: T_SI_LOCK_ACTION)
enum SecLockAction {
    SecUnlockAction     = SI_LOCK_CMD_UNLOCK,
    SecChangePwdLock    = SI_LOCK_CMD_CHANGE_PWD,
    SecStartupLock      = SI_LOCK_CMD_STARTUP,
    SecRefreshLock      = SI_LOCK_CMD_REFRESH,
    SecDepersSmsLock    = SI_LOCK_CMD_DEPERS_SMS,
    SecGetProfileLock   = SI_LOCK_CMD_GET_PROFILE
};

/*  ========================================================================
                                  SecLockTypes
    ========================================================================*/
// (ms.h: T_SI_LOCK_TYPES)
enum SecLockType {
    SecNetworkLock          = SI_NETWORK_LOCK ,
    SecNetworkSubsetLock    = SI_NETWORK_SUBSET_LOCK ,
    SecSpLock               = SI_SP_LOCK ,
    SecCorporateLock        = SI_CORPORATE_LOCK,
    SecSimLock              = SI_SIM_LOCK ,
    SecAtLock               = SI_AT_LOCK,
    SecNofLock              = SI_NOF_LOCKS,
    SecPfLock               = SI_PF_LOCKS,
    SecNofTypes             = SI_NOF_TYPES,
};

/*  ========================================================================
                                  SecLockCauses
    ========================================================================*/
// (ms.h: T_SI_LOCK_CAUSES)
enum SecLockCause {
    SecSucceded         = SI_SEC_SUCCEEDED,
    SecLockInvalid      = SI_SEC_LOCK_INVALID,
    SecUnauthorisized   = SI_SEC_UNAUTHORISIZED_ACTION,
    SecPersCodeError    = SI_SEC_PERS_CODE_ERROR,
    SecControlKeyError  = SI_SEC_CONTROL_KEY_ERROR,
    SecStorageError     = SI_SEC_STORAGE_ERROR,
    SecNoMoreTrials     = SI_SEC_NO_MORE_TRIALS,
};

/*  ========================================================================
                                  SecLockStatus
    ========================================================================*/
// (ms.h: T_SI_LOCK_STATUS)
enum SecLockStatus {
    SecLockArmed            = SI_LOCK_ARMED,
    SecLockActive           = SI_LOCK_ACTIVE,
    SecLockPermanentActive  = SI_LOCK_PERMANENT_ACTIVE,
    SecLockBlocked          = SI_LOCK_BLOCKED,
    SecLockDeactive         = SI_LOCK_DEACTIVE,
    SecLockDisabled         = SI_LOCK_DISABLED,
    SecLockAutoActivated    = SI_LOCK_AUTOACTIVATED,
    SecLockLastState        = SI_SEC_LAST_STATE,
    SecLockLocked           = SI_LOCKED,
    SecLockUnlocked         = SI_UNLOCKED,
};

/*  ========================================================================
                                  SecLockResult
    ========================================================================*/
// (ms.h: T_SI_LOCK_RESULT)
enum SecLockResult {
    SecContinueOperation    = SI_SEC_CONTINUE_OPERATION,
    SecVerificationNeeded   = SI_SEC_VERIFICATION_NEEDED,
    SecNoFurtherOperation   = SI_SEC_NO_FURTHER_OPERATION,
    SecLockError            = SI_SEC_LOCK_ERROR,
    SecUnknownResult        = SI_UNKNOWN_RES,
    SecProfileUpdate        = SI_PROFILE_UPDATE,
    SecImeiInvalid          = SI_SEC_IMEI_INVALID,

};

/*  ========================================================================
                                  SecLockCode
    ========================================================================*/
// (ms.h: T_SI_LOCK_CODE)
struct SecLockCode {
    UINT8 val[17];
};


/*  ========================================================================
                                  SecMmiConfigData
    ========================================================================*/
// (ms.h: T_SI_MMI_CONFIG_DATA)
struct SecMmiConfigData {
    UINT8 val[2];
};


/*  ========================================================================
                                  SecLockCommand
    ========================================================================*/
// (ms.h: T_SI_LOCK_CMD)
struct SecLockCommand {
    SecLockAction action;
    SecLockType   type;   
    SecLockCode   oldpwd;
    SecLockCode   newpwd;
};

/*  ========================================================================
                                  SecLockDescriptor
    ========================================================================*/
// (ms.h: T_SI_LOCK_DESCRIPTOR)
struct SecLockDescriptor {
    SecLockType   lock_type;      
    SecLockStatus lock_status;    
    SecLockResult lock_result;
    UINT8         lock_dcp_sup;
    UINT8         lock_retrial_method;
    INT           lock_retrial_count;
    UINT32        lock_time;
    UINT8         lock_order;     
};

/*  ========================================================================
                                  SecLocks
    ========================================================================*/
// (ms.h: T_SI_LOCKS)

const INT c_max_no_sec_locks = 6;

struct SecLocks {
    SecLockDescriptor val[c_max_no_sec_locks];    
};

/*  ========================================================================
                                  SecLockStates
    ========================================================================*/
// (ms.h: T_SI_LOCK_STATES)
struct SecLockStates {
    INT              no_locks;    
    UINT8            no_rfiles;   
    SecLockCause     lock_cause;
    SecLocks         locks;
    SecLockResult    lock_result;
    INT              tracediag;
    SecMmiConfigData mmi_configuration;
};

#endif  // Apc_LockTypes_hpp


