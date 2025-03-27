/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexClientPort_hpp)
#define Apoxi_ObexClientPort_hpp

#include <Obex/ObexAbstractPort.hpp>

//  Forward declaration of classes
class ObexClientDispatcher;

class ObexClientPort : public ObexAbstractPort {

    public:
        typedef ObexAbstractPort    Base;

        ObexClientPort(ObexAbstractTransport &  transport,
                       ObexProtocol &           protocol,
                       ObexClientDispatcher &   client);

        inline  BOOLEAN     IsConnected() const;

    protected:
        virtual void        StartAddrResolution();
        virtual void        AbortAddrResolution();

        virtual BOOLEAN     AcquireChannel(ObexChannel &        channel,
                                           const ObexAddrPtr &  addr_ptr,
                                           ObexResult           result);

        virtual void        OpenChannel(const ObexAddrPtr &     addr_ptr);
        virtual void        CloseChannel(ObexResult cause);

        virtual void        OnChannelClosed();
        virtual void        OnChannelOpened(ObexResult  result);

    private:
        EventType   EnableAction(FsmEngine &, EventType, ObjectObtainer &);

        // Initial state and state after port has been closed again.
        FSM_DECLARE_STATE(s1_initially);

        // Port is waiting for availability state to become 'AvsReady'
        FSM_DECLARE_STATE(s1_wait_avs);

        // Port is detaching from transport (procedure running)
        FSM_DECLARE_STATE(s1_detaching);

        // Port is attaching to transport (procedure running)
        FSM_DECLARE_STATE(s1_attaching);

        // Port is connected to a remote server.
        FSM_DECLARE_STATE(s1_connected);

        ObexClientDispatcher &      m_client;

        void                        EnableTransport();
};

/*  ----------------------------------------------------------------------
    IsConnected
    ---------------------------------------------------------------------- */
BOOLEAN     ObexClientPort::IsConnected()
const
{
    return  IsInState( FSM_STATE_FROM_NAME(s1_connected) );
}// IsConnected

#endif  // Apoxi_ObexClientPort_hpp

