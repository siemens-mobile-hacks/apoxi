/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Target_PdpContextSignalMapTable_hpp)
#define Asc_Target_PdpContextSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    PdpContextSignalMapTableNode
    ====================================================================== */
class PdpContextSignalMapTableNode : public SignalMapTableNode {
    public:
        static PdpContextSignalMapTableNode* GetInstance();
        
    private:
        static PdpContextSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_pdp_context_signal_map_table[];

        PdpContextSignalMapTableNode();
};

#endif  // Asc_Target_PdpContextSignalMapTable_hpp

