/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(AddOns_StreamObexImpl_hpp)
#define AddOns_StreamObexImpl_hpp


#include <Kernel/Types.hpp>
#include <Kernel/UserDispatcher.hpp>
#include <Kernel/Os/Mutex.hpp>
#include <Auxiliary/ByteBuffer.hpp>
#include <Obex/ObexObject.hpp>
#include <Obex/ObexLayer.hpp>
#include <Obex/ObexChannel.hpp>
#include <Obex/ObexBuffer.hpp>

#include "apoxi_emcpp_OBEXAdapter.hpp"
#include "emcpp_apoxi_OBEXAdapter.hpp"

class StreamObexTransport;


class StreamObexImpl : public ObexLayer {

        typedef ObexLayer Base;


    public:

        enum Error { SUCCESS = 0, FAIL = 1 };

        StreamObexImpl(StreamObexTransport& stream_obex_transport);

        virtual ~StreamObexImpl();

        void Init();

        void Create();

        void Destroy();

        virtual void Connect(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void Get(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void Put(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void Abort(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void SetPath(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void Disconnect(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void ReturnResponse(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexObject& conn_req);

        virtual void DataProcessed(const ObexChannel& client_chan, ObexOperationId oper_id, ObexBuffer& buffer);

        virtual ObexResult AcquireClientChannel(ObexChannel& result, const ObexAddrPtr& addr_ptr, BOOLEAN reserve);

        virtual ObexResult AcquireServerChannel(ObexChannel& result, const ObexAddrPtr& addr_ptr, BOOLEAN reserve) ;

        virtual ObexResult ReleaseChannel(ObexChannel& channel);

        virtual void OpenClientChannel(const ObexChannel& client_chan, ObexOperationId oper_id, const ObexAddrPtr& addr_ptr);

        virtual void BindServerChannel(const ObexChannel& server_chan, ObexOperationId oper_id, const ObexAddrPtr& addr_ptr);

        virtual void CloseChannel(const ObexChannel& server_chan, ObexOperationId oper_id);

        ObexOperationId GetOperationId(const ObexChannel& channel);

        void HandlePut(const ObexChannel& channel, const ObexObject& object);

        void HandleGet(const ObexChannel& channel, const ObexObject& object);

        void HandleConnect(const ObexChannel& channel, const ObexObject& object);

        void HandleDisconnect(const ObexChannel& channel, const ObexObject& object);

        void HandleSetPath(const ObexChannel& channel, const ObexObject& object);

        void HandleAbort(const ObexChannel& channel, const ObexObject& object);

        void HandleTransportDisconnect(const ObexChannel& channel);

        void GetRequestBuffer(const ObexChannel& channel, ObexBuffer& buffer);

        void ReturnResponseBuffer(const ObexChannel& channel, ObexBuffer& buffer);

        // stores OperationId per Channel internally
        Error BeginOperation(const ObexChannel& channel);
        Error EndOperation(const ObexChannel& channel, ObexResult::ErrorCode oper_result);
        INT   IsOperationActive(const ObexChannel& channel);

        // if no buffer avail @return null
        ObexBuffer* CreateBuffer(const ObexChannel& channel, unsigned short expected_packet_size);
        void FinalizeBuffer(const ObexChannel& channel);

        StreamObexTransport& GetTransport();
        
        
    private:

        StreamObexTransport& m_stream_obex_transport;
        ObexChannel m_obex_channel;

        ObexOperationId m_oper_id;

        ObexBuffer m_obex_buffer;

        emcpp_apoxi_OBEXAdapter* m_emcpp_apoxi_obex_adapter;
        apoxi_emcpp_OBEXAdapter* m_apoxi_emcpp_obex_adapter;

        Mutex m_mutex;


};

#endif

