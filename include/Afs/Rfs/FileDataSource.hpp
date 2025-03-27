/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileDataSource_hpp)
#define Apoxi_FileDataSource_hpp

#include <Auxiliary/DataSource.hpp>

class Path;
class File;
class FileDataSource;

typedef NiSharedPtr<File> FilePtr;
typedef NiSharedPtr<FileDataSource> FileDataSourcePtr;

class FileDataSource : public DataSource
{
    typedef DataSource Base;

    public:
        FileDataSource(const Path &file_path,
            DrmLocalId id = c_drm_invalid_local_id);

        FileDataSource(const FilePtr &file,
            DrmLocalId id = c_drm_invalid_local_id);

        virtual ~FileDataSource();

        virtual BOOLEAN Open();

        virtual BOOLEAN Close();
        virtual BOOLEAN IsOpen() const;
        virtual BOOLEAN Read(void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(void HUGE *buffer, UINT32 max_count,
            UINT32&bytes_read);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer, UINT32 count);
        virtual BOOLEAN Read(UINT32 offset, void HUGE *buffer,
            UINT32 max_count, UINT32 &bytes_read);
        virtual BOOLEAN GetSize(UINT32 &size) const;

    protected:
        FilePtr m_file;
};

#endif  // Apoxi_FileDataSource_hpp


