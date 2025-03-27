/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpRequest_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpRequest_hpp

#include <AddOns/AfsRam/RamDataSink.hpp>

// Defines the format of the contained headers.
typedef Vector<String> HttpRequestHeaders;

class HttpRequest;

class HttpRequest
{
    friend class HttpSocket;
    friend class HttpServer;

    public:
        // Defines available types of the request method.
        enum HttpRequestMethodType {
            c_http_request_method_get,
            c_http_request_method_post
        };

        // Defines one parameter name and value.
        typedef struct {
            String name;
            String value;
        } ParamPair;
        // Defines a list of parameters.
        typedef Vector<ParamPair> ParamPairList;

        HttpRequest(HttpRequestMethodType type = c_http_request_method_get);

        HttpRequestMethodType GetRequestMethodType();

        String GetRequestTarget();

        ParamPairList GetRequestParams();

        String GetHttpVersion();

        HttpRequestHeaders GetHeaders();

        RamDataSinkPtr GetBody();

        virtual ~HttpRequest();

    protected:
        void SetBody(RamDataSinkPtr newBody);

        
        HttpRequestMethodType m_requestMethod;  // the request method
        String m_requestTarget; // the request target
        Vector<ParamPair> m_requestParams;  // the request parameters
        String m_httpVersion;   // the HTTP version
        HttpRequestHeaders m_headers;   // vector of received request headers
        RamDataSinkPtr m_body;  // (optionally) received body data
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpRequest_hpp

