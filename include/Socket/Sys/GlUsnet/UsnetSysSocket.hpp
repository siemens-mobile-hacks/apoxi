/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Sys_BsdSysSocket_hpp)
#define Apoxi_Sys_BsdSysSocket_hpp


#if !defined(APOXI_SOCKET_SYSTEM_USNET)
    #error incorrect include of USNET specific header file
#endif

extern "C" {                // include usnet files - adopt include path in makefile
#include <usnet/local.h>
#include <usnet/socket.h>
}


#if defined(APOXI_RTOS_OSE166)
    #include <usnet/usnet_ose166.h>
#else
    #error Unsupported operating system for USNET SysSocket
#endif

#include <Socket/Sys/SysSocketBase.hpp>

/*  -------------------------------------------------------------------------
                                        Types
    ------------------------------------------------------------------------- */


class SysSocket : public SysSocketBase
{
    friend class SocketRxThread;
    friend class DataConn;

    public:
        class FdSet : public fd_set {
            public:
                FdSet() { Reset(); }

                BOOLEAN TestFor(const SysSocket &s) const { return FD_ISSET(s.GetHdl(), this); }
                void Add(const SysSocket &s) { FD_SET(s.GetHdl(), this); }
                void Remove(const SysSocket &s) { FD_CLR(s.GetHdl(), this); }
                void Reset() { FD_ZERO(this); }

                FdSet& operator=(const FdSet &fds) {
                    memcpy((fd_set *) this, &(const fd_set &) fds, sizeof(fd_set));
                    return *this;
                }
        };

        typedef int SocketHdl;

        enum Type {
            c_type_dgram = SOCK_DGRAM,
            c_type_stream = SOCK_STREAM,
            c_type_raw = SOCK_RAW
        };

        enum AddrFamily {
            c_addr_family_inet = AF_INET,
            c_addr_family_unspec = AF_UNSPEC
        };

        enum {
            c_pref_stack_size = 2000            // preferred stack size for SocketRxThread
        };

        typedef int Protocol;

        SysSocket(SocketHdl socket = -1);

        BOOLEAN IsValid() const { return m_socket != -1; }
        SocketHdl GetHdl() const { return m_socket; }

        static SocketHdl GetInvalidHdl() { return -1; }

        BOOLEAN Init(INT af, INT type, INT protocol);
        INT Close();

        BOOLEAN Accept(SysSocket *s, InetSocketAddr *peer);
        INT Bind(const InetSocketAddr &addr);
        INT Connect(const InetSocketAddr &peer);

        INT Listen(INT backlog) { return listen(m_socket, backlog); }
        INT Recv(void *buf, INT buflen, INT flags) { return recv(m_socket, (CHAR *) buf, buflen, flags); }
        INT RecvFrom(void *buf, INT buflen, INT flags, InetSocketAddr &peer);

        INT Send(const void *buf, INT buflen, INT flags) { return send(m_socket, (CHAR *) buf, buflen, flags); }
        INT SendTo(const void *buf, INT buflen, INT flags, const InetSocketAddr &peer);

        INT Shutdown(INT how) { return shutdown(m_socket, how); }

        INT GetLocal(InetSocketAddr &local);
        INT GetPeer(InetSocketAddr &peer);

        INT GetInBufByteCount(UINT &arg) { return ioctlsocket(m_socket, FIONREAD, &arg); }

        INT GetOption(OptionType type, INT &val);
        INT SetOption(OptionType type, INT val);
        
        SocketError GetSysError();

    private:
        SocketHdl m_socket;

        static INT Select(SysSocket::FdSet &readfds, SysSocket::FdSet &writefds, const Ticks *t_timeout = 0);
        static INT SignalSelect();

        static SocketError MapSysErrorCode(INT err);
        static BOOLEAN MapOptionType(SysSocket::OptionType type, INT &so_level, INT &so_type);

        static INT SystemInit() { return net_Init(); }
        static INT PppConnSetup(const CHAR *account, const CHAR *pwd, PppConnSetupDone callback);
        static void PppCallBack(NetError err);
        static INT PppStop(PppConnSetupDone callback) {
            callback(0);
            return 0;
        };
};



#endif  // Apoxi_Sys_BsdSysSocket_hpp


