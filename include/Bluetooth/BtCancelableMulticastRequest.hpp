/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtCancelableMulticastRequest_hpp)
#define BtCancelableMulticastRequest_hpp

#include <Bluetooth/BtDeviceList.hpp>
#include <Bluetooth/BtCancelableRequest.hpp>

class BtCancelableMulticastRequest: public BtCancelableRequest
{
    private:
        typedef BtCancelableRequest Base;

    public:
        BtCancelableMulticastRequest(const BtDeviceList& device_list);

        virtual ~BtCancelableMulticastRequest();


        BtDeviceList& GetDeviceList();


        const BtDeviceList& GetDeviceList() const;


        void SetDeviceList(const BtDeviceList& device_list);

    private:
        BtDeviceList m_device_list;
};

#endif  // BtCancelableMulticastRequest_hpp


