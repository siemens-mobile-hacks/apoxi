/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexServer_hpp)
#define Apoxi_ObexServer_hpp

#include <Auxiliary/ByteBuffer.hpp>

#include <Obex/ObexObject.hpp>
#include <Obex/ObexOperationId.hpp>
#include <Obex/ObexServerInfo.hpp>
#include <Obex/ObexServerDispatcher.hpp>

// Forward declarations of classes
class ObexObject;
class ObexBuffer;

class ObexServer : public ObexServerDispatcher {

    public:
        typedef ObexServerDispatcher Base;

        enum Operation {
            OConnect,
            ODisconnect,
            OPut,
            OGet,
            OSetPath,
            OAbort,
            ONone
        };

        ObexServer();

        ObexServer(ExecutionContext *   ctx_ptr);

        virtual ~ObexServer();

        virtual void        Init(ExecutionContext *     ctx_ptr);

        ObexResult  ReturnResponse(const ObexObject &  obex_resp);

        ObexResult  DataProcessed(ObexBuffer &  buffer,
                                  BOOLEAN       proceed = FALSE);

        UINT32                      GetProgressInBytes() const;

        inline  BOOLEAN             IsConnected() const;

        inline  UINT32              GetConnectionId() const;

        inline  const ByteBuffer &  GetTarget() const;

        inline  BOOLEAN         IsBoundToServerId(ObexServerId  id) const
        {
            return  ( m_server_info.GetServerId() == id );
        }

        BOOLEAN                 IsActiveOperation(const ObexOperationId &   oper_id) const;
        BOOLEAN                 IsBoundToTarget(const ByteBuffer &  target) const;
        BOOLEAN                 IsBoundToTarget() const;

    protected:
        virtual BOOLEAN         OnChannelsMatch(const ServerPortPtr &   port_ptr,
                                                const ObexMsg &         msg);

        virtual void            OnConnect(const ObexObject &  conn_req);

        virtual void            OnDisconnect(const ObexObject &  disc_req);

        virtual void            OnPut(const ObexObject &  put_req,
                                      BOOLEAN             initial);

        virtual void            OnGet(const ObexObject &  get_req,
                                      BOOLEAN             initial);

        virtual void            OnAbort(const ObexObject &  abort_req);

        virtual void            OnSetPath(const ObexObject &  setp_req);

        virtual void            OnComplete(Operation    op,
                                           ObexResult   result);

        virtual void            OnDataProcessed(ObexBuffer &    buffer);

        virtual void            OnDisconnected(ObexResult   result) {}

        virtual ObexResult      OpenAction();
        virtual ObexResult      CloseAction();
        virtual BOOLEAN         IsRequestForMe(const ObexMsg &      msg,
                                               ObexDispatcher * &   dispatcher_ptr);
        virtual void            OnBeginOperation(ObexDispatcher *   dispatcher_ptr) {}

        virtual ObexServerId    GetDefaultServerId() const;

    private:
        class ServerInfo : public ObexServerInfo {
            public:
                ServerInfo(ObexServer &     server);

                ObexResult          SetTarget(const String &    url_str);

                const ByteBuffer &  GetTarget() const
                {
                    return m_target;
                }

                virtual BOOLEAN     Accept(ObexServerVisitor &  v);

            private:
                ObexServer &        m_server;
                ByteBuffer          m_target;
        };

        class   DupeChecker;

        enum OperState {
            SInitial,   // No request being processed
            SRequest,   // Request being processed
            SResponse,  // Response has been sent, waiting for request
            SFinal      // Final response has been sent, waiting for completion
        };

        ServerInfo          m_server_info;
        ObexObject          m_abort_request;
        UINT32              m_connection_id;
        UINT32              m_data_progress;
        ObexOperationId     m_active_oper_id;
        Operation           m_active_oper_type;
        BOOLEAN             m_connected;
        BOOLEAN             m_final_response;   // Next response will be final.
        OperState           m_oper_state;

    private:
        BOOLEAN     IsBadRequest(const ServerPortPtr &      port_ptr,
                                 const ObexMsg &            msg,
                                 Operation                  oper_type);

        void        AcceptRequest(const ServerPortPtr &     port_ptr,
                                  const ObexMsg &           msg,
                                  Operation                 oper_type,
                                  BOOLEAN                   simple_op);

        void        RejectRequest(const ServerPortPtr &     port_ptr,
                                  const ObexMsg &           obex_msg,
                                  ObexObject::ResponseCode  cause);

        void        AssignConnectionId();

        void        SetOperState(OperState  new_state);

        BOOLEAN     HandleBuffer(const ObexMsg &            msg);
        BOOLEAN     HandleResult(const ObexMsg &            msg);

        BOOLEAN     HandleConnect(const ServerPortPtr &     port_ptr,
                                  const ObexMsg &           msg);

        BOOLEAN     HandleDisconnect(const ServerPortPtr &  port_ptr,
                                     const ObexMsg  &       msg);

        BOOLEAN     HandlePut(const ServerPortPtr &         port_ptr,
                              const ObexMsg &               msg);

        BOOLEAN     HandleGet(const ServerPortPtr &         port_ptr,
                              const ObexMsg &               msg);

        BOOLEAN     HandleSetPath(const ServerPortPtr &     port_ptr,
                                  const ObexMsg &           msg);

        BOOLEAN     HandleAbort(const ServerPortPtr &       port_ptr,
                                const ObexMsg &             msg);

        BOOLEAN     HandleBadResult(const ObexResult &      result,
                                    BOOLEAN                 in_operation);

        Operation   FinishOperation();
        void        DisposeBodyData(ObexObject  data_obj);
        void        ServiceNotImplemented(const CHAR *  dbg_str);
};

/*  ----------------------------------------------------------------------
    GetTarget
    ---------------------------------------------------------------------- */
const ByteBuffer &  ObexServer::GetTarget()
const
{
    return  m_server_info.GetTarget();
}// GetTarget

/*  ----------------------------------------------------------------------
    IsConnected
    ---------------------------------------------------------------------- */
BOOLEAN             ObexServer::IsConnected()
const
{
    return  m_connected;
}// IsConnected

/*  ----------------------------------------------------------------------
    GetConnectionId
    ---------------------------------------------------------------------- */
UINT32              ObexServer::GetConnectionId()
const
{
    return  m_connection_id;
}// GetConnectionId

#endif  // Apoxi_ObexServer_hpp

