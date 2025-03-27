/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MmCallSerialTerminalListener_hpp)
#define Apoxi_MmCallSerialTerminalListener_hpp

#include <AddOns/MmCall/SerialTerminalListener.hpp>

class MmCallSerialTerminalListener : public SerialTerminalListener 
{
public:
    typedef SerialTerminalListener Base;

    MmCallSerialTerminalListener();

    virtual ~MmCallSerialTerminalListener();
    
    virtual void OnTerminalEvent(SerialTerminal& terminal, SerialTerminal::Event event);
    
};
#endif /* Apoxi_MmCallSerialTerminalListener_hpp */

