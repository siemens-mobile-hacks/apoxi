/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(EmApoxiInetSocketAddr_hpp)
#define EmApoxiInetSocketAddr_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"
#include "EmApoxiIpAddr.hpp"
#include "EmApoxiIpPortNo.hpp"

class InetSocketAddr;

class EmApoxiInetSocketAddr
{

    public:

        EmApoxiInetSocketAddr(
            const EmApoxiIpAddr &ip = EmApoxiIpAddr(), 
            const EmApoxiIpPortNo &port = EmApoxiIpPortNo());

        ~EmApoxiInetSocketAddr();

        void SetPortNo(const EmApoxiIpPortNo& port);

        InetSocketAddr *GetInetSocketAddr() const {return mp_inet_socket_addr;}


    protected:


    private:
        InetSocketAddr *mp_inet_socket_addr;
        
}; // EmApoxiInetSocketAddr

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiInetSocketAddr_hpp

