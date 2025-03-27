/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtUncancelablePointToPointRequest_hpp)
#define BtUncancelablePointToPointRequest_hpp

#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtUncancelableRequest.hpp>

class BtUncancelablePointToPointRequest: public BtUncancelableRequest
{
    private:
        typedef BtUncancelableRequest Base;

    public:
        BtUncancelablePointToPointRequest(const BtDevice& device);

        virtual ~BtUncancelablePointToPointRequest();


        BtDevice& GetDevice();


        const BtDevice& GetDevice() const;


        void SetDevice(const BtDevice& device);

    private:
        BtDevice m_device;
};

#endif  // BtUncancelablePointToPointRequest_hpp


