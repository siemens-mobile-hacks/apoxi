/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SocketSerialTerminalListener_hpp)
#define Apoxi_SocketSerialTerminalListener_hpp


#include "SerialTerminalListener.hpp"

class SerialTerminalSocket;
class ExecutionContext;

class SocketSerialTerminalListener : public SerialTerminalListener 
{
public:
    typedef SerialTerminalListener Base;

    SocketSerialTerminalListener(SerialTerminalSocket& socket);

    virtual ~SocketSerialTerminalListener();

    virtual void OnTerminalEvent(SerialTerminal& terminal, SerialTerminal::Event event);

    void SetSocketExecutionContext(ExecutionContext* context) {m_socket_execution_context = context;};

    void SetActive(BOOLEAN active) { m_active = active; };

private: 
    SerialTerminalSocket& m_socket;
    
    ExecutionContext* m_socket_execution_context;

    BOOLEAN m_active;

};
#endif /* Apoxi_SocketSerialTerminalListener_hpp */

