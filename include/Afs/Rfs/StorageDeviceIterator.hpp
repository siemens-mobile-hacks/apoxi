/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StorageDeviceIterator_hpp)
#define Apoxi_StorageDeviceIterator_hpp

#include <Afs/Rfs/RootFileSystem.hpp>

class StorageDeviceVisitor;
class RootStorageDeviceIterator;

typedef NiSharedPtr<RootStorageDeviceIterator> RootStorageDeviceIteratorPtr;

class StorageDeviceIterator
{
    public:
        // Destroys a storage device iterator.
        ~StorageDeviceIterator();

        BOOLEAN IsValid() const;

        StorageDevicePtr GetStorageDevice() const;

        const WString& GetStorageDeviceId() const;

        void Increment();

        static BOOLEAN Accept(StorageDeviceVisitor &visitor);

    protected:
        explicit StorageDeviceIterator(const StorageDeviceFilterPtr &filter);

        StorageDeviceIterator& AtomicIncrement();

        friend class RootFileSystem;

    protected:
        StorageDeviceFilterPtr m_filter;

        SimpleMap<WString, StorageDevicePtr>::Iterator m_cur_device_id;
};



class RootStorageDeviceIterator : public StorageDeviceIterator {
    typedef StorageDeviceIterator Base;

    public:
         RootStorageDeviceIterator(const StorageDeviceFilterPtr &filter);

        // Destroys a root storage device iterator.
        ~RootStorageDeviceIterator();

        virtual BOOLEAN IsValid() const;

    protected:

        virtual StorageDeviceIterator& AtomicIncrement();

        friend class RootFileSystem;

};


#endif  // Apoxi_StorageDeviceIterator_hpp


