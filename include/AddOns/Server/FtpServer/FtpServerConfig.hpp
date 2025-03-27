/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServerConfig_hpp)
#define Apoxi_AddOns_Server_FtpServerConfig_hpp

#include <AddOns/Server/ServerConfig.hpp>
#include "FtpTypes.hpp"

class FtpServerConfig;

typedef NiSharedPtr<FtpServerConfig> FtpServerConfigPtr;

class FtpServerConfig : public ServerConfig
{
    typedef ServerConfig Base;

    public:
        FtpServerConfig();

        virtual ~FtpServerConfig();
};

#endif  // Apoxi_AddOns_Server_FtpServerConfig_hpp

