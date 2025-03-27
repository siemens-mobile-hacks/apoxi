/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiDnsClient_hpp)
#define EmApoxiDnsClient_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"
#include "EmApoxiIpAddr.hpp"

class ExtndDnsClient;

class EmApoxiDnsClient
{

    public:

        EmApoxiDnsClient();

        static void Init();

        EmApoxiBOOLEAN GetHostByName(char *a_name, EmApoxiIpAddr &a_ip_addr);

        ~EmApoxiDnsClient();


    protected:


    private:
        ExtndDnsClient *mp_dns_client;
        
}; // EmApoxiDnsClient

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiDnsClient_hpp

