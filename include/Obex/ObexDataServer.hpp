/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexDataServer_hpp)
#define Apoxi_ObexDataServer_hpp

#include <Obex/ObexObject.hpp>
#include <Obex/ObexBuffer.hpp>
#include <Obex/ObexServer.hpp>

// Forward declarations of classes
class ExecutionContext;
class DataSink;
class BinData;

class ObexDataServer : private ObexServer {

    private:
        typedef ObexServer  Base;

    public:
        enum {
            MinGetFragSize = 256,   
            DefGetFragSize = 4096   
        };
        ObexDataServer();

        ObexDataServer(ExecutionContext *   ctx_ptr);

        virtual ~ObexDataServer();

        virtual void        Init(ExecutionContext *     ctx_ptr);

        void                SetGetFragSize(UINT         frag_size);
        using               Base::Open;
        using               Base::Close;

        ObexHeaderList &    GetResponseHeaderList();

        ObexResult          InitResponse(ObexObject::ResponseCode   resp_code);

        ObexResult          PostResponse();

        ObexResult          AcceptData(DataSink *   data_sink_ptr,
                                       UINT32       max_data_size);

        ObexResult          ProvideData(BinData *   data_src_ptr);

        UINT32              GetProgressInBytes() const;

    protected:
        using               Base::OnDisconnected;
        using               Base::HangUp;
        using               Base::OnClose;
        using               Base::OnBind;
        using               Base::OnRelease;


        virtual void        OnConnect(const ObexHeaderList &    headers,
                                      UINT8                     flags);

        virtual void        OnDisconnect(const ObexHeaderList & headers) {}

        virtual void        OnPutIncoming() {}

        virtual void        OnGetIncoming() {}

        virtual void        OnPutHeaders(const ObexHeaderList & headers) {}

        virtual void        OnGetHeaders(const ObexHeaderList & headers) {}

        virtual void        OnSetPath(const ObexHeaderList &    headers,
                                      UINT8                     flags);

        virtual void        OnAbort(const ObexHeaderList &      headers) {}

        virtual void        OnDelete();

        virtual void        OnDataAvailable();

        virtual void        OnDataComplete();

        virtual void        OnDataRequested();

        virtual void        OnPutComplete(ObexResult    result) {}

        virtual void        OnGetComplete(ObexResult    result) {}


//  private: Only public for MSVC 6 compatibility :-(
    public:
        class OperState;
        class OperPutData;
        class OperGetData;
        class OperIdle;
        class OperConfirm;
        class OperFinal;
        class OperPutRequest;
        class OperPutHeaders;
        class OperPutAccept;
        class OperGetRequest;
        class OperGetHeaders;
        class OperGetAccept;
        class OperGetProvide;

    private:
        // VC6 :-((
        friend class        OperPutData;
        friend class        OperGetData;
        friend class        OperConfirm;
        friend class        OperPutRequest;
        friend class        OperGetRequest;

        ObexBuffer          m_buffer;
        ObexObject          m_request;
        ObexObject          m_response;
        DataSink *          m_data_snk_ptr;
        BinData *           m_data_src_ptr;
        const OperState *   m_op_state_ptr;
        mutable UINT32      m_data_progress;
        UINT32              m_data_size;
        UINT                m_frag_size;
        BOOLEAN             m_is_event_pending;
        BOOLEAN             m_is_event_handled;

        void                InitClass();
        void                SetOperState(const OperState &  next_state);

        BOOLEAN             IsOperationProceeding();

        BOOLEAN             IsRequestAcceptable(const ObexObject &  request,
                                                BOOLEAN             is_initial);

        void                SendResponse(BOOLEAN    force_final);

        void                HandleConfirm();
        void                HandlePutHeaders();
        void                HandlePutData();
        void                HandleGetHeaders();
        void                HandleGetData();

        void                RejectRequest();

        void                PostEvent();
        void                HandleEvents();

        BOOLEAN             RecvBodyData(const OperState &  cont_req_state);
        void                SendBodyData();

        void                UpdateProgress() const;

        virtual ObexResult  CloseAction();

        virtual void        OnConnect(const ObexObject &    conn_req);

        virtual void        OnDisconnect(const ObexObject &  disc_req);

        virtual void        OnPut(const ObexObject &  put_req,
                                  BOOLEAN             initial);

        virtual void        OnGet(const ObexObject &  get_req,
                                  BOOLEAN             initial);

        virtual void        OnAbort(const ObexObject &  abort_req);

        virtual void        OnSetPath(const ObexObject &  setp_req);

        virtual void        OnComplete(Operation    op,
                                       ObexResult   result);

        virtual void        OnDataProcessed(ObexBuffer &    buffer);
};

#endif  // Apoxi_ObexDataServer_hpp

