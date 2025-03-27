/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtDeviceAndServiceClass_hpp)
#define BtDeviceAndServiceClass_hpp


class BtDeviceAndServiceClass
{
    public:
        BtDeviceAndServiceClass();

        BtDeviceAndServiceClass(const BtDeviceAndServiceClass& device_and_service_class);

        BtDeviceAndServiceClass(ULONG device_and_service_class);

        virtual ~BtDeviceAndServiceClass();


        UINT8 GetMajorDeviceClass() const;


        void SetMajorDeviceClass(UINT8 major_device_class);


        UINT8 GetMinorDeviceClass() const;


        void SetMinorDeviceClass(UINT8 minor_device_class);


        UINT16 GetServiceClass() const;


        void SetServiceClass(UINT16 service_class);


        BtDeviceAndServiceClass& operator=(const BtDeviceAndServiceClass& device_and_service_class);


        BOOLEAN operator==(const BtDeviceAndServiceClass& device_and_service_class) const;


        BOOLEAN operator!=(const BtDeviceAndServiceClass& device_and_service_class) const;

    private:
        ULONG m_device_and_service_class;
};

#endif  // BtDeviceAndServiceClass_hpp

