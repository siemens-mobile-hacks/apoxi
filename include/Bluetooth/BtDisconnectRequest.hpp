/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDisconnectRequest_hpp)
#define BtDisconnectRequest_hpp

#include <Bluetooth/BtServiceRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtSingleConnectionController;

class BtDisconnectRequest: public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtDisconnectRequest(BtService& service);

        virtual ~BtDisconnectRequest();

    protected:

        virtual BOOLEAN Execute();


        virtual BOOLEAN PerformDisconnectControllerCall() = 0;

    private:

        const btapi_disconnect_t* GetApiSettings() const;

    private:
        btapi_disconnect_t m_api_disconnect;

    private:
        friend class BtSingleConnectionController;
};

#endif  // BtDisconnectRequest_hpp


