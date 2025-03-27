/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(EmApoxiUdpSocket_hpp)
#define EmApoxiUdpSocket_hpp
#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/
#include "EmApoxiInterface.hpp"
#include "EmApoxiInetSocketAddr.hpp"

class ExtndUdpSocket;

class EmApoxiUdpSocket
{

    public:
        EmApoxiUdpSocket();

        void Init(EmSockEventCbFn a_sock_event_cb_fn, void *a_user_data);

        EmApoxiBOOLEAN Open(EmApoxiInetSocketAddr *local_addr = 0,
                        EmApoxiBOOLEAN may_reuse_addr = EmApoxiTRUE);

        EmApoxiINT32 Write(const void *buf, EmApoxiINT32 buflen, EmApoxiInetSocketAddr *to=0);

        static EmApoxiINT32 ReadFromSocket(void *a_sock,
            EmApoxiUINT8 *ap_buff, EmApoxiINT32 a_len);

        ~EmApoxiUdpSocket();


    protected:


    private:
        ExtndUdpSocket *mp_udp_socket;
        
}; // EmApoxiUdpSocket

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiUdpSocket_hpp

