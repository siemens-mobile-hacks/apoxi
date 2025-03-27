/*----------------------------------------------------------------------------------------------
Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
All rights reserved.
------------------------------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------------------------------ */

#if !defined(Apoxi_DBService_hpp)
#define Apoxi_DBService_hpp

#include <AddOns/Services/Service.hpp>

/* =============================================================================================
    Item meta information
   ============================================================================================= */

/* ---------------------------------------------------------------------------------------------
    SyncMLItemMetaInfo
   --------------------------------------------------------------------------------------------- */

struct SyncMLItemMetaInfo {
    UINT32         m_size;
    String         m_format;
    String         m_type;
    String         m_mark;
    String         m_version;
};


/* ---------------------------------------------------------------------------------------------
    SyncMLDynamicDBCharacteristics
   --------------------------------------------------------------------------------------------- */

struct SyncMLDynamicProps {

    UINT32         m_free_id;
    UINT32         m_free_mem;

};

/* =============================================================================================
    Data store properties
   ============================================================================================= */

/* MS VC6++ is not able to successfully compile the constant structures, therefore the
   local define _MSVC_CONST_FLAW is necessary, which removes the const. */

#if defined(APOXI_COMPILER_MSVC)
    #define _MSVC_CONST_FLAW
#else
    #define _MSVC_CONST_FLAW const
#endif

enum SyncMLSyncType
{
    TwoWaySync = 1,
    SlowTwoWaySync = 2,
    OneWaySyncFromClient = 3,
    RefreshSyncFromClient = 4,
    OneWaySyncFromServer = 5,
    RefreshSyncFromServer = 6,
    ServerAlertedSync = 7
};


/* ---------------------------------------------------------------------------------------------
    SyncMLCTTypeVer
   --------------------------------------------------------------------------------------------- */

struct SyncMLCTTypeVerCT {

    const CHAR*    m_ct_type;
    const CHAR*    m_ver_ct;
};


/* ---------------------------------------------------------------------------------------------
    SyncMLCTValueDef
   --------------------------------------------------------------------------------------------- */

struct SyncMLCTValueDef {

    const CHAR*    m_val_enum;
    const CHAR*    m_data_type;
    UINT32         m_size;  
    const CHAR*    m_display_name;
};


/* ---------------------------------------------------------------------------------------------
    SyncMLCTParam
   --------------------------------------------------------------------------------------------- */

struct SyncMLCTParam {

    const CHAR*              m_param_name;
    const SyncMLCTValueDef*  _MSVC_CONST_FLAW  m_value_def;
    UINT32                   m_value_def_count;
};


/* ---------------------------------------------------------------------------------------------
    SyncMLCTProp
   --------------------------------------------------------------------------------------------- */

struct SyncMLCTProp {

    const CHAR*              m_prop_name;
    const SyncMLCTValueDef*  _MSVC_CONST_FLAW  m_value_def;
    UINT32                   m_value_def_count;
    const SyncMLCTParam*     _MSVC_CONST_FLAW  m_param;
    UINT32                   m_param_count;

};


/* ---------------------------------------------------------------------------------------------
    SyncMLCTCap
   --------------------------------------------------------------------------------------------- */

struct SyncMLCTCap {

    const CHAR*              m_ct_type;
    const SyncMLCTProp*      _MSVC_CONST_FLAW  m_prop;
    UINT32                   m_prop_count;

};

/* ---------------------------------------------------------------------------------------------
    SyncMLDataStoreProps
   --------------------------------------------------------------------------------------------- */

struct SyncMLDataStoreProps {

    const CHAR*              m_source_ref;
    const CHAR*              m_display_name;
    UINT16                   m_max_guid_size;
    const SyncMLCTTypeVerCT* _MSVC_CONST_FLAW m_rx_pref;
    const SyncMLCTTypeVerCT* _MSVC_CONST_FLAW  m_rx;
    UINT16                   m_rx_count;
    const SyncMLCTTypeVerCT* _MSVC_CONST_FLAW m_tx_pref;
    const SyncMLCTTypeVerCT* _MSVC_CONST_FLAW  m_tx;
    UINT16                   m_tx_count;

    const SyncMLSyncType* _MSVC_CONST_FLAW     m_sync_cap;
    UINT16                   m_sync_type_count;

    BOOLEAN                  m_shared_mem;
    UINT32                   m_max_mem;
    UINT32                   m_max_id;
    BOOLEAN                  m_support_large_objects;

    const SyncMLCTCap* _MSVC_CONST_FLAW        m_ct_cap;
    UINT32                   m_ct_cap_count;
};

#undef _MSVC_CONST_FLAW

/* =============================================================================================
    DBService
   ============================================================================================= */

class DBService : public Service {
    typedef Service Base;

protected:

    // Constructor
    DBService(const Guid &guid) : Service(guid) {}

public:

    // Necessary forward declarations -------------------------------------------------------------

    class DBItemIterator;

    // Open, close --------------------------------------------------------------------------------

    virtual BOOLEAN OpenDatabase() = 0;

    virtual BOOLEAN CloseDatabase() = 0;


    // Making changes -----------------------------------------------------------------------------

    virtual UINT16 AddItem(UINT32 &item_id, const void* item_data, UINT32 item_data_length, const SyncMLItemMetaInfo &item_meta_info) = 0;

    virtual UINT16 DeleteItem(const UINT32 item_id) = 0;

    virtual UINT16 UpdateItem(const UINT32 item_id, const void* item_data, UINT32 item_data_length, const SyncMLItemMetaInfo &item_meta_info) = 0;

    virtual UINT16 CopyItem(const UINT32 item_id, const UINT16 target_location, UINT32 &copy_item_id) = 0;


    // Retrieving item information ----------------------------------------------------------------

    virtual BOOLEAN GetItemData(const UINT32 item_id, void* item_data, UINT32 &item_data_length, SyncMLItemMetaInfo *item_meta_info = 0) = 0;

    virtual BOOLEAN GetItemMetaInfo(const UINT32 item_id, SyncMLItemMetaInfo &item_meta_info) = 0;


    // Accessing the whole datastore --------------------------------------------------------------

    virtual DBItemIterator* GetAllItems() = 0;

    virtual BOOLEAN ClearDatabase() = 0;


    // Searching and filtering --------------------------------------------------------------------

    virtual DBItemIterator* SearchDataItems(const String &search_grammar, const String &search_query) = 0;


    // Locking and unlocking ----------------------------------------------------------------------

    virtual BOOLEAN LockDataStore() = 0;

    virtual BOOLEAN UnlockDataStore() = 0;


    // Transactions -------------------------------------------------------------------------------

    virtual BOOLEAN StartTransaction() = 0;

    virtual BOOLEAN CommitTransaction() = 0;

    virtual BOOLEAN Rollback() = 0;


    // Device information -------------------------------------------------------------------------

    virtual const SyncMLDataStoreProps* GetStaticProperties() = 0;

    virtual BOOLEAN GetDynamicProperties(SyncMLDynamicProps &dynamic_props) = 0;


    // Iterator -----------------------------------------------------------------------------------

    class DBItemIterator {    

    public:
        
        virtual BOOLEAN Release() = 0;

        virtual BOOLEAN HasNext() = 0;

        virtual BOOLEAN GetNextItem(UINT32 &item_id, void* item_data, UINT32 &item_data_length, SyncMLItemMetaInfo *item_meta_info = 0) = 0;

        virtual BOOLEAN GetNextItemMetaInfo(UINT32 &item_id, SyncMLItemMetaInfo &item_meta_info) = 0;

    };
};

#endif // Apoxi_DBService_hpp


