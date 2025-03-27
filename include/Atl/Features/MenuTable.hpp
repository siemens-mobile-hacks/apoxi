/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Atl_MenuTable_hpp)
#define Atl_MenuTable_hpp

class MenuTableNode;

class MenuTable {
    friend class MenuTableNode;
    public:
        static const MenuTableNode* GetRoot() { return m_root; }

        static INT GetSize();

    private:
        static void Attach(MenuTableNode* node);

        static const MenuTableNode* m_root;
};

#endif // Atl_MenuTable_hpp

