/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtOperationSelectDevice_hpp)
#define BtOperationSelectDevice_hpp

#include <Bluetooth/BtDeviceFilter.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtOperationBase.hpp>

class BtOperationSelectDevice: public BtOperationBase
{
    private:
        typedef BtOperationBase Base;

    public:
        BtOperationSelectDevice(const BtDeviceFilter& device_filter = BtDeviceFilter());

        virtual ~BtOperationSelectDevice();

    public:

        virtual BtOperationType GetOperationType() const;

    public:

        void SetDeviceFilter(const BtDeviceFilter& device_filter);


        const BtDeviceFilter& GetDeviceFilter() const;


        void SetDevice(const BtDevice& device);


        const BtDevice& GetDevice() const;

    private:
        BtDeviceFilter m_device_filter;

        BtDevice m_device;
};

#endif // BtOperationSelectDevice_hpp


