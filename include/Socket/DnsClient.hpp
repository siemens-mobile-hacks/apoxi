/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DnsClient_hpp)
#define Apoxi_DnsClient_hpp

#include <Socket/DataConnProfile.hpp>

class SysDnsClient;

class DnsClient
{
    friend class SysDnsClient;

    public:
        static void Init() { }

        static void Shutdown() { }

#if defined(APOXI_COMPAT_1_13_0)

        inline static void ShutDown() { Shutdown(); }
#endif

        static UINT16 GetHostByName(const String &name, IpAddr &ip_addr,
            const DataConnProfile *dc_prof = 0);

        static UINT16 GetHostByAddr(const IpAddr &ip_addr, String &name,
            const DataConnProfile *dc_prof = 0);

    public:

#if defined(APOXI_COMPAT_1_13_0)

        DnsClient(const DataConnProfile *dc_prof = 0);

        DnsClient(const DataConnProfilePtr &dc_prof);
#else

        DnsClient(const DataConnProfilePtr &dc_prof = DataConnProfilePtr());
#endif

        virtual ~DnsClient();

        BOOLEAN GetHostByNameAsync(const String &name);

        BOOLEAN GetHostByAddrAsync(const IpAddr &ip_addr);

    protected:
        virtual void OnNameResponse(const String &name, UINT16 error_no) {};

        virtual void OnAddrResponse(const IpAddr &ip_addr, UINT16 error_no) {};

    private:
        static DataConnPtr ActivateDataConn(DataConnProfileId &dcp_id);

        SysDnsClient *m_sys_dns_client;

        DataConnPtr m_dc_ptr;

        DataConnProfileId m_profile_id;
};

#endif  // Apoxi_DnsClient_hpp


