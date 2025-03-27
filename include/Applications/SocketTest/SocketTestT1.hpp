/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestT1_hpp)
#define ApoxiApp_SocketTestT1_hpp

#include <SocketTest/SocketTestT.hpp>

class TcpSocket;
class UdpSocket;

class SocketTestT1 : public SocketTestT
{
public:
    SocketTestT1() { }
    virtual ~SocketTestT1() { }

    virtual internalStatus  TestA(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestB(internalStatus instatus, INT &ErrorCode); 

private:
    internalStatus CloseTcpSocket(TcpSocket **socket, INT &ErrorCode);
    internalStatus OpenTcpSocket(TcpSocket **socket, INT &ErrorCode);
    internalStatus CloseUdpSocket(UdpSocket **socket, INT &ErrorCode);
    internalStatus OpenUdpSocket(UdpSocket **socket, INT &ErrorCode);
};

#endif // ApoxiApp_SocketTestT1_hpp
