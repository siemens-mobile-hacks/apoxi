/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestT2_hpp)
#define ApoxiApp_SocketTestT2_hpp

#include <SocketTest/SocketTestT.hpp>

class InetSocketAddr;
class SysSocket;

class SocketTestT2 : public SocketTestT
{
public:
    SocketTestT2();
    virtual ~SocketTestT2();

    virtual internalStatus  TestA(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus TestB(internalStatus instatus, INT &ErrorCode); 

    void CleanUdpSocket(INT &ErrorCode, SocketTestMessage *&pMessage);

    INT ClientSend(const void *buf, INT buflen);
    INT ServerRead(void *buf, INT buflen, SysSocket *aSocket);

    void CleanTcpSocket(INT &ErrorCode, SysSocket *aSocket, SocketTestMessage *&pMessage);

private:
    SysSocket *m_pUdpSocket;
    SysSocket *m_pTcpServer;
    SysSocket *m_pTcpClient;
};

#endif // ApoxiApp_SocketTestT2_hpp
