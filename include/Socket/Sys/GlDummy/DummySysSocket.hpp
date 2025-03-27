/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */


#if !defined(Apoxi_Sys_Dummy_SysSocket_hpp)
#define Apoxi_Sys_Dummy_SysSocket_hpp


#include <Socket/Sys/SysSocketBase.hpp>


/*  -------------------------------------------------------------------------
                                        Types
    ------------------------------------------------------------------------- */

class SysSocket : public SysSocketBase
{
    friend class SocketRxThread;
    friend class DataConn;

    public:
        class FdSet {
            public:
                FdSet() { }

                BOOLEAN TestFor(const SysSocket &s) const { return FALSE; }
                void Add(const SysSocket &s) {  }
                void Remove(const SysSocket &s) { }
                void Reset() { }

                FdSet& operator=(const FdSet &fds) {
                    return *this;
                }
        };

        typedef int SocketHdl;

        enum Type {
            c_type_dgram,
            c_type_stream,
            c_type_raw
        };

        enum AddrFamily {
            c_addr_family_inet,
            c_addr_family_unspec
        };

        enum {
            c_pref_stack_size = 1000            // preferred stack size for SocketRxThread
        };

        typedef int Protocol;

        SysSocket(SocketHdl socket = -1) { }

        BOOLEAN IsValid() const { return -1; }
        SocketHdl GetHdl() const { return -1; }

        static SocketHdl GetInvalidHdl() { return -1; }

        BOOLEAN Init(INT af, INT type, INT protocol) { return FALSE; }
        INT Close() { return -1; }

        BOOLEAN Accept(SysSocket *s, InetSocketAddr *peer) { return FALSE; }
        INT Bind(const InetSocketAddr &addr) { return -1; }
        INT Connect(const InetSocketAddr &peer) { return -1; }

        INT Listen(INT backlog) { return -1; }
        INT Recv(void *buf, INT buflen, INT flags) { return -1; }
        INT RecvFrom(void *buf, INT buflen, INT flags, InetSocketAddr &peer) { return -1; }

        INT Send(const void *buf, INT buflen, INT flags) { return -1; }
        INT SendTo(const void *buf, INT buflen, INT flags, const InetSocketAddr &peer) { return -1; }

        INT Shutdown(INT) { return -1; }

        INT GetLocal(InetSocketAddr &local) { return -1; }
        INT GetPeer(InetSocketAddr &peer) { return -1; }

        INT GetInBufByteCount(UINT &arg) { return -1; }

        INT GetOption(OptionType type, INT &val) { return -1; }
        INT SetOption(OptionType type, INT val) { return -1; }

        SocketError GetSysError() { return c_socket_fatal_system_error; }

        static INT PsdLinkInit(const UINT8 nsapi) {
            return 0;
        };

        static INT PsdLinkUp(const UINT8 nsapi, BOOLEAN ackmode, UINT32 ipaddr) {
            return 0;
        };

        static INT PsdLinkStop(const UINT8 nsapi) {
            return 0;
        };

    private:
        static INT Select(SysSocket::FdSet &readfds, SysSocket::FdSet &writefds, const Ticks *t_timeout = 0) { return -1; }
        static INT SignalSelect() { return -1; }

        static INT SystemInit() { return 0; }
        static INT PppConnSetup(BOOLEAN serial, const CHAR *account, const CHAR *pwd, PppConnSetupDone callback) {
            callback(0);
            return 0;
        };
        static INT PppStop(PppConnSetupDone callback) {
            callback(0);
            return 0;
        };
};



#endif  // Apoxi_Sys_Dummy_SysSocket_hpp


