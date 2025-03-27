/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_ServerClient_hpp)
#define Apoxi_AddOns_Server_ServerClient_hpp

class ServerClient;

typedef NiSharedPtr<ServerClient> ServerClientPtr;

class Server;


class ServerClient
{
    friend class Server;

    public:
        virtual ~ServerClient();

        virtual UINT GetId();

    protected:
        ServerClient(Server* server);

        // Counts actually used instances.
        static UINT s_instance_cnt;

        // parent server
        Server* m_server;

        // id of the client (the following number of s_instance_cnt on initialization)
        UINT m_clientId;

};

#endif  // Apoxi_AddOns_Server_ServerClient_hpp

