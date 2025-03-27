/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtConnectRequest_hpp)
#define BtConnectRequest_hpp

#include <Bluetooth/BtServiceRequest.hpp>

/*  ------------------------------------------------------------------------
    Forward deklarations for friend relationships.
    ------------------------------------------------------------------------ */

class BtSingleConnectionController;

class BtConnectRequest: public BtServiceRequest
{
    private:
        typedef BtServiceRequest Base;

    public:
        BtConnectRequest(BtService& service);

        virtual ~BtConnectRequest();

    protected:

        virtual BOOLEAN Execute();


        virtual BOOLEAN PerformConnectControllerCall() = 0;

    protected:

        const btapi_connect_t* GetApiSettings() const;

    private:
        btapi_connect_t m_api_connect;

    private:
        friend class BtSingleConnectionController;
};

#endif  // BtConnectRequest_hpp


