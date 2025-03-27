/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(BtOperationSelectDeviceAndPerformServiceVerify_hpp)
#define BtOperationSelectDeviceAndPerformServiceVerify_hpp

#include <Bluetooth/BtTypes.hpp>
#include <Bluetooth/BtDeviceFilter.hpp>
#include <Bluetooth/BtDevice.hpp>
#include <Bluetooth/BtServiceVerifyResult.hpp>
#include <Bluetooth/BtOperationBase.hpp>

class BtOperationSelectDeviceAndPerformServiceVerify: public BtOperationBase
{
    private:
        typedef BtOperationBase Base;

    public:
        BtOperationSelectDeviceAndPerformServiceVerify();

        virtual ~BtOperationSelectDeviceAndPerformServiceVerify();

    public:

        virtual BtOperationType GetOperationType() const;

    public:

        const BtDeviceFilter& GetDeviceFilter() const;


        void SetDeviceFilter(const BtDeviceFilter& device_filter);


        const BtDevice& GetDevice() const;


        void SetDevice(const BtDevice& device);


        BtDeviceRelation GetDeviceRelation() const;


        void SetDeviceReleation(BtDeviceRelation device_relation);


        UINT8 GetNumberOfServicesToVerify() const;


        const BtUUID* GetServiceToVerify() const;


        BOOLEAN SetServicesToVerify(const BtUUID* services_to_verify, UINT8 number_of_services_to_verify);


        UINT8 GetNumberOfAttributesRequested() const;


        const BtAttributeId* GetAttributesRequested() const;


        BOOLEAN SetAttributesRequested(const BtAttributeId* attributes_requested, UINT8 number_of_attributes_requested);


        const BtServiceVerifyResult& GetServiceVerifyResult() const;


        BOOLEAN SetServiceVerifyResult(const BtServiceVerifyResult& service_verify_result);

    private:
        BtDeviceFilter m_device_filter;

        BtDevice m_device;

        BtDeviceRelation m_device_relation;

        UINT8 m_number_of_services_to_verify;

        BtUUID* m_services_to_verify;

        UINT8 m_number_of_attributes_requested;

        BtAttributeId* m_attributes_requested;

        BtServiceVerifyResult m_service_verify_result;
};

#endif // BtOperationSelectDeviceAndPerformServiceVerify_hpp


