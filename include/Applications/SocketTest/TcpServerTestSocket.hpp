/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiApp_TcpServerTestSocket_hpp)
#define ApoxiApp_TcpServerTestSocket_hpp

#include <Socket/TcpServerSocket.hpp>

class TcpServerTestSocket : public TcpServerSocket
{
public:
    TcpServerTestSocket();
    virtual ~TcpServerTestSocket();
    
protected:
        virtual void OnAsyncEvent(Event event);
};

#endif // ApoxiApp_TcpServerTestSocket_hpp
