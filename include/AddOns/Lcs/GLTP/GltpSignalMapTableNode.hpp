/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_Lcs_GLTP_GltpSignalMapTable_hpp)
#define AddOns_Lcs_GLTP_GltpSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

class GltpSignalMapTableNode : public SignalMapTableNode
{
    typedef SignalMapTableNode Base;

    public:

        ~GltpSignalMapTableNode();

        static GltpSignalMapTableNode* GetInstance();

        static void ReleaseInstance();


    private:

        GltpSignalMapTableNode();


    private:

        static GltpSignalMapTableNode* m_node;

        static const SignalMapTableEntry m_signal_map_table[];

}; // GltpSignalMapTableNode

#endif  // AddOns_Lcs_GLTP_GltpSignalMapTable_hpp

