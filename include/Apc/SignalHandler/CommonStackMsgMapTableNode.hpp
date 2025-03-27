/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_CommonStackMsgMapTable_hpp)
#define Apc_SignalHandler_CommonStackMsgMapTable_hpp

#include <Apc/SignalHandler/StackMsgMapTableNode.hpp>

/*  ======================================================================
    CommonStackMsgMapTableNode
    ====================================================================== */
class CommonStackMsgMapTableNode : public StackMsgMapTableNode {
    public:
        static CommonStackMsgMapTableNode* GetInstance();
        
    private:
        static CommonStackMsgMapTableNode *m_node;
        static const StackMsgMapTableEntry m_map_table[];

        CommonStackMsgMapTableNode();
};

#endif  // Apc_SignalHandler_CommonStackMsgMapTable_hpp

