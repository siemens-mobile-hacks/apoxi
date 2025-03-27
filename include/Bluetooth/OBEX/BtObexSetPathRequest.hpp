/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexSetPathRequest_hpp)
#define BtObexSetPathRequest_hpp

#include <Bluetooth/OBEX/BtObexClientOperationRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexClientService;

class BtObexSetPathRequest: public BtObexClientOperationRequest
{
    private:
        typedef BtObexClientOperationRequest Base;

    public:
        BtObexSetPathRequest(BtObexClientService& obex_client_service);

        virtual ~BtObexSetPathRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN GetBackup() const;


        void SetBackup(BOOLEAN backup = TRUE);


        BOOLEAN GetCreateDirectory() const;


        void SetCreateDirectory(BOOLEAN create_directory = TRUE);

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

#endif  // BtObexSetPathRequest_hpp


