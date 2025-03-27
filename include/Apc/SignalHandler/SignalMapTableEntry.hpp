/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_SignalMapTableEntry_hpp)
#define Apc_SignalHandler_SignalMapTableEntry_hpp

#include <Kernel/Types.hpp>
#include <Apc/SignalTypes.hpp>

#include <stack/sdl_macros.h>

typedef ApoxiSdlSignalIdType SdlSignalId;
typedef ApoxiSdlSignalNameType SdlSignalName;
typedef ApoxiSdlProcessPtrType ProcessPtr;

/*  ========================================================================
    SignalMapTableEntry
    ======================================================================== */
struct SignalMapTableEntry {
    SdlSignalId   id;
#if defined (APOXI_RTOS_WIN32) 
    SdlSignalName name;         // host implementation
    static BOOLEAN IsNameAvailable() { return (TRUE); }
#else
    static BOOLEAN IsNameAvailable() { return (FALSE); }
#endif
    void (*post_message_func)(const ProcessPtr &);
};

#endif // Apc_SignalHandler_SignalMapTableEntry_hpp


