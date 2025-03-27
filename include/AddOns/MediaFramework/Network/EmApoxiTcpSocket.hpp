/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(EmApoxiTcpSocket_hpp)
#define EmApoxiTcpSocket_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*
    This is an internal class which should not be used by the MMI in a direct 
    manner, and the interface may be changed in future releases.
*/

#include "EmApoxiInterface.hpp"
#include "EmApoxiInetSocketAddr.hpp"

class ExtndTcpSocket;


class EmApoxiTcpSocket
{

    public:

        EmApoxiTcpSocket();

        EmApoxiBOOLEAN Close();

        EmApoxiBOOLEAN Open();

        EmApoxiBOOLEAN Connect(EmApoxiInetSocketAddr &to);

        EmApoxiINT32 Write(const void *buf, EmApoxiINT32 buflen);

        ~EmApoxiTcpSocket();

        void Init(EmSockEventCbFn a_sock_event_cb_fn, void *a_user_data);

        static EmApoxiINT32 ReadFromSocket(void *a_sock,
            EmApoxiUINT8 *ap_buff, EmApoxiINT32 a_len);

        EmApoxiBOOLEAN SetDataConnProfileId(EmApoxiDataConnProfileId prof_id);


    protected:

    private:
        ExtndTcpSocket *mp_tcp_socket;
        
}; // EmApoxiTcpSocket

#endif // DOXYGEN_SHOULD_SKIP_THIS
#endif // EmApoxiTcpSocket_hpp

