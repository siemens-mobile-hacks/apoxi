/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_StandAlone_SaSignalMapTable_hpp)
#define AddOns_Lcs_StandAlone_SaSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

class SaSignalMapTableNode : public SignalMapTableNode
{
    typedef SignalMapTableNode Base;

    public:

        ~SaSignalMapTableNode();

        static SaSignalMapTableNode* GetInstance();

        static void ReleaseInstance();


    private:

        SaSignalMapTableNode();


    private:

        static SaSignalMapTableNode* m_node;

        static const SignalMapTableEntry m_signal_map_table[];

}; // SaSignalMapTableNode

#endif  // AddOns_Lcs_StandAlone_SaSignalMapTable_hpp

