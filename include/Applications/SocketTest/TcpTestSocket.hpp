/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_TcpTestSocket_hpp)
#define ApoxiApp_TcpTestSocket_hpp

#include <Socket/TcpSocket.hpp>

class TcpTestSocket : public TcpSocket
{
public:
    TcpTestSocket(BOOLEAN send_continue_msg = TRUE);
    virtual ~TcpTestSocket();

    void CollectPackets(INT testid, INT nr_of_packets, INT messageSize); 
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
    CHAR* m_nMessageBody; // Temporary buffer for current message.
    INT m_nMessagePos;    // Temporary input counter.
};

#endif // ApoxiApp_TcpTestSocket_hpp
