/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_ChargerSignalMapTableNode_hpp)
#define Apoxi_Devices_ChargerSignalMapTableNode_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    ChargerSignalMapTableNode
    ====================================================================== */
class ChargerSignalMapTableNode : public SignalMapTableNode {
    public:
        static ChargerSignalMapTableNode* GetInstance();
        
    private:
        static ChargerSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_map_table[];

        ChargerSignalMapTableNode();
};

#endif  // Apoxi_Devices_ChargerSignalMapTableNode_hpp


