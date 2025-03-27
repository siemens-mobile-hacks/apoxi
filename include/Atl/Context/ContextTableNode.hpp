/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Atl_Context_ContextTableNode_hpp)
#define Atl_Context_ContextTableNode_hpp

struct ContextTableEntry;
class ContextTable;

class ContextTableNode {
    friend class ContextTable;
    public:
        ContextTableNode(const ContextTableEntry* entry);
        
        virtual ~ContextTableNode();

        const ContextTableNode* GetNext() const { return m_next; }

        const ContextTableEntry* GetEntry() const { return m_entry; }
        
    private:
        void SetNext(const ContextTableNode* node);

        const ContextTableEntry* m_entry;
        const ContextTableNode* m_next;
};

#endif // Atl_Context_ContextTableNode_hpp

