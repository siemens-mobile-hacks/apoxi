/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FatFile_hpp)
#define Apoxi_FatFile_hpp

#include <Auxiliary/String.hpp>
#include <AddOns/AfsFat/FatTypes.hpp>
#include <Afs/Rfs/File.hpp>

class FatFile
{
    public:
        FatFile();
        ~FatFile();
        
        static void StreamingDriverReadCallback(INT16 result, void *client_arg);
        static void StreamingDriverWriteCallback(INT16 result, void *client_arg);
        
        inline BOOLEAN IsInitialized() const { return m_filehandle != -1; }

        BOOLEAN AssureInitialized(const CHAR *filename) const;

        BOOLEAN Open(const CHAR *filename, FatOpenMode mode);
        BOOLEAN OpenStreaming(const CHAR *filename, FatOpenMode mode);
        BOOLEAN Create(const CHAR *filename, UINT32 size);
        BOOLEAN CreateStreaming(const CHAR *filename);
        BOOLEAN Close();
        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 bytes);
        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 max_no_bytes,
            UINT32 &bytes_read);
        BOOLEAN ReadStreaming(void HUGE *buffer, UINT32 count, UINT32 bytes_read);
        BOOLEAN ReadStreamingAsync(void HUGE *buffer, UINT32 count, 
                void (callback_func)(File::Error result, UINT32 bytes_operated));
        BOOLEAN Write(const void HUGE *buffer, UINT32 offset, UINT32 no_bytes);
        BOOLEAN WriteStreaming(const void HUGE *buffer, UINT32 count);
        BOOLEAN WriteStreamingAsync(const void HUGE *buffer, UINT32 count, 
                void (callback_func)(File::Error result, UINT32 bytes_operated));
        BOOLEAN Delete();
        BOOLEAN Rename(const CHAR *new_filename);
        BOOLEAN Resize(UINT32 new_size);
        BOOLEAN GetFileSize(UINT32 &file_size) const;
        BOOLEAN GetCreationTimestamp(FatTimeRecord &time_stamp) const;
        BOOLEAN GetLastUpdateTimestamp(FatTimeRecord &time_stamp) const;
        BOOLEAN GetLastAccessTimestamp(FatTimeRecord &time_stamp) const;
        FatError GetLastError() const;
        BOOLEAN IsOpen() const;
        BOOLEAN SetReadOnly(BOOLEAN read_only);
        BOOLEAN IsReadOnly() const;
        BOOLEAN SetHidden(BOOLEAN hidden);
        BOOLEAN IsHidden() const;
        BOOLEAN SetArchive(BOOLEAN archive);
        BOOLEAN IsArchive() const;

        BOOLEAN GetHandle(FatHandle &file_handle) const;

    private:
        BOOLEAN Open(FatOpenMode mode);
        BOOLEAN GetFileInfo() const;
        BOOLEAN InternalWrite(const void HUGE *src, UINT32 offset, UINT32 nof);
        BOOLEAN InternalOpen(FatOpenMode mode);
        BOOLEAN Create(UINT32 size);
        BOOLEAN Append(const void HUGE *src, UINT32 nof);
        BOOLEAN Upsize(UINT32 new_size);
        BOOLEAN Downsize(UINT32 new_size);

        mutable BOOLEAN m_is_info_upd;
        BOOLEAN m_is_open;
        BOOLEAN m_is_writable;
        BOOLEAN m_is_streaming;
        UINT32 m_streaming_bytes_operated;
        UINT32 m_streaming_buf_size;
        FatOpenMode m_open_mode;
        File::StreamingCallback m_streaming_cb;

        mutable FatError m_last_error;
        FatHandle m_filehandle;
        String m_filename;
        mutable FatFileInfo m_file_info;
};

#endif  // Apoxi_FatFile_hpp

