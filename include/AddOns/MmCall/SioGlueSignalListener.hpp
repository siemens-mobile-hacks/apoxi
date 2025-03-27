/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_SioGlueSignalListener_hpp)
#define Apoxi_SioGlueSignalListener_hpp

#include "SioGlueWrapper.hpp"

class SerialTerminal;

class SioGlueSignalListener 
{
public:
    SioGlueSignalListener();

    virtual ~SioGlueSignalListener();

    void Init(SerialTerminal* terminal) {
        m_terminal = terminal;
    }

    void OnSignalChange(SioGlueWrapper::SignalType type, void* signal_parameter, void* user_parameter);

    static void sio_glue_handler (glue_sig_t sig_code, void *sig_param, void *user_param);

private:
    SerialTerminal *m_terminal;

};
#endif /* Apoxi_SioGlueSignalListener_hpp */

