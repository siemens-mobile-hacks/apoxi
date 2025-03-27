/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_SmsSocketSignalMapTable_hpp)
#define Asc_SmsSocketSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

/*  ======================================================================
    SmsSocketSignalMapTableNode
    ====================================================================== */
class SmsSocketSignalMapTableNode : public SignalMapTableNode {
    public:
        static SmsSocketSignalMapTableNode* GetInstance();
        
    private:
        static SmsSocketSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_sms_socket_signal_map_table[];

        SmsSocketSignalMapTableNode();
};

#endif  // Asc_SmsSocketSignalMapTable_hpp


