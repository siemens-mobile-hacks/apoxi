/*----------------------------------------------------------------------------------------------
Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
All rights reserved.
------------------------------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted withOut prior written authorisation.
------------------------------------------------------------------------------------------------ */

#if !defined(Apoxi_SyncMLManager_hpp)
#define Apoxi_SyncMLManager_hpp

#include <Config/SyncMLConfig.hpp>

#include <AddOns/Services/Service.hpp>
#include <AddOns/Services/ServiceBroker.hpp>

#include "DBService.hpp"

#if !defined(SYNCML_DATABASE_MAX)
    #define SYNCML_DATABASE_MAX 15
#endif

const INT c_syncml_database_max = SYNCML_DATABASE_MAX;

/* ---------------------------------------------------------------------------------------------
    SyncMLChangeType
   --------------------------------------------------------------------------------------------- */

enum SyncMLChangeType {

    SyncMLItemAdded,
    SyncMLItemDeleted,
    SyncMLItemModified,
    SyncMLItemDeletedAll
};

/* ---------------------------------------------------------------------------------------------
    SyncMLManager
   --------------------------------------------------------------------------------------------- */

class SyncMLManager
{
public:

    ~SyncMLManager();

    static SyncMLManager& GetInstance();

    // Registration of data stores and SyncML application -----------------------------------------

    BOOLEAN RegisterDataStore(const Guid &db_guid, UINT16 db_uri_id, const String &db_uri_string);

    const Guid& GetServiceGuid(UINT16 db_uri) const;

    DBService* GetDBServiceFromURI(UINT16 db_uri) const;
    
    String GetDataStoreUri(UINT16 db_uri) const;

    UINT16 GetDataStoreUri(const String& db_uri) const;

    UINT16 GetNumOfDataStores() const;

    BOOLEAN GetRegisteredDataStore(UINT16 idx, Guid &db_guid, UINT16 &db_uri_id, String &db_uri_string) const;

    BOOLEAN RegisterSyncMLApplication(Application* syncml_app);

    // Posting of change messages -----------------------------------------------------------------

    BOOLEAN PostItemChangedMsg(UINT16 db_uri, UINT32 item_uri, const DateTime &time_stamp, SyncMLChangeType change_code) const;

    // Retrieving device information --------------------------------------------------------------

    BOOLEAN GetDeviceInfo(SyncMLDeviceInfo &device_info) const;

    // private part -------------------------------------------------------------------------------

private:

    struct DbGuidItem {
        Guid    m_datastore_guid;
        UINT16  m_datastore_id_uri;
        String  m_datastore_string_uri;
    };

    SyncMLManager();

    SyncMLManager(const SyncMLManager& obj);
    
    void Init();

    DbGuidItem  m_db_guid_tab[c_syncml_database_max];

    UINT16 m_db_guid_tab_size;

    Application *m_syncml_app;

    static SyncMLManager m_instance;

    static BOOLEAN m_is_initialized;
};


#endif    // Apoxi_SyncMLManager_hpp

