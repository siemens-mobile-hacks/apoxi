/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StorageDeviceFilter_hpp)
#define Apoxi_StorageDeviceFilter_hpp

#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/WString.hpp>

class StorageDevice;
typedef NiSharedPtr<StorageDevice> StorageDevicePtr;

class StorageDeviceFilter
{
    public:
        virtual ~StorageDeviceFilter();

        virtual BOOLEAN Complies(const StorageDevicePtr &device) = 0;

    protected:
        StorageDeviceFilter();
};

class NamePatternStorageDeviceFilter : public StorageDeviceFilter
{
    public:
        NamePatternStorageDeviceFilter(const WString &name_pattern);

        virtual BOOLEAN Complies(const StorageDevicePtr &device);

    protected:
        virtual ~NamePatternStorageDeviceFilter();

    protected:
        WString m_name_pattern;
};

#endif  // Apoxi_StorageDeviceFilter_hpp


