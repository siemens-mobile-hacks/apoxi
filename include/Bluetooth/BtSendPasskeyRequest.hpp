/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtSendPasskeyRequest_hpp)
#define BtSendPasskeyRequest_hpp

#include <Bluetooth/BtRequestRespondRequest.hpp>

class BtSendPasskeyRequest: public BtRequestRespondRequest
{
    private:
        typedef BtRequestRespondRequest Base;

    public:
        BtSendPasskeyRequest(const BtDevice& device);

        virtual ~BtSendPasskeyRequest();


        virtual BtRequestType GetRequestType() const;


        BOOLEAN GetAcceptPairing() const;


        void SetAcceptPairing(BOOLEAN accept_pairing);


        const WString& GetPinCode() const;


        void SetPinCode(const WString& pin_code);

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);

    private:
        WString m_pin_code;

        btapi_passkey_rsp_t m_api_passkey_response;
};

#endif  // BtSendPasskeyRequest_hpp


