/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RamDataSink_hpp)
#define Apoxi_RamDataSink_hpp

#include <Afs/Rfs/FileDataSink.hpp>
#include <Afs/Rfs/File.hpp>

class RamDataSink;

typedef NiSharedPtr<RamDataSink> RamDataSinkPtr;

class RamDataSink : public FileDataSink
{
    typedef FileDataSink Base;

    friend class RamDataSource;

    public:
        RamDataSink(UINT32 initial_size = 0,
            DrmLocalId id = c_drm_invalid_local_id);

        virtual ~RamDataSink();

        BOOLEAN Save(const Path &file_path,
            UINT32 copy_buf_size = File::c_copy_buf_size) const;

    protected:
        // Counts actually used instances.
        static UINT s_instance_cnt;
};

#endif  // Apoxi_RamDataSink_hpp


