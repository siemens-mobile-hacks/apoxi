/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexClientService_hpp)
#define BtObexClientService_hpp

#include <Bluetooth/OBEX/BtObexClientServiceObserver.hpp>
#include <Bluetooth/OBEX/BtObexRegisterClientRequest.hpp>
#include <Bluetooth/OBEX/BtObexUnregisterClientRequest.hpp>
#include <Bluetooth/OBEX/BtObexConnectRequest.hpp>
#include <Bluetooth/OBEX/BtObexDisconnectRequest.hpp>
#include <Bluetooth/OBEX/BtObexSetPathRequest.hpp>
#include <Bluetooth/OBEX/BtObexGetRequest.hpp>
#include <Bluetooth/OBEX/BtObexPutRequest.hpp>
#include <Bluetooth/OBEX/BtObexAbortRequest.hpp>
#include <Bluetooth/OBEX/BtObexService.hpp>

class BtObexClientService: public BtObexService
{
    private:
        typedef BtObexService Base;

    public:
        BtObexClientService();

        virtual ~BtObexClientService();


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual BOOLEAN IsServerService() const;


        BOOLEAN IsConnected() const;


        UINT8 GetRfComPort() const;


        void SetRfComPort(UINT8 rf_com_port);


        virtual BtRequestState RegisterRequest(UINT8* header_buffer, UINT16 header_buffer_size, BtSecuritySettings security_settings = BtSesNoSecurity);


        virtual BtRequestState UnregisterRequest();


        BtRequestState ConnectRequest();


        BtRequestState DisconnectRequest();


        BtRequestState SetPathRequest(BOOLEAN backup, BOOLEAN create);


        BtRequestState GetRequest();


        BtRequestState PutRequest(BOOLEAN delete_object, BOOLEAN create_empty_object);


        BtRequestState AbortRequest();


        BOOLEAN DataReadyIndication(const UINT8* data, UINT16 data_size, BOOLEAN more_data_pending = FALSE);


        BOOLEAN DataBufferIndication(UINT8* data_buffer, UINT16 data_buffer_size);

    public:

        BOOLEAN Attach(BtObexClientServiceObserver* service_observer);


        BOOLEAN Detach(BtObexClientServiceObserver* service_observer);

#ifdef _DEBUG
    protected:

        virtual void DebugState();
#endif /* DEBUG */

    private:

        void RegisterCallback(BtResultCode result);


        void ConnectCallback(BtResultCode result);


        void DisconnectCallback(BtResultCode result);


        void SetPathCallback(BtResultCode result);


        void GetCallback(BtResultCode result);


        void PutCallback(BtResultCode result);


        void AbortCallback(BtResultCode result);

    private:
        UINT8 m_rf_com_port;

        BtObexRegisterClientRequest m_register_client_request;

        BtObexUnregisterClientRequest m_unregister_client_request;

        BtObexConnectRequest m_connect_request;

        BtObexDisconnectRequest m_disconnect_request;

        BtObexSetPathRequest m_set_path_request;

        BtObexGetRequest m_get_request;

        BtObexPutRequest m_put_request;

        BtObexAbortRequest m_abort_request;

    private:
        friend class BtObexRegisterClientRequest;
        friend class BtObexUnregisterClientRequest;
        friend class BtObexConnectRequest;
        friend class BtObexDisconnectRequest;
        friend class BtObexSetPathRequest;
        friend class BtObexGetRequest;
        friend class BtObexPutRequest;
        friend class BtObexAbortRequest;
};

#endif  // BtObexClientService_hpp


