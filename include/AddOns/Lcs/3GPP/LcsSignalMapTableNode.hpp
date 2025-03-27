/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_3GPP_LcsSignalMapTable_hpp)
#define AddOns_Lcs_3GPP_LcsSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

class LcsSignalMapTableNode : public SignalMapTableNode
{
    typedef SignalMapTableNode Base;

    public:

        ~LcsSignalMapTableNode();

        static LcsSignalMapTableNode* GetInstance();

        static void ReleaseInstance();


    private:

        LcsSignalMapTableNode();


    private:

        static LcsSignalMapTableNode* m_node;

        static const SignalMapTableEntry m_signal_map_table[];

}; // LcsSignalMapTableNode

#endif  // Apoxi_Lcs_LcsSignalMapTable_hpp

