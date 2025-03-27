/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RootFileImp_hpp)
#define Apoxi_RootFileImp_hpp

#include <Afs/Rfs/File.hpp>

class RootFileImp : public File
{
    typedef File Base;

    friend class RootStorageDeviceImp;

    public:
        virtual BOOLEAN Open(OpenMode open_mode);
        virtual BOOLEAN OpenStreaming(OpenMode open_mode);
        virtual BOOLEAN IsOpen() const;
        virtual BOOLEAN Close();
        virtual BOOLEAN Create(UINT32 size);
        virtual BOOLEAN CreateStreaming();
        virtual BOOLEAN CreateDir();
        virtual BOOLEAN Resize(UINT32 new_size, UINT32 copy_buf_size);
        virtual BOOLEAN Delete();
        virtual BOOLEAN Copy(const Pathname &dest_pathname,
            const WString &dest_device_Id, UINT32 copy_buf_size);
        virtual BOOLEAN Split(UINT32 offset, const Pathname &new_file,
            UINT32 copy_buf_size);
        virtual BOOLEAN Rename(const WString &new_name);
        virtual BOOLEAN SetReadOnly(BOOLEAN read_only);
        virtual BOOLEAN IsReadOnly() const;
        virtual BOOLEAN SetHidden(BOOLEAN hidden);
        virtual BOOLEAN IsHidden() const;
        virtual BOOLEAN SetArchive(BOOLEAN archive);
        virtual BOOLEAN IsArchive() const;
        virtual BOOLEAN GetSize(UINT32 &size) const;
        virtual BOOLEAN GetAttributes(Attributes &attributes) const;
        virtual BOOLEAN GetCreationDate(Date &date) const;
        virtual BOOLEAN GetModificationDate(Date &date) const;
        virtual BOOLEAN GetAccessDate(Date &date) const;
        virtual const WString& GetStorageDeviceId() const;
        virtual BOOLEAN SetNativeProperty(UINT prop_Id, const void *val);
        virtual BOOLEAN GetNativeProperty(UINT prop_Id, void *val) const;

    protected:
        RootFileImp(const Pathname &pathname);
        virtual ~RootFileImp();

        virtual BOOLEAN DoRead(void HUGE *buffer, UINT32 offset, UINT32 count);
        virtual BOOLEAN DoRead(void HUGE *buffer, UINT32 offset,
            UINT32 max_count, UINT32 &bytes_read);
        virtual BOOLEAN DoReadStreaming(void HUGE *buffer, UINT32 count,
            UINT32 &bytes_read);
        virtual BOOLEAN DoReadStreamingAsync(void HUGE *buffer, UINT32 count,
            StreamingCallback);

        virtual BOOLEAN DoWrite(const void HUGE *buffer, UINT32 offset,
            UINT32 count);
        virtual BOOLEAN DoWriteStreaming(const void HUGE *buffer, UINT32 count);
        virtual BOOLEAN DoWriteStreamingAsync(const void HUGE *buffer, 
                                            UINT32 count, StreamingCallback);

        virtual FileState& MyState();
        virtual const FileState& MyState() const;

        inline BOOLEAN Delegate() const;

        inline StorageDevicePtr GetDevice() const;

    private:
        FilePtr m_file;
};

#endif  // Apoxi_RootFileImp_hpp

