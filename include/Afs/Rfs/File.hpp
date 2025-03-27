/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_File_hpp)
#define Apoxi_File_hpp

#include <Afs/Rfs/RootFileSystem.hpp>
#include <Afs/Rfs/Path.hpp>
#include <Auxiliary/BitVector.hpp>
#include <Auxiliary/Date.hpp>
#include <Auxiliary/Time.hpp>

class FileVisitor;
class FileChunkOperator;

class File
{
    public:
        enum Error {
            NoError,
            OperationFailedError,
            AccessDeniedError,
            AlreadyOpenError,
            OpeningError,
            OperationNotAllowedError,
            OperationCancelledError,
            NotOpenError,
            NotFoundError,
            AlreadyExistsError,
            InitializingError,
            IllegalModeError,
            RangeError,
            WriteError,
            BadFileError,
            SharingError,
            DeviceError,
            FatalError,
            MemoryError,
            TooManyFilesError,
            OutOfMemoryError,
            InvalidFileNameError,
            InternalError,
            TempFileCreationError,
            IllegalIdError,
            IllegalTypeError,
            IllegalUserIdError,
            StreamingError,
            StaticFileError,
            InconsistentMemTablesError,
            NoFactoryDefaultFileError,
            MemNotAvailableError,
            BadFormatError,
            IOError,
            UnknownError,

            // Error codes specific for directory operations.
            IllegalDirOperationError,
            DirSpaceNotAvailableError,

            EndOfDirectoryError,
            
            // Error codes specific for files on removable medias.
            NoMediaError,
            BadMediaError,
            ChangedMediaError,
            MediaFailureError,
            EccError
        };

        enum OpenMode {
            ReadOnlyMode,
            ReadAndWriteMode
        };

        enum SeekOrigin {
            SeekSet, 
            SeekCur, 
            SeekEnd  
        };

        enum {
            c_copy_buf_size = 10 * 1024 // 10 KB.
        };

        class Attributes {
        public:
            enum Type {
                Directory = 0,
                ReadOnly,
                Hidden,
                Size,
                CreationDate,
                CreationTime,
                ModificationDate,
                ModificationTime,
                AccessDate,
                AccessTime,
                Archive
            };

        private:
            // Enumeration to control all BOOLEAN attribute values in one bit
            // vector.
            enum BoolAttrib {
                BoolDirectory = 0,
                BoolReadOnly,
                BoolHidden,
                BoolArchive
            };

            // Tells whether an attribute is defined.
            BitVector<Archive + 1> m_defined;

            // Stores all BOOLEAN attribute values in one bit vector.
            BitVector<BoolArchive + 1> m_bool_attribs;

            // All non-BOOLEAN attribute values.
            UINT32 m_size;
            Date m_creation_date;
            Time m_creation_time;
            Date m_modification_date;
            Time m_modification_time;
            Date m_access_date;
            Time m_access_time;

        public:
            BOOLEAN IsDefined(Type attribute) const {
                return m_defined.GetBit(attribute);
            }

            BOOLEAN IsDirectory() const {
                ASSERT_DEBUG(IsDefined(Directory));
                return m_bool_attribs.GetBit(BoolDirectory);
            }

            BOOLEAN IsReadOnly() const {
                ASSERT_DEBUG(IsDefined(ReadOnly));
                return m_bool_attribs.GetBit(BoolReadOnly);
            }

            BOOLEAN IsHidden() const {
                ASSERT_DEBUG(IsDefined(Hidden));
                return m_bool_attribs.GetBit(BoolHidden);
            }
            
            BOOLEAN IsArchive() const {
                ASSERT_DEBUG(IsDefined(Archive));
                return m_bool_attribs.GetBit(BoolArchive);
            }

            UINT32 GetSize() const {
                ASSERT_DEBUG(IsDefined(Size));
                return m_size;
            }

            Date GetCreationDate() const {
                ASSERT_DEBUG(IsDefined(CreationDate));
                return m_creation_date;
            }

            Time GetCreationTime() const {
                ASSERT_DEBUG(IsDefined(CreationTime));
                return m_creation_time;
            }

            Date GetModificationDate() const {
                ASSERT_DEBUG(IsDefined(ModificationDate));
                return m_modification_date;
            }

            Time GetModificationTime() const {
                ASSERT_DEBUG(IsDefined(ModificationTime));
                return m_modification_time;
            }

            Date GetAccessDate() const {
                ASSERT_DEBUG(IsDefined(AccessDate));
                return m_access_date;
            }

            Time GetAccessTime() const {
                ASSERT_DEBUG(IsDefined(AccessTime));
                return m_access_time;
            }

            void SetDirectory(BOOLEAN status = TRUE) {
                m_defined.SetBit(Directory);
                m_bool_attribs.SetBit(BoolDirectory, status);
            }

            void SetReadOnly(BOOLEAN status = TRUE) {
                m_defined.SetBit(ReadOnly);
                m_bool_attribs.SetBit(BoolReadOnly, status);
            }

            void SetHidden(BOOLEAN status = TRUE) {
                m_defined.SetBit(Hidden);
                m_bool_attribs.SetBit(BoolHidden, status);
            }
            
            void SetArchive(BOOLEAN status = TRUE) {
                m_defined.SetBit(Archive);
                m_bool_attribs.SetBit(BoolArchive, status);
            }

            void SetSize(UINT32 size) {
                m_defined.SetBit(Size);
                m_size = size;
            }

            void SetCreationDate(const Date &date) {
                m_defined.SetBit(CreationDate);
                m_creation_date = date;
            }

            void SetCreationTime(const Time &time) {
                m_defined.SetBit(CreationTime);
                m_creation_time = time;
            }

            void SetModificationDate(const Date &date) {
                m_defined.SetBit(ModificationDate);
                m_modification_date = date;
            }

            void SetModificationTime(const Time &time) {
                m_defined.SetBit(ModificationTime);
                m_modification_time = time;
            }

            void SetAccessDate(const Date &date) {
                m_defined.SetBit(AccessDate);
                m_access_date = date;
            }

            void SetAccessTime(const Time &time) {
                m_defined.SetBit(AccessTime);
                m_access_time = time;
            }
        };

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER >= 1300))
    // VC6 compiler has a problem with this protected keyword.
    protected:
#endif

        struct FileState {
            OpenMode m_open_mode;
            BOOLEAN m_temporary;
            UINT32 m_cur_file_pos;
            UINT8 m_chunk_size;
            BOOLEAN m_send_progress_messages;
            FileChunkOperator *m_chunk_operator;
            mutable Error m_last_error;

            FileState() :
                m_open_mode(ReadOnlyMode),
                m_temporary(FALSE),
                m_cur_file_pos(0),
                m_chunk_size(0),
                m_send_progress_messages(FALSE),
                m_chunk_operator(0),
                m_last_error(NoError)
            {}
        };

    protected:
        File(const Pathname &pathname, const WString &device_Id);

    public:
            typedef void (*StreamingCallback)(File::Error result, UINT32 bytes_operated);

    
        virtual ~File();

        virtual BOOLEAN Open(OpenMode open_mode) = 0;

        virtual BOOLEAN OpenStreaming(OpenMode open_mode) = 0;

        BOOLEAN IsOpenInMode(OpenMode open_mode) const;

        virtual BOOLEAN IsOpen() const = 0;

        virtual BOOLEAN Close() = 0;

        virtual BOOLEAN Create(UINT32 size) = 0;
        
        virtual BOOLEAN CreateStreaming() = 0;

        virtual BOOLEAN CreateDir() = 0;

        virtual BOOLEAN Resize(UINT32 new_size,
            UINT32 copy_buf_size = c_copy_buf_size);

        virtual BOOLEAN Delete() = 0;

        virtual BOOLEAN Move(const Pathname &dest_pathname);

        BOOLEAN Copy(const Path &dest_path,
            UINT32 copy_buf_size = c_copy_buf_size);

        virtual BOOLEAN Copy(const Pathname &dest_pathname,
            const WString &dest_device_Id = L"rfs",
            UINT32 copy_buf_size = c_copy_buf_size);

        virtual BOOLEAN Split(UINT32 offset, const Pathname &new_file,
            UINT32 copy_buf_size = c_copy_buf_size);

        virtual BOOLEAN Rename(const WString &new_name) = 0;

        BOOLEAN Exists() const;

        virtual BOOLEAN SetReadOnly(BOOLEAN read_only) = 0;

        virtual BOOLEAN IsReadOnly() const = 0;

        virtual BOOLEAN SetHidden(BOOLEAN hidden) = 0;

        virtual BOOLEAN IsHidden() const = 0;
        
        virtual BOOLEAN SetArchive(BOOLEAN archive) = 0;

        virtual BOOLEAN IsArchive() const = 0;

        BOOLEAN IsDirectory() const;

        const Pathname& GetPathname() const;

        const Path& GetPath() const;

        virtual BOOLEAN GetSize(UINT32 &size) const = 0;

        WString GetName() const;

        virtual BOOLEAN GetAttributes(Attributes &attributes) const
            { return FALSE; }

        virtual BOOLEAN GetCreationDate(Date &date) const = 0;

        virtual BOOLEAN GetModificationDate(Date &date) const = 0;

        virtual BOOLEAN GetAccessDate(Date &date) const
        {
            MyState().m_last_error = OperationNotAllowedError;
            return FALSE;
        }

        BOOLEAN Seek(INT32 offset, SeekOrigin origin);

        UINT32 Tell();

        BOOLEAN ReadCur(void HUGE *buffer, UINT32 count);

        BOOLEAN ReadCur(void HUGE *buffer, UINT32 max_count,
            UINT32 &bytes_read);

        BOOLEAN WriteCur(const void HUGE *buffer, UINT32 count);

        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 count);

        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 max_count,
            UINT32 &bytes_read);
            
        BOOLEAN ReadStreaming(void HUGE *buffer, UINT32 count,
            UINT32 &bytes_read);

        BOOLEAN ReadStreamingAsync(void HUGE *buffer, UINT32 count,
            StreamingCallback);

        BOOLEAN Write(const void HUGE *buffer, UINT32 offset, UINT32 count);
        
        BOOLEAN WriteStreaming(const void HUGE *buffer, UINT32 count);

        BOOLEAN WriteStreamingAsync(const void HUGE *buffer, UINT32 count,
            StreamingCallback callback_func);

        BOOLEAN Accept(FileVisitor &visitor);

        BOOLEAN IsTemporary() const
            { return MyState().m_temporary; }

        void MakePermanent();

        virtual const WString& GetStorageDeviceId() const = 0;

        const StorageDevicePtr GetStorageDevice() const;

        WString GetNativeFilePathname() const;

        WString GetNativeDirectoryPathname() const;

        UINT8 GetChunkSize() const;

        void SetChunkSize(UINT8 size, BOOLEAN send_progress_messages = FALSE);

        BOOLEAN CancelOperation();

        Error GetLastError() const;

        virtual BOOLEAN SetNativeProperty(UINT prop_Id, const void *val)
            { return FALSE; }

        virtual BOOLEAN GetNativeProperty(UINT prop_Id, void *val) const
            { return FALSE; }

    protected:
        friend class FileChunkOperator;

        virtual BOOLEAN DoRead(void HUGE *buffer, UINT32 offset, UINT32 count)
            = 0;

        virtual BOOLEAN DoRead(void HUGE *buffer, UINT32 offset,
            UINT32 max_count, UINT32 &bytes_read) = 0;

        virtual BOOLEAN DoWrite(const void HUGE *buffer, UINT32 offset,
            UINT32 count) = 0;

        virtual BOOLEAN DoReadStreaming(void HUGE *buffer, UINT32 count,
            UINT32 &bytes_read) = 0;

        virtual BOOLEAN DoReadStreamingAsync(void HUGE *buffer, UINT32 count,
            StreamingCallback) = 0;

        virtual BOOLEAN DoWriteStreaming(const void HUGE *buffer, UINT32 count) = 0;

        virtual BOOLEAN DoWriteStreamingAsync(const void HUGE *buffer, UINT32 count,
            StreamingCallback) = 0;

        BOOLEAN CopyContentsTo(const FilePtr &dest_file, UINT32 copy_buf_size);

        void SetTemporary();

        virtual FileState& MyState() = 0;

        virtual const FileState& MyState() const = 0;

        BOOLEAN PrepareRename(const WString &new_name, String &new_native_name)
            const;

        friend class RootFileSystem;
        friend class RootFileImp;

    private:
        Path m_path;
};

#endif  // Apoxi_File_hpp

