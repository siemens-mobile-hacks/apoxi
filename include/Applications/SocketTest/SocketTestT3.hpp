/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_SocketTestT3_hpp)
#define ApoxiApp_SocketTestT3_hpp

#include <SocketTest/SocketTestT.hpp>
#include <Socket/SocketTypes.hpp>
#include <Socket/InetSocketAddr.hpp>

class UdpTestSocket;

class SocketTestT3 : public SocketTestT
{
public:
    SocketTestT3();

    virtual ~SocketTestT3();

    virtual internalStatus  TestA(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestB(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestC(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestD(internalStatus instatus, INT &ErrorCode); 
    virtual internalStatus  TestE(internalStatus instatus, INT &ErrorCode); 
    virtual void FinishGroup();

    DownloadSettings m_PsdDownloadSettings;

protected:
    internalStatus  TestABCD(internalStatus instatus, INT &ErrorCode, BOOLEAN selfTest=FALSE, BOOLEAN download=FALSE);
    UINT32 m_nNumberOfPackets;
    UINT m_nNumberOfSockets;
    DataConnProfileId m_profileId;
    void SendFinalReport(DataConnProfileId profileId);

private:
    SocketTestMessage *m_pMessage;
    UINT32 m_nlenIn;
    UINT32 m_nFrequency;
    InetSocketAddr m_addressOut;

    INT m_nCurrentSocket;
    UdpTestSocket *m_ppUdpSocket[15];
    INT m_nWaitingForSockets;
    UdpTestSocket *m_pUdpReportSocket;
};

#endif // ApoxiApp_SocketTestT3_hpp
