/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG. 
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceAddress_hpp)
#define BtDeviceAddress_hpp

#include <stack/extensions.h>
#include <Auxiliary/WString.hpp>

class BtDeviceAddress
{
    public:
        BtDeviceAddress();

        BtDeviceAddress(const BtDeviceAddress& device_address);

        BtDeviceAddress(const btapi_bdaddr_t& api_device_address);

        BtDeviceAddress(const char* pc_device_address);

        ~BtDeviceAddress();


        BtDeviceAddress& operator=(const BtDeviceAddress& device_address);


        BOOLEAN operator==(const BtDeviceAddress& device_address) const;


        BOOLEAN operator!=(const BtDeviceAddress& device_address) const;


        WString& AsString(WString& string) const;


        const btapi_bdaddr_t& GetApiDeviceAddress() const;


        void SetApiDeviceAddress(const btapi_bdaddr_t& api_devcie_address);


        void SetStringDeviceAddress(const char* pc_device_address);

    private:
        btapi_bdaddr_t m_device_address;
};

/*  ------------------------------------------------------------------------
    constant declartion
    ------------------------------------------------------------------------ */

extern const BtDeviceAddress bt_c_empty_device_address;

#endif // BtDeviceAddress_hpp

