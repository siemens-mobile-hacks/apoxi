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
**    File name: BtSocketAddr.hpp
**    Version:
**    Date: 2005-10-24    14:48:26
**
** ============================================================================
**
** Project:     VenusU
** Block:       BtSocketAddr
** Process:
** File name:   BtSocketAddr.hpp
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

#ifndef SERIAL_BTSOCKADDRESS_H
#define SERIAL_BTSOCKADDRESS_H

#include <AddOns/SerialSocket/SockAddress.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>

// for requesting TX and RX MTU size
#define L2CA_TXMTU_SET      0x4000
#define L2CA_RXMTU_SET      0x4002

// for getting the negotiated TX and RX MTU size
#define L2CA_TXMTU_GET      0x4001
#define L2CA_RXMTU_GET      0x4003

enum BtProtocol
{
    c_bt_protocol_l2cap,
    c_bt_protocol_rfcomm
};

//Socket RFCOMM address
class RfcommSocketAddr : public SocketAddr
{
public:
    RfcommSocketAddr();
    RfcommSocketAddr(BtDeviceAddress& addr, UINT8 serverchannel);
    ~RfcommSocketAddr();
    void* GetSockAddr();
    INT32 GetSockAddrSize();

    void GetDeviceAddress(BtDeviceAddress& btDevAddr);

    unsigned char GetServerChannel();

private:
    void*      m_rfcommSockAddr;
    INT32   m_AddrSize;
};

//Socket L2CAP address
class L2CapSocketAddr : public SocketAddr
{
public:
    L2CapSocketAddr();
    L2CapSocketAddr(BtDeviceAddress& addr, UINT16 muxchan);
    void* GetSockAddr();
    INT32 GetSockAddrSize();

    ~L2CapSocketAddr();

    void GetDeviceAddress(BtDeviceAddress& btDevAddr);

    unsigned short GetPsm();

private:
    void*   m_l2CapSockaddr;
    INT32   m_AddrSize;

};

#endif //SERIAL_BTSOCKADDRESS_H

