/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpApplication_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpApplication_hpp

#include "HttpTypes.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"

class HttpApplication;

class HttpApplication
{
    friend class HttpServer;
    friend class HttpClient;

    public:
        static HttpApplication* GetInstance();

        virtual void ReleaseInstance();

        virtual String GetId();

        virtual String GetName();

        virtual String GetDescription();

        virtual HttpResponseCode OnHttpRequest(HttpRequest& request, HttpResponse& response) = 0;

        virtual ~HttpApplication();

    protected:
        HttpApplication(String appId, String appName, String appDescription);

        virtual void Init();

        virtual void Terminate();

        static HttpApplication* s_instance;
        String m_appId;
        String m_appName;
        String m_appDescription;
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpApplication_hpp

