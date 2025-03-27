/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Services_ServiceBroker_hpp)
#define Services_ServiceBroker_hpp

#include <Auxiliary/HashTable.hpp>
#include <AddOns/Services/Service.hpp>
#include <Kernel/Os/Mutex.hpp>

const INT c_broker_table_size = 10;

class ServiceBroker {

    class ServiceBrokerDestructor {
        public:
            ServiceBrokerDestructor();
            virtual ~ServiceBrokerDestructor();
    };

    public:
        friend class Service;
        typedef LinkedList<Service> ServiceList;

        static ServiceBroker* GetBroker();

        static void Release();

        Service* GetService(const Guid& guid);

        BOOLEAN IsServiceSupported(const Guid& guid);

        void RegisterService(Service* service);

        void UnregisterService(Service* service);

    private:
        friend class ServiceBrokerDestructor;
        
        ServiceBroker();    //lint !e1704

        virtual ~ServiceBroker();

        static ServiceBroker* m_broker;
        static ServiceBrokerDestructor m_destructor;
        static Mutex* m_mutex;

        UINT16 Hash(const Guid &guid);

        ServiceList m_service_root[c_broker_table_size];

};

#endif  // Services_ServiceBroker_hpp

