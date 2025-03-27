/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileDataSink_hpp)
#define Apoxi_FileDataSink_hpp

#include <Auxiliary/DataSink.hpp>

class Path;
class File;
class FileDataSink;

typedef NiSharedPtr<File> FilePtr;
typedef NiSharedPtr<FileDataSink> FileDataSinkPtr;

class FileDataSink : public DataSink
{
    typedef DataSink Base;

    public:
        FileDataSink(const Path &file_path, UINT32 initial_size = 0,
            BOOLEAN overwrite_existing_file = FALSE,
            DrmLocalId id = c_drm_invalid_local_id);

        FileDataSink(const FilePtr &file, UINT32 initial_size = 0,
            BOOLEAN overwrite_existing_file = FALSE,
            DrmLocalId id = c_drm_invalid_local_id);

        virtual ~FileDataSink();

        virtual BOOLEAN Open();

        virtual BOOLEAN Close();
        virtual BOOLEAN IsOpen() const;
        virtual UINT32 Write(const void HUGE *buf, UINT32 nbytes);
        virtual UINT32 Write(UINT32 offset, const void HUGE *buf, UINT32 nbytes);
        virtual BOOLEAN GetSize(UINT32 &size) const;

    protected:
        FilePtr m_file;
        const UINT32 m_initial_size;
        const BOOLEAN m_overwrite_existing_file;
};

#endif  // Apoxi_FileDataSink_hpp


