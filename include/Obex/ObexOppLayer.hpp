/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObexOppLayer_hpp)
#define Apoxi_ObexOppLayer_hpp

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#include <Obex/ObexProtocol.hpp>

//  Forward declarations of classes
class ObexObject;
class ObexBuffer;

class ObexOppLayer : public ObexProtocol {

    public:
        virtual void Push(const ObexChannel &   client_chan,
                          ObexOperationId       oper_id,
                          const ObexObject &    push_req) = 0;

        virtual void Pull(const ObexChannel &   client_chan,
                          ObexOperationId       oper_id,
                          const ObexObject &    pull_req) = 0;

        virtual void Abort(const ObexChannel &  client_chan,
                           ObexOperationId      oper_id,
                           const ObexObject &   abort_req) = 0;

        virtual void DataProcessed(const ObexChannel &  channel,
                                   ObexOperationId      oper_id,
                                   ObexBuffer &         obex_buffer) = 0;
    protected:
        ObexOppLayer(TypeId  prot_type);

        void OnPush(const ObexChannel & server_chan,
                    ObexOperationId     oper_id,
                    const ObexObject &  push_req);

        void OnPull(const ObexChannel & server_chan,
                    ObexOperationId     oper_id,
                    const ObexObject &  pull_req);

        void OnAbort(const ObexChannel &  server_chan,
                     ObexOperationId      oper_id,
                     const ObexObject &   abort_req);

        void OnResponse(const ObexChannel &     client_chan,
                        ObexOperationId         oper_id,
                        const ObexObject &      server_resp);

        void OnDataProcessed(const ObexChannel &  server_chan,
                             ObexOperationId      oper_id,
                             ObexBuffer &         app_buffer);
};

#endif  // DOXYGEN_SHOULD_SKIP_THIS

#endif  // Apoxi_ObexOppLayer_hpp

