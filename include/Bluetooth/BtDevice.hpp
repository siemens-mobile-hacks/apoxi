/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDevice_hpp)
#define BtDevice_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDeviceAddress.hpp>
#include <Bluetooth/BtDeviceAndServiceClass.hpp>
#include <Auxiliary/WString.hpp>

class BtDevice
{
    public:
        BtDevice(const BtDeviceAddress& address = bt_c_empty_device_address);

        BtDevice(const BtDevice& device);

        virtual ~BtDevice();


        BtResultCode GetDeviceAddress(BtDeviceAddress& device_addres) const;


        BtResultCode GetDeviceName(WString& device_name) const;


        BtResultCode GetDeviceAndServiceClass(BtDeviceAndServiceClass& device_and_service_class) const;


        BtResultCode IsKnown(BOOLEAN& is_paired) const;


        BtResultCode IsPaired(BOOLEAN& is_paired) const;


        BtResultCode IsTrusted(BOOLEAN& is_trusted) const;


        BtResultCode IsConnected(BOOLEAN& is_connected) const;


        BOOLEAN operator==(const BtDevice& device) const;


        BOOLEAN operator!=(const BtDevice& device) const;

    protected:

        BOOLEAN GetRemoteDeviceInformation(btapi_known_device_t& remote_device_information) const;

    private:
        BtDeviceAddress m_device_address;

    private:
        friend class BtGapAndSdapController;
};

extern const BtDevice bt_c_unknown_device;

#endif  // BtDevice_hpp

