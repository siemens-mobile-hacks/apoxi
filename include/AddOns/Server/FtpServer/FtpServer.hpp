/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpServer_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpServer_hpp

#include <Socket/SocketHandler.hpp>
#include <AddOns/Server/Server.hpp>
#include "FtpAuthProvider.hpp"
#include "FtpServerConfig.hpp"
#include "FtpServerSocket.hpp"
#include "FtpClient.hpp"
#include "FtpRequest.hpp"
#include "MsgTypes.hpp"


class FtpServer;

typedef NiSharedPtr<FtpServer> FtpServerPtr;

class FtpServer : public Server
{
    typedef Server Base;

    friend class FtpSocket;
    friend class FtpClient;

    public:
        FtpServer(FtpServerConfig* serverConfig, FtpAuthProvider* authProvider);

        virtual ~FtpServer();

        virtual void Start(const InetSocketAddr& localAddr, DataConnProfileId dataConnProfileId = c_invalid_data_conn_profile_id);

        virtual void Stop();

        virtual FtpClient* GetClient(UINT clientId);

        virtual IpAddr GetHostIp();

        virtual IpPortNo GetPort();

    protected:
        virtual void Init();

        virtual void Terminate();

        virtual BOOLEAN OnMessage(const Message& msg);

        virtual BOOLEAN ConnectClient(const InetSocketAddr& peerAddr, const FtpSocketPtr& peerSocket);

        virtual BOOLEAN DisconnectClient(UINT clientId);

        virtual BOOLEAN HandleRequest(const FtpRequest& request);

        virtual BOOLEAN ExecCmd(const FtpRequest& request);

    private:
        virtual void InternalInit();

        virtual void InternalTerminate();

        virtual void InternalStart(const InetSocketAddr& localAddr, DataConnProfileId dataConnProfileId);

        virtual void InternalStop(const InetSocketAddr& localAddr);
        
        // (listening) control connection server socket
        FtpServerSocketPtr m_ftpServerSocket;

        // needed to receive socket messages
        SocketHandler m_socketHandler;
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpServer_hpp

