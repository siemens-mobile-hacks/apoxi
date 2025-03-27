/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceUntrustRequest_hpp)
#define BtDeviceUntrustRequest_hpp

#include <Bluetooth/BtUncancelablePointToPointRequest.hpp>

class BtDeviceUntrustRequest: public BtUncancelablePointToPointRequest
{
    private:
        typedef BtUncancelablePointToPointRequest Base;

    public:
        BtDeviceUntrustRequest(const BtDevice& device);

        virtual ~BtDeviceUntrustRequest();


        virtual BtRequestType GetRequestType() const;

    protected:

        virtual BOOLEAN Execute();


        virtual void RegisterMessages() const;


        virtual void UnregisterMessages() const;


        virtual BOOLEAN OnMessage(const Message& message);
};

#endif  // BtDeviceUntrustRequest_hpp


