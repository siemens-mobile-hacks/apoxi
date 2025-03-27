/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RootFileSystem_hpp)
#define Apoxi_RootFileSystem_hpp



#include <Afs/Rfs/RfsConfig.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/SimpleMap.hpp>
#include <Auxiliary/WString.hpp>

class StorageDevice;
class Pathname;
class File;
class DirectoryIterator;
class Path;
class StorageDeviceIterator;
class FileFilter;
class StorageDeviceFilter;

typedef NiSharedPtr<StorageDevice> StorageDevicePtr;
typedef NiSharedPtr<File> FilePtr;
typedef NiSharedPtr<DirectoryIterator> DirectoryIteratorPtr;
typedef NiSharedPtr<StorageDeviceIterator> StorageDeviceIteratorPtr;
typedef NiSharedPtr<FileFilter> FileFilterPtr;
typedef NiSharedPtr<StorageDeviceFilter> StorageDeviceFilterPtr;

class RootFileSystem
{
    public:
        enum {
            MAX_STORAGE_DEVICE_ID_LENGTH =
                APOXI_MAX_NET_STORAGE_DEVICE_ID_LENGTH + 1
        };

    public:
        static FilePtr GetFile(const Pathname &pathname,
            const WString &device_Id = L"rfs");

        static FilePtr GetFile(const Path &path);

        static BOOLEAN Exists(const Pathname &pathname,
            const WString &device_Id = L"rfs");

        static BOOLEAN Exists(const Path &path);

        static BOOLEAN IsDirectory(const Pathname &pathname,
            const WString &device_Id = L"rfs");

        static BOOLEAN IsDirectory(const Path &path);

        static BOOLEAN MoveFile(const Pathname &from_file_pathname,
            const Pathname &to_pathname,
            const WString &from_device_Id = L"rfs",
            const WString &to_device_Id = L"rfs");

        static BOOLEAN MoveFile(const Path &from_file_path,
            const Path &to_path);

        static BOOLEAN DeleteFile(const Pathname &file_pathname,
            const WString &device_Id = L"rfs");

        static BOOLEAN DeleteFile(const Path &filepath);

        //
        // Iterator Operations
        //

        static DirectoryIteratorPtr GetDirectoryIterator(
            const Pathname &dir_pathname, const FileFilterPtr &filter,
            const WString &device_Id = L"rfs");

        static DirectoryIteratorPtr GetDirectoryIterator(const Path &filepath,
            const FileFilterPtr &filter);

        static StorageDeviceIteratorPtr GetStorageDeviceIterator(
            const StorageDeviceFilterPtr &filter);

        //
        // Storage Device Operations
        //

        static StorageDevicePtr GetStorageDevice(const WString &device_Id);

        static UINT GetStorageDeviceCount()
            { return m_storage_devices.GetSize(); }

        static FilePtr CreateTempFile(const Pathname &base_pathname,
            UINT32 size, const WString &device_Id = L"rfs");

        static FilePtr CreateTempFile(const Path &base_path, UINT32 size);

    protected:
        static BOOLEAN RegisterStorageDevice(StorageDevicePtr device);

        static BOOLEAN UnregisterStorageDevice(StorageDevicePtr device);

        static void NotifyMediaAvailableStatus(const StorageDevice &device,
            BOOLEAN media_present);

        friend class StorageDevice;

    private:
        RootFileSystem();
        ~RootFileSystem();

        static SimpleMap<WString, StorageDevicePtr> m_storage_devices;

        static BOOLEAN SetupPermanentStorageDevices();
        static BOOLEAN s_initializer_helper;

        friend class StorageDeviceIterator;
};

#endif  // Apoxi_RootFileSystem_hpp

