/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_IrdaTransport_hpp)
#define Apoxi_IrdaTransport_hpp

#include <stack/extensions.h>

#include <Devices/AbstractTransport.hpp>

class IrdaTransport : public AbstractTransport {

    public:

        typedef AbstractTransport Base;

        enum IrdaSwitchOffTimeout {
            default_irda_switch_off_timeout = 600000, // = 10 minutes, default IrDA Hardware switch off time-out when idle
        };

        enum ConnType
        {
            IrLap,  // do we have a connection?
            IrLmp,  // do we have open IrLmp connections?
            IrComm, // do we have open IrComm connections?
            IrObex  // do we have open IrObex connections?
        };
        
        enum TransportDisableReason
        {
            TransportDisableReasonNotApplicable,
            TransportDisableReasonIdleTimeout,
            TransportDisableReasonStackError,
            TransportDisableReasonAppRequest,
            TransportDisableReasonUnknown
        };

        IrdaTransport();

        ~IrdaTransport();

        static inline IrdaTransport & GetInstance() { return m_transport; }

        void SetNickname(UINT8 char_set, const CHAR *nickname) const;

        void SetHintBits(UINT byte_offset, UINT8 bit_mask) const;

        void ClearHintBits(UINT byte_offset, UINT8 bit_mask) const;

        virtual void Enable();

        void Disable();

        virtual AvState GetAvState() const;
        
        TransportDisableReason  GetTransportDisableReason() const;

        void                    OnAvStateChanged();

        BOOLEAN GetConnState(ConnType type) const;

        void SetIrdaHwTimeout(UINT32 irda_hw_timeout) ;
        
        inline BOOLEAN  GetIsWin98Mode() const { return m_is_win98_mode; }
        inline void     SetIsWin98Mode(BOOLEAN is_win98_mode)  { m_is_win98_mode = is_win98_mode; }


    private:

        static void irda_hw_cb(int state);
        static void irda_idle_state_cb(int state);
        static void irda_obex_state_cb(int state);
        static void irda_ircomm_state_cb(int state);
        static void irda_peer_cb(unsigned char *buf, int len);

        static SystemTimer m_irda_switch_off_timer;
        static UINT32 m_irda_switch_off_timeout;
        static void OnIrdaSwitchOffTimer(void* arg);

        static IrdaTransport        m_transport;
        AvState                     m_state;
        TransportDisableReason      m_transport_disable_reason;
        BOOLEAN                     m_is_win98_mode;
};


#endif  // Apoxi_IrdaTransport_hpp

