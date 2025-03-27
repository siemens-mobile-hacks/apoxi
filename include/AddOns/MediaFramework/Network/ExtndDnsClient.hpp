/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ExtndDnsClient_hpp)
#define ExtndDnsClient_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include <Socket/DnsClient.hpp>

#include "EmApoxiInterface.hpp"

class ExtndDnsClient : public DnsClient
{
    typedef DnsClient Base;

    public:
        void OnNameResponse(const String &name, UINT16 error_no);

        void OnAddrResponse(const IpAddr &ip_addr, UINT16 error_no);

        
}; // ExtndDnsClient

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // ExtndDnsClient_hpp

