/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ExternalPsdContextListener_hpp)
#define Apoxi_ExternalPsdContextListener_hpp

#include <stack/extensions.h>

/***************************************************************************/
/* - !!! - INTERNAL CLASSES - SUBJECT TO CHANGE - MUST NOT BE USED - !!! - */
/***************************************************************************/

// Forward definition to avoid cyclic includes
class Socket;
class ExtPsdContextListener_SioGlueSignalListener;
class ExtPsdContextListener_SerialTerminal;
class ExtPsdContextListener_SerialTerminalListener;

class ExtPsdContextListener_SioGlueWrapper
{
public:

    enum Result {
        SioOk = SIO_STAT_OK,          
        SioError = SIO_STAT_ERROR,       
        SioEnoughBuffer = SIO_STAT_WATER_HIGH,  
        SioBufferLow = SIO_STAT_WATER_LOW,   
        SioAtBusy = SIO_STAT_AT_BUSY,     
        SioAtComplete = SIO_STAT_AT_COMPL   
    };


    enum LineState
    {
        SioLineOff = SIO_LINE_OFF,   
        SioLineOn = SIO_LINE_ON,        
        SioLineDontCare = SIO_LINE_ON+1
        
    };


    enum Parity
    {
        ParityNone = SIO_PARITY_NONE,
        ParityOdd = SIO_PARITY_ODD,
        ParityEvent = SIO_PARITY_EVEN,
        ParityMark = SIO_PARITY_MARK,
        ParitySpace = SIO_PARITY_SPACE
    };

    enum SignalType
    {
        SioDataReq = GLUE_SIG_DATAREQ,   
        SioTermIos = GLUE_SIG_TERMIOS,   
        SioExecMode = GLUE_SIG_EXECMODE,  
        SioClose = GLUE_SIG_CLOSE,     
        SioOpen = GLUE_SIG_OPEN,      
        
        SioLast = GLUE_SIG_LAST 
    };

    enum SignalStartStop
    {
        SioExecModeStart = GLUE_EXECMODE_START,  
        SioExecModeKill = GLUE_EXECMODE_KILL,   
        
        SioSigvalLast = GLUE_SIGVAL_LAST
        
    };

    struct SioCommId {
        friend class ExtPsdContextListener_SioGlueWrapper;

        private:
            glue_fd_t  m_fd;
    };

    struct TermIos {

        public:

            TermIos();
            
            TermIos(sio_termios_t* sio_termios);

            ~TermIos();

            LineState GetDtr() const { return static_cast<LineState>(m_termios.dtr); }

            LineState GetRts() const { return static_cast<LineState>(m_termios.rts); }

            LineState GetDsr() const { return static_cast<LineState>(m_termios.dsr); }

            void SetDsr(LineState state) { m_termios.dsr = (sio_line_t)state; }

            LineState GetCts() const { return static_cast<LineState>(m_termios.cts); }

            void SetCts(LineState state) { m_termios.cts = (sio_line_t)state; }

            LineState GetDcd() const { return static_cast<LineState>(m_termios.dcd); }

            void SetDcd(LineState state) { m_termios.dcd = (sio_line_t)state; }

            LineState GetRi() const { return static_cast<LineState>(m_termios.ri); }

            void SetRi(LineState state) { m_termios.ri = (sio_line_t)state; }

            UINT32 GetSpeed() const { return m_termios.speed; }
            
            void SetSpeed(UINT32 speed) { m_termios.speed = speed; }

            UINT8 GetStopBits() const { return m_termios.stop_bits; }

            void SetStopBits(UINT8 stop_bits) { m_termios.stop_bits = stop_bits; }

            Parity GetParity() const { return static_cast<Parity>(m_termios.parity); }

            void SetParity(Parity parity) { m_termios.parity = (sio_parity_t)parity; }
            
            UINT8 GetDataBits() const { return m_termios.data_bits; }

            void SetDataBits(UINT8 data_bits) { m_termios.data_bits = data_bits; }

            friend ExtPsdContextListener_SioGlueWrapper;

        private:
            sio_termios_t m_termios;

    };

    static Result Close(const SioCommId &comm_id);


    static Result Open(const String &device_name, SioCommId& comm_id);

    //corresponding methods to functions and parameters of sio_glue
    //typedef enum
    //{
    //  GLUE_OPT_SIGACT,  --> RegisterHandler() / UnregisterHandler()
    //  GLUE_OPT_TERMIOS, --> GetStatus() / SetStatus()
    //  GLUE_OPT_WRVAL,   --> GetBufferSizes()
    //  GLUE_OPT_AT,      --> SetAtMode()
    //} glue_opt_t;

    static Result RegisterSignalListener(const SioCommId &comm_id, ExtPsdContextListener_SioGlueSignalListener &listener);

    static Result UnRegisterSignalListener(const SioCommId &comm_id, const ExtPsdContextListener_SioGlueSignalListener &listener);

    static Result SetAtMode(const SioCommId &comm_id, BOOLEAN at_mode);

    static Result GetAtMode(const SioCommId &comm_id, BOOLEAN &at_mode);

    static Result GetBufferSizes(const SioCommId &comm_id, UINT16 &free, UINT16 &size);

    static Result SetStatus(const SioCommId &comm_id, const TermIos& state);

    static Result GetStatus(const SioCommId &comm_id, TermIos& state);

    static Result ReadData  (const SioCommId &comm_id, void *buffer,
                        UINT16   size,
                        UINT16&  read);


    static Result WriteData  (const SioCommId &comm_id, const void *buffer,
                        UINT16   size,
                        UINT16&  written);

private:

    ExtPsdContextListener_SioGlueWrapper();

    ~ExtPsdContextListener_SioGlueWrapper();
};


class ExtPsdContextListener_SioGlueSignalListener 
{
public:
    ExtPsdContextListener_SioGlueSignalListener();

    virtual ~ExtPsdContextListener_SioGlueSignalListener();

    void Init(ExtPsdContextListener_SerialTerminal* terminal) {
        m_terminal = terminal;
    }

    void OnSignalChange(ExtPsdContextListener_SioGlueWrapper::SignalType type, void* signal_parameter, void* user_parameter);

    static void sio_glue_handler (glue_sig_t sig_code, void *sig_param, void *user_param);

private:
    ExtPsdContextListener_SerialTerminal *m_terminal;

};



const INT c_max_serial_terminals = 3;

class ExtPsdContextListener_SerialTerminal 
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
        ParityNone = ExtPsdContextListener_SioGlueWrapper::ParityNone,
        ParityOdd  = ExtPsdContextListener_SioGlueWrapper::ParityOdd,
        ParityEven = ExtPsdContextListener_SioGlueWrapper::ParityEvent,
        ParityMark = ExtPsdContextListener_SioGlueWrapper::ParityMark,
        ParitySpace = ExtPsdContextListener_SioGlueWrapper::ParitySpace
    };

    friend class ExtPsdContextListener_SioGlueSignalListener;

    virtual ~ExtPsdContextListener_SerialTerminal();

    Result Connect(const String &connect_string, UINT32 speed, UINT8 stop_bits, UINT8 data_bits, Parity parity);

    Result Disconnect();
    
    BOOLEAN IsConnected() const { return m_connected; };

    Result Read(void* buffer, UINT16 buffer_size, UINT16& bytes_read);

    Result Write(const void* buffer, UINT16 buffer_size, UINT16& bytes_written);


    Result SetAtMode(BOOLEAN enable);
    
    Result GetConnectionParameters(UINT32* speed, UINT8* stop_bits, UINT8* data_bits, Parity* parity) const;

    static ExtPsdContextListener_SerialTerminal* GetFreeSerialTerminal();

    static void ReleaseSerialTerminal(ExtPsdContextListener_SerialTerminal* terminal) {
        terminal->Release();
        terminal->m_is_in_use = FALSE;
    }
    
    void SetListener(ExtPsdContextListener_SerialTerminalListener* listener) {m_event_listener = listener;};

protected: 
    void OnSignalChange(ExtPsdContextListener_SioGlueWrapper::SignalType type, void* signal_parameter, void* user_parameter);

    BOOLEAN m_is_in_use;
private:
    
    ExtPsdContextListener_SerialTerminal(const String &device);

    BOOLEAN Init();
    
    BOOLEAN Release();

    //must accord to the sio.config!
    static ExtPsdContextListener_SerialTerminal m_terminals[c_max_serial_terminals];

    const String m_device;

    ExtPsdContextListener_SioGlueWrapper::SioCommId m_commId;
    
    ExtPsdContextListener_SioGlueSignalListener m_sio_signal_listener;

    BOOLEAN m_connected;
    
    ExtPsdContextListener_SerialTerminalListener* m_event_listener;
    
    ExtPsdContextListener_SioGlueWrapper::TermIos  m_term_ios;
};


class ExtPsdContextListener_SerialTerminalListener 
{
public:
    ExtPsdContextListener_SerialTerminalListener();
    virtual ~ExtPsdContextListener_SerialTerminalListener();
    virtual void OnTerminalEvent(ExtPsdContextListener_SerialTerminal& terminal, ExtPsdContextListener_SerialTerminal::Event event) = 0;

};


class ExtPsdContextListenerImpl_SerialTerminalListener : public ExtPsdContextListener_SerialTerminalListener 
{
public:
    typedef ExtPsdContextListener_SerialTerminalListener Base;

    ExtPsdContextListenerImpl_SerialTerminalListener();

    virtual ~ExtPsdContextListenerImpl_SerialTerminalListener();

    virtual void OnTerminalEvent(ExtPsdContextListener_SerialTerminal& terminal, ExtPsdContextListener_SerialTerminal::Event event);

    void TerminateExtPsdContext();

private:
    void OnDataAvailable(ExtPsdContextListener_SerialTerminal &terminal);

    void OnResponseReceived(String response);

    ExtPsdContextListener_SerialTerminal *m_terminal;
   
    UINT8 m_ext_pdp_ctx_id;
    BOOLEAN m_service_init;
    String m_data;
};

#endif /* Apoxi_ExternalPsdContextListener_hpp */

