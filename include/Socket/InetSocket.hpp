/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_InetSocket_hpp)
#define Apoxi_InetSocket_hpp

#include <Socket/Socket.hpp>
#include <Socket/SocketData.hpp>

class InetSocket : public Socket
{
    friend class SocketHandler;
    friend class TcpServerSocket;

    public:
        enum Type {
            c_type_dgram = SysSocket::c_type_dgram,
            c_type_stream = SysSocket::c_type_stream,
            c_type_raw = SysSocket::c_type_raw,

            c_type_default = c_type_dgram
        };

        enum ShutdownMode {
            c_shutdown_stop_rx = SysSocket::c_shutdown_stop_rx,
            c_shutdown_stop_tx = SysSocket::c_shutdown_stop_tx,
            c_shutdown_stop_rx_tx = SysSocket::c_shutdown_stop_rx_tx
        };

        virtual ~InetSocket();

        virtual BOOLEAN IsOpen() const { return m_sd != 0; }

        SocketError GetError() const
            { return m_sd != 0 ? m_sd->GetError() : c_socket_enotsock; }

        BOOLEAN Shutdown(ShutdownMode how);

        virtual BOOLEAN Close();

        BOOLEAN Bind(const InetSocketAddr &addr);

        BOOLEAN GetPeer(InetSocketAddr &addr);

        BOOLEAN GetLocal(InetSocketAddr &addr);

        ExecutionContext* GetOwnerContext() const;

        virtual BOOLEAN IsBlocking() const;
        virtual BOOLEAN SetBlocking(BOOLEAN block = FALSE);

        INT GetInBufByteCount();

        BOOLEAN GetSoTypeOption(Type &type);

        BOOLEAN GetSoDebugOption(BOOLEAN &dbg) {
            return GetBoolOption(SysSocket::c_option_debug, dbg);
        }

        BOOLEAN SetSoDebugOption(BOOLEAN dbg) {
            return SetBoolOption(SysSocket::c_option_debug, dbg);
        }

        BOOLEAN GetSoReuseAddrOption(BOOLEAN &reuse) {
            return GetBoolOption(SysSocket::c_option_reuse_addr, reuse);
        }

        BOOLEAN SetSoReuseAddrOption(BOOLEAN reuse) {
            return SetBoolOption(SysSocket::c_option_reuse_addr, reuse);
        }

        BOOLEAN GetSoKeepAliveOption(BOOLEAN &keep_alive) {
            return GetBoolOption(SysSocket::c_option_keep_alive, keep_alive);
        }

        BOOLEAN SetSoKeepAliveOption(BOOLEAN keep_alive) {
            return SetBoolOption(SysSocket::c_option_keep_alive, keep_alive);
        }

        BOOLEAN GetSoLingerOption(SysSocket::LingerSetting &linger_setting) {
            return SetError(m_sd->GetLingerOption(linger_setting));
        }

        BOOLEAN SetSoLingerOption(
            const SysSocket::LingerSetting &linger_setting)
        {
            return SetError(m_sd->SetLingerOption(linger_setting));
        }

        BOOLEAN GetSoDontRouteOption(BOOLEAN &dont_route) {
            return GetBoolOption(SysSocket::c_option_dont_route, dont_route);
        }

        BOOLEAN SetSoDontRouteOption(BOOLEAN dont_route) {
            return SetBoolOption(SysSocket::c_option_dont_route, dont_route);
        }

        BOOLEAN GetSoBroadcastOption(BOOLEAN &broadcast) {
            return GetBoolOption(SysSocket::c_option_broadcast, broadcast);
        }

        BOOLEAN SetSoBroadcastOption(BOOLEAN broadcast) {
            return SetBoolOption(SysSocket::c_option_broadcast, broadcast);
        }

        BOOLEAN GetSoSndBufOption(INT &bufsize) {
            return SetError(
                m_sd->GetOption(SysSocket::c_option_snd_buf, bufsize));
        }

        BOOLEAN SetSoSndBufOption(INT bufsize) {
            return SetError(
                m_sd->SetOption(SysSocket::c_option_snd_buf, bufsize));
        }

        BOOLEAN GetSoRcvBufOption(INT &bufsize) {
            return SetError(
                m_sd->GetOption(SysSocket::c_option_rcv_buf, bufsize));
        }

        BOOLEAN SetSoRcvBufOption(INT bufsize) {
            return SetError(
                m_sd->SetOption(SysSocket::c_option_rcv_buf, bufsize));
        }

        DataConnProfileId GetDataConnProfileId() const;

        BOOLEAN SetDataConnProfileId(DataConnProfileId id) const;

        BOOLEAN IsDataConnEstablished() const {
            return (IsOpen() && m_sd->IsDaCoActive());
        }

        void SetReadEventNotification(BOOLEAN enable);

    protected:
        SocketData *m_sd;

        BOOLEAN m_read_event_notification;

        typedef SysSocket::OptionType OptionType;

        void ResetDataConnIdleTimer() const;

        virtual void OnAsyncEvent(Event event) { }

        virtual void OnControlMsg(const SocketControlMsg &msg) = 0;

        BOOLEAN GetBoolOption(OptionType type, BOOLEAN &val);
        BOOLEAN SetBoolOption(OptionType type, BOOLEAN val);

        BOOLEAN WaitForDataRecv() { return m_sd->WaitForDataRecv(); }
        BOOLEAN WaitForDataSent() { return m_sd->WaitForDataSent(); }

        BOOLEAN SetError(BOOLEAN ok) {
            ASSERT_DEBUG(IsOpen());
            return m_sd->SetError(ok);
        }

        BOOLEAN SetError(SocketError err) {
            ASSERT_DEBUG(IsOpen());
            return m_sd->SetError(err);
        }

        BOOLEAN EnsureContext();

        SocketData* GetSd() const { return m_sd; }

        void Attach(SocketData *sd);
        void Detach();

        BOOLEAN HandOver(InetSocket &to_socket);

        BOOLEAN SetupDataConn();

        InetSocket();

        BOOLEAN Open(Type type, const InetSocketAddr *local_addr,
            BOOLEAN may_reuse_addr);

        INT Read(void *buf, INT buflen, InetSocketAddr *from);
        virtual INT Read(void *buf, INT buflen) {
            return Read(buf, buflen, 0);
        }

        INT Write(const void *buf, INT buflen, const InetSocketAddr *to);
        virtual INT Write(const void *buf, INT buflen) {
            return Write(buf, buflen, 0);
        }

#ifdef APOXI_SOCKET_OPERATION_LOCK

        BOOLEAN m_operation_pending;

        class OperationLock {
            public:
                OperationLock(BOOLEAN &operation_pending);

                ~OperationLock();

                BOOLEAN LockAcquired() const
                    { return m_lock_acquired; }

            private:
                // External socket operation pending flag.
                BOOLEAN &m_operation_pending;

                // Flag indicating if the operation lock could be acquired or
                // not.
                BOOLEAN m_lock_acquired;

                // Global operation lock semaphore for all active sockets.
                static Semaphore s_sem;

                // Semaphore initialization flag.
                static BOOLEAN s_sem_init;
        };

#endif  // APOXI_SOCKET_OPERATION_LOCK

};

#endif  // Apoxi_InetSocket_hpp

