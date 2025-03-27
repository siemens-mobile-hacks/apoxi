/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_HandlerId_hpp)
#define Asc_HandlerId_hpp

#include <Kernel/Types.hpp>
#include <Kernel/System.hpp>
#include <Kernel/Os/Os.hpp>


/*  ========================================================================
    HandlerId
    ======================================================================== */
enum HandlerId {
    AccHandlerId,
    AocHandlerId,
#ifdef APOXI_COMPAT_2_2_0

    BattHandlerId,
#endif

    CallHandlerId,
    CbsHandlerId,
#ifdef APOXI_COMPAT_2_2_0

    ChrHandlerId,
#endif

    CrssHandlerId,
    MocVoiceHandlerId,
    MtcVoiceHandlerId,
    NetworkHandlerId,
    PlmnHandlerId,
    PowerHandlerId,
#ifdef APOXI_COMPAT_2_0_0

    RtcHandlerId,
#endif

    SigHandlerId,
    SimHandlerId,
    AtcHandlerId,
    SimTkHandlerId,
    SimTkLceHandlerId,
    SmsHandlerId,
    SsHandlerId,
    SsMainHandlerId,
    // Base Handler for Supplementary Service handler
    SsBaseHandlerId,
    CallWaitingHandlerId,
    CallForwardingHandlerId,
    CallBarringHandlerId,
    EmlppHandlerId,
    ClipHandlerId,
    ClirHandlerId,
    ColpHandlerId,
    ColrHandlerId,
    UssdHandlerId,
    MoUssdHandlerId,
    CallControlHandlerId,
    CallDeflectionHandlerId,
    BootHandlerId,
    MultiSlotHandlerId,

    SsCcbsHandlerId,
    CnapHandlerId,

#if defined(APOXI_LIB_ADDON_VR)

    VrHandlerId,
#endif
    
#if defined(APOXI_UUS_SUPPORT)
    UusHandlerId,
#endif  

#if defined(APOXI_LIB_ADDON_MMCALL)
    MmCallHandlerId,
#endif

    MaxHandlerId,
};

#endif  // Asc_HandlerId_hpp

