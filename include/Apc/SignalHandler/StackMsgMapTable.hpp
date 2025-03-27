/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_StackMsgMapTable_hpp)
#define Apc_SignalHandler_StackMsgMapTable_hpp

class StackMsgArgument;
class StackMsgMapTableNode;
/*  ========================================================================
    StackMsgMapTable
    ======================================================================== */
class StackMsgMapTable {
    friend class StackMsgMapTableNode;
    public:
        static void SendSignal(const StackMsgArgument &arg);

    private:
        static StackMsgMapTableNode *m_anchor;
        static void Attach(StackMsgMapTableNode *node);
        static void Remove(StackMsgMapTableNode *node);
};

#endif // Apc_SignalHandler_StackMsgMapTable_hpp


