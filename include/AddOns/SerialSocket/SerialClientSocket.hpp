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
**    File name: SerialClientSocket.h
**    Version: 
**    Date: 2005-08-31    14:48:26
**                                                  
** ============================================================================
**
** Project:     VenusU
** Block:       SerialClientSocket
** Process:     
** File name:   SerialClientSocket.h
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

#ifndef SERIAL_CLIENTSOCKET_H
#define SERIAL_CLIENTSOCKET_H

#include "SerialSocket.hpp"
#include "SockAddress.hpp"

class SerialServerSocket;

class SerialClientSocket : public SerialSocket
{
    typedef SerialSocket Base;
public:
    SerialClientSocket();
    virtual ~SerialClientSocket();

    INT Bind(SocketAddr& sock_addr);

    INT Connect(SocketAddr& serv_addr);

protected:
//  SerialSocketData *m_sd;

friend SerialServerSocket;
};


#endif //SERIAL_CLIENTSOCKET_H

