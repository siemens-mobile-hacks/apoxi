/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpRequest_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpRequest_hpp

#include <Socket/InetSocketAddr.hpp>


class FtpRequest;

class FtpRequest
{
    public:
        FtpRequest(const InetSocketAddr& peerAddr, UINT clientId, const String& cmd, const String& params);
        virtual ~FtpRequest();

        const InetSocketAddr& GetPeerAddr() const { return m_peerAddr; }
        UINT GetClientId() const { return m_clientId; }
        const String& GetCmd() const { return m_cmd; }
        const String& GetParams() const { return m_params; }

    private:
        InetSocketAddr m_peerAddr;
        UINT m_clientId;
        String m_cmd;
        String m_params;
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpRequest_hpp

