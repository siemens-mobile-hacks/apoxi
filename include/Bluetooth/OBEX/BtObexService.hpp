/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexService_hpp)
#define BtObexService_hpp

#include <Kernel/UserDispatcher.hpp>
#include <Bluetooth/BtObservableService.hpp>
#include <Bluetooth/OBEX/BtObexEvent.hpp>
#include <Bluetooth/OBEX/BtObexServiceObserver.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexRequest;
class BtObexController;

class BtObexService: public BtObservableService
{
    private:
        typedef BtObservableService Base;

    public:
        BtObexService();

        virtual ~BtObexService();


        virtual BtProfile GetProfile() const;


        virtual BOOLEAN IsServerService() const = 0;


        virtual BtRequestState RegisterRequest(UINT8* header_buffer, UINT16 header_buffer_size, BtSecuritySettings security_settings = BtSesNoSecurity) = 0;


        virtual BtRequestState UnregisterRequest() = 0;


        BOOLEAN AddHeader(UINT8 header_id, UINT8 header_value);


        BOOLEAN AddHeader(UINT8 header_id, UINT32 header_value);


        BOOLEAN AddHeader(UINT8 header_id, UINT8* header_value, UINT16 header_value_length);


        BOOLEAN AddHeader(UINT8 header_id, WString header_value);


        BOOLEAN DiscardHeaders();
        

        BOOLEAN GetFreeSize(UINT16 &bytes_free);

    protected:

        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);


//      BOOLEAN DataReady(btapi_goep_data_ready_t& api_data_ready);

    protected:

        virtual void RequestStateChangeCallback(BtServiceRequest* request, BtRequestState old_request_state, BtRequestState new_request_state);


        void UnregisterCallback(BtResultCode result);

#ifdef _DEBUG
    protected:

        virtual void DebugState();
#endif /* DEBUG */

private:

        void HeaderIndicationCallback(BtResultCode result, const BtObexHeader& obex_header);


        void HeaderSentIndicationCallback(BtResultCode result);


        void GetDataBufferIndicationCallback(BtResultCode result, UINT16 number_of_bytes, BOOLEAN delete_object, BOOLEAN create_empty);


        void GetDataIndicationCallback(BtResultCode result);


        void TransportDisconnectCallback(BtResultCode result);

    private:
        friend class BtObexRequest;
        friend class BtObexController;
};

#endif  // BtObexService_hpp


