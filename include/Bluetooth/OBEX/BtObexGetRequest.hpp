/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexGetRequest_hpp)
#define BtObexGetRequest_hpp

#include <Bluetooth/OBEX/BtObexClientOperationRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexClientService;

class BtObexGetRequest: public BtObexClientOperationRequest
{
    private:
        typedef BtObexClientOperationRequest Base;

    public:
        BtObexGetRequest(BtObexClientService& obex_client_service);

        virtual ~BtObexGetRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


        virtual void ExecutionCallback(BtResultCode result);


        virtual BOOLEAN GetAcceptAbort() const;

    private:

        btapi_goep_operation_t* GetApiSettings();

    private:
        btapi_goep_operation_t m_operation_settings;

    private:
        friend class BtObexController;
};

#endif  // BtObexGetRequest_hpp


