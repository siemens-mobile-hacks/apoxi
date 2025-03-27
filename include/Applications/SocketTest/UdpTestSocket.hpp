/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_UdpTestSocket_hpp)
#define ApoxiApp_UdpTestSocket_hpp

#include <Socket/UdpSocket.hpp>
#include <Socket/InetSocketAddr.hpp>

class UdpTestSocket : public UdpSocket
{
public:
    UdpTestSocket(BOOLEAN send_continue_msg = TRUE);
    virtual ~UdpTestSocket();

    void CollectPackets(int testid, int nr_of_packets); 
    UINT32 GetReceivedPackets() { return m_nPacketsReceived; } 

    enum _constants { m_nHeaderSize = 32 }; 

protected:
    virtual void OnAsyncEvent(Event event);

    UINT32 m_nWaitingForPackets; 
    BOOLEAN *m_nPacketsCollected; 
    UINT32 m_nPacketsReceived; 

    const BOOLEAN m_send_continue_msg;
    INT m_nTestID;
    INT m_nMessageSize;

    Ticks m_ticks;

    InetSocketAddr m_addressOut;
};

#endif // ApoxiApp_UdpTestSocket_hpp
