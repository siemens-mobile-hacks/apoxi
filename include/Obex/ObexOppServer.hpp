/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexOppServer_hpp)
#define Apoxi_ObexOppServer_hpp

#include <Auxiliary/MimeTypeTable.hpp>
#include <Auxiliary/DynamicBitVector.hpp>

#include <Obex/ObexObject.hpp>
#include <Obex/ObexDispatcher.hpp>
#include <Obex/ObexServerInfo.hpp>

// Forward declarations of classes
class ExecutionContext;
class ObexBuffer;
class ObexChannel;
class ObexOperationId;

class ObexOppServer {

    class  DupeChecker;
    class  InstanceFinder;

    friend class ObexServerOppImpl;
    friend class DupeChecker;

    public:
        ObexOppServer();

        ObexOppServer(ExecutionContext *    ctx_ptr,
                      MimeType              mime_type);

        virtual void    Init(ExecutionContext *     ctx_ptr,
                             MimeType               mime_type);

        ObexResult      BindToMimeType(MimeType     mime_type);

        ObexResult      UnbindMimeType(MimeType     mime_type);

        ObexResult      Open();

        ObexResult      Close();

        ObexResult      AcceptPush();

        ObexResult      AcceptPull(const WString &  obj_name,
                                   const WString &  obj_desc,
                                   UINT32           obj_size);

        ObexResult      ProvideData(ObexBuffer &    app_data,
                                    BOOLEAN         end_data = FALSE);

        ObexResult      DataProcessed(ObexBuffer &  app_data);

        ObexResult      DataProcessed();

        ObexResult      CancelOperation(ObexObject::ResponseCode    resp_code,
                                        const WString &             resp_desc = WString());

        UINT32          GetProgressInBytes() const;

        BOOLEAN         IsActiveOperation(const ObexOperationId oper_id) const;

        BOOLEAN         IsBoundToChannel(const ObexChannel &    channel) const;

        BOOLEAN         IsBoundToMimeType(MimeType  mime_type) const;

        BOOLEAN         IsBoundToServerId(ObexServerId  id) const
        {
            return  ( m_server_info.GetServerId() == id );
        }

    protected:
        virtual void    OnPush(const WString &  obj_name,
                               const String &   obj_type,
                               const WString &  obj_desc,
                               UINT32           obj_size);

        virtual void    OnPull(const WString &  obj_name,
                               const String &   obj_type);

        virtual void    OnAbort();

        virtual void    OnDataAvailable(ObexBuffer &    app_data,
                                        BOOLEAN         end_data);

        virtual void    OnDataProcessed(ObexBuffer &    buffer);

        virtual void    OnPushComplete(ObexResult       result,
                                       const WString &  description);

        virtual void    OnPullComplete(ObexResult       result,
                                       const WString &  description);

    private:
        class OppDispatcher : public ObexDispatcher {

            public:
                OppDispatcher(ObexOppServer *   opp_srvr_ptr);

                inline  ObexOppServer *     GetServerPtr() const
                {
                    return  m_server_ptr;
                }

            private:
                typedef ObexDispatcher      Base;

                ObexOppServer *             m_server_ptr;
        };

        class ServerInfo : public ObexServerInfo {
            public:
                ServerInfo(ObexOppServer &  server);

                virtual BOOLEAN     Accept(ObexServerVisitor &  v);

            private:
                ObexOppServer &     m_server;
        };

        OppDispatcher               m_dispatcher;
        ServerInfo                  m_server_info;
        mutable UINT32              m_opp_progress;
        DynamicBitVector            m_mime_type_set;
        BOOLEAN                     m_is_open;

        static  ObexOppServer *     FindInstance(ObexServerId   server_id);

        inline  BOOLEAN             IsAmbigous(const DynamicBitVector & mime_type_set)
        const
        {
            return  m_mime_type_set.Intersects(mime_type_set);
        }

        BOOLEAN                     IsRequestForMe(const ObexMsg &      msg,
                                                   ObexDispatcher * &   dispatcher_ptr);

        void                        InitClass(ExecutionContext *    ctx_ptr,
                                              MimeType              mime_type);

        void                        UpdateProgress() const;
};

#endif  // Apoxi_ObexOppServer_hpp

