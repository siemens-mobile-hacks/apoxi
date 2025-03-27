/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Gprs_SimLockTypes_hpp)
#define Apc_Gprs_SimLockTypes_hpp

#include <Kernel/Types.hpp>

#include <Apc/SignalTypes.hpp>

enum LockStatus {
    SimLocked =  SI_LOCKED,
    SimUnlocked = SI_UNLOCKED,
    };

// T_SI_LOCK_STATES
struct SimLockStates {
    LockStatus  network;
    LockStatus  sp;
    LockStatus  sim;
    LockStatus  corporate;
};

#endif  // Apc_Gprs_SimLockTypes_hpp


