/* ----------------------------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH & Co. OHG. All rights reserved.
   ----------------------------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted withOut prior written authorisation.
   ---------------------------------------------------------------------------------------------- */

#if !defined(Apoxi_GatiManager_hpp)
#define Apoxi_GatiManager_hpp

#include <Kernel/SubSystem.hpp>

#if !defined(GATIMANAGER_DATABASE_MAX)
    #define GATIMANAGER_DATABASE_MAX 10
#endif

const UINT8 c_gati_manager_database_max = GATIMANAGER_DATABASE_MAX;

#if !defined(GATIMANAGER_CONNECTIONS_MAX)
    #define GATIMANAGER_CONNECTIONS_MAX 20
#endif

const UINT8 c_gati_manager_connections_max = GATIMANAGER_CONNECTIONS_MAX;

#if !defined(GATIMANAGER_PORT)
    #define GATIMANAGER_PORT 9009
#endif

const UINT16 c_gati_manager_port = GATIMANAGER_PORT;

#if !defined(GATIMANAGER_PORT_VAR)
    #define GATIMANAGER_PORT_VAR "APOXI_GATI_PORT"
#endif

#if !defined(REGISTER_GATI_SERVER)
    #define REGISTER_GATI_SERVER(classname) static BOOLEAN __##classname_registered = \
        GatiManager::GetInstance().Register(##classname::CreateInstance, ##classname::ID);
#endif

class GatiServer;

class GatiManager : SubSystem {

    typedef SubSystem Base;

    public:     

        virtual ~GatiManager();
        
        static GatiManager& GetInstance();

        BOOLEAN StartUp();

        BOOLEAN ShutDown();

        BOOLEAN Register(GatiServer* (*createInstanceFunc)(), const UINT32 id);

        BOOLEAN Deregister(const UINT32 id);

        BOOLEAN SendData(const GatiServer* server, const UINT32 cmd, const UINT32 length, const void* data);

        BOOLEAN Broadcast(const INT id, const UINT32 cmd, const UINT32 length, const void* data);

        // ------ Methods derived from class SubSystem ------------------------------------------------

        virtual const WCHAR* GetName() const { return L"GATI"; }
        
        virtual BootSequenceState InvokeAt() const { return SubSystemManager::c_run_level_1; }

        virtual void OnPowerUp() { GatiManager::GetInstance().StartUp(); }

        virtual void OnPowerDown() { GatiManager::GetInstance().ShutDown(); }
        
    private:
        friend class GatiManagerInternals;

        struct GatiServerEntry {
            GatiServer* (*m_createInstanceFunc)();
            UINT32 m_id;
        };

        struct GatiConnectionEntry {
            GatiServer* m_server;
            UINT32 m_socket;            
        };

        struct DataGramHeader {     
            UINT32 m_id;

            UINT32 m_cmd;

            UINT32 m_length;
        };

        GatiManager();

        GatiManager(const GatiManager& obj);
        
        void Init();

        INT16 FindServer(const UINT32 id);

        INT16 FindFreeConnectionEntry();

        GatiServer* GetNewServer(const UINT32 id);

        void HandleConnectionRequest(UINT32 socket);

        BOOLEAN IsSocketOpen(UINT32 socket);

        void CloseSocket(UINT32 &socket);

        void CloseConnection(const UINT16 connpos);

        BOOLEAN ReadHeader(UINT32 socket, DataGramHeader &header);

        BOOLEAN WriteHeader(UINT32 socket, DataGramHeader header);

        BOOLEAN ReadData(UINT32 socket, void* buffer, UINT32 len);

        BOOLEAN WriteData(UINT32 socket, void* buffer, UINT32 len);     
        
        void Run();     

        /************************************************************************/

        UINT8 m_servers_tab_size;

        GatiServerEntry m_servers_tab[c_gati_manager_database_max];     

        GatiConnectionEntry m_conns_tab[c_gati_manager_connections_max];

        BOOLEAN m_wsa_initialized;

        void* m_thread;             

        UINT32 m_socket;        
            
        static GatiManager m_instance;

        static BOOLEAN m_is_initialized;
};

#endif  // Apoxi_GatiManager_hpp


