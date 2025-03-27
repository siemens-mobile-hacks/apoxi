/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexConnectRequest_hpp)
#define BtObexConnectRequest_hpp

#include <Bluetooth/OBEX/BtObexClientOperationRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexClientService;

class BtObexConnectRequest: public BtObexClientOperationRequest
{
    private:
        typedef BtObexClientOperationRequest Base;

    public:
        BtObexConnectRequest(BtObexClientService& obex_client_service);

        virtual ~BtObexConnectRequest();


        virtual BtRequestType GetRequestType() const;


        BtDevice GetTargetDevice() const;


        void SetTargetDevice(const BtDevice& target_device);


        UINT8 GetRfComPort() const;


        void SetRfComPort(UINT8 rfcom_port);

    protected:

        virtual BOOLEAN Execute();


        virtual void ExecutionCallback(BtResultCode result);

    private:

        btapi_goep_operation_t* GetApiSettings();

    private:
        btapi_goep_operation_t m_operation_settings;

    private:
        friend class BtObexController;
};

#endif  // BtObexConnectRequest_hpp


