/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtServiceDiscoveryDatabase_hpp)
#define BtServiceDiscoveryDatabase_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS

/* !!! ATTENTON !!! Internal class only !!! ATTENTION !!!
   The class may not be used by the MMI in a direct 
   manner and the interface may be changed in future 
   releases.
   !!! ATTENTON !!! Internal class only !!! ATTENTION !!! */

#include <Bluetooth/BtSddbServiceRecord.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtGapAndSdapController;

class BtServiceDiscoveryDatabase
{
    public:

        static BtServiceDiscoveryDatabase& GetInstance();

    public:
        virtual ~BtServiceDiscoveryDatabase();

    protected:

        void* AddServiceRecord(const BtSddbServiceRecord& service_record);


        void RemoveServiceRecordByBuffer(const void* service_record_buffer);


        void RemoveServiceRecordByHandle(UINT32 service_record_handle);


        BOOLEAN SetServiceRecordHandle(const void* service_record_buffer, UINT32 service_record_handle);

    protected:
        class BtServiceDiscoveryDatabaseNode
        {
            public:
                BtServiceDiscoveryDatabaseNode();

                ~BtServiceDiscoveryDatabaseNode();


                UINT32 GetServiceRecordHandle();


                void SetServiceRecordHandle(UINT32 service_record_handle);


                void* GetServiceRecordBuffer();


                void SetServiceRecordBuffer(void* service_record_buffer);


                BtServiceDiscoveryDatabaseNode* GetNext();


                void SetNext(BtServiceDiscoveryDatabaseNode* next);

            private:
                UINT32 m_service_record_handle;

                void* m_service_record_buffer;

                BtServiceDiscoveryDatabaseNode* m_next;
        };

    private:
        BtServiceDiscoveryDatabase();


        BtServiceDiscoveryDatabaseNode* FindServiceDiscoveryDatabaseNodeByServiceRecordBuffer(const void* service_record_buffer);

    private:
        BtServiceDiscoveryDatabaseNode* m_anchor;

    private:
        static BtServiceDiscoveryDatabase m_service_discovery_database;

    private:
        friend class BtGapAndSdapController;
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS
#endif  // BtServiceDiscoveryDatabase_hpp


