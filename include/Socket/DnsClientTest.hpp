/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DnsClientTest_hpp)
#define Apoxi_DnsClientTest_hpp

#include <Socket/DnsClient.hpp>

class DnsClientTest : public DnsClient
{
    public:
        DnsClientTest();

        virtual ~DnsClientTest();

    protected:
        virtual void OnNameResponse(const String & name, UINT16 error_no);

        virtual void OnAddrResponse(const IpAddr & ip_addr, UINT16 error_no);
};

#endif //Apoxi_DnsClientTest_hpp


