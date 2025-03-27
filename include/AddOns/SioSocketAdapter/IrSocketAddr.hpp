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
**    File name: IrSocketAddr.hpp
**    Version:
**    Date: 2005-12-22    14:48:26
**
** ============================================================================
**
** Project:     VenusU
** Block:       IrSocketAddr
** Process:
** File name:   IrSocketAddr.hpp
**
** ============================================================================
**
**
** ============================================================================
** History:
**
** Date        Author               Comment
** ----------------------------------------------------------------------------
**
** 2005-12-22  schwenke             created.
** ============================================================================
*/

#ifndef SERIAL_IRSOCKADDRESS_H
#define SERIAL_IRSOCKADDRESS_H

#include <AddOns/SerialSocket/SockAddress.hpp>
//#include <Bluetooth/BtDeviceAddress.hpp>

//enum BtProtocol
//{
//    c_bt_protocol_l2cap,
//    c_bt_protocol_rfcomm
//};

/*
typedef UINT32 IrDeviceAddress; // from \3p_irda_esi\inc\irlmpttp.h  //IrDeviceAddr


typedef struct sock_ir_socket_s //analog zu \ms-bt-src\src\bt-ctrl\sio_sockbt.h  sock_bt_rfcomm_t
{
    sock_family_t       family;    // = BT 
    sock_ir_protocol_t  protocol;  //enum // = L2CAP, RFCOMM 
    
    IrDeviceAddress      bdAddr;
    btapi_u8_t          server_channel;
    
} sock_ir_socket_t;
*/

/*
#ifndef (SIO_SOCK_HEAD)

typedef unsigned short sock_family_t;
typedef unsigned int sock_protocol_t;

//#define SIO_SOCK_HEAD \
//    sock_family_t    family; \
//    sock_protocol_t  protocol; \
//  long             fd;



typedef struct sock_termio_s
{
//    SIO_SOCK_HEAD
    sock_family_t    family; 
    sock_protocol_t  protocol; 
    long             fd;
        
    struct
    {
        CHAR  serv_addr[SIO_MAX_DEVICENAME_LENGTH + 1];
        CHAR  dev_addr[SIO_MAX_DEVICENAME_LENGTH + 1];
        
    } sa;
    
    long  *at_fd;  // AT default device descriptor. 
    
}  sock_termio_t;

#endif
*/
//Socket IR address
class IrSocketAddr : public SocketAddr
{
public:
    IrSocketAddr(BOOLEAN is_server);
//  IrSocketAddr(sock_termio_t& addr, UINT8 serverchannel);
    virtual ~IrSocketAddr();
    void* GetSockAddr();
    INT32 GetSockAddrSize();

//    void GetDeviceAddress(IrDeviceAddress &irDevAddr);

//  unsigned char GetServerChannel();

private:
    void* m_irSockAddr; // sock_termio_t
    INT32 m_AddrSize;
};

#endif //SERIAL_IRSOCKADDRESS_H

