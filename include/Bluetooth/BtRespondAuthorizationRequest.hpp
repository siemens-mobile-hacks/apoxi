/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtRespondAuthorizationRequest_hpp)
#define BtRespondAuthorizationRequest_hpp

#include <Bluetooth/BtRequestRespondRequest.hpp>

class BtRespondAuthorizationRequest: public BtRequestRespondRequest
{
    private:
        typedef BtRequestRespondRequest Base;

    public:
        BtRespondAuthorizationRequest(const BtDevice& device);

        virtual ~BtRespondAuthorizationRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN GetAcceptAuthorization() const;


        void SetAcceptAuthorization(BOOLEAN accept_authorization);


        BOOLEAN GetCreateTrust() const;


        void SetCreateTrust(BOOLEAN create_trust);

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);

    private:
        btapi_authorisation_rsp_t m_api_authorization_response;
};

#endif  // BtRespondAuthorizationRequest_hpp


