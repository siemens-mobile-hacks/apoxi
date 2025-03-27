/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestT4_hpp)
#define ApoxiApp_SocketTestT4_hpp

#include <SocketTest/SocketTestT.hpp>
#include <Socket/SocketTypes.hpp>

class TcpTestSocket;
class TcpServerTestSocket;

class SocketTestT4 : public SocketTestT
{
public:
    SocketTestT4();

    virtual ~SocketTestT4();

    virtual internalStatus  TestA(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestB(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestC(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestD(internalStatus instatus, INT &ErrorCode); 
    virtual void FinishGroup();

protected:
    UINT32 m_nNumberOfPackets;
    UINT m_nNumberOfSockets;
    DataConnProfileId m_profileId;

protected:
    internalStatus  TestBCD(internalStatus instatus, INT &ErrorCode);
    internalStatus  TestAA(internalStatus instatus, INT &ErrorCode);
    void SendFinalReport(DataConnProfileId profileId);

    TcpTestSocket *m_pTcpOutSocket;
    TcpServerTestSocket *m_pTcpServerSocket;
    TcpTestSocket *m_pTcpInSocket;
    SocketTestMessage *m_pMessage;
    UINT32 m_nlenIn;
    UINT m_nStartNumber;

    INT m_nCurrentSocket;
    TcpTestSocket *m_ppTcpSocket[15];
    INT m_nWaitingForSockets;
    TcpTestSocket *m_pTcpReportSocket;
};

#endif // ApoxiApp_SocketTestT4_hpp
