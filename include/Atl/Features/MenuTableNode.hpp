/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Atl_MenuTableNode_hpp)
#define Atl_MenuTableNode_hpp

#include <Atl/Features/MenuPool.hpp>

class MenuTable;

class MenuTableNode {
    friend class MenuTable;
    public:
        MenuTableNode(const MenuPool::MenuTableEntry* entry);

        virtual ~MenuTableNode();

        const MenuTableNode* GetNext() const { return m_next; }

        const MenuPool::MenuTableEntry* GetEntry() const { return m_entry; }

    private:
        void SetNext(const MenuTableNode* node);

        const MenuPool::MenuTableEntry* m_entry;

        const MenuTableNode*    m_next;
};

#endif // Atl_Context_ContextTableNode_hpp

