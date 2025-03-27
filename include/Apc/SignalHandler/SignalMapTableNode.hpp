/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_SignalMapTableNode_hpp)
#define Apc_SignalHandler_SignalMapTableNode_hpp

#include <Kernel/Types.hpp>
#include <Apc/SignalHandler/SignalMapTableEntry.hpp>

class ProcessNode;
class SignalMapTable;
/*  ========================================================================
    SignalMapTableNode
    ======================================================================== */
//TODO: What is this? murrayc.
class SignalMapTableNode {
    friend class SignalMapTable;
    public:
        //TODO: Please explain these parameters. For instance, last_entry seems to always be LAST_SIGNAL_CODE. muraryc. 
        SignalMapTableNode(const SignalMapTableEntry *map_table, SdlSignalId last_entry, SignalMapTableNode **node = 0);

        void Remove();
        
    private:
        const SignalMapTableEntry *m_map_table;
        SdlSignalId m_last_entry;

        SignalMapTableNode *m_next;
        SignalMapTableNode **m_node_ptr;
        
        void SetNext(SignalMapTableNode *node);
        BOOLEAN PostMessage(const ProcessNode &process_node);
        BOOLEAN PostMessageWithinTable(const ProcessNode &process_node);
};

#endif // Apc_SignalHandler_SignalMapTableNode_hpp


