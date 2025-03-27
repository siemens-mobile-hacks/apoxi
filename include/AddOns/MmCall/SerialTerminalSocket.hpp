/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SerialTerminalSocket_hpp)
#define Apoxi_SerialTerminalSocket_hpp

#include <Asc/Types.hpp>
#include <Socket/Socket.hpp>
#include <Auxiliary/PhoneNumber.hpp>

#include <AddOns/MmCall/SerialTerminal.hpp>
#include <AddOns/MmCall/SocketSerialTerminalListener.hpp>

class SerialTerminalSocket : public Socket 
{
public:
    typedef Socket Base;
    
    SerialTerminalSocket();

    virtual ~SerialTerminalSocket();
    
    virtual INT Read(void *buf, INT buflen);

    virtual INT Write(const void *buf, INT buflen);

    virtual void SetSocketEventListener(SocketEventListener* listener);
    
    virtual BOOLEAN Open(void);
    
    virtual BOOLEAN IsOpen(void) const;
    
    virtual BOOLEAN Close();
    
    virtual BOOLEAN IsBlocking() const;
    
    virtual BOOLEAN SetBlocking(BOOLEAN block = 0);
    
    void SetTerminal(SerialTerminal* terminal);

protected:
    SerialTerminal* GetTerminal() const { return m_terminal;};  

private:

    ExecutionContext *m_execution_context;
    
    SerialTerminal *m_terminal;

    SocketSerialTerminalListener m_terminal_listener;
};
#endif /* Apoxi_SerialTerminalSocket_hpp */

