/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_StackMsgMapTableEntry_hpp)
#define Apc_SignalHandler_StackMsgMapTableEntry_hpp

#include <Apc/StackMsgArgument.hpp>

typedef CHAR* StackMsgArgName;

/*  ========================================================================
    StackMsgMapTableEntry
    ======================================================================== */
struct StackMsgMapTableEntry {
    StackMsgArgId id;
#if defined (APOXI_RTOS_WIN32) 
    StackMsgArgName name;           // host implementation add on
    static BOOLEAN IsNameAvailable() { return (TRUE); }
#else
    static BOOLEAN IsNameAvailable() { return (FALSE); }
#endif 
    void (*send_signal_func)(const StackMsgArgument &);
};

#endif // Apc_SignalHandler_StackMsgMapTableEntry_hpp


