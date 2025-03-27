/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NetAdapterHandler_hpp)
#define Apoxi_NetAdapterHandler_hpp

#include <Kernel/Os/Semaphore.hpp>
#include <Auxiliary/NonCloneable.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/IpAddr.hpp>
#include <Auxiliary/IpPortNo.hpp>
#include <Socket/InetSocketAddr.hpp>
#include <Socket/UdpSocket.hpp>
#include <Socket/TcpSocket.hpp>

class InetSocket;
class NetAdapterHandler;

class NetAdapter : public NonCloneable {

    public:
        typedef UINT Id;

        enum Type {
            c_type_udp,
            c_type_tcp
        };

        enum Event {
            c_event_data_sent,
            c_event_data_received,
            c_event_adapter_closed
        };

        struct DataSentEventArgs;
        struct DataReceivedEventArgs;

        struct EventArgs {
            virtual const DataSentEventArgs& GetDataSentEventArgs() const
            { ASSERT_ALWAYS(FALSE); return static_cast<const DataSentEventArgs&>(*this); };
            virtual const DataReceivedEventArgs& GetDataReceivedEventArgs() const
            { ASSERT_ALWAYS(FALSE); return static_cast<const DataReceivedEventArgs&>(*this); };
        };

        struct DataSentEventArgs : public EventArgs {

            virtual const DataSentEventArgs& GetDataSentEventArgs() const
            { return static_cast<const DataSentEventArgs&>(*this); }

            UINT32 m_data_len;
        };

        struct DataReceivedEventArgs : public EventArgs {

            virtual const DataReceivedEventArgs& GetDataReceivedEventArgs() const
            { return static_cast<const DataReceivedEventArgs&>(*this); }

            UINT32 m_data_len;
            UINT8* m_buffer;
            InetSocketAddr m_recv_from;
        };

    public:
        NetAdapter(
            NetAdapterHandler* handler,
            Id id,
            Type type);

        Id GetId() const {
            return m_id;
        }

        Type GetType() const {
            return m_type;
        }

    protected:
        NetAdapterHandler* m_handler;
        Id  m_id;
        Type m_type;
        // ToDo: Add this to all constructors.
        // BOOLEAN  m_is_server; 
};


class NetAdapterHandler : public NonCloneable {

    friend class NetAdapter;
    friend class ClientNetAdapter;

    public:
        typedef NiSharedPtr<NetAdapter> NetAdapterPtr;

        typedef void (*NetAdapterHandlerCallback)(void* client_arg,
            NetAdapterHandler &handler, NetAdapter &net_adapter,
            NetAdapter::Event event, const NetAdapter::EventArgs &event_args);

        NetAdapterHandler(NetAdapterHandlerCallback callback, void* client_arg, UINT32 recv_buffer_size = 512);

        ~NetAdapterHandler();

        NetAdapter::Id OpenClientNetAdapter(DataConnProfileId dc_id,
            NetAdapter::Type net_adapter_type,
            const IpAddr& remote_address, const IpPortNo& remote_port, IpPortNo* local_port = 0);

        NetAdapter::Id OpenServerNetAdapter(DataConnProfileId dc_id,
            NetAdapter::Type net_adapter_type,
            const IpPortNo& local_port);

        BOOLEAN Send(NetAdapter::Id id, const UINT8* buffer, UINT32 len, InetSocketAddr *to = 0)
            const;

        NetAdapterPtr GetNetAdapter(NetAdapter::Id id) const;

        // Closes the given NetAdapter.
        BOOLEAN CloseNetAdapter(NetAdapter::Id id);

        // Closes all NetAdapters.
        void CloseAllNetAdapters();

        static UINT GetInvalidNetAdapterId() { return static_cast<UINT>(-1); }

    protected:

        // Application overrides

        virtual void OnDataReceived(NetAdapter &netadapter, const NetAdapter::DataReceivedEventArgs& args)
            { InvokeCallBack(netadapter, NetAdapter::c_event_data_received, args); }

        virtual void OnDataSent(NetAdapter &netadapter, const NetAdapter::DataSentEventArgs& args)
            { InvokeCallBack(netadapter, NetAdapter::c_event_data_sent, args); }

        virtual void OnNetAdapterClosed(NetAdapter &netadapter)
            { InvokeCallBack(netadapter, NetAdapter::c_event_adapter_closed); }


    private:
        
        NetAdapterPtr CreateNetAdapter(NetAdapter::Type type);

        void InvokeCallBack(NetAdapter &net_adapter, NetAdapter::Event event,
            const NetAdapter::EventArgs &args = NetAdapter::EventArgs());

        NetAdapter::Id OpenNetAdapter(DataConnProfileId dc_id,
            NetAdapter::Type net_adapter_type, const IpAddr& remote_address,
            const IpPortNo& remote_port, IpPortNo* local_port, BOOLEAN is_server);

        BOOLEAN OpenNetAdapter(
            NetAdapterPtr net_adapter, DataConnProfileId dc_id,
            const IpAddr& remote_address, const IpPortNo& remote_port,
            IpPortNo* local_port, BOOLEAN is_server);

        void* m_client_arg;

        NetAdapterHandlerCallback m_callback;

        mutable Semaphore m_map_sem;

        typedef SimpleMap<NetAdapter::Id, NetAdapterPtr> NetAdapterMap;
        NetAdapterMap m_net_adapter_map;

        const UINT32 m_recv_buffer_size;
};


class ClientNetAdapter : public NetAdapter {
    typedef NetAdapter Base;

    public:
        ClientNetAdapter(
            NetAdapterHandler* handler,
            NetAdapter::Id id,
            NetAdapter::Type type);

        virtual ~ClientNetAdapter();

        virtual BOOLEAN Send(const UINT8* data, UINT32 len, InetSocketAddr *to = 0);
        void HandleOnAsyncEvent(InetSocket::Event event);

        virtual INT Read(void *buf, INT buflen, InetSocketAddr *from = 0) = 0;
        virtual INT Write(const void *buf, INT buflen, InetSocketAddr *to = 0) = 0;
        virtual INT GetInBufByteCount() = 0;
        virtual SocketError GetError() const = 0;

    protected:
        UINT8* m_recv_buffer;

        UINT8* m_send_buffer;
        UINT32 m_send_buffer_size;
        UINT32 m_send_buffer_offset;
        UINT32 m_data_sent;

        Semaphore m_send_sem;
};

class UdpNetAdapter : public UdpSocket, public ClientNetAdapter {

    typedef UdpSocket Base;

    public:
        UdpNetAdapter(
            NetAdapterHandler* handler,
            NetAdapter::Id id,
            NetAdapter::Type type);

        virtual INT Read(void *buf, INT buflen, InetSocketAddr *from = 0)
        { return Base::Read(buf, buflen, from); }

        virtual INT Write(const void *buf, INT buflen, InetSocketAddr *to = 0)
        { return Base::Write(buf, buflen, to);  }

        virtual INT GetInBufByteCount()
        { return Base::GetInBufByteCount(); }

        virtual SocketError GetError() const
        { return Base::GetError(); }

    protected:
        virtual void OnAsyncEvent(InetSocket::Event event)
        { ClientNetAdapter::HandleOnAsyncEvent(event); }
};

class TcpNetAdapter : public TcpSocket, public ClientNetAdapter {

    typedef TcpSocket Base;

    public:
        TcpNetAdapter(
            NetAdapterHandler* handler,
            NetAdapter::Id id,
            NetAdapter::Type type);

        virtual INT Read(void *buf, INT buflen, InetSocketAddr *from = 0)
        { return Base::Read(buf, buflen); }

        virtual INT Write(const void *buf, INT buflen, InetSocketAddr *to = 0)
        { return Base::Write(buf, buflen);  }

        virtual INT GetInBufByteCount()
        { return Base::GetInBufByteCount(); }

        virtual SocketError GetError() const
        { return Base::GetError(); }

    protected:
        virtual void OnAsyncEvent(InetSocket::Event event)
        { ClientNetAdapter::HandleOnAsyncEvent(event); }
};

#endif   // Apoxi_NetAdapterHandler_hpp

