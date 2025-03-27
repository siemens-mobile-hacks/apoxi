/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpSocket_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpSocket_hpp

#include <AddOns/Server/Server.hpp>
#include <Socket/TcpSocket.hpp>

class FtpSocket;

typedef NiSharedPtr<FtpSocket> FtpSocketPtr;

class FtpSocket : public TcpSocket
{
    typedef TcpSocket Base;

    friend class FtpServer;
    friend class FtpServerSocket;
    friend class FtpClient;
    friend class FtpDataSocket;
    friend class FtpInTransfer;
    friend class FtpOutTransfer;

    public:
        FtpSocket(Server* server, UINT clientId = 0);

        virtual ~FtpSocket();

    protected:
        virtual BOOLEAN ReplyMessage(const String& code, const String& text);

        virtual void SetClientId(UINT clientId);

        virtual void OnAsyncEvent(Event event);

        Server* m_server;

    private:
        UINT m_clientId;
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpSocket_hpp

