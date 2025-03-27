/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpClient_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpClient_hpp

#include <Socket/InetSocketAddr.hpp>
#include <AddOns/Server/Server.hpp>
#include "FtpSocket.hpp"
#include "FtpDataSocket.hpp"
#include "FtpDataServerSocket.hpp"
#include "FtpTransfer.hpp"
#include "FtpRequest.hpp"
#include "MsgTypes.hpp"

class FtpClient;

typedef NiSharedPtr<FtpClient> FtpClientPtr;


class FtpClient : public ServerClient
{
    friend class FtpServer;
    friend class FtpDataServerSocket;

    typedef ServerClient Base;

    public:
        enum State {
            c_state_not_logged_in,
            c_state_terminated,
            c_state_login_process,
            c_state_logged_in
        };

        FtpClient(Server* server, Pathname homeDir, Pathname currentDir = Pathname(L"/"));

        virtual ~FtpClient();

        virtual UINT GetId();

        virtual const String& GetUser();

        virtual FtpSocketPtr GetFtpSocket();

        virtual FtpDataSocketPtr GetFtpDataSocket();

        virtual InetSocketAddr GetPeerDataSocketAddr();

        virtual InetSocketAddr GetLocalDataSocketAddr();

        virtual FtpDataConnectionType GetDataConnectionType();

    protected:        
        virtual void SetFtpSocket(FtpSocketPtr ftpSocket);
        
        virtual void SetFtpDataSocket(FtpDataSocketPtr ftpDataSocket);
        
        virtual void SetPeerDataSocketAddr(const InetSocketAddr& peerDataSocketAddr);
        
        virtual void SetLocalDataSocketAddr(const InetSocketAddr& localDataSocketAddr);

        virtual void SetDataConnectionType(FtpDataConnectionType dataConnType);

        State GetState();

        void SetState(State state);

        BOOLEAN ReplyMessage(const String& replyCode, const String& text);

        Pathname GetAbsolutePathname(const Pathname& pathname);

        BOOLEAN EstablishDataConnection();

        BOOLEAN CloseDataConnection();

        String GetDirItemInformation(Pathname pathname);

        virtual BOOLEAN ExecCmd(const FtpRequest& request);

        virtual BOOLEAN ExecUserCmd(const FtpRequest& request, AuthProvider* ftpAuthProvider);

        virtual BOOLEAN ExecPassCmd(const FtpRequest& request, AuthProvider* ftpAuthProvider);

        virtual BOOLEAN ExecPwdCmd(const FtpRequest& request);

        virtual BOOLEAN ExecPortCmd(const FtpRequest& request);

        virtual BOOLEAN ExecTypeCmd(const FtpRequest& request);

        virtual BOOLEAN ExecModeCmd(const FtpRequest& request);

        virtual BOOLEAN ExecStruCmd(const FtpRequest& request);

        virtual BOOLEAN ExecListCmd(const FtpRequest& request);

        virtual BOOLEAN DoListCmd(const FtpRequest& request);

        virtual BOOLEAN ExecCwdCmd(const FtpRequest& request);

        virtual BOOLEAN ExecCdupCmd(const FtpRequest& request);

        virtual BOOLEAN ExecRmdCmd(const FtpRequest& request);

        virtual BOOLEAN ExecDeleCmd(const FtpRequest& request);

        virtual BOOLEAN ExecMkdCmd(const FtpRequest& request);

        virtual BOOLEAN ExecRetrCmd(const FtpRequest& request);

        virtual BOOLEAN DoRetrCmd(const FtpRequest& request);

        virtual BOOLEAN ExecStorCmd(const FtpRequest& request);

        virtual BOOLEAN DoStorCmd(const FtpRequest& request);

        virtual BOOLEAN ExecQuitCmd(const FtpRequest& request);

        virtual BOOLEAN ExecNoopCmd(const FtpRequest& request);

        virtual BOOLEAN ExecPasvCmd(const FtpRequest& request);

    private:
        BOOLEAN EstablishActiveDataConnection();

        BOOLEAN EstablishPassiveDataConnection();

        // user name of the client
        String m_user;
        // current state of the client
        State m_state;
                
        // control socket
        FtpSocketPtr m_ftpSocket;
        // (optionally, in passive mode listening) data connection server socket
        FtpDataServerSocketPtr m_ftpDataServerSocket;
        // data socket
        FtpDataSocketPtr m_ftpDataSocket;
        // local data socket address
        InetSocketAddr m_localDataSocketAddr;
        // peer data socket address
        InetSocketAddr m_peerDataSocketAddr;

        // data connection mode
        FtpDataConnectionType m_dataConnType;

        // transfer options
        FtpTransferMode m_transferMode;
        FtpTransferType m_transferType;
        FtpTransferStructure m_transferStructure;

        // home directory
        Pathname m_homeDir;
        // current directory (relative path)
        Pathname m_currentDir;

        // BooleanCondition for accepting passive data connections
        BooleanCondition m_acceptDoneCondition;
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpClient_hpp

