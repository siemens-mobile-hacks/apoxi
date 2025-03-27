/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexServerOppImpl_hpp)
#define Apoxi_ObexServerOppImpl_hpp

#include "ObexBuffer.hpp"
#include "ObexObject.hpp"
#include "ObexServer.hpp"

// Forward declarations of classes
class ObexOppServer;


class ObexServerOppImpl : public ObexServer {

    public:
        static  ObexServerOppImpl &     GetInstance();

        inline  BOOLEAN     IsActiveOppServer(const ObexOppServer *  srvr_ptr)
        const
        {
            return  ( srvr_ptr == m_active_opp_server_ptr );
        }

        ObexResult  AttachOppServer(ObexOppServer *     self_ptr);

        void        DetachOppServer(ObexOppServer *     self_ptr);

        ObexResult  AcceptPush();

        ObexResult  AcceptPull(const WString &  obj_name,
                               const WString &  obj_desc,
                               UINT32           obj_size);

        ObexResult  ProvideData(ObexBuffer &    app_data,
                                BOOLEAN         end_data);

        ObexResult  DataProcessed(ObexBuffer &  app_data);

        ObexResult  DataProcessed();

        ObexResult  CancelOperation(ObexObject::ResponseCode    resp_code,
                                    const WString &             resp_desc);

    protected:
        virtual BOOLEAN         IsValidContext() const;
        virtual void            OnConnect(const ObexObject &  conn_req);
        virtual void            OnDisconnect(const ObexObject &  disc_req);
        virtual void            OnPut(const ObexObject & put_req, BOOLEAN   initial);
        virtual void            OnGet(const ObexObject & put_req, BOOLEAN   initial);
        virtual void            OnAbort(const ObexObject &  abort_req);
        virtual void            OnComplete(Operation    op, ObexResult  result);
        virtual void            OnDataProcessed(ObexBuffer &    buffer);
        virtual BOOLEAN         IsRequestForMe(const ObexMsg &      msg,
                                               ObexDispatcher * &   dispatcher_ptr);
        virtual void            OnBeginOperation(ObexDispatcher *   dispatcher_ptr);
        virtual ObexServerId    GetDefaultServerId() const;

    private:
        typedef ObexServer  Base;

        enum OppState {

            SOppAvailable,      
            SOppAborted,        
            SOppFinally,        

            SOppPushRequest,    
            SOppPushContinued,  
            SOppPushResponse,   

            SOppPullRequest,    
            SOppPullContinued,  
            SOppPullResponse,   
        };

        class HeaderCollector {

            public:
                HeaderCollector() : m_size(0)
                {
                }
                void                        Reset();

                BOOLEAN                     Parse(const ObexHeaderList &    headers);

                inline  UINT32              GetSize() const
                {
                    return  m_size;
                }
                inline  const WString &     GetName() const
                {
                    return  m_name;
                }
                inline  const String &      GetType() const
                {
                    return  m_type;
                }
                inline  const WString &     GetDescription() const
                {
                    return  m_desc;
                }

            private:
                UINT32              m_size;
                WString             m_name;
                String              m_type;
                WString             m_desc;

                HeaderCollector(const HeaderCollector &);
                HeaderCollector &   operator=(const HeaderCollector &);
        };

        static  ObexServerOppImpl   s_instance;

        OppState                    m_opp_state;
        BOOLEAN                     m_is_accepted;
        BOOLEAN                     m_is_end_data;  // Only response !
        BOOLEAN                     m_is_final;     // Only request !
        ObexObject::ResponseCode    m_resp_code;
        UINT8                       m_active_opp_server_cnt;
        WString                     m_description;
        ObexObject                  m_response;
        ObexBuffer                  m_buffer;
        ObexOppServer *             m_active_opp_server_ptr;
        const ExecutionContext *    m_active_context_ptr;
        HeaderCollector             m_opp_headers;

        ObexServerOppImpl();

        inline  ObexOppServer &     GetActiveOppServer()
        {
            ASSERT_DEBUG(m_active_opp_server_ptr != 0);
            return *m_active_opp_server_ptr;
        }

        inline  BOOLEAN     IsApiActive() const
        {
            return  ( m_active_opp_server_ptr != 0 );
        }

        inline  void        SetOppState(OppState    new_state)
        {
            m_opp_state = new_state;
        }

        inline  OppState    GetOppState()const
        {
            return  m_opp_state;
        }

        inline  BOOLEAN     IsInState(OppState  query_state) const
        {
            return  ( query_state == m_opp_state );
        }

        inline BOOLEAN      IsOperationCancelled() const
        {
            return ( m_resp_code != ObexObject::RespOk );
        }

        ObexOppServer *     FindOppServer(ObexServerId  server_id);

        void                BeginOppRequest(ObexObject  request);

        ObexResult          EnqueueData(ObexBuffer &    app_data,
                                        BOOLEAN         end_data);

        void                DequeueData();

        ObexResult          SendResponse(OppState       next_state);
        ObexResult          ReturnBuffer(ObexBuffer &   app_data);
};

#endif  // Apoxi_ObexServerOppImpl_hpp

