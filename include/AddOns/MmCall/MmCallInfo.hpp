/*  ------------------------------------------------------------------------
    Copyright (C) 2005 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_MmCallInfo_hpp)
#define Apoxi_MmCallInfo_hpp

#include <Asc/Types.hpp>
#include "SerialTerminalSocket.hpp"
#include "SerialTerminal.hpp"

class MmCallInfo {
    public:
        enum CallState {
            InSetup,
            InAccept,
            InReject,
            InRelease,
            InCall,
            Closed
        };

        enum CallDirection {
            MobileOriginatedCall,
            MobileTerminatedCall,
            NoCall
        };

        MmCallInfo();
        
        ~MmCallInfo();
        
        void Invalidate();
        
        void SetCallIndex(CallIndex call_index) {m_call_index = call_index;};
        
        CallIndex GetCallIndex() const  {return m_call_index;};
        
        void SetCallId(INT8 call_id) {m_call_id = call_id;};
        
        INT8 GetCallId() const  {return m_call_id;};
        
        void SetCallDirection(CallDirection call_dir) { m_calldir = call_dir; };
        
        CallDirection GetCallDirection() const { return m_calldir; };

        void SetCallState(CallState state) { m_call_state = state; };

        CallState GetCallState() const { return m_call_state; };

        void SetOnlineMode(BOOLEAN in_online_mode) { m_online_mode = in_online_mode; };
        
        BOOLEAN IsInOnlineMode() const {return m_online_mode;};
        
        SerialTerminalSocket* GetSocket() { return &m_data_socket; };
        
        SerialTerminal* GetDataTerminal() const { return m_data_terminal;};

    private:

        void InitMmCallInfo();

        CallIndex               m_call_index;
        INT8                    m_call_id;
        SerialTerminalSocket    m_data_socket;
        SerialTerminal *        m_data_terminal;
        BOOLEAN                 m_online_mode;
        CallDirection           m_calldir;
        CallState               m_call_state;
    
};

#endif

