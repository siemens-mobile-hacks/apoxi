/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Win32_SysSocket_hpp)
#define Apoxi_Win32_SysSocket_hpp

#include <Socket/Sys/SysSocketBase.hpp>
#include <Socket/SocketTypes.hpp>

class InetSocketAddr;
struct fd_set;
class Ticks;

class SysSocket : public SysSocketBase
{
    friend class SocketRxThread;
    friend class DataConnManager;
    friend class PppDataConn;
    friend class PsdDataConn;

    public:
        typedef UINT32 SocketHdl;

        enum {
            c_pref_stack_size = 100000
        };

        typedef INT Protocol;

        SysSocket(SocketHdl socket = GetInvalidHdl());

        BOOLEAN IsValid() const;
        SocketHdl GetHdl() const { return m_socket; }

        static SocketHdl GetInvalidHdl();
        static UINT8 GetInvalidNsapi();

        BOOLEAN Open(AddrFamily af, Type type, Protocol protocol);
        BOOLEAN SetNsapi(UINT8 nsapi);
        BOOLEAN Close();

        BOOLEAN IsBlocking() const;

        BOOLEAN SetBlocking(BOOLEAN blocking = TRUE);

        BOOLEAN Accept(SysSocket *s, InetSocketAddr *peer);
        BOOLEAN Bind(const InetSocketAddr &addr);
        BOOLEAN Connect(const InetSocketAddr &peer);
        BOOLEAN Listen(INT backlog);

        INT Recv(void *buf, INT buflen, INT flags);
        INT RecvFrom(void *buf, INT buflen, INT flags, InetSocketAddr &peer);

        INT Send(const void *buf, INT buflen, INT flags);
        INT SendTo(const void *buf, INT buflen, INT flags,
            const InetSocketAddr &peer);

        BOOLEAN Shutdown(ShutdownMode how);

        BOOLEAN GetLocal(InetSocketAddr &local) const;
        BOOLEAN GetPeer(InetSocketAddr &peer) const;

        BOOLEAN GetInBufByteCount(UINT &arg) const;

        BOOLEAN GetOption(OptionType type, INT &val) const;
        BOOLEAN SetOption(OptionType type, INT val);

        BOOLEAN GetLingerOption(LingerSetting &linger_setting) const;
        BOOLEAN SetLingerOption(const LingerSetting &linger_setting);

        SocketError GetSysError(BOOLEAN include_global_errors = TRUE) const;

    protected:
        SocketError GetSysErr(BOOLEAN check_errno) const;

    private:
        class FdSet
        {
            friend class SysSocket;

            public:
                FdSet();
                FdSet(const FdSet &fds);
                ~FdSet();

                BOOLEAN TestFor(const SysSocket &s) const;
                void Add(const SysSocket &s);
                void Remove(const SysSocket &s);
                void Reset();

                FdSet& operator=(const FdSet &fds);

            private:
                fd_set *m_fd_set;
        };

        void SetSocket(SocketHdl socket) { m_socket = socket; }

        static BOOLEAN InitCmdSockets();

        static INT Select(FdSet &readfds, FdSet &writefds,
            const Ticks *t_timeout = 0);
        static BOOLEAN SignalSelect();

        static INT MapType(Type type);
        static INT MapAddrFamily(AddrFamily addr_family);
        static INT MapShutdownMode(ShutdownMode mode);

        static BOOLEAN MapOptionType(OptionType type, INT &so_level,
            INT &so_type);

        static INT SystemInit() { return 0; }

        static INT PppConnSetup(BOOLEAN serial, const CHAR *account,
            const CHAR *pwd, PppCallback callback, PppDataConn &dc);

        static INT PppStop(PppCallback callback, PppDataConn &dc) {
            callback(c_ppp_stop_success, dc, 0);
            return 0;
        }

        static INT PppCancel() {
            return 0;
        }

        static INT PsdLinkUp(UINT8 nsapi, BOOLEAN ackmode, UINT32 ipaddr,
            BOOLEAN is_umts, PsdIfCallback callback, PsdDataConn &dc)
        {
            callback(0, static_cast<void*>(&dc)); // Simulate good case.
            return 0;
        }

        static INT PsdLinkStop(UINT8 nsapi, PsdIfCallback callback,
            PsdDataConn &dc) {
            callback(0, static_cast<void*>(&dc)); // Simulate good case.
            return 0;
        }


        SocketHdl m_socket;

        BOOLEAN m_blocking;

        static const int c_ppp_setup_success;

        static const int c_ppp_stop_success;
};

#endif  // Apoxi_Win32_SysSocket_hpp

