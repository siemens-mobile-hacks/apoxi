/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexServerPort_hpp)
#define Apoxi_ObexServerPort_hpp

#include <Obex/ObexAbstractPort.hpp>

//  Forward declaration of classes.
class ObexServerDispatcher;

class ObexServerPort : public ObexAbstractPort {

    public:
        typedef ObexAbstractPort    Base;

        ObexServerPort(ObexAbstractTransport &  transport,
                       ObexProtocol &           protocol,
                       ObexServerDispatcher &   server);

        inline  BOOLEAN     IsListening() const;

        void                Reset();

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
        // Initial state and state after port has been closed again.
        FSM_DECLARE_STATE(s1_initially);

        // Port is waiting for availability state to become 'AvsReady'
        FSM_DECLARE_STATE(s1_wait_avs);

        // Port is detaching from transport (procedure running)
        FSM_DECLARE_STATE(s1_detaching);

        // Port is attaching to transport (procedure running)
        FSM_DECLARE_STATE(s1_attaching);

        // Port is listening to incoming connections.
        FSM_DECLARE_STATE(s1_listening);

        ObexServerDispatcher &      m_server;
};

BOOLEAN     ObexServerPort::IsListening()
const
{
    return  IsInState( FSM_STATE_FROM_NAME(s1_listening) );
}

#endif  // Apoxi_ObexServerPort_hpp

