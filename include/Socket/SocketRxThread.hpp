/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketRxThread_hpp)
#define Apoxi_SocketRxThread_hpp

#include <Kernel/Os/Os.hpp>
#include <Socket/Sys/SysSocket.hpp>

class SocketData;

class SocketRxThread : public Thread
{
    public:
        SocketRxThread();

        BOOLEAN Init();

        static BOOLEAN NotifyOnDataRecv(const SocketData *sd, BOOLEAN enable = TRUE);
        static BOOLEAN NotifyOnReadyToSend(const SocketData *sd, BOOLEAN enable = TRUE);
        static BOOLEAN StopNotifications(const SocketData *sd);
        static BOOLEAN Wakeup();
        static BOOLEAN Shutdown();

    private:
        typedef SysSocket::FdSet FdSet;

        static BOOLEAN m_quit;
        static INT m_socket_count;
        static UINT32 m_msg_id;
        static Semaphore m_sem_wait;
        static FdSet m_read_fds;
        static FdSet m_write_fds;
        static FdSet m_sel_read_fds;
        static FdSet m_sel_write_fds;

        virtual INT ThreadFn();

        static void TraceFdSet();

        static BOOLEAN AddToFds(const SocketData *s, FdSet &fds);
        static BOOLEAN RemoveFromFds(const SocketData *s, FdSet &fds);
};

#endif  // Apoxi_SocketRxThread_hpp

