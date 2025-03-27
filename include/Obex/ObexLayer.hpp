/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexLayer_hpp)
#define Apoxi_ObexLayer_hpp

#include <Obex/ObexServerInfo.hpp>
#include <Obex/ObexProtocol.hpp>

//  Forward declarations of classes
class ObexObject;
class ObexBuffer;
class ObexMsg;
class ObexHeaderList;

class ObexLayer : public ObexProtocol {

    public:
        virtual void Connect(const ObexChannel &    client_chan,
                             ObexOperationId        oper_id,
                             const ObexObject &     conn_req) = 0;

        virtual void Get(const ObexChannel &    client_chan,
                         ObexOperationId        oper_id,
                         const ObexObject &     get_req) = 0;

        virtual void Put(const ObexChannel &    client_chan,
                         ObexOperationId        oper_id,
                         const ObexObject &     put_req) = 0;

        virtual void Abort(const ObexChannel &  client_chan,
                           ObexOperationId      oper_id,
                           const ObexObject &   abort_req) = 0;

        virtual void SetPath(const ObexChannel &    client_chan,
                             ObexOperationId        oper_id,
                             const ObexObject &     setp_req) = 0;

        virtual void Disconnect(const ObexChannel &     client_chan,
                                ObexOperationId         oper_id,
                                const ObexObject &      disc_req) = 0;

        virtual void ReturnResponse(const ObexChannel &     server_chan,
                                    ObexOperationId         oper_id,
                                    const ObexObject &      server_resp) = 0;

        virtual void DataProcessed(const ObexChannel &   channel,
                                   ObexOperationId       oper_id,
                                   ObexBuffer &          obex_buffer) = 0;
    protected:
        ObexLayer();

        void    OnResponse(const ObexChannel &  client_chan,
                           ObexOperationId      oper_id,
                           const ObexObject &   server_resp);

        void OnConnect(const ObexChannel &  server_chan,
                       ObexOperationId      oper_id,
                       const ObexObject &   conn_req);

        void OnDisconnect(const ObexChannel &  server_chan,
                          ObexOperationId      oper_id,
                          const ObexObject &   disc_req);

        void OnSetPath(const ObexChannel &  server_chan,
                       ObexOperationId      oper_id,
                       const ObexObject &   setp_req);

        ObexServerId    OnGet(const ObexChannel &   server_chan,
                              ObexOperationId       oper_id,
                              const ObexObject &    get_req);

        ObexServerId    OnPut(const ObexChannel &   server_chan,
                              ObexOperationId       oper_id,
                              const ObexObject &    put_req);

        void OnAbort(const ObexChannel &    server_chan,
                     ObexOperationId        oper_id,
                     const ObexObject &     abort_req,
                     ObexServerId           server_id = ObexServerInfo::NoServerId);

        void OnDataProcessed(const ObexChannel &  channel,
                             ObexOperationId      oper_id,
                             ObexBuffer &         app_buffer);

    private:
        ObexServerId    DispatchByTarget(BOOLEAN &              has_target,
                                         const ObexChannel &    server_chan,
                                         const ObexHeaderList & headers);

        ObexServerId    DispatchRequest(const ObexChannel &     server_chan,
                                        const ObexObject &      request,
                                        BOOLEAN                 is_disc);

        void            RejectRequest(const ObexChannel &       server_chan,
                                      const ObexOperationId &   oper_id,
                                      const ObexObject &        obex_req);
};

#endif  // Apoxi_ObexLayer_hpp

