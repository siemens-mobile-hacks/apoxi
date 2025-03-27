/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_LockTableList_hpp)
#define Apoxi_LockTableList_hpp
#include <Afs/LockTable.hpp>


class LockTableList {
    
    public:

        ~LockTableList();

        static LockTableList* GetLockTableList();

        INT16 AddLockUriInTable(const Uri& uri_string, Application* lock_owner, BOOLEAN transac_flag);

        Application* FindUriFromTables(const Uri& given_uri, INT16& lockid, BOOLEAN& transac_flag);

        Application* FindUriFromTables(INT16 lockid, Uri& uri, BOOLEAN& transac_flag);//it's an in/out parameter

        RegResult HasAnyChildLocked(const Uri& given_uri);

        RegResult IsDeletePossible(const Uri& given_uri);

        void RemoveLockUriInTable(INT16 lockid);

    protected:

        BOOLEAN CreateLockTable();

        void DeleteLockTable(INT16 locktableid);

        LockTable* GetLockTable(INT16 locktableid);
        
    private:

        LockTableList();

        static LockTableList m_lock_table_list;
        
        LockTable* m_lock_table;

        LockTable* m_start_of_table;

        INT16 lock_table_count;
};
#endif


