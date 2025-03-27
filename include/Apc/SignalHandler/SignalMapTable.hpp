/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_SignalHandler_SignalMapTable_hpp)
#define Apc_SignalHandler_SignalMapTable_hpp

class ProcessNode;
class SignalMapTableNode;
/*  ========================================================================
    SignalMapTable
    ======================================================================== */
class SignalMapTable {
    friend class SignalMapTableNode;
    public:
        static void PostMessage(const ProcessNode &process_node);

    private:
        static SignalMapTableNode *m_anchor;
        static void Attach(SignalMapTableNode *node);
        static void Remove(SignalMapTableNode *node);
};

#endif // Apc_SignalHandler_SignalMapTable_hpp


