/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceFilter_hpp)
#define BtDeviceFilter_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDeviceAndServiceClass.hpp>
#include <Bluetooth/BtDevice.hpp>

class BtDeviceFilter
{
    public:
        BtDeviceFilter();

        BtDeviceFilter(const BtDeviceFilter& device_filter);

        BtDeviceFilter(const BtDeviceAndServiceClass& device_and_service_class, BtDeviceState device_state = BtDsKnown);

        virtual ~BtDeviceFilter();


        BtDeviceAndServiceClass& GetDeviceAndServiceClass();


        const BtDeviceAndServiceClass& GetDeviceAndServiceClass() const;


        void SetDeviceAndServiceClass(const BtDeviceAndServiceClass& device_and_service_class);


        BtDeviceState GetDeviceState() const;


        void SetDeviceState(BtDeviceState device_state);


        virtual BOOLEAN Matches(const BtDevice& device) const;

    private:
        BtDeviceAndServiceClass m_device_and_service_class;

        BtDeviceState m_device_state;
};

#endif  // BtDeviceFilter_hpp


