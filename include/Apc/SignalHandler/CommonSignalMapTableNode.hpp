/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_CommonSignalMapTable_hpp)
#define Apc_SignalHandler_CommonSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    CommonSignalMapTableNode
    ====================================================================== */
class CommonSignalMapTableNode : public SignalMapTableNode {
    public:
        static CommonSignalMapTableNode* GetInstance();
        
    private:
        static CommonSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_map_table[];

        CommonSignalMapTableNode();
};

#endif  // Apc_SignalHandler_CommonSignalMapTable_hpp


