/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_StorageDevice_hpp)
#define Apoxi_StorageDevice_hpp

#include <Auxiliary/BitVector.hpp>
#include <Afs/Rfs/RootFileSystem.hpp>
#include <Afs/Rfs/File.hpp>

class StorageDevice
{
    public:
        enum DeviceCapability {
            DirectorySupport = 0,
            Removable = 1,
            ReadOnly = 2,
            ExchangeableMedia = 3,
            MediaAvailableStatusNotification = 4,
            DEVICE_CAPABILITY_COUNT = 5
        };

        enum ScanResult {
            ScanOk,

            ScanNotSupported,

            ScanProblemDetected,
            ScanRepairableProblemDetected,
            ScanNonRepairableProblemDetected,

            ScanProblemRepaired,

            ScanRepairFailed,

            ScanInternalError
        };

    protected:
        StorageDevice(const WString &device_Id, const WString &name);

    public:
        virtual ~StorageDevice();

        const WString& GetId() const
            { return m_device_Id; }

        const WString& GetName() const
            { return m_name; }

        virtual BOOLEAN SetMediaName(const WString &name);

        virtual BOOLEAN GetMediaName(WString &name) const;

        virtual BOOLEAN GetMediaAvailableStatus(BOOLEAN &media_present) const
            { return FALSE; }

        virtual UINT32 GetFreeVolumeSize() const = 0;

        virtual UINT32 GetTotalVolumeSize() const = 0;

        virtual UINT32 GetUsedVolumeSize() const = 0;

        virtual BOOLEAN GetSectorSize(UINT32 &size) const
            { return FALSE; }

        virtual BOOLEAN GetClusterSize(UINT32 &size) const
            { return FALSE; }

        virtual BOOLEAN IsReady() const = 0;

        BOOLEAN IsCapabilitySupported(DeviceCapability device_capability)
            const;

        virtual BOOLEAN IsDirectory(const Pathname &pathname) const = 0;

        virtual BOOLEAN Exists(const Pathname &pathname) const = 0;

        virtual BOOLEAN Flush();

        virtual BOOLEAN Format(BOOLEAN quick = FALSE) = 0;

        virtual ScanResult ScanDisk(BOOLEAN do_repair = FALSE)
            { return ScanNotSupported; }

        virtual File::Error GetLastError() const 
            { return m_last_error; }

        virtual WString GetNativeFilePathname(const Pathname &pathname) const
            = 0;

        virtual WString GetNativeDirectoryPathname(const Pathname &pathname)
            const = 0;

        virtual UINT8 GetDefaultChunkSize() const = 0;

        virtual BOOLEAN SetNativeProperty(UINT prop_id, const void *val)
            { return FALSE; }

        virtual BOOLEAN GetNativeProperty(UINT prop_id, void *val) const
            { return FALSE; }

        virtual BOOLEAN GetOpenFilesCounter(UINT &counter) const;

    protected:
        static BOOLEAN Register(StorageDevicePtr device);

        void SetDeviceCapability(DeviceCapability device_capability,
            BOOLEAN value);

        virtual void OnNotifyMediaAvailableStatus(BOOLEAN media_present)
            { }

        void NotifyMediaAvailableStatus(BOOLEAN media_present);

        virtual FilePtr CreateFileObject(const Pathname &pathname) const = 0;

        virtual DirectoryIteratorPtr CreateDirectoryIterator(
            const Pathname &dir_pathname, const FileFilterPtr &filter) const
            = 0;

        virtual BOOLEAN Shutdown();

        void IncrementOpenFileCounter() {
            ++m_open_file_counter;
        }

        void DecrementOpenFileCounter() {
            --m_open_file_counter;
        }

        friend class RootFileSystem;
        friend class File;

        // The last error returned by the driver
        mutable File::Error m_last_error;

    private:
        const WString &m_device_Id;
        const WString &m_name;

        UINT m_open_file_counter;

        BitVector<DEVICE_CAPABILITY_COUNT> m_device_capabilities;
};

#endif  // Apoxi_StorageDevice_hpp

