/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexServerService_hpp)
#define BtObexServerService_hpp

#include <Bluetooth/OBEX/BtObexServerServiceObserver.hpp>
#include <Bluetooth/OBEX/BtObexRegisterServerRequest.hpp>
#include <Bluetooth/OBEX/BtObexUnregisterServerRequest.hpp>
//#include <Bluetooth/OBEX/BtObexSendResponseRequest.hpp>
#include <Bluetooth/OBEX/BtObexService.hpp>
#include <Bluetooth/OBEX/BtObexController.hpp>

class BtObexServerService: public BtObexService
{
    private:
        typedef BtObexService Base;

    public:
        BtObexServerService();

        virtual ~BtObexServerService();


        virtual BtRequestState GetRequestState(BtRequestType request_type) const;


        virtual BOOLEAN IsServerService() const;


        virtual BtRequestState RegisterRequest(UINT8* header_buffer, UINT16 header_buffer_size, BtSecuritySettings security_settings = BtSesNoSecurity);


        virtual BtRequestState UnregisterRequest();


        BOOLEAN DataBufferIndication(UINT8* data_buffer, UINT16 data_buffer_size, UINT8 response_code = 0);


        BOOLEAN DataIndication(const UINT8* data, UINT16 data_size, BOOLEAN more_data_pending = FALSE, UINT8 response_code = 0);


        BOOLEAN SendResponse(UINT8 response_code);


        UINT8 GetRfComChannel() const;

    public:

        BOOLEAN Attach(BtObexServerServiceObserver* service_observer);


        BOOLEAN Detach(BtObexServerServiceObserver* service_observer);

#ifdef _DEBUG
    protected:

        virtual void DebugState();
#endif /* DEBUG */

    private:

        void RegisterCallback(BtResultCode result, UINT8 rfcom_channel);


        void ConnectCallback(BtResultCode result, const BtDevice& device);


        void DisconnectCallback(BtResultCode result);


        void SetPathCallback(BtResultCode result, BOOLEAN backup, BOOLEAN create);


        void GetCallback(BtResultCode result);


        void PutCallback(BtResultCode result);


        void AbortCallback(BtResultCode result);

    private:
        BtObexRegisterServerRequest m_register_server_request;

        BtObexUnregisterServerRequest m_unregister_server_request;

//      BtObexSendResponseRequest m_send_response_request;

    private:
        friend class BtObexRegisterServerRequest;
        friend class BtObexUnregisterServerRequest;
        friend class BtObexController;
};

#endif  // BtObexServerService_hpp


