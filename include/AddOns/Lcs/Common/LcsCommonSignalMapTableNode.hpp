/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_Common_LcsCommonSignalMapTableNode_hpp)
#define AddOns_Lcs_Common_LcsCommonSignalMapTableNode_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

class LcsCommonSignalMapTableNode : public SignalMapTableNode
{
    typedef SignalMapTableNode Base;

    public:

        ~LcsCommonSignalMapTableNode();

        static LcsCommonSignalMapTableNode* GetInstance();

        static void ReleaseInstance();


    private:

        LcsCommonSignalMapTableNode();


    private:

        static LcsCommonSignalMapTableNode* m_node;

        static const SignalMapTableEntry m_signal_map_table[];
};

#endif // AddOns_Lcs_Common_LcsCommonSignalMapTableNode_hpp

