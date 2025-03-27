/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Target_DataCallSignalMapTable_hpp)
#define Asc_Target_DataCallSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    DataCallSignalMapTableNode
    ====================================================================== */
class DataCallSignalMapTableNode : public SignalMapTableNode {
    public:
        static DataCallSignalMapTableNode* GetInstance();
        
    private:
        static DataCallSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_data_call_signal_map_table[];

        DataCallSignalMapTableNode();
};

#endif  // Asc_Target_DataCallSignalMapTable_hpp

