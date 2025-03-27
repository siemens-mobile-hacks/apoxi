/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexClientDispatcher_hpp)
#define Apoxi_ObexClientDispatcher_hpp

#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/BitField.hpp>

#include <Obex/ObexResult.hpp>
#include <Obex/ObexChannel.hpp>
#include <Obex/ObexAddress.hpp>
#include <Obex/ObexAddrPtr.hpp>
#include <Obex/ObexOperationId.hpp>
#include <Obex/ObexDispatcher.hpp>

// Forward declarations of classes
class ObexClientPort;

class ObexClientDispatcher : public ObexEventHandler {

    friend class ObexClientPort;

    public:
        typedef ObexEventHandler Base;

        virtual ~ObexClientDispatcher();

        virtual void            Init(ExecutionContext *     ctx_ptr);

        virtual ObexResult      Open(const String &  obex_addr_url);

        virtual ObexResult      Close();

        inline  ObexAddrPtr     GetRemoteAddrPtr() const;

    protected:
        typedef NiSharedPtr<ObexClientPort> ClientPortPtr;

        ClientPortPtr           GetActivePortPtr() const;

        static  inline BOOLEAN  IsValidPortPtr(const ClientPortPtr &    port_ptr);

        ObexClientDispatcher();

        virtual BOOLEAN         IsValidContext() const;

        virtual BOOLEAN         OnObexMsg(const ObexMsg &   msg);

        virtual BOOLEAN         OnObexAddrMsg(const ObexAddrMsg &   msg);

        virtual BOOLEAN         OnObexTransportMsg(const ObexTransportMsg &  msg);

        virtual void            OnOpen(ObexResult   result) = 0;

        virtual void            OnClose(ObexResult  result) = 0;

        virtual BOOLEAN         OnChannelsMatch(const ClientPortPtr &   port_ptr,
                                                const ObexMsg &         msg) = 0;

        virtual ObexResult      OpenAction();

        virtual ObexResult      CloseAction();

        void                    AbortSelection();

    private:
        enum  ClientFlags {
            IsOpenPending,      
            IsClosePending,     
            IsOpenNotified,     
            IsCloseNotified,    
            IsEventPending,     
            IsConnected,        
        };

        BitField8               m_client_state;
        ObexResult              m_result;
        ObexOperationId         m_select_oper_id;
        ObexDispatcher          m_dispatcher;
        String                  m_obex_url_str;
        ClientPortPtr           m_active_port_ptr;

        void                    OnPortOpened(ObexResult     result);
        void                    OnPortClosed(ObexTransportId    id);
        ObexResult              OnTransportSelected(ObexTransportId id);
        void                    Notify();
        void                    NotifyOpened();
        void                    NotifyClosed();
        void                    CleanUp();
};

BOOLEAN     ObexClientDispatcher::IsValidPortPtr(const ClientPortPtr &   port_ptr)
{
    return  ( port_ptr.Get() != 0 );
}

#if 0
/*  ----------------------------------------------------------------------
    GetRemoteAddrPtr
    ---------------------------------------------------------------------- */
ObexAddrPtr     ObexClientDispatcher::GetRemoteAddrPtr()
const
{
    return  m_addr_ptr;
}// GetRemoteAddrPtr
#endif

#endif  // Apoxi_ObexClientDispatcher_hpp

