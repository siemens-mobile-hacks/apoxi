/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SerialSocketData_hpp)
#define Apoxi_SerialSocketData_hpp

#include <Socket/Sys/SysSocket.hpp>
#include <Socket/SocketData.hpp>
#include <Socket/DataConnProfile.hpp>
#include "SerialSocket.hpp"
#include <Kernel/Condition.hpp>

class Socket;
class ExecutionContext;
class SerialIoSet;

/* This is derived from SocketData only to pass this object using SocketControlMsg */
class SerialSocketData  : public SocketData
{
    typedef SocketData Base;

    friend class SerialSocket;
    friend class SerialClientSocket;
    friend class SerialServerSocket;
    friend class SerialSocketSubSystem;

    public:
        SerialSocket* GetAttachedSerialSocket() const { return ( m_socket ); }
        ExecutionContext* GetContext() const { return m_context; }

        BOOLEAN IsInUse() const { return m_socket != 0; }

        SerialIoSet *GetSerialIoSet () const { return m_io_set; }
        void SetSerialIoSet ( SerialIoSet *set ) { m_io_set = set; }

    private:
        SerialSocket *m_socket;
        ExecutionContext *m_context;
        SerialIoSet *m_io_set;

        SerialSocketData();

        void Attach(SerialSocket *s);
        void Detach(SerialSocket *s);
};

#endif  // Apoxi_SocketData_hpp

