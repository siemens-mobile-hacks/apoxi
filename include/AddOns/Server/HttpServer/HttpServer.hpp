/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpServer_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpServer_hpp

#include <Socket/SocketHandler.hpp>
#include <AddOns/Server/Server.hpp>
#include "HttpAuthProvider.hpp"
#include "HttpServerConfig.hpp"
#include "HttpServerSocket.hpp"
#include "HttpRequest.hpp"
#include "HttpClient.hpp"
#include "HttpApplication.hpp"
#include "MsgTypes.hpp"


class HttpServer;

typedef NiSharedPtr<HttpServer> HttpServerPtr;

class HttpServer : public Server
{
    typedef Server Base;

    friend class HttpServerSocket;
    friend class HttpClient;
    friend class HttpSocket;

    public:
        HttpServer(HttpServerConfig* serverConfig, HttpAuthProvider* authProvider = 0);

        virtual ~HttpServer();

        virtual void Start(const InetSocketAddr& localAddr, DataConnProfileId dataConnProfileId = c_invalid_data_conn_profile_id);

        virtual void Stop();

        virtual IpAddr GetHostIp();

        virtual IpPortNo GetPort();

    protected:
        virtual void Init();

        virtual void Terminate();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual BOOLEAN ConnectClient(const InetSocketAddr& peerAddr, const HttpSocketPtr& peerSocket);

        virtual BOOLEAN DisconnectClient(UINT clientId);

        virtual BOOLEAN HandleRequest(UINT clientId, const HttpRequest& hr);

        virtual HttpClient* GetClient(UINT clientId);

        virtual HttpApplication* GetApplication(String appId);

        virtual Pathname GetWwwDir();

    private:
        virtual void InternalInit();

        virtual void InternalTerminate();

        virtual void InternalStart(const InetSocketAddr& localAddr, DataConnProfileId dataConnProfileId);

        virtual void InternalStop(const InetSocketAddr& localAddr);
        
        // listening server socket
        HttpServerSocketPtr m_httpServerSocket;

        // socket handler
        SocketHandler m_socketHandler;
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpServer_hpp

