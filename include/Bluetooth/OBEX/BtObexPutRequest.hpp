/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexPutRequest_hpp)
#define BtObexPutRequest_hpp

#include <Bluetooth/OBEX/BtObexClientOperationRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexClientService;

class BtObexPutRequest: public BtObexClientOperationRequest
{
    private:
        typedef BtObexClientOperationRequest Base;

    public:
        BtObexPutRequest(BtObexClientService& obex_client_service);

        virtual ~BtObexPutRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN GetDeleteObject() const;


        void SetDeleteObject(BOOLEAN delete_object = TRUE);


        BOOLEAN GetCreateEmptyObject() const;


        void SetCreateEmptyObject(BOOLEAN create_empty = TRUE);

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

#endif  // BtObexPutRequest_hpp


