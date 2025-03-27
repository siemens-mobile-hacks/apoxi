/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Adc_FfsFile_hpp)
#define Adc_FfsFile_hpp

#include <Adc/FfsMimeTypeMap.hpp>

/*------------------------------------------------------------------
                            FfsFile
 ------------------------------------------------------------------*/

class FfsFile
{
    public:
        FfsFile();
        ~FfsFile();

        BOOLEAN     Open(FfsFileId id, FfsFileType file_type, FfsOpenMode mode);
        BOOLEAN     Open(FfsFileId id, MimeType mime_type, FfsOpenMode mode);
        BOOLEAN     Open(const CHAR *filename, FfsOpenMode mode);
        BOOLEAN     Open(const CHAR *filename, FfsFileType file_type, FfsOpenMode mode);
        BOOLEAN     Open(const CHAR *filename, MimeType mime_type, FfsOpenMode mode);

        BOOLEAN     Close();

        BOOLEAN     Read(UINT32 offset, void FFS_HUGE *dst, UINT16 nof);

        BOOLEAN     Create(FfsFileId id, FfsFileType file_type, UINT32 size);
        BOOLEAN     Create(FfsFileId id, MimeType mime_type, UINT32 size);
        BOOLEAN     Create(const CHAR *filename, UINT32 size);
        BOOLEAN     Create(const CHAR *filename, FfsFileType file_type, UINT32 size);
        BOOLEAN     Create(const CHAR *filename, MimeType mime_type, UINT32 size);

        BOOLEAN     Write(const void FFS_HUGE *src, UINT32 offset, UINT16 nof);

        BOOLEAN     Modify(const void FFS_HUGE *src, UINT32 offset, UINT16 nof);

        BOOLEAN     Delete();

        BOOLEAN     Append(const void FFS_HUGE *src, UINT16 nof);
        
        BOOLEAN     Rename(FfsFileId new_id);
        BOOLEAN     Rename(const CHAR *new_filename);

        UINT32      GetFileSize();

        FfsFileType GetFileType();

        FfsTimeRecord   GetTimestamp();

        FfsError    GetLastError() const { return m_last_error; }

    private:
        BOOLEAN     Open(FfsOpenMode mode);
        BOOLEAN     Create(FfsFileId id, UINT32 size);
        BOOLEAN     GetFileInfo();
        const CHAR* GetFileExtension(const CHAR *filename);

        BOOLEAN     m_is_info_upd;
        BOOLEAN     m_has_filename;
        FfsFileId   m_file_id;
        FfsUserType m_user_id;
        FfsFileType m_file_type;
        FfsError    m_last_error;
        FfsHandle   m_filehandle;
        FfsFileInfo m_file_info;
        String      m_filename;
};



#endif


