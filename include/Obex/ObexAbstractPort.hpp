/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexAbstractPort_hpp)
#define Apoxi_ObexAbstractPort_hpp

#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexAddress.hpp>
#include <Obex/ObexChannel.hpp>
#include <Obex/ObexOperationId.hpp>
#include <Obex/ObexMessages.hpp>
#include <Obex/FsmEngine.hpp>

//  Forward declarations of classes.
class ObexAbstractTransport;
class ObexProtocol;


class ObexAbstractPort : public FsmEngine::Actor {
    friend class FsmEngine;
    public:
        virtual ~ObexAbstractPort();

        inline  const ObexChannel &     GetChannel() const;

        inline  BOOLEAN                 IsBoundTo(const ObexChannel &  ch) const;

        inline  ObexProtocol &          GetProtocol();

        void                            Open();

        void                            Close();

        void                            CheckTransportAvailable();

        BOOLEAN                         AcceptsMessage(const ObexMsg &      msg);

        BOOLEAN                         AcceptsMessage(const ObexAddrMsg &  msg);

        enum EventType {
            FSM_INTERNAL_EVENTS,

            EvOpen,             
            EvClose,            
            EvOpComplete,       
            EvResolveComplete,  
            EvAvsChanged,       

            EvAvsReady,         
            EvAvsIsBad,         

            EvResolveSuccess,   
            EvResolveFailure,   

            EvOpenSuccess,      
            EvOpenFailure,      

            EvReleaseComplete   
        };

    protected:
        struct  AddressEvent : public ObtainableObject {

            AddressEvent(const ObexAddrMsg &    addr_msg) :

                m_addr_msg(addr_msg)
            {
            }
            const ObexAddrMsg &     m_addr_msg;
        };
        struct  CompleteEvent : public ObtainableObject {

            CompleteEvent(const ObexMsg &   obex_msg) :

                c_result(obex_msg.GetResult())
            {
            }
            const ObexResult    c_result;
        };

        EventType   EvalAvsAction(FsmEngine &, EventType, ObjectObtainer &);

        EventType   StartResolveAction(FsmEngine &, EventType, ObjectObtainer &);
        EventType   AbortResolveAction(FsmEngine &, EventType, ObjectObtainer &);
        EventType   ResolveCompleteAction(FsmEngine &, EventType, ObjectObtainer &);

        EventType   OpenAction(FsmEngine &, EventType, ObjectObtainer &);
        EventType   OpenCompleteAction(FsmEngine &, EventType, ObjectObtainer &);

        EventType   CloseAction(FsmEngine &, EventType, ObjectObtainer &);
        EventType   CloseCompleteAction(FsmEngine &, EventType, ObjectObtainer &);

        EventType   ReleaseAction(FsmEngine &, EventType, ObjectObtainer &);
        EventType   DestroyAction(FsmEngine &, EventType, ObjectObtainer &);

        EventType   DefaultAction(FsmEngine &, EventType, ObjectObtainer &);

        ObexAbstractPort(ObexAbstractTransport &        transport,
                         ObexProtocol &                 protocol,
                         const FsmEngine::StateInfo &   initial_state);

        inline  ObexAbstractTransport &     GetTransport();
        inline  const ObexOperationId &     GetTransportOperId() const;
        inline  const ObexAddrPtr &         GetAddress();

        inline  void        SetAddress(const ObexAddrPtr &  addr_ptr);
        inline  void        ReleaseAddress();

        inline  BOOLEAN     IsInState(const FsmEngine::StateInfo &  state) const;

        inline  void        ExternalEvent(EventType             ev_type,
                                          ObtainableObject *    ev_data_ptr);

        ObexOperationId &       StartOperation();

        BOOLEAN                 IsAvsReady() const;

        virtual const CHAR *    GetTraceInfo() const;

        virtual void            StartAddrResolution() = 0;

        virtual void            AbortAddrResolution() = 0;

        virtual BOOLEAN     AcquireChannel(ObexChannel &        channel,
                                           const ObexAddrPtr &  addr_ptr,
                                           ObexResult           result) = 0;

        virtual void        ReleaseChannel();

        virtual void        OpenChannel(const ObexAddrPtr &     addr_ptr) = 0;

        virtual void        CloseChannel(ObexResult cause) = 0;

        virtual void        OnChannelClosed() = 0;

        virtual void        OnChannelOpened(ObexResult  result) = 0;

    private:
        // Substate: Port is waiting for an address resolved by the transport
        FSM_DECLARE_STATE(s2_resolving);

        // Substate: Port is waiting for 'OpenChannel()' to complete.
        FSM_DECLARE_STATE(s2_opening);

        // Substate: Port is waiting for 'CloseChannel()' to complete.
        FSM_DECLARE_STATE(s2_closing);

        ObexOperationId                 m_oper_id;
        ObexChannel                     m_channel;
        ObexAbstractTransport &         m_transport;
        ObexProtocol &                  m_protocol;
        ObexAddrPtr                     m_addr_ptr;
        FsmEngine::StateReferrer        m_fsm_stack[2];
        FsmEngine                       m_fsm;

        ObexAbstractPort(const ObexAbstractPort &);
        ObexAbstractPort &  operator=(const ObexAbstractPort &);
};

/*  ----------------------------------------------------------------------
    GetChannel
    ---------------------------------------------------------------------- */
const ObexChannel &     ObexAbstractPort::GetChannel()
const
{
    return  m_channel;
}// GetChannel

/*  ----------------------------------------------------------------------
    IsAssociated
    ---------------------------------------------------------------------- */
BOOLEAN     ObexAbstractPort::IsBoundTo(const ObexChannel &     channel)
const
{
    return ( m_channel == channel );
}// IsAssociated

/*  ----------------------------------------------------------------------
    GetProtocol
    ---------------------------------------------------------------------- */
ObexProtocol &  ObexAbstractPort::GetProtocol()

{
    return  m_protocol;
}// GetProtocol

/*  ----------------------------------------------------------------------
    GetTransport
    ---------------------------------------------------------------------- */
ObexAbstractTransport &     ObexAbstractPort::GetTransport()
{
    return  m_transport;
}// GetTransport

/*  ----------------------------------------------------------------------
    GetTransportOperId
    ---------------------------------------------------------------------- */
const ObexOperationId &     ObexAbstractPort::GetTransportOperId()
const
{
    return  m_oper_id;
}// GetTransportOperId

/*  ----------------------------------------------------------------------
    IsInState
    ---------------------------------------------------------------------- */
BOOLEAN     ObexAbstractPort::IsInState(const FsmEngine::StateInfo &     state)
const
{
    return  m_fsm.IsInState(state);
}// IsInState

/*  ----------------------------------------------------------------------
    ExternalEvent
    ---------------------------------------------------------------------- */
void    ObexAbstractPort::ExternalEvent(EventType           event_type,
                                        ObtainableObject *  event_data_ptr)
{
    m_fsm.ExternalEvent( event_type, event_data_ptr );
}// ExternalEvent

/*  ----------------------------------------------------------------------
    GetAddress
    ---------------------------------------------------------------------- */
const ObexAddrPtr &     ObexAbstractPort::GetAddress()
{
    return  m_addr_ptr;
}// GetAddress

/*  ----------------------------------------------------------------------
    SetAddress
    ---------------------------------------------------------------------- */
void    ObexAbstractPort::SetAddress(const ObexAddrPtr &    addr_ptr)
{
    m_addr_ptr = addr_ptr;
}// SetAddress

/*  ----------------------------------------------------------------------
    ReleaseAddress
    ---------------------------------------------------------------------- */
void    ObexAbstractPort::ReleaseAddress()
{
    m_addr_ptr.Clear();
}// ReleaseAddress

#endif  // Apoxi_ObexServerPort_hpp

