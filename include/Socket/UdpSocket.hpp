/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_UdpSocket_hpp)
#define Apoxi_UdpSocket_hpp

#include <Socket/InetSocket.hpp>

class UdpSocket : public InetSocket
{
    typedef InetSocket Base;

    public:

#if defined(APOXI_COMPAT_1_13_0)

        inline BOOLEAN Init(const InetSocketAddr *local_addr = 0,
            BOOLEAN may_reuse_addr = TRUE)
        {
            return Open(local_addr, may_reuse_addr);
        }
#endif

        BOOLEAN Open(const InetSocketAddr *local_addr = 0,
            BOOLEAN may_reuse_addr = TRUE);

        BOOLEAN SetPeer(const InetSocketAddr &addr);

        INT Read(void *buf, INT buflen, InetSocketAddr *from = 0)
            { return Base::Read(buf, buflen, from); }

        INT Write(const void *buf, INT buflen, const InetSocketAddr *to = 0)
            { return Base::Write(buf, buflen, to); }

        BOOLEAN HandOver(UdpSocket &to_socket)
            { return Base::HandOver(to_socket); }

    protected:
        virtual void OnControlMsg(const SocketControlMsg &msg);
};

#endif  // Apoxi_UdpSocket_hpp

