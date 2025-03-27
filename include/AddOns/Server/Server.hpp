/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_Server_hpp)
#define Apoxi_AddOns_Server_Server_hpp

#include <Kernel/ServiceThread.hpp>
#include <Socket/InetSocketAddr.hpp>
#include <Socket/DataConnProfile.hpp>
#include <AddOns/Server/AuthProvider.hpp>
#include <AddOns/Server/ServerConfig.hpp>
#include <AddOns/Server/ServerClient.hpp>

#if defined(APOXI_SER_DATACONN_SUPPORT)
#include <Socket/SerDataConnProfile.hpp>
#endif

// define a DBG_OUT range for Server
#define SERVER_DBG_OUT_RANGE 35900

// default value for backlog of the listening TcpServerSocket
#define APOXI_SERVER_DEFAULT_BACKLOG 15

// default maximum of currently connected clients
#define APOXI_SERVER_DEFAULT_MAX_USERS 5

class Server;

typedef NiSharedPtr<Server> ServerPtr;

class Server : public ServiceThread
{
    typedef ServiceThread Base;

    public:
        Server(AuthProvider* authProvider,
            ServerConfig* serverConfig,
            UINT maxUsers = APOXI_SERVER_DEFAULT_MAX_USERS,
            INT backlog = APOXI_SERVER_DEFAULT_BACKLOG);

        virtual ~Server() = 0;

        virtual void Start(const InetSocketAddr& localAddr, DataConnProfileId dataConnProfileId = c_invalid_data_conn_profile_id) = 0;
        
        virtual void Stop() = 0;

        virtual ServerClient* GetClient(UINT clientId);

        virtual UINT GetClientCount();

        virtual BOOLEAN IsRunning() { return m_running; }
        

        virtual UINT GetMaxUsers();

        virtual void SetMaxUsers(UINT maxUsers);

        virtual INT GetBacklog();

        virtual void SetBacklog(INT backlog);
        

#if defined(APOXI_SER_DATACONN_SUPPORT)

        virtual DataConnProfileId GetTempSerDataConnProfileId()
        { return s_temp_serial_dcp.GetId(); }
        
        virtual UINT8 GetTempSerDataConnProfileIdRefs()
            { return s_temp_serial_dcp_refs; }
        
        virtual UINT8 IncreaseTempSerDataConnProfileIdRefs()
            { return ++s_temp_serial_dcp_refs; }
        
        virtual UINT8 DecrementTempSerDataConnProfileIdRefs()
            { return (s_temp_serial_dcp_refs > 0) ? --s_temp_serial_dcp_refs : 0; }

        virtual BOOLEAN IsSerialDeviceInUse();
#endif 

    protected:
        virtual BOOLEAN AddClient(ServerClient* client);

        virtual void Init() = 0;

        virtual void Terminate() = 0;

        virtual IpAddr GetHostIp() = 0;

        virtual IpPortNo GetPort() = 0;

        virtual AuthProviderPtr GetAuthProvider();

        virtual void SetAuthProvider(AuthProviderPtr authProvider);

        virtual ServerConfigPtr GetServerConfig();

        virtual void SetServerConfig(ServerConfigPtr serverConfig);

        AuthProviderPtr m_authProvider;
        ServerConfigPtr m_serverConfig;
        BOOLEAN m_running;
        SimpleMap<UINT, ServerClient*> m_clients;

        // maximum of currently connected clients
        UINT m_maxUsers;

        // value for backlog of the listening TcpServerSocket
        INT m_backlog;

#if defined(APOXI_SER_DATACONN_SUPPORT)
        // temporary default serial profile (needed if no CSD or GPRS profile is defined)
        static SerDataConnProfile s_temp_serial_dcp;
        // stores the number of clients using the serial data connection
        static UINT8 s_temp_serial_dcp_refs;
#endif 
};

#endif  // Apoxi_AddOns_Server_Server_hpp

