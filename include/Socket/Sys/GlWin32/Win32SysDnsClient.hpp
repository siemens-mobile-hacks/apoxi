/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Win32_SysDnsClient_hpp)
#define Apoxi_Win32_SysDnsClient_hpp

#include <Kernel/Os/Semaphore.hpp>
#include <Kernel/Os/SystemTimer.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/Vector.hpp>
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


        static Semaphore s_async_sem;
        static BOOLEAN s_async_sem_init;

        struct AsyncDnsRequest {
            DnsClient* m_dns_client;
            BOOLEAN m_is_host_by_name;
            String m_name;
            IpAddr m_ip_addr;
        };

        static Vector<AsyncDnsRequest> s_dns_requests;

        static INT AddAsyncDnsRequest(DnsClient* dns_client,
            BOOLEAN m_is_host_by_name, const String &name,
            const IpAddr &ip_addr);

        static INT ProcessAsyncDnsRequests();

        static void RemoveAsyncDnsRequests(DnsClient* dns_client);

};

#endif  // Apoxi_Win32_SysDnsClient_hpp

