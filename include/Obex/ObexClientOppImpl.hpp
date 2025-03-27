/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexClientOppImpl_hpp)
#define Apoxi_ObexClientOppImpl_hpp

#include <Obex/ObexBuffer.hpp>
#include <Obex/ObexClient.hpp>
#include <Obex/ObexOppClient.hpp>

class ObexOppClientOperation {

    public:
        ObexOppClientOperation();

        virtual ~ObexOppClientOperation();

        virtual ObexResult  Initiate(const ObexObject &     request) const = 0;

        virtual void        OnFailure(ObexOppClient &       client,
                                      const ObexResult &    result) const = 0;
};

class ObexOppClientPush : public ObexOppClientOperation {
    public:
        static  inline  ObexOppClientOperation &    GetInstance()
        {
            return s_instance;
        }

        virtual ObexResult  Initiate(const ObexObject &     request) const;

        virtual void        OnFailure(ObexOppClient &       client,
                                      const ObexResult &    result) const;

    private:
        static  ObexOppClientPush   s_instance;
};

class ObexOppClientPull : public ObexOppClientOperation {
    public:
        static  inline  ObexOppClientOperation &    GetInstance()
        {
            return s_instance;
        }

        virtual ObexResult  Initiate(const ObexObject &     request) const;

        virtual void        OnFailure(ObexOppClient &       client,
                                      const ObexResult &    result) const;
    private:
        static  ObexOppClientPull   s_instance;
};

class ObexClientOppImpl : public ObexClient {

    public:
        static  ObexClientOppImpl &     GetInstance();

        inline  BOOLEAN     IsActiveOppClient(const ObexOppClient *  client_ptr)
        const
        {
            return ( m_active_opp_client_ptr == client_ptr );
        }

        ObexResult          StartOperation(ObexOppClient *  opp_client_ptr);

        void                Disconnect();

        void                CloseConnection();

        ObexResult          Push(const ObexObject &     push_req);

        ObexResult          Pull(const ObexObject &     push_req);

        ObexResult          Abort(const WString &       desc,
                                  BOOLEAN               force_sync);

        ObexResult          ProvideData(ObexBuffer &    app_data,
                                        BOOLEAN         end_data);

        ObexResult          DataProcessed(ObexBuffer &  app_data);

    protected:
        virtual BOOLEAN     IsValidContext() const;
        virtual void        OnOpen(ObexResult   result);
        virtual void        OnClose(ObexResult  result);

        virtual void        OnConnect(const ObexObject &        conn_resp,
                                      ObexResult                result);

        virtual void        OnDisconnect(const ObexObject &     disc_resp,
                                         ObexResult             result);

        virtual void        OnPutResponse(const ObexObject &    put_resp);
        virtual void        OnPutComplete(ObexResult            result);
        virtual void        OnGetResponse(const ObexObject &    get_resp);
        virtual void        OnGetComplete(ObexResult            result);

        virtual void        OnAbort(const ObexObject &  abort_resp,
                                    ObexResult          result);

        virtual void        OnDataProcessed(ObexBuffer &    buffer);

    private:
        typedef ObexClient  Base;

        enum OppState {

            SOppAvailable,      
            SOppOpening,        
            SOppTransient,      
            SOppCancelled,      
            SOppConnected,      

            SOppAborted,        
            SOppFinally,        

            SOppPushInitial,    
            SOppPushContinued,  
            SOppPushResponse,   

            SOppPullInitial,    
            SOppPullContinued,  
            SOppPullResponse    
        };

        static  ObexClientOppImpl   s_instance;

        OppState                    m_opp_state;
        ObexObject::ResponseCode    m_resp_code;
        BOOLEAN                     m_is_end_data;  // Only request !
        BOOLEAN                     m_is_final;     // Only response !
        BOOLEAN                     m_is_api_being_notified;
        WString                     m_description;
        ObexOppClient *             m_active_opp_client_ptr;
        ObexObject                  m_request;
        ObexBuffer                  m_buffer;

        ObexClientOppImpl();

        inline  ObexOppClient &     GetActiveOppClient()
        {
            ASSERT_DEBUG(m_active_opp_client_ptr != 0);
            return *m_active_opp_client_ptr;
        }

        inline  void        SetActiveOppClient(ObexOppClient *  client_ptr)
        {
            m_active_opp_client_ptr = client_ptr;
        }

        inline  void        SetOppState(OppState    new_state)
        {
            m_opp_state = new_state;
        }

        inline  OppState    GetOppState() const
        {
            return  m_opp_state;
        }

        inline  BOOLEAN     IsInState(OppState  query_state) const
        {
            return  ( query_state == m_opp_state );
        }

        void        OnBadResponse(const ObexObject &  bad_resp);

        void        SendAbort();

        ObexResult  EnqueueData(ObexBuffer &    app_data,
                                BOOLEAN         end_data);

        BOOLEAN     OnOppPreComplete(const ObexResult &     result);
};

#endif  // Apoxi_ObexClientOppImpl_hpp

