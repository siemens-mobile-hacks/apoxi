/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObexMngr_hpp)
#define Apoxi_ObexMngr_hpp



#include <Obex/ObexResult.hpp>
#include <Obex/ObexOperationId.hpp>
#include <Obex/ObexTransportSet.hpp>

// Forward declaration of of classes.
class ObexChannel;
class ObexProtocol;
class ObexServerMngr;

class ObexMngr {

    class   TransportManager;

    friend  class ObexAbstractTransport;
    friend  class TransportManager;
    friend  class ObexServerInfo;
    friend  class ObexServer;
    friend  class ObexOppServer;
    friend  class ObexLayer;
    friend  class ObexOppServerTest;

    public:
        static const CHAR *     c_any_url;

        static ObexMngr &   GetInstance();

        ObexOperationId         StartSelection(ObexTransportSet sel_from);

        void                    AbortSelection(ObexOperationId  oper_id);

        ObexAbstractTransport & GetTransport(const ObexChannel &  channel) const;

        ObexAbstractTransport & GetTransport(ObexTransportId    transport_id) const;

        ObexProtocol &          GetProtocol(const ObexChannel &  channel) const;

        void                        RegisterObexApp(Application &   obex_app);

        inline  ObexTransportSet    EnumTransports(const String &   filter_url = c_any_url) const;

        ObexResult              SelectTransport(ObexAbstractTransport *  selected);

    private:
        class TransportVisitor;
        class TransportFilter;
        class TransportFinder;
        class TransportLister;

        class TransportMngr {

            public:
                TransportMngr();

                void                        Init();

                ObexTransportId             Register(ObexAbstractTransport &  t);

                ObexAbstractTransport *     Get(ObexTransportId  id) const;

                ObexAbstractTransport *     Get(const String &  scheme_url) const;

                ObexTransportSet            Enum(const String &  filter_url) const;

            private:
                ObexAbstractTransport *     m_xport_arr[APOXI_OBEX_MAX_NO_TRANSPORTS];
                ObexTransportId             m_first_id_available;

                TransportMngr(const TransportMngr &);

                TransportMngr &     operator=(const TransportMngr &);

                void                ForEach(TransportVisitor &  v)  const;
        };

        class TransportVisitor : public NonCloneable {

            friend class  TransportMngr;

            protected:
                TransportVisitor();

            private:
                /*  @brief  Method called for each node being visited.

                    @param  t   Reference to transport currently visited.
                    @return \c 'TRUE' to stop visiting additional nodes,
                            \c 'FALSE' tp continue. */
                virtual BOOLEAN     Visit(ObexAbstractTransport &  t) = 0;
        };

        class SelectCommand {
            public:
                SelectCommand() {}

                SelectCommand(ObexTransportSet  ts,
                              ObexOperationId   id) :
                    m_from_ts(ts),
                    m_oper_id(id)
                {
                }
                inline  const ObexOperationId &     GetOperationId() const;

                inline  BOOLEAN                     IsPending() const;

                void    Execute(Application *       obex_app_ptr);

                void    Complete(ObexTransportId    transport_id);

            private:
                ObexTransportSet    m_from_ts;
                ObexOperationId     m_oper_id;
        };

        static ObexMngr     s_obex_mngr;

        TransportMngr       m_xport_mngr;
        SelectCommand       m_select_queue[APOXI_OBEX_MAX_NO_SELECTIONS];
        Application *       m_obex_app_ptr;
        UINT8               m_head_queue_indx;
        UINT8               m_tail_queue_indx;
        BOOLEAN             m_select_abort;

        ObexMngr(const ObexMngr &);

        ObexMngr &          operator=(const ObexMngr &);

        ObexMngr();

        void                Init();

        inline  ObexTransportId     RegisterTransport(ObexAbstractTransport &  t);

        ObexServerMngr &            GetServerMngr();
};

/*  ----------------------------------------------------------------------
    SelectCommand::GetOperationId
    ---------------------------------------------------------------------- */
const ObexOperationId &     ObexMngr::SelectCommand::GetOperationId()
const
{
    return  m_oper_id;
}// GetOperationId

/*  ----------------------------------------------------------------------
    SelectCommand::IsPending
    ---------------------------------------------------------------------- */
BOOLEAN     ObexMngr::SelectCommand::IsPending()
const
{
    return  m_oper_id.IsValid();
}// IsPending

/*  ----------------------------------------------------------------------
    EnumTransports
    ---------------------------------------------------------------------- */
ObexTransportSet    ObexMngr::EnumTransports(const String &     filter_url)
const
{
    return  m_xport_mngr.Enum(filter_url);
}// EnumTransports

/*  ----------------------------------------------------------------------
    RegisterTransport
    ---------------------------------------------------------------------- */
ObexTransportId     ObexMngr::RegisterTransport(ObexAbstractTransport &  t)
{
    return  m_xport_mngr.Register(t);
}// RegisterTransport


#endif  // Apoxi_ObexMngr_hpp

