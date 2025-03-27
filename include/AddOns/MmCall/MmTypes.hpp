/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(AddOn_MmCall_Types_hpp)
#define AddOn_MmCall_Types_hpp

const INT c_invalid_call_id = -1;

enum MmCallState {
    CalledPartyAlerting,
    MtcReady,
    MtcArrived,
    MmCallReleased,
    MmCallOnHold,
    MmCallDisconnecting,
    MmCallDisconnectingByUser,
    MmCallDisconnectingByNetwork,
    MmCallDisconnected,
    MmCallDisconnectedByUser,
    MmCallDisconnectedByNetwork,
    MmMocSetupAccept,
    MmMocInSetup,
    MmCallProgressIndication,

    SetupConfirmation,
    AcceptConfirmation
};

enum XCallStat {
    XCallStatActive = 0,
    XCallStatHold = 1,
    XCallStatDialling = 2,
    XCallStatMOAlerting = 3,
    XCallStatMtRinging = 4,
    XCallStatMtWaiting = 5,
    XCallStatDisconnected = 6
};


enum XaocServiceState {
    XnoAoc = 0,
    XaocInformation = 1,
    XaocCharging = 2
};

#endif // AddOn_MmCall_Types_hpp

