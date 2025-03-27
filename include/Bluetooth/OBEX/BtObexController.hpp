/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexController_hpp)
#define BtObexController_hpp

#include <stack/extensions.h>
#include <Bluetooth/BtMultiConnectionController.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexService;
class BtObexServerService;
class BtObexClientService;
class BtObexRegisterServerRequest;
class BtObexUnregisterServerRequest;
class BtObexSendResponseRequest;
class BtObexRegisterClientRequest;
class BtObexUnregisterClientRequest;
class BtObexConnectRequest;
class BtObexDisconnectRequest;
class BtObexSetPathRequest;
class BtObexGetRequest;
class BtObexPutRequest;
class BtObexAbortRequest;

class BtObexController: public BtMultiConnectionController
{
    private:
        typedef BtMultiConnectionController Base;

    public:

        static BtObexController& GetInstance();

    public:
        virtual ~BtObexController();


        virtual const WCHAR* GetName() const;

    protected:

        BOOLEAN ObexRegisterServerRequest(BtObexRegisterServerRequest* register_request);


        BOOLEAN ObexUnregisterServerRequest(BtObexUnregisterServerRequest* unregister_request);

//      ///
//      /**
//      */
//      BOOLEAN ObexSendResponseRequest(BtObexSendResponseRequest* send_response_request);


        BOOLEAN ObexRegisterClientRequest(BtObexRegisterClientRequest* register_request);


        BOOLEAN ObexUnregisterClientRequest(BtObexUnregisterClientRequest* unregister_request);


        BOOLEAN ObexConnectRequest(BtObexConnectRequest* connect_request);


        BOOLEAN ObexDisconnectRequest(BtObexDisconnectRequest* disconnect_request);


        BOOLEAN ObexSetPathRequest(BtObexSetPathRequest* set_path_request);


        BOOLEAN ObexGetRequest(BtObexGetRequest* get_request);


        BOOLEAN ObexPutRequest(BtObexPutRequest* put_request);


        BOOLEAN ObexAbortRequest(BtObexAbortRequest* abort_request);


        BOOLEAN ObexAddHeader(const BtObexService* obex_service, UINT8 header_id, UINT8 header_value);


        BOOLEAN ObexAddHeader(const BtObexService* obex_service, UINT8 header_id, UINT32 header_value);


        BOOLEAN ObexAddHeader(const BtObexService* obex_service, UINT8 header_id, UINT8* header_value, UINT16 header_value_length);


        BOOLEAN ObexAddHeader(const BtObexService* obex_service, UINT8 header_id, WString header_value);


        BOOLEAN ObexDiscardHeaders(const BtObexService* obex_service);


        BOOLEAN ObexGetFreeSize(const BtObexService* obex_service, UINT16 &bytes_free);


        BOOLEAN ObexSendResponse(const BtObexService* obex_service, UINT8 response_code);


        BOOLEAN ObexDataBufferIndication(const BtObexService* obex_service, UINT8* data_buffer, UINT16 data_buffer_size, UINT8 response_code);


        BOOLEAN ObexDataIndication(const BtObexService* obex_service, const UINT8* data, UINT16 data_size, BOOLEAN more_data_pending, UINT8 response_code);

    private:
        /*---------------------------------------------------------------------*/
        /* The following functions must not be called by an application.       */
        /* They are the entry point from the stack callback functions into our */
        /* object orientated framework (APOXI).                                */
        /* They are implemented as static because they have to be passed as    */
        /* normal C function pointers. The reason for this is the BT-API Stack */
        /* interface that demands C function pointers for callback the         */
        /* callback functions it calls to state the progress of ongoing        */
        /* operations                                                          */
        /*---------------------------------------------------------------------*/


        static void OnObexErrorCallback(btapi_result_t result, const btapi_goep_error_t* error);


        void OnObexError(BtResultCode result, const btapi_goep_error_t* error);


        static void OnObexRegisterCallback(btapi_result_t result, const btapi_goep_register_t* registration_info);


        void OnObexRegister(BtResultCode result, const btapi_goep_register_t* registration_info);


        static void OnObexGetDataCallback(btapi_result_t result, void* apoxi_handle);


        void OnObexGetData(BtResultCode result, void* apoxi_handle);


        static void OnObexHeaderInidicationCallback(btapi_result_t result, const btapi_goep_header_ind_t* header_indication);


        void OnObexHeaderInidication(BtResultCode result, const btapi_goep_header_ind_t* header_indication);


        static void OnObexHeaderSentCallback(btapi_result_t result, void* apoxi_handle);


        void OnObexHeaderSent(BtResultCode result, void* apoxi_handle);


        static void OnObexResponseIndicationCallback(btapi_result_t result, const btapi_goep_rsp_t* response_indication);


        void OnObexResponseIndication(BtResultCode result, const btapi_goep_rsp_t* response_indication);


        static void OnObexGetBufferCallback(btapi_result_t result, const btapi_goep_getbuffer_t* get_buffer_description);


        void OnObexGetBuffer(BtResultCode result, const btapi_goep_getbuffer_t* get_buffer_description);


        static void OnObexOperationIndicationCallback(btapi_result_t result, const btapi_goep_operation_ind_t* operation_indication);


        void OnObexOperationIndication(BtResultCode result, const btapi_goep_operation_ind_t* operation_indication);


        static void OnObexTransportDisconnectCallback(btapi_result_t result, void* apoxi_handle);


        void OnObexTransportDisconnect(BtResultCode result, void* apoxi_handle);

    private:
        BtObexController();


        virtual void Register();


        virtual void Unregister();


        BOOLEAN PrepareAbortRequestExecution(void* apoxi_handle, BtObexAbortRequest* request);


        BtObexAbortRequest* CleanUpAbortRequestExecution(void* apoxi_handle, BtResultCode result_code);

    protected:
        class BtObexConnection: public BtMultiConnectionController::BtConnection
        {
            private:
                typedef BtMultiConnectionController::BtConnection Base;

            public:
                BtObexConnection();

                virtual ~BtObexConnection();


                btapi_goep_handle_t GetObexHandle() const;


                void SetObexHandle(btapi_goep_handle_t obex_handle);


                BOOLEAN GetIsServer() const;


                void SetIsServer(BOOLEAN is_server);


                BtObexAbortRequest* GetRunningAbortRequest() const;


                void SetRunningAbortRequest(BtObexAbortRequest* request);

            private:
                btapi_goep_handle_t m_obex_handle;

                BOOLEAN m_is_server;

                BtObexAbortRequest* m_abort_request;
        };

    private:

        BtObexConnection* FindConnectionByObexHandle(btapi_goep_handle_t obex_handle) const;


        btapi_goep_handle_t GetObexHandle(const void* apoxi_handle);

#ifdef _DEBUG
    private:

        void DebugState();
#endif /* _DEBUG */

    private:
        btapi_goepcb_funp_t* m_obex_callback_functions;

    private:
        static BtObexController m_controller;

    private:
        friend class BtObexService;
        friend class BtObexServerService;
        friend class BtObexClientService;
        friend class BtObexRegisterServerRequest;
        friend class BtObexUnregisterServerRequest;
        friend class BtObexSendResponseRequest;
        friend class BtObexRegisterClientRequest;
        friend class BtObexUnregisterClientRequest;
        friend class BtObexConnectRequest;
        friend class BtObexDisconnectRequest;
        friend class BtObexSetPathRequest;
        friend class BtObexGetRequest;
        friend class BtObexPutRequest;
        friend class BtObexAbortRequest;
};

#endif  // BtObexController_hpp

