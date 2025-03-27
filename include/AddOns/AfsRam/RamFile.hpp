/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamFile_hpp
#define Apoxi_RamFile_hpp

#include <Auxiliary/String.hpp>
#include <AddOns/AfsRam/RamFileNode.hpp>

class RamFile;
typedef NiSharedPtr<RamFile> RamFilePtr;

class RamFile
{
    public:
        RamFile();
        ~RamFile();

        inline BOOLEAN IsInitialized() const { return m_filehandle != 0; }

        BOOLEAN AssureInitialized(const CHAR *filename);

        BOOLEAN Open(const CHAR *filename, RamOpenMode mode);
        BOOLEAN Create(const CHAR *filename, UINT32 size);
        BOOLEAN Close();
        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 bytes);
        BOOLEAN Read(void HUGE *buffer, UINT32 offset, UINT32 max_no_bytes,
            UINT32 &bytes_read);
        BOOLEAN Write(const void HUGE *buffer, UINT32 offset, UINT32 no_bytes);
        BOOLEAN Delete();
        BOOLEAN Rename(const CHAR *new_filename);
        BOOLEAN Resize(UINT32 new_size);
        BOOLEAN GetFileSize(UINT32 &file_size) const;
        BOOLEAN GetCreationTimestamp(Date &time_stamp) const;
        BOOLEAN GetLastUpdateTimestamp(Date &time_stamp) const;
        BOOLEAN GetLastAccessTimestamp(Date &time_stamp) const;
        RamError GetLastError() const;
        BOOLEAN IsOpen() const;
        BOOLEAN SetReadOnly(BOOLEAN read_only);
        BOOLEAN IsReadOnly() const;
        BOOLEAN SetHidden(BOOLEAN hidden);
        BOOLEAN IsHidden() const;

    private:
        BOOLEAN Open(RamOpenMode mode);
        BOOLEAN GetFileInfo() const;
        BOOLEAN InternalWrite(const void HUGE *src, UINT32 offset, UINT32 nof);
        BOOLEAN InternalOpen(RamOpenMode mode);
        BOOLEAN Create(UINT32 size);
        BOOLEAN Append(const void HUGE *src, UINT32 nof);

        mutable BOOLEAN m_is_info_upd;
        BOOLEAN m_is_open;
        BOOLEAN m_is_writable;
        RamOpenMode m_open_mode;

        mutable RamError m_last_error;
        RamHandle m_filehandle;
        String m_filename;
        mutable RamFileInfo m_file_info;

        // TODO implement file sharing
};

#endif  // Apoxi_RamFile_hpp

