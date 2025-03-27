/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Lwip_SysDnsClient_hpp)
#define Apoxi_Lwip_SysDnsClient_hpp

#include <Kernel/Os/SystemTimer.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/IpAddr.hpp>
#include <Auxiliary/String.hpp>

class DnsClient;
struct hostent;

class DataConn;
typedef NiSharedPtr<DataConn> DataConnPtr;

class SysDnsClient
{
    friend class DnsClient;

    public:
        static INT GetHostByName(const String &name, IpAddr &ip_addr,
            const DataConnPtr &dc_ptr);

        static INT GetHostByAddr(const IpAddr &ip_addr, String &name,
            const DataConnPtr &dc_ptr);

    protected:
        SysDnsClient(DnsClient* dns_client);

        virtual ~SysDnsClient();

        INT GetHostByNameAsync(const String &name);

        INT GetHostByAddrAsync(const IpAddr &ip_addr);

    private:
        DnsClient* m_dns_client;

        static BOOLEAN CheckDcAndUpdateNameServers(const DataConnPtr &dc_ptr);

        static void AsyncDnsHostByNameCallback(void* client_args,
            INT status, struct hostent *host);

        static void AsyncDnsHostByAddrCallback(void* client_args,
            INT status, struct hostent *host);

        static void OnTimer(void *args);

        static SystemTimer s_timer;

};

#endif  // Apoxi_Lwip_SysDnsClient_hpp

