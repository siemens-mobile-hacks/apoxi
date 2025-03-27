/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RootDirectoryIteratorImp_hpp)
#define Apoxi_RootDirectoryIteratorImp_hpp

#include <Afs/Rfs/DirectoryIterator.hpp>

class RootDirectoryIteratorImp : public DirectoryIterator
{
    public:
        explicit RootDirectoryIteratorImp(const Pathname &dir_pathname, 
            const FileFilterPtr &filter, 
            const StorageDeviceFilterPtr &dev_filter);

        virtual File::Error GetLastError() const;

        virtual void Increment();

    protected:
        virtual ~RootDirectoryIteratorImp();

        virtual DirectoryIterator& AtomicIncrement();

    private:
        inline void ConstructCurrentPathname();

        inline void ConstructCurrentDevicePathname();

        inline void SkipRootStorageDevice();

    protected:
        StorageDevicePtr m_cur_device;
        DirectoryIteratorPtr m_cur_dir_itor;
        Pathname m_cur_dev_pathname;

        StorageDeviceIteratorPtr m_dev_itor;
};

#endif  // Apoxi_RootDirectoryIteratorImp_hpp


