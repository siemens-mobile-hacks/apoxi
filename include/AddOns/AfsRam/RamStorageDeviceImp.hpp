/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RamStorageDeviceImp_hpp)
#define Apoxi_RamStorageDeviceImp_hpp

#include <Afs/Rfs/StorageDevice.hpp>

class RamStorageDeviceImp : public StorageDevice
{
    typedef StorageDevice Base;

    friend class RootFileSystem;

    public:
        virtual UINT32 GetFreeVolumeSize() const;
        virtual UINT32 GetTotalVolumeSize() const;
        virtual UINT32 GetUsedVolumeSize() const;
        virtual BOOLEAN IsReady() const;
        virtual BOOLEAN IsDirectory(const Pathname &pathname) const;
        virtual BOOLEAN Exists(const Pathname &pathname) const;
        virtual BOOLEAN Format(BOOLEAN quick = FALSE);
        virtual WString GetNativeFilePathname(const Pathname &pathname) const;
        virtual WString GetNativeDirectoryPathname(const Pathname &pathname)
            const;
        virtual UINT8 GetDefaultChunkSize() const;

        static const WString& GetId();

    protected:
        RamStorageDeviceImp();

        virtual ~RamStorageDeviceImp();

        virtual FilePtr CreateFileObject(const Pathname &pathname) const;
        virtual DirectoryIteratorPtr CreateDirectoryIterator(
            const Pathname &dir_pathname, const FileFilterPtr &filter) const;

        static BOOLEAN Setup();
};

#endif  // Apoxi_RamStorageDeviceImp_hpp


