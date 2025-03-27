/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexServerDispatcher_hpp)
#define Apoxi_ObexServerDispatcher_hpp

#include <Auxiliary/BitField.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

#include <Obex/ObexTypes.hpp>
#include <Obex/ObexConfig.hpp>
#include <Obex/ObexResult.hpp>
#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexTransportSet.hpp>

#include <Obex/ObexDispatcher.hpp>

// Forward declarations of classes
class ObexServerPort;
class ObexChannel;


class ObexServerDispatcher : public ObexEventHandler {

    friend class ObexServerPort;

    public:
        typedef ObexEventHandler Base;

        enum OpenFlags {

            SdbAutoRegister  = 1,   


            PrivateTransport = 2,   

        };

        virtual ~ObexServerDispatcher();

        virtual void        Init(ExecutionContext *     ctx_ptr);

        virtual ObexResult  Open(const String &             obex_addr_url,
                                 UINT8                      open_flags     = 0,
                                 const ObexTransportSet &   excl_xport_set = ObexTransportSet() );

        virtual ObexResult  Close();

        inline  UINT8       GetNrOfOpenedTransports() const;

        BOOLEAN             IsBoundToChannel(const ObexChannel &  channel) const;

    protected:
        typedef NiSharedPtr<ObexServerPort> ServerPortPtr;

        static  inline BOOLEAN  IsPortPtrValid(const ServerPortPtr &    port_ptr);

        ObexServerDispatcher();

        inline const String &   GetUrlStr() const;

        inline  BOOLEAN     IsActive() const;

        inline  BOOLEAN     IsActive(const ServerPortPtr &  port_ptr) const;

        inline  BOOLEAN     IsShuttingDown() const;

        virtual BOOLEAN     IsValidContext() const;
        virtual BOOLEAN     OnObexMsg(const ObexMsg &   msg);
        virtual BOOLEAN     OnObexAddrMsg(const ObexAddrMsg &   msg);
        virtual BOOLEAN     OnObexTransportMsg(const ObexTransportMsg & msg);

        virtual void        HangUp();

        virtual void        OnBind(const ObexAddrPtr &  addr_ptr,
                                   ObexResult           result);

        virtual void        OnRelease(const ObexAddrPtr &  addr_ptr,
                                      ObexResult           result);

        /* @brief   Indicates completion of a Close() operation.

            @param  result  When 'result' evaluates to \c 'TRUE' it
                            indicates successful completion of a \c Close()
                            operation, otherwise it was shut down spontaneously.
                            Check the error code in the latter case. */
        virtual void        OnClose(ObexResult  result);

        /*  @brief  Indicates reception of an OBEX protocol event.

            This notification method is called whenever an ObexMsg is received
            which is originated from one of the transport channels the current
            \c ObexServerDispatcher instance is listening to.
            Derived classes mut implement it to dispatch the various events
            resulting from communication using an OBEX-based protocol.

            @param  port_ptr    Port from which the OBEX event was received.
            @param  msg         ObexMsg containing the event type and data. */
        virtual BOOLEAN     OnChannelsMatch(const ServerPortPtr &   port_ptr,
                                            const ObexMsg &         msg) = 0;

        virtual ObexResult  OpenAction();
        virtual ObexResult  CloseAction();

        ServerPortPtr       GetActivePortPtr() const;

        BOOLEAN             IsAcceptable(const ServerPortPtr &  port_ptr) const;

        void                SetActive(const ServerPortPtr &     port_ptr);

        void                SetIdle();

    private:
        enum  ServerFlags {
            IsClosePending,
            IsCloseNotified,
            IsEventPending,
            IsListening
        };

        BitField8           m_server_state;
        UINT8               m_server_flags;
        ObexTransportSet    m_server_excl_set;
        UINT8               m_server_port_cnt;
        ObexDispatcher      m_dispatcher;
        String              m_obex_url_str;
        ServerPortPtr       m_active_port_ptr;
        ServerPortPtr       m_server_port_tab[APOXI_OBEX_MAX_NO_TRANSPORTS];


        void                OnPortClosed(ObexTransportId    id);

        void                CleanUp();
        void                Notify();
        void                NotifyClosed();
};

/*  ----------------------------------------------------------------------
    GetNrOfOpenedTransports
    ---------------------------------------------------------------------- */
inline  UINT8   ObexServerDispatcher::GetNrOfOpenedTransports()
const
{
    return  m_server_port_cnt;
}// GetNrOfOpenedTransports

BOOLEAN     ObexServerDispatcher::IsPortPtrValid(const ServerPortPtr &   port_ptr)
{
    return  ( port_ptr.Get() != 0 );
}

BOOLEAN     ObexServerDispatcher::IsActive()
const
{
    return IsPortPtrValid(m_active_port_ptr);
}

BOOLEAN     ObexServerDispatcher::IsActive(const ServerPortPtr &    port_ptr)
const
{
    return  ( m_active_port_ptr.Get() ==  port_ptr.Get() );
}

/*  ----------------------------------------------------------------------
    IsShuttingDown
    ---------------------------------------------------------------------- */
BOOLEAN     ObexServerDispatcher::IsShuttingDown()
const
{
    return  m_server_state.GetBit(IsClosePending);
}// IsShuttingDown

const String &  ObexServerDispatcher::GetUrlStr()
const
{
    return  m_obex_url_str;
}

#endif  // Apoxi_ObexServerDispatcher_hpp

