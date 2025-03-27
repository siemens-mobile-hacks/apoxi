/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceUnpairRequest_hpp)
#define BtDeviceUnpairRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

class BtDeviceUnpairRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtDeviceUnpairRequest(const BtDevice& device);

        virtual ~BtDeviceUnpairRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);
};

#endif  // BtDeviceUnpairRequest_hpp


