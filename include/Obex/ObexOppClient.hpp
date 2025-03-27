/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexOppClient_hpp)
#define Apoxi_ObexOppClient_hpp

#include <Auxiliary/MimeTypeTable.hpp>

#include <Obex/ObexObject.hpp>
#include <Obex/ObexDispatcher.hpp>

// Forward declarations of classes
class ObexBuffer;
class ObexTriggerMsg;
class ObexClientOppImpl;
class ObexOppClientOperation;


class ObexOppClient {

    class   OppDispatcher;

    friend  class OppDispatcher;
    friend  class ObexClientOppImpl;
    friend  class ObexOppClientPush;
    friend  class ObexOppClientPull;

    public:
        ObexOppClient();

        ObexOppClient(Application *  app_ptr);

        virtual ~ObexOppClient();

        virtual void        Init(Application *  app_ptr);

       ObexResult           Open(const String &     obex_url);

       ObexResult           Close();

        ObexResult  Push(const String &     obex_url,
                         const WString &    obj_name,
                         MimeType           obj_type,
                         const WString &    obj_desc,
                         UINT32             obj_size);

        ObexResult  Pull(const String &     obex_url,
                         MimeType           obj_type = c_mime_unknown,
                         const WString &    obj_name = L"");

        ObexResult  ProvideData(ObexBuffer &    app_data,
                                BOOLEAN         end_data = FALSE);

        ObexResult  DataProcessed(ObexBuffer &  app_data);

        ObexResult      Abort(const WString &   desc,
                              BOOLEAN           force_sync = FALSE);

        UINT32          GetProgressInBytes() const;

    protected:
        virtual void    OnPushConfirmed();

        virtual void    OnDataProcessed(ObexBuffer &    app_data);

        virtual void    OnPushComplete(ObexResult                   result,
                                       ObexObject::ResponseCode     resp_code,
                                       const WString &              push_desc);

        virtual void    OnPullConfirmed(const WString &     obj_name,
                                        const WString &     obj_desc,
                                        UINT32              obj_size);

        virtual void    OnDataAvailable(ObexBuffer &    app_data,
                                        BOOLEAN         end_data);

        virtual void    OnPullComplete(ObexResult                   result,
                                       ObexObject::ResponseCode     resp_code,
                                       const WString &              pull_desc);

    private:
        class OppDispatcher : public ObexDispatcher {

            public:
                OppDispatcher(ObexOppClient *   opp_clnt_ptr);

            protected:
                virtual BOOLEAN         OnMessage(const Message &   msg);

                virtual void            RegisterMessages() const;
                virtual void            UnregisterMessages() const;

            private:
                typedef ObexDispatcher  Base;

                ObexOppClient *         m_actual_client_ptr;
        };

        BOOLEAN                         m_opp_hold_conn;
        BOOLEAN                         m_opp_initiated;
        OppDispatcher                   m_dispatcher;
        ObexObject                      m_request;
        String                          m_url;
        const ObexOppClientOperation *  m_opp_oper_ptr;
        mutable UINT32                  m_opp_progress;

        BOOLEAN                 OnObexTriggerMsg(const ObexTriggerMsg &     msg);

        void                    OnOppInitiated();
        void                    OnOppCompleted();
        void                    OnOppConnected();
        void                    OnOppCancelled(ObexResult   result);

        ObexResult              CheckOperation(const String &   obex_url);
        ObexResult              StartOperation(const ObexOppClientOperation &   op);

        inline  const String &  GetUrl() const
        {
             return m_url;
        }

        inline  BOOLEAN         IsInValidContext() const
        {
            return  m_dispatcher.IsInValidContext();
        }

        inline  BOOLEAN         IsOperationPending() const
        {
             return ( m_opp_oper_ptr != 0 );
        }

        inline  BOOLEAN         HoldsConnection() const
        {
             return m_opp_hold_conn;
        }

        void                    UpdateProgress() const;
};

#endif  // Apoxi_ObexOppClient_hpp

