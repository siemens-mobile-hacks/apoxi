/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpDataServerSocket_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpDataServerSocket_hpp

#include <Socket/TcpServerSocket.hpp>
#include <AddOns/Server/Server.hpp>
#include "FtpRequest.hpp"

class FtpDataServerSocket;

typedef NiSharedPtr<FtpDataServerSocket> FtpDataServerSocketPtr;

class FtpDataServerSocket : public TcpServerSocket
{
    typedef TcpServerSocket Base;

    friend class FtpClient;

    friend class TcpServerSocket;

    public:
        FtpDataServerSocket(Server* server, UINT clientId = 0);

        virtual ~FtpDataServerSocket();

    protected:
        virtual void OnAsyncEvent(Event event);

    private:
        // parent server
        Server* m_server;

        // ID of the corresponding client
        UINT m_clientId;

};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpDataServerSocket_hpp

