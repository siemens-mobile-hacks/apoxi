/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_Target_Gprs_AudioSignalMapTable_hpp)
#define Asc_Target_Gprs_AudioSignalMapTable_hpp

#include <Apc/SignalHandler/SignalMapTableNode.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class AudioSignalMapTableNode : public SignalMapTableNode {
    public:
        static AudioSignalMapTableNode* GetInstance();
        
    private:
        static AudioSignalMapTableNode *m_node;
        static const SignalMapTableEntry m_signal_map_table_entry[];

        AudioSignalMapTableNode();
};

#endif //DOXYGEN_SHOULD_SKIP_THIS

#endif  // Asc_Target_Gprs_AudioSignalMapTable_hpp


