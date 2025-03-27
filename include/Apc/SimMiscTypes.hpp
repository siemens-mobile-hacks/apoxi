/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Gprs_SimMiscTypes_hpp)
#define Apc_Gprs_SimMiscTypes_hpp

#include <Kernel/Types.hpp>

#include <Apc/SignalTypes.hpp>

/*  ------------------------------------------------------------------------
    sim information structure
    ------------------------------------------------------------------------ */

struct AddInfo {
    UINT8 val[4];
};

typedef T_SI_SIM_CHANGED_STATE SimChangedState;

struct SimInfo {
    SimIndicator            sim_indicator;      
    IccId                   iccid;
    SimType                 sim_type;
    SimPhase                sim_phase;          
    ChvStatus               chv1_status;
    ChvStatus               chv2_status;        
    ChvAttemptsStruct       chv_attempts;       
    Language                pref_language;
    AddInfo                 add_info;
    ExtLanguage             ext_pref_language;
    UINT8                   changed_indication; // 0x00 not changed, 0xff new, 0x01->0xfe new but used before
    SimChangedState         changed_state;
};

#endif  // Apc_Gprs_SimMiscTypes_hpp


