/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FatStorageDeviceImp_hpp)
#define Apoxi_FatStorageDeviceImp_hpp

#include <Afs/Rfs/StorageDevice.hpp>
#include <AddOns/AfsFat/FatTypes.hpp>

class FatStorageDeviceImp : public StorageDevice
{
    typedef StorageDevice Base;

    friend class RootFileSystem;
    friend class FatFileImp;
    friend class FatFile;
    friend class FatDirectoryIteratorImp;

    public:
        virtual BOOLEAN GetMediaAvailableStatus(BOOLEAN &media_present) const;
        virtual UINT32 GetFreeVolumeSize() const;
        virtual UINT32 GetTotalVolumeSize() const;
        virtual UINT32 GetUsedVolumeSize() const;
        virtual BOOLEAN IsReady() const;
        virtual BOOLEAN IsDirectory(const Pathname &pathname) const;
        virtual BOOLEAN Exists(const Pathname &pathname) const;
        virtual BOOLEAN Flush();
        virtual BOOLEAN Format(BOOLEAN quick = FALSE);
        virtual WString GetNativeFilePathname(const Pathname &pathname) const;
        virtual WString GetNativeDirectoryPathname(const Pathname &pathname)
            const;
        virtual UINT8 GetDefaultChunkSize() const;

    private:
        struct FatFsDeviceDescriptor {
            FsDeviceType m_device_type;
            CHAR m_drive_letter;
            WString m_device_id;
            WString m_device_name;
            BOOLEAN m_removable_media;
            BOOLEAN m_media_available_notification;

            FatFsDeviceDescriptor(
                FsDeviceType device_type,
                CHAR drive_letter,
                const WString &device_id,
                const WString &device_name,
                BOOLEAN removable_media,
                BOOLEAN media_available_notification)
            :
                m_device_type(device_type),
                m_drive_letter(drive_letter),
                m_device_id(device_id),
                m_device_name(device_name),
                m_removable_media(removable_media),
                m_media_available_notification(media_available_notification)
            { }
        };

        static File::Error ConvertFatErrorToFileError(FatError fat_error);

        FatStorageDeviceImp(const FatFsDeviceDescriptor &device_desc);

        virtual ~FatStorageDeviceImp();

        virtual FilePtr CreateFileObject(const Pathname &pathname) const;
        virtual DirectoryIteratorPtr CreateDirectoryIterator(
            const Pathname &dir_pathname, const FileFilterPtr &filter) const;

        static BOOLEAN Setup();

        static BOOLEAN Setup(FsDeviceType device_type);

        virtual void OnNotifyMediaAvailableStatus(BOOLEAN media_present);

        virtual BOOLEAN Shutdown();

        BOOLEAN OnUsbMassStorageConnectEvent();

        const FatFsDeviceDescriptor &m_desc;

    private:
        friend class FatStorageDeviceImpInternals;

        WString GetNativeHelper(const Pathname &pathname) const;

        static BOOLEAN InitAndRegister(
            FsDeviceType device_type,
            CHAR drive_letter,
            BOOLEAN removable_media,
            BOOLEAN media_available_notification);
};

#endif  // Apoxi_FatStorageDeviceImp_hpp

