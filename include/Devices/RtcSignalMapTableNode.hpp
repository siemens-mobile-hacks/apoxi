/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_RtcSignalMapTableNode_hpp)
#define Apoxi_Devices_RtcSignalMapTableNode_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    RtcSignalMapTableNode
    ====================================================================== */
class RtcSignalMapTableNode : public SignalMapTableNode {
    public:
        static RtcSignalMapTableNode* GetInstance();
        
    private:
        static RtcSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_map_table[];

        RtcSignalMapTableNode();
};

#endif  // Apoxi_Devices_RtcSignalMapTableNode_hpp


