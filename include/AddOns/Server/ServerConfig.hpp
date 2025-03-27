/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_ServerConfig_hpp)
#define Apoxi_AddOns_Server_ServerConfig_hpp

#include <Afs/Rfs/Pathname.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Socket/DataConnProfile.hpp>

class ServerConfig;

typedef NiSharedPtr<ServerConfig> ServerConfigPtr;

class ServerConfig
{
    public:
        ServerConfig();

        virtual ~ServerConfig();

        virtual const Pathname& GetRootDir();

        virtual void SetRootDir(Pathname rootDir);

        virtual DataConnProfileId GetDataConnProfileId();

        virtual void SetDataConnProfileId(DataConnProfileId dataConnProfileId);

        virtual UINT GetMaxUsers();

        virtual void SetMaxUsers(UINT maxUsers);

        virtual INT GetBacklog();

        virtual void SetBacklog(INT backlog);

    protected:
        // location of root directory of the server
        Pathname m_rootDir;

        // ID of the DataConnProfile to use for socket connections
        DataConnProfileId m_dataConnProfileId;

        // maximum of currently connected clients
        UINT m_maxUsers;

        // value for backlog of the listening TcpServerSocket
        INT m_backlog;
};

#endif  // Apoxi_AddOns_Server_ServerConfig_hpp

