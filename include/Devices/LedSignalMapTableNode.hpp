/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Devices_LedSignalMapTableNode_hpp)
#define Apoxi_Devices_LedSignalMapTableNode_hpp

#if defined(APOXI_LED_NEW_INTERFACE)

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    LedSignalMapTableNode
    ====================================================================== */
class LedSignalMapTableNode : public SignalMapTableNode {

    public:
        static LedSignalMapTableNode* GetInstance();
        
    private:
        static LedSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_map_table[];

        LedSignalMapTableNode();
};

#endif  // APOXI_LED_NEW_INTERFACE

#endif  // Apoxi_Devices_LedSignalMapTableNode_hpp

