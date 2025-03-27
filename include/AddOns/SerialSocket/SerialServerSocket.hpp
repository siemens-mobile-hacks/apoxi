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
**    File name: SerialServerSocket.h
**    Version: 
**    Date: 2005-08-31    14:48:26
**                                                  
** ============================================================================
**
** Project:     VenusU
** Block:       SerialServerSocket
** Process:     
** File name:   SerialServerSocket.h
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

#ifndef SERIAL_SERVERSOCKET_H
#define SERIAL_SERVERSOCKET_H

#include "SerialSocket.hpp"
#include "SockAddress.hpp"

class SerialServerSocket : public SerialSocket
{
    typedef SerialSocket Base;
public:
    SerialServerSocket();
    virtual ~SerialServerSocket();

    INT Accept(SerialSocket& clientSock, SocketAddr& addr);

    INT Bind(SocketAddr& serv_addr);

    INT Listen(INT backlog);

protected:
//  SerialSocketData *m_sd;
};


#endif //SERIAL_SERVERSOCKET_H

