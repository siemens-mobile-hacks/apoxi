/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpServerSocket_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpServerSocket_hpp

#include <Socket/TcpServerSocket.hpp>
#include <AddOns/Server/Server.hpp>

class FtpServerSocket;

typedef NiSharedPtr<FtpServerSocket> FtpServerSocketPtr;

class FtpServerSocket : public TcpServerSocket
{
    typedef TcpServerSocket Base;

    public:
        FtpServerSocket(Server* server);

        virtual ~FtpServerSocket();

    protected:
        virtual void OnAsyncEvent(Event event);

    private:
        // parent server
        Server* m_server;

};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpServerSocket_hpp

