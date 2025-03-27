/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_FileBinData_hpp)
#define Apoxi_FileBinData_hpp

#include <Auxiliary/BinData.hpp>
#include <Auxiliary/NiSharedPtr.hpp>

class Path;
class File;

typedef NiSharedPtr<File> FilePtr;

class FileBinData : public BinData
{
    typedef BinData Base;

    public:
        static FileBinData* CreateInstance(const Path &file_path);

        static FileBinData* CreateInstance(const FilePtr &file);

        virtual BOOLEAN Read(UINT32 idx, UINT8& val) const;
        virtual UINT32 Read(UINT32 idx, void *buf, UINT32 nbytes) const;
        virtual UINT32 GetLength() const;
        virtual BinData* Clone() const;
        virtual MemMap* ObtainMemMap(UINT32 idx, UINT32 size) const;
        virtual void ReleaseMemMap(MemMap** h_map) const;

    protected:
        FileBinData();
        virtual ~FileBinData();

        FilePtr m_file;
};

#endif  // Apoxi_FileBinData_hpp

