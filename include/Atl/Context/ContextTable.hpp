/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Atl_Context_ContextTable_hpp)
#define Atl_Context_ContextTable_hpp

#include <Kernel/Types.hpp>

class ContextTableNode;

class ContextTable {
    friend class ContextTableNode;
    public:
        static const ContextTableNode* GetRoot() { return m_root; }

        static INT GetSize();

    private:
        static void Attach(ContextTableNode* node);

        static const ContextTableNode* m_root;
};

#endif // Atl_Context_ContextTable_hpp

