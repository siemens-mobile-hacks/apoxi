/*  ------------------------------------------------------------------------
Copyright (C) 2005 COMNEON Software GmbH & Co. All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(Apoxi_IrdaObexImpl_hpp)
#define Apoxi_IrdaObexImpl_hpp

#include "IrdaObexAddr.hpp"

#include <stack/extensions.h>

#include <Kernel/Os/Mutex.hpp>

#include <Obex/ObexLayer.hpp>
#include <Obex/ObexChannel.hpp>
#include <Obex/ObexHeaderBuilder.hpp>
#include <Obex/ObexObject.hpp>
#include <Obex/ObexBuffer.hpp>

#define APOXI_IRDA_OBEX_MAX_CHANNELS    10
#define APOXI_IRDA_OBEX_HEADER_BUFF_SIZE OBEX_TX_BUFF_SIZE

class IrdaObexImpl : public ObexLayer {


    class ClientAppContext;
    class ServerAppContext;

    friend class ClientAppContext;
    friend class ServerAppContext;

    public:

        IrdaObexImpl();

        /*
         * implementation of ObexProtocol
         */

        virtual ObexResult  AcquireClientChannel(ObexChannel &          result,
                                                 const ObexAddrPtr &    addr_ptr,
                                                 BOOLEAN                reserve);

        virtual ObexResult  AcquireServerChannel(ObexChannel &          result,
                                                 const ObexAddrPtr &    addr_ptr,
                                                 BOOLEAN                reserve);

        virtual ObexResult  ReleaseChannel(ObexChannel &  channel);

        virtual void OpenClientChannel(const ObexChannel &  client_chan,
                                       ObexOperationId      oper_id,
                                       const ObexAddrPtr &  addr_ptr);

        virtual void BindServerChannel(const ObexChannel &  server_chan,
                                       ObexOperationId      oper_id,
                                       const ObexAddrPtr &  addr_ptr);

        virtual void CloseChannel(const ObexChannel &  server_chan,
                                  ObexOperationId      oper_id);
        /*
         * implementation of ObexLayer
         */

        virtual void Connect(const ObexChannel &    client_chan,
                             ObexOperationId        oper_id,
                             const ObexObject &     conn_req);

        virtual void Get(const ObexChannel &    client_chan,
                         ObexOperationId        oper_id,
                         const ObexObject &     get_req);

        virtual void Put(const ObexChannel &    client_chan,
                         ObexOperationId        oper_id,
                         const ObexObject &     put_req);

        virtual void Abort(const ObexChannel &  client_chan,
                           ObexOperationId      oper_id,
                           const ObexObject &   abort_req);

        virtual void SetPath(const ObexChannel &    client_chan,
                             ObexOperationId        oper_id,
                             const ObexObject &     setp_req);

        virtual void Disconnect(const ObexChannel &     client_chan,
                                ObexOperationId         oper_id,
                                const ObexObject &      disc_req);

        virtual void ReturnResponse(const ObexChannel &     server_chan,
                                    ObexOperationId         oper_id,
                                    const ObexObject &      server_resp);

        virtual void DataProcessed(const ObexChannel &   channel,
                                   ObexOperationId       oper_id,
                                   ObexBuffer &      obex_buffer);
    private:

        /* helper construct to get reference to IrdaObexImpl object
           in Extended Systems callback functions */
        /* no member templates... */
        class ServerAppContext
        {
            friend class IrdaObexImpl;

            public:
                ServerAppContext(IrdaObexImpl & self, UINT index) : m_self(self),
                    m_index(index)
                {
                    m_self.m_server_app_contexts[m_index] = this;
                }

                ~ServerAppContext() {
                        m_self.m_server_app_contexts[m_index] = 0;
                }

                inline IrdaObexImpl & GetSelf() const { return m_self; }
                inline U8 *GetHeaderBuffer() const { return (U8 *) m_header_buffer; }
                inline U16 GetHeaderBufferLen() { return sizeof(m_header_buffer); }
                inline ObexChannel & GetChannel() {
                    return m_channel;
                }
                inline void StartOperation(ObexOperationId oper_id) {
                    ASSERT_DEBUG(!m_oper_id.IsValid());
                    m_oper_id = oper_id;
                }
                inline void StopOperation(ObexResult & result) {
                    m_self.OnComplete(m_channel, m_oper_id, result);
                    m_oper_id.Invalidate();
                }

                inline BOOLEAN          IsBusy() const
                {
                    return  m_oper_id.IsValid();
                }

                void                    Close(ObexOperationId   oper_id);
                void                    OnChannelClosed();

            private:
                // must be first member
                ObexServerApp           m_server_app;
                IrdaObexImpl &          m_self;
                U8                      m_header_buffer[APOXI_IRDA_OBEX_HEADER_BUFF_SIZE];
                ObexOperationId         m_oper_id;
                ObexOperationId         m_close_oper_id;
                UINT                    m_index;
                ObexChannel             m_channel;
                ObServerEvent           m_last_event;
                ObexHeaderBuilder       m_oheaderbuilder;
                ObexObject              m_received_obex_obj;
                ObexBuffer              m_buffer;
                ObexObject              m_get_resp_obex_obj;
                ObexBuffer::Size        m_get_offset;
        };

        /* helper construct to get reference to IrdaObexImpl object
           in Extended Systems callback functions */

        class ClientAppContext
        {
            friend class IrdaObexImpl;

            public:
                ClientAppContext(IrdaObexImpl & self, UINT index) : m_self(self),
                    m_index(index),
                    m_tried_irxfer_obex(FALSE)
                {
                    m_self.m_client_app_contexts[m_index] = this;
                }

                ~ClientAppContext() {
                        m_self.m_client_app_contexts[m_index] = 0;
                }

                inline IrdaObexImpl & GetSelf() const { return m_self; }
                inline U8 *GetHeaderBuffer() const { return (U8 *) m_header_buffer; }
                inline U16 GetHeaderBufferLen() const { return sizeof(m_header_buffer); }
                inline ObexChannel & GetChannel() {
                    return m_channel;
                }
                inline void SetAddrPtr(const ObexAddrPtr & addr_ptr) { m_addr_ptr = addr_ptr; }
                inline IrDeviceAddr GetRemoteAddr() const {
                    return ((IrdaObexClientAddr &) *m_addr_ptr).GetRemoteAddr(); }
                inline void StartOperation(ObexOperationId oper_id) {
                    ASSERT(!m_oper_id.IsValid());
                    m_oper_id = oper_id;
                }
                inline void StopOperation(ObexResult & result) {
                    m_self.OnComplete(m_channel, m_oper_id, result);
                    m_oper_id.Invalidate();
                }

                void                    Close(ObexOperationId   oper_id);
                void                    OnChannelClosed();

            private:

                // must be first member
                ObexClientApp           m_client_app;
                IrdaObexImpl &          m_self;
                U8                      m_header_buffer[APOXI_IRDA_OBEX_HEADER_BUFF_SIZE];
                ObexAddrPtr             m_addr_ptr;
                ObexOperationId         m_oper_id;
                ObexOperationId         m_close_oper_id;
                ObexOperationId         m_abort_oper_id;
                UINT                    m_index;
                ObexChannel             m_channel;
                BOOLEAN                 m_tried_irxfer_obex;
                BOOLEAN                 m_is_data_expected;
                ObexHeaderBuilder       m_oheaderbuilder;
                ObexObject              m_received_obex_obj;
                ObexBuffer              m_buffer;
                ObexBuffer::Size        m_get_offset;
                ObexObject              m_get_obex_obj;
                ObexBuffer::Size        m_put_offset;
                ObexObject              m_put_obex_obj;
                ObexObject              m_abort_req;
        };

        void ObexTpConnect(ClientAppContext & client_context, const U8 *query, U8 len) const;

        /*
         * Extended Systems specific callback functions
         */

        static void ObexServerCallback(ObexServerCallbackParms *parms);

        static void ObexClientCallback(ObexClientCallbackParms *parms);

        /*
         * Object Store API functions
         */

        static ObexRespCode OBSTORE_Read(void *obs, U8 *buff, U16 len);

        static ObexRespCode OBSTORE_WriteServer(void *obs, U8 *buff, U16 len);
        static ObexRespCode OBSTORE_WriteClient(void *obs, U8 *buff, U16 len);

        static U32 OBSTORE_GetObjectLen(void *obs);

        static ObexRespCode OBSTORE_ReadFlexServer(void *obs, U8 *buff, U16 *len, BOOL *more);
        static ObexRespCode OBSTORE_ReadFlexClient(void *obs, U8 *buff, U16 *len, BOOL *more);

        BOOLEAN ComposeHeaders(const ObexObject &   put_req, ObexAppHandle * apphandle  );


        /* End of Extended Systems specific callback functions */

        UINT GetFreeClientIndex() const;
        UINT GetFreeServerIndex() const;

        
        static void OnTimerForceDisconnect(void* arg);
        enum force_disconnect_timeout{  c_force_disconnect_timeout = 300 // if after Client ObexDisconnect no Success Response is received during this interval, disconnect is forced.
        };


        static ObStoreFuncTable     m_obsf_server;
        static ObStoreFuncTable     m_obsf_client;

        ClientAppContext *          m_client_app_contexts[APOXI_IRDA_OBEX_MAX_CHANNELS];
        BOOLEAN                     m_client_app_contexts_is_used[APOXI_IRDA_OBEX_MAX_CHANNELS];
        UINT                        m_default_server_index;
        UINT                        m_default_server_index_count;
        UINT                        m_default_server_index_bound_count;
        ServerAppContext *          m_server_app_contexts[APOXI_IRDA_OBEX_MAX_CHANNELS];
        Mutex                       m_mutex;
        static SystemTimer          m_timer_force_disconnect;
};

#if defined(_DEBUG)
static const char * ObexResultErrorcodeStringtab[] ={
    "Success" ,
        "ObexError"  ,
        "OperationAborted",
        "TransportDisconnected" ,"","","","",
        "OperationAlreadyRunning"  ,
        "OperationNotSupported"     ,
        "OperationNotPermitted"  ,
        "InvalidHeadersInRequest","","","","",
        "ResourceNotAvailable"   ,
        "OutOfMemory"       ,"","","","","","","","","","","","","","",
        "ServerAlreadyOpen",
        "ServerAlreadyClosed","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",
        "ClientAlreadyOpen",
        "ClientAlreadyClosed","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",
        "InvalidHeaderId",
        "UnknownMimeType","","","", ""
        ,"","","","","","","","","",""    ,"","","","","","","","","",""     ,"","","","","","","","","",""     ,"","","","","","","","","",""     ,"","","","","","","","","",""
        ,"","","","","","","","","",""    ,"","","","","","","","","",""     ,"","","","","","","","","",""     ,"","","","","","","","","",""     ,"","","","","","","","","",""
        ,"","","","","","","","","",""    ,"","","","","","","","","",""     ,"","","","","","","","","",""     ,"","","","","","","","","",""     ,"","","","","","","","","",""
        ,"252","253","254",
        "Unspecified",
};


static const char * ObexResultResponseCodeStringtab[] ={
    "Request" ,  "","","","","","","","","","",   "","","","","","","","","","",   "","","","","","","","","","",  "",
        "RespOk"  ,  "","","","","","","","",   "","","","","","","",
        // 3xx codes
        "RespMultipleChoices" ,
        "RespMovedPermanently" ,
        "RespMovedTemporarily" ,
        "RespSeeOther" ,
        "RespNotModified" ,
        "RespUseProxy" ,  "","","","","","","",   "","","",
        // 4xx codes
        "RespBadRequest" ,
        "RespUnauthorized" ,
        "RespPaymentRequired" ,
        "RespForbidden" ,
        "RespNotFound" ,
        "RespMethodNotAllowed" ,
        "RespNotAcceptable" ,
        "RespProxyAuthenticationRequired" ,
        "RespRequestTimeOut" ,
        "RespConflict" ,
        "RespGone" ,
        "RespLengthRequired" ,
        "RespPreconditionFailed" ,
        "RespRequestedEntityTooLarge" ,
        "RespRequestUrlTooLarge" ,
        "RespRequestUnsupportedMediaType" ,
        // 5xx codes
        "RespInternalServerError" ,
        "RespNotImplemented" ,
        "RespBadGateWay" ,
        "RespServiceUnavailable" ,
        "RespGatewayTimeOut" ,
        "RespHttpVersionNotSupported" ,   "","","","","","","","","","",
        // 6xx codes
        "RespDatabaseFull" ,
        "RespDatabaseLocked" , "","","","","","","","","","","","","","",
        // 7xx codes
        "","","","","","","","","","","","","","","","",
        // 8xx codes
        "","","","","","","","","","","","","","","","",   "","","","","","","","","","","","","","","","",
        // Axx codes
        "","","","","","","","","","","","","","","","",   "","","","","","","","","","","","","","","","",
        // Cxx codes
        "","","","","","","","","","","","","","","","",   "","","","","","","","","","","","","","","","",
        // Exx codes
        "","","","","","","","","","","","","","","","",   "","","","","","","","","","","","","","","","",
};

static const char * ObStatusStringtab[] ={
        "OB_STATUS_SUCCESS" ,
        "OB_STATUS_FAILED"  ,
        "OB_STATUS_PENDING"  ,
        "OB_STATUS_DISCONNECT"  ,
        "OB_STATUS_NO_CONNECT"  ,
        "NN05"  ,
        "OB_STATUS_MEDIA_BUSY"  ,
        "NN07"  ,
        "NN08"  ,
        "NN09"  ,
        "NN10"  ,
        "OB_STATUS_BUSY"  ,
        "OB_STATUS_NO_RESOURCES"  ,
        "NN13"  ,
        "NN14"  ,
        "NN15"  ,
        "NN16"  ,
        "NN17"  ,
        "OB_STATUS_INVALID_PARM"  ,
        "OB_STATUS_IN_PROGRESS"  ,
        "NN20"  ,
        "NN21"  ,
        "NN22"  ,
        "NN23"  ,
        "NN24"  ,
        "NN25"  ,
        "NN26"  ,
        "NN27"  ,
        "NN28"  ,
        "NN29"  ,
        "OB_STATUS_INVALID_HANDLE"  ,
        "OB_STATUS_PACKET_TOO_SMALL"  ,
        "OB_STATUS_NO_SESSION"  ,


};



#endif



#endif // Apoxi_IrdaObexImpl_hpp

