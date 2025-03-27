/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_InetSocketAddr_hpp)
#define Apoxi_InetSocketAddr_hpp

#include <Auxiliary/IpAddr.hpp>
#include <Auxiliary/IpPortNo.hpp>
#include <Auxiliary/String.hpp>

class InetSocketAddr
{
    public:
        InetSocketAddr(const IpAddr &ip = IpAddr(), const IpPortNo &port = IpPortNo());

        IpPortNo GetPortNo() const { return m_port; }
        void SetPortNo(const IpPortNo &port) { m_port = port; }

        IpAddr GetIpAddr() const { return m_addr; }
        void SetIpAddr(const IpAddr &ip) { m_addr = ip; }

        String Verbose() const;

    private:
        IpAddr m_addr;
        IpPortNo m_port;
};

#endif  // Apoxi_InetSocketAddr_hpp


