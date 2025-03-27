/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexUnregisterClientRequest_hpp)
#define BtObexUnregisterClientRequest_hpp

#include <Bluetooth/OBEX/BtObexRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexClientService;

class BtObexUnregisterClientRequest: public BtObexRequest
{
    private:
        typedef BtObexRequest Base;

    public:
        BtObexUnregisterClientRequest(BtObexClientService& obex_client_service);

        virtual ~BtObexUnregisterClientRequest();


        virtual BtRequestType GetRequestType() const;


        btapi_goep_handle_t GetObexHandle(void) const;


        void SetObexHandle(btapi_goep_handle_t obex_handle);

    protected:

        virtual BOOLEAN Execute();


        virtual void ExecutionCallback(BtResultCode result);

    private:

        btapi_goep_handle_t GetApiSettings() const;

    private:
        btapi_goep_handle_t m_obex_handle;

    private:
        friend class BtObexController;
};

#endif  // BtObexUnregisterClientRequest_hpp


