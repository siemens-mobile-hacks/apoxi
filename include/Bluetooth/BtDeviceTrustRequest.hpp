/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceTrustRequest_hpp)
#define BtDeviceTrustRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

class BtDeviceTrustRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtDeviceTrustRequest(const BtDevice& device);

        virtual ~BtDeviceTrustRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);
};

#endif  // BtDeviceTrustRequest_hpp


