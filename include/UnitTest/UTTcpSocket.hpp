/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(UTTcpSocket_hpp)
#define UTTcpSocket_hpp

#ifdef APOXI_UNITTEST
#ifdef APOXI_UNITTEST_TCPIP

#include <Socket/DataConnManager.hpp>
#include <Socket/TcpSocket.hpp>

class UTTcpSocket: public TcpSocket {
    typedef TcpSocket Base; 

    public:         
        UTTcpSocket() {};
        virtual ~UTTcpSocket() {};  

    public:
        virtual void OnAsyncEvent(Event event);
        
};//class UTTcpSocket


#endif //APOXI_UNITTEST_TCPIP
#endif //APOXI_UNITTEST
#endif //UTTcpSocket_hpp


