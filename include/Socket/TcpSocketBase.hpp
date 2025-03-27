/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TcpSocketBase_hpp)
#define Apoxi_TcpSocketBase_hpp

#include <Socket/InetSocket.hpp>

/*  -------------------------------------------------------------------------
                                    Types
    ------------------------------------------------------------------------- */

class TcpSocketBase : public InetSocket
{
    typedef InetSocket Base;

    public:
        BOOLEAN GetTcpNoDelayOption(BOOLEAN &nodelay) {
            return GetBoolOption(SysSocket::c_option_tcp_no_delay, nodelay);
        }

        BOOLEAN SetTcpNoDelayOption(BOOLEAN nodelay) {
            return SetBoolOption(SysSocket::c_option_tcp_no_delay, nodelay);
        }

        BOOLEAN GetTcpMaxSetOption(BOOLEAN &nodelay) {
            return GetBoolOption(SysSocket::c_option_tcp_max_seg, nodelay);
        }

        BOOLEAN SetTcpMaxSetOption(BOOLEAN nodelay) {
            return SetBoolOption(SysSocket::c_option_tcp_max_seg, nodelay);
        }

    protected:
        BOOLEAN Open(const InetSocketAddr *local_addr, BOOLEAN may_reuse_addr) {
            return Base::Open(c_type_stream, local_addr, may_reuse_addr);
        }
};

#endif  // Apoxi_TcpSocketBase_hpp


