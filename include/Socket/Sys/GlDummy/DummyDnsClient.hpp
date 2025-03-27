/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Os_Win32_DnsClient_hpp)
#define Apoxi_Os_Win32_DnsClient_hpp


class DnsClient;
class DataConnProfile;

class SysDnsClient
{
    friend class DnsClient;

    public:
        static void Init() {}
        
        static UINT16 GetHostByName(const String & name, IpAddr & ip_addr,
                                    DataConnProfile * dc_profile) {
            return 0;
        }

        static UINT16 GetHostByAddr(const IpAddr & ip_addr, String & name,
                                    DataConnProfile * dc_profile) {
            return 0;
        }

        void OnTimer() {}

    protected:
        SysDnsClient(DataConnProfile * dc_profile) {}

        ~SysDnsClient() {}
        
        BOOLEAN GetHostByNameAsync(DnsClient* dnsc, const String & name) {
            return FALSE;
        }

        BOOLEAN GetHostByAddrAsync(DnsClient* dnsc, const IpAddr & ip_addr) {
            return FALSE;
        }
            
};



#endif  // Apoxi_Os_Win32_DnsClient_hpp


