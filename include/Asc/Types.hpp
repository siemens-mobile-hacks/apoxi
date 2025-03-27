/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Types_hpp)
#define Asc_Types_hpp

#include <Apc/SignalTypes.hpp>

typedef INT CallIndex;
typedef INT ChannelNo;

const INT c_max_mpty_members = 5;
const INT c_max_calls = 14;

const ChannelNo c_max_channels = (ChannelNo)2;
const ChannelNo c_null_channel_no = (ChannelNo)-1;
const CallIndex c_null_call_index = (CallIndex)-1;
const CallIndex c_mpty_indication = (CallIndex)c_max_calls + 1;

const UINT32 c_sem_obtain_timeout = 500;    // 500 ms UINT32 instead of Ticks!!!
const UINT32 c_mutex_timeout = 500;         // 500 ms


enum CallApiRc {
    NoError,
    CallDataLocked,
    NoNetwork,
    ActiveCallDetected,
    ActiveCallRequired,
    HeldCallDetected,
    HeldCallRequired,
    SetupCallDetected,
    SpeechCallRequired,
    MaxCallCountExceeded,
    CallSetupRejected,
    HoldRequestRejected,
    RetrieveRequestRejected,
    JoinCallsRejected,
    InvalidCallIndex,
    VoidCallIndex,
    MptyCallRequired,
    MptyCallDetected,
    ActiveMptyRequired,
    MaxMptyMemberCountExceeded,
    InvalidMptyMemberCount,
    CallNotMptyMember,
    CallDisconnected,
    SupplementaryServiceFailed,
    SecondCallMissing,
    UnexpectedResult,
    SimToolkitCallSetupFailed,
    DataCallDetected,
    DataCallRequired,
    MocChangedToSupplementaryService,
    MocChangedToUssd,
    SwapRequestRejected,
    CallAcceptForbidden,
    NotSupported
};


enum ClearCause {
    SubscriberBusy = UserBusy,
    // This cause indicates that the equipment sending this cause does not wish
    // to accept this call, although it could have accepted the call because 
    // the equipment sending this cause is neither busy nor incompatible.
    RejectCall = CallRejected   // obsolete
};


enum SsApiRc {
    UnspecifedRc,
    Success, 
    SupplementaryServicePending,
    SupplementaryServiceNotPending,
    InvalidTipd,
    InvalidServiceCode,
    InvalidMmiServiceGroup,
    InvalidBasicService,
    InvalidTimeOut,
    InvalidPhoneNumber,
    SupplementaryServiceDenied,
    NormalServiceRequired,
    SsDataLocked,
    ConfPasswordMismatch,
    SupplementaryServiceChangedToMoc,
    SupplementaryServiceChangedToSs,
    SupplementaryServiceChangedToUssd,
    UssdTransactionError,
    InvalidPriority,
    SupplementaryServiceNotSupported
};


struct CallEvent {

    enum Action {
        MocInSetup,     
        MocEstablished,     // an moc has been successfully established
        MocRejected,        // an moc has been rejected
        MtcIsWaiting,       // an mtc has arrived and waits to be accepted/rejected
        // MtcAccepted,
        // MtcRejected,     // waiting mtc has been rejected by user
        MtcEstablished,     // waiting mtc has ben sucessfully established
        CallReleased,       // call released by user
        CallDisconnected,   // call disconnected by remote party
        CallIsHeld,         // active call has been put on hold
        CallRetrieved,      // held call has been retrieved
        EctAccomplished,    // ect procedure started disconnnect msgs will follow-up
        MultipartyJoin,
        MultiPartyOnHold,
        MultiPartyRetrieved,
        MultiPartyReleased,
        MultiPartySplitted,

        // For MM Calls
        MmMocInSetup,
        MmMocEstablished,
        MmMocRejected,
        MmMtcIsWaiting,
        MmMtcEstablished,
        MmCallReleased,
        MmCallDisconnected
    } ;

    Action action;          // what happened
    CallIndex call_index;   // which call was affected/c_null_call_index
};

/*
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
    CallIsCleared       = MN_CALL_IS_CLEARED,
    CallModifyIndicated = MN_CALL_MODIFY_INDICATED,
    CallModifyStarted   = MN_CALL_MODIFY_STARTED,
    CallModifyCompleted = MN_CALL_MODIFY_COMPLETED,
    CallModifyRejected  = MN_CALL_MODIFY_REJECTED
*/

enum DisconnectingMode {
    UserDisconnetion,
    NetWorkDisconnection,
    NotSpecified
};


enum TtyMode {
#if defined APOXI_CTM
    TtyOff     = TTY_MODE_OFF,
    TtyAuto    = TTY_MODE_AUTO,
    TtyVco     = TTY_MODE_VCO,
    TtyHco     = TTY_MODE_HCO,
#else
    TtyOff  = 0,
    TtyAuto = 1,
    TtyVco  = 2,
    TtyHco  = 3,
#endif
    TtyModeUnknown = 4
};

enum TtySpeed {
#if defined APOXI_CTM
    Tty45_5 = TTY_45_5_BAUDOT,
    Tty50_0 = TTY_50_0_BAUDOT,
#else
    Tty45_5 = 0,
    Tty50_0 = 1,
#endif
    TtySpeedUnknown = 2
};

#endif  // Asc_Types_hpp

