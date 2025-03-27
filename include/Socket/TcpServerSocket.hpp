/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TcpServerSocket_hpp)
#define Apoxi_TcpServerSocket_hpp

#include <Socket/TcpSocketBase.hpp>

class TcpSocket;

class TcpServerSocket : public TcpSocketBase
{
    typedef TcpSocketBase Base;

    public:
        enum {
            c_default_max_pending_requests = 5
        };

#if defined(APOXI_COMPAT_1_13_0)

        inline BOOLEAN Init(const InetSocketAddr &local_addr,
            BOOLEAN may_reuse_addr = TRUE)
        {
            return Open(local_addr, may_reuse_addr);
        }
#endif

        BOOLEAN Open(const InetSocketAddr &local_addr,
            BOOLEAN may_reuse_addr = TRUE);

        BOOLEAN Listen(INT backlog = c_default_max_pending_requests);

        BOOLEAN Accept(TcpSocket &socket, InetSocketAddr *peer_addr = 0);

        BOOLEAN HandOver(TcpServerSocket &to_socket)
            { return Base::HandOver(to_socket); }

    protected:
        virtual void OnControlMsg(const SocketControlMsg &msg);
};

#endif  // Apoxi_TcpServerSocket_hpp

