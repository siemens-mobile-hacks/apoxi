/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_StackMsgMapTableNode_hpp)
#define Apc_SignalHandler_StackMsgMapTableNode_hpp

#include <Kernel/Types.hpp>
#include <Apc/SignalHandler/StackMsgMapTableEntry.hpp>

class StackMsgMapTable;
/*  ========================================================================
    StackMsgMapTableNode
    ======================================================================== */
class StackMsgMapTableNode {
    friend class StackMsgMapTable;
    public:
        StackMsgMapTableNode(const StackMsgMapTableEntry *map_table, StackMsgArgId StackMsgArgId, StackMsgMapTableNode **node = 0);

        void Remove();

    private:
        const StackMsgMapTableEntry *m_map_table;
        StackMsgArgId m_last_entry;

        StackMsgMapTableNode *m_next;
        StackMsgMapTableNode **m_node_ptr;

        void SetNext(StackMsgMapTableNode *node);
        BOOLEAN SendSignal(const StackMsgArgument &arg);
        BOOLEAN SendSignalWithinTable(const StackMsgArgument &arg);
};

#endif // Apc_SignalHandler_StackMsgMapTableNode_hpp


