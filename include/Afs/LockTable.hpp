/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_LockTable_hpp)
#define Apoxi_LockTable_hpp

#include <Afs/Uri.hpp>
#include <Afs/RegistryTypes.hpp>

#if !defined(APOXI_REG_MAX_URIS_IN_TABLE)
    #define APOXI_REG_MAX_URIS_IN_TABLE 256
#endif

class Application;


struct LockTableEntry{
    BOOLEAN transac_flag;
    Uri locked_object_uri;
    Application* lock_owner_id;
};


class LockTable {
    public:
        enum {
            c_max_uris_per_table = APOXI_REG_MAX_URIS_IN_TABLE,
            c_table_full = -1
        };

        LockTable(INT16 locktableid);

        ~LockTable();

        INT16 AddUri(const Uri &lock_uri, Application* lock_owner, BOOLEAN transac_flag);

        Application* SearchUri(const Uri &uri_to_search, INT16& lock_index, BOOLEAN& transac_flag);

        Application* GetUri(INT16 lockid, Uri& locked_uri, BOOLEAN& transac_flag);

        void RemoveUri(INT16 lockid);

        LockTable* GetNextLockTable() { return m_next;}

        void SetNextLockTable(LockTable* lck_tbl) {m_next = lck_tbl;}

        INT16 GetLockTableId() { return lock_table_id; }

        void SetLockTableId(INT16 id) { lock_table_id = id; }

        RegResult HasAnyChildLocked(const Uri& uri_to_search );

        RegResult IsDeletePossible(const Uri& uri_to_search );

    private:

        INT16 lock_table_id;

        LockTable* m_next;

        LockTableEntry m_lock_table_entry[c_max_uris_per_table];
};
#endif


