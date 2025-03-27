/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ExtndTcpSocket_hpp)
#define ExtndTcpSocket_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include <Socket/DataConnManager.hpp>
#include <Socket/TcpSocket.hpp>

#include "EmApoxiInterface.hpp"

class ExtndTcpSocket : public TcpSocket
{
    typedef TcpSocket Base;

    public:

        ExtndTcpSocket();

        void Init(EmSockEventCbFn a_sock_event_cb_fn, void *a_user_data);

        ~ExtndTcpSocket();

    protected:

        virtual void OnAsyncEvent(Event event);


    private:
        EmSockEventCbFn *m_sock_event_cb_fn;
        void *m_sock_event_user_data;
        
}; // ExtndTcpSocket

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // ExtndTcpSocket_hpp

