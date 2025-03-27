/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpSocket_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpSocket_hpp

#include <Auxiliary/Vector.hpp>
#include <Socket/TcpSocket.hpp>
#include <AddOns/Server/Server.hpp>
#include <AddOns/AfsRam/RamDataSource.hpp>
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

class HttpSocket;

typedef NiSharedPtr<HttpSocket> HttpSocketPtr;

class HttpSocket : public TcpSocket
{
    typedef TcpSocket Base;

    friend class HttpServer;
    friend class HttpClient;

    public:
        HttpSocket(Server* server, UINT clientId = 0);

        virtual ~HttpSocket();

    protected:
        virtual void SetClientId(UINT clientId);

        virtual void OnAsyncEvent(Event event);

        virtual BOOLEAN SendResponse(HttpResponse& httpResponse);

        virtual String ConvertFromHtml(const String& str);

        virtual INT8 HexCharToUInt8(CHAR ch);

        // corresponding server
        Server* m_server;

        // boolean condition which has to be fulfilled before requests can be handled
        BooleanCondition m_connected;

    private:
        // enum specifying whether headers, file content or data sink data is sent
        enum HttpResponsePosition {
            c_http_response_position_status,
            c_http_response_position_headers,
            c_http_response_position_file,
            c_http_response_position_data
        };

        virtual BOOLEAN SendStatusLine();

        virtual BOOLEAN SendHeader();

        virtual BOOLEAN SendFileBlock();

        virtual BOOLEAN SendDataBlock();

        virtual void ResumeNextResponse();

        virtual BOOLEAN ProcessPost(RamDataSource body, HttpRequest& request);

        virtual BOOLEAN ReadUrlParameters(RamDataSource& data_src, HttpRequest& request);


        // ID of the corresponding client
        UINT m_clientId;

        // vector with all enqueued responses to send
        Vector<HttpResponse> m_responsesToSend;
        // pointer to current response to send
        HttpResponse* m_currentResponse;

        // current position of data to be sent
        HttpResponsePosition m_position;
        // current offset of data to be sent
        UINT32 m_offset;
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpSocket_hpp

