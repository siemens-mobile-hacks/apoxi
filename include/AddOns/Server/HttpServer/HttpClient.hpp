/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpClient_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpClient_hpp

#include <Socket/InetSocketAddr.hpp>
#include <AddOns/Server/Server.hpp>
#include "HttpSocket.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "MsgTypes.hpp"

class HttpClient;

typedef NiSharedPtr<HttpClient> HttpClientPtr;


class HttpClient : public ServerClient
{
    friend class HttpServer;

    typedef ServerClient Base;

    public:
        HttpClient(Server* server);

        virtual ~HttpClient();

        virtual UINT GetId();

        virtual HttpSocketPtr GetHttpSocket();

        virtual BOOLEAN OnHttpRequest(HttpRequest& httpRequest);

        virtual BOOLEAN OnHttpGetRequest(HttpRequest& httpRequest);

        virtual BOOLEAN OnHttpPostRequest(HttpRequest& httpRequest);

        virtual HttpResponseCode OnFileRequest(const Pathname& pathname, HttpResponse& httpResponse);

    protected:        
        virtual void SetHttpSocket(HttpSocketPtr httpSocket);

        Pathname GetAbsolutePathname(const Pathname& pathname);

        HttpResponseCode GetIndexPage(const HttpRequest& httpRequest, HttpResponse& httpResponse);

        HttpResponseCode GetFavicon(HttpResponse& httpResponse);

        HttpResponseCode GetStyleSheet(HttpResponse& httpResponse);

        HttpResponseCode GetErrorPage(HttpResponse& httpResponse, HttpResponseCode errorCode, WString errorDescription = L"");

    private:
        /*
        This method is needed within GetFavicon() when generating icon byte array.
        String UintToHex(UINT8 val);
        */

        // communication socket
        HttpSocketPtr m_httpSocket;
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpClient_hpp

