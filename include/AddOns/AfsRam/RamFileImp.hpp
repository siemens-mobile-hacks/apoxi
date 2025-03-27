/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RamFileImp_hpp)
#define Apoxi_RamFileImp_hpp

#include <Afs/Rfs/File.hpp>
#include <AddOns/AfsRam/RamFile.hpp>

class RamFileImp : public File
{
    typedef File Base;

    friend class RamStorageDeviceImp;

    public:
        virtual BOOLEAN Open(OpenMode open_mode);
        virtual BOOLEAN OpenStreaming(OpenMode open_mode) {
            return FALSE;
        };
        virtual BOOLEAN IsOpen() const;
        virtual BOOLEAN Close();
        virtual BOOLEAN Create(UINT32 size);
        virtual BOOLEAN CreateStreaming() {
            return FALSE;
        };
        virtual BOOLEAN CreateDir();
        virtual BOOLEAN Resize(UINT32 new_size, UINT32 copy_buf_size);
        virtual BOOLEAN Delete();
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

    protected:
        RamFileImp(const Pathname &pathname);
        virtual ~RamFileImp();

        virtual BOOLEAN DoRead(void HUGE *buffer, UINT32 offset, UINT32 count);
        virtual BOOLEAN DoRead(void HUGE *buffer, UINT32 offset,
            UINT32 max_count, UINT32 &bytes_read);
        virtual BOOLEAN DoReadStreaming(void HUGE *buffer, UINT32 count,
            UINT32 &bytes_read){ 
                return FALSE;
            };
        virtual BOOLEAN DoReadStreamingAsync(void HUGE *buffer, UINT32 count,
            StreamingCallback) {
                return FALSE;
            };

        virtual BOOLEAN DoWrite(const void HUGE *buffer, UINT32 offset,
            UINT32 count);
        virtual BOOLEAN DoWriteStreaming(const void HUGE *buffer, UINT32 count) {
                return FALSE;
            };
        virtual BOOLEAN DoWriteStreamingAsync(const void HUGE *buffer, 
            UINT32 count, StreamingCallback) {
                return FALSE;
            };

        virtual FileState& MyState();
        virtual const FileState& MyState() const;

        static Error ConvertRamErrorToFileError(RamError ram_error);
        static RamOpenMode TranslateOpenMode(OpenMode open_mode);

    private:
        FileState m_state;
        RamFile m_ram_file;
};

#endif  // Apoxi_RamFileImp_hpp

