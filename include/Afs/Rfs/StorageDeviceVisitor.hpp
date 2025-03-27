/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StorageDeviceVisitor_hpp)
#define Apoxi_StorageDeviceVisitor_hpp

#include <Auxiliary/NiSharedPtr.hpp>

class StorageDevice;
class StorageDeviceFilter;

typedef NiSharedPtr<StorageDevice> StorageDevicePtr;
typedef NiSharedPtr<StorageDeviceFilter> StorageDeviceFilterPtr;

class StorageDeviceVisitor
{
    public:
        virtual ~StorageDeviceVisitor();

        virtual BOOLEAN Visit(const StorageDevicePtr &device) = 0;

        inline StorageDeviceFilterPtr GetIteratorFilter() const 
            { return m_filter; }

    protected:
        StorageDeviceVisitor(const StorageDeviceFilterPtr &filter);

    protected:
        StorageDeviceFilterPtr m_filter;
};

#endif  // Apoxi_StorageDeviceVisitor_hpp


