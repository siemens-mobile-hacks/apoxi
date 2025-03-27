/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexClient_hpp)
#define Apoxi_ObexClient_hpp

#include <Obex/ObexObject.hpp>
#include <Obex/ObexClientDispatcher.hpp>

// Forward declarations of classes.
class ObexBuffer;

class ObexClient : public ObexClientDispatcher {

    public:
        typedef ObexClientDispatcher Base;

        ObexClient();

        ObexClient(ExecutionContext *   ctx_ptr);

        virtual ~ObexClient();

        ObexResult          Connect(const ObexObject &  conn_req);

        ObexResult          Disconnect(const ObexObject &  disc_req);

        ObexResult          Put(const ObexObject &  put_req);

        ObexResult          Get(const ObexObject &  get_req);

        ObexResult          Abort(const  ObexObject &  abort_req);

        ObexResult          SetPath(const ObexObject &  setpath_req);

        ObexResult          DataProcessed(ObexBuffer &  buffer);

        inline  UINT32      GetConnectionId() const;

        inline  UINT32      GetProgressInBytes() const;

    protected:
        virtual void        OnOpen(ObexResult   result);
        virtual void        OnClose(ObexResult  result);

        virtual BOOLEAN     OnChannelsMatch(const ClientPortPtr &   port_ptr,
                                            const ObexMsg &         msg);

        virtual void        OnConnect(const ObexObject &  conn_resp,
                                      ObexResult          result);

        virtual void        OnDisconnect(const ObexObject &  disc_resp,
                                         ObexResult          result);

        virtual void        OnSetPath(const ObexObject &  setp_resp,
                                      ObexResult          result);

        virtual void        OnPutResponse(const ObexObject &  put_resp);

        virtual void        OnPutComplete(ObexResult    result);

        virtual void        OnGetResponse(const ObexObject &  get_resp);

        virtual void        OnGetComplete(ObexResult    result);

        virtual void        OnAbort(const ObexObject &  abort_resp,
                                    ObexResult          result);

        virtual void        OnDataProcessed(ObexBuffer &    buffer);

    private:
        enum OperType {
            OConnect,
            ODisconnect,
            OPut,
            OGet,
            OSetPath,
            ONone
        };

        enum OperState {
            SInitial,   // No request being processed
            SRequest,   // Request has been sent, waiting for response
            SResponse,  // Response has been received, waiting for application
            SFinal      // Final response received, waiting for completion
        };
        ObexObject          m_response;
        UINT32              m_connection_id;
        UINT32              m_data_progress;
        ObexOperationId     m_oper_id;
        OperType            m_oper_type;
        OperState           m_oper_state;
        BOOLEAN             m_abort;
        BOOLEAN             m_final;


        inline  void        SetOperState(OperState  new_state);

        BOOLEAN             HandleBuffer(const ObexMsg &            msg);

        BOOLEAN             HandleResult(const ClientPortPtr &      port_ptr,
                                         const ObexMsg &            msg);

        BOOLEAN             HandleResponse(const ClientPortPtr &    port_ptr,
                                           const ObexMsg &          msg);

        void                CheckForConnId(const ObexObject &       response);
        void                NotifyResponse(const ObexObject &       response);

        void                LaunchRequest(OperType                  oper_type,
                                          BOOLEAN                   end_of_data);

        void                FinalizeOperation();
};

/*  ----------------------------------------------------------------------
    GetConnectionId
    ---------------------------------------------------------------------- */
UINT32  ObexClient::GetConnectionId()
const
{
    return  m_connection_id;
}// GetConnectionId

/*  ----------------------------------------------------------------------
    GetProgressInBytes
    ---------------------------------------------------------------------- */
UINT32  ObexClient::GetProgressInBytes()
const
{
    return  m_data_progress;
}// GetProgressInBytes

/*  ----------------------------------------------------------------------
    SetOperState
    ---------------------------------------------------------------------- */
void    ObexClient::SetOperState(OperState  new_state)
{
    m_oper_state = new_state;
}// SetOperState

#endif  // Apoxi_ObexClient_hpp

