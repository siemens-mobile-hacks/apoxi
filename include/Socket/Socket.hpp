/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Socket_hpp)
#define Apoxi_Socket_hpp

#include <Auxiliary/NonCloneable.hpp>
#include <Auxiliary/Vector.hpp>

class SocketControlMsg;
class SocketEventListener;

class Socket : public NonCloneable
{
    friend class SocketHandler;

    public:
        enum Event {
            c_event_data_received,
            c_event_data_sent,
            c_event_conn_established,
            c_event_conn_failed,
            c_event_conn_closed,
            c_event_conn_req_pending,
            c_event_bearer_lost
        };

    public:
        Socket();

        virtual ~Socket();

        virtual BOOLEAN IsOpen() const = 0;
        virtual BOOLEAN Close() = 0;

        virtual BOOLEAN IsBlocking() const = 0;

        virtual BOOLEAN SetBlocking(BOOLEAN block = FALSE) = 0;

        virtual INT Read(void *buf, INT buflen) = 0;

        virtual INT Write(const void *buf, INT buflen) = 0;

        static BOOLEAN IsInstanceValid(const Socket *socket);

        virtual void SetSocketEventListener(SocketEventListener *listener) {
            m_listener = listener;
        }

    protected:
        virtual void OnControlMsg(const SocketControlMsg &msg);

        SocketEventListener* GetSocketEventListener() const {
            return m_listener;
        }

    private:
        SocketEventListener* m_listener;

        static Vector<const Socket *>& GetVector();
};

class SocketEventListener
{
    public:
        SocketEventListener();
        virtual ~SocketEventListener();

        virtual void OnSocketEvent(Socket::Event event, Socket *socket) = 0;
};

#endif // Apoxi_Socket_hpp

