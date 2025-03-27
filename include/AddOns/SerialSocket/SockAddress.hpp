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
**    File name: SockAddress.h
**    Version:
**    Date: 2005-10-24    14:48:26
**
** ============================================================================
**
** Project:     VenusU
** Block:       SockAddress
** Process:
** File name:   SockAddress.h
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

#ifndef SERIAL_SOCKADDRESS_H
#define SERIAL_SOCKADDRESS_H

//Socket address base class
//Each sock address types are derived from this class
class SocketAddr
{
public:
    SocketAddr(){}
    virtual void* GetSockAddr() = 0;
    virtual INT32 GetSockAddrSize() = 0;

    virtual ~SocketAddr(){}
private:
};

#endif //SERIAL_SOCKADDRESS_H

