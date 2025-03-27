/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SerialSocketThread_hpp)
#define Apoxi_SerialSocketThread_hpp

#include <Kernel/Os/Os.hpp>
#include <Socket/Sys/SysSocket.hpp>
#include "SerialIoAdapter.hpp"

class SerialSocketData;

class SerialSocketThread : public Thread
{
        typedef Thread Base;

    public:
        SerialSocketThread ();

        BOOLEAN Init();

        static BOOLEAN NotifyOnData(const SerialSocketData *sd, BOOLEAN enable = TRUE);

        static BOOLEAN StopNotifications(const SerialSocketData *sd);

        static BOOLEAN Wakeup();

        static BOOLEAN Shutdown();

        static BOOLEAN AddToList(const SerialSocketData *sd, SerialIoSet &set);

        static BOOLEAN RemoveFromList(const SerialSocketData *sd, SerialIoSet &set);

        static SerialIoSet* GetIoSetInstance() { return &m_ioset; }

    private:
        static BOOLEAN m_quit;
        static INT m_socket_count;
        static UINT32 m_msg_id;
        static Semaphore m_sem_wait;
        static SerialIoSet m_ioset;

        virtual INT ThreadFn();

        static void TraceFdSet();

};

#endif  // Apoxi_SocketRxThread_hpp


