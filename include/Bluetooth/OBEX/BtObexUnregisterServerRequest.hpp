/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtObexUnregisterServerRequest_hpp)
#define BtObexUnregisterServerRequest_hpp

#include <Bluetooth/OBEX/BtObexRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtObexServerService;

class BtObexUnregisterServerRequest: public BtObexRequest
{
    private:
        typedef BtObexRequest Base;

    public:
        BtObexUnregisterServerRequest(BtObexServerService& obex_server_service);

        virtual ~BtObexUnregisterServerRequest();


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

#endif  // BtObexUnregisterServerRequest_hpp


