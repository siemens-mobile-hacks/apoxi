/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_StackMsgProcessor_hpp)
#define Apc_SignalHandler_StackMsgProcessor_hpp

#include <Apc/SignalHandler/ProcessNode.hpp>

class StackMsgArgument;

/*  ========================================================================
    StackMsgProcessor
    ======================================================================== */
class StackMsgProcessor {
    public:
        static void Init(const ProcessNode &process_node);

        static ProcessPtr GetProcessPtr() { return m_process_ptr; }
        static void PostFromStackMsg(StackMsgArgument * arg);

    protected:
        static ProcessPtr m_process_ptr;
};

#endif  // Apc_SignalHandler_StackMsgProcessor_hpp


