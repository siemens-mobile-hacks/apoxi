/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SerialTerminalListener_hpp)
#define Apoxi_SerialTerminalListener_hpp


#include "SerialTerminal.hpp"


class SerialTerminalListener 
{
public:
    SerialTerminalListener();
    virtual ~SerialTerminalListener();
    virtual void OnTerminalEvent(SerialTerminal& terminal, SerialTerminal::Event event) = 0;

};
#endif /* Apoxi_SerialTerminalListener_hpp */

