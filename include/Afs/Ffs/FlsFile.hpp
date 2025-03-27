/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FlsFile_hpp)
#define Apoxi_FlsFile_hpp

#include <Afs/Ffs/FfsTypes.hpp>
#include <Afs/Rfs/File.hpp>
#include <Auxiliary/String.hpp>

class FlsFile
{
    public:

        FlsFile();
        FlsFile(FfsUserType user_id);
        ~FlsFile();
        
        // callback functions for the streaming operations.
        static void StreamingDriverReadCallback(FfsError result, void *client_arg);
        static void StreamingDriverWriteCallback(FfsError result, void *client_arg);

        BOOLEAN     IsInitialized() const { return m_is_initialized; }

        BOOLEAN     AssureInitialized(const CHAR *filename);

        BOOLEAN     Open(FfsFileId id, FfsFileType file_type);

        BOOLEAN     Open(const CHAR *filename);

        BOOLEAN     Open(const CHAR *filename, FfsFileType file_type);
        
        BOOLEAN     OpenStreaming(const CHAR *filename);

        BOOLEAN     Create(FfsFileId id, FfsFileType file_type, UINT32 size);

        BOOLEAN     Create(const CHAR *filename, UINT32 size);

        BOOLEAN     Create(const CHAR *filename, FfsFileType file_type,
            UINT32 size);

        BOOLEAN     CreateStreaming(const CHAR *filename);

        BOOLEAN     Copy(const CHAR *dest_filename);

        BOOLEAN     Close();

        BOOLEAN     Read(void FFS_HUGE *dst, UINT32 offset, UINT32 no_bytes)
            const;

        BOOLEAN     Read(void FFS_HUGE *dst, UINT32 offset, UINT32 max_no_bytes,
            UINT32 &bytes_read) const;
            
        BOOLEAN     ReadStreaming(void HUGE *buffer, UINT32 count, UINT32 bytes_read);

        BOOLEAN     ReadStreamingAsync(void HUGE *buffer, UINT32 count, 
                        void (callback_func)(File::Error result, UINT32 bytes_operated));

        BOOLEAN     Write(const void FFS_HUGE *src, UINT32 offset,
            UINT32 no_bytes);

        BOOLEAN     WriteStreaming(const void HUGE *buffer, UINT32 count);

        BOOLEAN     WriteStreamingAsync(const void HUGE *buffer, UINT32 count, 
                        void (callback_func)(File::Error result, UINT32 bytes_operated));

        BOOLEAN     Delete();

        BOOLEAN     Rename(FfsFileId new_id);

        BOOLEAN     Rename(const CHAR *new_filename);

        BOOLEAN     Resize(UINT32 new_size);

        BOOLEAN     GetFileSize(UINT32 &file_size) const;

        BOOLEAN     GetFileType(FfsFileType &file_type) const;

        BOOLEAN     GetTimestamp(FfsTimeRecord &time_stamp) const;

        FfsError    GetLastError() const { return m_last_error; }

        BOOLEAN     IsOpen() const { return m_is_open; }

        FfsUserType GetUserId() const { return m_user_id; }

        BOOLEAN     SetUserId(FfsUserType user_id);

        BOOLEAN     GetHandle(FfsHandle &file_handle) const;

        BOOLEAN     SetDrmAttrib(const FfsDrmAttrib &attrib);

        BOOLEAN     GetDrmAttrib(FfsDrmAttrib &attrib) const;

    private:
        BOOLEAN     Open(FfsOpenMode mode);
        BOOLEAN     InternalOpen(FfsOpenMode mode);
        BOOLEAN     Create(UINT32 size);
        BOOLEAN     InternalWrite(const void FFS_HUGE *src, UINT32 offset,
            UINT32 nof);
        BOOLEAN     Modify(const void FFS_HUGE *src, UINT32 offset, UINT32 nof);
        BOOLEAN     Append(const void FFS_HUGE *src, UINT32 nof);
        BOOLEAN     GetFileInfo() const;
        const CHAR* GetFileExtension(const CHAR *filename) const;
        BOOLEAN     Upsize(UINT32 new_size);
        BOOLEAN     Downsize(UINT32 new_size);

        mutable BOOLEAN     m_is_info_upd;
        BOOLEAN     m_is_initialized;
        BOOLEAN     m_has_filename;
        BOOLEAN     m_is_open;
        BOOLEAN     m_is_writeable;
        FfsFileId   m_file_id;
        FfsOpenMode m_open_mode;
        FfsUserType m_user_id;
        FfsFileType m_file_type;
        mutable FfsError    m_last_error;
        FfsHandle   m_filehandle;
        String      m_filename;
        mutable FfsFileInfo m_file_info;
        
        
        BOOLEAN m_is_streaming;
        UINT32 m_streaming_bytes_operated;
        UINT32 m_streaming_buf_size;
        File::StreamingCallback m_streaming_cb;

};

#endif  // Apoxi_FlsFile_hpp

