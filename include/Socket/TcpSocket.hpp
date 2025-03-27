/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_TcpSocket_hpp)
#define Apoxi_TcpSocket_hpp

#include <Socket/TcpSocketBase.hpp>

class TcpSocket : public TcpSocketBase
{
    typedef TcpSocketBase Base;

    public:

        TcpSocket();

#if defined(APOXI_COMPAT_1_13_0)

        inline BOOLEAN Init(const InetSocketAddr *local_addr = 0, BOOLEAN may_reuse_addr = TRUE) {
            return Open(local_addr, may_reuse_addr);
        }
#endif

        BOOLEAN Open(const InetSocketAddr *local_addr = 0, BOOLEAN may_reuse_addr = TRUE) {
            return Base::Open(local_addr, may_reuse_addr);
        }

        BOOLEAN Connect(const InetSocketAddr &to, BOOLEAN event = FALSE);

        INT Read(void *buf, INT buflen)
            { return Base::Read(buf, buflen, 0); }

        INT Write(const void *buf, INT buflen)
            { return Base::Write(buf, buflen, 0); }

        BOOLEAN HandOver(TcpSocket &to_socket)
            { return Base::HandOver(to_socket); }

    protected:
        virtual void OnControlMsg(const SocketControlMsg &msg);

    private:
        BOOLEAN m_async_connect;    // Flag for handling asynchronous connect.
};

#endif  // Apoxi_TcpSocket_hpp


