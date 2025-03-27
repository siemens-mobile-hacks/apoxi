/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServer_HttpApplicationSupplier_hpp)
#define Apoxi_AddOns_Server_HttpServer_HttpApplicationSupplier_hpp

#include <Auxiliary/SimpleMap.hpp>
#include "HttpApplication.hpp"

class HttpApplicationSupplier;

class HttpApplicationSupplier
{
    friend class HttpServer;
    friend class HttpClient;

    public:
        static HttpApplicationSupplier* GetInstance();

        virtual void ReleaseInstance();

        virtual BOOLEAN RegisterApplication(HttpApplication* httpApplication);

        virtual void DeregisterApplication(String appId);

        virtual HttpApplication* GetApplication(String appId);

        virtual UINT GetApplicationCount();

        virtual ~HttpApplicationSupplier();

    protected:
        // map of application with their keys
        SimpleMap<String, HttpApplication*> m_appList;

    private:
        HttpApplicationSupplier();

        void Init();

        void Terminate();

        static HttpApplicationSupplier* s_instance;
};

#endif  // Apoxi_AddOns_Server_HttpServer_HttpApplicationSupplier_hpp

