/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_HttpServerConfig_hpp)
#define Apoxi_AddOns_Server_HttpServerConfig_hpp

#include <AddOns/Server/ServerConfig.hpp>
#include "HttpTypes.hpp"

class HttpServerConfig;

typedef NiSharedPtr<HttpServerConfig> HttpServerConfigPtr;

class HttpServerConfig : public ServerConfig
{
    typedef ServerConfig Base;

    public:
        HttpServerConfig();

        virtual ~HttpServerConfig();

        virtual const Pathname& GetWwwDir();

        virtual void SetWwwDir(Pathname wwwDir);

    protected:
        // location of www directory of the server
        Pathname m_wwwDir;
};

#endif  // Apoxi_AddOns_Server_HttpServerConfig_hpp

