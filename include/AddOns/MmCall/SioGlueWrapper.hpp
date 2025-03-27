/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SioGlueWrapper_hpp)
#define Apoxi_SioGlueWrapper_hpp

#include <stack/extensions.h>

//forward definition to avoid cyclic includes
class SioGlueSignalListener;

class SioGlueWrapper 
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
        friend class SioGlueWrapper;

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

            friend SioGlueWrapper;

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

    static Result RegisterSignalListener(const SioCommId &comm_id, SioGlueSignalListener &listener);

    static Result UnRegisterSignalListener(const SioCommId &comm_id, const SioGlueSignalListener &listener);

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

    SioGlueWrapper();

    ~SioGlueWrapper();
};

#endif /* Apoxi_SioGlueWrapper_hpp */

