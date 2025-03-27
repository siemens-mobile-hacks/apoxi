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
**    File name: SerialSocket.h
**    Version: 
**    Date: 2005-08-31    14:48:26
**                                                  
** ============================================================================
**
** Project:     VenusU
** Block:       SerialSocket Layer
** Process:     
** File name:   SerialSocket.h
**
** ============================================================================
**
**
** ============================================================================
** History:
**
** Date       Author  Comment
** ----------------------------------------------------------------------------
**
** 26.07.04   ges     created.
** ============================================================================
*/

#ifndef SERIAL_SOCK_H
#define SERIAL_SOCK_H

#include "SerialIoAdapter.hpp"
//class SerialIoAdapter;

// #define  DEBUG_SERIAL_SOCKET

#if defined ( DEBUG_SERIAL_SOCKET )
#define DEBUG( __X__ ) printf __X__
#else
#define DEBUG( __X__ )  ;
#endif  /* DEBUG_SERIAL_SOCKET ) */

class SerialSocket : public Socket
{
    typedef Socket Base;
    friend class SerialIoAdapter;
    friend class SerialIoSet;

public:
    SerialSocket();
    virtual ~SerialSocket();

    void OnControlMsg(const SocketControlMsg &msg);

    BOOLEAN Open ( SerialIoAdapter::SocketFamily fam, INT protocol );


    //Functions implemented for the base class Socket
    virtual BOOLEAN IsOpen() const;

    virtual BOOLEAN Close();

    virtual BOOLEAN IsBlocking() const;

    virtual BOOLEAN SetBlocking(BOOLEAN block = FALSE);

    virtual INT Read(void *buf, INT buflen);

    virtual INT Write(const void *buf, INT buflen);

    // todo: comments
    INT IoCtl(INT requestcode, INT argument);

    INT OptGet(INT optname, void* optval, INT& optlen);

    INT OptSet(INT optname, const void* optval, INT optlen);

protected:
    SerialSocketData *m_sd;
    SerialIoAdapter m_serialio; 

};

#endif //SERIAL_SOCK_H

