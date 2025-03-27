/* ============================================================================
** Copyright (C) 2004-2005 COMNEON GmbH & Co. OHG. All rights reserved.
** ============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** ============================================================================
** Revision Information :
**    File name: SerialIoAdapter.h
**    Version:
**    Date: 2005-08-31    14:48:26
**
** ============================================================================
**
** Project:     VenusU
** Block:       SerialIoAdapter
** Process:
** File name:   SerialIoAdapter.h
**
** ============================================================================
**
**
** ============================================================================
** History:
**
** Date       Author                Comment
** ----------------------------------------------------------------------------
**
** 31.08.05   Murugan/Balan         created.
** ============================================================================
*/

#ifndef SERIALIO_ADAPTER_H
#define SERIALIO_ADAPTER_H


#define SIO_USE_SOCKET_CONCEPT 1

// TODO: remove this define after receiving write_fd support from SIO
// #define SIO_STUB_SELECT_WRITE_SUPPORT

#include <Socket/Socket.hpp>
#include <Kernel/Condition.hpp>
#include <sio_sock.h>
#include <sio_dev.h>
#include "SockAddress.hpp"
#include <iodriver.h>
#include <iolib.h>

#if defined ( SIO_STUB_SELECT_WRITE_SUPPORT )
#define SIO_SIGNAL_DATA_SENT    SIO_SIGNAL_LAST + 1
#else
#define SIO_SIGNAL_DATA_SENT    SIO_SIGNAL_LAST_BIT_SENT
#endif

class SerialSocket;
class SerialSocketData;
class SerialIoSet
{
public:
    SerialIoSet ();
    ~SerialIoSet ();

    enum SerialSocketEvent
    {
            NONE            /* No events */
        ,   ABORT           /* Event for the received ETX char. */
        ,   CLOSE_REQ       /* Close the descriptor. */
        ,   CONNECT_REQ     /* Signal to a server socket. */
        ,   CONNECT_SUCCESS /* Connect success. */
        ,   CONNECT_FAIL    /* Connect fail. */
        ,   DATA_RECEIVED   /* Received data from the serial device. */
        ,   DATA_SENT       /* Data is sent via the serial device. */
        ,   DISCONNECT_IND  /* Signal to a client socket. */
        ,   UNKNOWN         /* Unknown socket */
    };

    BOOLEAN Init();

    BOOLEAN Add( const SerialSocketData *s ) { BOOLEAN ret; ret = !AddToReadList ( s ); ret |= !AddToWriteList ( s ); return ( ret ); }

    BOOLEAN Remove( const SerialSocketData *s ) { BOOLEAN ret; ret = !RemoveFromReadList ( s ); ret |= !RemoveFromWriteList ( s ); return ( ret ); }

    INT AddToReadList(const SerialSocketData *sockdata);

    INT RemoveFromReadList(const SerialSocketData *sockdata );

    INT AddToWriteList(const SerialSocketData *sockdata);

    INT RemoveFromWriteList(const SerialSocketData *sockdata );

    INT Select( const Ticks *t_timeout );

    BOOLEAN SignalSelect ();

    BOOLEAN TestFor ( const SerialSocketData *sockdata ) const;

#if defined ( USE_STUB )
    SerialSocketEvent GetEvent ( const SerialSocketData *sockdata );
#else
    SerialSocketEvent GetEvent ( const SerialSocketData *sockdata ) const;
#endif

public:
#if defined ( USE_STUB )
    SerialSocket    *m_sock1;
    SerialSocket    *m_sock2;

    INT             m_signal1;
    INT             m_signal2;
#else
    fd_set_t    m_read_fdset;
    fd_set_t    m_write_fdset;
    INT         m_selectid;
#endif
};


class SerialIoAdapter
{
public:
    friend SerialSocket;
    friend SerialIoSet;

    // Error structures
    enum ErrorCode
    {
        c_sio_err_none          =   SIO_ERR_NONE,
        c_sio_err_acces         =   SIO_ERR_ACCES,           /* 1   Permission denied. */
        c_sio_err_addrnnotvail  =   SIO_ERR_ADDRNOTAVAIL,    /* 2   Cannot assign requested address. */
        c_sio_err_afnosupport   =   SIO_ERR_AFNOSUPPORT,     /* 3   Address family not supported by protocol */
        c_sio_err_again         =   SIO_ERR_AGAIN,           /* 4   Try again. */
        c_sio_err__already      =   SIO_ERR_ALREADY,         /* 5   Operation already in progress. */
        c_sio_err_badf          =   SIO_ERR_BADF,            /* 6   Invalid file descriptor. */
        c_sio_err_busy          =   SIO_ERR_BUSY,            /* 7   Device or resource busy. */
        c_sio_err_connrefused   =   SIO_ERR_CONNREFUSED,     /* 8   Connection refused. */
        c_sio_err_fault         =   SIO_ERR_FAULT,           /* 9   Bad address. */
        c_sio_err_inprogress    =   SIO_ERR_INPROGRESS,      /* 10  Operation now in progress. */
        c_sio_err_inval         =   SIO_ERR_INVAL,           /* 11  Invalid argument. */
        c_sio_err_nametoolong   =   SIO_ERR_NAMETOOLONG,     /* 12  File name too long. */
        c_sio_err_nfile         =   SIO_ERR_NFILE,           /* 13  File table overflow. */
        c_sio_err_noact         =   SIO_ERR_NOACT,           /* 14  No device action handler. */
        c_sio_err_nodev         =   SIO_ERR_NODEV,           /* 15  No such device. */
        c_sio_err_nomem         =   SIO_ERR_NOMEM,           /* 16  Out of memory. */
        c_sio_err_noopt         =   SIO_ERR_NOOPT,           /* 17  Option not implemented. */
        c_sio_err_noprotoopt    =   SIO_ERR_NOPROTOOPT,      /* 18  Protocol not available. */
        c_sio_err_nosubdev      =   SIO_ERR_NOSUBDEV,        /* 19  No such device sub structure. */
        c_sio_err_nosys         =   SIO_ERR_NOSYS,           /* 20  Function not implemented. */
        c_sio_err_notsock       =   SIO_ERR_NOTSOCK,         /* 21  Argument descriptor is not a socket. */
        c_sio_err_nscan         =   SIO_ERR_NSCAN,           /* 22  Scanner list overflow. */
        c_sio_err_opnotsupp     =   SIO_ERR_OPNOTSUPP,       /* 23  Operation not supported. */
        c_sio_err_protonosupport    =   SIO_ERR_PROTONOSUPPORT,  /* 24  Protocol not supported. */
        c_sio_err_sockstate     =   SIO_ERR_SOCKSTATE,       /* 25  The  socket is in the wrong state. */
        c_sio_err_timeout       =   SIO_ERR_TIMEDOUT,        /* 26  Connection timed out. */
        c_sio_err_max           =   SIO_ERR_MAX

    };

    struct SioErrorDesc
    {
        ErrorCode   c_sio_errno;     /* Number of last error. */
        ErrorCode   c_global_errno;  /* Number of last error. */
        CHAR        *file_name;     /* Location of the error. */
        LONG        line_no;       /* Location of the error. */
    };

    //maintain the order as present in Enum sock_pf_t in sio_sock.h
    enum SocketFamily
    {
        c_sock_pf_undef = 0,
        c_sock_pf_termio,           /* Modem terminal. */
        c_sock_pf_bt,               /* Bluetooth. */
        c_sock_pf_max               /* For now..  */
    };

#if defined ( USE_STUB )
    SerialIoAdapter ( SerialSocket *pSerialSocket );
#else
    SerialIoAdapter();
#endif

    ~SerialIoAdapter();

    INT Open (SocketFamily fam, INT protocol );

    INT Accept(SerialSocket& clientSock, SocketAddr& sock_addr);

    INT Bind(SocketAddr& sock_addr);

    INT Connect(SocketAddr& serv_addr);

    INT Close();

    INT GetErrorNumber(SioErrorDesc& errorinfo);

    INT IoCtl(INT requestcode, INT argument);

    INT Listen(INT backlog);

    INT OptGet(INT optname, void* optval, INT& optlen);

    INT OptSet(INT optname, void* optval, INT optlen);

    INT Read(void* buf, LONG length);

    INT Write(const void* buf, LONG count);

private:
    LONG m_sd;
    LONG m_fd;

#if defined (USE_STUB )
    SerialSocket *m_remote_socket;
    //BOOLEAN        bConnected;
    static BooleanCondition m_connected_cond;
#endif

};

#endif //SERIALIO_ADAPTER_H

