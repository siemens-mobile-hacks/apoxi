/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SerialTerminal_hpp)
#define Apoxi_SerialTerminal_hpp

#include <AddOns/MmCall/SioGlueWrapper.hpp>
#include <AddOns/MmCall/SioGlueSignalListener.hpp>

class Socket;
class SerialTerminalListener;

const INT c_max_serial_terminals = 3;

class SerialTerminal 
{
public:

    enum Event {
        DataAvailable,
        DataSent
    };

    enum Result {
        Ok,
        Error,
        NotConnected
    };

    enum Parity
    {
        ParityNone = SioGlueWrapper::ParityNone,
        ParityOdd  = SioGlueWrapper::ParityOdd,
        ParityEven = SioGlueWrapper::ParityEvent,
        ParityMark = SioGlueWrapper::ParityMark,
        ParitySpace = SioGlueWrapper::ParitySpace
    };

    friend class SioGlueSignalListener;

    virtual ~SerialTerminal();

    Result Connect(const String &connect_string, UINT32 speed, UINT8 stop_bits, UINT8 data_bits, Parity parity);

    Result Disconnect();
    
    BOOLEAN IsConnected() const { return m_connected; };

    Result Read(void* buffer, UINT16 buffer_size, UINT16& bytes_read);

    Result Write(const void* buffer, UINT16 buffer_size, UINT16& bytes_written);


    Result SetAtMode(BOOLEAN enable);
    
    Result GetConnectionParameters(UINT32* speed, UINT8* stop_bits, UINT8* data_bits, Parity* parity) const;

    static SerialTerminal* GetFreeSerialTerminal();

    static void ReleaseSerialTerminal(SerialTerminal* terminal) {
        terminal->Release();
        terminal->m_is_in_use = FALSE;
    }
    
    void SetListener(SerialTerminalListener* listener);

protected: 
    void OnSignalChange(SioGlueWrapper::SignalType type, void* signal_parameter, void* user_parameter);

    BOOLEAN m_is_in_use;
private:
    
    SerialTerminal(const String &device);

    BOOLEAN Init();
    
    BOOLEAN Release();

    //must accord to the sio.config!
    static SerialTerminal m_terminals[c_max_serial_terminals];

    const String m_device;

    SioGlueWrapper::SioCommId m_commId;
    
    SioGlueSignalListener m_sio_signal_listener;

    BOOLEAN m_connected;
    
    SerialTerminalListener* m_event_listener;
    
    SioGlueWrapper::TermIos  m_term_ios;
};
#endif /* Apoxi_SerialTerminal_hpp */

